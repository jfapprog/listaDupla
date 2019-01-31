/* 
 ** UC: 21046-Estrutura de Dados e Algoritmos Fundamentais
 ** e-fólio A 2015-16 (gdlli.cpp)
 **
 ** Aluno: 1301913 - José Póvoa
 */

#include <iostream>
#include "ListaDupla.h"
using namespace std;

ListaDupla::ListaDupla()
{
    primeiro = ultimo = 0;
    //para testes
    //cout << "Lista construida!" << endl;
}

ListaDupla::~ListaDupla()
{
    NoDuplo* auxiliar = 0;
    //enquanto a lista não é vazia apagar o primeiro elemento
    //o primeiro passa a ser o seguinte
    while (!Vazia())
    {
        auxiliar = primeiro;
        primeiro = primeiro->seguinte;
        delete auxiliar;
    }
    //para testes
    //cout << "Lista destruida!" << endl;
}

bool ListaDupla::Vazia() const
{
    //se o apontador para o primeiro elemento é nulo, então a lista está vazia
    return primeiro == 0;
}

void ListaDupla::Esvaziar()
{
    while (RemoverDoInicio());
}

void ListaDupla::AdicionarNoInicio(unsigned int elem)
{
    //se a lista está vazia o elemento a adicionar
    //passa a ser o primeiro e o último
    if (Vazia())
        ultimo = primeiro = new NoDuplo(elem);
        //se não está vazia,
        //o anterior ao primeiro passa a ser o elemento a adicionar
        //e depois esse passa a ser o primeiro
    else
    {
        primeiro->anterior = new NoDuplo(elem, primeiro);
        primeiro = primeiro->anterior;
    }
}

void ListaDupla::AdicionarNoFim(unsigned int elem)
{
    //se a lista está vazia o elemento a adicionar
    //passa a ser o primeiro e o último
    if (Vazia())
        ultimo = primeiro = new NoDuplo(elem);
        //se não está vazia,
        //o seguinte ao último passa a ser o elemento a adicionar
        //e depois esse passa a ser o último 
    else
    {
        ultimo->seguinte = new NoDuplo(elem, 0, ultimo);
        ultimo = ultimo->seguinte;
    }
}

void ListaDupla::InserirNoIndice(unsigned int indice, unsigned int elem)
{
    //se é zero inserir nó no início
    if (indice == 0)
    {
        AdicionarNoInicio(elem);
        return;
    }
    //se não, percorrer a lista até ao elemento no indice de inserção
    NoDuplo* atual = primeiro;
    while (atual != 0 && indice > 0)
    {
        atual = atual->seguinte;
        indice--;
    }
    //se percorreu totalmente a lista o novo nó é inserido no fim
    if (atual == 0)
        AdicionarNoFim(elem);
        //se não, o seu anterior passa a ter como seguinte o novo nó
        //o novo nó tem como seguinte o atual e como anterior, o anterior ao atual
        //o anterior do atual passa a ser o novo
    else
    {
        atual->anterior->seguinte = new NoDuplo(elem, atual, atual->anterior);
        atual->anterior = atual->anterior->seguinte;
    }
}

bool ListaDupla::RemoverDoInicio()
{
    if (Vazia())
        return false;
    NoDuplo* auxiliar = primeiro;
    //se a lista não está vazia
    //se apenas tem um elemento, o primeiro e o último passam a ser nulos
    if (primeiro == ultimo)
        primeiro = ultimo = 0;
        //se tem mais do que um elemento
        //o primeiro passa a ser o seu seguinte
    else
    {
        primeiro = primeiro->seguinte;
        primeiro->anterior = 0;
    }
    delete auxiliar;
    return true;
}

bool ListaDupla::RemoverDoFim()
{
    if (Vazia())
        return false;
    NoDuplo* auxiliar = ultimo;
    //se a lista não está vazia
    //se apenas tem um elemento, o primeiro e o último passam a ser nulos
    if (primeiro == ultimo)
        primeiro = ultimo = 0;
        //se tem mais do que um elemento
        //o último passa a ser o seu anterior
    else
    {
        ultimo = ultimo->anterior;
        ultimo->seguinte = 0;
    }
    delete auxiliar;
    return true;
}

int ListaDupla::RemoverElemento(unsigned int elem)
{
    if (Vazia())
        return -1;
    //se é igual ao primeiro elemento, chama o método removerDoInicio()
    if (elem == primeiro->elemento)
    {
        RemoverDoInicio();
        return 0;
    }
    //se não
    int indice = 0;
    NoDuplo* atual = primeiro;
    //procura o primeiro elemento igual
    while (atual != 0 && (atual->elemento != elem))
    {
        atual = atual->seguinte;
        indice++;
    }
    //se não encontra retorna -1
    if (atual == 0)
        return -1;
    //se encontra, eliminar atual
    //mudar o seguinte do anterior para o seguinte do atual
    atual->anterior->seguinte = atual->seguinte;
    //se atual é último, mudar último para o seu anterior
    if (atual == ultimo)
        ultimo = atual->anterior;
        //se não, mudar o anterior do seguinte para o anterior do atual
    else
        atual->seguinte->anterior = atual->anterior;
    //apagar atual
    delete atual;
    return indice;
}

unsigned int ListaDupla::NumeroElementos() const
{
    if (Vazia())
        return 0;
    unsigned int contador = 0;
    NoDuplo* atual = primeiro;
    //percorrer a lista para contar elementos
    while (atual != 0)
    {
        atual = atual->seguinte;
        contador++;
    }
    return contador;
}

int ListaDupla::ElementoDoInicio() const
{
    if (Vazia())
        return -1;
    return primeiro->elemento;
}

int ListaDupla::ElementoDoFim() const
{
    if (Vazia())
        return -1;
    return ultimo->elemento;
}

int ListaDupla::ElementoMaximo() const
{
    if (Vazia())
        return -1;
    unsigned int maximo = primeiro->elemento;
    NoDuplo* atual = primeiro->seguinte;
    //percorrer a lista e atualizar máximo
    while (atual != 0)
    {
        if (atual->elemento > maximo)
            maximo = atual->elemento;
        atual = atual->seguinte;
    }
    return (int) maximo;
}

int ListaDupla::ProcurarElemento(unsigned int elem) const
{
    int indice = 0;
    NoDuplo* atual = primeiro;
    //percorrer a lista até encontrar igual e atualizar índice
    while (atual != 0 && (atual->elemento != elem))
    {
        atual = atual->seguinte;
        indice++;
    }
    //se percorreu até ao final é porque não encontrou e retorna -1
    if (atual == 0)
        return -1;
    //se não, retorna o índice
    return indice;
}

void ListaDupla::Mostrar() const
{
    if (Vazia())
    {
        cout << '*' << endl;
        return;
    }
    NoDuplo* atual = primeiro;
    //percorrer a lista e escrever na consola todos os elementos
    while (atual != 0)
    {
        cout << atual->elemento << ' ';
        atual = atual->seguinte;
    }
    cout << endl;
}

//método utilizado apenas para testes
void ListaDupla::MostrarInvertida() const
{
    if (Vazia())
    {
        cout << '*' << endl;
        return;
    }
    NoDuplo* atual = ultimo;
    //percorrer a lista pela ordem inversa
    //e escrever na consola todos os elementos
    while (atual != 0)
    {
        cout << atual->elemento << ' ';
        atual = atual->anterior;
    }
    cout << endl;
}
