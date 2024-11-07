#include <iostream>
#include <string>
#include <iomanip> //usado pra setar a precisão do número double
#include "users.hpp"
#include "menus.hpp"
#include "events.hpp"
#include "tickets.hpp"


using namespace std;

void start_menu(StartUsers *UserList){
    int command = 0;


    while(1){
        
        if(command == 4) break;
        
        cout << "1. Login\n";
        cout << "2. Cadastro\n";
        cout << "3. Mostrar Usuários\n";
        cout << "4. Encerrar\n";

        cout << endl;
        cin >> command;

        switch(command){
            case 1:
                if(!UserList->head){
                    cout << "\nNão há contas cadastradas\n\n\n";
                } 

            else
                login(UserList);

                break;

            case 2:
                register_user(UserList);

                break;

            case 3:

                if(!UserList->head){
                    cout << "\nNão há usuários cadastrados\n";

                } else {
                    show_users(UserList->head);
                    cout << "\nHá um total de " << UserList->Uquant << " usuários cadastrados\n\n";

                }

                break;

            case 4:
                break;

            default:
                printf("Comando Inválido\n");
                
                break;
                
        }
    }

}

void user_menu_adm(StartUsers *List, User *u){

    string password_check;
    string del_ename;
    
    cout << "Bem vindo " << u->name << " ★ !\n\n";

    int command = 0;


    while(1){
        

        if(command == 4 || command == 5) break;

        cout << "1. Meus Eventos\n";
        cout << "2. Cadastrar Evento (+/-)\n";
        cout << "3. Excluir Evento\n";
        cout << "4. Excluir Conta\n";
        cout << "5. Menu Principal\n";

        cout << endl;
        cin >> command;


        switch(command){
            case 1:

                if(show_user_events(u->e_List->head)){
                    cout << "\n\nHá " << u->e_List->e_quant << " Eventos Cadastrados\n\n"; 

                }

                else cout << "Você não tem eventos cadastrados\n\n";
                
            break;


            case 2:

                if(u->e_List->e_quant > 5){
                    cout << "Você só pode cadastrar 5 eventos por vez!!\n\n";

                } else {
                    register_events(u->e_List);
                    u->e_List->e_quant++;

                }

            break;


            case 3:


                cout << "Senha: ";
                getchar();
                getline(cin, password_check);

                cout << endl;

                if(password_check == u->password){
                    show_user_events(u->e_List->head);

                    cout << "\n";
                    cout << "Digite o nome do evento que deseja excluir: ";
                    getline(cin, del_ename);
                    cout << endl;

                    remove_user_event(u->e_List, del_ename);
                    u->e_List->e_quant--;

                } 

                else cout << "Senha Incorreta\n";
                

            break;


            case 4:

                //mensagem "de tem certeza?"
                cout << "Senha: ";
                getchar();
                getline(cin, password_check);

                if(password_check == u->password){
                    remove_user(List, u->CPF);
                    List->Uquant--;

                    cout << "Conta Excluida\n";
                    return ;
                }

                else cout << "Senha Incorreta\n";

            break;


            default:

            break;

        }

    }
}


void user_menu(StartUsers *List, User *u){ //não adminstrador

    string find_tname;
    string straux;
    string password_check;
    
    cout << "Bem Vindo " << u->name << "!\n";

    int command = 0;

    
     while(command != 6){

        cout << endl;
        cout << "=====================================================================\n";
        cout << "Nome: " << u->name << "\t\t\t";
        cout << "CPF: " << u->CPF << "\t\t\t";
        cout << "Saldo: R$" << setprecision(2) << fixed << u->cred << endl;
        cout << "=====================================================================\n";
        
        if(u->Adm) cout << "Adminstrador ★\n\n";


        cout << "1. Eventos\n";
        cout << "2. Comprar Ingresso(Incompleto)\n";
        cout << "3. Meus Ingressos (Em obras)\n";
        cout << "4. Adicionar Crédito\n";
        cout << "5. Excluir Conta\n";
        cout << "6. Menu Principal\n";

        cout << endl;
        cin >> command;

        switch(command){
            case 1:
                //Olhar eventos (criar menu) 
                show_all_events(List);
                
                //mandar o UserList
                    //entrar na memoria dos usuário
                        //checar quem é adm e imprimir os eventos desse adm

                //compra de ingressos
            break;


            case 2:

                show_all_events(List);

                if(check_events(List)){

                    cout << "\n\nDigite o nome do Evento que deseja comprar: "; 
                    cin >> straux;
                    cout << straux << endl;
                    find_event(List, straux);
                    
                    cout << "\n\nIngresso comprado\n\n";

                }

                //função para encontrar ingresso
                cout << "Erro4\n";

                        //ao achar, criar ingresso e colocar informações
                        //
                    //verificar se o usuário tem dinheiro para efetuar a compra              

            break;

            case 3:

                if(u->t_List->t_quant == 0){
                    cout << "Você não possui ingressos\n";
                    break;
                }

                show_user_tickets(u->t_List->head);
                //mostrar ingressos, enviar u
                //mostrar ingresso dos usuários


            break;

            case 4:
                credit_menu(u);

            break;


            case 5:

                //mensagem "de tem certeza?"
                cout << "Senha: ";
                getchar();
                getline(cin, password_check);

                if(password_check == u->password){
                    //cout << "Ponteiro do primeiro da lisa" << &(List->head);
                    //remove_user(&(List->head), u, aux);
                    remove_user(List, u->CPF);
                    List->Uquant--;
                    command = 5;

                    cout << "\nConta Excluida :( \n\n\n";
                    return ;
                    
                } 
                    else cout << "Senha Incorreta\n";

            break;


            case 6:
                //volta para o menu
            break;

            default:

            break;
        }



    }
}

void credit_menu(User *u){
    double cred;
    long int num_card;
    int cvv;
    string date;
    string name_card;
    
        cout << "Quanto deseja colocar?\nR$ ";
        cin >> cred;
        
        cout << "\n\nInformações do Cartão: \n\n";

        cout << "Número do Cartão: ";
        for(int i = 0; i < 4; i++) cin >> num_card;

        cout << "Nome: ";
        getchar();
        getline(cin, name_card);

        cout << "Validade: ";
        getline(cin, date);

        cout << "cvv: ";
        cin >> cvv;
        cout << endl;

        u->cred += cred; 

        cout << "Crédito adicionado! cheque sua conta\n\n\n";
}