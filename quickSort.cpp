#include <iostream>
using namespace std;

int partition(int* arr, int s, int e);
void quickSort(int* arr, int s, int e);


int main()
{
    int size = 10;
    int arr[] = {5, 4, 7, 3, 1, 8, 3, 12, 9, 11};

    quickSort(arr, 0, size - 1);

    for(int i=0; i<10; ++i)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

// 0 1 2 3 4 5 6   7   8  9
// 1 2 5 6 7 7 9  15  10
//         s                 
//       e
// i   
/*
q(0, 9);  pI = 4;
q(0, 4);  pI = 0;
q(2, 4);  pI = 3;

*/
void quickSort(int* arr, int s, int e)
{

    if(s == e)
        return;

    int pI = partition(arr, s, e);

    
    quickSort(arr, s, pI);
    quickSort(arr, pI+2, e);
}

int partition(int* arr, int s, int e) // indoex of pivot
{   
    int temp;
    int pIndex = s;

    while(1)
    {
        while(arr[s] <= arr[pIndex]) // pivot == 7
        {
            ++s;
            if( s == e )
                break;
        }
        
        while(arr[e] > arr[pIndex])
            --e;

        if(s >= e)
        {
            break;
        }

        temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
    }

    temp = arr[pIndex];
    arr[pIndex] = arr[e];
    arr[e] = temp;
    return e-1;
}