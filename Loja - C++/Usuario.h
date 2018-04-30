#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
using std::string;

class Usuario
{
public:
    void setUsuario(string name, string key, string c);
    void setNome (string name);
    void setSenha (string key);
    void setCpf (string cpf);
    string getNome();
    string getSenha();
    string getCpf();
    int gerenciaEstoque(string name);
private:
    string nome;
    string senha;
    string cpf;
};

#endif // USUARIO_H_INCLUDED
