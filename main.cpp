#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <clocale>
#include <random>
#include <string>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

struct Pizza {
    int id = 0;
    string sabor;
    float preco = 0;
};
struct Borda {
    int id = 0;
    string sabor;
    float preco = 0;
};
struct Bebida {
    int id = 0;
    string sabor;
    float preco = 0;
};
struct Pedido {
    char descricao[256];
    Pizza pizza;
    Borda borda;
    Bebida bebida;
};

const int N = 5;
int fim = -1, aux = 0;

char conf;
char *descricao;

bool sinal = false;

Pizza pizza;
Borda borda;
Bebida bebida;
Pedido pedido;

Pedido listaPedidos [N];

Pizza cardapioPizzas [N] = {{12, "Calabresa", 49},
                    {30, "Frango", 45},
                    {25, "Peperoni", 38},
                    {16, "Marguerita", 44} };

Borda cardapioBordas [N] = {{14, "Catupiry", 8},
                    {15, "Chocolate", 10},
                    {16, "Cheddar", 12}};

Bebida cardapioBebidas [N] = {{1, "Coca", 12},
                        {2, "Fanta", 9},
                        {3, "Guarana", 12}};

void inserirPedidoNoFim(); // inserir no final da lista
void listarTodosPedidos(); //imprimir a lista de pedidos
void calcMediaPedidos(); //calcula media dos pedidos
void inserirPedidoKAnterior();//insere no K anterior
void ConsultarNomeERemoverAnterior();
void AlterarPedidoK();
void ConsultarPosicaoK();
void ImprimirPedidosPares();
void ProcuraPedidoEAlteraDados();
void OrdemCrescentePorSabor();
char* toUpperCase(char texto[256]);

int main (){
    setlocale(LC_ALL, "pt-br");

    int op = -1;
    while (op != 0) {
        cout << "\nPrograma Gerenciar Pedidos de Pizzas";
        cout << "\n0 - Sair";
        cout << "\n1 - Imprimir a lista";
        cout << "\n2 - Inserir Novo Pedido no Fim da Lista";
        cout << "\n3 - Calculo da Media dos Pedidos";
        cout << "\n4 - Inserir Na Posicao K-1";
        //cout << "\n5 - Consultar Por Descricao e Remover o Anterior (PENDENTE)";
        //cout << "\n6 - Alterar Posicao K (PENDENTE)";
        //cout << "\n7 - Consultar Posicao K (PENDENTE)";
        //cout << "\n8 - Imprimir Posicoes Pares (PENDENTE)";
        //cout << "\n9 - Procurar Posicao E Alterar Dados (PENDENTE)";
        //cout << "\n10 - Classificar em Ordem Crescente Por Sabor (PENDENTE)";
        //cout << "\nEscolha uma opcao: ";
        fflush (stdin);
        std::cout << endl;
        std::cin >> op;
        switch (op){
            case 0: {cout << "\nFinalizado"; break;}
            case 1: {listarTodosPedidos(); break;}
            case 2: {inserirPedidoNoFim(); break;}
            case 3: {calcMediaPedidos(); break;}
            case 4: {inserirPedidoKAnterior(); break;}
            default: {cout << "\nOpcao Invalida..."; break;}
        }
        std::cout << endl;
    }
}
void ConsultarNomeERemoverAnterior() {
        sinal = false;
        string filtro;
    if(fim+1 != N) {
        std::cout << "Informe a descricao do pedido que deseja alterar: " << endl;
        cin >> filtro;
        if(filtro == pedido.descricao) {

        }
    }
}

void inserirPedidoKAnterior() {
    sinal = false;

    if (fim + 1 != N) {
        std::cout << "Informe a posicao que sera alterada" << endl;
        int K = (rand()%4)+1;
        if(K!=N) {
            if (K >= 0 and K <= fim) {
                std::cout << "Dê uma descrição para o pedido" << endl;
                std::cin >> descricao;
                toUpperCase(descricao);
                pedido.descricao = descricao ;
                std::cout << pedido.descricao << endl;
                pedido.pizza = cardapioPizzas[rand()%3+1];
                std::cout << pedido.pizza.sabor << endl;
                pedido.borda = cardapioBordas[rand()%2+1];
                std::cout << pedido.borda.sabor << endl;
                pedido.bebida = cardapioBebidas[rand()%2+1];
                std::cout << pedido.bebida.sabor << endl;

                std::cout << "Confirma Esses Dados? (S/N)" << endl;
                std::cin >> conf;
                conf = toupper(conf);

                if(conf == 'S') {
                    fim = fim + 1;
                    aux = fim;
                    while (aux != K-1) {
                        listaPedidos[aux] = listaPedidos[aux-1];
                        aux = aux-1;
                    }
                    listaPedidos[K] = pedido;
                    sinal = true;
                    std::cout << "Operacao realizada com sucesso";
                } else {
                    std::cout << "Dados Não Inseridos";
                }

            }else {
                std::cout << "Posicao Fora da Lista Ou Lista Vazia";
            }
        }
    } else {
        std::cout << "Lista Cheia";
    }

}
void inserirPedidoNoFim(){
    sinal = false;
    cout << "\nInserir Novo Pedido no Fim da Lista";

    if ((fim+1) < N) {
        std::cout << "Dê uma descrição para o pedido" << endl;
        std::cin >> pedido.descricao;
        toUpperCase(pedido.descricao);
        cout << "Informe a pizza (1-Calabresa,2-Frango,3-Peperoni,4-Marguerita)" << endl;
        pedido.pizza = cardapioPizzas[rand()%3+1];
        std::cout << "Sabor " << pedido.pizza.sabor << " inserido" << endl;
        cout << "Informe a borda (1-Catupiry, 2-Chocolate, 3-Cheddar)" << endl;
        pedido.borda = cardapioBordas[rand()%2+1];
        std::cout << "Borda " << pedido.borda.sabor << " inserido" << endl;
        cout << "Informe a bebida (1-Coca, 2-Fanta, 3-Guarana)" << endl;
        pedido.bebida = cardapioBebidas[rand()%2+1];
        std::cout << "Bebida " << pedido.bebida.sabor << " inserido" << endl;

        cout << "Confirma (S/N): ";
        std::cin >> conf;
        conf = toupper(conf);

        if (conf == 'S'){
            fim = fim + 1;
            listaPedidos[fim] = pedido;
            sinal = true;
        }
        else cout << "\nDados nao inseridos";
    }
    else cout << "\nLista Cheia";
}

void listarTodosPedidos() {
    sinal = false;
    cout << "\nListagem de Pessoas";
    if (fim > -1){
        aux = 0;
        cout << "\n"<< setw(15)  << "Descricao"
                    << setw(15)  << "Pizza"
                    << setw(15) << "Borda"
                    << setw(15)  << "Bebida";
        while (aux<=fim){
            pedido = listaPedidos[aux];
            cout << "\n"<< setw(15)  << pedido.descricao
                        << setw(15)  << pedido.pizza.sabor
                        << setw(15) << pedido.borda.sabor
                        << setw(15)  << pedido.bebida.sabor;
            aux++;
        }
        sinal = true;
    }
    else cout << "\nLista de Pessoas esta vazia...";
}

void calcMediaPedidos(){
    int somaValorPedido = 0;
    float mediaPedidos = 0;
    cout << "\nCalculo da Media de Idade";
    sinal = false;
    if (fim > -1){
        aux = 0;
        while (aux <= fim){
            somaValorPedido = somaValorPedido + listaPedidos[aux].pizza.preco + listaPedidos[aux].borda.preco + listaPedidos[aux].bebida.preco;
            aux = aux + 1;
        }
        mediaPedidos = (float) somaValorPedido / aux;
        cout << "\nMedia do valor dos pedidos: " << fixed << setprecision(2) << mediaPedidos;
        sinal = true;
    }
    else cout << "\nLista Vazia...";
}

char* toUpperCase(char texto[256]){
        cout << "Original String:\n"<< texto << endl;
        cout<<"String in UPPERCASE:\n";
        for (int x=0; x<strlen(texto); x++)
            putchar(toupper(texto[x]));
        cout << texto;
}