/* 
 ** UC: 21046-Estrutura de Dados e Algoritmos Fundamentais
 ** e-fólio A 2015-16 (gdlli.cpp)
 **
 ** Aluno: 1301913 - José Póvoa
 */

#ifndef LISTADUPLA_H
#define LISTADUPLA_H

//#include <iostream>
//using namespace std;

class NoDuplo
{
public:
    unsigned int elemento;
    NoDuplo* seguinte;
    NoDuplo* anterior;
    NoDuplo()
    {
        seguinte = 0;
        anterior = 0;
        //para testes
        //cout << "No vazio construido!" << endl;
    }
    NoDuplo(unsigned int elem, NoDuplo* seg = 0, NoDuplo* ant = 0)
    {
        elemento = elem;
        seguinte = seg;
        anterior = ant;
        //para testes
        //cout << "No " << elemento << " construido!" << endl;
    }
    virtual ~NoDuplo()
    {
        //para testes
        //cout << "No " << elemento << " destruido!" << endl;
    }
};

class ListaDupla
{
private:
    NoDuplo* primeiro;
    NoDuplo* ultimo;
public:
    ListaDupla();
    virtual ~ListaDupla();
    
    bool Vazia() const;
    void Esvaziar();
    
    void AdicionarNoInicio(unsigned int elem);
    void AdicionarNoFim(unsigned int elem);
    void InserirNoIndice(unsigned int indice, unsigned int elem);
    bool RemoverDoInicio();
    bool RemoverDoFim();
    int RemoverElemento(unsigned int elem);
    
    unsigned int NumeroElementos() const;
    int ElementoDoInicio() const;
    int ElementoDoFim() const;
    int ElementoMaximo() const;
    int ProcurarElemento(unsigned int elem) const;
               
    void Mostrar() const;
    void MostrarInvertida() const;
};

#endif /* LISTADUPLA_H */

