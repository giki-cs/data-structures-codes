#include <iostream>
using namespace std;

void mergeSort(int [], int);
void print(int [], int);

int main()
{
    int a[] = {2, 7, 6, 3, 1, 8, 4, 9, 3, 5, 4, 5, 2};
    int n = sizeof(a)/sizeof(a[0]);

    mergeSort(a, n);

    print(a, n);

    return EXIT_SUCCESS;
}

void mergeSort(int a[], int n)
{
    if( n == 1 )
        return;
    
    int m = n/2; 

    int L[m];
    int R[n-m];
    for(int i=0; i<m; ++i)
        L[i] = a[i];
    for(int i=0; i<n-m; ++i)
        R[i] = a[m+i];
    
    mergeSort(L, m); // left sub-array
    mergeSort(R, n-m); // right sub-array

    int i, j, k;
    i = j = k = 0;

    while(i < m && j < n-m)
    {
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            ++i;
        }
        else
        {
            a[k] = R[j];
            ++j;
        }
        ++k;
    }
    while(i < m)
    {
        a[k] = L[i];
        ++i;
        ++k;
    }

    while(j < n-m)
    {
        a[k] = R[j];
        ++j;
        ++k;
    }

}

void print(int a[], int n)
{
    for(int i=0; i<n; ++i)
        cout << a[i] << " ";
    cout << endl;
}