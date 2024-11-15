#include <iostream>
#include "users.hpp"
#include "menus.hpp"
#include "events.hpp"



using namespace std;

int main(){
    StartUsers *UserList = NULL;
    UserList = create_list();
    
    start_menu(UserList);


    return 0;
}



// void remove ticket  tad de devolução
    // void delete_ticket



//Erro ao excluir ingresso
    //adicionei dois ingressos com o mesmo nome, exclui e deu erro
    //solução: criar uma busca de ingressos para usar o nome do evento como chave e impedir o usuário adm de criar este evento
         


// na hora de dar free em uma conta verificar se o usuário tem ingressos ou eventos, desalocar as respectivas memórias
    //ainda há bugs na hora 
    //mensagem "você ainda tem ingressos nessa conta, seus ingressos serão perdidos"


 
//salvar informações de login, ingresso e eventos em um arquivo



//--------------------------------------Resolvido--------------------------------------

//Erro na hora de fazer a compra de um ingresso
    //tad insert_ticket
    //mudou o problema, progredimos 


//por enquanto é melhor fazer uma limitação de 5 eventos e 5 ingressos, depois otimizo
    //por enquanto cada usuário só poderá ter um ingresso de cada evento, mas pretendo fazer para que tenha mais de um


    // void show_all events
    // void remove event
        // void delete event


// compra de ingresso 
    //fazer buscar por nome, copiar as informações do ingresso para o slot de ingressos do usuário e descontar o crédito


//é preciso fazer a lista de eventos antes de fazer a de ingressos
    //verificar funcionamento de lista de eventos
    //1. adicionar, printar, excluir, printar, adicionar, printar
    //2. adicionar 1, printar, adicionar 2, printar, excluir 1, printar
    //3. adicionar 1, printar, adicionar 2, printar, excluir 2, printar


//criar a lógica da criação da lista de ingressos
    //qual vai ser o caso para saber se a lista de ingressos está vazia?