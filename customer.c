#include <stdio.h>
#include "customer.h"

void show_customer(customer customer){
    printf("ID: %d\nName: %s\nBirth date: %s\nRegister date: %s\n",
    customer.id, strtok(customer.name, "\n"), strtok(customer.birth_date, "\n"), strtok(customer.register_date, "\n"));
}   