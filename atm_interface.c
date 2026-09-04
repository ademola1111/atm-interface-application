#include <stdio.h>

int main()
{
    int pin;
    int enteredPin;
    int choice;
    int newPin;

    float balance = 50000.00;
    float amount;

    printf("=================================\n");
    printf("        WELCOME TO ATM\n");
    printf("=================================\n");

    printf("Create your 4-digit PIN: ");
    scanf("%d", &pin);

    if (pin < 1000 || pin > 9999)
    {
        printf("Invalid PIN. PIN must be 4 digits.\n");
        return 0;
    }

    printf("\nPIN created successfully!\n");

    printf("\nEnter your PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin != pin)
    {
        printf("Incorrect PIN. Access denied.\n");
        return 0;
    }

    printf("\nLogin successful!\n");
    do
    {
        printf("\n=================================\n");
        printf("             ATM MENU\n");
        printf("=================================\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Change PIN\n");
        printf("5. Transfer Money\n");
        printf("6. Exit\n");
        printf("=================================\n");

        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nCurrent Balance: N%.2f\n", balance);
            break;

        case 2:
            printf("\nEnter amount to deposit: N");
            scanf("%f", &amount);

            if (amount > 0)
            {
                balance += amount;
                printf("Deposit successful.\n");
                printf("New Balance: N%.2f\n", balance);
            }
            else
            {
                printf("Invalid amount.\n");
            }
            break;

        case 3:
            printf("\nEnter amount to withdraw: N");
            scanf("%f", &amount);

            if (amount <= 0)
            {
                printf("Invalid amount.\n");
            }
            else if (amount > balance)
            {
                printf("Insufficient balance.\n");
            }
            else
            {
                balance -= amount;
                printf("Withdrawal successful.\n");
                printf("Remaining Balance: N%.2f\n", balance);
            }
            break;

        case 4:
            printf("\nEnter your current PIN: ");
            scanf("%d", &enteredPin);

            if (enteredPin == pin)
            {
                printf("Enter your new 4-digit PIN: ");
                scanf("%d", &newPin);

                if (newPin >= 1000 && newPin <= 9999)
                {
                    pin = newPin;
                    printf("PIN changed successfully.\n");
                }
                else
                {
                    printf("Invalid PIN. PIN must be 4 digits.\n");
                }
            }
            else
            {
                printf("Incorrect PIN.\n");
            }
            break;

        case 5:
            printf("\nEnter amount to transfer: N");
            scanf("%f", &amount);

            if (amount <= 0)
            {
                printf("Invalid amount.\n");
            }
            else if (amount > balance)
            {
                printf("Insufficient balance.\n");
            }
            else
            {
                balance -= amount;

                printf("Transfer successful.\n");
                printf("Amount transferred: N%.2f\n", amount);
                printf("Remaining Balance: N%.2f\n", balance);
            }
            break;

        case 6:
            printf("\nThank you for using the ATM. Goodbye!\n");
            break;

        default:
            printf("\nInvalid option. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}