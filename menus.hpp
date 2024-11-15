#ifndef _MENUS_HPP_
#define _MENUS_HPP_
#include <iostream>
#include "users.hpp"


using namespace std;


void start_menu(StartUsers *UserList);

void user_menu(StartUsers *Fuser, User *u);

void credit_menu(User *u);

void user_menu_adm(StartUsers *Fuser, User *u);


#endif