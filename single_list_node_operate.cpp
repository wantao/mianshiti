#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

struct m_Node
{
	int data;
	m_Node* next;
};

typedef struct m_Node* pNode;

pNode linked_list_select_sort(pNode u_head)
{
	pNode first = NULL,tail = NULL,pre_min = NULL,min = NULL,p = NULL;

	while (u_head != NULL)
	{
		for (p = u_head,min = u_head; p->next != NULL; p = p->next)
		{
			if (p->next->data < min->data)
			{
				pre_min = p;
				min = p->next;
			}
		}
		if (first == NULL)
		{
			first = min;
			tail = min;
		}
		else
		{
			tail->next = min;
			tail = min;
		}
		if (min == u_head)
		{
			u_head = u_head->next;
		}
		else
		{
			pre_min->next = min->next;
		}
	}
	if (first->next != NULL)
	{
		tail->next = NULL;
	}
	u_head = first;
	return u_head;
}

pNode create_single_linked_list(const int& u_listLength)
{
	pNode head = NULL,tail = NULL;
	int numberTmp;
	for (int i = 1; i <= u_listLength; i++)
	{
		pNode nodeTmp = (pNode)malloc(sizeof(pNode));
		if (nodeTmp != NULL)
		{
			printf("input the %d th number:",i);
			scanf("%d",&numberTmp);
			nodeTmp->data = numberTmp;
			nodeTmp->next = NULL;
			if (head == NULL)
			{
				head = nodeTmp;
				tail = nodeTmp;
			}
			else
			{
				tail->next = nodeTmp;
				tail = nodeTmp;
			}
			tail->next = NULL;
		}
		else
		{
			printf("%d th node malloc failure\n",i);
		}
	}
	return head;
}

void print_single_linked_list(pNode u_head)
{
	pNode p = u_head;
	while (p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

pNode insert_node(pNode u_head,const int& u_number)
{
	pNode p1 = NULL,p2 = NULL;
	u_head = linked_list_select_sort(u_head);
	p1 = u_head;
	p2 = u_head;
	while (p1 != NULL)
	{
		if (p1->data >= u_number)
		{
			break;
		}
		p2 = p1;
		p1 = p1->next;
	}
	pNode insertNode = (pNode)malloc(sizeof(pNode));
	insertNode->data = u_number;
	insertNode->next = NULL;
	if (insertNode == NULL)
	{
		printf("insert %d failure\n",u_number);
		return u_head;
	}
	if (p2 == u_head)
	{
		u_head = insertNode;
		u_head->next = p2;
	}
	else
	{
		p2->next = insertNode;
		insertNode->next = p1;
	}

	return u_head;
}

pNode node_del(pNode u_head,const int& u_number)
{
	pNode p = NULL,p_pre = NULL;
	p = u_head;

	while (p != NULL && p->data != u_number)
	{
		p_pre = p;
		p = p->next;
	}
	if (p_pre != NULL)
	{
		p_pre->next = p->next;
		free(p);
		p = NULL;
	}
	return u_head;
}

void free_single_linked_list(pNode u_head)
{
	pNode p = NULL;
	
	while (u_head != NULL)
	{
		p = u_head;
		u_head = u_head->next;	
		free(p);
		p = NULL;
	}
}

int get_single_linked_list_length(pNode u_head)
{
	int retLength = 0;
	pNode p = u_head;
	while (p != NULL)
	{
		retLength += 1;
		p = p->next;
	}
	return retLength;
}

pNode single_linked_link_insert_sort(pNode u_head)
{
	pNode first; /*Ϊԭ����ʣ������ֱ�Ӳ�������Ľڵ�ͷָ��*/
	pNode t; /*��ʱָ�����������ڵ�*/
	pNode p; /*��ʱָ�����*/
	pNode q; /*��ʱָ�����*/

	first = u_head->next; /*ԭ����ʣ������ֱ�Ӳ�������Ľڵ������ɸ���ͼ12����⡣*/
	u_head->next = NULL; /*ֻ����һ���ڵ����������������ɸ���ͼ11����⡣*/

	while (first != NULL) /*����ʣ�����������*/
	{
		/*ע�⣺����for����������ֱ�Ӳ�������˼��ĵط�*/
		for (t=first, q=u_head; ((q!=NULL) && (q->data < t->data)); p=q, q=q->next); /*����ڵ��������������Ҳ����λ��*/

		/*�˳�forѭ���������ҵ��˲����λ��*/
		/*ע�⣺��������˵����仰���Էŵ�����ע���˵��Ǹ�λ��ҲӦ�öԵģ����Ǿ��ǲ��ܡ�ԭ���������������ĵ�3������֪���ˡ�*/
		first = first->next; /*���������еĽڵ��뿪���Ա������뵽���������С�*/

		if (q == u_head) /*���ڵ�һ���ڵ�֮ǰ*/
		{
			u_head = t;   
		}
		else /*p��q��ǰ��*/
		{
			p->next = t;  
		}
		t->next = q; /*��ɲ��붯��*/
		/*first = first->next;*/
	}
	return u_head;
}

pNode single_linked_list_bubble_sort(pNode u_head)
{
	if (u_head != NULL)
	{
		pNode pre = NULL;
		pNode p = NULL;
		int temp = 0;
		int listLength = get_single_linked_list_length(u_head);
		
		for (int j = 1; j < listLength; j++)
		{
			p = u_head;
			for (int i = 0; i < listLength-j; i++)
			{
				if (p->data > p->next->data)
				{
					temp = p->data;
					p->data = p->next->data;
					p->next->data = temp;
				}
				p = p->next;
			}
		}
	}
	return u_head;
}

pNode single_link_list_reverse(pNode u_head)
{
	pNode p1 = NULL;
	pNode p2 = NULL;
	pNode p3 = NULL;

	p1 = u_head;
	p2 = p1->next;

	while (p2)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	u_head->next = NULL;
	u_head = p1;
	return u_head;
}

pNode single_linked_list_del_head_node(pNode u_head)
{
	if (u_head != NULL)
	{
		pNode p = u_head;
		u_head = p->next;
		free(p);
		p = NULL;
	}
	return u_head;
}

int main(void)
{
	int listLength = 0;
	pNode singleLinkedList = NULL;
	printf("input the list length:");
	scanf("%d",&listLength);
	singleLinkedList = create_single_linked_list(listLength);
	printf("before sort:");
	print_single_linked_list(singleLinkedList);

	/*singleLinkedList = linked_list_select_sort(singleLinkedList);
	printf("after sort:");
	print_single_linked_list(singleLinkedList);
	
	int insertData = 0;
	printf("input the insertData:");
	scanf("%d",&insertData);
	singleLinkedList = insert_node(singleLinkedList,insertData);
	printf("after insert:");
	print_single_linked_list(singleLinkedList);

	int delData = 0;
	printf("input the delData:");
	scanf("%d",&delData);
	singleLinkedList = node_del(singleLinkedList,delData);
	printf("after del:");
	print_single_linked_list(singleLinkedList);
	singleLinkedList = single_linked_link_insert_sort(singleLinkedList);
	printf("after insert sort:");
	print_single_linked_list(singleLinkedList);*/

	/*printf("after bubble sort:");
	singleLinkedList = single_linked_list_bubble_sort(singleLinkedList);
	print_single_linked_list(singleLinkedList);

	printf("after reverse :");
	singleLinkedList = single_link_list_reverse(singleLinkedList);
	print_single_linked_list(singleLinkedList);*/

	printf("after del head:");
	singleLinkedList = single_linked_list_del_head_node(singleLinkedList);
	print_single_linked_list(singleLinkedList);

	free_single_linked_list(singleLinkedList);
	return 0;
}