
#include <stdio.h>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;


int compareCodeStr(string code1, string code2)
{
    int size1 = code1.size(), size2 = code2.size();

    if(size1<size2)
    {
        code2 = code2.substr(0,size1);
        if(code1.compare(code2)==0)
        {
            return -1;
        }
    }
    else if(size1>size2)
    {
        code1 = code1.substr(0,size2);
        if(code1.compare(code2)==0)
        {
            return 1;
        }
    }

    for(int i = 0; i<size1; i++)
    {
        if((code1[i]+0)<(code2[i]+0))
        {
            return -1;
        }
        else if((code1[i]+0)>(code2[i]+0))
        {
            return 1;
        }
    }
    return 0;
}

int partition (string arr[], int low, int high)
{
    string pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (compareCodeStr(arr[j], pivot)<=0)
        {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(string arr[], int low, int high)
{
    while (low < high)
    {
        int pi = partition(arr, low, high);

        if (pi - low < high - pi)
        {
			quickSort(arr, low, pi - 1);
			low = pi + 1;
		}
		else
		{
			quickSort(arr, pi + 1, high);
			high = pi - 1;
		}
    }
}

void printArray(string arr[], int size)
{
    for (int i=0; i < size; i++)
        printf("%s ", arr[i].c_str());
    printf("\n");
}

int main()
{
    string arr[] = {"aac", "0zzzz", "aacfsdf", "fccsdf", "0zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz", "aac", "aaccvfsdf", "c",
    "0zzzz", "fsbsdf","fsbsdf0", "bfsdf", "0sfsdf", "aaaacfsdffn", "aac", "aacfsd", "fccsdf", "aaccvf", "fsbsdf", "bfsdfy",
    "0sfsdf", "aaaacf", "aacfsd"};
    int size = sizeof(arr)/sizeof(arr[0]), sizeWord, sizeAux = 0;

    printf("Array: \n\n");
    printArray(arr, size);
    quickSort(arr, 0, size-1);
    printf("\n\nSorted array: \n\n");
    printArray(arr, size);
}
