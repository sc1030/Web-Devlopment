#include<stdio.h>

void main()
{
    int arr1[50],n,i,j=0,lrg,lrg2nd;

    printf("\n\nFind the second largest element in an array:\n");
    printf("Enter number of elements: ");
    printf("Input the size of the array :");
    scanf("%d",&n);

    printf("Input %d elements in the array:\n",n);
    for(i=0; i < n ; i++)
    {
        printf("element - %d:",i);
        scanf("%d",&arr1[i]);
    }
    lrg = 0;
    for(i=0; i<n; i++)
    {
        if(lrg<arr1[i])
        {
            lrg=arr1[i];
            j=i;
        }
    }

    lrg2nd =0;
    for(i=0;i<n;i++)
    {
        if(i==j)
        {
            i++;
            i--;
        }
        else{
            if(lrg2nd<arr1[i])
            {
                lrg2nd=arr1[i];
            }
        }
    }
    printf("\nThe Second Largest Element is:%d",lrg2nd);
    return 0;
}