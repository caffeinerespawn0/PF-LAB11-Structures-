#include <stdio.h>
#include <string.h>

struct Transaction {
    char type[20];
    char date[20];
    float amount;
};

struct Account {
    char name[30];
    int accountNum;
    char type[20];
    float balance;
    float interestRate;
    char creationd[20];
    char lasttransd[20];
    struct Transaction transactions[100];
    int transactionCount;
};

struct Account accounts[100];
int n = 0; // number of accounts

void createAccount() {
    struct Account newAccount;

    printf("Enter your name: ");
    scanf("%s", newAccount.name);

    printf("Enter today's date (D/M/Y): ");
    scanf("%s", newAccount.creationd);

    printf("Enter your account number: ");
    scanf("%d", &newAccount.accountNum);

    printf("Enter your account type (Savings, Current, Fixed Deposit): ");
    scanf("%s", newAccount.type);

    newAccount.transactionCount = 0;
    strcpy(newAccount.lasttransd, newAccount.creationd);

    if (strcmp(newAccount.type, "Savings") == 0) {
        newAccount.balance = 1000;
        newAccount.interestRate = 4.0;
    } else if (strcmp(newAccount.type, "Current") == 0) {
        newAccount.balance = 5000;
        newAccount.interestRate = 0.0;
    } else if (strcmp(newAccount.type, "Fixed") == 0 || strcmp(newAccount.type, "Fixed Deposit") == 0) {
        newAccount.balance = 10000;
        newAccount.interestRate = 7.0;
    } else {
        printf("Invalid choice. Defaulting to Savings account.\n");
        strcpy(newAccount.type, "Savings");
        newAccount.balance = 1000;
        newAccount.interestRate = 4.0;
    }

    accounts[n] = newAccount;
    n++;
    printf("Your account has been created successfully!\n");
}

void depositMoney(int accIndex) {
    float amount;
    char date[20];

    printf("Enter the amount you want to deposit: ");
    scanf("%f", &amount);

    printf("Enter today's date (D/M/Y): ");
    scanf("%s", date);

    accounts[accIndex].balance += amount;
    strcpy(accounts[accIndex].lasttransd, date);

    int tIndex = accounts[accIndex].transactionCount;
    strcpy(accounts[accIndex].transactions[tIndex].type, "Deposit");
    accounts[accIndex].transactions[tIndex].amount = amount;
    strcpy(accounts[accIndex].transactions[tIndex].date, date);
    accounts[accIndex].transactionCount++;

    printf("Deposit successful! New balance: %.2f\n", accounts[accIndex].balance);
}

void withdrawMoney(int accIndex) {
    float amount;
    char date[20];
    float minBalance;

    if (strcmp(accounts[accIndex].type, "Savings") == 0) minBalance = 1000;
    else if (strcmp(accounts[accIndex].type, "Current") == 0) minBalance = 5000;
    else minBalance = 10000;

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    printf("Enter today's date (D/M/Y): ");
    scanf("%s", date);

    if (accounts[accIndex].balance - amount < minBalance) {
        printf("Withdrawal denied! Minimum balance must be maintained: %.2f\n", minBalance);
        return;
    }

    accounts[accIndex].balance -= amount;
    strcpy(accounts[accIndex].lasttransd, date);

    int tIndex = accounts[accIndex].transactionCount;
    strcpy(accounts[accIndex].transactions[tIndex].type, "Withdrawal");
    accounts[accIndex].transactions[tIndex].amount = amount;
    strcpy(accounts[accIndex].transactions[tIndex].date, date);
    accounts[accIndex].transactionCount++;

    printf("Withdrawal successful! New balance: %.2f\n", accounts[accIndex].balance);
}

void showTransactionHistory(int accIndex) {
    struct Account acc = accounts[accIndex];

    if (acc.transactionCount == 0) {
        printf("\nNo transactions yet for account %s (Account #%d)\n",
               acc.name, acc.accountNum);
        return;
    }

    printf("\n--- Transaction History for %s (Account #%d) ---\n",
           acc.name, acc.accountNum);

    for (int i = 0; i < acc.transactionCount; i++) {
        printf("%d. %s: %.2f on %s\n", i + 1,
               acc.transactions[i].type,
               acc.transactions[i].amount,
               acc.transactions[i].date);
    }
}

void displayAccount(int accIndex) {
    struct Account acc = accounts[accIndex];
    printf("\nAccount Info\n");
    printf("Name: %s\n", acc.name);
    printf("Account Number: %d\n", acc.accountNum);
    printf("Account Type: %s\n", acc.type);
    printf("Balance: %.2f\n", acc.balance);
    printf("Interest Rate: %.2f%%\n", acc.interestRate);
    printf("Creation Date: %s\n", acc.creationd);
    printf("Last Transaction Date: %s\n", acc.lasttransd);

    printf("\nTransaction History (%d transactions):\n", acc.transactionCount);
    for (int i = 0; i < acc.transactionCount; i++) {
        printf("%d. %s: %.2f on %s\n", i + 1,
               acc.transactions[i].type,
               acc.transactions[i].amount,
               acc.transactions[i].date);
    }
}

int main() {
    int choice, accIndex;

    while (1) {
        printf("\nWelcome to Bank Account Management System\n");
        printf("1. Create an Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Show Transaction History\n");
        printf("5. Show Account Details\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                if (n == 0) {
                    printf("No accounts created yet!\n");
                    break;
                }
                printf("Enter account index (0 to %d): ", n - 1);
                scanf("%d", &accIndex);
                if (accIndex < 0 || accIndex >= n) {
                    printf("Invalid account index!\n");
                    break;
                }
                if (choice == 2) depositMoney(accIndex);
                else if (choice == 3) withdrawMoney(accIndex);
                else if (choice == 4) showTransactionHistory(accIndex);
                else if (choice == 5) displayAccount(accIndex);
                break;
            case 6:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Enter a valid number!\n");
        }
    }

    return 0;
}
