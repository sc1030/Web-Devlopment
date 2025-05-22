#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store account information
struct Account
{
    int accountNumber;
    char HolderName[50]; // Corrected the variable name
    float balance;
};

// Function declarations
void displayMenu();
void createAccount();
void viewAccount();
void deposit();
void withdraw();
void updateFile(struct Account acc); // Added parameter name to match the definition

int main()
{
    int choice;

    do
    {
        displayMenu();
        printf("\n\n->Enter your Choice... ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n\n-->CREATE ACCOUNT..");
            createAccount(); // Call the createAccount function
            break;
        case 2:
            printf("\n\n-->VIEW ACCOUNT..");
            viewAccount(); // Call the viewAccount function
            break;
        case 3:
            printf("\n\n-->DEPOSIT..");
            deposit(); // Call the deposit function
            break;
        case 4:
            printf("\n\n-->WITHDRAW..");
            withdraw(); // Call the withdraw function
            break;
        case 5:
            printf("\n\n-->EXITING PROGRAM..");
            break;
        default:
            printf("\n\n-->INVALID CHOICE . PLEASE TRY AGAIN.\n");
        }

    } while (choice != 5);

    return 0;
}

void displayMenu()
{
    printf("\n\n\t\t======BANK ACCOUNT SYSTEM======\n\n ");
    printf("\t\t1. ---> CREATE ACCOUNT.\n");
    printf("\t\t2. ---> VIEW ACCOUNT.\n");
    printf("\t\t3. ---> DEPOSIT.\n");
    printf("\t\t4. ---> WITHDRAW.\n");
    printf("\t\t5. ---> EXIT.\n");
}

void createAccount()
{
    struct Account acc;
    printf("->Enter Account Number \n");
    scanf("%d", &acc.accountNumber);

    printf("->Enter Holder Name \n");
    scanf("%s", acc.HolderName); // Removed the '&' operator before acc.HolderName

    printf("->Enter Initial Balance \n");
    scanf("%f", &acc.balance);

    // SAVE ACCOUNT INFORMATION TO FILE
    updateFile(acc);

    printf("\n\n\t====Account Created Successfully====\n\n");
}

void viewAccount()
{
    struct Account acc;
    int accountNumber;
    printf("-->Enter Account Number \n\n");
    scanf("%d", &accountNumber);

    FILE *file = fopen("account.txt", "r");
    int found = 0;

    while (fread(&acc, sizeof(struct Account), 1, file) == 1)
    {
        if (acc.accountNumber == accountNumber)
        {
            found = 1;
            printf("\n==== Account Information ====\n");
            printf("Account Number: %d\n", acc.accountNumber);
            printf("Holder Name :%s \n", acc.HolderName);
            printf("Balance : %.2f\n", acc.balance);
            break; // Added a break to exit the loop after finding the account
        }
    }

    fclose(file);

    if (!found)
    {
        printf("Account not found. \n");
    }
}

void deposit()
{
    struct Account acc;
    int accountNumber;
    float amount;
    printf("Enter Account Number.. \n");
    scanf("%d", &accountNumber);

    FILE *file = fopen("account.txt", "r+");
    int found = 0;

    while (fread(&acc, sizeof(struct Account), 1, file) == 1)
    {
        if (acc.accountNumber == accountNumber)
        {
            found = 1;
            printf("Enter Deposit Amount.. \n");
            scanf("%f", &amount);

            acc.balance += amount;
            fseek(file, -sizeof(struct Account), SEEK_CUR);
            fwrite(&acc, sizeof(struct Account), 1, file);
            printf("Deposit Successful. Updated Balance: %.2f\n", acc.balance);
            break;
        }
    }

    fclose(file);

    if (!found)
    {
        printf("Account Not Found. \n");
    }
}

void withdraw()
{
    struct Account acc;
    int accountNumber;
    float amount;
    printf("-->Enter Account Number. \n");
    scanf("%d", &accountNumber);

    FILE *file = fopen("account.txt", "r+");
    int found = 0;

    while (fread(&acc, sizeof(struct Account), 1, file) == 1)
    {
        if (acc.accountNumber == accountNumber)
        {
            found = 1;
            printf("-->Enter Withdraw Amount. \n");
            scanf("%f", &amount);
            if (amount > acc.balance)
            {
                printf("--Insufficient Funds--.\n");
            }
            else
            {
                acc.balance -= amount;
                fseek(file, -sizeof(struct Account), SEEK_CUR);
                fwrite(&acc, sizeof(struct Account), 1, file);
                printf("---Withdrawal Successful--. Updated Balance: %.2f\n", acc.balance);
            }
            break;
        }
    }
    fclose(file);

    if (!found)
    {
        printf("Account not found. \n");
    }
}

void updateFile(struct Account acc)
{
    FILE *file = fopen("account.txt", "a");
    if (file == NULL)
    {
        printf("--Error Opening File. \n");
        exit(1);
    }
    fwrite(&acc, sizeof(struct Account), 1, file);

    fclose(file);
}







