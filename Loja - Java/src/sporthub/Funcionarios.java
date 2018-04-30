package sporthub;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.List;

public class Funcionarios {
    
    private List <Usuario> listaUsuarios = new ArrayList<>();
    
    public int buscaListaUsuarios (String cpf, String key, Usuario user){
        int i = 0;       
        String nome;
        String auxiliar1;
        String auxiliar2;
        while( i < listaUsuarios.size() ){
            auxiliar1 = listaUsuarios.get(i).getCpf();
            auxiliar2 = listaUsuarios.get(i).getSenha();
            nome = listaUsuarios.get(i).getNome();
            if(auxiliar1.equals(cpf) && auxiliar2.equals(key)){
                user.setNome(nome);                
                return 1;
            }
            if( auxiliar1.equals(cpf)){
                return 2;
            }
            i++;
        }
        return 0;
    }
    public void fazerLoginUsuario(Estoque stock){
        int j;
        String cpf;
        String key;
        
        Scanner ler = new Scanner(System.in);
        System.out.println("Informe seu CPF: ");
        cpf = ler.nextLine();
        System.out.println("Informe sua senha: ");
        key = ler.nextLine();
        
        Usuario user = new Usuario();
        
        j = buscaListaUsuarios(cpf, key, user);
        
        if( j == 1){
            int i;
            do{
                i = user.gerenciaEstoque(user.getNome());
                switch(i){
                    case 1:{
                        stock.insereListaProdutos(cpf);
                        break;
                    }
                    case 2:{
                        stock.retiraListaProdutos(cpf);
                        break;
                    }
                    case 3:{
                        stock.checaEstoque();
                        break;
                    }
                    case 4:{
                        int a;
                        a = retiraListaUsuarios(cpf);
                        if(a==1)
                            return;
                        else
                            break;
                    }
                    default:
                        if( i != 0)
                            System.out.println("Opção Invalida!");
                }
            }while(i != 0);
        }
        else
            System.out.println("\nErro!, CPF ou senha incorretos.");
    }
    public void realizarNovoCadastro(){
        String name;
        String key1;
        String key2;
        String cpf;
        Scanner ler = new Scanner(System.in);
        int j;
        Usuario user = new Usuario();
        
        System.out.println("\nInforme seu Nome: ");
        name = ler.nextLine();
        System.out.println("\nInforme seu CPF: ");
        cpf =  ler.nextLine();
        System.out.println("Informe sua senha: ");
        key1 = ler.nextLine();
        System.out.println("Confirme a senha: ");
        key2 = ler.nextLine();
        
        while(!key1.equals(key2)){
            System.out.println("Senhas Diferentes! \nInforme uma nova senha: ");
            key1 = ler.nextLine();
            System.out.println("Confirme a senha: ");
            key2 = ler.nextLine();
        }
        
        j = buscaListaUsuarios(cpf, key1, user);
        if( j == 1 || j == 2 )
            System.out.println("\nErro! Usuario já cadastrado.");
        else{
            user.setUsuario(name, key2, cpf);
            listaUsuarios.add(user);
        }
    }
    public int retiraListaUsuarios(String cpf){
        int op;
        Scanner ler = new Scanner(System.in);
        
        System.out.println("\n Tem certeza de que deseja desfazer a sua conta?");
        System.out.println("1 - Sim \n2 - Não");
        op = ler.nextInt();
         
        if ( op == 1 ){
            String aux;
            int i = 0;
            while ( i < listaUsuarios.size()){
                aux = listaUsuarios.get(i).getCpf();
                if (aux.equals(cpf)){
                    listaUsuarios.remove(i);
                    break;
                }
                i++;
            }
            return 1;
        }
        else
            return 0;
    }
}
