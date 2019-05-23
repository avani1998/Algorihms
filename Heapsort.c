#include<stdio.h>
#include<time.h>
int h[50000];
void heapify(int h[],int n)
{
    int i,j,v,k,heap;
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=h[k];
        heap=0;
        while(!heap && (2*k)<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(h[j]<h[j+1])
                j=j+1;
            }
            if(v>=h[j])
            heap=1;
            else
            {
                h[k]=h[j];
                k=j;
            }
        }
        h[k]=v;
    }
}

void main()
{
    int n,i,t,size;
    clock_t end,start;
    double tottime;
    printf("Enter the heap size\n");
    scanf("%d",&n);
    printf("Enter the heap\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
    }
    start=clock();
    heapify(h,n);
    for(i=n;i>=1;i--)
    {
        t=h[1];
        h[1]=h[i];
        h[i]=t;
        size=i-1;
        heapify(h,size);
    }
    end=clock();
    printf("Elements sorted\n");
    for(i=1;i<=n;i++)
    printf("%d\t",h[i]);
    tottime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Time taken is %f\n",tottime);
}
