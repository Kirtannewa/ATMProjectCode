#include <stdio.h>
double balance = 1000000;

int validatePin() 
{
    int pin, attempts = 0, correct_pin = 112233, i;
    do {
        printf("Enter your pin code: ");
        scanf("%d", &pin);

        if (pin != correct_pin) 
		{
            attempts++;
            if (attempts < 3) {
                printf("\nIncorrect PIN. Try again!\n\n");
                printf("%d Chance left\n\n", 3 - attempts);
            } 
			else 
			{
                printf("\nYour Account has been BLOCKED for a DAY.\n\n");
                return 0;
            }
        }
    } while (pin != correct_pin);

    printf("\nPIN accepted. Welcome!\n");
    printf("\n");
    return 1;
}

void displayCase() 
{
    printf("1. Balance Inquiry\n");
    printf("2. Withdraw Money\n");
    printf("3. Deposit Money\n");
    printf("4. Account information\n");
    printf("5. Exit\n\n");
}

void balanceInquiry() 
{
    printf("\nYour Total Balance: %.2f\n", balance);
}
bool withdrawMoney()
{
	int withdrawMoney, withdraw;
	float withdrawn_balance;
	printf("\nWithdraw Amount: ");
	scanf("%d", &withdraw);
	if(balance < withdraw)
	{
		printf("Insufficient Funds\n");
		return false;
	}
	else
	{
		withdrawn_balance = balance - withdraw;
		balance = withdrawn_balance;
		printf("\Amount %d has been withdrawn form your account\n",withdraw);
		printf("\nYour Total Balance is %.2f\n",withdrawn_balance);
		return true;
	}
}


void depositMoney() 
{
    int depo;
	float depo_balance;
    printf("How much amount would you like to deposit: ");
    scanf("%d", &depo);
    printf("\nAmount %dRs has been deposited to your account\n",depo);
    depo_balance = balance + depo;
    balance = depo_balance;
    printf("\nCurrent Balance:%.2f\n",depo_balance);
}

void accountInformation() 
{
    printf("Name: Kirtan Malakar\n");
    printf("Age: 20\n");
    printf("Sex: Male\n");
    printf("Bank Balance: %.2f\n", balance);
}

void exit()
{
	printf("-------Thank you for choosing DWIT BANK-------\n");
}



// ****main code starts of ATM*****//

int main() {
    int opt;
    char count;
    
    printf("-----Welcome to the ATM Machine-----\n\n");
    
    if (!validatePin()) 
	{
        return 0;
    }

    do {
        displayCase();
        printf("Enter Your Choice: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                balanceInquiry();
                break;
            case 2:
                if (balance < withdrawMoney())
				{
            	printf("Failed to withdraw money.\n");
        		}
        		break;
            case 3:
                depositMoney();
                break;
            case 4:
                accountInformation();
                break;
            case 5:
                exit();
                return 0;
            default:
                printf("\nInvalid option\n");
        }

        printf("\nDo you want to continue[Y/N]: ");
        scanf(" %c", &count);
        printf("\n");
    } while (count == 'Y' || count == 'y');

    printf("-------Thank you for choosing DWIT BANK-------\n");

    return 0;
}

