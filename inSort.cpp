//inserion sort in linked list
//THERE ARE PROBLEMS IN THIS CODE. I MUST CORRECT THESE!!!!
#include <iostream>
using namespace std;

void insertionSort(int[], int);

int main()
{
    int a[] = {9, 27, 4, 6, 71, 3};
    int n = sizeof(a)/sizeof(a[0]);

    insertionSort(a, n);

    for(int i=0; i<n; i++)
        cout << a[i] << " ";

    return EXIT_SUCCESS;
}

void insertionSort(int arr[], int n)
{
    int key;
    for(int i=1; i<n; ++i)
    {
        key = arr[i];
        insertionSort(arr, i+1);
        for(int j=i-1; j>=0; --j)
        {
            if(arr[j] > arr[j+1])
            {
                arr[j+1] = arr[j];
                arr[j] = key;
            }
            else
                break;
        }
    }
}