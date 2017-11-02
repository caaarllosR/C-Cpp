#include <stdio.h>
#include <deque>

using namespace std;

int main()
{
    int  N, M, j = 0,l = 0, v[100000], t, xCount[100000], x[100000];
    deque<int> vAux;

    scanf("%d%d", &N,&M);

    for (int i = 0; i < N; i++)
    {
        xCount[i] = 0;
    }
    while((N!=0)&&(M!=0))
    {
        for (int i = 0; i < N; i++)
        {
            vAux.push_back(i+1);
        }
        for (int i = 0; i < M; i++)
        {
            scanf("%d", &j);
            xCount[j]++;
            x[i] = j;
        }


        for (int i = 0; i < M; i++)
        {
            l = x[i];
            j = xCount[l];
            xCount[l] = 0;

            for (int k = 0; k < l; k++)
            {
                vAux.push_front(vAux[N+k-1-(l+j-1)]);
            }
            vAux.erase(vAux.begin()+N+l-1-(l+j-1), vAux.begin()+l+N+l-1-(l+j-1));
        }
        printf("%d", vAux.front());
        vAux.pop_front();
        for (int i = 1; i < N; i++)
        {
            printf(" %d", vAux.front());
            vAux.pop_front();
        }
        printf("\n");
        scanf("%d%d", &N,&M);
    }
	return 0;
}
