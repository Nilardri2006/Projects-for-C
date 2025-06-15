#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining structure for the bank account

struct account
{
    int acc_number;
    char name[100];
    float balance;
};

// declaring the all fuctions

void create_account();
void view_all_account();
void deposit_money();
void withdraw_money();
void search_account_details();
void delete_account();
void modify_account();

int main()
{
    int choice;
    do
    {
        printf("_________________________________________________________________________________\n");
        printf("___BANK MANAGEMENT SYSTEM___\n");
        printf("1. Create Account\n");
        printf("2. View All Accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Search Account Details\n");
        printf("6. Delete Account\n");
        printf("7. Modify Account\n");
        printf("8. Exit\n");
        printf("Please enter your choice: ");

        scanf("%d", &choice);
        printf("_________________________________________________________________________________\n");

        switch (choice)
        {
        case 1:
            create_account();
            break;
        case 2:
            view_all_account();
            break;
        case 3:
            deposit_money();
            break;
        case 4:
            withdraw_money();
            break;
        case 5:
            search_account_details();
            break;
        case 6:
            delete_account();
            break;
        case 7:
            modify_account();
            break;

        case 8:
            exit(0);
        default:
            printf("invalid input!!");
        }
    } while (1);

    return 0;
}

void create_account()
{
    FILE *fp;
    fp = fopen("accounts.txt", "a");
    struct account acc;
    if (fp == NULL)
    {
        printf("Error occuring to open the file!!");
        return;
    }
    // input acc details
    printf("Please enter your account number: ");
    scanf("%d", &acc.acc_number);
    printf("Please enter your first  name: ");
    scanf("%s", &acc.name);
    printf("Please enter initial balance: ");
    scanf("%f", &acc.balance);

    // writing on account.txt file
    fprintf(fp, "%d %s %.2f \n", acc.acc_number, acc.name, acc.balance);
    fclose(fp);
    printf("!! Account Created Successfully !!\n");
}

void view_all_account()
{
    FILE *fp = fopen("accounts.txt", "r");
    struct account acc;
    if (fp == NULL)
    {
        printf("No accounts found\n");
        return;
    }

    // read & display all accounts
    printf("\n_____Account List_____\n");
    while (fscanf(fp, "%d %s %f \n", &acc.acc_number, acc.name, &acc.balance) == 3)
    {
        printf("Account No: %d\n", acc.acc_number);
        printf("Name of Account holder: %s\n", acc.name);
        printf("Balance: %.2f \n", acc.balance);
        printf("----------------------------------------------------------\n");
    }
    fclose(fp);
}

void deposit_money()
{
    FILE *fp = fopen("accounts.txt", "r"); // opening the original file
    FILE *temp = fopen("temp.txt", "w");   // opening a atemporary file to write

    struct account acc;
    int acc_no, found = 0;
    float amount;

    // input details
    printf("Please enter your Account Number: ");
    scanf("%d", &acc_no);
    printf("Please enter the amount to deposit: ");
    scanf("%f", &amount);

    // Reading from orgininal and writing in temp file adding existing amount
    while (fscanf(fp, "%d %s %f \n", &acc.acc_number, acc.name, &acc.balance) == 3)
    {
        if (acc.acc_number == acc_no)
        {
            acc.balance += amount;
            found = 1;
        }
        fprintf(temp, "%d %s %f \n", acc.acc_number, acc.name, acc.balance);
    }
    // replace old with new file
    fclose(fp);
    fclose(temp);
    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    // notify result
    if (found)
        printf("Deposit Successful!!\n");
    else
        printf("Account not found.\n");
}

void withdraw_money()
{
    FILE *fp = fopen("accounts.txt", "r"); // opening the original file
    FILE *temp = fopen("temp.txt", "w");   // opening a atemporary file to write

    struct account acc;
    int acc_no, found = 0;
    float amount;

    // input details
    printf("Please enter your Account Number: ");
    scanf("%d", &acc_no);
    printf("Enter amount to  withdraw: ");
    scanf("%f", &amount);

    // proccessing the record
    while (fscanf(fp, "%d %s %f \n", &acc.acc_number, acc.name, &acc.balance) == 3)
    {
        if (acc.acc_number == acc_no)
        {
            if (acc.balance >= amount)
            {
                acc.balance -= amount;
                found = 1;
            }
            else
            {
                printf("Insufficient balance \n");
                found = -1;
            }
        }

        fprintf(temp, "%d %s %.2f \n", acc.acc_number, acc.name, acc.balance);
    }

    // replace old with new file
    fclose(fp);
    fclose(temp);
    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    // notify result to the user
    if (found == 1)
    {
        printf("Withdrawl successfull.\n");
    }
    else if (found == 0)
    {
        printf("Account not found.\n");
    }
}

void search_account_details()
{
    FILE *fp = fopen("accounts.txt", "r"); // opening  file
    struct account acc;
    int acc_no, found = 0;
    printf("Please enter your Account Number to search: ");
    scanf("%d", &acc_no);

    // searching
    while (fscanf(fp, "%d %s %f \n", &acc.acc_number, acc.name, &acc.balance) == 3)
    {
        if (acc.acc_number == acc_no)
        {
            printf("Account Found!\n");
            printf("Account No: %d\n", acc.acc_number);
            printf("Name: %s\n", acc.name);
            printf("Balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Account does not exist");
    }
    fclose(fp);
}

void delete_account()
{
    FILE *fp = fopen("accounts.txt", "r"); // opening the original file
    FILE *temp = fopen("temp.txt", "w");   // opening a atemporary file to write

    struct account acc;
    int acc_no, found = 0;

    // input details
    printf("Please enter your Account Number: ");
    scanf("%d", &acc_no);

    // copy all except that one to delete
    while (fscanf(fp, "%d %s %f \n", &acc.acc_number, acc.name, &acc.balance) == 3)
    {
        if (acc.acc_number == acc_no)
        {
            found = 1;
            continue;
        }
        fprintf(temp, "%d %s %.2f \n", acc.acc_number, acc.name, acc.balance);
    }

    // replace the file
    fclose(fp);
    fclose(temp);
    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if (found)
    {
        printf("Accout deleted successfully.\n");
    }
    else
    {
        printf("Account not found.\n");
    }
}

void modify_account()
{
    FILE *fp = fopen("accounts.txt", "r"); // opening the original file
    FILE *temp = fopen("temp.txt", "w");   // opening a atemporary file to write

    struct account acc;
    int acc_no, found = 0;

    // input details
    printf("Please enter your Account Number: ");
    scanf("%d", &acc_no);

    // read and modify the records
    while (fscanf(fp, "%d %s %f \n", &acc.acc_number, acc.name, &acc.balance) == 3)
    {
        if (acc.acc_number == acc_no)
        {
            printf("Enter new name: ");
            scanf("%s", acc.name);
            printf("Enter new balance: ");
            scanf("%f", &acc.balance);
            found = 1;
        }
        fprintf(temp, "%d %s %.2f \n", acc.acc_number, acc.name, acc.balance);
    }

    // finalizing the changes
    fclose(fp);
    fclose(temp);
    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if (found)
    {
        printf("Account modified successfully.\n");
    }
    else
    {
        printf("Account not found.\n");
    }
}