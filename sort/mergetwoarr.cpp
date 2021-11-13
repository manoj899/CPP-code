#include<iostream>

using namespace std;

int mergetwosortedarrays(int* arr, int lo, int mid, int hi)
{
    int inv = 0;

    int* aux = new int[hi - lo + 1];

    int i = lo;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= hi)
    {
        if(arr[i] < arr[j])
        {
            aux[k++] = arr[i++];
        }
        else
        {
            aux[k++] = arr[j++];
            inv += mid + 1 - i;
        }
    }

    while(i <= mid)
        aux[k++] = arr[i++];

    while(j <= hi)
        aux[k++] = arr[j++];

    for(i = 0; i < hi - lo + 1; i++)
    {
        arr[lo + i] = aux[i];
    }

    return inv;
}

int mergesort(int* arr, int lo, int hi)
{
    if(lo == hi)
    {
        return 0;
    }
    int mid = (lo + hi) / 2;
    int li = mergesort(arr, lo, mid);
    int ri = mergesort(arr, mid + 1, hi);
    int si = mergetwosortedarrays(arr, lo, mid, hi);
    return li + ri + si;
}

int main(int argc, char** argv)
{
    int* arr = new int[8] {2, 9, 6, 1, 4, 3, 7, 5};
    int count = mergesort(arr, 0, 7);
    cout << count << endl;

    for(int i = 0; i < 8; i++)
    {
        cout << arr[i] << endl;
    }
}