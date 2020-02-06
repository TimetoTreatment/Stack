#include <stdio.h>
#include <stdlib.h>
#include "Earraystack.h"


void ASiniti(AStack* st, int max)
{
	st->ar = (DATA*)malloc(max * sizeof(DATA));
	if (st == NULL)
	{
		printf("Error : Not enough Memory.\n");

		exit(-1);
	}

	st->top = -1;
	st->max = max - 1;
}

int ASisEmpty(AStack* st)
{
	if (st->top == -1)
		return 1;

	return 0;
}

int ASisFull(AStack* st)
{
	if (st->top == st->max)
		return 1;

	return 0;
}

void ASpush(AStack* st, DATA data)
{
	if (ASisFull(st) == 1)
	{
		printf("Error : Stack Overflow.\n");

		exit(-1);
	}

	st->top++;
	st->ar[st->top] = data;
}

DATA ASpop(AStack* st)
{
	if (ASisEmpty(st) == 1)
	{
		printf("Error : Stack is Empty.\n");

		exit(-1);
	}

	st->top--;

	return st->ar[st->top + 1];
}

DATA ASpeek(AStack* st)
{
	if (ASisEmpty(st) == 1)
	{
		printf("Error : Stack is empty.\n");

		exit(-1);
	}

	return st->ar[st->top];
}

int ASsize(AStack* st)
{
	return (st->top) + 1;
}

void ASlist(AStack* st)
{
	for (int i = 0; i <= st->top; i++)
	{
		printf("%d\n", st->ar[i]);
	}
}