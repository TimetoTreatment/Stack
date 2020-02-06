#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Earraystack.h"

#define DEBUG 1


void debug(void);


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Define DATA type and ArrayStack structure
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#if DEBUG==1
int main(void)
{
	debug();

	return 0;
}
#endif

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Parenthesis Problem
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Type string to check or Enter "exit" to exit.
#if DEBUG==0

int check_parenthesis(AStack* st, char ch);

int main(void)
{
	char buffer[101];
	char* pc;
	AStack st[1];


	ASiniti(st, 100);

	for (;;)
	{
		gets_s(buffer, 100);

		if (strcmp(buffer, "exit") == 0)
		{
			break;
		}

		for (pc = buffer; *pc && check_parenthesis(st, *pc); pc++)
			;

		if (*pc == '\0' && ASsize(st) == 0)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}

		st->top = -1;
	}
}

int check_parenthesis(AStack* st, char ch)
{
	int ch_num;

	if (ch == '(' || ch == ')')
		ch_num = 1;

	else if (ch == '{' || ch == '}')
		ch_num = 2;

	else if (ch == '[' || ch == ']')
		ch_num = 3;

	if (ch == '(' || ch == '{' || ch == '[')
	{
		ASpush(st, ch_num);
	}
	else if (ch == ')' || ch == '}' || ch == ']')
	{
		if (ASsize(st) != 0 && ASpeek(st) == ch_num)
		{
			ASpop(st);
		}
		else
		{
			return 0;
		}
	}

	return 1;
}

#endif