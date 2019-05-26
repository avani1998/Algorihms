#include<stdio.h>
void Floyds(int A[5][5])
{
    int i,j;
    for(int k=0;k<5;k++)
    {
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
            }
        }
    }
    printf("the final matrix is\n");
    for(i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
}
int min(int a,int b)
{
    if(a<b)
    return a;
    else return b;
}
void main()
{
    int i,n;
    int A[5][5];
    printf("Enter the matrix\n");
    for(i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    Floyds(A);
}
/*Enter the number of elements                                                                                                                     
5                                                                                                                                                
Enter matrix                                                                                                                                     
0 2 999 1 8                                                                                                                                      
6 0 3 2 999                                                                                                                                      
999 999 0 4 999                                                                                                                                  
999 999 2 0 3                                                                                                                                    
3 999 999 999 0                                                                                                                                  
The final matrix is                                                                                                                              
0       2       3       1       4                                                                                                                
6       0       3       2       5                                                                                                                
10      12      0       4       7                                                                                                                
6       8       2       0       3                                                                                                                
3       5       6       4       0    */
