/*
マップ制作を楽にしたい。
・もういいy
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false, true} bool;

typedef struct event
{
	char *inst;
	unsigned char mac;
	struct event *next;
} event;

event evnew(void);
bool evfree(event *);

int main()
{
	
	return 0;
}

event evnew()
{
	event e;

	e.inst
	
	return e;
}

bool evfree(event *e)
{
	free(e->inst);
	e->mac = 0;

	return true;
}
