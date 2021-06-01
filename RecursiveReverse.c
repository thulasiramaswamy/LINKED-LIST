include <stdio.h>
#include <stdlib.h>
struct Node
{
	int dat;
	struct Node* next;
};
struct Node* newNode(int value)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->dat = value;
	temp->next = NULL;
	return temp;
}
void create(struct Node** head, int value)
{
	struct Node* temp = *head;
	if (temp != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newNode(value);
		return;
	}
	*head = newNode(value);
}
void printList(struct Node* head)
{
	if (head == NULL)  { printf("\nEmpty List !!!"); return; }
	struct Node* temp = head;
	while (temp != NULL)
	{
		printf(" %d ", temp->dat);
		temp = temp->next;
	}
}
struct Node* recursiveReverse(struct Node* head)
{
	if (head == NULL || head->next == NULL) return head;
	struct Node* rest = recursiveReverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return rest;
}
int main(void)
{
	struct Node* head = NULL;
	int i, arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (i = 0; i < sizeof(arr) / sizeof(int); i++)
		create(&head, arr[i]);	
	printList(head);
	head = recursiveReverse(head);
	printList(head);
	getchar();
	return 0;
}
