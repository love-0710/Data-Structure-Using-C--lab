#include<stdio.h>

int main()
{
    int n,a[100],key,pos;
        int binarysearch(int a[], int n, int item)
    {
        int flag, low=0, mid, high=n-1;
        while(high>=low)
        {
            if(a[mid]==item)
            {
                flag++;
                break;
            }
            else if(item>a[mid])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }

        }
        if(flag==1)
        {
            return mid;
        }
        else
        {
            return 0;
        }
    }
    printf("Enter the size of an array: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d",&key);


    pos = binarysearch(a,n,key);
    if(pos != 0)
    {
        printf("Element %d found at position %d",key,pos+1);
    }
    else
    printf("Element %d is not found");
    return 0;
}