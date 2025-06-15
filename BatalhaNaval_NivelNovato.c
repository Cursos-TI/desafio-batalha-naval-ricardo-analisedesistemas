#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void criatbuleiro(int tabuleiro[10][10],int linhas){//esse argumento assume que nao se sabe quantas linhas terá a matriz apenas o numero de elementos[10]
    for(int i =0;i < linhas;i++){
        for(int j =0;j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }


}

int inserenavio(int tabuleiro[10][10], int tamanho, int linha, int coluna, int oritentacao);

void imprimetabuleiro(int tabuleiro[10][10],char letras[10]){ //ou tabuleiro[][10]
//coloca os caracteres sobre cada posição de cada elemento da primeira linha
printf(" /-------BATALHA NAVAL---------/\n\n");
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
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(tabuleiro[i][j] == 3) {
                printf("(%d, %c) ", i, letras[j]);
            }
        }
    }
    printf("\n");
}


int main(int argc, char const *argv[]){

int  tabuleiro[10][10];//(*tabuleiro)[10] se declarar como ponteiro de arrays o compilador exige alocação dinamica de memoria
char letras[11] = {' ','A','B','C','D','E','F','G','H','I','J'};
int tamanho = 3;
int navio1, navio2,navio3;
criatbuleiro(tabuleiro,10);

navio1 = inserenavio(tabuleiro,tamanho,0,3,1);
navio2 = inserenavio(tabuleiro,tamanho,9,0,0);
navio3 = inserenavio(tabuleiro,tamanho,5,4,2);

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
        printf("Não cabe na diagonal, está fora do tamanho fixo da matriz!!\n");
        getchar();
        return 0;
    }
    
    // Verifica se já não há navio nessas posições
    for(int i = 0; i < tamanho; i++) {
        if(orientacao == 0) { // Horizontal
            if(tabuleiro[linha][coluna + i] != 0) {
                printf("Já tem navio aqui!!");
                getchar();
                return 0; // Já tem navio aqui
            }
        } else if(orientacao == 1) { // Vertical
            if(tabuleiro[linha + i][coluna] != 0) {
                printf("Já tem navio aqui!!");
                getchar();
                return 0; // Já tem navio aqui
            }
        } else { // Diagonal
            if(tabuleiro[linha + i][coluna + i] != 0) {
                printf("Já tem navio aqui!!");
                getchar();
                return 0; // Já tem navio aqui
            }
        }
    }
    
// Insere o navio
    for(int i = 0; i < tamanho; i++) {
        if(orientacao == 0) { // Horizontal
            tabuleiro[linha][coluna + i] = 3;// se posição for horizontal =  mesma linha preenche 3 colunas
        //printf("Navio inserido com sucesso!Na posição horizontal!");
        } else if(orientacao == 1){ // Vertical
            tabuleiro[linha + i][coluna] = 3;//se posição for vertical =  mesma coluna preenche 3 linhas
            //printf("Navio inserido com sucesso!Na posição vertical!");
        }else{
            tabuleiro[linha+i][coluna+i] = 3;
        }
    }
    
    return 1; // Sucesso

} 