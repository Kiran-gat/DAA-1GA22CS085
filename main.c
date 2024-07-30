#include <stdio.h>
#include <stdlib.h>
#define size 100
int count;

int partition(int A[size],int l,int r){

 int i,j,pivot,temp;
 pivot=A[l];
 i=l+1;
 j=r;
 while(1){

    while(pivot>=A[i]&& i<=r)
    {  count++;
       i++;
    }

    while(pivot<A[j])
    {    count++;
        j--;

    }
   count++;
    if(i<j)
    {

        temp=A[i];
        A[i]=A[j];
        A[j]=temp;

    }
    else{

        temp=A[j];
        A[j]=A[l];
        A[l]=temp;
        return j;
    }
 }

}
void quicksort(int A[size],int l,int r){

   int s;
   if(l<r)
   {
       s=partition(A,l,r);
       quicksort(A,l,s-1);
       quicksort(A,s+1,r);

   }

}

int main()
{
    int i,n,A[size];
    printf("enter the size:\n");
    scanf("%d",&n);
    printf("enter the elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    quicksort(A,0,n-1);

    printf("sorted array\n");
    for(i=0;i<n;i++)
        printf("%d",A[i]);
    printf("th comparison %d",count);

}
