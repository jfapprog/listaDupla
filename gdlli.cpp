/* 
 ** UC: 21046-Estrutura de Dados e Algoritmos Fundamentais
 ** e-fólio A 2015-16 (gdlli.cpp)
 **
 ** Aluno: 1301913 - José Póvoa
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <cstdlib>
#include "ListaDupla.h"
#include "Fila.h"

using namespace std;

const int NUM_COMANDOS_MAX = 3;

void LerComandos(Fila* comandos)
{
    string linha = "";
    int posicaoEspaco = -1;
    int contador = 0;
    cout << ">> ";
    getline(cin, linha);
    do
    {
        posicaoEspaco = (int) linha.find(' ');
        if (posicaoEspaco < 0)
            comandos->Colocar(linha);
        else
            comandos->Colocar(linha.substr(0, posicaoEspaco));
        linha = linha.substr(posicaoEspaco + 1, linha.length() - posicaoEspaco);
        contador++;
    } while (posicaoEspaco > 0 && contador < NUM_COMANDOS_MAX);
}

int main()
{
    ListaDupla* inteiros = new ListaDupla();
    Fila* comandos = new Fila();
    bool naoSair = true;
    do
    {
        LerComandos(comandos);
        if (comandos->Primeiro() == "ins0")
        {
            comandos->Retirar();
            if (comandos->NumeroElementos() != 1)
                cout << "Sintaxe correta: ins0 numero_nao_negativo" << endl;
            else
            {
                int elemento = atoi(comandos->Primeiro().c_str());
                if (elemento < 0 || !isdigit(comandos->Primeiro()[0]))
                    cout << "Sintaxe correta: ins0 numero_nao_negativo" << endl;
                else
                {
                    inteiros->AdicionarNoInicio(elemento);
                    cout << elemento << " inserido no inicio da lista" << endl;
                }
            }
        } else if (comandos->Primeiro() == "insend")
        {
            comandos->Retirar();
            if (comandos->NumeroElementos() != 1)
                cout << "Sintaxe correta: insend numero_nao_negativo" << endl;
            else
            {
                int elemento = atoi(comandos->Primeiro().c_str());
                if (elemento < 0 || !isdigit(comandos->Primeiro()[0]))
                    cout << "Sintaxe correta: insend numero_nao_negativo"
                        << endl;
                else
                {
                    inteiros->AdicionarNoFim(elemento);
                    cout << elemento << " inserido no fim da lista" << endl;
                }
            }
        } else if (comandos->Primeiro() == "del0")
        {
            comandos->Retirar();
            if (comandos->NumeroElementos() != 0)
                cout << "Sintaxe correta: del0" << endl;
            else
            {
                if (inteiros->RemoverDoInicio())
                    cout << "Primeiro elemento removido" << endl;
                else
                    cout << '*' << endl;
            }
        } else if (comandos->Primeiro() == "delend")
        {
            comandos->Retirar();
            if (comandos->NumeroElementos() != 0)
                cout << "Sintaxe correta: delend" << endl;
            else
            {
                if (inteiros->RemoverDoFim())
                    cout << "Ultimo elemento removido" << endl;
                else
                    cout << '*' << endl;
            }
        } else if (comandos->Primeiro() == "dellist")
        {
            comandos->Retirar();
            if (comandos->NumeroElementos() != 0)
                cout << "Sintaxe correta: dellist" << endl;
            else
                inteiros->Esvaziar();
        } else if (comandos->Primeiro() == "prt0")
        {
            comandos->Retirar();
            if (comandos->NumeroElementos() != 0)
                cout << "Sintaxe correta: prt0" << endl;
            else
            {
                if (inteiros->ElementoDoInicio() == -1)
                    cout << '*' << endl;
                else
                    cout << inteiros->ElementoDoInicio() << endl;
            }
        } else if (comandos->Primeiro() == "prtend")
        {
            comandos->Retirar();
            if (comandos->NumeroElementos() != 0)
                cout << "Sintaxe correta: prtend" << endl;
            else
            {
                if (inteiros->ElementoDoFim() == -1)
                    cout << '*' << endl;
                else
                    cout << inteiros->ElementoDoFim() << endl;
            }
        } else if (comandos->Primeiro() == "prt")
        {
            comandos->Retirar();
            if (comandos->NumeroElementos() != 0)
                cout << "Sintaxe correta: prt" << endl;
            else
                inteiros->Mostrar();
        } else if (comandos->Primeiro() == "dim")
        {
            comandos->Retirar();
            if (comandos->NumeroElementos() != 0)
                cout << "Sintaxe correta: dim" << endl;
            else
                cout << inteiros->NumeroElementos() << endl;
        } else if (comandos->Primeiro() == "find")
        {
            comandos->Retirar();
            if (comandos->NumeroElementos() != 1)
                cout << "Sintaxe correta: find numero_nao_negativo" << endl;
            else
            {
                int elemento = atoi(comandos->Primeiro().c_str());
                if (elemento < 0 || !isdigit(comandos->Primeiro()[0]))
                    cout << "Sintaxe correta: find numero_nao_negativo" << endl;
                else
                {
                    int ind;
                    if ((ind = inteiros->ProcurarElemento(elemento)) == -1)
                        cout << '*' << endl;
                    else
                        cout << "Primeira ocorrencia de " << elemento
                            << " na posicao " << ind << endl;
                }
            }
        } else if (comandos->Primeiro() == "del")
        {
            comandos->Retirar();
            if (comandos->NumeroElementos() != 1)
                cout << "Sintaxe correta: del numero_nao_negativo" << endl;
            else
            {
                int elemento = atoi(comandos->Primeiro().c_str());
                if (elemento < 0 || !isdigit(comandos->Primeiro()[0]))
                    cout << "Sintaxe correta: del numero_nao_negativo" << endl;
                else
                {
                    int ind;
                    if ((ind = inteiros->RemoverElemento(elemento)) == -1)
                        cout << '*' << endl;
                    else
                        cout << elemento << " removido da posicao " << ind << endl;
                }
            }
        } else if (comandos->Primeiro() == "ins")
        {
            comandos->Retirar();
            int posicaoMaxima = inteiros->NumeroElementos();
            if (comandos->NumeroElementos() != 2)
                cout << "Sintaxe correta: ins posicao(>=0 e <="
                    << posicaoMaxima << ") numero_nao_negativo" << endl;
            else
            {
                int posicao = atoi(comandos->Primeiro().c_str());
                if (posicao < 0 || posicao > posicaoMaxima
                        || !isdigit(comandos->Primeiro()[0]))
                    cout << "Sintaxe correta: ins posicao(>=0 e <="
                        << posicaoMaxima << ") numero_nao_negativo" << endl;
                else
                {
                    comandos->Retirar();
                    int elemento = atoi(comandos->Primeiro().c_str());
                    if (elemento < 0 || !isdigit(comandos->Primeiro()[0]))
                        cout << "Sintaxe correta: ins posicao(>=0 e <="
                            << posicaoMaxima << ") numero_nao_negativo" << endl;
                    else
                    {
                        inteiros->InserirNoIndice(posicao, elemento);
                        cout << elemento << " inserido na posicao "
                                << posicao << endl;
                    }
                }
            }
        } else if (comandos->Primeiro() == "sort")
        {
            comandos->Retirar();
            if (comandos->NumeroElementos() != 0)
                cout << "Sintaxe correta: sort" << endl;
            else
            {
                ListaDupla* auxiliar = new ListaDupla();
                int maximo;
                while ((maximo = inteiros->ElementoMaximo()) != -1)
                {
                    inteiros->RemoverElemento(maximo);
                    auxiliar->AdicionarNoInicio(maximo);
                }
                delete inteiros;
                inteiros = auxiliar;
            }
        } else if (comandos->Primeiro() == "exit")
        {
            comandos->Retirar();
            if (comandos->NumeroElementos() != 0)
                cout << "Sintaxe correta: exit" << endl;
            else
                naoSair = false;
        } else
            cout << "Introduziu um comando errado!" << endl;
        comandos->Esvaziar();
    } while (naoSair);
    delete inteiros;
    delete comandos;
    return 0;
}

