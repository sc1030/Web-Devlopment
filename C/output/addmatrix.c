#include<stdio.h>

void main()
{
    int r,c,a[10][10],b[10][10],sum[10][10],i,j;
    printf("enter the number of rows (between 1 and 10):");
    scanf("%d", &r);

    printf("enter the number of columns (between 1 and 10):");
    scanf("%d", &c);

    printf("\nenter elements of 1st matrix: \n");
    for(i=0; i<r; i++)
    for(j=0; j<c; j++) 
    {
        printf("Enter element a%d%d: ",i+1,j+1);
        scanf("%d",&a[i][j]);
    }

    printf("\nenter elements of 2nd matrix: \n ");
    for(i=0; i<r; i++)
    for(j=0; j<c; j++)
    {
        printf("enter elements b%d%d", i+1,j+1);
        scanf("%d",&b[i][j]);
    }

    //adding two matrix
    for(i=0; i<r; i++)
    for(j=0; j<c; j++)
    {
        sum[i][j] = a[i][j] + b[i][j];
    }
    printf("\nSum of two matrices:\n");
    for(i=0; i<r; i++)
    for(j=0; j<c; j++)
    {
        printf("%d", sum[i][j]);
        if(j==c-1)
        {
            printf("\n\n");
        }
    }
    return ;
}