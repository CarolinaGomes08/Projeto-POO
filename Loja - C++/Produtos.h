#ifndef PRODUTOS_H_INCLUDED
#define PRODUTOS_H_INCLUDED

#include<list>
#include <iostream>
#include <iomanip>
#include <string>
#include<cstdlib>

using namespace std;

class Produto
{
public:
    void setMarca (int marca);
    void setPreco (float preco);
    void setDescricao (int descricao, int option);
    void setCpf (string cpf);
    void setQuantidade (int quantidade);
    void setId (int id);
    string getMarca();
    float getPreco();
    string getDescricao();
    string getCpf();
    int getQuantidade();
    int getId();
protected:
    string marca;
    string descricao;
    string cpf;
    int quantidade;
    int id;
    float preco;
};

class Equipamento: public Produto
{
public:
    Equipamento(int marca, int descricao, string cpf, int quantidade, int option, float preco, int modalidade);
    void setModalidade(int modalidade);
    string getModalidade();
    void imprimeInformacoesEquipamento();
private:
    string modalidade;
};

class Vestuario: public Produto
{
public:
    Vestuario(int marca, int descricao, string c, int quantidade, int option, int tamanho, int genero, float preco);
    void setTamanho (int tamanho);
    void setGenero (int genero);
    int getTamanho();
    string getGenero ();
    void imprimeInformacoesVestuario();
private:
    int tamanho;
    string genero;
};

#endif // PRODUTOS_H_INCLUDED
