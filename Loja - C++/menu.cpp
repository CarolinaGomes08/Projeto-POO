#include "Menu.h"

using namespace std;

void Menu::menu()
{
    int op;
    Funcionarios *employees;
    Estoque *stock;
    employees = new Funcionarios;
    stock = new Estoque;
    do{
    cout << "******** Sports Hub - Controle de estoque - Menu Principal ********" << endl;
    cout << "Informe a opcao desejada: " << endl;
    cout << "1 - Fazer login" << endl;
    cout << "2 - Realizar novo cadastro" << endl;
    cout << "0 - Sair" << endl;
    cin >> op;
    system("cls");
    switch (op)
    {
    case 1:
        {
            employees->fazerLoginUsuario(stock);
        }
        break;
    case 2:
        {
            employees->realizarNovoCadastro();
        }
        break;
    default:
        if (op == 0)
            cout << "Fechando Estoque..." << endl;
    }

  } while (op != 0);
}
