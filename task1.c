#include<stdio.h>

int main()
{
    unsigned int uinst, N;
    scanf("%u", &uinst);

    /// se extrage N din primii 3 biti din stanga:

    N=(uinst>>29)+1;

     /// Consideram numerotarea de la 0 la 31 (incepand din dreapta).
     /// Atunci primii 3 biti sunt pe pozitiile 31, 30, 29

     printf("%u ", N);

     ///Parcurgerea celor N perechi de biti:

     unsigned int k, aux, cod, m=27, dim;
     char s[5]="+-*/";

     for(k=1; k<=N; k++){
        aux=(uinst>>m);
        cod=aux&3;
        printf("%c ", s[cod]);
        m-=2;
     }

     aux=uinst>>(25-2*N); /// Pe aceasta pozitie va fi exact primul bit din cei 4 care reprezinta dimensiunea

     dim=(aux&15)+1;

     printf("%u\n", dim);


    return 0;
}

