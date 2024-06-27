#include "customer.h"

typedef struct{
	int number;
	customer customer;
	float balance;
	float limit;
	float total_balance;  // balance + limit
} account;

void create_account();
void withdraw(account acc, float value, account *accs, int count_accs);
void deposit(account acc, float value, account *accs, int count_accs);
void transfer(account origin, account destiny, float value, account *accs, int count_accs);
void show_account(account acc);
void update_total_balance(account acc);
account find_account_by_number(account *accs, int count_accs, int number);
void show_accounts(account *accs, int count_accs);