#include <stdio.h>
#include <windows.h>
#include "account.h"
#include "customer.h"

void menu();

static account accs[50];
static int count_accs = 0;
static int count_customers = 0;

int main(){
	return 0;
}

void menu(){
	int opcao = 0;
	printf("=============================\n");
	printf("=========== BankC ===========\n");
	printf("=============================\n\n");
	
	printf("1- criar conta\n");
	printf("2- sacar\n");
	printf("3- depositar\n");
	printf("4- transferir\n");
	printf("5- listar contas\n");
	printf("6- sair\n");
	
	scanf("%d", &opcao);
	getchar();

	switch(opcao){
		case 1:
			create_account();
			break;
		case 2:
			withdraw();
			break;
		case 3:
			deposit();
			break;
		case 4:
			transfer();
			break;
		case 5:
			show_accounts();
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
