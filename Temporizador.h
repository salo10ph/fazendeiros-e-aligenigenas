#include <stdio.h>
#include <time.h>       // for time()
#define BILLION  1000000000.0
#define LIMITE_TEMPO 50
 double tempo_atual = LIMITE_TEMPO;
 struct timespec inicio, fim;

 void imprimeTempo(){
     clock_gettime(CLOCK_REALTIME, &fim);
         tempo_atual = tempo_atual - ((fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / BILLION);
         printf("Tempo atual: %.1f", tempo_atual);
         inicio = fim;
     if(tempo_atual < -100000){
            tempo_atual = LIMITE_TEMPO;
     }
 }
