#include<stdio.h>
void merge(int a[],int low,int mid,int high)
{
    int l1,l2,i,b[100];
    for(l1=low,l2=mid,i=low;l1<=mid && l2<=high;i++)
    {
        if(a[l1]<a[l2])
        b[i]=a[l1++];
        else
        b[i]=a[l2++];
    }
    while(l1<=mid)
    b[i++]=a[l1++];
    while(l2<=high)
    b[i++]=a[l2++];
    for(i=low;i<=high;i++)
    a[i]=b[i];
}
void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid+1,high);
    }
}
void main()
{
    int a[100],i,j,n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(a,0,n-1);
    printf("The sorted array is \n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
}
/*Enter the number of elements                                                                                                                     
5                                                                                                                                                
Enter the array                                                                                                                                  
6                                                                                                                                                
3                                                                                                                                                
9                                                                                                                                                
7                                                                                                                                                
1                                                                                                                                                
The sorted array is                                                                                                                              
1       3       6       7       9   */
