#include "Produtos.h"

using namespace std;

void Produto::setMarca(int marca)
{
        switch (marca)
        {
        case 1:
            {
                this->marca = "Adidas";
                break;
            }
        case 2:
            {
                this->marca = "Fila";
                break;
            }
        case 3:
            {
                this->marca = "Nike";
                break;
            }
        case 4:
            {
                this->marca = "Olympikus";
                break;
            }
        case 5:
            {
                this->marca = "Oxer";
                break;
            }
        case 6:
            {
                this->marca = "Puma";
                break;
            }
        case 7:
            {
                this->marca = "Topper";
                break;
            }
        }
}
void Produto::setPreco(float preco)
{
        this->preco = preco;
}
void Produto::setDescricao(int descricao, int option)
{
    if(option == 1)
    {
        switch(descricao)
        {
        case 1:
            {
                this->descricao = "Calca";
                break;
            }
        case 2:
            {
                this->descricao = "Calcado";
                break;
            }
        case 3:
            {
                this->descricao = "Camiseta";
                break;
            }
        case 4:
            {
                this->descricao = "Meia";
                break;
            }
        case 5:
            {
                this->descricao = "Shorts";
                break;
            }
        }
    }
    else
    {
        switch(descricao)
        {
        case 1:
            {
                this->descricao = "Bicicleta";
                break;
            }
        case 2:
            {
                this->descricao = "Bola";
                break;
            }
        case 3:
            {
                this->descricao = "Patins";
                break;
            }
        case 4:
            {
                this->descricao = "Prancha";
                break;
            }
        case 5:
            {
                this->descricao = "Raquete";
                break;
            }
        case 6:
            {
                this->descricao = "Rede";
                break;
            }
        }
    }
}
void Produto::setCpf(string cpf)
{
        this->cpf = cpf;
}
void Produto::setQuantidade(int q)
{
        quantidade = q;
}
void Produto::setId(int id)
{
    this->id = id;
}
string Produto::getMarca()
{
    return marca;
}
float Produto::getPreco()
{
    return preco;
}
string Produto::getDescricao()
{
    return marca;
}
string Produto::getCpf ()
{
    return cpf;
}
int Produto::getQuantidade()
{
    return quantidade;
}
int Produto::getId()
{
    return id;
}

Equipamento::Equipamento(int marca, int descricao, string cpf, int quantidade, int option, float preco, int modalidade)
{
    setMarca(marca);
    setDescricao(descricao, option);
    setCpf(cpf);
    setQuantidade(quantidade);
    setPreco(preco);
    setModalidade(modalidade);
}
void Equipamento::setModalidade (int modalidade)
{
    switch(modalidade)
    {
    case 1:
        {
            this->modalidade = "Basquete";
            break;
        }
    case 2:
        {
            this->modalidade = "Ciclismo";
            break;
        }
    case 3:
        {
            this->modalidade = "Futebol";
            break;
        }
    case 4:
        {
            this->modalidade = "Patinacao";
            break;
        }
    case 5:
        {
            this->modalidade = "Surf";
            break;
        }
    case 6:
        {
            this->modalidade = "Tenis";
            break;
        }
    case 7:
        {
            this->modalidade = "Volei";
            break;
        }
    }
}
string Equipamento::getModalidade ()
{
    return modalidade;
}

void Equipamento::imprimeInformacoesEquipamento()
{
    cout << "\nProduto: ";
    cout << "\nMarca: "<< marca;
	cout << "\nDescricao: "<< descricao;
	cout << "\nQuantidade: "<< quantidade;
	cout << "\nPreco: ";
	cout << "R$ " << fixed << setprecision(2) << preco;
	cout << "\nModalidade esportiva: " << modalidade;
	cout << "\nID do produto: " << id;
	cout << "\nModificado por ultimo por: " << cpf << endl;
	cout << "-----------------------------------------------" << endl;
}

Vestuario::Vestuario(int marca, int descricao, string cpf, int quantidade, int option, int tamanho, int genero, float preco)
{
    setMarca(marca);
    setDescricao(descricao, option);
    setCpf(cpf);
    setQuantidade(quantidade);
    setPreco(preco);
    setTamanho(tamanho);
    setGenero(genero);
}
void Vestuario::setTamanho (int tamanho)
{
        this->tamanho = tamanho;
}
void Vestuario::setGenero (int genero)
{
    switch (genero)
    {
    case 1:
        {
            this->genero = "Feminino";
            break;
        }
    case 2:
        {
            this->genero = "Masculino";
            break;
        }
    }
}
int Vestuario::getTamanho ()
{
        return tamanho;
}
string Vestuario::getGenero()
{
        return genero;
}

void Vestuario::imprimeInformacoesVestuario()
{
    cout << "\nProduto: ";
    cout << "\nMarca: "<<marca;
	cout << "\nDescricao: "<<descricao;
	cout << "\nQuantidade: "<<quantidade;
	cout << "\nPreco: ";
	cout << "R$ " << fixed << setprecision(2) << preco;
	cout << "\nGenero: " << genero;
	cout << "\nTamanho: " << tamanho;
	cout << "\nID do produto: " << id;
	cout << "\nModificado por ultimo por: " << cpf << endl;
	cout << "-----------------------------------------------" << endl;
}
