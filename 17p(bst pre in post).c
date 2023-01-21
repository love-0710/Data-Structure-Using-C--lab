#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *create(){
	struct node *p;
	int item;
	printf("Enter data (-1 for no data)\n");
	scanf("%d",&item);
	if(item == -1){
		return NULL;
	}
	p=(struct node*)malloc(sizeof(struct node));
	p->data = item;
	printf("Enter left child of %d:\n",item);
	p->left=create();
	printf("Enter right child of %d:\n",item);
	p->right=create();
	return p;
}

void preorder(struct node *p){
	if(p!=NULL){
		printf("\t%d",p->data);
		preorder(p->left);
		preorder(p->right);
	}
}

void inorder(struct node *p){
	if(p!=NULL){
		inorder(p->left);
		printf("\t%d",p->data);
		inorder(p->right);
	}
}

void postorder(struct node *p){
	if(p!=NULL){
		postorder(p->left);
		postorder(p->right);
		printf("\t%d",p->data);
	}
}

int main(){
	struct node *root;
	root = create();
	printf("\nThe preorder traversal of tree is :\n");
	preorder(root);
	printf("\nThe postorder traversal of tree is :\n");
	postorder(root);
	printf("\nThe inorder traversal of tree is :\n");
	inorder(root);

return 0;
}
