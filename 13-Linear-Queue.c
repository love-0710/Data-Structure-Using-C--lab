// Menu Driven Program to implement Linear Queue

#include <stdio.h>

#define size 3

int queue[size], front = -1, rear = -1;

void display() {
	if (rear == -1) {
		printf ("\n\nQueue Empty!");
		return;
	}

	printf ("\n\nQueue -\n[\t");
	for (int i = front; i <= rear; i++)
		printf ("%d\t", queue[i]);
	printf ("]");

}


void enqueue (int data) {
	if (rear == size - 1) {
		printf ("\n\nOverflow!");
		return;
	}

	if (front == -1, rear == -1)
		front = rear = 0;
	else ++rear;

	queue[rear] = data;
}


void dequeue () {
	if (front == -1 || front > rear) {
		printf ("\n\nQueue Empty!");
		return;
	}

	printf ("\n\nDequeued element is %d", queue[front]);

	if (front == rear)
		front = rear = -1;
	else ++front;
}



int main () {

	int data, choice = 1;

	printf ("\n\nLINEAR QUEUE");
	while (choice) {
		printf ("\n\nChoose - ");
		printf ("\n\t1. Enqueue");
		printf ("\n\t2. Dequeue");
		printf ("\n\t3. Display");
		printf ("\n\t4. Exit");
		printf ("\n\nEnter [1-4]: ");
		scanf ("%d", &choice);


	switch (choice) {
		case 1:
			printf ("\n\nEnter element: ");
			scanf ("%d", &data);
			printf ("Initially \nFront: %d \nRear: %d", front, rear);
			enqueue (data);
			display();
			printf ("\n\nAfter enqueue \nFront: %d \nRear: %d", front, rear);
			break;

		case 2:
			printf ("\n\nFront: %d \nRear: %d:", front, rear);
			dequeue();
			printf ("\n\nFront: %d \nRear: %d", front, rear);
			break;

		case 3:
			display();
			break;

		case 4:
			choice = 0;
			break;

		default:
			printf ("\n\nEnter valid choice!");

	}


	}

	return 0;

}
