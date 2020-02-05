#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayStack.h"

void print_functions(void);


void debug(void)
{
	int n;
	int item;
	char cmd[6];
	AStack st[1];

	
	print_functions();

	printf("Stack Size : ");
	scanf("%d", &n);
	getchar();

	ASiniti(st, n);

	for (;;)
	{
		printf("$");
		scanf("%s", cmd);

		if (strcmp(cmd, "push") == 0)
		{
			scanf("%d", &item);
			getchar();

			ASpush(st, item);
		}

		if (strcmp(cmd, "pop") == 0)
		{
			if (ASisEmpty(st) == 1)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", ASpop(st));
			}
		}

		if (strcmp(cmd, "size") == 0)
		{
			printf("%d\n", ASsize(st));
		}

		if (strcmp(cmd, "isempty") == 0)
		{
			printf("%d\n", ASisEmpty(st));
		}

		if (strcmp(cmd, "isfull") == 0)
		{
			printf("%d\n", ASisFull(st));
		}

		if (strcmp(cmd, "peek") == 0)
		{
			if (ASisEmpty(st) == 1)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", ASpeek(st));
			}
		}

		if (strcmp(cmd, "list") == 0)
		{
			ASlist(st);
		}

		if (strcmp(cmd, "exit") == 0)
		{
			return;
		}
	}
}


void print_functions(void)
{
	char* list[10] = { "push X", "pop","size","isempty","isfull","peek","list","exit", "\0" };
	char** pc;


	for (pc = list; **pc; pc++)
	{
		printf("%s\n", *pc);
	}

	printf("\n");
}