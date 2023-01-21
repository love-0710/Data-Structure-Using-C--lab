
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev,*next;
    int data;
};

struct node *head=NULL;

void beginsert();
void lastinsert ();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();
void count();


int main (){
    int ch=0;
    while(ch!=9){
        printf("\n\nMain Menu\n");
        printf("\nChose one option from the following list...\n");
        printf("\n1.Insert at the beginning  \n2.Insert at end  \n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from end\n6.Delete at Random Location\n7.Search\n8.Display\n9.Quit\n");
        printf("\nEnter your choice:\n");
        scanf("\n%d",&ch);
        switch(ch){
            case 1:
            		beginsert();
            		break;
            case 2:
            		lastinsert();
            		break;
            case 3:
            		randominsert();
            		break;
            case 4:
            		begin_delete();
            		break;
            case 5:
            		last_delete();
            		break;
            case 6:
            		random_delete();
            		break;
            case 7:
            		search();
            		break;
            case 8:
            		display();
            		break;
            case 9:
            		exit(0);
            		break;
            default:
        	    printf("Please enter a valid choice..");
        }
    }
}
void beginsert(){
    struct node *ptr;
    int item;
    ptr = (struct node *) malloc(sizeof(struct node *));
    if(ptr == NULL){
        printf("\nOVERFLOW");
    }
    else{
	if(head!=NULL){
		head->prev=ptr;
	}
        printf("\nEnter value\n");
        scanf("%d",&item);
        ptr->data = item;
        ptr->next = head;
	ptr->prev =NULL;
        head = ptr;
        printf("\nNode inserted");
    }
}
void lastinsert()
{
    struct node *ptr,*temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
        printf("\nOVERFLOW");
    else
    {
        printf("\nEnter value?\n");
        scanf("%d",&item);
        ptr->data = item;
        if(head == NULL)
        {
            ptr -> next = NULL;
            ptr->prev=NULL;
	    head = ptr;
            printf("\nNode inserted");
        }
        else
        {
            temp = head;
            while (temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp->next = ptr;
	    ptr->prev=temp;
            ptr->next = NULL;
            printf("\nNode inserted");
        }
    }
}
void count()
{
	int r=0;
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		r++;
		temp=temp->next;
	}
	printf("No of nodes in list: %d",r);

}
void randominsert()
{
    int i,loc,item;
    struct node *ptr, *temp;
    ptr = (struct node *) malloc (sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter element value");
        scanf("%d",&item);
        ptr->data = item;
        printf("\nEnter the element after which you want to insert ");
        scanf("\n%d",&loc);
        temp=head;
        while(temp->next!=NULL &&temp->data!=loc)
        {
            temp = temp->next;
        }
	if(temp->next!=NULL)
		temp->next->prev=ptr;
	ptr->prev=temp;
        ptr ->next = temp ->next;
        temp ->next = ptr;
        printf("\nNode inserted");
    } 
}
void begin_delete()
{
    struct node *ptr;
    if(head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
	ptr=head;
        head = ptr->next;
	if(head!=NULL)
		head->prev=NULL;
  	free(ptr);
        printf("\nNode deleted from the begining ...\n");
    }
}
void last_delete()
{
    struct node *ptr,*ptr1;
    if(head == NULL)
    {
        printf("\nlist is empty");
    }
    else if(head -> next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nOnly node of the list deleted ...\n");
    }
    else
    {
        ptr = head;
        while(ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr ->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\nDeleted Node from the last ...\n");
    }
}
void random_delete()
{
    if(head == NULL)
    {
        printf("\nlist is empty");
	return;
    }
    struct node *ptr,*ptr1;
    int loc,i;
    printf("\n Enter the value of the node on which you want to perform deletion \n");
    scanf("%d",&loc);
    ptr=head;
    for(i=0;i<loc && ptr->data!=loc;i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;
        if(ptr == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    ptr1 ->next = ptr ->next;
    if(ptr->next!=NULL)
	ptr->next->prev=ptr1;
    free(ptr);
    if(i==0)
    {

	head=head->next;
    }
    printf("\nDeleted node %d ",i+1);
}
void search()
{
    struct node *ptr;
    int item,i=0,flag=1;
    ptr = head;
    if(ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search?\n");
        scanf("%d",&item);
        while (ptr!=NULL)
        {
            if(ptr->data == item)
            {
                printf("item found at location %d ",i+1);
                flag=0;
		break;
            }
            i++;
            ptr = ptr -> next;
        }
        if(flag==1)
        {
            printf("Item not found\n");
        }
    }
}
void display()
{
    struct node *ptr,*ptr1;
    ptr = head;
    if(ptr == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("\nPrinting values from front to back\n");
        while (ptr!=NULL)
        {
            printf("\n%d",ptr->data);
	    ptr1=ptr;
            ptr = ptr -> next;
        }
	printf("\nPrinting values from back to front\n");
        while (ptr1!=NULL)
        {
            printf("\n%d",ptr1->data);
            ptr1 = ptr1 -> prev;
        }

    }
}
