#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int dat;
	struct Node* next;
};
struct Node* head = NULL;
struct Node* newNode(int value)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->dat  = value;
	temp->next = NULL;
	return temp;
}

void create(struct Node** head, int value)
{
	*head = newNode(value);	
}
void addAtEnd(struct Node** root, int value)
{
	struct Node* temp = *root;
	if (temp != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newNode(value);
		return;
	}
}
void createAndAppend(struct Node** head, int value)
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
void addAtBegin(struct Node** head, int value)
{
	struct Node* temp = newNode(value);
	temp->next = *head;
	*head = temp;
}
void addAtPos(struct Node** head, int pos, int value)
{
	struct Node* newnode = newNode(value);
	struct Node* temp = *head;
	int i;
	for (i = 1; i < pos - 1; i++)
		temp = temp->next;

	newnode->next = temp->next;
	temp->next = newnode;
}
void addMiddle(struct Node** head, int value)
{
	struct Node* newnode = newNode(value);
	struct Node* slow = *head;
	struct Node* fast = (*head)->next;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	newnode->next = slow->next;
	slow->next = newnode;
}
void addAfter(struct Node** head, int after, int value)
{
	struct Node* temp = *head;
	struct Node* newnode = newNode(value);

	while (temp && temp->dat != after)
		temp = temp->next;		
	newnode->next = temp->next;
	temp->next = newnode;
}
void delKey(struct Node** head, int key)
{
	struct Node* temp = *head;
	struct Node* prev = NULL;
	while (temp && temp->dat != key)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	free(temp);
}
void delAfter(struct Node** head, int after)
{
	struct Node* temp = *head;
	struct Node* temp1 = NULL;
	while (temp && temp->dat != after)
		temp = temp->next;
	temp1 = temp->next;
	temp->next = temp1->next;
	free(temp1);
}
void delPos(struct Node** head, int Pos)
{
	struct Node* temp = *head;
	struct Node* temp1;
	int i;
	for (i = 1; i < Pos - 1; i++)
		temp = temp->next;
	temp1 = temp->next;
	temp->next = temp1->next;
	free(temp1);
}
void delList(struct Node** head)
{
	struct Node* curr = *head;
	struct Node* next;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*head = NULL;
}
void delWithOnlyOnePointer(struct Node* ptr)
{
	struct Node* temp = ptr->next;
	ptr->dat = temp->dat;
	ptr->next = temp->next;
	free(temp);
}
void delMiddle(struct Node** head)
{
	struct Node* slow = *head;
	struct Node* fast = *head;
	struct Node* temp;
	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	temp = slow->next;
	slow->next = temp->next;
	free(temp);
}
void deletelastOccurence(struct Node **head, int d)
{
	struct Node *current = *head;
	struct Node *prev = NULL;
	struct Node *match = NULL;

	if (current == NULL)
	{
		printf("list is empty\n");
		return;
	}
	// If there is only one node in the list
	if (current->next == NULL)
	{
		if (current->dat == d)
		{
			free(current);
			*head = NULL;
		}
		else
			printf(" No match\n");
		return;
	}	
	while (current && current->next)
	{
		if (current->next->dat == d)
		{
			prev = current;
			match = current->next;
		}
		current = current->next;
	}
	if (prev)
	{
		prev->next = match->next;
		free(match);
	}
	else
	{		
		if ((*head)->dat == d)
		{
			current = *head;
			*head = current->next;
			printf("element is at head Delete %d\n", current->dat);
			free(current);
		}
		else
			printf("No match\n");
	}
}
void deleteMNodesAfterNodes(struct Node* head, int M, int N)
{
	struct Node* curr = head;
	struct Node* t;
	struct Node* temp;
	int Cnt;
	while (curr)
	{
		for (Cnt = 1; Cnt < M && curr != NULL; Cnt++)
			curr = curr->next;
		if (curr == NULL) return;
		t = curr->next;
		for (Cnt = 1; Cnt <= N && t != NULL; Cnt++)
		{
			temp = t;
			t = t->next;
			free(temp);
		}
		curr->next = t;
		curr = t;
	}
}
void deleteNode(struct Node** head_ref, struct Node* del)
{	
	struct Node* temp = *head_ref;
	if (*head_ref == NULL || del == NULL)
		return;

	if (*head_ref == del)
		*head_ref = del->next;

	while (temp->next != del) 
		temp = temp->next;
	
	temp->next = del->next;	
	free(del);
	return;
}
int isPrime(int N)
{
	int i, Cnt = 1;
	for (i = 1; i < N; i++)
	{
		if (N % i == 0)
			Cnt++;
	}
	if (Cnt == 2)
		return 1;
	else return 0;
}
void deleteAllPrimes(struct Node** head)
{
	struct Node* ptr = *head;
	struct Node* next;

	while (ptr != NULL) 
	{
		next = ptr->next;	
		if (isPrime(ptr->dat))
			deleteNode(head, ptr);
		ptr = next;
	}
}
void removeDupSorted(struct Node** head)
{
	struct Node* temp = *head;
	struct Node* temp1;
	while (temp->next != NULL)
	{
		if (temp->dat == temp->next->dat)
		{
			temp1 = temp->next->next;
			free(temp->next);
			temp->next = temp1;
		}
		else
			temp = temp->next;
	}
}
void removeDupUnSorted(struct Node *start)
{
	struct Node *ptr1, *ptr2, *dup;
	ptr1 = start;
	
	while (ptr1 != NULL && ptr1->next != NULL)
	{
		ptr2 = ptr1;
		/* Compare the picked element with rest	of the elements */
		while (ptr2->next != NULL)
		{
			/* If duplicate then delete it */
			if (ptr1->dat == ptr2->next->dat)
			{				
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				free(dup);
			}
			else
				ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}
/*
C++ version
void removeDup(struct Node* head)
{
	unordered_set<int> seen;
	struct Node* curr = head;
	struct Node* prev = NULL;
	while (curr != NULL)
	{
		if (seen.find(curr->dat) != seen.end())
		{
			prev->next = curr->next;
			delete(curr);
		}
		else
		{
			seen.insert(curr->dat);
			prev = curr;
		}
		curr = prev->next;
	}
}*/

void loopRemoval(struct Node** head, struct Node* loopNode)
{
	struct Node* ptr1 = *head;
	struct Node* ptr2 = loopNode;

	while (1)
	{
		while (ptr2->next != ptr1 && ptr2->next != loopNode)
			ptr2 = ptr2->next;
		if (ptr2->next == ptr1) break;
		ptr1 = ptr1->next;
	}
	ptr2->next = NULL;
}
void loopDetect(struct Node** head)
{
	struct Node* ptr1 = *head;
	struct Node* ptr2 = *head;
	int Cnt = 0;
	while (ptr1 && ptr2 && ptr2->next)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
		Cnt++;
		if (ptr1 == ptr2)
		{
			printf("Loop Found...");
			printf("\n Length of the loop : %d ", Cnt);
			//loopRemoval(&head, ptr1);
			return;
		}
	}
	printf("\nNo Loop found...");
}
void reverse(struct Node** head)
{
	struct Node* curr = *head;
	struct Node* prev = NULL;
	struct Node* next;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}
void reversePrint(struct Node* head)
{
	if (head == NULL) return;
	reversePrint(head->next);
	printf(" %d ", head->dat);
}
struct Node* reverseRecur(struct Node* node)
{
	if (node == NULL)
		return NULL;
	if (node->next == NULL) 
	{
		head = node;
		return node;
	}
	struct Node* node1 = reverseRecur(node->next);
	node1->next = node;
	node->next = NULL;
	return node;
}
struct Node *reverseGroups(struct Node *head, int k)
{
	struct Node* current = head;
	struct Node* next = NULL;
	struct Node* prev = NULL;
	int count = 0;

	while (current != NULL && count < k)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}

	if (next != NULL)
		head->next = reverseGroups(next, k);
	return prev;
}
struct Node *kAltReverse(struct Node *head, int k)
{
	struct Node* current = head;
	struct Node* next;
	struct Node* prev = NULL;
	int count = 0;

	/*1) reverse first k nodes of the linked list */
	while (current != NULL && count < k)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}

	/* 2) Now head points to the kth node. So change next
	of head to (k+1)th node*/
	if (head != NULL)
		head->next = current;

	/* 3) We do not want to reverse next k nodes. So move the current
	pointer to skip next k nodes */
	count = 0;
	while (count < k - 1 && current != NULL)
	{
		current = current->next;
		count++;
	}

	/* 4) Recursively call for the list starting from current->next.
	And make rest of the list as next of first node */
	if (current != NULL)
		current->next = kAltReverse(current->next, k);

	/* 5) prev is new head of the input list */
	return prev;
}
int getNthNode(struct Node** head, int N)
{
	struct Node* ptr1 = *head;
	int Cnt = 1;
	while (Cnt < N)
	{
		ptr1 = ptr1->next;
		Cnt++;
	}
	return ptr1->dat;
}
int getNthNodeFromEnd(struct Node** head, int N)
{
	struct Node* ptr1 = *head;
	struct Node* ptr2 = *head;
	int Cnt = 0;
	while (Cnt < N)
	{
		ptr1 = ptr1->next;
		Cnt++;
	}
	while (ptr1 && ptr2)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return ptr2->dat;
}

void swapNodes(struct Node **head_ref, int x, int y)
{
	// Nothing to do if x and y are same 
	if (x == y) return;

	// Search for x (keep track of prevX and CurrX 
	struct Node *prevX = NULL, *currX = *head_ref;
	while (currX && currX->dat != x)
	{
		prevX = currX;
		currX = currX->next;
	}

	// Search for y (keep track of prevY and CurrY 
	struct Node *prevY = NULL, *currY = *head_ref;
	while (currY && currY->dat != y)
	{
		prevY = currY;
		currY = currY->next;
	}

	// If either x or y is not present, nothing to do 
	if (currX == NULL || currY == NULL)
		return;

	// If x is not head of linked list 
	if (prevX != NULL)
		prevX->next = currY;
	else // Else make y as new head 
		*head_ref = currY;

	// If y is not head of linked list 
	if (prevY != NULL)
		prevY->next = currX;
	else  // Else make x as new head 
		*head_ref = currX;

	// Swap next pointers 
	struct Node *temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
}

/*O(m+n) time and O(1) auxiliary space */
struct Node* mergeTwoSortedLists(struct Node* a, struct Node* b)
{
	if (a == NULL)return b;
	if (b == NULL)return a;

	struct Node* head = NULL;
	struct Node* tail = NULL;

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
	if (a == NULL)
		tail->next = b;
	else
		tail->next = a;
	return head;
}
void push(struct Node** head, int value)
{
	struct Node* temp = newNode(value);
	temp->next = *head;
	printf("\n%d pushed into the stack", value);
	*head = temp;
}
void pop(struct Node** head)
{
	if (*head == NULL) { printf("\n\nStack is empty !!! Nothing to pop...\n\n"); return; }
	struct Node* temp = *head;
	*head = temp->next;	
	//printf("\n%d popped out", temp->dat);
	free(temp);
}
int getTop(struct Node* head)
{
	if (head == NULL) { printf("\n\nStack is empty !!! Nothing to pop...\n\n"); return -1; }
	return head->dat;
}
void sortedInsert(struct Node** head, struct Node* newnode)
{	
	if (*head == NULL || (*head)->dat >= newnode->dat)
	{
		newnode->next = *head;
		*head = newnode;
		return;
	}

	struct Node* curr = *head;
	while (curr->next != NULL && curr->next->dat < newnode->dat)
		curr = curr->next;

	newnode->next = curr->next;
	curr->next = newnode;
}
void insertionSort(struct Node** head)
{
	struct Node* result = NULL;
	struct Node* curr = *head;
	struct Node* next;

	while (curr != NULL)
	{
		next = curr->next;
		sortedInsert(&result, curr);
		curr = next;
	}
	*head = result;
}
void printList(struct Node* head)
{
	if (head == NULL) { printf("\n\nList is empty !!!\n\n"); return; }
	struct Node* temp = head;
	printf("\n");
	while (temp != NULL)
	{
		printf(" %d ", temp->dat);
		temp = temp->next;
	}
	printf("\n");
}
struct Node* SortedMerge(struct Node* a, struct Node* b)
{
	struct Node* result = NULL;

	if (a == NULL)
		return b;

	else if (b == NULL)
		return a;
	
	if (a->dat <= b->dat)
	{
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return result;
}
void FrontBackSplit(struct Node* source, struct Node** frontRef, struct Node** backRef)
{
	struct Node* fast;
	struct Node* slow;
	slow = source;
	fast = source->next;
	
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}
void MergeSort(struct Node** headRef)
{
	struct Node* head = *headRef;
	struct Node* a;
	struct Node* b;

	if ((head == NULL) || (head->next == NULL))
		return;

	FrontBackSplit(head, &a, &b);
	
	MergeSort(&a);
	MergeSort(&b);

	*headRef = SortedMerge(a, b);
}
void segregateUsingTwoTraversals(struct Node** head)
{
	struct Node* temp = *head;
	struct Node* tempEve = NULL;

	while (temp != NULL)
	{
		if (temp->dat % 2 == 0)
			createAndAppend(&tempEve, temp->dat);
		temp = temp->next;
	}
	temp = *head;
	while (temp != NULL)
	{
		if (temp->dat % 2 != 0)
			createAndAppend(&tempEve, temp->dat);
		temp = temp->next;
	}
	printList(tempEve);
}
struct Node* segregateUsingOneTraversal(struct Node* head)
{
	struct Node* curr;
	struct Node* evenStart = NULL;
	struct Node* evenEnd = NULL;
	struct Node* oddStart = NULL;
	struct Node* oddEnd = NULL;

	for (curr = head; curr != NULL; curr = curr->next)
	{
		int x = curr->dat;
		if (x % 2 == 0)
		{
			if (evenStart == NULL)
			{
				evenStart = curr;
				evenEnd = evenStart;
			}
			else
			{
				evenEnd->next = curr;
				evenEnd = evenEnd->next;
			}
		}
		else
		{
			if (oddStart == NULL)
			{
				oddStart = curr;
				oddEnd = oddStart;
			}
			else
			{
				oddEnd->next = curr;
				oddEnd = oddEnd->next;
			}
		}
	}

	if (oddStart == NULL || evenStart == NULL)
		return;
	evenEnd->next = oddStart;
	oddEnd->next = NULL;
	return evenStart;
}
void moveLastToFirst(struct Node** head)
{
	struct Node* temp = *head;
	struct Node* secLast = NULL;
	while (temp->next != NULL)
	{
		secLast = temp;
		temp = temp->next;
	}
	secLast->next = NULL;
	temp->next = *head;
	*head = temp;
}
void rotateCounterClockWise(struct Node** head, int k)
{
	if (k == 0) return;

	struct Node* current = *head;
	int Cnt = 1;

	while (Cnt < k && current != NULL)
	{
		current = current->next;
		Cnt++;
	}

	if (current == NULL) return;

	struct Node* kthNode = current;

	while (current->next != NULL)
		current = current->next;

	current->next = *head;
	*head = kthNode->next;
	kthNode->next = NULL;
}
struct Node* rotateClockWise(struct Node* head, int k)
{
	if (!head) return;

	struct Node* temp = head;
	int len = 1;

	while (temp->next != NULL)
	{
		temp = temp->next;
		len++;
	}

	if (k > len)
		k = k % len;

	k = len - k;

	if (k == 0) return head;

	struct Node* current = head;
	int Cnt = 1;
	while (Cnt < k && current != NULL)
	{
		current = current->next;
		Cnt++;
	}

	if (current == NULL) return head;

	struct Node* kthNode = current;
	temp->next = head;
	head = kthNode->next;
	kthNode->next = NULL;
	return head;
}
int lengthIterative(struct Node* head)
{
	if (head == NULL) return 0;
	struct Node* temp = head;
	int Cnt = 0;
	while (temp != NULL)
	{
		Cnt++;
		temp = temp->next;
	}
	return Cnt;
}
int lengthRecursive(struct Node* head)
{
	if (head == NULL) return 0;
	else
		return 1 + lengthRecursive(head->next);
}
int searchIterative(struct Node* head, int key)
{
	if (head == NULL) return 0;
	struct Node* temp = head;	
	while (temp != NULL)
	{
		if (temp->dat == key)
			return 1;
		temp = temp->next;
	}
	return 0;
}
int searchRecursive(struct Node* head, int key)
{
	if (head == NULL) return 0;
	if (head->dat == key) return 1;
	else
		return searchRecursive(head->next, key);
}
int compareLists(struct Node* list1, struct Node* list2)
{
	while (list1 && list2)
	{
		if (list1->dat != list2->dat)
			return 0;
		list1 = list1->next;
		list2 = list2->next;
	}
	return 1;
}
int isPalindrome(struct Node* head)
{
	struct Node* slow = head;
	struct Node* fast = head;
	struct Node* second_half;
	struct Node* prev = NULL;
	struct Node* mid = NULL;
	int res = 1;

	if (head != NULL && head->next != NULL)
	{
		while (slow && fast->next && fast->next->next)
		{
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;						
		}
		/* fast becomes NULL when even elements in the list
		* NOT NULL for odd elements
		* To skip the middle node for odd case and store
		*/
		if (fast != NULL)
		{
			mid = slow;
			slow = slow->next;
		}
		second_half = slow;
		prev->next = NULL;
		reverse(&second_half);
		res = compareLists(head, second_half);
		reverse(&second_half);
		if (mid != NULL)
		{
			prev->next = mid;
			mid->next = second_half;
		}
		else
			prev->next = second_half;
	}
	return res;
}
int main()
{
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;
	create(&head, 1);	
	int i, arr[] = { 1, 3, 5, 7, 9 };
	int   arr1[] = { 4, 6, 10, 12 };

	int p[] = { 50, 2, 8, 3, 10, 9, 12, 15, 13, 7, 10};
	//int p[] = { 2, 0, 2, 2, 2, 1 };

	for (i = 0; i < sizeof(p) / sizeof(p[0]); i++)
		addAtEnd(&head, p[i]);
	MergeSort(&head);
	printList(head);
	getchar();
	return 0;
}
