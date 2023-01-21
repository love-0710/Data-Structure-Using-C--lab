#include<stdio.h>
#include<ctype.h>
char stack[100];
int top=-1;
void push(char ch)
{
	top=top+1;
	stack[top]= ch;
}
char pop()
{
	if(top<=-1)
	{
		return -1;
	}
	else
	{
		return(stack[top--]);
	}
}
int priority(char ch)
	{
		if(ch=='(')
		{
			return 0;
		}
		if(ch=='+' || ch=='-')
		{
			return 1;
		}
		if(ch=='*' || ch=='/')
		{
			return 2;
		}
	}
int main()
{
	char infix[100], postfix[100];
	char *ch, x;
	int k=0;
	printf("Enter the infix string\n");
	scanf("%s", &infix);
	ch=&infix[0];
	while(*ch!='\0')
	{
		if(*ch=='(')
			{
				push(*ch);
			}
		else if(isalnum(*ch))
			{
				postfix[k]=*ch;
				k++;
			}
		else if(*ch==')')
			{
				while((x=pop())!='(')
				{
					postfix[k]=x;
					k++;
				}
			}
		else
		{
			while(top!=-1 && priority(stack[top])>= priority(*ch))
			{
				postfix[k]= pop();
				k++;
			}
			push(*ch);
		}
		ch++;
	}


while(top!=-1)
{
	postfix[k]=pop();
	k++;
}
printf("\n The postfix expression is:  %s \n\n", postfix);
return 0;
}
