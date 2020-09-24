#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main (){

    int num, i, j, u, cont_moda, cont;
    double media = 0, mediana = 0, moda = 0, aux, seq[3000];

    //Entrada da sequência
    scanf(" %d\n", &num);
    
    for(i=0;i<num;i++){
        scanf("%lf", &seq[i]);
    }

   //Sequência organizada
   for(j=0; j<num; j++){
        for(i=1; i<num; i++){
            if (seq[i-1]>seq[i]){
                aux = seq[i-1];
                seq[i-1] = seq[i];
                seq[i] = aux;
            }

        }
    }
   
    //Média
    for(i=0;i<num;i++){
        media = seq[i] + media;
    }
    media = media/num;

    //Mediana
    if(num % 2 == 0){
        //número par
        u = num/2;
        mediana = (seq[u-1] + seq[u])/2;

    } else {
        //número ímpar
        mediana = num/2;
        u = mediana + 0.5;
        mediana = seq[u];

    }

    //Moda
    cont_moda = 0;
    moda = -1;
    cont = 0;
    for (i = 0; i < num; i++) {
        cont++;
        if (i == num-1 || seq[i] != seq[i+1]){  
            /* quando um bloco de numeros iguais termina */
            if (cont > cont_moda) {
                cont_moda = cont;
                moda = seq[i];
            }
            cont = 0;
        }
    }

    //Imprimir os dados
    printf("%.1lf\n%.1lf\n%.0lf", media, mediana, moda);

    return(0);
}
