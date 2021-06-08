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
6. Delete element at First Position
7. Delete element at Last Position
*/

#include <stdio.h>
#include <stdlib.h>

/*
* Node Structure
*/
struct Node
{
	int dat;
	struct Node* next;
};

/*
*  Create a Node when the List is Empty
*/
struct Node* addToEmpty(int value)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->dat = value;
	temp->next = temp;
	return temp;
}
/*
* Add an element at the Begining of the List
*/
struct Node* addAtBeg(struct Node* tail, int value)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->dat = value;
	newnode->next = tail->next;
	tail->next = newnode;
	return tail;
}
/*
* Add an element at the End of the List
*/
struct Node* addAtEnd(struct Node* tail, int value)
{
	if (tail == NULL)
		return addToEmpty(tail, value);
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->dat = value;
	newnode->next = tail->next;
	tail->next = newnode;
	tail = tail->next;
	return tail;
}
/*
* Add an element at the Specified Position of the List
*/
struct Node* addAtPos(struct Node* tail, int value, int Pos)
{
	struct Node* p = tail->next;
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->dat = value;
	int i;
	for (i = 0; i < Pos - 2; i++)
		p = p->next;

	newnode->next = p->next;
	p->next = newnode;

	if (p == tail)
		tail = tail->next;
	return tail;
}
/*
* Deletes the Last Element in the List
*/
struct Node* delLast(struct Node* tail)
{
	if (tail == NULL) return tail;
	struct Node* temp = tail->next;
	if (tail->next == tail)
	{
		free(tail);
		tail = NULL;
		return tail;
	}
	while (temp->next != tail)
		temp = temp->next;
	temp->next = tail->next;
	free(tail);
	tail = temp;
	return tail;
}
/*
* Deletes the First Element in the List
*/
struct Node* delFirst(struct Node* tail)
{
	if (tail == NULL) return tail;
	if (tail->next == tail)
	{
		free(tail);
		tail = NULL;
		return tail;
	}
	struct Node* temp = tail->next;
	tail->next = temp->next;
	free(temp);
	temp = NULL;
	return tail;
}
/*
* Prints the elements in the List
*/
void printList(struct Node* tail)
{
	if (tail == NULL) { printf("List is empty !!! ");  return; }
	struct Node* p = tail->next;
	do
	{
		printf(" %d ", p->dat);
		p = p->next;
	} while (p != tail->next);
}
/*
* Prints the Size of the List
*/
void size(struct Node* tail)
{
	if (tail == NULL) { printf("List is empty !!! ");  return; }
	struct Node* p = tail->next;
	int Cnt = 0;
	do
	{
		p = p->next;
		Cnt++;
	} while (p != tail->next);
	printf("\nSize of the List : %d\n", Cnt);
}
/*
* Driver Function
*/
int main(void)
{
	struct Node* tail;
	tail = addToEmpty(10);
	tail = addAtBeg(tail, 5);
	tail = addAtEnd(tail, 15);
	tail = addAtEnd(tail, 20);
	tail = addAtEnd(tail, 25);
	tail = addAtEnd(tail, 30);
	tail = addAtPos(tail, 18, 3);
	tail = delLast(tail);
	tail = delFirst(tail);
	printList(tail);
	size(tail);
	return 0;
}
