package sporthub;


/**
 *CONCLUÍDO
 * @author Weslles
 */

public class Vestuario extends Produto{
    
    private int tamanho;
    private String genero;
    
    public Vestuario(int marca, int descricao, String cpf, int quantidade, int option, int tamanho, int genero, float preco){
        setMarca(marca);
        setDescricao(descricao, option);
        setCpf(cpf);
        setQuantidade(quantidade);
        setPreco(preco);
        setTamanho(tamanho);
        setGenero(genero);
    }
    
    public void setTamanho(int tamanho){
        this.tamanho = tamanho;
    }
    
    public int getTamanho(){
        return tamanho;
    }
    
    public void setGenero(int genero){
        switch (genero)
        {
            case 1:
            {
                this.genero = "Feminino";
                break;
            }
            case 2:
            {
                this.genero = "Masculino";
                break;
            }
        }
    }
    
    public String getGenero(){
        return genero;
    }
    
    public void imprimeInformacoesVestuario(){
        System.out.println("\nProduto: ");
        System.out.println("Marca:\t\t\t   "+getMarca());
        System.out.println("Descricao:\t\t   "+getDescricao());
        System.out.println("Quantidade:\t\t   "+getQuantidade());
        System.out.println("Preco:\t\t\t   R$ "+getPreco() );
        System.out.println("Genero:\t\t\t   "+getGenero());
        System.out.println("Tamanho:\t\t   "+getTamanho());
        System.out.println("ID do Produto:\t\t   "+getId());
        System.out.println("Modificado por Ultimo por: "+getCpf());
        System.out.println("-----------------------------------------------");
    }
    
}
