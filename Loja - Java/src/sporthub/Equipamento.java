package sporthub;

/**
 *CONCLUÍDO
 * @author Weslles
 */
public class Equipamento extends Produto {
    private String modalidade;
    
    /*Construtor padrão para classe Equipamento*/
    public Equipamento(int marca, int descricao, String cpf, int quantidade, int option, float preco, int modalidade){
        setMarca(marca);
        setDescricao(descricao, option);
        setCpf(cpf);
        setQuantidade(quantidade);
        setPreco(preco);
        setModalidade(modalidade);
    } 
    public void setModalidade( int modalidade){
        switch(modalidade){
            case 1:
            {
                this.modalidade = "Basquete";
                break;
            }
            case 2:
            {
                this.modalidade = "Ciclismo";
                break;
            }
            case 3:
            {
                this.modalidade = "Futebol";
                break;
            }
            case 4:
            {
                this.modalidade = "Patinacao";
                break;
            }
            case 5:
            {
                this.modalidade = "Surf";
                break;
            }
            case 6:
            {
                this.modalidade = "Tenis";
                break;
            }
            case 7:
            {
                this.modalidade = "Volei";
                break;
            }
        }
    }
    public String getModalidade(){
        return modalidade;
    }
    public void imprimeInformacoesEquipamento(){
        System.out.println("\nProduto:");
        System.out.println("Marca:\t\t\t   "+getMarca());
        System.out.println("Descricao:\t\t   "+getDescricao());
        System.out.println("Quantidade:\t\t   "+getQuantidade());
        System.out.println("Preco:\t\t\t   R$ "+getPreco());
        System.out.println("Modalidade:\t\t   "+getModalidade());
        System.out.println("ID do Produto:\t\t   "+getId());
        System.out.println("Modificado por Ultimo por: "+getCpf());
        System.out.println("-----------------------------------------------");
        
    } 
}
