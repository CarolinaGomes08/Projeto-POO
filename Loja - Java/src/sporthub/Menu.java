package sporthub;
import java.util.Scanner;

/**
 *
 * @author Weslles
 */
public class Menu {
    
    public void menu()
    {
        int op;
        Funcionarios employees = new Funcionarios();
        Estoque stock = new Estoque();
        Scanner ler = new Scanner(System.in);
        do{
            System.out.println("******** Sports Hub - Controle de estoque - Menu Principal ********\n");
            System.out.println("Informe a opcao desejada: ");
            System.out.println("1 - Fazer Login\n"
                             + "2 - Fazer Novo Cadastro\n"
                             + "0 - Sair");
            op = ler.nextInt();
            switch(op){
                case 1:{
                    employees.fazerLoginUsuario(stock);
                }
                break;
                case 2:{
                    employees.realizarNovoCadastro();
                }
                break;
                default:
                    if (op == 0)
                    System.out.println( "Fechando Estoque...");
                    }
        }while(op != 0);
        
    }
    
}
