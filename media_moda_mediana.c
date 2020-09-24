#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <locale.h>


int main (){

    int num, i, j, aux;
    float conta = 0;
    int seq[100];
    double media = 0, mediana = 0, moda = 0;

    setlocale(LC_ALL,"");

    printf("Quantas entradas de dados ter� a sequ�ncia?\n");
    scanf(" %d", &num);
    int cont[num];

    printf("Digite as %d entradas:\n", num);
    for(i=0; i<num; i++){
        scanf("%d", &seq[i]);
    }

    //Sequ�ncia organizada
    for(j=0; j<num; j++){
        for(i=1; i<num; i++){
            if (seq[i-1]>seq[i]){
                aux = seq[i-1];
                seq[i-1] = seq[i];
                seq[i] = aux;
            }

        }
    }

    //M�dia
    for(i=0;i<num;i++){
        media = seq[i] + media;
    }
    media = media/num;

    //Mediana
    if(num % 2 == 0){
        //n�mero par
        aux = num/2;
        mediana = (seq[aux-1] + seq[aux])/2;

    } else {
        //n�mero �mpar
        mediana = num/2;
        aux = mediana + 0.5;
        mediana = seq[aux];

        if(mediana == 1){
            mediana = seq[0];
        }
    }

    //Moda

    for(i=0; i<num; i++){
        for(j=i+1;j<num;j++){
            if(seq[i] == seq[j]){
                cont[i]++;
                if(cont[i]>conta){
                    conta=cont[i];
                    moda = seq[i];
                }
            }
        }
        cont[i] = 0;
    }
    if (conta == 0){
        moda = seq[0];
    }
    //Imprimir os dados
    printf("\nA sequ�ncia em roll �: \n%d", seq[0]);
    for(i=1; i<num; i++){
        printf(" %d", seq[i]);
    }

    printf("\nA m�dia � %.1lf, a mediana � %.1lf e a moda � %.0lf", media, mediana, moda);


    return(0);
}