#ifndef _TICKETS_HPP_
#define _TICKETS_HPP_

#include <iostream>
#include "users.hpp"

#define T 10


using namespace std;

struct Tick{
    char *tname; //nome do ticket
    char *data;
    char *local;
    char *organizer;
    int t_id;

    Tick *next;
};


struct Tick_List{
    Tick *head;
    int t_quant;
};


Tick_List *create_tlist();

Tick *new_node_t(string tname, string data, string local);

void insert_ticket(Tick *tickets, Tick *newTicket);

void register_tickets(Tick_List *t_List, int t_quant, Event *e);

void show_user_tickets(Tick *ticket);
#endif