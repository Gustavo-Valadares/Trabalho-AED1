#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "users.hpp"
#include "menus.hpp"
#include "events.hpp"
#include "tickets.hpp"

using namespace std;


Event_List *create_elist(){

    Event_List *ne = NULL;
    
    ne = (Event_List*) malloc (sizeof(Event_List));
    ne->e_quant = 0;
    ne->head = NULL;

    return ne;
}


void delete_elist(Event_List *elist){
    Event *aux = NULL, *remove = NULL;

    
    if(elist->head){
        aux = elist->head;

        while(aux->next){
            remove = aux;
            aux = remove->next;
            free(remove);

        }

        free(aux);
    }

    free(elist);

}


void insert_event(Event *events, Event *ne){
    if(!(events->next)){
        events->next = ne;

        return ;
    }

    insert_event((events->next), ne);
    return ; 
}



void register_events(Event_List *e_List){
    
    Event *ne = NULL;
    string straux;
    string ename;
    string data;
    string local;
    double price;
    
    char check = 'n';


    while(check != 'y'){
        
        cout << "Nome do Evento: ";
        cin.ignore();
        getline(cin, straux);
        ename = straux;         

        cout << "Data: ";
        getline(cin, straux);
        data = straux;

        cout << "Local: ";
        getline(cin, straux);
        local = straux;

        cout << "Preço: ";
        cin >> price;


        cout << "\nAs informações estão corretas?\n\n[y]\t[n]\n\n";
        cin >> check;
        
    }

    ne = new_node_e(ename, data, local, price);

    if(!ne){
        cout << "Erro ao cadastrar evento\n\n";
        return ;
    }


    if(!e_List->head){
        e_List->head = ne;

    } else insert_event(e_List->head, ne);


} 


Event *new_node_e(string ename, string data, string local, double price){
    Event *e = NULL;
    
    e = (Event *) malloc (sizeof(Event));
    if(!e) return NULL;

    strcpy(e->ename, ename.c_str());
    strcpy(e->data, data.c_str());
    strcpy(e->local, local.c_str());

    e->price = price;
    e->next = NULL;


    return e;
}


bool show_user_events(Event *event){

    if(!event) return false;


    while(event){
        cout << "\n===============================================================================================\n";
        cout << "Evento: " << event->ename << "\n";
        cout << "Data: " << event->data << "\n";
        cout << "Local: " <<  event->local << "\n";
        cout << "Preço: " << event->price << "\n";

        event = event->next;
    }

    return true;


}


void remove_user_event(Event_List *e_List, string del_name, User *u){
    Event *remove, *eventAux;

    eventAux = NULL;
    remove = NULL;
    


        if(e_List->head->ename == del_name){

            remove = e_List->head;
            e_List->head = remove->next;

            cout << "Evento " << remove->ename << " Removido\n\n";

        } else {
            eventAux = e_List->head;

            while(eventAux->next->ename != del_name){
                eventAux = eventAux->next;

            }

            remove = eventAux->next;

            eventAux->next = remove->next;

            cout << "Evento " << remove->ename << " Removido\n\n";
        }


    //--------------Removendo Ingressos de usuários com ingressos do evento que foi excluido-------------------

    User *userAux = NULL;

        while(userAux){
            if(userAux->Adm == true){
                continue;

            } else {
                userAux->t_List;
                //procurar na lista de ingressos o ingresso de nome == del_name
            }

            userAux = userAux->next;

        }

    free(remove);
}



void show_all_events(StartUsers *UserList){
    User *user;
    Event *event;
    int check = 0;
    

    user = UserList->head; //user se torna o primeiro usuario da lista
 
    
    while(user){ //enquanto o user não for um ponteiro nulo (enquanto não atingir o final da lista)

        if(user->Adm){ // caso o usuário seja administrador, chama-se a função para mostrar os eventos disponíveis do usuário
            
            event = user->e_List->head;

            if(show_user_events(event)) check = 1;
        

        }

        user = user->next; //percorre a lista
    }


    if(check == 0){
        cout << "\nNão há Eventos cadastrados\n\n";
        return ;
    }

}



bool check_events(StartUsers *UserList){
    User *user;
    Event *event;
    int check = 0;

    user = UserList->head;


    while(user){ //enquanto o user não for um ponteiro nulo (enquanto não atingir o final da lista)

        if(user->Adm){ // caso o usuário seja administrador, chama-se a função para mostrar os eventos disponíveis do usuário
            if(user->e_List->head) return true;

        } 

        user = user->next; //percorre a lista
    }

    return false;
}



bool find_event(StartUsers *UserList, User *u, string straux){
    User *user = NULL;
    Event *event = NULL;
    Tick *nt = NULL;

    int check = 0;
    
    // cout << "Erro 2.1\n";
    user = UserList->head; //user se torna o primeiro usuario da lista
 
    
    while(user){ //enquanto o user não for um ponteiro nulo (enquanto não atingir o final da lista)

        // cout << "Erro 2.2\n";
        if(user->Adm){ // caso o usuário seja administrador, chama-se a função para mostrar os eventos disponíveis do usuário
            // cout << "Erro 2.3\n";
            event = user->e_List->head;
            
            while(event){

                // cout << "Erro 2.4\n";
                if(event->ename == straux){
                    
                    // cout << "Erro 2.5\n";
                    nt = new_node_t(event->ename, event->data, event->local);


                    show_user_tickets(nt);
                    cout << endl;

                    // cout << "Erro 2.6.1\n";

                    if(u->t_List->head == NULL){
                        u->t_List->head = nt;
                        return true;

                    } else {
                        insert_ticket(u->t_List->head, nt); 
                        return true;

                    }


                }

                event = event->next;
            }

        }

        user = user->next; //percorre a lista
    }

    return false;

}