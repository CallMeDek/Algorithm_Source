// realtest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

typedef struct node Node;

int main()
{
	Node* p;
	Node* temp;
	Node* head;

	head = (Node*)malloc(sizeof(Node));

	head->data = 0;
	head->next = NULL;

	p = head;
	
	temp = (Node*)malloc(sizeof(Node));
	temp->data = 1;
	temp->next = NULL;

	p->next = temp;

	printf("%d testing \n", head->next->data);

    return 0;
}

