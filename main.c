#include <stdio.h>
#include <windows.h>
#include "account.h"
#include "customer.h"

void menu();

static account accs[50];
static int count_accs = 0;
static int count_customers = 0;

int main(){
	printf("=============================\n");
	printf("=========== BankC ===========\n");
	printf("=============================\n\n");
	
	menu();
	return 0;
}

void menu(){
	int option = 0;
	
	printf("1- create account\n");
	printf("2- withdraw\n");
	printf("3- deposit\n");
	printf("4- transfer\n");
	printf("5- show accounts\n");
	printf("6- exit\n");
	printf("choose: ");
	
	scanf("%d", &option);
	getchar();

	switch(option){
		case 1:
			create_account(accs, &count_accs, &count_customers);
			Sleep(2);
			menu();
			break;
		case 2:
			if(count_accs > 0){
				int number;
				printf("Number of the account: \n");
				scanf("%d", &number);

				account acc = find_account_by_number(accs, count_accs, number);
				if(acc.number == number){
					float value;
					printf("Value: \n");
					scanf("%f", &value);
					withdraw(acc, value, accs, count_accs);
				} else {
					printf("No account with this number.\n");
				}
			} else {
				printf("No accounts in the bank.\n");
			}
			Sleep(2);
			menu();
			break;
		case 3:
			if(count_accs > 0){
				int number;
				printf("Number of the account: \n");
				scanf("%d", &number);

				account acc = find_account_by_number(accs, count_accs, number);
				if(acc.number == number){
					float value;
					printf("Value: \n");
					scanf("%f", &value);
					deposit(acc, value, accs, count_accs);
				} else {
					printf("No account with this number.\n");
				}
			} else {
				printf("No accounts in the bank.\n");
			}
			Sleep(2);
			menu();
			break;
		case 4:
			if(count_accs > 0){
				int number_origin, number_destiny;

				printf("Number of the origin account: \n");
				scanf("%d", &number_origin);
				account origin = find_account_by_number(accs, count_accs, number_origin);

				if(origin.number == number_origin){
					printf("Number of the destiny account: \n");
					scanf("%d", &number_destiny);
					account destiny = find_account_by_number(accs, count_accs, number_destiny);

					if(destiny.number == number_destiny){
						float value;
						printf("Value: \n");
						scanf("%f", &value);

						transfer(origin, destiny, value, accs, count_accs);
					} else {
						printf("No account with this number.\n");
					}
				} else {
					printf("No account with this number.\n");
				}
			} else {
				printf("No accounts in the bank.\n");
			}
			Sleep(2);
			menu();
			break;
		case 5:
			if(count_accs > 0){
				show_accounts(accs, count_accs);
			} else {
				printf("No accounts in the bank.\n");
			}
			Sleep(2);
			menu();
			break;
		case 6:
			printf("Goodbye!\n");
			Sleep(2);
			exit(0);
		default:
			printf("Invalid option.\n");
			Sleep(2);
			menu();
			break;
	}
}
