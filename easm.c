#include <stdio.h>
#include <string.h>

typedef struct
{
	char *inst;
	unsigned char mac;
} event;

event evnew(void);
evfree(event *);

int main()
{
	return 0;
}