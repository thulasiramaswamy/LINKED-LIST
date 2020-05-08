// C Program to demonstrate Circular Singly Linked List
/******************************************************/
/***********  AUTHOR - THULASI VEGGALAM	***************/
/******************************************************/
/* The following operations covered in this program
1. Create a node in an empty circular list
2. Append at the end of a circular list
3. Add at begining of a circular list
4. Add after specified node
5. Check whether the list is Circular or Not
6. Delete a given key
 */

#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node
{
 int data;
 struct Node *next;
};
/* returns a new node */
struct Node* newNode(int value)
{
 struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
 temp->data = value;
 temp->next = NULL;
 return temp;
}

/* Adds a Node to an Empty List */
struct Node *addToEmpty(struct Node *last, int value)
{
 if (last != NULL)
 	return last;

 last = newNode(value);	
 last->next = last;
 return last;
}

/* Adds a Node at the begining of the List */
struct Node *addBegin(struct Node *last, int value)
{
 if (last == NULL)
 	return addToEmpty(last, value);

 struct Node* temp = newNode(value);	

 temp->next = last->next;
 last->next = temp;
 return last;
}

/* Adds a Node at the end of the List */
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
void deleteNode(struct Node** head, int key)
{
 struct Node* temp = *head;	
 if (temp == NULL)
	return;
	
 if (temp->dat == key && temp->next == *head)
 {
	free(temp);
	temp = NULL;
 }

 struct Node *last = *head, *toDel;
 if (temp->dat == key)
 {		
 	while (last->next != temp)
		last = last->next;

	last->next = temp->next;
	free(temp);
	temp = last->next;
 }
 while (last->next != *head && last->next->dat != key)
 {
	last = last->next;
 }
 if (last->next->dat == key)
 {
	toDel = last->next;
	last->next = toDel->next;
	free(toDel);
 }
 else
	printf("\nKey Not Found !!! \n\n");
}
void printList(struct Node *last)
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
 deleteNode(&last, 20);
 if (isCircular(&last))
	printf("\nCircular LL\n");
 else
	printf("\n Not a Circular LL\n");

 printList(last);
 printf("\n\n");
 return 0;
}
