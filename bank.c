#include<stdio.h>

struct Bank
{
	int accno;
	char name[25];
	float balance;
};
void accept(struct Bank [],int);
void display(struct Bank [],int);
void lessBal(struct Bank [],int);
void WithdrawDeposit(struct Bank [],int);
int main()
{
	struct Bank b1[5];
	accept(b1,5);
	display(b1,5);
	int ch;
	while(1)
	{
		printf("\n\n\nPress 1 for Viewing Minimum Balance account\nPress 2 for Withdraw Deposit\nPress 3 for displaying all accounts\nEnter Your Choice :");
		scanf("%d",&ch);

		switch(ch)
		{
		case 1:lessBal(b1,5);
				break;
		case 2: WithdrawDeposit(b1,5);
				break;
		case 3:display(b1,5);
				break;
		}
	
	}
	
	return 0;
}

void accept(struct Bank sarr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\nEnter the bank Account no :");
		scanf("%d",&sarr[i].accno);

		printf("\nEnter the bank Account  holder name :");
		scanf("%s",sarr[i].name);

		printf("\nEnter the bank balance :");
		scanf("%f",&sarr[i].balance);

		printf("\n");
	}
}

void display(struct Bank sarr[],int n)
{
	printf("\n\n*******************************************************************************");
	for(int i=0;i<n;i++)
	{
		printf("\nBank Account no : %d",sarr[i].accno);
		

		printf("\nEnter the bank Account  holder name : %s",sarr[i].name);
		

		printf("\nEnter the bank balance : %f",sarr[i].balance);
		printf("\n");
	}
}

void lessBal(struct Bank sarr[],int n)
{
	printf("\nCustomers having min. bank balance are :\n");
	for(int i=0;i<n;i++)
	{
		if(sarr[i].balance<100)
		{
			printf("\nAccount No : %d",sarr[i].accno);
			printf("\nName : %s",sarr[i].name);
		}
	}

}


void WithdrawDeposit(struct Bank sarr[],int n)
{
	int acc;
	float amount;
	int code;

	printf("\nEnter Account no :");
	scanf("%d",&acc);

	printf("\nEnter the code (1:Withdraw & 0:Deposit):");
	scanf("%d",&code);

	if(code)
	{
		printf("\nEnter the Amount to be Withdrawn :");
		scanf("%f",&amount);

		for(int i=0;i<n;i++)
		{
			if(sarr[i].accno == acc && sarr[i].balance>100)
			{
				printf("Hello %s,",sarr[i].name);
				sarr[i].balance=sarr[i].balance-amount;
				printf("\nWithdraw successfull");
				printf("\nYour Updated Balance is %f\n",sarr[i].balance );
				break;
			}
			if(sarr[i].accno==acc && sarr[i].balance<100)
			{
				printf("\nLess balance detected. Cannot Withdraw the Amount" );
			}
			
			
		}

	}
	else if(code==0)
	{
		printf("\nEnter the Amount to be Deposited :");
		scanf("%f",&amount);

		for(int i=0;i<n;i++)
		{
			if(sarr[i].accno == acc && sarr[i].balance>100)
			{
				printf("Hello %s,",sarr[i].name);
				sarr[i].balance=sarr[i].balance+amount;
				printf("\nDeposit successfull");
				printf("\nYour Updated Balance is %f\n",sarr[i].balance );
				break;
			}

		}

	}
	

}