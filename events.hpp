#ifndef _EVENTS_HPP_
#define _EVENTS_HPP_
#include <iostream>
#include <string>
#include "users.hpp"


using namespace std;

struct Event{
    char ename[50];
    char data[50];
    char local[50];
    double price;
    int e_id;
    Event *next;

};

struct Event_List{
    Event *head;
    int e_quant;
};


Event_List *create_elist();

Event *new_node_e(string ename, string data, string local, double price);

void delete_elist(Event_List *elist);

void insert_event(Event *event, Event *ne);

//void show_ingressos(Tick *u_tickets);

bool show_user_events(Event *events);

void register_events(Event_List *events);

void remove_user_event(Event_List *e_List, string del_name);

void delete_event(Event *events);

#endif