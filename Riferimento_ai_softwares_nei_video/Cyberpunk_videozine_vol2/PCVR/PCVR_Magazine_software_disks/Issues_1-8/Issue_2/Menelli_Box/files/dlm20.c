/* Downloader for 6811 code S-records */

/* IBM-PC Mix Power C version
   for Mini board by Fred Martin

   from a program originally written by Henry Q. Minsky
   and subsequently modified by Randy Sargent

*/

#define VERSION_HI 2
#define VERSION_LO 0

/*

  V1.0 February 10, 1992:
    first version

  V1.1 February 15, 1992:
    added "-delay" flag

  V1.2 February 28, 1992:
    deleted "-delay"; modified eeboot code to echo each character
    after eeprom burn

  V1.3 March 9, 1992:
    allowed Motorola S19 record to be named with ".hex" suffix in
    addition to ".s19"

  V1.4 March 25, 1992:
    added flags to allow downloading to a board with a normal serial
    line circuit

  V2.0 April 13, 1992:
    re-wrote bootstrap routine for "intelligent" eeprom burn
    added "-be" (bulk erase) flag to erase whole eeprom before download

*/

/*

    Mini board has hardware echo of all characters;
    does not have additional 6811 firmware echo during bootstrap
     download mode.

*/

#include <stdio.h>
#include <string.h>
#include <bios.h>
#include <time.h>

int debug_serial= 0;

int com_port= 0;	/* 0==COM1; 1==COM2 */

int bs_feedback= 0;	/* if true, expect serial 6811 echo during 
                           bootstrap sequence */

int hardware_echo= 1;	/* if true, expect serial hardware to echo
                           characters during normal download */

int bulk_erase= 0;	/* if true, bulk erase eeprom before download */

char filename[128];
char filenamea[128];
char filenameb[128];

int bootstring[9][80];

void init_bootstring(void)
{
    strcpy(bootstring[0], "S12300008E00FF4FB71035CE10001F2E80FC1D282086B0A72B860CA72D8D2B20FC7F00E84F");
    strcpy(bootstring[1], "S12300202004860197E88D5F167D00E827048D102006183C8D5F183808180926E939188F95");
    strcpy(bootstring[2], "S1230040E700A600202D863E8D298D3B817327F6368D2C8F8D29188F32817227E58170274B");
    strcpy(bootstring[3], "S123006032815727BD815027B48142273F817727CD863F3CCE10001F2E80FCA72F38398D51");
    strcpy(bootstring[4], "S123008006368D031632393CCE10001F2E20FCA62F3839188FE10027A9A60043D7E994E9C8");
    strcpy(bootstring[5], "S12300A0270486168D2386028D1F20968606B7103BB7103F8A01B7103B183C9DD918387F21");
    strcpy(bootstring[6], "S12300C0103B188F8602CE103FB7103BE7008A01B7103B8D0A7F103B3918CE6F9A2004184A");
    strcpy(bootstring[7], "S10B00E0CE0B29180926FC3996");
    strcpy(bootstring[8], "S9030000FC");
}


/***************************************************************/
/* The 6811 is in bootstrap mode, so send a 0xFF at 1200 baud. */
/* Then send 256 bytes of program. These will be loaded in     */
/* starting at 0x00, and each byte will be echoed              */
/***************************************************************/

/**************/
/* BREAKPOINT */
/**************/

void breakpoint(void)
{
    if (bioskey(1)) { /* not zero if key ready */
        int key= bioskey(0) & 0xff;
        if (key == 27 || key == 3) exit(1);
    }
}


/*******************/
/* SERIAL ROUTINES */
/*******************/

int last_char= -1;

#define BIOSCOM_INIT	0
#define BIOSCOM_WRITE   1
#define BIOSCOM_READ    2
#define BIOSCOM_STATUS	3

#define BAUD_1200	0x80
#define BAUD_9600	0xE0

#define	EIGHT_BITS	0x03

#define	DATA_READY	0x100
#define	DATA_SET_READY	0x20

void serial_init_1200(void)
{
    int status;

    status= bioscom(BIOSCOM_INIT, BAUD_1200 | EIGHT_BITS, com_port);
    if (debug_serial) printf("\tCOM%1d initialized; status= %#.4x\n",
                             com_port+1, status);
/*
    if (!(status & DATA_SET_READY)) {
        printf("Serial line not ready on COM%1d, exiting\n", com_port+1);
        exit(1);
    }
*/
}

void serial_init_9600(void)
{
    int status;

    status= bioscom(BIOSCOM_INIT, BAUD_9600 | EIGHT_BITS, com_port);
    if (debug_serial) printf("\tCOM%1d initialized; status= %#.4x\n",
    			     com_port+1, status);
/*
    if (!(status & DATA_SET_READY)) {
        printf("Serial line not ready on COM%1d, exiting\n", com_port+1);
        exit(1);
    }
*/
}

int serial_getchar(void)
{
    int ret;
    while (1) {
        breakpoint();
        if (bioscom(BIOSCOM_STATUS, 0, com_port) & DATA_READY) { /* data ready */
            ret = bioscom(BIOSCOM_READ, 0, com_port);
            if (debug_serial) printf("read char >%04x< from serial\n", ret);
            return ret & 0xFF;
        }
    }
}

/* returns -1 if not ready */
int serial_getchar_nowait(void)
{
    if (!(bioscom(BIOSCOM_STATUS, 0, com_port) & DATA_READY)) return -1;
    else return serial_getchar();
}

void serial_putchar(int c)
{
    if (debug_serial) printf("write char %02x to serial\n", c);
    bioscom(BIOSCOM_WRITE, (char)c, com_port);
}

void serial_putchar_getecho(int c)
{
    int i;

    serial_putchar(c);
    if (hardware_echo) {
        if (debug_serial) printf("discarding echo ");
        if (c != (i= serial_getchar()))	{ /* hardware echoes the char */
            printf("Serial line echo error (wanted %02x, got %02x)\n",
                   c, i);
            exit(1);
        }
    }
}


/* reads chars until there are no more; returns value of last char read */
int serial_getlast_char(void)
{
    int ch;
    int got_one= 0;

    if (debug_serial) printf("  Flushing to last char: ");
try_again:
    while (bioscom(BIOSCOM_STATUS, 0, com_port) & DATA_READY) {
        ch= bioscom(BIOSCOM_READ, 0, com_port);
        if (debug_serial) printf("read >%04x< ", ch);
        got_one= 1;
    }
    breakpoint();
    if (!got_one) goto try_again;

    if (debug_serial) printf("Returning >%02x<.\n", ch);
    return ch & 0xFF;
}

/* reads chars until there are no more */
void serial_flush(void)
{
    if (debug_serial) printf("  Flushing serial port: ");
    while (bioscom(BIOSCOM_STATUS, 0, com_port) & DATA_READY) {
        int ch= bioscom(BIOSCOM_READ, 0, com_port);
        if (debug_serial) printf(" >%04x< ", ch);
    }
    if (debug_serial) printf("Done.\n");
}

/* send 's' until get prompt, 1 if successful, 0 if not */
int synch_with_board(void)
{
    int j;

    serial_putchar('s');
    serial_putchar('s');
    serial_putchar('s');
    serial_putchar('s');
    serial_putchar('s');

    printf("Synchronizing with board...");
    for (j=0; j<20; j++) {
        int ch, lch;

        /* get characters until the last one; return the last valid char */
        while (1) {
/*            usleep(55000L); */
            lch= serial_getchar_nowait();
            if (lch == -1) break;
            ch = lch;
        }

        if (ch == '>') {
                serial_flush();
                break;
        }
        serial_putchar('s');

        printf("."); fflush(stdout);
        usleep(55000L);
    }
    if (j == 20) {
        printf("failed.\n");
        return 0;
    } else {
        printf("OK\n");
        return 1;
    }
}

void usleep(long usec)
{
    clock_t finish;

    finish= clock() + (usec * (long)CLK_TCK) / 1000000L;

    while (clock() < finish);
}

/*****************/
/* HEX FUNCTIONS */
/*****************/

int hex_to_int(char ch)
{
  if ('0' <= ch && ch <= '9') return ch - '0';
  if ('a' <= ch && ch <= 'f') return ch - 'a' + 10;
  if ('A' <= ch && ch <= 'F') return ch - 'A' + 10;
  printf("Illegal hex digit >%c<\n", ch);
  return 0;
}

int decode_hex(char *str, int index)
{
   int hi,lo;
   char chi,clo;
   chi = str[index];
   clo = str[index+1];
   hi = hex_to_int(chi);
   lo = hex_to_int(clo);
   return (hi*16)+lo;
   }

void parsearg(int argc, char *argv[])
{
    int i=2;

    if (argc == 1) usage();

    i= 1;

    while (i < argc) {

        if (!stricmp(argv[i], "-debug")) {
            debug_serial= 1;
            printf("Turning serial debugging on\n");
            i++;
            continue;
        }

        if (!stricmp(argv[i], "-port")) {
            char *port= argv[i+1];
            if (!stricmp(port, "com1")) {
                printf("Using COM1\n");
                com_port= 0;
            } else if (!stricmp(port, "com2")) {
                printf("Using COM2\n");
                com_port= 1;
            } else {
                printf("Unsupported com port `%s'\n\n", port);
                usage();
            }
            i+=2;
            continue;
        }

        if (!stricmp(argv[i], "-mb")) {
            bs_feedback= 0;
            hardware_echo= 1;
            printf("Turning bootstrap feedback off, hardware echo on\n");
            i++;
            continue;
        }

        if (!stricmp(argv[i], "-ns")) {
            bs_feedback= 1;
            hardware_echo= 0;
            printf("Turning bootstrap feedback on, hardware echo off\n");
            i++;
            continue;
        }

        if (!stricmp(argv[i], "-be")) {
            bulk_erase= 1;
            i++;
            continue;
        }

        if (!stricmp(argv[i], "-help") ||
            !stricmp(argv[i], "-h") ||
            !stricmp(argv[i], "?") ||
            !stricmp(argv[i], "-?")) {
                verbose_usage();
            }
        i++;
    }

    /* mandatory first arg:  filename to download */
    {
        char *suffix= strchr(argv[1],'.');
        strcpy(filename, argv[1]);
        if (!suffix) {
            strcpy(filenamea, filename);
            strcat(filenamea, ".s19");
            strcpy(filenameb, filename);
            strcat(filenameb, ".hex");
        } else if (!stricmp(suffix+1, "asm")) {
            printf("Can't download a .asm file\n");
            usage();
        } else if (!stricmp(suffix+1, "s19") &&
                   !stricmp(suffix+1, "hex")) {
            printf("You should be downloading a .s19 file or a .hex file\n");
            usage();
        }
    }

}






/********/
/* MAIN */
/********/

void usage(void)
{
    printf("usage:  dlm filename[.s19|.hex] [-port COM1|COM2] [-mb] [-ns] [-be]\n");
    printf("            [-debug] [-help]\n\n");

    printf("\t-port COM1 or -port COM2:  use specified serial port\n");
    printf("\t                           (defaults to COM%1d)\n\n", com_port+1);

    printf("\t-mb                        assume Mini Board serial connection\n");
    printf("\t                           (hardware echo of transmitted characters,\n");
    printf("\t                           except during bootstrap; defaults on)\n\n");

    printf("\t-ns                        assume normal serial connection\n");
    printf("\t                           (defaults off)\n\n");

    printf("\t-be                        bulk erase EEPROM at start of download\n");
    printf("\t                           (faster if many bytes have changed;\n");
    printf("\t                           defaults off)\n\n");

    printf("\t-debug                     turns on debugging data\n\n");

    printf("\t-help                      verbose program information\n\n");

    exit(-1);
}

void verbose_usage()
{
    printf("This program downloads Motorola S-records to a 6811-based\n");
    printf("systems.\n\n");

    printf("The serial port of your IBM must be fooled into thinking that\n");
    printf("a normal device is connected for the program to work.\n\n");

    printf("To do this, connect together pins 5, 6, and 20 (for IBM XT-style\n");
    printf("serial ports), or pins 4, 6, and 8 (for IBM AT-style serial ports).\n\n");

    printf("On an XT, pin 3 is receive, pin 2 is transmit, and pin 7 is ground.\n");
    printf("On an AT, pin 3 is transmit, pin 2 is receive, and pin 5 is ground.\n\n\n\n");

    printf("Press ENTER for more\n");
    getchar();

    clrscrn();
    printf("The pinout of the Mini Board RJ11 jack, looking into the jack, is\n");
    printf("the following:\n\n");

    printf("            +-----+                      IBM-XT      IBM-AT\n");
    printf("          +-+     +-+                    (DB-25)     (DB-9)\n");
    printf("        +-+         +-+\n");
    printf("        |             |       Mini RxD      2           3\n");
    printf("        |             |\n");
    printf("        |             |       Mini TxD      3           2\n");
    printf("        |             |\n");
    printf("        |             |       Mini Gnd      7           5\n");
    printf("        |             |\n");
    printf("        |             |\n");
    printf("        |   # # # #   |      (connect     5,6,20      4,6,8\n");
    printf("        |   # # # #   |      together)\n");
    printf("        +---#-#-#-#---+\n");
    printf("            T G G R\n");
    printf(" M I N I    x n n x\n");
    printf("            D d d D\n\n");

    printf("It is recommended that you use modular phone to DB-style connectors\n");
    printf("and phone cord to connect to the Mini.  Wire the phone adapter so that\n");
    printf("when the wires are swapped by the connecting cord they connect as shown.\n");

    exit(0);
}

void main(int argc, char *argv[])
{
    char line_in[256];

    int byte_count, data_byte, return_byte, i, j;
    int total_bytes, startaddh, startaddl;
    int bs_ix=0;

    FILE *userstream;

    printf("DLM:  6811 File Downloader with Intelligent EEPROM burn by Fred Martin\n");
    printf("Version %d.%d %s %s\n\n", VERSION_HI, VERSION_LO, __DATE__, __TIME__);

    parsearg(argc, argv);

    init_bootstring();

    total_bytes=0;

    /* open user's pgm */
    if ((userstream = fopen(filename,"r")) == NULL)
      if ((userstream = fopen(filenamea,"r")) == NULL)
        if ((userstream = fopen(filenameb,"r")) == NULL) {
        printf("Couldn't open user program %s, %s, or %s\n",filename, filenamea, filenameb);
        usage();
        } else {
            strcpy(filename, filenameb);
        }
    else {
        strcpy(filename, filenamea);
    }

    printf("Downloading %s, press ESC to abort\n",filename);

    /* initialize 1200 baud port 8 bits no parity */
    serial_init_1200();

    printf("Downloading eeprom loader to RAM at 1200 baud...");

    /* send initial 0xff */
    serial_putchar(0xff);

    while (1) {
        strcpy(line_in, bootstring[bs_ix++]);
        if ((line_in[0] == 'S') && (line_in[1] == '9')) break;

        byte_count = (decode_hex(line_in,2) - 3);

        /* loop sending data bytes from the s-record */
        for (i = 0; i < byte_count; i++) {
            data_byte = decode_hex(line_in,(2*i)+8);
            serial_putchar(data_byte);
            if (bs_feedback) serial_getchar();
            if (!(total_bytes % 32)) printf("\n");
            printf(".");
            total_bytes++;
        }
    }
    /* now send 256-byte_count 0's to fill the rest of ram */

    while (total_bytes < 256) {
        serial_putchar(0);
        if (bs_feedback) serial_getchar();
        if (!(total_bytes % 32)) printf("\n");
        printf("_");
        total_bytes++;
    }

    printf("\n%d total bytes (boot loader done)\n\n", total_bytes);

    /* now download the user prog */

    /* initialize 9600 baud port 8 bits no parity */
    usleep(110000L);	/* wait for last char to transmit */
    serial_init_9600();

    /* synchronize */
    if (!synch_with_board()) exit(1);

    if (bulk_erase) {
        printf("Bulk erasing EEPROM..."); fflush(stdout);
        serial_putchar_getecho('B');
        serial_putchar_getecho(0);
        serial_putchar_getecho(0);
        serial_putchar_getecho(0);
        serial_putchar_getecho(0xF5); /* config register */

        /* board should send prompt now */
        if (serial_getchar() != '>') {
            printf("Board synchronization error. \n");
            exit(1);
        } else printf("OK\n");
    }

    printf("Sending %s at 9600 baud\n", filename);
    total_bytes= 0;

    while (fgets(line_in,256,userstream) != NULL) {
        if ((line_in[0] == 'S') && (line_in[1] == '9')) break;

        byte_count = decode_hex(line_in,2) - 3;
        startaddh = decode_hex(line_in,4);
        startaddl = decode_hex(line_in,6);

        /* use block download to EEPROM mode */
        serial_putchar_getecho('P');
/*        if (serial_getchar() != 'P') {
            printf("Board synchronization error.\n");
            exit(1);
        } */
        serial_putchar_getecho(startaddh);
        serial_putchar_getecho(startaddl);
        serial_putchar_getecho(0);		/* count hi */
        serial_putchar_getecho(byte_count);

        /* loop sending data bytes from the s-record */
        for (i = 0; i < byte_count; i++) {
            data_byte = decode_hex(line_in,(2*i)+8);
            serial_putchar_getecho(data_byte);
            return_byte= serial_getchar();
            if (data_byte != return_byte) {
                printf("Board memory error:  wanted %02x, got %02x at address %04x\n",
                       data_byte, return_byte, (startaddh<<8)+startaddl+i);
            }

            total_bytes++;
            if (!(total_bytes % 16)) printf(".");
        }

        /* board should send prompt now */
        if (serial_getchar() != '>') {
            printf("Board synchronization error. \n");
            exit(1);
        }

    }

    printf("\nUser program downloaded successfully.\n");
    fclose(userstream);

    exit(0);
}


