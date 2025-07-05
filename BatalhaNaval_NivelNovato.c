#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define  TAMANHO = 10

//função para criar o tabuleiro e inicializar com zeros
void criatbuleiro(int tabuleiro[10][10],int linhas){//esse argumento assume que nao se sabe quantas linhas terá a matriz apenas o numero de elementos[10]
    for(int i =0;i < linhas;i++){
        for(int j =0;j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }


}

//assinatura da função para inserir os navios no tabuleiro
int inserenavio(int tabuleiro[10][10], int tamanho, int linha, int coluna, int oritentacao);

//função para imprimir tabuleiro na tela
void imprimetabuleiro(int tabuleiro[10][10],char letras[10]){ //ou tabuleiro[][10]

printf(" /-------BATALHA NAVAL---------/\n\n");//coloca os caracteres sobre cada posição de cada elemento da primeira linha
for(int i = 0; i < 11;i++){ 
    //printf("");
    printf("%-3c",letras[i]);
}
    printf("\n");

for(int i = 0 ; i < 10;i++){
    printf("%2d ", i - 0);
    for(int j = 0; j < 10;j++){
        tabuleiro[i][j];
        printf("%d  ", tabuleiro[i][j]);
        }
        
        printf("\n");
    }

// Imprime coordenadas dos navios
   printf("\nCoordenadas dos Navios:\n");
    for(int i = 0; i <= 9; i++) {
        for(int j = 0; j < 11; j++) {
            if(tabuleiro[i][j] == 1) {
                printf("(Linha:%d|Coluna:%c) \n",i,letras[j]+1);
            }else if(tabuleiro[i][j] == 3){
               printf("(Linha:%d|Coluna:%c) ",i,letras[j]+1);
            }
        }
        
    }
    printf("\n");
}


int main(int argc, char const *argv[]){

int  tabuleiro[10][10];//(*tabuleiro)[10] se declarar como ponteiro de arrays o compilador exige alocação dinamica de memoria
char letras[11] = {' ','A','B','C','D','E','F','G','H','I','J'};
int tamanho = 3;
int navio1, navio2,navio3,navio4;
criatbuleiro(tabuleiro,10);

navio1 = inserenavio(tabuleiro,tamanho,0,2,3);//linha 5, coluna 2, orientação 3 diagonal secundária
navio2 = inserenavio(tabuleiro,tamanho,0,7,2);//linha 7, coluna 0, orientação 1 vertical
navio3 = inserenavio(tabuleiro,tamanho,9,7,0);//linha 9, coluna 7, orientação 0 horizontal
navio4 = inserenavio(tabuleiro,tamanho,7,4,1);//linha 0, coluna 4, orientação 2 diagonal primária
imprimetabuleiro(tabuleiro,letras);


return 0;
}



int inserenavio(int tabuleiro[10][10], int tamanho, int linha, int coluna, int orientacao){
    // Orientacao: 0 para horizontal, 1 para vertical
    
    
    // Verifica se a posição inicial é válida
    if(linha < 0 || linha >= 10 || coluna < 0 || coluna >= 10) {
        printf("Posição invalida!!");
        getchar();
        return 0; // Posição inválida
    }
    
    // Verifica se o navio cabe na orientação escolhida
    if(orientacao == 0 && (coluna + tamanho) > 10) {
        printf("Não cabe na horizontal, está fora do tamanho fixo da matriz!!\n");
        getchar();
        return 0; // Não cabe na horizontal
    }
    if(orientacao == 1 && (linha + tamanho) > 10) {
        printf("Não cabe na vertical, está fora do tamanho fixo da matriz!!\n");
        getchar();
        return 0; // Não cabe na vertical
    }
    
    if(orientacao == 2 && ((linha + tamanho)>10 || (coluna + tamanho)>10)){
        printf("Não cabe na diagonal (esquerda p/ direita), está fora do tamanho fixo da matriz!!\n");
        getchar();
        return 0;
    }
    if(orientacao == 3 && ((linha + tamanho)< -1 || (coluna - tamanho)< -1)){
        printf("Não cabe na diagonal (direita p/ esuqerda), está fora do tamanho fixo da matriz!\n");
        getchar();
        return 0;
    }
    // Verifica se já não há navio nessas posições
    for(int i = 0; i < tamanho; i++) {
        if(orientacao == 0 && tabuleiro[linha][coluna + i] != 0) { // Horizontal
            printf("Já tem navio aqui H!!");
            getchar();
            return 0; // Já tem navio aqui
            
        } else if(orientacao == 1 && tabuleiro[linha + i][coluna] != 0) { // Vertical
            printf("Já tem navio aqui V!!");
                getchar();
                return 0; // Já tem navio aqui
                  
        } else if(orientacao == 2 && tabuleiro[linha + i][coluna + i] != 0){ // Diagonal da esquerda p direita de cima para baixo
            printf("Já tem navio aqui D1!!");
            getchar();
                    
        } else if(orientacao == 3 && tabuleiro[linha + i][coluna - i] != 0){ // Diagonal da direita p esquerda de cima para baixo
                printf("Já tem navio aqui D1!!");
                getchar();
                
            }
        }
        for(int i = 0; i < tamanho; i++) {
        if(orientacao == 0) { // Horizontal
            tabuleiro[linha][coluna + i] = 3;// se posição for horizontal =  mesma linha preenche 3 colunas
        //printf("Navio inserido com sucesso!Na posição horizontal!");
        } else if(orientacao == 1){ // Vertical
            tabuleiro[linha + i][coluna] = 3;//se posição for vertical =  mesma coluna preenche 3 linhas
            //printf("Navio inserido com sucesso!Na posição vertical!");
        }else if(orientacao == 2){
            tabuleiro[linha+i][coluna+i] = 3;//da esquerda pra direita
        }else if(orientacao == 3){
            tabuleiro[linha+i][coluna-i] = 3;//da direita pra esquerda 
        }
    }
    
// Insere o navio
    
    
    //}
    //Insere o navio na diagoanl inversa direita para esquerda
    /*for(int i = 0; i < tamanho; i++){
        if(orientacao == 3){
            tabuleiro[linha+i][coluna+i] = 3;
        }
    }*/
    return 1; // Sucesso
    }
