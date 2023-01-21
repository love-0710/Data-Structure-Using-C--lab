#include<stdio.h>
int main()
{
    int arr[100],search,n,pos;
    printf("Enter number of elements in array= ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter element} to be searched: ");
    scanf("%d",&search);
    int linearsearch(int a[], int n, int search)
    {
        int i;
        for(i=0; i<n; i++)
        {
            if(a[i]==search)
            return i;
        }
        return -1;
    }
    pos =linearsearch(arr,n,search);
    if (pos == -1)
    printf("%d is not found",search);
    else
    printf("%d is present at position %d", search, pos+1);
    return 0;
}
