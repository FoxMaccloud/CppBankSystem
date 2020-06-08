#include <iostream>
#include <fstream>
#include <stdlib.h>
//#include "ConsoleColor.h"

struct date
{
    int month, day, year;
};



struct personalData
{
    
    char name;
    int accountNumber;
    int age;
    char address;
    char nationality;
    double phone;
    float amount;
    struct date dob;    
    struct date deposit;
    struct date withdraw;
    
}add,upd,check,rem,transaction;


void welcomeMenu()
{
    std::cout << "\t\t\t*** WELCOME TO THE MAIN MENU! ***\n" << std::endl;
}

int menu()
{
    std::cout << "\t\t\t1. Create new account" << std::endl;
    std::cout << "\t\t\t2. Update information of existing account" << std::endl;
    std::cout << "\t\t\t3. For transactions" << std::endl;
    std::cout << "\t\t\t4. Check the details of existing account" << std::endl;
    std::cout << "\t\t\t5. Removing existing account" << std::endl;
    std::cout << "\t\t\t6. View customer's list" << std::endl;
    std::cout << "\t\t\t7. Exit" << std::endl;
    
    std::cout << "\t\t\tEnter your choice:" << std::endl;

    int menuChoice;
    

    while (true)
    {
        std::cin >> menuChoice; 
        if (0 < menuChoice && menuChoice < 8)
        {
            std::cout << "Menu choice: " << menuChoice << std::endl;
            break;
        } else {
            std::cout << "Invalid choice!" << std::endl;
        }
    }
    return menuChoice;
}


void newAccount()
{
    int choice;
    FILE *ptr;

    ptr = fopen("record.dat", "a+");
    account_num:
    system("clear");
    std::cout << "\n\n\t\t\t\xB2\xB2\xB2\xB2\ ADD RECORD  \xB2\xB2\xB2\xB2" << std::endl;
    std::cout << "\n\n\n\t\t\tEnter today's date(mm/dd/yyyy):" << std::endl;
    
    scanf("%d/%d/%d", &add.deposit.month, &add.deposit.day, &add.deposit.year);
    std::cout << "\n\t\t\tEnter the account number: " << std::endl;

    scanf("%d", &check.accountNumber);

    while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %d/%d/%d\n", &add.accountNumber, &add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, &add.address, &add.nationality, &add.phone, &add.deposit, &add.deposit.day, &add.deposit.month, &add.deposit.year)!=EOF)
    {
        if (check.accountNumber == add.accountNumber)
        {
            std::cout << "Account number is already in use!" << std::endl;
        }
        
    }

    add.accountNumber = check.accountNumber;
    std::cout << "\t\t\tEnter name: " << std::endl;
    scanf("%s", add.name);
    std::cout << "\t\t\tEnter the date of birth (dd/mm/yyyy): " << std::endl;
    scanf("%d/%d/%d", &add.dob.day, &add.dob.month, &add.dob.year);
    std::cout << "\t\t\tEnter the age: " << std::endl;
    scanf("%d", &add.age);
    std::cout << "\t\t\tEnter the address: " << std::endl;
    scanf("%s", &add.address);
    std::cout << "\t\t\tAdd the Nationality" << std::endl;
    scanf("%s", &add.nationality);
    std::cout << "\t\t\tAdd the phone number: " << std::endl;
    scanf("%lf", &add.phone);
    std::cout << "\t\t\tEnter the amount to deposit: $" << std::endl;
    scanf("%f", &add.amount);
    
    fclose(ptr);

    std::cout << "\t\t\tAccount created successfully!" << std::endl;
    std::cout << "\n\t\t\tEnter 1 to go back the main menu \n 0 to exit:" << std::endl;
    int option;
    std::cin >> option;
    while (true)
    {
        if (option == 1)
        {
            menu();
            break;
        } else if (option == 0) {
            close();
            break;
        } else {
            std::cout << "\t\t\tInvalid option!" << std::endl;
        }
    }

    
    




}

void viewAccounts()
{
    FILE *view;
    int records = 0;
    view=fopen("record.dat","r");
    system("clear");
    std::cout << "\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n" << std::endl;

    while (fscanf(view, "%d %s %d/%d/%d %d %s %s %lf %s %d/%d/%d\n", &add.accountNumber, &add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, &add.address, &add.nationality, &add.phone, &add.deposit, &add.deposit.day, &add.deposit.month, &add.deposit.year)!=EOF)
    {
        std::cout << "\n" << &add.accountNumber << " " << &add.name << " " << &add.address << " " << &add.phone << std::endl;
        records++;
    }

    fclose(view);
    if (records == 0)
    {
        system("clear");
        std::cout << "\n NO RECORDS!\n" << std::endl; 
    }
    

    std::cout << "\n\t\t\tEnter 1 to go back the main menu \n 0 to exit:" << std::endl;
    int option;
    std::cin >> option;
    while (true)
    {
        if (option == 1)
        {
            menu();
            break;
        } else if (option == 0) {
            close();
            break;
        } else {
            std::cout << "\t\t\tInvalid option!" << std::endl;
        }
    }
}

void edit(void)
{
    int choice,test=0;
    FILE *oldRecord,*newRecord;
    oldRecord = fopen("record.dat","r");
    newRecord = fopen("new.dat","w");




    fclose(oldRecord);
    fclose(newRecord);
    remove("record.dat");
    rename("new.dat","record.dat");

}

void transact(void)
{   int choice,test=0;
    FILE *oldRecord,*newRecord;
    oldRecord = fopen("record.dat","r");
    newRecord = fopen("new.dat","w");



   fclose(oldRecord);
   fclose(newRecord);
   remove("record.dat");
   rename("new.dat","record.dat");

}


void erase(void)
{
    FILE *oldRecord,*newRecord;
    int test=0;
    oldRecord=fopen("record.dat","r");
    newRecord=fopen("new.dat","w");



    fclose(oldRecord);
    fclose(newRecord);
    remove("record.dat");
    rename("new.dat","record.dat");

}


void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");


    fclose(ptr);
}


void close(void)
{
    std::cout << "\n\t\t\tGoodbye!" << std::endl;
}



int main()
{
    int menuChoice;
    
    system("clear");
    std::cout << "\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n" << std::endl;
    
    welcomeMenu();
    int menuChoise = menu();

    switch (menuChoise)
    {
    case 1: newAccount();
        break;
    case 2: close();
        break;
    case 3: close();
        break;
    case 4: viewAccounts();
        break;
    default:
        break;
    }





    return 0;
}
