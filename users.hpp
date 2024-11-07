#ifndef _USERS_HPP_
#define _USERS_HPP_
#include <iostream>
#include <string>
#include "events.hpp"
#include "tickets.hpp"


using namespace std;

struct User{ // struct nó
    char name[50];
    long int CPF;
    string password;
    double cred;
    bool Adm;
    User *next;

    Event_List *e_List;
    //int e_quant;

    Tick_List *t_List;
    //int t_quant;

};

struct StartUsers { //struct inicio
    User *head;
    int Uquant;

};


StartUsers *create_list(void);
bool check_list(StartUsers *UserList);

void insert_user(User **List, User *nu);

User *new_node(string name, string password, bool Adm, long int CPF);

void delete_user(User *nu);

bool new_user(StartUsers *List);;

void cadastre(StartUsers *List);

void show_users(User *List);

bool check_cpf(User *List, long int CPF);

void login(StartUsers *List);

User *check_log(User *u, long int CPF);

void show_all_events(StartUsers *UserList);

void remove_user(StartUsers *List, long int CPF);

void run_t_list(StartUsers *UserList);

bool find_event(StartUsers *List, string straux);

bool check_events(StartUsers *UserList);

void register_user(StartUsers *List);


#endif