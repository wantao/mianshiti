#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct bTree
{
	int data;
	struct bTree* left;
	struct bTree* right;
};

typedef struct bTree* pBTree;

pBTree create_bTree()
{
	pBTree root = NULL;
	int inputNumber = 0;
	printf("input node number:");
	scanf("%d",&inputNumber);
	if (inputNumber != 0)
	{
		root = (pBTree)malloc(sizeof(pBTree));
		if (root != NULL)
		{
			
			root->data = inputNumber;
			root->left = create_bTree();
			root->right = create_bTree();
		}
		else
		{
			printf("create bTree failure:malloc error\n");
			return NULL;
		}
	}
	return root;
}

void binary_tree_visit_pre_order(pBTree u_bTree)
{
	if (u_bTree != NULL)
	{
		printf("%d->",u_bTree->data);
		binary_tree_visit_pre_order(u_bTree->left);
		binary_tree_visit_pre_order(u_bTree->right);
	}
}	

void binary_tree_visit_in_order(pBTree u_bTree)
{
	if (u_bTree != NULL)
	{
		binary_tree_visit_in_order(u_bTree->left);
		printf("%d->",u_bTree->data);
		binary_tree_visit_in_order(u_bTree->right);
	}
}

void binary_tree_visit_post_order(pBTree u_bTree)
{
	if (u_bTree != NULL)
	{
		binary_tree_visit_post_order(u_bTree->left);
		binary_tree_visit_post_order(u_bTree->right);
		printf("%d->",u_bTree->data);
	}
}

int compare_tree(pBTree u_bTree1,pBTree u_bTree2)
{
	if (!u_bTree1 && !u_bTree2)
	{
		return 1;
	}
	if ((!u_bTree1 && u_bTree2) || (u_bTree1 && !u_bTree2))
	{
		return 0;
	}
	if (u_bTree1 && u_bTree2)
	{
		if (u_bTree1->data == u_bTree2->data)
		{
			if (compare_tree(u_bTree1->left,u_bTree2->left))
			{
				return compare_tree(u_bTree1->right,u_bTree2->right);
			}
			else if (compare_tree(u_bTree1->left,u_bTree2->right))
			{
				return compare_tree(u_bTree1->right,u_bTree2->left);
			}
		}
	}
	return 0;
}


int main(void)
{
	pBTree bTree1 = NULL,bTree2 = NULL;
	bTree1 = create_bTree();
	printf("\n bTree1 preOrder visit:");
	binary_tree_visit_pre_order(bTree1);
	printf("\n bTree1 inOrder visit:");
	binary_tree_visit_in_order(bTree1);
	printf("\n bTree1 postOrder visit:");
	binary_tree_visit_post_order(bTree1);

	bTree2 = create_bTree();
	printf("\n bTree2 preOrder visit:");
	binary_tree_visit_pre_order(bTree2);
	printf("\n bTree2 inOrder visit:");
	binary_tree_visit_in_order(bTree2);
	printf("\n bTree2 postOrder visit:");
	binary_tree_visit_post_order(bTree2);

	int compResult = compare_tree(bTree1,bTree2);
	if (compResult == 1)
	{
		printf("\n bTree1 bTree2 is equal\n");
	}
	else
	{
		printf("\n bTree1 bTree2 is not equal\n");
	}
	return 0;
}