typedef struct{
	int id;
	char name[50];
	char email[50];
	char cpf[20];
	char birth_date[10];
	char register_date[10];
} customer;

void show_customer(customer customer);
