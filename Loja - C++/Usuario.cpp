#include "Usuario.h"

using namespace std;

void Usuario::setUsuario(string name, string key, string cpf)
{
    setNome(name);
    setSenha(key);
    setCpf(cpf);
}

void Usuario::setNome (string name)
{
        nome = name;
}

void Usuario::setSenha (string key)
{
        senha = key;
}

void Usuario::setCpf (string cpf)
{
        this->cpf = cpf;
}

string Usuario::getNome()
{
    return(nome);
}

string Usuario::getSenha()
{
    return(senha);
}

string Usuario::getCpf()
{
    return(cpf);
}

int Usuario::gerenciaEstoque(string name)
{
    int op;
    cout << "******** Bem vindo ao controle de estoque da loja ********" << endl;
    cout << "Usuario logado: " << name << endl;
    cout << "Informe a opcao desejada: " << endl;
    cout << "1 - Inserir novos produtos" << endl;
    cout << "2 - Retirar produtos do estoque" << endl;
    cout << "3 - Checar estoque" << endl;
    cout << "4 - Desfazer conta" << endl;
    cout << "0 - Sair" << endl;
    cin >> op;
    return op;
}
