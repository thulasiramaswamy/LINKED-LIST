#include <stdio.h>
#include <stdlib.h>

struct Node
{
 int dat;
 struct Node *next;
};

/* allocates and returns a new node */
struct Node* new_node(int value)
{
 struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
 temp->dat = value;
 temp->next = NULL;
 return temp;
}

/* Loop removal */
void removeLoop(struct Node* loop_node, struct Node* head)
{
 struct Node* ptr1;
 struct Node* ptr2;

 ptr1 = head;
 printf("\nLoop Detected..!!!\n");
 while (1)
 {
	 ptr2 = loop_node;

   while (ptr2->next != loop_node && ptr2->next != ptr1)
			ptr2 = ptr2->next;

	 if (ptr2->next == ptr1) break;
  ptr1 = ptr1->next;
 }
 ptr2->next = NULL;
 printf("\nLoop Removed..!!!\n");
}

/* Loop Detection */
int detectLoop(struct Node* head)
{
 struct Node* slow = head;
 struct Node* fast = head;

 while (slow && fast && fast->next)
 {
 slow = slow->next;
 fast = fast->next->next;

  if (slow == fast)
  {
	 removeLoop(slow, head);			
	 return 1;
  }
 }
 return 0;
}

/* Prints List */
void printList(struct Node *head_ref)
{
 if (*head_ref == NULL) { printf("\nEmpty List !!! \n"); return; }
 struct Node* temp = head_ref;
	
 while (temp != NULL)
 {
	printf(" %d ", temp->dat);
	temp = temp->next;
 }
}

/* Driver Function */
int main(void)
{
 struct Node* head = new_node(1);
 head->next = new_node(2);
 head->next->next = new_node(3);
 head->next->next->next = new_node(4);
 head->next->next->next->next = new_node(5);
 head->next->next->next->next->next = new_node(6);
 head->next->next->next->next->next->next = new_node(7);
 head->next->next->next->next->next->next->next = new_node(8);
 head->next->next->next->next->next->next->next->next = new_node(9);
 head->next->next->next->next->next->next->next->next->next = new_node(10);

 head->next->next->next->next->next->next->next->next->next = head->next;
 detectLoop(head);
 printList(head);

 getchar();
 return 0;
}
