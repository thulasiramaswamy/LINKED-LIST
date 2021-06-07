/* AUTHOR : THULASI VEGGALAM */
/* C Program to Demonstrate Merge Two Sorted Lists */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int dat;
	struct Node* next;
};
struct Node* new_Node(int value)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->dat = value;
	temp->next = NULL;
	return temp;
}
/* Creates a Fresh list, if the List is empty
*  Appends the Node into the list, if the List is not Empty
*/
void createAndAppend(struct Node** head_ref, int value)
{
	struct Node* temp = *head_ref;
	if (temp != NULL)
	{
		while (temp->next != NULL) temp = temp->next;
		temp->next = new_Node(value);
		return;
	}
	*head_ref = new_Node(value);
}
/*
* Function that merges two sorted Lists
*/
struct Node* merge(struct Node* head1, struct Node* head2)
{
	struct Node* newhead;
	struct Node* sorting = NULL;
	if (head1 == NULL)		return head2;
	if (head2 == NULL)		return head1;
	if (head1 && head2)
	{
		if (head1->dat <= head2->dat)
		{
			sorting = head1;
			head1 = sorting->next;
		}
		else
		{
			sorting = head2;
			head2 = sorting->next;
		}
	}
	newhead = sorting;
	while (head1 && head2)
	{
		if (head1->dat<= head2->dat)
		{
			sorting->next = head1;
			sorting = head1;
			head1 = sorting->next;
		}
		else
		{
			sorting->next = head2;
			sorting = head2;
			head2 = sorting->next;
		}
	}
	if (head1 == NULL)		sorting->next = head2;
	if (head2 == NULL)		sorting->next = head1;
	return newhead;
}
/*
* Driver Function
*/
int main()
{
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;
	struct Node* sortedHead = NULL;
	int i, arr[] = { 1, 3, 5, 7, 9, 11, 12, 14, 15, 16 };
	int arr1[] = { 2, 4, 6, 8, 10 };

	for (i = 0; i < sizeof(arr) / sizeof(int); i++)
		createAndAppend(&head1, *(arr + i));

	for (i = 0; i < sizeof(arr1) / sizeof(int); i++)
		createAndAppend(&head2, *(arr1 + i));

	sortedHead = merge(head1, head2);

	printf("\n Sorted Merged Linked List =>  ");
	while (sortedHead != NULL)
	{
		printf("%d  ", sortedHead->dat);
		sortedHead = sortedHead->next;
	}
	return 0;
}
