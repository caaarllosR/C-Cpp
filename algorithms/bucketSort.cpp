#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;


void bucketSort(vector<float> &v)
{
	vector<float> b[v.size()];

	for (int i=0; i<v.size(); i++)
	{
	    int j = v.size()*v[i];
	    b[j].push_back(v[i]);
	}

	for (int i=0; i<v.size(); i++)
	{
        sort(b[i].begin(), b[i].end());
    }
	int k = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < b[i].size(); j++)
		{
            v[k++] = b[i][j];
		}
    }
}

int main()
{
    float values[] = {0.89, 0.33, 0.29, 0.43, 0.25, 0.18, 0.38,
                    0.98, 0.47, 0.88, 0.70, 0.28, 0.94, 0.52, 0.68, 0.91,
                    0.74, 0.48, 0.98, 0.80, 0.68, 0.57, 0.92, 0.35, 0.96,
                    0.39, 0.45, 0.53, 0.00, 0.49, 0.18, 0.36, 0.17, 0.75,
                    0.69, 0.68, 0.86, 0.61, 0.91, 0.91, 0.64, 0.18, 0.49,
                    0.06, 0.20, 0.01, 0.46, 0.66, 0.33, 0.48, 0.08, 0.26,
                    0.35, 0.92, 0.06, 0.96, 0.20, 0.63, 0.42, 0.70, 0.60,
                    0.06, 0.57, 0.76, 0.49, 0.46, 0.33, 0.09, 0.83, 0.30,
                    0.67, 0.66, 0.00, 0.42, 0.34, 0.45, 0.84, 0.89, 0.84,
                    0.12, 0.17, 0.21, 0.43, 0.16, 0.93, 0.12, 0.13, 0.83,
                    0.18, 0.96, 0.65, 0.59, 0.36, 0.03, 0.12, 0.05, 0.05,
                    0.56, 0.10, 0.51};
    int sizeV = sizeof(values)/sizeof(values[0]);

	vector<float> v;
	v.assign(values, values+sizeV);
	bucketSort(v);

    printf("\nResultado:");
    for (int i = 0; i < sizeV; i++)
    {
        printf(" %g", v[i]);
    }
    printf("\n");
	return 0;
}
