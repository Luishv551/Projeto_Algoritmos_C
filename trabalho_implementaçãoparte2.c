#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cadastro
{
    int codproduto, quantidade;
    char nome [40];
    char categoria [40];
    float preco;
};

struct cadastro cont[100];
int quant=0;

void quantidadeproduto(struct cadastro produto)
{
    cont[quant] = produto;
    quant++;
}

void leitura()
{
    int i;
    FILE *fp;

    if((fp = fopen("trabalho.txt", "r+b"))!=  NULL)
    {
        fscanf(fp, "%d\n", &quant);
        for(i=0; i<quant; i++){
        fread(&cont[i],sizeof(struct cadastro),1,fp);
        }
    }

    fclose(fp);
}


struct cadastro produto()
{
    struct cadastro auxiliar;
    printf("\nDigite nome do produto:\n");
    scanf("%s", &auxiliar.nome);
    auxiliar.codproduto = rand() % 99;
    printf("\nCodigo do produto %d\n",auxiliar.codproduto);
    printf("\nQuantidade de produtos:\n");
    scanf("%d", &auxiliar.quantidade);
    printf("\nDigite a categoria do produto:\n");
    scanf("%s",&auxiliar.categoria);
    printf("\nDigite o preco do produto:\n");
    scanf("%f",&auxiliar.preco);
    system("CLS");
    return auxiliar;
}


void pesquisar()
{
    int i, opcao;
    char nome [30];
    int codproduto;
        do{
            printf("\nMENU DE BUSCA\n");
            printf("\n1- Mostrar lista de produtos:\n");
            printf("\n2- Buscar pela categoria:\n");
            printf("\n3- Buscar pelo codigo do produto:\n");
            printf("\n4- Sair do menu de busca:\n");
            printf("\nDigite o numero da opcao desejada:\n");
            scanf("%d",&opcao);

            system("CLS");
            switch(opcao)
            {
                case 1:
                    printf("\nProdutos Cadastrados\n");
                    for (i=0; i<quant; i++){
                        printf("\nProduto %d \n",i+1);
                        printf ("\nNome do Produto: %s", cont[i].nome);
                        printf ("\nCodigo do Produto: %d", cont[i].codproduto);
                        printf ("\nQuantidade em estoque do Produto: %d", cont[i].quantidade);
                        printf ("\nCategoria do Produto: %s", cont[i].categoria);
                        printf ("\nPreco do Produto: %.2f\n", cont[i].preco);

                        }
                        break;
                case 2:
                    printf("Digite a categoria do produto:\n");
                    scanf("%s",&nome);
                    for(i=0;i<quant;i++){
                    if (strcmp (nome, cont[i].categoria) == 0){
                        printf ("\nNome do Produto: %s", cont[i].nome);
                        printf ("\nCodigo do Produto: %d", cont[i].codproduto);
                        printf ("\nQuantidade em estoque do Produto: %d", cont[i].quantidade);
                        printf ("\nCategoria do Produto: %s", cont[i].categoria);
                        printf ("\nPreco do Produto: %.2f", cont[i].preco);

                        }

                    }
                    break;
                case 3:
                    printf("Digite o codigo do produto:\n");
                    scanf("%d",&codproduto);
                     for(i=0;i<quant;i++){
                     if(codproduto==cont[i].codproduto){
                         printf("\nNome do Produto: %s", cont[i].nome);
                        printf("\nCodigo do Produto: %d", cont[i].codproduto);
                        printf("\nQuantidade em estoque do Produto: %d", cont[i].quantidade);
                        printf("\nCategoria do Produto: %s", cont[i].categoria);
                        printf("\nPreco do Produto: %.2f", cont[i].preco);
                     }
                     }
                     break;
                }
            }while(opcao!=4);
            system("CLS");
}
void atualizacao(){
    int i;
    char name[30];
    printf("\nDigite o nome do produto que deseja alterar: ");
    scanf("%s",&name);
    for(i=0;i<quant;i++){
        if (strcmp(cont[i].nome,name)==0){

        printf("Digite o novo preco do produto:\n");
        scanf("%f",&cont[i].preco);

        printf("\nO novo preco e:%f\n",cont[i].preco);
        }
        }
    }


void remocao(){

    int i,j;
    int cod_busc;
	printf("\nveja numero do produto que você deseja remover\n");
	pesquisar();
	printf("\nInforme o Codigo do Produto que se Deseja Excluir: ");
	scanf("%i",&cod_busc);
	for(i = 0 ;i < quant ;i++){

		if (cont[i].codproduto == cod_busc)
		{
			for(j=i; j<quant; j++)
            {
                cont[j] = cont[j+1];
            }
            quant = quant - 1;
		}
	}
    system("CLS");
    }

void gravacao(){
                    int i;
                    FILE *fp;
                    fp = fopen("trabalho.txt", "w+b");
                    fprintf(fp,"%d\n",quant);
                    for(i=0; i<quant; i++){
                    fwrite(&cont[i],sizeof(struct cadastro),1,fp);
                        }
                fclose(fp);
                }

int main(){
    int opcao;
    struct cadastro cont[100];
    int quant=0;
    struct cadastro novoproduto;
    leitura();
    do{
        printf("----------\n");
        printf("MENU");
        printf("\n----------\n");
        printf("\n1 - Cadastrar:");
        printf("\n2 - Pesquisar:");
        printf("\n3 - atualizacao:");
        printf("\n4 - remocao:");
        printf("\n5-Sair do MENU");
        printf("\nSelecione a opcao desejada:");
        scanf("%d",&opcao);
        system("CLS");
        switch(opcao){

        case 1:
                novoproduto = produto();
                quantidadeproduto(novoproduto);
                break;

        case 2:
                pesquisar();
                break;

        case 3:
                atualizacao();
                break;

        case 4:
                remocao();
                break;

        case 5:
                printf("Ate mais!\n");
                gravacao();
                return 0;
        default:
            printf("Opcao invalida, tente novamente!\n");
            break;
        }

}while(opcao!=5);


}
