#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encrypt.h"

#define MAX_ACCOUNTS 100
#define MAX_PASSWORD_LENGTH 50

struct Account {
    char website[100];
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
};

struct Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;
char f;



//function to save the data to the file named accounts
void saveAccountsToFile() {
    FILE *file = fopen("accounts.txt", "w");
    if (file == NULL) {
        perror("\n\t\t\t\t\t\tError opening file");
        return;
    }

    for (int i = 0; i < numAccounts; i++) {
        fprintf(file, "%s %s %s\n", accounts[i].website, accounts[i].username, accounts[i].password);
    }

    fclose(file);
}





//function to load the data from the file named accounts
void loadAccountsFromFile() {
    FILE *file = fopen("accounts.txt", "r");
    if (file == NULL) {
        perror("\n\t\t\t\t\t\tError opening file");
        return;
    }

    while (fscanf(file, "%s %s %s", accounts[numAccounts].website, accounts[numAccounts].username, accounts[numAccounts].password) != EOF) {
        numAccounts++;
    }

    fclose(file);
}





//function to create new account
void createAccount() {
    if (numAccounts < MAX_ACCOUNTS) {
        struct Account newAccount;
	printf("\n\t\t\t\t\t**********Enter the details for creating new account:**********\n");
        printf("\t\t\t\t\t\tEnter website: ");
        scanf("%s", newAccount.website);
        printf("\t\t\t\t\t\tEnter username: ");
        scanf("%s", newAccount.username);
        printf("\t\t\t\t\t\tEnter password: ");
        scanf("%s", newAccount.password);
	encrypt(newAccount.password, 6);
        accounts[numAccounts] = newAccount;
        numAccounts++;
	system("clear");
        printf("\t\t\t\t\t\t**********Account created!**********\n");
        saveAccountsToFile();
    } else {
        printf("\t\t\t\t\t\tCannot create more accounts. Storage is full.\n");
    }
}





//function to retrieve the password
void retrieveAccount() {
    char website[100];
    printf("\n\t\t\t\t\t**********Enter the details for retrieving the account:**********\n");
    printf("\t\t\t\t\t\tEnter website: ");
    scanf("%s", website);
    int l=0;

    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].website, website) == 0) {
            printf("\n\t\t\t\t\t\tWebsite: %s\n", accounts[i].website);
            printf("\t\t\t\t\t\tUsername: %s\n", accounts[i].username);
	    char passw[50];
		   strcpy(passw,accounts[i].password);
	    decrypt(passw, 6);
            printf("\t\t\t\t\t\tPassword: %s\n", passw);
	    l=1;
            
        }
    }
    if(l){
    printf("\t\t\t\t\t\tAccounts found.\n");
    printf("\n\t\t\t\t\t\tPress enter to procced to main menu");
    getchar();
    getchar();
    system("clear");
    }
    else{
    printf("\t\t\t\t\t\tAccount not found.\n");
    printf("\n\t\t\t\t\t\tPress enter to procced to main menu");
    getchar();
    getchar();
    system("clear");
    }
}





//function to login to the password manager
int login() {
    char username[50];
    char password[50];
    char user[]="Varun";
    char pass[]="@Jindal";

    printf("\n\t\t\t\t\t**********WELCOME TO PASSWORD HANDLER...LOGIN TO PROCEED**********\n");
    printf("\t\t\t\t\t\tEnter username: ");
    scanf("%s", username);
    printf("\t\t\t\t\t\tEnter password: ");
    scanf("%s", password);

        if (strcmp(user, username) == 0 && strcmp(pass, password) == 0){
            printf("\t\t\t\t\t\tLogin successful!\n");
            return 1;
        }

    printf("\t\t\t\t\t\tLogin failed. Invalid username or password.\n");
    return 0;
}





//function to sort the data
void bubbleSort(struct Account *arr, int n) {
    struct Account temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].website, arr[j + 1].website) > 0) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}






int main() {
     system("clear");
     if( login()==1) {
     loadAccountsFromFile();
     system("clear");
     printf("\t\t\t\t\t\t**********Logged in successfully.**********\n");

    int choice;

    while (1) {
        printf("\n\t\t\t\t\t**********Password Manager Menu:**********\n");
        printf("\n\t\t\t\t\t\t1. Create Account\n");
        printf("\t\t\t\t\t\t2. Retrieve Account Credentials\n");
	printf("\t\t\t\t\t\t3. Show the sorted list of all websites stored.\n");
        printf("\t\t\t\t\t\t4. Exit\n");
	printf("\n\t\t\t\t\t******************************************\n");
        printf("\t\t\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);
	system("clear");

        switch (choice) {
            case 1:
                createAccount();
                break;

            case 2:
                retrieveAccount();
                break;

            case 3:
		bubbleSort(accounts, numAccounts);
		printf("\n\t\t\t\t\t\tWEBSITE \t USERNAME \t ENCRYTED PASSWORD");
		for(int i=0;i<numAccounts;i++){
			printf("\n\t\t\t\t\t\t%s \t %s \t %s\n",accounts[i].website,accounts[i].username,accounts[i].password);
		}
		printf("\n\t\t\t\t\t\tPress enter to procced to main menu");
                getchar();
                getchar();
                system("clear");
		break;
		
            case 4:
                printf("\t\t\t\t\t\tExiting the password manager.\n");
                saveAccountsToFile();
                return 0;

            default:
                printf("\t\t\t\t\t\tInvalid choice. Please enter a valid option.\n");
                break;
        }
    }
	       }
	       else{
	       printf("\t\t\t\t\t\tWrong password.\n");
	       }
        
    return 0;
}
