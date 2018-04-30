#include "Usuario.h"
#include "Funcionarios.h"
using std::string;

int Funcionarios::buscaListaUsuarios(string cpf, string key, Usuario *user)
{
    int i = 0;
    std::list<Usuario>::iterator p;
    p = listaUsuarios.begin();
    string auxiliar1;
    string auxiliar2;
    while (i<listaUsuarios.size())
    {
        auxiliar1 = p->getCpf();
        auxiliar2 = p->getSenha();
        if (auxiliar1 == cpf && auxiliar2 == key)
        {
            user->setNome(p->getNome());
            return 1;
        }
        if (auxiliar1 == cpf)
            return 2;
        i++;
        p++;
    }
    return 0;
}

void Funcionarios::fazerLoginUsuario(Estoque *stock)
{
    int j;
    string cpf;
    string key;
    cout << "Informe seu CPF: " << endl;
    fflush(stdin);
    getline(cin, cpf);
    cout << "Informe sua senha: " << endl;
    fflush(stdin);
    getline(cin, key);
    system("cls");
    Usuario *user;
    user = new Usuario;
    j = buscaListaUsuarios(cpf, key, user);
    if (j == 1)
    {
        int i;
        do{
        i = user->gerenciaEstoque(user->getNome());
        system("cls");
        switch (i)
        {
        case 1:
            {
                stock->insereListaProdutos(cpf);
                break;
            }
        case 2:
            {
                stock->retiraListaProdutos(cpf);
                break;
            }
        case 3:
            {
                stock->checaEstoque();
                break;
            }
        case 4:
            {
                int a;
                a = retiraListaUsuarios(cpf);
                if (a == 1)
                    return;
                else
                    break;
            }
        default:
            if(i != 0)
                cout << "Opcao invalida!" << endl;
        }
        } while (i != 0);
    }
    else
        cout << "Erro! CPF ou senha incorretos." << endl;
}

void Funcionarios::realizarNovoCadastro()
{
    string name;
    string key1;
    string key2;
    string cpf;
    int j;
    Usuario *user;
    user = new Usuario;
    cout << "Informe seu nome: " << endl;
    fflush(stdin);
    getline(cin, name);
    cout << "Informe seu CPF: " << endl;
    fflush(stdin);
    getline(cin, cpf);
    cout << "Informe sua senha: " << endl;
    fflush(stdin);
    getline(cin, key1);
    cout << "Confirme a senha: " << endl;
    fflush(stdin);
    getline(cin, key2);
    while (key1 != key2)
        {
            cout << "Senhas diferentes! Informe uma nova senha:" << endl;
            fflush(stdin);
            getline(cin, key1);
            cout << "Confirme a senha: " << endl;
            fflush(stdin);
            getline(cin, key2);
        }
    system("cls");
    j = buscaListaUsuarios(cpf, key1, user);
    if (j == 1 || j == 2)
        cout << "Erro! Usuario ja cadastrado." << endl;
    else
    {
        user->setUsuario(name, key1, cpf);
        listaUsuarios.push_front(*user);
    }
}

int Funcionarios::retiraListaUsuarios (string cpf)
{
    int op;
    cout << "Tem certeza de que deseja desfazer a sua conta?" << endl;
    cout << "1 - Sim" << endl;
    cout << "2 - nao" << endl;
    cin >> op;
    system("cls");
    if (op == 1)
    {
        string aux;
        int i = 0;
        std::list<Usuario>::iterator p;
        p = listaUsuarios.begin();
        while (i<listaUsuarios.size())
            {
                aux = p->getCpf();
                if(aux == cpf)
                {
                    listaUsuarios.erase(p);
                    break;
                }
                i++;
                p++;
            }
        return 1;
    }
    else
        return 0;
}
