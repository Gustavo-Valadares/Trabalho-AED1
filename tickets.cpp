#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "users.hpp"
#include "events.hpp"
#include "tickets.hpp"


using namespace std;


Tick_List *create_tlist(){

    Tick_List *newTicket = NULL;

    newTicket = (Tick_List *) malloc (sizeof(Tick_List));
    newTicket->t_quant = 0;
    newTicket->head = NULL;


    return newTicket;
}



void insert_ticket(Tick *tickets, Tick *newTicket){
    cout << "Erro 3.1\n";
    if(!(tickets->next)){
        cout << "Erro 3.2\n";
        tickets->next = newTicket;
        cout << "Erro 3.3.1\n";

        return ;
    }

    cout << "Erro 3.3.2\n";
    insert_ticket((tickets->next), newTicket);
    return ;
}



void register_tickets(Tick_List *t_List, int t_quant, Event *e){ //recebe o 
    Tick *newTicket = NULL;

    if(t_quant == 10){
        cout << "Você só pode obter 10 ingressos\n\n";
        return ; 
    }


    newTicket = new_node_t(e->ename, e->data, e->local);

    if(!newTicket){
        cout << "Erro ao cadastrar evento\n\n";
        return ;
    }


    if(!t_List->head){
        t_List->head = newTicket;

    } else insert_ticket(t_List->head, newTicket);
}





Tick *new_node_t(string tname, string data, string local){
    Tick *t = NULL;

    t = (Tick *) malloc (sizeof(Tick));
    if(!t) return NULL;

    strcpy(t->tname, tname.c_str());
    strcpy(t->data, data.c_str());
    strcpy(t->local, local.c_str());

    t->next = NULL;

    return t;
}



void show_user_tickets(Tick *ticket){

    if(!ticket) return ;

    cout << "\n===============================================================================================\n";
    cout << "Ingresso: " << ticket->tname << "\n";
    cout << "Data: " << ticket->data << "\n";
    cout << "Local: " <<  ticket->local << "\n";

    if(ticket->next) show_user_tickets(ticket->next);
    else return ;

}