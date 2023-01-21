//Menu driven program to implement stack using array

#include <stdio.h>
#define size 50

static int stack[size], top = -1;


void push() {
	int data;
	if(top == size -1)
		printf("\n\nOverflow!");
	else{
		printf("\n\nEnter element to be inserted to stack :");
		scanf("%d", &data);
		top+=1;
		stack[top] = data;
	}
}



void pop() {
	if(top == -1)
		printf("\n\nUnderflow!");
	else {
		printf("\n\nPopped element: %d", stack[top]);
		top=top-1;
	}
}



void peek(){
	if(top == -1)
		printf("\n\nStack is empty!");
	else
		printf("\n\nPeekaboo! Top most element is %d", stack[top]);
}



void display(){
	if (top == -1)
		printf("\n\nStack is empty");
	else{
		printf("\n\nElements present in stack -\n\n[\t");
		for (int i = 0; i <= top; i++){
			printf("%d\t", stack[i]);
		}
		printf("]");
	}
}




main(){
	int choice = 1;

	while (choice) {
		printf( "\n\nChoose - \n\t1. Push\n\t2. Pop\n\t3. Peep\n\t4. Display\n\t5. Exit\n\n");
		scanf("%d", &choice);


	/*     MENU       */
	switch(choice) {
		case 1:
			push();
			display();
			break;
		case 2:
			pop();
			display();
			break;
		case 3:
			peek();
			break;
		case 4:
			display();
			break;
		case 5:
			choice = 0;
			break;
		default:
			printf("\n\nEnter correct choice!\n\n");
			break;
	}

	}

	return 0;
}
