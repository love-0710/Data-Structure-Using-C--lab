#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
} *f = NULL, *r = NULL;

typedef struct Node node;

void enqueue (int d) {
	node *n = (node *) malloc ( sizeof(node) );
	n -> data = d;
	n -> next = NULL;
	if (!r && !f) {
		f = r = n;
		r -> next = f;
	}
	else {
		r -> next = f;
		r = n;
		n -> next = f;
	}
}

void dequeue () {
	node *t = f;
	if (!f && !r) {
		printf ("\n\nQueue empty!");
		return;
	}
	if (f == r) {
		f = r = NULL;
		free (t);
		return;
	}
	r -> next = f = f-> next;
	free (t);
}

void print () {
	node *t = f;
	if (!f && !r) {
		printf ("\n\nQueue empty!");
		return;
	}
	printf ("\n\n[\t");
	do {
		printf ("%d\t", t -> data);
		t = t -> next;
	} while (t != f);
	printf ("]");
}


int main () {
	int ch = -1, val;
	while (ch) {
		printf ("\n\nChoose -\n\t1. Enqueue\n\t2. Dequeue\n\t3. Display\n\t4. Exit\n\nEnter[1-4]: ");
		scanf ("%d", &ch);
		switch (ch) {
			case 1:
				printf ("\n\nEnter data: ");
				scanf ("%d", &val);
				enqueue (val);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				print();
				break;
			case 4:
				ch = 0;
				break;
		}
	}
	return 0;
}
