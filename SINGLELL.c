// C Program to Demonstrate the Simple Linked List Operations
/******************************************************/
/***********  AUTHOR - THULASI VEGGALAM	***************/
/******************************************************/
/*
THE FOLLOWING PROGRAM COVERS THE OPERATIONS IN THE LIST
1. CREATES THE LIST
2. APPENDS INTO THE LIST
3. INSERT AT THE SPECIFIED POSITION
4. SEARCH THE ELEMENT IN THE LIST
5. GET THE LENGTH OF LIST
6. ADDING THE NODE AT THE BEGINING OF THE LIST
7. PRINTS THE LIST
*/
#include <stdio.h>
#include <stdlib.h>
/* A Simple and Typical Node Structure */
struct Node
{
	int dat;
	struct Node *next;
};
/* Allocates memory dynamically and returns a new node */
struct Node* new_node(int value)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->dat = value;
	temp->next = NULL;
	return temp;
}
/* Creates a Fresh list, if the List is empty
*  Appends the Node into the list, if the List is not Empty
*/
void createAndAppend(struct Node **head_ref, int value)
{
	struct Node* temp = *head_ref;
	if(temp != NULL)
	{
		while(temp->next != NULL) temp = temp->next;
		temp->next = new_node(value);
		return;
	}
	*head_ref = new_node(value);
}
/* Calculates the Length of the List and Returns */
int length(struct Node **head_ref)
{
	/* Base Condition to Check a List is Empty or Not */
	int Cnt = 0;
	if(*head_ref == NULL) return 0;
	struct Node* temp = *head_ref;
	while(temp != NULL)
	{		
		temp = temp->next;
		Cnt++;
	}
	return Cnt;
}
/* Insert the Node at the Starting Position  */
void addNodeAtBegining(struct Node** head_ref, int value)
{
	struct Node* temp = new_node(value);
	temp->next = *head_ref;
	*head_ref = temp;
}
/* Insert the Node at the Desired Position  */
void insertAtLocation(struct Node **head_ref, int Position, int value)
{
	int i, lengthOfTheList = length(head_ref);
	struct Node *temp = *head_ref;
	if( *head_ref == NULL || Position > lengthOfTheList ) { printf("\n%d is invalid position to insert", Position); return; }
	if(Position == 1 ) { addNodeAtBegining(head_ref, value); return; }
	else
	{
		for( i = 0 ; i < Position - 2 ; i++ ) temp = temp->next;
		struct Node* newNode = new_node(value);
		newNode->next = temp->next;
		temp->next = newNode;
	}
}
/* Prints the list */
void printList(struct Node **head_ref)
{
	/* Base Condition to Check a List is Empty or Not */
	if(*head_ref == NULL) { printf("\nEmpty List !!! \n"); return; }
	struct Node* temp = *head_ref;
	printf("\nElements in the list :\n");
	while(temp != NULL)
	{
		printf(" %d ", temp->dat);
		temp = temp->next;
	}
}
/* Driver Function */
int main(void)
{
	struct Node* head = NULL;
	/* creating a list with the first element and then appending with the list of array of values */
	int i, arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for( i = 0 ; i < sizeof(arr)/sizeof(int) ; i++ )
		createAndAppend(&head, *(arr+i));
	printList(&head);
	insertAtLocation(&head, 1, 34);
	printList(&head);
	getchar();	
	return 0;
}
