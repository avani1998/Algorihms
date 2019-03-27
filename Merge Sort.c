#include<stdio.h>
void main()
{
	int a[30],n,i;
	printf("Enter no of elements:");
	scanf("%d",&n);
	printf("Enter array elements:");
	
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	mergesort(a,0,n-1);
	
	printf("\nSorted array is :");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
 
void mergesort(int a[],int low,int high)
{
	int mid;
		
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(a,low,mid);		//left recursion
		mergesort(a,mid+1,high);	//right recursion
		merge(a,low,mid+1,high);	//merging of two sorted sub-arrays
	}
}
 
void merge(int a[],int low,int mid,int high)
{
	int temp[50];	//array used for merging
	int i=low,j=mid,k; //beginning of the first list> ;	//beginning of the second list
	k=0;
	
	while(i<=mid && j<=high)	//while elements in both lists
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	
	while(i<=mid)	//copy remaining elements of the first list
		temp[k++]=a[i++];
		
	while(j<=high)	//copy remaining elements of the second list
		temp[k++]=a[j++];
		
	//Transfer elements from temp[] back to a[]
	for(i=low,j=0;i<=high;i++,j++)
		a[i]=temp[j];
}
