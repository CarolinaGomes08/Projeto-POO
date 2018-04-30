package sporthub;

/**
 *CONCLUÍDO
 * @author Weslles
 */
abstract class Produto {
    protected String marca;
    protected String descricao;
    protected String cpf;
    protected int quantidade;
    protected float preco;
    protected int id;
    
    public void setMarca(int marca){
       switch (marca)
        {
           case 1:
           {
               this.marca = "Adidas";
               break;
           }
           case 2:
           {
               this.marca = "Fila";
               break;
           }
           case 3:
           {
                this.marca = "Nike";
                break;
           }
           case 4:
           {
                this.marca = "Olympikus";
                break;
           }
           case 5:
           {
                this.marca = "Oxer";
                break;
           }
           case 6:
           {
                this.marca = "Puma";
                break;
           }
           case 7:
           {
                this.marca = "Topper";
                break;
           }
           default:
                System.out.println("\nErro, Entrada Inválida");
            }
    }
    public String getMarca(){
        return marca;
    }
    public void setDescricao(int descricao, int option){
        if (option == 1){
            switch(descricao){  
                
                case 1:
                    {
                        this.descricao = "Calca";
                        break;
                    }
                case 2:
                    {
                        this.descricao = "Calcado";
                        break;
                    }
                case 3:
                    {
                        this.descricao = "Camiseta";
                        break;
                    }
                case 4:
                    {
                        this.descricao = "Meia";
                        break;
                    }
                case 5:
                    {
                        this.descricao = "Shorts";
                        break;
                    }
            }
        }
        else{
                        
            switch(descricao)
            {
                case 1:
                {
                    this.descricao = "Bicicleta";
                    break;
                }
                case 2:
                {
                    this.descricao = "Bola";
                    break;
                }
                case 3:
                {
                    this.descricao = "Patins";
                    break;
                }
                case 4:
                {
                    this.descricao = "Prancha";
                    break;
                }
                case 5:
                {
                    this.descricao = "Raquete";
                    break;
                }
                case 6:
                {
                    this.descricao = "Rede";
                    break;
                }
            }
        }
    }
    public String getDescricao(){
        return descricao;
    }
    public void setCpf(String cpf){
        this.cpf = cpf;
    }    
    public String getCpf(){
        return cpf;
    } 
    public void setQuantidade(int quantidade){
        this.quantidade = quantidade;
    }   
    public int getQuantidade(){
        return quantidade;
    }
    public void setPreco(float preco){
        this.preco = preco;
    
    }
    public float getPreco(){
        return preco;
    }
    public void setId(int id){
        this.id = id;
    }
    public int getId(){
        return id;
    }
}
