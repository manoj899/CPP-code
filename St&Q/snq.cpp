#include <iostream>
#include<vector>

using namespace std;

class kstacks
{
    private:
        int cap;
        int* da;
        int* pa;
        int* sha;
        int fh;
    public:
        kstacks(int cap, int k)
        {
            this->cap = cap;
            this->da = new int[cap];
            this->pa = new int[cap];
            this->sha = new int[k];
            this->fh = 0;

            for(int i = 0; i < cap; i++)
            {
                da[i] = 0;
                pa[i] = i + 1;
            }
            pa[cap - 1] = -1; 

            for(int i = 0; i < k; i++)
            {
                this->sha[i] = -1;
            }
        }

        bool isFull()
        {
            return fh == -1;
        }

        bool isEmpty(int s)
        {
            return sha[s] == -1;
        }

        void push(int val, int s)
        {
            if(isFull())
            {
                cout << "Stack overflow" << endl;
            }
            else
            {
                int temp = fh;

                fh = pa[fh]; // rf in free
                pa[temp] = sha[s]; // af1 in s
                sha[s] = temp; // af2 in s

                da[temp] = val;
            }
        }

        void pop(int s)
        {
            if(isEmpty(s))
            {
                cout << "Stack underflow" << endl;
                return;
            }
            else
            {
                int temp = sha[s];

                sha[s] = pa[temp];
                pa[temp] = fh;
                fh = temp;

                da[temp] = 0;
            }
        }

        int top(int s)
        {
            if(isEmpty(s))
            {
                cout << "Stack underflow" << endl;
                return -1;
            }
            else
            {
                return da[sha[s]];
            }
        }
};

void petrolpumps(vector<int>& oil, vector<int>& dist)
{
    int i = 0; int j = 0;
    int spare = 0;
    while(i < oil.size())
    {
        if(spare + oil[j] >= dist[j])
        {
            spare = spare + oil[j] - dist[j];
            j = (j + 1) % oil.size();

            if(j == i)
            {
                cout << i << endl;
                return;
            }
        }
        else
        {
            if(j < i)
            {
                cout << "No solution." << endl;
                return;
            }
            spare = 0;
            i = j + 1;
            j = i;
        }
    }
    
    cout << "No solution." << endl;
}


int main(int argc, char** argv)
{
//     kstacks ks(10, 3);

//     ks.push(10, 0);
//     ks.push(20, 0);
//     ks.push(30, 1);
//     ks.push(40, 2);
//     ks.push(50, 2);
//     ks.push(60, 1);
//     ks.push(70, 1);
//     ks.push(80, 2);
//     ks.push(90, 0);
//     ks.push(100, 0);
//     ks.push(110, 0);

//     for(int i = 0; i <= 2; i++)
//     {
//         cout << i << ": ";
//         while(ks.isEmpty(i) == false)
//         {
//             int val = ks.top(i); ks.pop(i);
//             cout << val << " ";
//         }
//         cout << endl;
//     }
    vector<int> o1 {6, 4, 8, 2, 3, 3, 7, 1, 2};
    vector<int> d1 {5, 5, 2, 4, 4, 6, 7, 2, 1};
    petrolpumps(o1, d1);
}




