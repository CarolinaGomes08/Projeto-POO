#include "Estoque.h"

using namespace std;

void Estoque::insereListaProdutos(string cpf)
{
    int marca, quantidade, option;
    float preco;
    cout << "Selecione a opcao que melhor especifica o produto a ser inserido: "<< endl;
    cout << "1 - Peca de vestuario" << endl;
    cout << "2 - Equipamento esportivo" << endl;
    fflush(stdin);
    cin >> option;
    while (option < 1 || option > 2)
    {
        cout << "Opcao inexistente! informe uma opcao valida." << endl;
        fflush(stdin);
        cin >> option;
    }
    cout << "Selecione a opcao que indica a marca do produto: " << endl;
    cout << "1 - Adidas" << endl;
    cout << "2 - Fila" << endl;
    cout << "3 - Nike" << endl;
    cout << "4 - Olympikus" << endl;
    cout << "5 - Oxer" << endl;
    cout << "6 - Puma" << endl;
    cout << "7 - Topper" << endl;
    fflush(stdin);
    cin >> marca;
    while (marca < 1 || marca > 7)
    {
        cout << "Opcao inexistente! informe uma opcao valida." << endl;
        fflush(stdin);
        cin >> marca;
    }
    cout << "Informe a quantidade de produtos que deseja inserir: " << endl;
    fflush(stdin);
    cin >> quantidade;
    cout << "Informe o preco do produto: " << endl;
    fflush(stdin);
    cin >> preco;
    switch (option)
    {
    case 1:
        {
            insereListaVestuario(marca, cpf, quantidade, preco);
        }
        break;
    case 2:
        {
            insereListaEquipamento(marca, cpf, quantidade, preco);
        }
        break;
    }
}

void Estoque::retiraListaProdutos(string cpf)
{
    int quantidade, option, id;
    cout << "Selecione a opcao que melhor especifica o produto a ser retirado: "<< endl;
    cout << "1 - Peca de vestuario" << endl;
    cout << "2 - Equipamento esportivo" << endl;
    fflush(stdin);
    cin >> option;
    cout << "Informe o ID do produto que deseja retirar: " << endl;
    cout << "(Se nao souber, pressione 0 para voltar, e verifique na checagem de estoque) " << endl;
    fflush(stdin);
    cin >> id;
    if(id == 0)
    {
        system("cls");
        return;
    }
    cout << "Informe quantos produtos devem ser retirados: " << endl;
    fflush(stdin);
    cin >> quantidade;
    system("cls");
    switch (option)
    {
    case 1:
        {
            retiraListaVestuario(quantidade, id, cpf);
            break;
        }
    case 2:
        {
            retiraListaEquipamento(quantidade, id, cpf);
            break;
        }
    }
}

void Estoque::insereListaVestuario(int marca, string cpf, int quantidade, float preco)
{
    int tamanho, genero, aux1, aux2, descricao,j = 0;
    std::list<Vestuario>::iterator pV;
    cout << "Selecione a opcao que melhor descreve o produto: " << endl;
    cout << "1 - Calca" << endl;
    cout << "2 - Calcado" << endl;
    cout << "3 - Camiseta" << endl;
    cout << "4 - Meia" << endl;
    cout << "5 - Shorts" << endl;
    fflush(stdin);
    cin >> descricao;
    while (descricao < 1 || descricao > 5)
    {
        cout << "Opcao inexistente! informe uma opcao valida." << endl;
        fflush(stdin);
        cin >> descricao;
    }
    cout << "Informe o tamanho da(s) pecas" << endl;
    fflush(stdin);
    cin >> tamanho;
    cout << "Selecione a opcao que indica o genero do produto: " << endl;
    cout << "1 - Feminino" << endl;
    cout << "2 - Masculino" << endl;
    fflush(stdin);
    cin >> genero;
    while (genero < 1 || genero > 2)
    {
        cout << "Opcao inexistente! informe uma opcao valida." << endl;
        fflush(stdin);
        cin >> genero;
    }
    system("cls");
    Vestuario v(marca, descricao, cpf, quantidade, 1, tamanho, genero, preco);
    pV = listaVestuario.begin();
    while (j<listaVestuario.size())
        {
            if(pV->getMarca() == v.getMarca() && pV->getDescricao() == v.getDescricao() && pV->getPreco() == v.getPreco() && pV->getTamanho() == v.getTamanho() && pV->getGenero() == v.getGenero())
            {
                aux1 = pV->getQuantidade();
                aux2 = v.getQuantidade();
                pV->setQuantidade(aux1+aux2);
                pV->setCpf(cpf);
                break;
            }
            j++;
            pV++;
        }
        if (j == listaVestuario.size())
        {
            int i = j+1;
            v.setId(i);
            listaVestuario.push_back(v);
        }
}
void Estoque::insereListaEquipamento(int marca, string cpf, int quantidade, float preco)
{
    int aux1, aux2, descricao, modalidade, j = 0;
    std::list<Equipamento>::iterator pE;
    cout << "Selecione a opcao que melhor descreve o produto: " << endl;
    cout << "1 - Bicicleta" << endl;
    cout << "2 - Bola" << endl;
    cout << "3 - Patins" << endl;
    cout << "4 - Prancha" << endl;
    cout << "5 - Raquete" << endl;
    cout << "6 - Rede" << endl;
    fflush(stdin);
    cin >> descricao;
    while (descricao < 1 || descricao > 6)
    {
        cout << "Opcao inexistente! informe uma opcao valida." << endl;
        fflush(stdin);
        cin >> descricao;
    }
    cout << "Selecione a opcao que indica a modalidade esportiva do equipamento: " << endl;
    cout << "1 - Basquete" << endl;
    cout << "2 - Ciclismo" << endl;
    cout << "3 - Futebol" << endl;
    cout << "4 - Patinacao" << endl;
    cout << "5 - Surf" << endl;
    cout << "6 - Tenis" << endl;
    cout << "7 - Volei" << endl;
    fflush(stdin);
    cin >> modalidade;
    while (modalidade < 1 || modalidade > 7)
    {
        cout << "Opcao inexistente! informe uma opcao valida." << endl;
        fflush(stdin);
        cin >> modalidade;
    }
    system("cls");
    Equipamento e(marca, descricao, cpf, quantidade, 2, preco, modalidade);
    pE = listaEquipamento.begin();
    while (j<listaEquipamento.size())
        {
            if(pE->getMarca() == e.getMarca() && pE->getDescricao() == e.getDescricao() && pE->getPreco() == e.getPreco() && pE->getModalidade() == e.getModalidade())
            {
                aux1 = pE->getQuantidade();
                aux2 = e.getQuantidade();
                pE->setQuantidade(aux1+aux2);
                pE->setCpf(cpf);
                break;
            }
            j++;
            pE++;
        }
        if (j == listaEquipamento.size())
        {
            e.setId(j+1);
            listaEquipamento.push_back(e);
        }
}

void Estoque::retiraListaVestuario(int quantidade, int id, string cpf)
{
    int j, t = 0, k = 0;
    bool b = false;
    std::list<Vestuario>::iterator pV;
    pV = listaVestuario.begin();
    while (k != id && t <= listaVestuario.size())
    {
        k = pV->getId();
        if (k == id)
        {
            j = pV->getQuantidade();
            if (j < quantidade)
                cout << "Erro! Nao existem tantos exemplares no estoque." << endl;
            else if (j >= quantidade)
            {
                pV->setQuantidade(j-quantidade);
                pV->setCpf(cpf);
            }
            b = true;
            break;
        }
        pV++;
        t++;
    }
    if(b == false)
    {
        cout << "Erro! O produto nao se encontra disponivel no estoque" << endl;
    }
}

void Estoque::retiraListaEquipamento(int quantidade, int id, string cpf)
{
    int j, t = 0, k = 0;
    string modalidade;
    bool b = false;
    std::list<Equipamento>::iterator pE;
    pE = listaEquipamento.begin();
    while (k != id && t <= listaEquipamento.size())
    {
        k = pE->getId();
        if (k == id)
        {
            j = pE->getQuantidade();
            if (j < quantidade)
                cout << "Erro! Nao existem tantos exemplares no estoque." << endl;
            else if (j >= quantidade)
            {
                pE->setQuantidade(j-quantidade);
                pE->setCpf(cpf);
            }
            b = true;
            break;

        }
        pE++;
        t++;
    }
    if(b == false)
    {
        cout << "Erro! O produto nao se encontra disponivel no estoque" << endl;
    }
}

void Estoque::imprimeListaVestuario()
{
    std::list<Vestuario>::iterator pV;
    pV = listaVestuario.begin();
    for (int i=0; i<listaVestuario.size();i++)
        {
            pV->imprimeInformacoesVestuario();
            pV++;
        }
    return;
}

void Estoque::imprimeListaEquipamento()
{
    std::list<Equipamento>::iterator pE;
    pE = listaEquipamento.begin();
    for (int j=0; j<listaEquipamento.size();j++)
        {
            pE->imprimeInformacoesEquipamento();
            pE++;
        }
    return;
}

void Estoque::checaEstoque()
{
    int op;
    char v;
    cout << "Informe o tipo de produto que deseja verificar: " << endl;
    cout << "1 - Produtos de vestuario" << endl;
    cout << "2 - Equipamentos esportivos" << endl;
    cout << "3 - Todo o estoque" << endl;
    fflush(stdin);
    cin >> op;
    system("cls");
    switch (op)
    {
    case 1:
        {
            cout << "Lista de produtos de vestuario disponiveis no estoque: " << endl;
            imprimeListaVestuario();
            break;
        }
    case 2:
        {
            cout << "Lista de Equipamentos presentes no estoque: " << endl;
            imprimeListaEquipamento();
            break;
        }
    case 3:
        {
            cout << "Lista de produtos de vestuario disponiveis no estoque: " << endl;
            imprimeListaVestuario();
            cout << "\nLista de Equipamentos presentes no estoque: " << endl;
            imprimeListaEquipamento();
            break;
        }
    default:
        cout << "Opcao invalida!" << endl;
    }
    cout << "\nPara voltar digite v: " << endl;
    cin >> v;
    system("cls");
}
