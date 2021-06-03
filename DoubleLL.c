/* C Program to Demonstrate Double Linked List and Operations */
/*
* AUTHOR : THULASI VEGGALAM
*/

#include <stdio.h>
#include <stdlib.h>

/* Double Linked List Node Structure */
struct Node
{
	struct Node* prev;
	int dat;
	struct Node* next;
};
/* Allocates memory and returns a Node */
struct Node* newNode(int value)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->dat = value;
	temp->next = temp->prev = NULL;
	return temp;
}
/* 
*  Creates the List, If List is Empty
*  Appends into the List, If List is not Empty
*/
void createAndAppend(struct Node** head, int value)
{
	struct Node* temp = *head;
	struct Node* newnode = newNode(value);
	if (temp != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
		newnode->prev = temp;
		return;
	}
	*head = newnode;
}
/*
*  Add a node at the begining
*/
void addAtBegining(struct Node** head, int value)
{
	struct Node* newnode = newNode(value);
	if (*head == NULL) { *head = newnode; return; }
	(*head)->prev = newnode;
	newnode->next = *head;
	*head = newnode;	
}
/* Add at specified position */
void addAtPosition(struct Node** head, int Pos, int value)
{
	struct Node* temp = *head;
	struct Node* newnode = newNode(value);
	int i;
	for (i = 0; i < Pos - 2; i++)
		temp = temp->next;

	newnode->next = temp->next;
	newnode->prev = temp;
	temp->next = newnode;
}
/* Prints the elements in the List */
void printList(struct Node* head)
{
	if (head == NULL) { printf("\nList is Empty !!! \n");  return; }
	struct Node* temp = head;
	while (temp != NULL)
	{
		printf(" %d ", temp->dat);
		temp = temp->next;
	}
	printf("\n");
}
/* Driver Program */
int main(void)
{
	struct Node* head = NULL;
	int i, arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		createAndAppend(&head, arr[i]);
	printList(head);
	addAtPosition(&head, 5, 12);
	printList(head);
	return 0;
}
