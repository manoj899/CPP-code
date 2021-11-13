#include<iostream>
using namespace std;

void downheapify(int* arr, int i, int last)
{
    int li = 2 * i + 1;
    int ri = 2 * i + 2;

    int mi = i;
    if(li <= last && arr[li] > arr[mi])
        mi = li;

    if(ri <= last && arr[ri] > arr[mi])
        mi = ri;

    if(mi != i)
    {
        swap(arr[mi], arr[i]);
        downheapify(arr, mi, last);
    }
}

void heapsort(int* arr, int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        downheapify(arr, i, n - 1);
    }

    for(int i = 1; i <= n - 1; i++)
    {
        swap(arr[0], arr[n - i]);
        downheapify(arr, 0, n - i - 1);
    }
}

int main(int argc, char** argv)
{
    int arr[] = {7, 8, 1, 3, 6, 2, 4};
    heapsort(arr, 7);
    for(int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}