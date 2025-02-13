#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h> 
#include "moverpeca.h"
#include "index.h"

int quantidadeDeCasas ;

// movimentacao da peca escolhida
void moverPeca(char peca[20]){
char input[50];
char *endptr;
printf("Digite o numero de quantidade de casas que esse peca deve se mover : \n");
if (fgets(input, sizeof(input), stdin)) {
 input[strcspn(input, "\n")] = '\0';
 if (input[0] == '\0' || !isdigit(input[0])) {
 moverPeca(peca);
}
}
char pc[20] ;
strcpy(pc, peca);
pc[0] = toupper(peca[0]);
printf("=========================================================================\n");
printf("Peca selecionada '%s'\n", pc);
quantidadeDeCasas = strtol(input, &endptr, 10);
definirDirecao(peca);
return ;
}
void definirDirecao(char peca[20]){
char direcao[20];
if(strcmp(peca, "bispo") == 0){
        strcpy(direcao, "diagonal");
}
else if(strcmp(peca, "torre") == 0){
        strcpy(direcao, "direita");
}
else if(strcmp(peca, "rainha") == 0){
        strcpy(direcao, "esquerda");
}
    movimentoPorDirecao(quantidadeDeCasas,direcao);

}

void movimentoPorDirecao(int quantidadeDeCasas ,char direcao[20]){
printf("Essa peca ira se mover '%d' casas para a direcao '%s' \n",quantidadeDeCasas,direcao);
    for (int i = 1; i <= quantidadeDeCasas ; i++) {
printf("Passo: %d\n",i);
    }
selecionarNovaPeca();
 }
