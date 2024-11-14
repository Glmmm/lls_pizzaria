#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <clocale>
#include <random>
#include <string>
#include <clocale>
#include <cstring>

using namespace std;

// EX 1
struct Pizza
{
    int id = 0;
    string sabor;
    float preco = 0;
};

struct Borda
{
    int id = 0;
    string sabor;
    float preco = 0;
};

struct Bebida
{
    int id = 0;
    string sabor;
    float preco = 0;
};

struct Pedido
{
    int id = 0;
    char descricao[30] = "";
    Pizza pizza;
    Borda borda;
    Bebida bebida;
};

constexpr int N = 5;
int fim = -1, aux = 0;
int id;
char conf;
char filtro[30];
bool sinal = false;

Pizza pizza;
Borda borda;
Bebida bebida;
Pedido pedido;
Pedido listaPedidos[N];
Pizza cardapioPizzas[N] = {
    {12, "Calabresa", 49},
    {30, "Frango", 45},
    {25, "Peperoni", 38},
    {16, "Marguerita", 44}};
Borda cardapioBordas[N] = {
    {14, "Catupiry", 8},
    {15, "Chocolate", 10},
    {16, "Cheddar", 12}};
Bebida cardapioBebidas[N] = {
    {1, "Coca", 12},
    {2, "Fanta", 9},
    {3, "Guarana", 12}};

bool compararPorNome(const Pedido &p1, const Pedido &p2)
{
    return strcmp(p1.descricao, p2.descricao) < 0;
}

void inserirPedidoNoFim();

void listarTodosPedidos();

// EX 9
void calcMediaPedidos();

// EX 2
void inserirPedidoKAnterior();

// EX 3
void ConsultarNomeERemoverAnterior();

// EX 4
void ProcurarPedidoAlterarPedidoPosicaoK();

// EX 5
void ConsultarPedidoPosicaoK();

// EX 6
void ImprimirPedidosPares();

// EX 8
void OrdemCrescentePorSabor();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int op = -1;
    while (op != 0)
    {
        cout << "\nPrograma Gerenciar Pedidos de Pizzas";
        cout << "\n0 - Sair";
        cout << "\n1 - Imprimir a lista";
        cout << "\n2 - Inserir Novo Pedido no Fim da Lista";
        cout << "\n3 - Calculo da Media dos Pedidos";
        cout << "\n4 - Inserir Na Posicao K-1";
        cout << "\n5 - Consultar Por Descricao e Remover o Anterior";
        cout << "\n6 - Alterar Posicao K";
        cout << "\n7 - Consultar Posicao K";
        cout << "\n8 - Imprimir Posicoes Pares";
        cout << "\n9 - Procurar Posicao E Alterar Dados ";
        cout << "\n10 - Classificar em Ordem Crescente Por Sabor";
        fflush(stdin);
        std::cout << endl;
        op = -1;
        std::cin >> op;
        switch (op)
        {
        case 0:
        {
            cout << "\nFinalizado";
            break;
        }
        case 1:
        {
            listarTodosPedidos();
            break;
        }
        case 2:
        {
            inserirPedidoNoFim();
            break;
        }
        case 3:
        {
            calcMediaPedidos();
            break;
        }
        case 4:
        {
            inserirPedidoKAnterior();
            break;
        }
        case 5:
        {
            ConsultarNomeERemoverAnterior();
            break;
        }
        case 6:
        {
            ProcurarPedidoAlterarPedidoPosicaoK();
            break;
        }
        case 7:
        {
            ConsultarPedidoPosicaoK();
            break;
        }
        case 8:
        {
            ImprimirPedidosPares();
            break;
        }
        case 9:
        {
            ProcurarPedidoAlterarPedidoPosicaoK();
            break;
        }
        case 10:
        {
            OrdemCrescentePorSabor();
            break;
        }
        default:
        {
            cout << "\nOpcao Invalida...";
            break;
        }
        }
    }
    std::cout << endl;
}

void listarTodosPedidos()
{
    if (fim > -1)
    {
        aux = 0;
        cout << "\n"
             << setw(15) << "ID"
             << setw(15) << "Nome"
             << setw(15) << "Pizza"
             << setw(15) << "Borda"
             << setw(15) << "Bebida";
        while (aux <= fim)
        {
            pedido = listaPedidos[aux];
            cout << "\n"
                 << setw(15) << pedido.id
                 << setw(15) << pedido.descricao
                 << setw(15) << pedido.pizza.sabor
                 << setw(15) << pedido.borda.sabor
                 << setw(15) << pedido.bebida.sabor;
            aux++;
        }
    }
    else
        cout << "\nLista de Pedidos esta vazia...";
}

void inserirPedidoNoFim()
{
    sinal = false;
    cout << "\nInserir Novo Pedido no Fim da Lista" << endl;

    if ((fim + 1) < N)
    {
        std::cout << "Insira o numero do pedido" << endl;
        id++;
        pedido.id = id;
        std::cout << pedido.id << endl;
        std::cout << "Insira o nome do cliente" << endl;
        std::cin >> pedido.descricao;
        std::cout << pedido.descricao << endl;
        pedido.pizza = cardapioPizzas[rand() % 3 + 1];
        std::cout << pedido.pizza.sabor << " inserido" << endl;
        pedido.borda = cardapioBordas[rand() % 2 + 1];
        std::cout << pedido.borda.sabor << " inserido" << endl;
        pedido.bebida = cardapioBebidas[rand() % 2 + 1];
        std::cout << pedido.bebida.sabor << " inserido" << endl;
        cout << "Confirma (S/N): ";
        std::cin >> conf;
        conf = toupper(conf);
        if (conf == 'S')
        {
            fim = fim + 1;
            listaPedidos[fim] = pedido;
            sinal = true;
        }
        else
        {
            cout << "\nDados nao inseridos";
            id--;
        }
    }
    else
        cout << "\nLista Cheia";
}

void calcMediaPedidos()
{
    int somaValorPedido = 0;
    float mediaPedidos = 0;
    cout << "\nCalculo da Media de Idade";
    sinal = false;
    if (fim > -1)
    {
        aux = 0;
        while (aux <= fim)
        {
            somaValorPedido = somaValorPedido + listaPedidos[aux].pizza.preco + listaPedidos[aux].borda.preco +
                              listaPedidos[aux].bebida.preco;
            aux = aux + 1;
        }
        mediaPedidos = (float)somaValorPedido / aux;
        cout << "\nMedia do valor dos pedidos: " << fixed << setprecision(2) << mediaPedidos;
        sinal = true;
    }
    else
        cout << "\nLista Vazia...";
}

void inserirPedidoKAnterior()
{
    if (fim + 1 != N)
    {
        std::cout << "Informe a posicao que sera alterada" << endl;
        int K = (rand() % 4) + 1;
        if (K != N)
        {
            if (K >= 0 && K <= fim)
            {
                std::cout << "Insira o numero do pedido" << endl;
                id++;
                pedido.id = id;
                std::cout << pedido.id << endl;
                std::cout << "Insira o nome do cliente" << endl;
                std::cin >> pedido.descricao;
                std::cout << pedido.descricao << endl;
                pedido.pizza = cardapioPizzas[rand() % 3 + 1];
                std::cout << pedido.pizza.sabor << " inserido" << endl;
                pedido.borda = cardapioBordas[rand() % 2 + 1];
                std::cout << pedido.borda.sabor << " inserido" << endl;
                pedido.bebida = cardapioBebidas[rand() % 2 + 1];
                std::cout << pedido.bebida.sabor << " inserido" << endl;
                std::cout << "Confirma Esses Dados? (S/N)" << endl;
                std::cin >> conf;
                conf = toupper(conf);
                if (conf == 'S')
                {
                    fim = fim + 1;
                    aux = fim;
                    while (aux != K - 1)
                    {
                        listaPedidos[aux] = listaPedidos[aux - 1];
                        aux = aux - 1;
                    }
                    listaPedidos[K] = pedido;
                    std::cout << "Operacao realizada com sucesso";
                }
                else
                {
                    std::cout << "Dados Não Inseridos";
                    id--;
                }
            }
            else
            {
                std::cout << "Posicao Fora da Lista Ou Lista Vazia";
            }
        }
    }
    else
    {
        std::cout << "Lista Cheia";
    }
}

void ConsultarNomeERemoverAnterior()
{
    if (fim > 0)
    {
        std::cout << "Informe a descricao do cliente: " << endl;
        cin >> filtro;
        aux = 0;
        while (aux <= fim)
        {
            if (string(filtro) == string(listaPedidos[aux].descricao))
            {
                if (aux > 0)
                {
                    std::cout << "Pedido encontrado, excluir anterior? (S/N)" << endl;
                    std::cin >> conf;
                    conf = toupper(conf);
                    if (conf == 'S')
                    {
                        while (aux <= fim)
                        {
                            listaPedidos[aux - 1] = listaPedidos[aux];
                            aux = aux + 1;
                        }
                        fim = fim - 1;
                        std::cout << "Ação confirmada";
                    }
                    else
                    {
                        std::cout << "Dados não confirmados" << endl;
                        aux = fim + 1;
                    }
                }
                else
                {
                    cout << "Foi encontrado, mas está na primeira posição" << endl;
                    aux = fim + 1;
                }
            }
            else
            {
                aux = aux + 1;
            }
        }
    }
    else
    {
        std::cout << "Lista tem menos de 2 elementos" << endl;
    }
}

void ProcurarPedidoAlterarPedidoPosicaoK()
{
    if (fim + 1 != N)
    {
        std::cout << "Informe a posicao que deseja alterar: " << endl;
        int K;
        cin >> K;
        aux = 0;
        if (K > 0 && K <= fim)
        {
            while (aux <= fim)
            {
                if (aux == K)
                {
                    std::cout << "Insira o numero do pedido" << endl;
                    id++;
                    pedido.id = id;
                    std::cout << pedido.id << endl;
                    std::cout << "Insira o nome do cliente" << endl;
                    std::cin >> pedido.descricao;
                    std::cout << pedido.descricao << endl;
                    pedido.pizza = cardapioPizzas[rand() % 3 + 1];
                    std::cout << pedido.pizza.sabor << " inserido" << endl;
                    pedido.borda = cardapioBordas[rand() % 2 + 1];
                    std::cout << pedido.borda.sabor << " inserido" << endl;
                    pedido.bebida = cardapioBebidas[rand() % 2 + 1];
                    std::cout << pedido.bebida.sabor << " inserido" << endl;
                    std::cout << "Confirma os dados?" << endl;
                    std::cin >> conf;
                    conf = toupper(conf);
                    if (conf == 'S')
                    {
                        listaPedidos[aux] = pedido;
                        aux = fim;
                    }
                }
                aux++;
            }
        }
        else
            std::cout << "Fora da lista";
    }
    else
        cout << "Lista cheia";
}

void ConsultarPedidoPosicaoK()
{
    int K;
    if (fim != -1)
    {
        std::cout << "Informe a posicao que deseja consultar: " << endl;
        cin >> K;
        aux = 0;
        if (K >= 0 && K <= fim)
        {
            while (aux <= fim)
            {
                if (aux == K)
                {
                    pedido = listaPedidos[aux];
                    cout << "\n"
                         << setw(15) << "ID"
                         << setw(15) << "Nome"
                         << setw(15) << "Pizza"
                         << setw(15) << "Borda"
                         << setw(15) << "Bebida";
                    cout << "\n"
                         << setw(15) << pedido.id
                         << setw(15) << pedido.descricao
                         << setw(15) << pedido.pizza.sabor
                         << setw(15) << pedido.borda.sabor
                         << setw(15) << pedido.bebida.sabor;
                    aux = fim;
                }
                aux++;
            }
        }
        else
            std::cout << "Fora da lista";
    }
    else
        cout << "Lista vazia";
}

void ImprimirPedidosPares()
{
    if (fim > -1)
    {
        aux = 0;
        cout << "\n"
             << setw(15) << "ID"
             << setw(15) << "Nome"
             << setw(15) << "Pizza"
             << setw(15) << "Borda"
             << setw(15) << "Bebida";
        while (aux <= fim)
        {
            if (aux % 2 == 0)
            {
                pedido = listaPedidos[aux];
                cout << "\n"
                     << setw(15) << pedido.id
                     << setw(15) << pedido.descricao
                     << setw(15) << pedido.pizza.sabor
                     << setw(15) << pedido.borda.sabor
                     << setw(15) << pedido.bebida.sabor;
            }
            aux++;
        }
    }
    else
        cout << "\nLista de Pedidos esta vazia...";
}

void OrdemCrescentePorSabor()
{
    if (fim > 0)
    {
        for (int i = 0; i < fim; i++)
        {
            for (int j = i + 1; j <= fim; j++)
            {
                if (strlen(listaPedidos[i].descricao) > strlen(listaPedidos[j].descricao))
                {
                    Pedido aux = listaPedidos[i];
                    listaPedidos[i] = listaPedidos[j];
                    listaPedidos[j] = aux;
                }
            }
        }
    }
    else
    {
        std::cout << "Lista só tem 1 elemento";
    }
}
