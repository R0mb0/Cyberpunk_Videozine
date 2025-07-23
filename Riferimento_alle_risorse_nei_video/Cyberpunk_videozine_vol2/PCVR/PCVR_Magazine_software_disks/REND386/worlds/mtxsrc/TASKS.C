/* Very simple, non-preemptive, multitasking system
   with round-robin scheduling */

/* Written by Bernie Roehl, June 1992 */

/* Copyright 1992 by Dave Stampe and Bernie Roehl.
   May be freely used to write software for release into the public domain;
   all commercial endeavours MUST contact Bernie Roehl and Dave Stampe
   for permission to incorporate any part of this software into their
   products!

	 ATTRIBUTION:  If you use any part of this source code or the libraries
	 in your projects, you must give attribution to REND386, Dave Stampe,
	 and Bernie Roehl in your documentation, source code, and at startup
	 of your program.  Let's keep the freeware ball rolling!
 */

#include <stdio.h>
#include <alloc.h>  /* malloc() */
#include "rend386.h"  /* for current_time() */

typedef struct _task TASK;

struct _task {
	void (*fn)(int cmd, char *msg, long now, long period);
	void *data;
	long period, lastran, wakeup;
	TASK *next;
};

static TASK *current_task = NULL;

TASK *get_current_task()
{
	return current_task;
}

TASK *add_task(TASK **tasklist,
	void (*fn)(int cmd, char *init, long now, long period),
	long period, void *param)
{
	TASK *t;
	if ((t = malloc(sizeof(TASK))) == NULL) return NULL;
	t->fn = fn; 
	t->data = NULL; 
	t->period = period;
	t->lastran = 0L; 
	t->wakeup = current_time();
	t->next = *tasklist;
	current_task = *tasklist = t;
	if (fn) (*fn)(0, param, current_time(), period); /* initialize */
	return t;
}

void del_task(TASK **tasklist, TASK *tsk)
{
	TASK *t;
	if (tsk == NULL) return;
	if (tsk == *tasklist)
		*tasklist = tsk->next;
	else
		for (t = *tasklist; t; t = t->next)
		if (t->next == tsk) {
			t->next = tsk->next;
			break;
		}
	free(tsk);
}

void *find_task_data(TASK *task)
{
	return &task->data;
}

void run_tasks(TASK *tasklist)
{
	long now;
	now = current_time();
	for (current_task = tasklist; current_task; current_task = current_task->next) {
		if (current_task->fn && (now >= current_task->wakeup)) {
			current_task->wakeup = now + current_task->period;
			current_task->fn(1, NULL, now, current_task->period);
			current_task->lastran = now;
		}
	}
}

