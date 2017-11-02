#include <stdio.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

void bubbleSort(string words[], int n)
{
    int size1, size2;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            size1 = words[j].size();
            size2 = words[j+1].size();
            if (size1 < size2)
            {
              swap(words[j], words[j+1]);
            }
        }
    }
}


int main()
{
    int  N, j = 0, sizeArr = 0, sizeSort = 0;
    string words[50], token, s;

    scanf("%d", &N);
    string wordsSort[N];

    getchar();
    for (int i = 0; i < N; i++)
    {
        getline(cin,s);
        istringstream iss(s);
        while (getline(iss, token, ' '))
        {
            words[j] = token;
            sizeArr++;
            j++;
        }

        bubbleSort(words, sizeArr);
        wordsSort[sizeSort] = words[0];
        for (int i = 1; i < sizeArr; i++)
        {
            wordsSort[sizeSort].append(" "+words[i]);
        }
        sizeSort++;
        sizeArr = 0;
        j = 0;
    }
    for (int i = 0; i < sizeSort; i++)
    {
        printf("%s\n", wordsSort[i].c_str());
    }
	return 0;
}

