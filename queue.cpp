#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
	int data;
	struct node* next;
};

typedef struct node* pNode;

struct linkedQueue
{
	pNode front;
	pNode rear;
};

typedef struct linkedQueue* pLinkedQueue;

pLinkedQueue createQueue()
{
	int queueLength = 0;
	int inputNumber = 0;
	pLinkedQueue retQueue = NULL;
	retQueue = (pLinkedQueue)malloc(sizeof(pLinkedQueue));
	if (retQueue != NULL)
	{
		retQueue->front = NULL;
		retQueue->rear = NULL;
	}
	printf("\n input init queue length:");
	scanf("%d",&queueLength);
	for (int i = 1; i <= queueLength; i++)
	{
		printf("\n input %d th value:",i);
		scanf("%d",&inputNumber);
		pNode tmp = (pNode)malloc(sizeof(pNode));
		if (tmp != NULL)
		{
			tmp->data = inputNumber;
			tmp->next = NULL;
			if (retQueue->front == NULL)
			{
				retQueue->front = tmp;
				retQueue->rear = tmp;
			}
			else
			{
				retQueue->rear->next = tmp;
				retQueue->rear = tmp;
			}
		}
		else
		{
			printf("createQueue malloc tmp Node failure\n");
			return NULL;
		}
	}
	return retQueue;
}

void freeQueue(pLinkedQueue& u_head)
{
	pNode p = NULL;
	if (u_head != NULL)
	{
		p = u_head->front;
		while (p != NULL)
		{
			u_head->front = p->next;
			free(p);
			p = p->next;
		}
		if (u_head != NULL)
		{
			u_head->front = NULL;
			u_head->rear = NULL;
			free(u_head);
			u_head = NULL;
		}
	}
}

void print_linked_queue(pLinkedQueue u_head)
{
	if (u_head != NULL)
	{
		pNode p = u_head->front;
		while (p != NULL)
		{
			printf("%d ",p->data);
			p = p->next;
		}
	}
	printf("\n");
}

pLinkedQueue queue_insert(pLinkedQueue head,const int& u_insertNumber)
{
	pNode tmpNode = (pNode)malloc(sizeof(pNode));
	
	if(tmpNode == NULL)
	{
		printf("queue_insert tmpNode new failure\n");
	}
	if (tmpNode != NULL)
	{
		tmpNode->data = u_insertNumber;
		tmpNode->next = NULL;
	}
	if (head->rear == NULL)
	{
		head->front = tmpNode;
		head->rear =tmpNode;
	}
	else
	{
		head->rear->next = tmpNode;
		head->rear = tmpNode;
	}

	return head;
}

pLinkedQueue queue_del(pLinkedQueue head)
{
	if (head->front == NULL)
	{
		printf("queue_del head->front is NULL");
	}
	else
	{
		pNode p = head->front;
		head->front = head->front->next;
		free(p);
		p = NULL;
	}
	return head;
}

int main(void)
{
	int queueLength = 0;
	pLinkedQueue queueHead = NULL;
	queueHead = createQueue();
	print_linked_queue(queueHead);

	int insertNumber = 0;
	printf("\n input insertNumber:");
	scanf("%d",&insertNumber);
	queueHead = queue_insert(queueHead,insertNumber);
	print_linked_queue(queueHead);

	/*queueHead = queue_del(queueHead);
	print_linked_queue(queueHead);*/

	freeQueue(queueHead);

	print_linked_queue(queueHead);
	
	return 0;
}