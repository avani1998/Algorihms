#include<stdio.h>
#include<time.h>
void main()
{
    int i,j,A[1000000];
    clock_t end,start;
    int n;double time;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        A[i]=rand();
    }
    start=clock();
    for(i-0;i<n;i++)
    {
        int min=A[i];
        for(j=i+1;j<n;j++)
        {
            if(min<A[j])
            {
                A[i]=A[j];
                A[j]=min;
            }
        }
    }
    end=clock();
    time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Time taken for %d inputs is %f\n",n,time);
}
