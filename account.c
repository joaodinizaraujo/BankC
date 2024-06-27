#include "account.h"
#include "customer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifndef ACCOUNT_H
#define ACCOUNT_H

void create_account(account *accs, int *count_accs, int *count_customers){
    customer customer;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    char register_date[11];
    sprintf(register_date, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(customer.register_date, register_date);
    
    printf("Customer data:\n");
    customer.id = (*count_customers) + 1;

    printf("Name: \n");
    fgets(customer.name, 50, stdin);

    printf("Email: \n");
    fgets(customer.email, 50, stdin);

    printf("CPF: \n");
    fgets(customer.cpf, 20, stdin);
    
    printf("Birth date: \n");
    fgets(customer.birth_date, 20, stdin);

    (*count_customers)++;

    accs[(*count_accs)].number = (*count_accs) + 1;
    accs[(*count_accs)].customer = customer;
    accs[(*count_accs)].balance = 0.0;
    accs[(*count_accs)].limit = 0.0;
    accs[(*count_accs)].total_balance = 0.0;

    show_account(accs[(*count_accs)]);

    (*count_accs)++;
}

void withdraw(account acc, float value, account *accs, int count_accs){
    if(value > 0 && acc.total_balance >= value){
        for(int i = 0; i < count_accs; i++){
            if(accs[i].number == acc.number){
                if(accs[i].balance >= value){
                    accs[i].balance = accs[i].balance - value;
                    accs[i].total_balance = update_total_balance(accs[i]);
                } else {
                    float restante = accs[i].balance - value;
                    accs[i].limit = accs[i].limit - restante;
                    accs[i].balance = 0.0;
                    accs[i].total_balance = update_total_balance(accs[i]);
                }
                printf("Withdraw done.\n");
            }
        }
    } else {
        printf("Withdraw not done. Please try again.\n");
    }
}

void deposit(account acc, float value, account *accs, int count_accs){
    if(value > 0){
        for(int i = 0; i < count_accs; i++){
            if(accs[i].number == acc.number){
                accs[i].balance = accs[i].balance + value;
                accs[i].total_balance = update_total_balance(accs[i]);
                printf("Deposit done.\n");
            }
        }
    } else {
        printf("Error during deposit. Try again.\n");
    }
}

void transfer(account origin, account destiny, float value, account *accs, int count_accs){
    if(value > 0 && origin.total_balance >= value){
        for(int i = 0; i < count_accs; i++){
            if(accs[i].number == origin.number){
                for(int j = 0; j < count_accs; j++){
                    if(accs[i].number == destiny.number){
                        if(accs[i].balance >= value){
                            accs[i].balance = accs[i].balance - value;
                            accs[j].balance = accs[j].balance + value;
                            accs[i].total_balance = update_total_balance(accs[i]);
                            accs[j].total_balance = update_total_balance(accs[j]);
                        } else {
                            float restante = accs[i].balance - value;
                            accs[i].limit = accs[i].limit + restante;
                            accs[i].balance = 0.0;
                            accs[j].balance = accs[j].balance + value;
                            accs[i].total_balance = update_total_balance(accs[i]);
                            accs[j].total_balance = update_total_balance(accs[j]);
                        }
                        printf("Transfer done.\n");
                    }
                }
            }
        }
    } else {
        printf("Transfer not done.\n");
    }
}

void show_account(account acc){
    printf(
        "\nAccount: \nNumber: %d\nCustomer: %s\nBirth date: %s\nRegister date: %s\nTotal balance: %.2f\n",
        acc.number, 
        strtok(acc.customer.name, "\n"), 
        strtok(acc.customer.birth_date, "\n"), 
        strtok(acc.customer.register_date, "\n"), 
        acc.total_balance
    );
}

float update_total_balance(account acc){
    return acc.balance + acc.limit;
}

account find_account_by_number(account *accs, int count_accs, int number){
    account acc;
    if(count_accs > 0){
        for(int i = 0; i < count_accs; i++){
            if(accs[i].number == number){
                acc = accs[i];
                break;
            }
        }
    }
    return acc;
}

void show_accounts(account *accs, int count_accs){
    for(int i = 0; i < count_accs; i++){
        show_account(accs[i]);
    }
}

#endif