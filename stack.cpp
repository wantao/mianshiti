#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
	int data;
	struct node* next;
};

typedef struct node* pNode;

struct stack
{
	pNode bottom;
	pNode top;
};

typedef struct stack* pStack;

pStack init_stack()
{
	pStack retStack = NULL;
	retStack = (pStack)malloc(sizeof(pStack));
	
	if (retStack != NULL)
	{
		retStack->bottom = NULL;
		retStack->top = NULL;
	}

	return retStack;
}

pStack stack_push(pStack u_stack,const int& u_insertNumber)
{
	pNode tmp = NULL;
	tmp = (pNode)malloc(sizeof(pNode));
	if (tmp != NULL)
	{
		tmp->data = u_insertNumber;
		tmp->next = NULL;
		if (u_stack == NULL)
		{
			u_stack = init_stack();
			if (u_stack == NULL)
			{
				printf("stack_insert init_stack failure\n");
				return NULL;
			}
			else
			{
				u_stack->bottom = tmp;
				u_stack->top = tmp;
			}
		}
		else
		{
			if (u_stack->bottom == NULL)
			{
				u_stack->bottom = tmp;
				u_stack->top = tmp;
			}
			else
			{
				u_stack->top->next = tmp;
				u_stack->top = tmp;
			}
		}
	}
	else
	{
		printf("stack_insert tmpNode malloc failure\n");
	}
	return u_stack;
}

pStack stack_pop(pStack u_stack,int& u_popData)
{
	if (u_stack != NULL)
	{
		pNode p = NULL;
		if (u_stack->bottom == NULL)
		{
			printf("stack_pop empty stack\n");
			return u_stack;
		}
		else
		{
			p = u_stack->bottom;
			u_popData = u_stack->top->data;
			printf("\n pop data:%d\n",u_popData);
			while (p->next != NULL && p->next != u_stack->top)
			{
				p = p->next;
			}
			if (p->next != NULL)
			{
				u_stack->top = p;
				u_stack->top->next = NULL;
				free(p->next);
				p->next = NULL;
			}
			else
			{
				u_stack->bottom = NULL;
				u_stack->top = NULL;
				free(p);
				p = NULL;
			}

		}
	}
	else
	{
		printf("stack_pop undefined u_stack\n");
	}
	return u_stack;
}

void print_stack(pStack u_stack)
{
	if (u_stack != NULL && u_stack->bottom != NULL)
	{
		pNode p = u_stack->bottom;
		while (p)
		{
			printf("%d ",p->data);
			p = p->next;
		}
	}
	else if (u_stack == NULL)
	{
		printf("print_stack undefined u_stack\n");
	}
	else
	{
		printf("print_stack empty u_stack\n");
	}
}

int main(void)
{
	pStack mStack = init_stack();
	
	int pushData = 0;
	int stackLength = 0;
	printf("\n input stackLength:");
	scanf("%d",&stackLength);

	for (int i = 1; i <= stackLength; i++)
	{
		printf("input %d th pushData:",i);
		scanf("%d",&pushData);
		stack_push(mStack,pushData);
	}

	mStack = stack_pop(mStack,pushData);

	print_stack(mStack);
}