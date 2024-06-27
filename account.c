#include "account.h"
#include "customer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void create_account(){
    customer customer;

    char dia[3];
    char mes[3];
    char ano[4];
    char register_date[13];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    if(tm.tm_mday < 10){
        sprintf(dia, "0%d", tm.tm_mday);
    } else {
        sprintf(dia, "%d", tm.tm_mday);
    }

    if((tm.tm_mon + 1) < 10){
        sprintf(mes, "0%d", tm.tm_mon + 1);
    } else {
        sprintf(mes, "%d", tm.tm_mon + 1);
    }

    sprintf(ano, "%d", tm.tm_year + 1900);

    strcpy(register_date, "");
    strcat(register_date, dia);
    strcat(register_date, "/");
    strcat(register_date, mes);
    strcat(register_date, "/");
    strcat(register_date, ano);
    strcat(register_date, "\0");
    strcpy(customer.register_date, register_date);
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
    printf("Number: %s\nCustomer: %s\nBirth date: %s\nRegister date: %s\nTotal balance: %.2f\n",
    acc.number, strtok(acc.customer.name, "\n"), strtok(acc.customer.birth_date, "\n"), strtok(acc.customer.register_date), acc.total_balance);
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