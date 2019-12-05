#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/

	struct s_queue *q = queueInit();
	enqueue(q, "lol");
	printf("peek == %s\n", peek(q));
	printf("isEmpty == %d\n", isEmpty(q));
	enqueue(q, "csdsd");
	enqueue(q, "werwer");
	enqueue(q, "whar astath");
	enqueue(q, "lassst??");
	printf("dequeue == %s\n", dequeue(q));
	printf("dequeue == %s\n", dequeue(q));
	printf("dequeue == %s\n", dequeue(q));
	printf("dequeue == %s\n", dequeue(q));
	printf("dequeue == %s\n", dequeue(q));
	printf("dequeue == %s\n", dequeue(q));
	printf("peek == %s\n", peek(q));
	printf("isEmpty == %d\n", isEmpty(q));

	return (0);
}



// Function used for the test
// Don't go further :)

