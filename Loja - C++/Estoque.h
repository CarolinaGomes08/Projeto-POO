#ifndef ESTOQUE_H_INCLUDED
#define ESTOQUE_H_INCLUDED

#include<list>
#include<stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include<cstdlib>
#include "Produtos.h"

class Estoque
{
public:
    void insereListaProdutos(string cpf);
    void retiraListaProdutos(string cpf);
    void insereListaVestuario(int marca, string cpf, int quantidade, float preco);
    void insereListaEquipamento(int marca, string cpf, int quantidade, float preco);
    void retiraListaVestuario(int quantidade, int id, string cpf);
    void retiraListaEquipamento(int quantidade, int id, string cpf);
    void imprimeListaVestuario();
    void imprimeListaEquipamento();
    void checaEstoque();
private:
    std::list<Vestuario> listaVestuario;
    std::list<Equipamento> listaEquipamento;
};

#endif // ESTOQUE_H_INCLUDED
