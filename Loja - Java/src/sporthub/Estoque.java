package sporthub;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.List;


/**
 *
 * @author Weslles
 */
public class Estoque {
    private List <Equipamento> listaEquipamento = new ArrayList<>();
    private List <Vestuario> listaVestuario= new ArrayList<>();

    public void insereListaProdutos(String cpf){
        Scanner input = new Scanner(System.in);
        int marca, qnt, option;
        float preco;

        
        System.out.println("\n---------------\n1-Peça de Vestuário\n2-Equipamento Esportivo\n---------------");
        System.out.println("\nSelecione a opcao que melhor especifica o produto a ser inserido::");
        option=input.nextInt();
        while (option < 1 || option > 2){
            System.out.println("Opcao inexistente! informe uma opcao valida.");
            option=input.nextInt();
        }
        
        System.out.println("Selecione a opcao que indica a marca do produto: ");
        System.out.println("\n1 - Adidas"
                         + "\n2 - Fila"
                         + "\n3 - Nike"
                         + "\n4 - Olympikus"
                         + "\n5 - Oxer"
                         + "\n6 - Puma"
                         + "\n7 - Topper");
        marca = input.nextInt();
        while ( marca < 1 || marca > 7 ){
            System.out.println("Opcao inexistente! informe uma opcao valida.");
            marca = input.nextInt();
        }
        
        System.out.println("\nInforme a quantidade de produtos que deseja inserir: ");
        qnt = input.nextInt();
        System.out.println("Informe o preço do produto: ");
        preco = input.nextFloat();
        
        switch(option){
            case 1:{
                insereListaVestuario(marca, cpf, qnt, preco);
                break;
            }
            case 2:{
                insereListaEquipamento(marca, cpf, qnt, preco);
                break;
            }
        }
    } // OK
   
    public void retiraListaProdutos(String cpf){
        int qnt, option, id;
        Scanner ler = new Scanner(System.in);
        System.out.println("\nSelecione a opcao que melhor especifica o produto a ser retirado:");
        System.out.println("1 - Peça de Vestuário");
        System.out.println("2 - Equipamento Esportivo\n");
        option = ler.nextInt();
        System.out.println("\n Informe o ID do produto que deseja retirar: ");
        System.out.println("Se não souber, pressione 0 para voltar e verifique na checagem do estoque");
        id = ler.nextInt();
        
        if( id == 0)
            return;
        System.out.println("\nInforme quantos produtos devem ser retirados: ");
        qnt = ler.nextInt();
        switch(option){
            case 1:{
                retiraListaVestuario(qnt, id, cpf);
                break;
            }
            case 2:{
                retiraListaEquipamento(qnt, id, cpf);
                break;
            }
        }
    }  //OK  
    
    public void insereListaEquipamento(int marca, String cpf, int qnt, float preco ){
        int aux1, aux2, desc, mod, ind =0;
        int i;
        
        Scanner ler = new Scanner(System.in);
       
        System.out.println("Selecione a opção que melhor descreve o produto: ");
        System.out.println("\n1 - Bicicleta"
                + "\n2 - Bola"
                + "\n3 - Patins"
                + "\n4 - Prancha"
                + "\n5 - Raquete"
                + "\n6 - Rede");
        desc = ler.nextInt();
        while ( desc < 1 || desc >6 ){
            System.out.println("Opcao inexistente! informe uma opcao valida.");
            desc = ler.nextInt();
        }
        
        System.out.println("Selecione a opção que indica a modalidade esportiva do equipamento: ");
        System.out.println("\n1 - Basquete"
                + "\n2 - Ciclismo"
                + "\n3 - Futebol"
                + "\n4 - Patinação"
                + "\n5 - Surf"
                + "\n6 - Tenis"
                + "\n7 - Volei");
        mod = ler.nextInt();
        while ( mod < 1 || mod >6 ){
            System.out.println("Opcao inexistente! informe uma opcao valida.");
            mod = ler.nextInt();
        }
        
        Equipamento e = new Equipamento(marca, desc, cpf, qnt, 2, preco, mod);
        while (ind < listaEquipamento.size()){
            if(     listaEquipamento.get(ind).getMarca().equals(e.getMarca()) &&
                    listaEquipamento.get(ind).getDescricao().equals(e.getDescricao()) &&
                    listaEquipamento.get(ind).getPreco() == e.getPreco() &&
                    listaEquipamento.get(ind).getModalidade().equals(e.getModalidade()) ){
                aux1 = listaEquipamento.get(ind).getQuantidade();
                aux2 = e.getQuantidade();
                listaEquipamento.get(ind).setQuantidade(aux1+aux2);
                listaEquipamento.get(ind).setCpf(cpf);
                break;
            }
            ind++; 
        }
        
        if(ind == listaEquipamento.size()){
            if(ind == 0)
                i = 1;
            else{
                ind--;
                i = listaEquipamento.get(ind).getId()+1;
            }
                
            e.setId(i);
            listaEquipamento.add(e);
        }
    } // OK

    public void insereListaVestuario(int marca, String cpf, int quantidade, float preco){
        Scanner ler = new Scanner(System.in);
        int desc, tam, genero, ind = 0;
        int aux1, aux2;
        
        System.out.println("Selecione a opcao que melhor descreve o produto:");
        System.out.println(  "1 - Calça\n"
                           + "2 - Calçado\n"
                           + "3 - Camiseta\n"
                           + "4 - Meia\n"
                           + "5 - Shorts\n");
        
        desc = ler.nextInt();
        while( desc < 1 || desc > 5){
            System.out.println("Opcao inexistente! informe uma opcao valida.");
            desc = ler.nextInt();
        }
        System.out.println("Informe o tamanho da(s) peças: ");
        tam = ler.nextInt();
        System.out.println("Selecione a opção que indica o genero do produto: ");
        System.out.println("1 - Feminino"+
                         "\n2 - Masculino");
        
        genero = ler.nextInt();
        while ( genero < 1 || genero > 2){
            System.out.println("Opcao inexistente! informe uma opcao valida.");
            genero = ler.nextInt();
        }
        Vestuario v = new Vestuario(marca, desc, cpf, quantidade, 1, tam, genero, preco);
        while(ind < listaVestuario.size() ){
            if( listaVestuario.get(ind).getGenero().equals(v.getGenero())&&
                listaVestuario.get(ind).getDescricao().equals(v.getDescricao()) &&
                listaVestuario.get(ind).getMarca().equals(v.getMarca()) &&
                listaVestuario.get(ind).getPreco() == v.getPreco() &&
                listaVestuario.get(ind).getTamanho() == v.getTamanho() ){
                
                    aux1 = listaVestuario.get(ind).getQuantidade();
                    aux2 = v.getQuantidade();
                    listaVestuario.get(ind).setQuantidade(aux1+aux2);
                    listaVestuario.get(ind).setCpf(v.getCpf());
                    break;
            }
            ind++;
        }
        if ( ind == listaVestuario.size() ){
            int novoInd;
            if( ind == 0 )
                novoInd = 1;
            else{
                ind--;
                novoInd = listaVestuario.get(ind).getId()+1;
            }
            v.setId(novoInd);
            listaVestuario.add(v);
        }
        
    }

    public void retiraListaEquipamento(int quantidade, int id, String cpf){
        int cont, ind = 0, cheqId = 0;
        boolean b = false;
                
        while( cheqId != id && ind <= listaEquipamento.size() ){
            cheqId = listaEquipamento.get(ind).getId();
            if(cheqId == id){
                cont = listaEquipamento.get(ind).getQuantidade();
                if(cont < quantidade)
                    System.out.println("Erro! Não existem tantos exemplares no estoque.");
                else{
                    listaEquipamento.get(ind).setQuantidade(cont - quantidade);
                    listaEquipamento.get(ind).setCpf(cpf);
                }
                b = true;
                break;
            }
            ind++;
                 
        }
        if( b == false){
            System.out.println("Erro! O produto nao se encontra disponivel no estoque");
        }
    }  //OK

    public void retiraListaVestuario(int quantidade, int id, String cpf ){
        int cont, ind = 0, cheqId = 0;
        boolean b = false;
                
        while( cheqId != id && ind <= listaVestuario.size() ){
            cheqId = listaVestuario.get(ind).getId();
            if(cheqId == id){
                cont = listaVestuario.get(ind).getQuantidade();
                if(cont < quantidade)
                    System.out.println("Erro! Não existem tantos exemplares no estoque.");
                else{
                    listaVestuario.get(ind).setQuantidade(cont - quantidade);
                    listaVestuario.get(ind).setCpf(cpf);
                }      
                b = true;
                break;
            }
            ind++;
                 
        }
        if( b == false){
            System.out.println("Erro! O produto nao se encontra disponivel no estoque");
        }
    }  //OK

    public void imprimeListaVestuario() {
        int i;
        for ( i = 0; i < listaVestuario.size(); i++){
            listaVestuario.get(i).imprimeInformacoesVestuario();
        }
     }  //OK

    public void imprimeListaEquipamento() {
        int j;
        for(j = 0; j<listaEquipamento.size(); j++){
            listaEquipamento.get(j).imprimeInformacoesEquipamento();
        }
     }   //OK

    public void checaEstoque(){
        int op;
        boolean b = true;
        int v;
        char t;
        Scanner ler = new Scanner(System.in);

        System.out.println("Informe o tipo de produto que deseja verificar: ");
        System.out.println("1 - Produtos de Vestuário ");
        System.out.println("2 - Equipamentos Esportivos ");
        System.out.println("3 - Todo o Estoque ");
        op = ler.nextInt();

        switch(op){
            case 1:{
                System.out.println("Lista de produtos de vestuario disponiveis no estoque: ");
                imprimeListaVestuario();
                break;
            }
            case 2:{
                System.out.println("Lista de Equipamentos presentes no estoque: ");
                imprimeListaEquipamento();
                break;
            }
            case 3:{
                System.out.println("Lista de Produtos de Vestuario disponivel no estoque: ");
                imprimeListaVestuario();
                System.out.println("\nLista de Equipamentos presentes no estoque: ");
                imprimeListaEquipamento();
                break;
            }
            default:
                System.out.println("Opção Invalida!");
            
        }
        System.out.println("\nPara voltar digite 0: ");
        v = ler.nextInt();
        while(v != 0 ){
            System.out.println("\nErro! Para voltar digite v: ");
            v = ler.nextInt();
        }
    } 
}
