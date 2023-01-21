/* STACK USING LINKED LIST*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
} *head = NULL;

typedef struct Node node;



//PUSH
void push (int val) {
	node *newNode = (node*) malloc ( sizeof(node) );
	newNode -> data = val;
	newNode -> next = NULL;

	if (!head) {
		head = newNode;
		return;
	}

	node *temp = head;
	while (temp -> next)
		temp = temp -> next;

	temp -> next = newNode;
}


void pop () {
	if (!head) {
		printf ("\n\nList is empty!");
		return;
	}
	node *temp1 = head, *temp2;

	if (!(head -> next)) {
		head = NULL;
		free (temp1);
		return;
	}

	//node *temp1 = head, *temp2;

	while (temp1 -> next) {
		temp2 = temp1;
		temp1 = temp1 -> next;
	}
	temp2 -> next = NULL;
	free (temp1);
}

void peek () {
	if (!head) {
		printf ("\n\nList is empty!");
		return;
	}
	node *temp = head;
	while (temp -> next)
		temp = temp -> next;
	printf ("\n\nPeekaboo! Latest element is %d", temp -> data);
}


//DISPLAY
void display() {
	if (!head) {
		printf ("\n\nList is empty!");
		return;
	}

	node *temp = head;

	printf ("\n\n[\t");
	while (temp) {
		printf ("%d\t", temp -> data);
		temp = temp -> next;
	}
	printf ("]");
}

// MENU and main function
int main () {
	int val, ch = -1;

	while (ch) {
		printf ("\n\nChoose -\n\t1. Push\n\t2. Pop\n\t3. Peek\n\t4. Display\n\t5. Exit\n\nEnter[1-5]: ");
		scanf ("%d", &ch);
		switch (ch) {
			case 1:
				printf ("\n\nEnter value: ");
				scanf ("%d", &val);
				push(val);
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				ch = 0;
				break;
			default:
				printf ("\n\nEnter valid choice: ");
		}
	}

	return 0;
}
