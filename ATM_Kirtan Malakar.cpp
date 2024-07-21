//pin code = 112233
#include <stdio.h>
double balance = 1000000;
int main()
{
	int opt, chance = 2;
	char count;
	int pin, attempts = 0, correct_pin = 112233, withdraw, withdrawn_balance, depo, depo_balance, i;
	
	
	printf("-----Welcome to the ATM Machine-----\n\n");

	do{
		printf("Enter your pin code: ");
		scanf("%d", &pin);
		
		if (pin != correct_pin) 
		{
			attempts++;
			if (attempts < 3) 
			{
				printf("\nIncorrect PIN. Try again!\n\n");
				for (i=0; i<=3; i++);
				printf("%d Chance left\n\n",chance);
				chance--;
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
	
	do{
		printf("1.Balance Inquiry\n");
		printf("2.Withdraw Money\n");
		printf("3.Deposit Money\n");
		printf("4.Account information\n");
		printf("5.Exit\n\n");
		
		printf("Enter Your Choice: \n");
		scanf(" %d",&opt);
		
		switch(opt)
		{
			
			case 1:
				printf("\nYour Total Balance:%.2f\n", balance);
				break;
			case 2:
				printf("\nWithdraw Amount: \n");
				scanf("%d",&withdraw);
				if(balance < withdraw)
				{
					printf("Insuffiecient funds");
				}
				else
				{
				withdrawn_balance = balance - withdraw;
				balance = withdrawn_balance;
				printf("\nAmount %d has been withdrawn from your account\n",withdraw);
				printf("\nYour Total Balance is %d\n",withdrawn_balance);
				}
			
				break;
			case 3:
				printf("How much you amount would you like to deposit: \n");
				scanf("%d",&depo);
				printf("\nAmount %dRs has been deposited to your account\n",depo);
				depo_balance = balance + depo;
				balance = depo_balance;
				printf("\nCurrent Balance:%d\n",depo_balance);
				break;
			case 4:
				printf("Name: Kirtan Malakar\n");
				printf("Age: 20\n");
				printf("Sex: Male\n");
				printf("Bank Balance: %.2f\n",balance);
				break;
			case 5:
				printf("-------Thank for choosing DWIT BANK-------");
				return 0;
				break;
			default:
			printf("\nInvalid option\n");
			
		}
		printf("\nDo you want to continue[Y/N]:");
		scanf(" %c",&count);
		printf("\n");
	}while(count == 'Y' || count == 'y');
	
	printf("-------Thank for choosing DWIT BANK-------");
 	
	return 0;
}


