#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node* next;
};
static struct node* reverse(struct node*  head_ref)
{
    struct node* prev = NULL;
    struct node* current = head_ref;
	struct node* next=NULL;
    while(current != NULL)
  {
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
  }
   head_ref=prev;
	return head_ref;
}

struct node* push(struct node* head_ref, int new_data)
  {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = head_ref;
    head_ref=new_node;
    return head_ref;  
}
void printlist(struct node* head)
{
    struct node* temp=head;
    while(temp != NULL)
    {
     printf("%d ", temp->data);
     temp = temp-> next;
    }
}
int main()
{
	struct node* head = NULL;
	int ch=0;
	while(ch!=2)
	{
		printf("Enter 1 to add element to beginning, 2 to stop\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			int a;
			printf("Enter element : ");
			scanf("%d",&a);
			head=push(head,a);
		}
	}
	printf("given linked list:\n");
	printlist(head);
	head=reverse(head);
	printf("\n reversed linked list: \n\t");
	printlist(head);
	printf("\t");
	return 0;
}
