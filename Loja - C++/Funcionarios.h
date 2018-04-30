#ifndef FUNCIONARIOS_H_INCLUDED
#define FUNCIONARIOS_H_INCLUDED

#include<iostream>
#include<iomanip>
#include<string>
#include<list>
#include<stdio.h>
#include<cstdlib>
#include "Usuario.h"
#include "Estoque.h"

class Funcionarios
{
public:
    int buscaListaUsuarios(string cpf, string key, Usuario *user);
    void fazerLoginUsuario(Estoque *stock);
    void realizarNovoCadastro();
    int retiraListaUsuarios(string cpf);
private:
    std::list<Usuario> listaUsuarios;
};

#endif // FUNCIONARIOS_H_INCLUDED
