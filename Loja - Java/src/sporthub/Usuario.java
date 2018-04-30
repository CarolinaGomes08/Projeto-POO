package sporthub;
import java.util.Scanner;
/**
 *Concluido
 * @author Weslles
 */
public class Usuario {
    private String nome;
    private String senha;
    private String cpf;
    
    public void setUsuario( String name, String key, String cpf ){
        setNome(name);
        setSenha(key);
        setCpf(cpf);
    }
    public void setNome(String name){
        nome = name;
    }
    public void setSenha(String key){
        senha = key;
    }
    public void setCpf( String cpf){
        this.cpf = cpf;
    }
    public String getNome(){
        return nome;
    }
    public String getCpf(){
        return cpf;
    }
    public String getSenha(){
        return senha;
    }
    public int gerenciaEstoque(String name){
        int opcao;
        Scanner ler = new Scanner(System.in);
        
        System.out.println("\n******** Bem vindo ao controle de estoque da loja ********\n");
        System.out.println("Usuario logado "+name);
        System.out.println("\nInforme a opção desejada: ");
        System.out.println("1 - Inserir novos produtos");
        System.out.println("2 - Retirar produtos do estoque");
        System.out.println("3 - Checar estoque");
        System.out.println("4 - Desfazer conta");
        System.out.println("0 - Sair");
                
        opcao = ler.nextInt();
        return opcao;
    }
}

