#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include "users.hpp"
#include "menus.hpp"
#include "events.hpp"



using namespace std;


StartUsers *create_list(void){
    StartUsers *List;

    List = (StartUsers *) malloc (sizeof(StartUsers));

    List->Uquant = 0;
    List->head = NULL;

    return List;
}


bool check_list(StartUsers *UserList){
    return UserList;
}


void insert_user(User *Fuser, User *nu){ //função recursiva que insere o usuario na lista //Fuser = Fist user
    if(!(Fuser->next)){
        Fuser->next = nu;
        
        return ;

    }

    insert_user((Fuser->next), nu);
    return ;
}


User *new_node(string name, string password, bool Adm, long int CPF){
    User *u = NULL;

    u = (User *) malloc (sizeof(User)); 
    if(!u) return NULL;

    strcpy(u->name, name.c_str());

    u->next = NULL;
    u->cred = 0;

    u->CPF = CPF;
    u->password = password;
    u->Adm = Adm;


    if(Adm){
        u->e_List = create_elist();
        u->t_List = NULL;

    } else {
        u->t_List = create_tlist();
        u->e_List = NULL;
        
    }

    return u;
}


void delete_user(User *u){
    
    cout << "err\n";
    if(u->Adm){
        cout << "err1\n";
        delete_elist(u->e_List);
    }
    else free(u->t_List);

    free(u);

}


bool new_user(StartUsers *List){
    User *nu = NULL;
    string name;
    string password_conf;
    string password;
    int name_l;
    char is_adm;
    bool Adm;
    int Adm_password;
    long int CPF;


//(---------------------------------Verificando CPF--------------------------------------------)

    cout << "\nCPF: ";
    cin >> CPF;


//(------------------------------------Recebendo Informações do Usuário-----------------------------------------)

    cout << "Nome de Usuário: ";
    getchar();
    getline(cin, name);


    while(1){
        cout << "\nSenha: ";
        getline(cin, password);

        cout << "Confirme sua senha: ";
        getline(cin, password_conf);

        if(password_conf != password) cout << "As senhas não são iguais! Tente novamente\n\n";
        else break;
    }




//(-----------------------------Administrador-----------------------------------------------)

        cout << "\nDeseja se tornar Administrador?\n\n[y]\t[n]\n\n";
        cin >> is_adm;

        do{

            if(is_adm == 'n'){
                Adm = false;
                break;
            }

            cout << "\nSenha de Administrador: ";
            cin >> Adm_password;

            if(Adm_password == 12345){
                Adm = true;
                break;

            } else {
                cout << "\nSenha Incorreta\n";
                Adm = false;

                cout << "\nTentar novamente?\n\n[y]\t[n]\n";
                cin >> is_adm;

            }
        } while(is_adm == 'y');



//------------------------------------Inserindo Usuário---------------------------------

        //cout << name << endl;
        nu = new_node(name, password, Adm, CPF);
        

        if(!nu) return false;


        if(!List->head){

            List->head = nu;

        } else {
            if(check_cpf(List->head, nu->CPF) == false){   
                insert_user(List->head, nu);

            } else {
                free(nu);
                cout << "CPF já, existente!\n\n";
                
                return false;

            }
        }


    return true;
}


void register_user(StartUsers *List){

        if(new_user(List)){
            cout << "\n\nUsuário cadastrado com sucesso!\n\n";
            List->Uquant++;

        } else{
            cout << "Não foi possivel fazer o cadastro, tente novamente\n\n";

        } 

}


void show_users(User *List){ //função recursiva que mostra os usuarios da lista
cout << "\n===============================================================================================\n";
    cout << "Nome: " << List->name << "\n";
    cout << "CPF: " << List->CPF << "\n";
    
    if(List->Adm) cout << "Adminstrador ★\n";

    if(!List->next) return;
    else show_users(List->next);

}


bool check_cpf(User *Fuser, long int CPF){ // função recursiva que percorre a lista para verificar os CPFs dos usuários

    bool check;

    if(!Fuser){
        return false;

    } 

    if(Fuser->CPF == CPF) return true;
    else check = check_cpf(Fuser->next, CPF);


    return check;

} // com problema, depois que um cpf igual é encontrado, o cadastro buga 


//(----------------------------Login--------------------------------------------)

void login(StartUsers *List){
    long int cpf_log;
    string name_log;
    string password_log;
    User *Ulog = NULL;

    //cout << "Endereço List: " << List << endl;
    cout << "CPF: ";
    cin >> cpf_log;

    Ulog = check_log(List->head, cpf_log);
    

    if(!Ulog){
        cout << "\nCpf não cadastrado\n\n";
        return ;

    }



    cout << "Nome de Usuário: ";
    cin >> name_log;

    cout << "Senha: ";
    cin >> password_log;


    if(Ulog->name == name_log && Ulog->password == password_log){
        cout << "\n\nLogin feito com sucesso!\n\n\n";

        if(Ulog->Adm) user_menu_adm(List, Ulog);
        else user_menu(List, Ulog);
        

        return ;

    } 

    if(Ulog->name != name_log && Ulog->password != password_log){
        cout << "\n\nNome e senha incorretos!\n\n";
        return ;
    }

    if(Ulog->name != name_log && Ulog->password == password_log){
        cout << "\n\nNome Incorreto!\n\n";
        return ;
    }

    if(Ulog->name == name_log && Ulog->password != password_log){
        cout << "\n\nSenha Incorreta!\n\n";
        return ;
    }

}


User *check_log(User *u, long int CPF){ 
    
    if(!u) return u;

    if(u->CPF == CPF) return u;

    u = check_log(u->next, CPF);
    return u;
}


void remove_user(StartUsers *List, long int CPF){ 

    User *remove, *aux;

    aux = NULL;
    remove = NULL;


        if(List->head->CPF == CPF){
            remove = List->head;
            List->head = remove->next;

            cout << "Usuário " << remove->name << " Removido\n\n";

        } else {
            aux = List->head;

            while(aux->next->CPF != CPF){
                aux = aux->next;
            }

            remove = aux->next;
            aux->next = remove->next;

            cout << "Usuário " << remove->name << " Removido\n\n";

        }

    delete_user(remove);
        
}