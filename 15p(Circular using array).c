
#include <stdio.h>

#define max 5

int queue[max], front = -1, rear = -1;

void enqueue (int data) {
        if ( (rear + 1) % max == front) {
                printf ("\n\nOverflow!");
                return;
        }

        if (front == -1 && rear == -1)
                front = rear = 0;

        else rear = (rear + 1) % max;
        queue[rear] = data;
}

void dequeue () {
        if (front == -1 && rear == -1) {
                printf ("\n\nUnderflow!");
                return;
        }

        printf ("\n\nDequeued element is %d", queue[front]);

        if (front == rear)
                front = rear = -1;


        else front = (front + 1) % max;
}

void display () {
        if (front == -1 && rear == -1) {
                printf ("\n\nQueue is empty!");
                return;
        }

        printf ("\n\nQueue -\n[\t");
	if(front<rear)
        for (int i = front; i <= rear; i++)
                printf ("%d\t", queue[i]);

	else
	{
	for(int i= front; i!=rear; i=(i+1)%max)
		printf("%d\t", queue[i]);
		printf("%d",queue[rear]);
	}
	printf("]");
}


int main () {

        int data, choice = 1;

        printf ("\n\nCIRCULAR QUEUE");
        while (choice) {
                printf ("\n\nChoose - ");
                printf ("\n\t1. Enqueue");
                printf ("\n\t2. Dequeue");
                printf ("\n\t3. Display");
                printf ("\n\t4. Exit");
                printf ("\n\nEnter choice [1-4]: ");
                scanf ("%d", &choice);

                switch (choice) {
                        case 1:
                                printf ("\n\nEnter element: ");
                                scanf ("%d", &data);
                                printf ("\n\nInitially \nFront: %d \nRear: %d", front, rear);
                                enqueue (data);
                                printf ("\n\nAfter enqueue \nFront: %d \nRear: %d", front, rear);
                                break;
                        case 2:
                                printf ("\n\nFront: %d \nRear: %d", front, rear);
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
                                break;
                }

        }

        return 0;
}


