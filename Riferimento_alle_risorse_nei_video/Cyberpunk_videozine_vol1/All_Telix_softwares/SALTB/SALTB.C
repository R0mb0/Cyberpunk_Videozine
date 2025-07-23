/*

   SALTB.C

*/

#include <stdio.h>			/* standard comments */
#include <ctype.h>			/* more comments */
#include <malloc.h>
#include <string.h>

#define COMMENT_COL	41
#define PASCAL	1
#define INDENT	4
#define YES	1
#define NO	0
#define BFRSIZ	513

extern int atoi(char *);
extern void abend(void);

extern void closeoff(void);
extern void chkcomment(void);
extern void comment(void);

extern void doequ(void);
extern void doquote(void);
extern void dofiles(int ,int ,char * * );

extern void exit(int);

extern void fmtcdecl(void);
extern void finish_line(void);

extern int getch(void);
extern void gotelse(void);
extern int getnl(void);

extern void help(FILE *);

extern int infgetc(FILE *);

extern int pascal lookup(char * *);

extern int main(int ,char * *);
extern int mygets(void);

extern void oversize(void);
extern FILE *openfile(int );

extern void ptabs(void);
extern void putbuf(void);
extern int parsearg(int ,char * * );
extern void putline(void);
extern void putnl(void);
extern int pascal putcmtln(int);	/* subroutine of comment() */

extern void pascal toindent(int );
extern void tabtoccol(void);

extern char *strtrim(char *,int );

int clevel	= 0;
int col = 0;				/* output column location */
int eflg= 0;

int spflg[20][10];
int sind[20][10];
int stabs[20][10];
int slevel[10];
int siflev[10];
int sifflg[10];
int qflg= 0;				/* 1 when within for statement */
int tabs= 0;				/* current indent level */
int peek= -1;				/* local value for unget routine */

#define TEMPINDon	1
#define TEMPINDoff	0
int tmpind	= TEMPINDoff;		/* temp indent flag on==extra indent */

int paren	= 0;			/* paren level */
int testeof	= 0;			/* 1==test for premature EOF */
int iflev	= 0;
int level	= 0;
int displ	= 0;			/* index to next free spot in buffer */
int inptab	= 0;			/* used to detab input */
int inpcol	= 0;			/* used to detab input */
int wasbl	= 0;			/* used to elim excessive whitespace */
int waswv	= 0;			/* was wvar variable */
int nline	= 0;			/* force new line switch */

int reply	= YES;			/* reply prompt 'y' or 'n' */
int hflag	= NO;			/* put in header */
int bflag	= YES;			/* don't fold line at trailing ')' */

int ifflg	= -1;

#define AT_LEFTMARG	1
#define WITHIN_LINE	0
int sflg= AT_LEFTMARG;			/* 1 <==> \n, 0 <==> text was online */

int pmode	= PASCAL;		/* pascal mode wanted */
int indent	= INDENT;
int ccol= COMMENT_COL;
#define MAXTIMES 2			/* tab not more than 2 times */
int defflag	= MAXTIMES;		/* <2 implies tab to next tabstop  */

int lastchar;
int c;
int ind[10]	=
{
    0,0,0,0,0,0,0,0,0,0
};
int pflg[10]	=
{
    0,0,0,0,0,0,0,0,0,0
};
char lchar;
char pchar;
int ct;

char *wvar[]	=
{
    "char",
    "int",
    "long",
    "str",                              /* 88/04/22 */
    0};

char *wif[]	=
{
    "if",
    0};
char *welse[]	=
{
    "else",
    0};

char *welsedo[] =
{
    "do",
    "else",
    0};

char *wnline[]	=
{
    "for",
    "if",
    "while",
    0};

char *wfor[]	=
{
    "for",
    0};

char *wds[]	=
{
    "case",
    "default",
    0};

char *wdosw[]	=
{
    "do",
    "switch",
    0};

char *buff;				/* global pointer to work buffer */
char cc;
FILE *infil, *outfil;

char *how[]	=
{
    "Telix-source code beautifier (SALTB.EXE). Command format is:\n",
    "\tSALTB [-Bn][-Cnn][-Hn][-In][-Pn][-Rn] source[.slt] newfile[.slt]",
    "\tSALTB [-Bn][-Cnn][-Hn][-In][-Pn][-Rn] <infile >outfile",
    "\tSALTB [-Bn][-Cnn][-Hn][-In][-Pn][-Rn] source[.slt] >outfile",
    "\t[ ] refer to optional parameters that affect formatting.\n",
    "When the source file extension is omitted, a \".SLT\" is appended.",
    "When newfile[.SLT] is omitted, output is to STDOUT. Similarly, if no",
    "file is specified, input is from STDIN and output is to STDOUT.\n",
    "-Bn\tB0 \"if, while, for\" action statements on lines after closing ')'.",
    "-Cnn\tdefines the column to the right of statements where comments",
    "\tshould begin.  -Cnn, if specified, must respect  0< nn <73.",
    "-Hn\tcontrols insertion of program comment as header and trailer lines.",
    "-In\tis indentation for each nesting level. Indent value be  0< n <9.",
    "-Pn\tcontrols style of brace alignment. -P0 means it is not wanted!",
    "-Rn\tcontrols overwriting of output file. -R1 prompts for permission.\n",
    "For example: Indent by 2s, output to printer: SALTB >PRN -I2C33P0\n",
    "Warning...Do not allow \">newfile.SLT\" to be same as INPUT file name",
    "\tas distruction of input source file by output file will occur.\n",
    "\tDefaults: -b1 -i4 -c41 -h0-p1-r1      Les. Satenstein." __DATE__ ".",
    0
};
char *ifile	= 0;			/* input file name */
char *wfile	= 0;			/* workfile name */
char *ofile	= 0;			/* output file name*/

/***************************************
 *	where it all begins
 *
 ***************************************/

main(argc,argv)
int argc;
char *argv[];
{
    register char *wbuff;		/* work buffer space pointer */
    int i;


    if (*argv[1] == '?')
    {
	help(stdout);
	return(4);
    }
    if(3<(i = parsearg(argc,argv)))
	abend();			/* Incorrect no args */
    if(!(buff = wbuff = calloc(BFRSIZ,1)))
    {
	fputs("\nNeed more memory to continue",stderr);
	return(4);
    }					/* why not */

    dofiles(i,argc,argv);

    fputs("\nSALTB.EXE -- a TELIX SALT-code beautifier vers 1.0. -- " __DATE__ " --\n",
    stderr);
    fputs("          Author: Leslie Satenstein (514-682-5882)\n",stderr);
    fputs("          SALTB ? for help\n",stderr);
    while(testeof=0,(c = getch()) != EOF)
    {
	if(c == ' ' && wasbl == ' ' )
	    continue;
	testeof = 1;			/* eof now will abort */
	switch(wasbl = c)
	{
	case ' ':
	    if(!bflag)
		nline+=lookup(wnline);
	    if(c=lookup(welsedo))
	    {
		if(lookup(wdosw))	/* could be a do {} */
		{			/* if so, write the do and continue*/
		    putbuf();
		    continue;
		}
		gotelse();
	    }
	    else
	    if(!paren) waswv+=lookup(wvar);

	    if(sflg == WITHIN_LINE || displ > 0)
		wbuff[displ++] = ' ';
	    if(c)
		putbuf();		/* sflag=0; */
	    continue;

	case '\n':
	    if((eflg = lookup(welse)))
		gotelse();
	    if(pmode)
		if(lookup(wdosw))
		    pchar=' ';
	    putline();			/* put new line, setup for next one*/
	    if(eflg )
	    {
		pflg[level]++;
		tabs++;
	    }
	    else if(pchar == lchar)
		tmpind = TEMPINDon;
	    continue;

	case '{':
	    if(lookup(welse))
	    {
		gotelse();
		if(pmode)
		    putbuf();
	    }
	    siflev[clevel] = iflev;
	    sifflg[clevel] = ifflg;
	    iflev = ifflg = 0;
	    clevel++;
	    if( sflg == AT_LEFTMARG && pflg[level] != 0)
	    {
		pflg[level]--;
		tabs--;
	    }

	    if(pmode)			/* only do if pmode selected */
		if(lookup(wdosw))
		{			/*     do and switch keywords */
		    sflg = AT_LEFTMARG;
		    putbuf();
		}
	    if(sflg == WITHIN_LINE)	/* only do if pmode selected */
		putnl();		/* put new line, setup for next one*/
	    wbuff[displ++] = '{';
	    putbuf();
	    finish_line();
	    tabs++;
	    if(pflg[level] > 0)
	    {
		ind[level] = 1;
		level++;
		slevel[level] = clevel;
	    }
	    continue;

	case '}':
	    clevel--;
	    if((iflev = siflev[clevel]-1) < 0)
		iflev = 0;

	    ifflg = sifflg[clevel];
	    if(pflg[level] >0 && ind[level] == 0)
	    {
		tabs -= pflg[level];
		pflg[level] = 0;
	    }
	    putbuf();
	    tabs--;
	    ptabs();

	    wbuff[displ++]='}';
	    if((peek = getch()) == ';')
	    {
		wbuff[displ++]=';';
		peek = -1;
	    }
	    finish_line();
	    if(clevel < slevel[level])
		if(level > 0)
		    level--;
	    if(ind[level] != 0)
	    {
		tabs -= pflg[level];
		pflg[level] = 0;
		ind[level] = 0;
	    }
	    continue;

	case '"':
	case '\'':
	    doquote();
	    continue;

	case ';':
	    waswv=0;		/* turn off switch for tabing vars */
	    wbuff[displ++] = ';';
	    putbuf();
	    if(pflg[level] > 0 && ind[level] == 0)
	    {
		tabs -= pflg[level];
		pflg[level] = 0;
	    }
	    finish_line();
	    if(iflev > 0)
		if(ifflg == 1)
		{
		    iflev--;
		    ifflg = 0;
		}
		else iflev = 0;
	    continue;

	case '^':
		wbuff[displ++] = '^';
		wbuff[displ++] = getch();
	    continue;

	case '?':
	    qflg = 1;
	    wbuff[displ++] = '?';
	    continue;

	case ':':
	    wbuff[displ++] = ':';
	    if(qflg == 1)
	    {
		qflg = 0;
		continue;
	    }
	    if(!lookup(wds))
	    {
		sflg = WITHIN_LINE;
		putbuf();
	    }
	    else
	    {
		tabs--;
		putbuf();
		tabs++;
	    }
	    if((peek = getch()) == ';')
	    {
		wbuff[displ++];
		peek = -1;
	    }
	    finish_line();
	    continue;

	case '/':
	    chkcomment();
	    continue;

	case '!':
	    while(wbuff[displ-1] == ' ' && displ>0) displ--;
	    wbuff[displ++]=' ';
	    wbuff[displ++]='!';
	    continue;

	case ',':                       // within paren as for(i=5,j=3;.... )
	    wbuff[displ++] = ',';       /* or  static int j=5,k=2; */
	    putbuf();
	    if(getnl())
		peek = '\n';
	    continue;

	case ')':
	    paren--;
	    wbuff[displ++] = ')';
	    putbuf();
	    if(getnl())
	    {
		peek = '\n';
		if(paren != 0)
		    tmpind = TEMPINDon;
		else if(tabs > 0)
		{
		    pflg[level]++;
		    tabs++;
		    ind[level] = 0;
		}
	    }
	    if(nline && !paren) 	/* only if out of nested brackets */
	    {
		if((peek=getch()) == ' ')
		    wbuff[displ++]=' ';
		while(' ' == (peek=getch()))
		    peek=-1;		/* skip past blanks */
		if(isalpha(peek) || peek == '_')
		{
		    if(wbuff[displ-1] == ' ')
			displ--;
		    tmpind = TEMPINDon;
		    finish_line();
		}
	    }
	    continue;

	case '(':
	    wbuff[displ++] = '(';
	    paren++;
	    if(!bflag)
		nline+=lookup(wnline);
	    if(lookup(wfor))
	    {
		while((c = mygets()) != ';');
		ct=0;
cont:
		while((c = mygets()) != ')')
		    if(c == '(')
			ct++;

		if(ct != 0)
		{
		    ct--;
		    goto cont;
		}
		paren--;
		putbuf();
		if(getnl())
		{
		    peek = '\n';
		    pflg[level]++;
		    tabs++;
		    ind[level] = 0;
		}
		continue;
	    }
	    if(lookup(wif))
	    {
		putbuf();
		stabs[clevel][iflev] = tabs;
		spflg[clevel][iflev] = pflg[level];
		sind[clevel][iflev] = ind[level];
		iflev++;
		ifflg = 1;
	    }
	    continue;

	case '=':
	    doequ();			/* process = sign */
	    continue;

	default:
	    wbuff[displ++] = c;
	    if(c != ',')
		lchar = c;
	}
    }
    closeoff();
    return 0;
} /* end main */
/*;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
     process equ sign
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;*/
void doequ()
{
    register char *wbuff;
    char prevopt;			/* previous operator was  */
    if((!paren)&&(waswv||lookup(wvar))) /* but not within ( ... ) */
    {
	 waswv=1;
	 fmtcdecl();			 /* (char *)abc = 5;	   */
    }
    /*	  for !=  and == surround with blank on either side; */
    else
    {
	prevopt=wbuff[displ-1];
	if(prevopt == '!' || prevopt == '=') /* cant handle <<= */
	{
	    if(displ>2 && wbuff[displ-2] != ' ')
	    {
		wbuff[displ-1]=' ';
		wbuff[displ++]=prevopt;
		wbuff[displ++]='=';
		c=wasbl=' ';
	    }
	}
    }
    wbuff[displ++]=c;
}
/*;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

 for int, unsigned, long char  ... put a tab char before the =

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;*/
void fmtcdecl()
{
    register char *wbuff    = buff;	/* backup to non blank */
    while (wbuff[displ-1] == ' ')
	displ--;
    wbuff[displ++]=wasbl=c= ' ';        /* pad with one blank */
    if(waswv && (col+displ)<16)
       {
       wbuff[displ++] = ' ';
       toindent(16);			    /* space to next indent */
       }
    else
       toindent(8);
    wbuff[displ++] = '=';               /* variable c modified to ' ' */
    while(' ' == (peek=getch()))
	peek=-1;
}


/*********************************

	process quote string

*********************************/
void doquote()
{
    register char *wbuff    = buff;
    wbuff[displ++] = c;
    while((cc = getch()) != c)
    {
	wbuff[displ++] = cc;
	if(cc == '\n')
	{
	    putbuf();
	    sflg = AT_LEFTMARG;
	}
    }
    wbuff[displ++] = cc;
    if(defflag>=MAXTIMES && getnl())	/* check for within '#' */
    {
	lchar = cc;
	peek = '\n';
    }
} /* end do quote */

/*
    endup input file processing
*/
void closeoff()
{
    if(tabs||paren||clevel)
    {
	fputs("\n\a\aUnbalanced brace, parenthesis or unclosed quote/string\n",
	stderr);
	testeof=1;
	peek=-1;
	getch();
	exit(4);
    }
    if(hflag)
	fputs("/*+***********) end of program (************+*/",outfil);
    fclose (infil);
    fclose (outfil);
    if(ofile)
    {
	unlink(ofile);			/* ignore return code */
	if(rename(wfile,ofile))
	{
	    fputs("\nRename of \"",stderr);
	    fputs(wfile,stderr);
	    fputs("\" to \"",stderr);
	    fputs(ofile,stderr);
	    fputs("\" failed!",stderr);
	    exit(4);
	}
    }
}

/***************************************
 * Indent by i*tabs from left margin Do
 * not invoke from other than left margin.
 ***************************************/

void ptabs()
{
    int i;
    if(tabs<=0)
	tabs=0;
    else
    {
	for(i=tabs*indent,col+=i; i>=8 ; i-=8)fputs("\t",outfil);
	while(i--)
	    fputs(" ",outfil);
    }
}

/***************************************
 *  local getchar routine
 *  handles unget() type of operation
 ***************************************/

getch()
{
    if(peek == -1)			/* any other value means ungetc() */
    {					/* was previous entry */
	if(lastchar != ' ')
	    pchar = lastchar;
	lastchar=infgetc(infil);
    }
    else lastchar = peek;
    peek = -1;
    return(lastchar);
}

/***************************************
 * if buff has something put it out
 * if necessary, indent before doing so
 ***************************************/

void putbuf()
{
    register int i;
    if(displ)
    {
	if(sflg == AT_LEFTMARG)
	{
	    ptabs();
	    sflg = WITHIN_LINE;
	    if(tmpind)
	    {
		tmpind = TEMPINDoff;
		if(tabs>0)
		    for (i=indent,col+=i;i--;) fputs(" ",outfil);
	    }
	}
	buff[displ] = '\0';
	fputs(buff,outfil);
	col+=displ;
	if(displ> BFRSIZ)
	    oversize();
	displ = 0;
    }
    else
    {
	if(sflg == AT_LEFTMARG)
	{
	    sflg = WITHIN_LINE;
	    tmpind = TEMPINDoff;
	}
    }
}

/***************************************
 * scan buffer looking for a keyword
 *
 ***************************************/
pascal lookup(tab)
char *tab[];
{
    register char *spr;
    register char *tpr;
    int k,i,ii;
    if(displ)
    {
	spr=buff;
	ii=0;
	while(spr[ii] &&(spr[ii] <'a'||spr[ii]>'z'))
	    if(displ<=++ii)
		return 0;

	for(i=0;tpr=tab[i++];)
	{
	    for(k=ii,spr=buff+ii;*tpr && *tpr == *spr++;k++,tpr++);
	    if( *tpr == '\0')
		if
		    (k == displ||(k<displ && (_ctype+1)[*spr] & (_BLANK|_PUNCT|_CONTROL)))
		    return(1);		/* not a..zA..Z_ */
	}				/* "if any as lookup should fail*/
    }					/*  do{ should work, dos should not */
    return(0);
}

/***************************************
 * get string from input, handle "... "
 * or ' '
 ***************************************/

mygets()
{
    register char *str	    = buff;
    register char ch;
beg:
    while((ch=str[displ++]=getch()) == '^')
    {
	if((peek=getch()) == '\n')
	{
	    displ--;			/* backup one char, throw away \  */
	    peek=-1;			/* force read from file */
	}
	else
	    str[displ++]=getch();
    }
    if(ch == '\''||ch == '"')
    {
	while((cc=str[displ++]=getch())!=ch)
	    if(cc == '^')
		if((peek=getch()) == '\n')
		{
		    displ--;		/* backup 1 char, throw away \ */
		    peek=-1;		/* and read next char */
		}
		else str[displ++] = getch();
	goto beg;
    }
    if(ch == '\n')
    {
	putbuf();
	tmpind=TEMPINDon;
	goto beg;
    }
    return(ch);
}

/***************************************
 * common code when "else" is detected
 *
 ***************************************/

void gotelse()
{
    tabs = stabs[clevel][iflev];
    pflg[level] =spflg[clevel][iflev];
    ind[level] = sind[clevel][iflev];
    ifflg = 1;
}

/***************************************
 *  scan past last statement to new line
 *    or to comment where it is processed
 ***************************************/

int getnl()				/* fill buff until \n detected */
{
    register char *str	    = buff;
    register int firstc;
    firstc=peek=getch();
    if(firstc == ' ')
    {
	while((wasbl = getch()) == ' '); /* skip leading/multiple blanks */
	peek=wasbl;			/* check if something like)  {..*/
	if(peek != '{')
	    str[displ++]=firstc;	/*			   ^	*/
    }

    if(peek == '/')
    {
	peek = -1;
	if((peek = getch()) == '/') /* for new comment field*/
	{
	    if (col)
	    {
		col+=displ;
		defflag=MAXTIMES;	/* disable tabcol ftn */
		tabtoccol();
	    }
	    str[displ++] = '/';
	    str[displ++]='/';
	    peek=-1;
	    while((firstc=getch()) != '\n')
		str[displ++]=firstc;
	    return(peek);
	}
	else str[displ++] = '/';
    }

    if ( (peek = getch()) == '\n')
    {
	peek=-1;
	return(peek);
    }

    return(0);
}

/**************************************
  got / check for *  and if so
  process the comment which could
  spill across several lines of code.
  If // then process to EOL
***************************************/
void chkcomment()
{
    register char *wbuff    = buff;
    register int i;
    if((peek = getch()) != '/' ) //
    {
	wbuff[displ++] = c;
	return ;
    }
    if(col+=displ)
	tabtoccol();
    wbuff[displ++] = '/';

	wbuff[displ++]=getch(); 	// put out second slash
	do				// put out rest of line
	{
	    wbuff[displ++]=i=getch();
	}
	while( '\n' != i);
	displ--;			//discard the '\n'
	putline();			// put out the line and reset all important vars
}

/***************************************
 *  Process comments within C code
 *
 ***************************************/

void comment()
{
    register char *str	    = buff;
    int hold= inpcol-displ;		/* calc where in line we are */
    int wascmnt     = 0;		/* to determine # leading ' '*/

	/*************************************************************
	*  This function is entered whenever a comment is  detected  *
	*  The	rules should be as follows:			     *
	*  1.	If the comment is a 1-liner, then indent the comment *
	*	to match the indentation level			     *
	*  2.	If the comment is continued on the next line and     *
	*	the comment has nothing to the left of it (eg starts *
	*	the line, put the comment line out without revision  *
	*************************************************************/

rep:
    while((c = str[displ++] = getch()) != '*') /* scan to first '*' */
    {
	if(c == '^')                   /* was line folded ? */
	    if((peek=getch()) == '\n')
	    {
		displ--;
		peek=-1;
		continue;
	    }
	if(c == '\n')                   /* was eol encountered ? */
	{				/* then comment continues on*/
	    if((col == 0)&&(sflg == AT_LEFTMARG)) /* successive lines */
	    {
		hold=putcmtln(hold);
		wascmnt=1;
	    }
	    else putbuf();
	    nline=col=0;
	}
    }
    /* got star, check for  aster/   */
    while((c = str[displ++] = getch()) != '/')
    {
	if(c == '^')
	    if((peek=getch()) == '\n')
	    {
		displ--;
		peek=-1;
		continue;
	    }
	if(c == '\n')
	{
	    if(col == 0&& sflg == AT_LEFTMARG)
	    {
		hold=putcmtln(hold);
		wascmnt=1;
	    }
	    else putbuf();

	    nline=col=0;
	}
	if(c != '*')
	    goto rep;
    }
    if(wascmnt)
    {
	col+=displ;
	hold=putcmtln(hold);
    }
}

pascal putcmtln(hold)			/* subroutine of comment() */
int hold;
{
    for(;0<hold--;)fputs(" ",outfil);
    buff[displ]='\0';
    fputs(buff,outfil);
    if(displ> BFRSIZ)
	oversize();
    return(displ=0);
}

/***************************************
 *   abnormal end
 *
 ***************************************/
void abend()
{
    help(stderr);
    exit(3);				/* never to return */
}
/*********************************************
 *		oversize()
 * abnormal end if buff is filled past the end
 *
 *********************************************/
void oversize()
{
    fputs("\nDanger... Data written past end of buffer\n",stderr);
    exit(4);
}
/***************************************
 *   HELP HELP
 *
 ***************************************/

void help(fd)
FILE *fd;
{
    register char *cptr;
    register int i;
    for(i=0;cptr=how[i];i++)
    {
	fputs(cptr,fd);
	fputs("\n",fd);
    }
}

/***************************************
 * code to end a line
 * scan to the end of the line,
 * put the line, followed by a new line
 * and reset margin and column indicators
 ***************************************/

void finish_line()
{
    getnl();
    putline();
}

/***************************************
 *
 *	tab to the next indent val
 *	used for "\n#define  ABCDEFE  xx
 *
 ***************************************/
void pascal toindent(i)
int i;
{
    register char *wbuff    = buff;
    register int n;
    if((col-1) >= ccol) 		/* don't do if to right of ccol*/
	return; 			/* indent must be power of 2 */

    n=i-(displ+col)&(i-1);
    if(n == (i-1)&&wbuff[displ-1] == ' ') /* check if any padding or to but up*/
    {
	if(lastchar == '=')
	    displ--;			/* only do it if lastcar is equalsign*/
    }
    else
	while (n--)
	    wbuff[displ++]=' ';

}

/***************************************
 *	tab to the next tab column
 *	follow ms-dos convention
 ***************************************/

void tabtoccol()			/* ccol index orig 0  */
{					/* existing column position */
    register char *str	    = buff;
    int n;
    int m;
    if((col-1) >= ccol)
	return;

    /* if same already there, otherwise to the right */
    /* n=distance to add to col to arrive at closest  tab column*/
    /* if n=0, col is on tab column and n has to be bumped to 8 */
    /* 0->8,1->7,2->6,.....7->1 */

    if(!(n=8-col&7))			/* size of jump to next tab stop */
	n=8;				/* m=tab stop before or equal to ccol */
    for(m=ccol&~7;(col+n)<=m ;n=8)
    {
	str[displ++]='\t';
	col+=n;
    }
    for(;col< ccol;col++)str[displ++]=' ';
}

/***************************************
 *	detab input,  keep track of
 *	logical displacement on line
 ***************************************/

int infgetc(fd)
FILE *fd;
{
    register int cc;
    if(inptab)				/* local count of spaces to push*/
    {					/* out if tab encountered in input */
	inptab--;
	return ' ';
    }
    if('\t' == (cc=fgetc(fd)))
    {
	inpcol +=(1+(inptab=(~inpcol)&7));
	return ' ';
    }

    if((cc == EOF) && testeof)
    {
	fputs("\n\a\aInput file ends prematurely. Cannot continue!!\n",stderr);
	exit(4);
    }
    inpcol++;				/* logical position in the input line */
    if( cc == '\n' || cc == '\r' )
	inpcol=0;
    return cc;
}

/***************************************
 *     parse command line arguments
 *
 ***************************************/

parsearg(argc,argv)
int argc;
char *argv[];
{
    register char *strptr;
    register int i;
    int j,k,err;
    for(k=argc,i=1;i<argc;i++)		/* check for switch */
    {
	strptr=strupr(argv[i]);
	if((j=*strptr++)  == '-'|| j== '/')
	{
	    k--;
	    while(*strptr)
	    {
		j=atoi(strptr+1);
		switch(*(strptr++))
		{
		case 'I':
		    indent=j;
		    break;
		case '-':
		    continue;
		case 'B':
		    bflag=j;
		    break;
		case 'C':
		    ccol=j;
		    break;
		case 'H':
		    hflag=j;
		    break;
		case 'P':
		    pmode=j;
		    break;
		case 'R':
		    reply=j;
		    break;
		default:
		    fputs("\n",stderr);
		    fputs(argv[i],stderr);
		    fputs(" :- Unknown flag",stderr);
		    abend();
		}
		while(isdigit(*strptr )) ++strptr;
	    }
	}
    }
    err=0;
    if(indent<1||indent>8)
	err=indent=INDENT;

    if(ccol<0 || ccol> 72)
	err=ccol=COMMENT_COL;

    if(pmode&~1)
    {
	pmode=PASCAL;
	err=YES;
    }
    if(reply&~1)
    {
	reply = err = YES;
    }
    if(bflag&~1)
    {
	bflag = err = YES;
    }
    if(err)
    {
	fputs("\nAn invalid switch parameter was set to default value\a\n\n",stderr);
	help(stderr);
    }
    ccol--;				/* column 41 <==>  ccol==40 */
    return k;
}
void putline()
{
    putbuf();				// write out the line
    putnl();				// and then the cr, lf
}

void putnl()				/* put new line, setup for next one*/
{
    sflg = AT_LEFTMARG; 		/* sflg indicates whether new line */
    fputs("\n",outfil);
    nline=col=0;

}

void dofiles(k,argc,argv)
int k;
int argc;
char *argv[];
{
    int i;
    register char *str;
    infil=stdin;
    outfil=stdout;
    str=buff;
    strcpy(str,"Console Input");
    if(k>1)
	for(i=1;i<argc;i++)
	    if(*argv[i] != '-' && *argv[i]!= '/')
	    {
		ifile=calloc(65,1);
		strcpy(ifile,strupr(argv[i]));
		if(!strrchr(ifile,'.'))
		    strcat(ifile,".SLT"); /* get input file id */
		strcpy(str,ifile);
		infil=openfile(0);	/* open for input */
		break;
	    }
    if(k>2)
	for(i++;i<argc;i++)
	    if(*argv[i] != '-')
	    {
		ofile=calloc(65,1);
		wfile=calloc(65,1);
		if((!ifile)||(!wfile)||(!ofile))
		{
		    fputs("\nInsufficient memory available, Cannot continue!\n",stderr);
		    exit (4);
		}
		strcpy(ofile,strupr(argv[i]));
		if(!strrchr(ofile,'.'))
		    strcat(ofile,strrchr(ifile,'.'));/* get output file id */
		strcpy(str,ofile);
		strcpy(wfile,ofile);
		strcpy(strrchr(wfile,'.'),".$$$");/* substit .$$$ for .slt */
		outfil=openfile(1);
		break;
	    }
    if(hflag)
    {
	fputs("/**+*****) ",outfil);
	if(!(str=strrchr(buff,'\\')))   /* skip path and drive id */
	    if(!(str=strrchr(buff,':')))
		str=buff-1;
	fputs(++str,outfil);
	fputs(" (*******+**/\n",outfil);
    }
}

/***************************************
 *     open files, check for
 *     accidental overwrite
 ***************************************/

FILE *openfile(option)
int option;				/* option==0 is read only */
{
    int c;
    FILE *ptr;
    register char *str;
    switch(option)
    {
    case 0:
	if(!(ptr=fopen(ifile,"r")))
	{
	    fputs("\nUnable to open ",stderr);
	    fputs(ifile,stderr);
	    fputs(". Try SALTB ?\n",stderr);
	    exit(4);
	}
	break;

    case 1:
	if(reply)			/* global sw to test for delete */
	{
	    if(ptr=fopen(ofile,"r"))
	    {
		fclose(ptr);
		while(1)
		{
		    fputs("\nFile ",stderr);
		    fputs(ofile,stderr);
		    fputs(" exists! Overwrite? (y/n) ",stderr);
		    fflush(stderr);
		    fflush(stdin);
		    fgets(str=buff+128,10,stdin);
		    strtrim(str,0);
		    if('n' == (c=tolower(*str) ) )
			exit (4);
		    if(c == 'y')
			break;
		}
	    }

	    if(ptr=fopen(wfile,"r"))
	    {
		fclose(ptr);
		while(1)
		{
		    fputs("\nFile ",stderr);
		    fputs(wfile,stderr);
		    fputs(" exists! Overwrite? (y/n) ",stderr);
		    fflush(stderr);
		    fflush(stdin);
		    fgets(str=buff+128,10,stdin);
		    strtrim(str,0);
		    if('n' == (c=tolower(*str) ) )
			exit (4);
		    if(c == 'y')
			break;
		}
	    }
	}
	if( (ptr=fopen(wfile,"w")) == (FILE *)NULL)
	{
	    fputs("\nUnable to open workfile :",stderr);
	    fputs(wfile,stderr);
	    fputs(", Aborting execution\n",stderr);
	    exit(4);
	}
	break;
    default:
	fputs("Openfile option invalid\n",stderr);
	abend();
    }
    return ptr;
}
/************************************************
  strtrim()
  trim off leading/trailing blanks according to op
  op==+, trailing ctl chars, op==- leading ctl chars
  op==0  both ends
*************************************************/
char *strtrim(st,op)
char *st;
int op;
{
    register char *cp;
    register int sl;
    if(sl=strlen(st))
    {
	if(op >=0)
	    for(cp=st+sl-1;st<=cp;)
	    {
		if((*cp) > ' ')
		    break;
		*cp--=0;
	    }
	if(op <=0)
	{				/* move string left, padding with 0's*/
	    for(cp=st;*cp&&(*cp<=' ');cp++);
	    if(cp != st)
		strncpy(st,cp,sl);
	}
    }
    return st;
}
