/* Functions related to the simple "multi-tasker" */

/* Written by Bernie Roehl, June 1992 */

/* Copyright 1992 by Dave Stampe and Bernie Roehl.
   May be freely used to write software for release into the public domain;
   all commercial endeavours MUST contact Bernie Roehl and Dave Stampe
   for permission to incorporate any part of this software into their
   products!
 */

typedef void TASK;

extern TASK *get_current_task(void);
extern TASK *add_task(TASK **tasklist, void (*fn)(), long period, void *param);
extern void del_task(TASK **tasklist, TASK *tsk);
extern void run_tasks(TASK *tasklist);
extern void *find_task_data(TASK *task);

/* End of tasks.h */
