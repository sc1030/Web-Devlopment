#include<stdio.h>
 
 void num_print();
 void alpha_print();
 void rev_num_print();
 void main()
 {
    int choice;

    printf("\n enter choice for which you want to print pattern:");
    printf("\n1. number triangle \n2.alphabet triangle  \n3.reverse number triangle\n");
    scanf("%d",&choice);
    printf("\n enter choice is: %d\n", choice);
    switch(choice)
    {
        case 1:
        num_print();
        break;
        case 2:
        alpha_print();
        break;
        case 3:
        rev_num_print();
        break;
        default:
        printf("\n kindly enter correct choice.");
    }
    return 0;
 }
 void num_print()
 {
    int i,j,rows;
    printf("Enter the number of rows in your pattern:\t");
    scanf("%d",&rows);
    for(i=0; i<=5; ++i){
        for(j=1; j<=i; ++j){
            printf("%d ",j);
        }
        printf("\n");
    }
 }
  void alpha_print()
  {
    int i,j;
    char input,alphabet = 'A';
    printf("Enter an uppercase character you want to print in the last row: ");
    scanf("%c", &input);
    for(i=1;i<=7;++i)
    {
        for(j=1; j<=i; ++j)
        {
            printf("%c ", alphabet);
        }
        ++alphabet;
        printf("\n");
    }
    return 0;
  }
      
      void rev_num_print()
      {
        int i,j,rows;
        printf("enter the number the rows");
        scanf("%d",&rows);
        for(i=rows; i>=1; --i){
            for(j=1; j<=i; ++j){
                printf("%d",j);
            }
            printf("\n");
        }
      }