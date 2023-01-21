/* QUEUE USING LINKED LIST */

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
} *head = NULL;

typedef struct Node node;

int front = -1, rear = -1;

//ENQUEUE
void enqueue (int val) {
	node *newNode = (node *) malloc ( sizeof(node) );
	newNode -> data = val;
	newNode -> next = NULL;

	if (!head) {
		head = newNode;
		front = rear = 0;
		return;
	}

	node *temp = head;
	while (temp -> next)
		temp = temp -> next;

	temp -> next = newNode;
	rear += 1;
}


//DEQUEUE
void dequeue () {
	if (!head) {
		printf ("\n\nList is empty!");
		front = rear = -1;
		return;
	}
	node *temp = head;
	if (!(temp -> next)) {
		head = NULL;
		free (temp);
		front = rear = -1;
		return;
	}
	head = temp -> next;
	free (temp);
	rear -= 1;
}


//DISPLAY
void display () {
	if (!head) {
		printf ("\n\nList is empty!");
		return;
	}
	node *temp = head;
	printf ("\n\n[\t");
	while (temp) {
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	printf ("]");
}

void po() {
	printf ("\n\nFront: %d\nRear: %d", front, rear);
}


int main () {
	int val, ch = -1;

	while (ch) {
		printf ("\n\nChoose -\n\t1. Enqueue\n\t2. Dequeue\n\t3. Display\n\t4. Exit\n\nEnter[1-4]: ");
		scanf ("%d", &ch);

		switch (ch) {
			case 1:
				printf ("\n\nEnter value: ");
				scanf ("%d", &val);
				enqueue(val);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				po();
				break;
			case 4:
				ch = 0;
				break;
			default:
				printf ("\n\nEnter valid choice!");
		}
	}
	return 0;
}
