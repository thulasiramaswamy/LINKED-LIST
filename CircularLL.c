// C Program to demonstrate Circular Linked List
// Create a node in an empty circular list
// Append at the end of a circular list
// Add at begining of a circular list
// Add after specified node
// Check whether the list is Circular or Not

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};
struct Node* newNode(int value)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = value;
	temp->next = NULL;
	return temp;
}
struct Node *addToEmpty(struct Node *last, int value)
{
	if (last != NULL)
		return last;

	last = newNode(value);	
	last->next = last;
	return last;
}
struct Node *addBegin(struct Node *last, int value)
{
	if (last == NULL)
		return addToEmpty(last, value);

	struct Node* temp = newNode(value);	

	temp->next = last->next;
	last->next = temp;
	return last;
}
struct Node *addEnd(struct Node *last, int value)
{
	if (last == NULL)
		return addToEmpty(last, value);
	
	struct Node* temp = newNode(value);
	temp->next = last->next;
	last->next = temp;	
	last = temp;	
	return last;
}
struct Node *addAfter(struct Node *last, int value, int item)
{
	if (last == NULL)
		return NULL;

	struct Node *temp, *p;
	p = last->next;
	do
	{
		if (p->data == item)
		{
			temp = newNode(value);
			temp->next = p->next;
			p->next = temp;

			if (p == last)	last = temp;
			return last;
		}
		p = p->next;
	} while (p != last->next);
	printf("\n%d is not present in the list", item);
	return last;
}
void display(struct Node *last)
{
	struct Node *p;
	if (last == NULL) 
	{ 
		printf("\n List is empty"); 
		return; 
	}
	p = last->next;
	do	
	{ 
		printf(" %d", p->data);	
		p = p->next; 
	} while (p != last->next);
}
// Store head of the linked list and traverse it.
// If we reach NULL, linked list is not circular.
// If reach head again, linked list is circular
int isCircular(struct Node** head)
{
	if (*head == NULL) return 1;
	struct Node* temp = *head;
	while (temp != NULL && temp != *head)
		temp = temp->next;

	return (temp == *head);
}
int main()
{
	struct Node *last = NULL;

	last = addToEmpty(last, 6);
	last = addBegin(last, 4);
	last = addBegin(last, 2);

	last = addEnd(last, 8);
	last = addEnd(last, 12);
	last = addAfter(last, 10, 8);

	if (isCircular(&last))
		printf("\nCircular LL\n");
	else
		printf("\n Not a Circular LL\n");

	display(last);
	printf("\n\n");
	return 0;
}
