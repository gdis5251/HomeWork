#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
	int array[100];
	int top;		//既表示栈顶也表示数组要插入的下标
}	stack;

//init
void StackInit(stack *s)
{
	s->top = 0;
}




//input
void StackPush(stack *s, int val)
{
	s->array[s->top] = val;
	s->top++;
}




//Pop
void StackPop(stack *s)
{
	s->top--;
}




//isEmpty
int StackEmpty(stack *s)
{
	return s->top == 0 ? 1 : 0;
}



//return top value
int StackTop(stack *s)
{
	return s->array[s->top - 1];
}




//Git Size
int StackSize(stack *s)
{
	return s->top;
}





//括号匹配
bool BracketMatch(char *str)
{
	stack s;
	StackInit(&s);

	while (*str != '\0')
	{
		switch (*str)
		{
		case '(':
		case '[':
		case '{':
			StackPush(&s, (int)*str);
			break;

		case ')':
		case ']':
		case '}':
			if (StackEmpty(&s))
				return false;

			char ch = (char)StackTop(&s);
			StackPop(&s);

			if (!((ch == '(' && *str == ')') || \
				(ch == '[' && *str == ']') || \
				(ch == '{' && *str == '}')))
				return false;
			break;
		default :
			break;
		}

		str++;
	}

	if (!StackEmpty(&s))
		return false;

	return true;
}