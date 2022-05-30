#include<stdio.h>
int main()
{    unsigned int uinst, N, v[9];
    scanf("%u", &uinst);

    N=(uinst>>29)+1;
    unsigned int k, aux, cod, M=27, dim;
    char s[5]="+-*/";

    for(k=1; k<=N; k++)
    {
        aux=(uinst>>M);
        cod=aux&3;
        v[k-1]=cod;

        M-=2;
    }
    aux=uinst>>(25-2*N);
    dim=(aux&15)+1;
    int nr, q, r, m;
    nr=16/dim;
    q=((N+1)*dim)/16;
    r=((N+1)*dim)%16;
    m=q+(r!=0);
    k=0;
    int  poz, i;
    unsigned int comp;
    unsigned short x, y, w[17];
    for(i=1; i<=m; i++)
    {

        scanf("%u", &x);

        for(poz=16-dim; poz>=0; poz-=dim)
        {
            y=x>>poz;
            comp=(short)((1<<dim)-1);
            w[k]=y&comp;
            k++;
        }
    }
    int rez=(int)w[0];
    for(k=0; k<N; k++)
    {
        if(v[k]==0)
            rez=rez+w[k+1];
        if(v[k]==1)
            rez=rez-w[k+1];
        if(v[k]==2)
            rez=rez*w[k+1];
        if(v[k]==3)
            rez=rez/w[k+1];
    }
    printf("%d\n", rez);
    return 0;
}

