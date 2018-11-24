
#include <stdio.h>

using namespace std;

int maxValue(int v[], int n)
{
    int k = v[0];
  	for (int i = 1; i < n; i++) {
        if (v[i] > k) {
            k = v[i];
        }
    }
    return k;
}


void countingSort(int v[], int n, int k)
{
    int c[10], b[n];
    for (int i = 0; i < 10; i++) {
        c[i] = 0;
    }
	for (int i = 0; i < n; i++) {
        b[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        c[ (v[i]/k)%10 ]++;
    }

    for (int i = 1; i < 10; i++)
    {
        c[i] += c[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        b[c[ (v[i]/k)%10 ] - 1] = v[i];
        c[ (v[i]/k)%10 ]--;
    }


    for (int i = 0; i < n; i++)
    {
        v[i] = b[i];
    }
}

void radixSort(int v[], int n)
{
    int k = maxValue(v, n);
    for (int exp10 = 1; k/exp10 > 0; exp10 *= 10)
        countingSort(v, n, exp10);
}


int main()
{
    int v[] = {3239, 6017, 5273, 4783, 3852, 4601, 8686,
                8461, 5336, 9559, 6441, 7488, 6429, 2379, 8420, 6897,
                1170, 1637, 3251, 2724, 8543, 8575, 1284, 5531, 7812,
                6587, 3229, 4359, 3082, 1554, 4664, 3502, 3016, 7260,
                5678, 4524, 5682, 8336, 7723, 9947, 2892, 4728, 4956,
                5953, 6331, 1566, 3199, 4218, 2812, 1577, 6022, 4994,
                2328, 8857, 5044, 1246, 3796, 5917, 5809, 6639, 7119,
                6257, 6532, 2136, 7359, 5510, 1519, 6925, 7001, 7352,
                6544, 5987, 9115, 2114, 9900, 5854, 5478, 1525, 4137,
                6128, 1597, 5336, 7337, 3335, 2744, 9357, 4515, 4298,
                8036, 4307, 6862, 5206, 2931, 2198, 3974, 5134, 9849,
                4493, 2255, 1602};
    int size = sizeof(v)/sizeof(v[0]);
    radixSort(v, size);

    printf("\nResult:");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", v[i]);
    }
    printf("\n");
    return 0;
}
