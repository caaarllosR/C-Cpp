#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void comb(int N, int K)
{
    string bitMask(K, 1);
    bitMask.resize(N, 0);

    do {
        for (int i = 0; i < N; ++i)
        {
            if (bitMask[i]) cout << " " << i;
        }
        cout << endl;
    } while (prev_permutation(bitMask.begin(), bitMask.end()));
}

int main()
{
    int n;
    int k;
    cin >> n >> k;
    comb(n, k);
}
