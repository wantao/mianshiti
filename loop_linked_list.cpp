#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct loopNode
{
	int data;
	struct loopNode* next;
};

typedef struct loopNode* pLoopNode;

void josePhus(int u_n,int u_k,int u_m)
{
	pLoopNode p,r,curr;
	p = (pLoopNode)malloc(sizeof(pLoopNode));
	p->data = 1;
	p->next = p;
	curr = p;

	for (int i = 2; i <= u_n; i++)
	{
		pLoopNode t = (pLoopNode)malloc(sizeof(pLoopNode));
		t->data = i;
		t->next = curr->next;
		curr->next = t;
		curr = t;
	}
	r = curr;
	while (--u_k)
	{
		r = p;
		p = p->next;
	}
	
	while (u_n)
	{
		int s = u_m;
		while (--s)
		{
			r = p;
			p = p->next;
		}
		r->next = p->next;
		printf("%d->",p->data);
		free(p);
		p = r->next;
		u_n -= 1;
	}
}

int main(void)
{
	josePhus(13,4,2);
	return 0;
}