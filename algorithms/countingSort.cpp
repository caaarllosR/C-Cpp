#include <stdio.h>

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

void coutingSort(int v[], int n, int k)
{

    int c[k], b[n];
    for (int i = 0; i <= k; i++) {
        c[i] = 0;
    }
	for (int i = 0; i < n; i++) {
        b[i] = 0;
    }

 	for (int i = 0; i < n; i++) {
        c[v[i]]++;
    }

 	for (int i = 1; i <= k; i++) {
        c[i] += c[i-1];
    }

 	for (int i = 0; i < n; i++) {
        b[c[v[i]]-1] = v[i];
        c[v[i]]--;
    }

    for (int i = 0; i < n; i++) {
 			v[i] = b[i];
    }
}

int main()
{
    int v[] = {16, 3, 77, 79, 64, 42, 27, 68, 94, 83, 10,
                8, 82, 98, 96, 6, 83, 100, 53, 15, 79, 11, 61, 74, 65, 23,
                46, 97, 50, 49, 19, 81, 93, 43, 42, 33, 2, 61, 95, 95, 78,
                37, 23, 89, 67, 3, 53, 86, 2, 39, 100, 13, 65, 45, 70, 26,
                22, 56, 0, 37, 96, 79, 17, 10, 92, 89, 28, 22, 58, 7, 94,
                48, 91, 53, 82, 15, 34, 41, 31, 36, 29, 58, 50, 9, 79, 72,
                99, 61, 53, 28, 92, 39, 42, 0, 94, 100, 1, 85, 93, 63};
    int n = sizeof(v)/sizeof(v[0]);
    int k = maxValue(v, n);
    coutingSort(v, n, k);

    printf("\nResult:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", v[i]);
    }
    printf("\n");
    return 0;
}
