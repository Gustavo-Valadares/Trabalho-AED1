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



//tem algum caralho de bug na hora de cadastrar um evento que eu não tenho a mínima ideia de como resolve
    //problema não é no recebimento de strings
    //resolvido
    //o problema era em recebimento de string




//criar a lógica da criação da lista de ingressos
    //qual vai ser o caso para saber se a lista de ingressos está vazia?
    //gerar id para cada evento usando rand e srand
    

//é preciso fazer a lista de eventos antes de fazer a de ingressos
    //verificar funcionamento de lista de eventos
    //1. adicionar, printar, excluir, printar, adicionar, printar (funcionando)
    //2. adicionar 1, printar, adicionar 2, printar, excluir 1, printar (duncuinando)
    //3. adicionar 1, printar, adicionar 2, printar, excluir 2, printar (funcionando)


//por enquanto é melhor fazer uma limitação de 5 eventos e 5 ingressos, depois otimizo
       

    // bool add_ticket
    // void remove ticket 
        // void delete_ticket




        // void new_node_e();
            // ainda há um erro depois da exclusão e adição de um evento (user scanf para receber string ver se resolve)            


        // na hora de dar free em uma conta verificar se o usuário tem ingressos ou eventos, desalocar as respectivas memórias
            //ainda há bugs na hora 


    // compr de ingresso 
        //fazer buscar por nome, copiar as informações do ingresso para o slot de ingressos do usuário e descontar o crédito