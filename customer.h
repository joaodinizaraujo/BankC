#ifndef CUSTOMER_H
#define CUSTOMER_H

typedef struct{
	int id;
	char name[50];
	char email[50];
	char cpf[20];
	char birth_date[13];
	char register_date[13];
} customer;

void show_customer(customer customer);

#endif
