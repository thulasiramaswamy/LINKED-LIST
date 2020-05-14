/* AUTHOR : THULASI VEGGALAM */
/* C Program to Demonstrate Merge Two Sorted Lists */

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

/* Creates a node, if List is empty
 * Appends node, if List is not empty
 */
void createAndAppend(struct Node **head_ref, int value)
{
	struct Node* temp = *head_ref;
	if (temp != NULL)
	{
		while (temp->next != NULL) temp = temp->next;
		temp->next = new_node(value);
		return;
	}
	*head_ref = new_node(value);
}

/* Merges two sorted lists and returns head node */
struct Node* sortedMerge(struct Node* a, struct Node* b)
{
	if (a == NULL) return b;
	if (b == NULL) return a;

	struct Node* head = NULL;
	struct Node* tail = NULL;

	/* head and tail initailization */
	if (a->dat <= b->dat)
	{
		head = tail = a;
		a = a->next;
	}
	else
	{
		head = tail = b;
		b = b->next;
	}

	while (a != NULL && b != NULL)
	{
		if (a->dat <= b->dat)
		{
			tail->next = a;
			tail = a;
			a = a->next;
		}
		else
		{
			tail->next = b;
			tail = b;
			b = b->next;
		}
	}

	/* If any of the list has extra nodes in the end
	* Just append in the end
	* Here, If 'a' has nodes left out, attach 'a' to tail
	* else attach 'b' to tail
	*/
	if (a == NULL) tail->next = b;
	else tail->next = a;

	return head;
}

/* Print the list */
void printList(struct Node *head_ref)
{
 /* Base Condition to Check a List is Empty or Not */
 if (head_ref == NULL) 
 { 
  printf("\nEmpty List !!! \n"); 
  return;
 }
 struct Node* temp = head_ref;

 printf("\nElements in the list :\n");
 
 while (temp != NULL)
 {
  printf(" %d ", temp->dat);
  temp = temp->next;
 }
}

/* Driver Function */
int main(void)
{
 struct Node* head1 = NULL;
 struct Node* head2 = NULL;
 
 int i;
 int arr1[] = {1, 10, 15, 45 };
 int arr2[] = { 5, 18, 25, 40, 50, 60 };

for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]) ; i++)
	createAndAppend(&head1, *(arr1+i));

for (i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++)
	createAndAppend(&head2, *(arr2 + i));
	
 struct Node* res = sortedMerge(head1, head2);
 printList(res);
 return 0;
}
