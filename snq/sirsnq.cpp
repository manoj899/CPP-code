#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

class Interval
{
    public:
        int start;
        int end;

        Interval(int start, int end)
        {
            this->start = start;
            this->end = end;
        }

        bool operator<(const Interval& o) const  // ask syntax
        {
            return this->start < o.start;
        }
};

void overlappingIntervals(vector<int>& starts, vector<int>& ends)
{
    vector<Interval> intvs;

    for(int i = 0; i < starts.size(); i++)
    {
        Interval intv(starts[i], ends[i]);
        intvs.push_back(intv);
    }

    sort(intvs.begin(), intvs.end());
}

void celebrity(vector<vector<bool>> mat)
{
    int left = 0;
    int right = mat.size() - 1;

    while(left < right)
    {
        if(mat[left][right] == true)
        {
            left++; // discard left
        }
        else
        {
            right--;
        }
    }

    // confirmation
    for(int i = 0; i < mat.size(); i++)
    {
        if(i != left)
        {
            if(mat[i][left] == false || mat[left][i] == true)
            {
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << left << endl;
}

bool duplicateBrackets(string str)
{
    stack<char> st;

    for(int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if(ch == ')')
        {
            if(st.top() == '(')
            {
                return true;
            }
            else
            {
                while(st.top() != '(')
                {
                    st.pop();
                }
                st.pop();
            }
        }
        else
        {
            st.push(ch);
        }
    }

    return false;
}

void nge(vector<int>& v)
{
    vector<int> res (v.size(), 0);

    stack<int> st;
    st.push(v[v.size() - 1]);
    res[v.size() - 1] = -1;

    for(int i = v.size() - 2; i >= 0; i--)
    {
        while(st.size() > 0 && v[i] > st.top())
        {
            st.pop();
        }

        // either the stack is empty or the element at top is > v[i]
        res[i] = st.size() > 0? st.top(): -1;
        st.push(v[i]);
    }

    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

void ddid(string s)
{
    stack<int> st;

    int val = 1;
    for(int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        st.push(val++);

        if(ch == 'i')
        {
            while(st.size() > 0)
            {
                cout << st.top();
                st.pop();
            }
        }
    }

    st.push(val++);
    while(st.size() > 0)
    {
        cout << st.top();
        st.pop();
    }

    cout << endl;
}

void stack_demo()
{
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    while(st.size() > 0)
    {
        cout << st.top() << endl;
        st.pop();
    }

    cout << endl;
}

int getpriority(char op)
{
    int rv = -1;

    switch(op)
    {
        case '^':
            rv = 3;
            break;
        case '*':
        case '/':
            rv = 2;
            break;
        case '+':
        case '-':
            rv = 1;
            break;
        default:
            break;
    }

    return rv;
}

int eval(int v1, int v2, char op)
{
    int rv = -1;

    switch(op)
    {
        case '^':
            rv = pow(v1, v2);
            break;
        case '*':
            rv = v1 * v2;
            break;
        case '/':
            rv = v1 / v2;
            break;
        case '+':
            rv = v1 + v2;
            break;
        case '-':
            rv = v1 - v2;
            break;
        default:
            break;
    }

    return rv;
}

int infixeval(string exp)
{
    stack<char> os;
    stack<int> vs;

    for(int i = 0; i < exp.size(); i++)
    {
        char ch = exp[i];

        if(ch == '(')
        {
            os.push(ch);
        }
        else if(ch == ')')
        {
            while(!(os.top() == '('))
            {
                char op = os.top(); os.pop();
                int v2 = vs.top(); vs.pop();
                int v1 = vs.top(); vs.pop();
                vs.push(eval(v1, v2, op));
            }
            os.pop();
        }
        else if(ch >= '0' && ch <= '9')
        {
            // operand
            vs.push(ch - '0');
        }
        else
        {
            // operator
            while(os.size() > 0 && 
                    os.top() != '(' && 
                    getpriority(os.top()) >= getpriority(ch))
            {
                char op = os.top(); os.pop();
                int v2 = vs.top(); vs.pop();
                int v1 = vs.top(); vs.pop();
                vs.push(eval(v1, v2, op));
            }
            os.push(ch);
        }
    }

    while(!(os.size() == 0))
    {
        char op = os.top(); os.pop();
        int v2 = vs.top(); vs.pop();
        int v1 = vs.top(); vs.pop();
        vs.push(eval(v1, v2, op));
    }
    
    return vs.top();
}

string infixtopostfix(string exp)
{
    string postfix;
    stack<char> os;

    for(int i = 0; i < exp.size(); i++)
    {
        char ch = exp[i];

        if(ch == '(')
        {
            os.push(ch);
        }
        else if(ch == ')')
        {
            while(os.top() != '(')
            {
                char op = os.top(); os.pop();
                postfix += op;
            }
            os.pop();
        }
        else if(ch >= '0' && ch <= '9')
        {
            postfix += ch;
        }
        else
        {
            while(os.size() > 0 && 
                  os.top() != '(' && 
                  getpriority(os.top()) >= getpriority(ch))
            {
                char op = os.top(); os.pop();
                postfix += op;
            }
            os.push(ch);
        }
    } 

    while(os.size() > 0)
    {
        char op = os.top(); os.pop();
        postfix += op;
    }

    return postfix;
}



int main(int argc, char** argv)
{
    // stack_demo();
    // ddid("dddddddd");
    // ddid("iiiiiiii");
    // ddid("ddidddid");
    // ddid("iidddidd");

    // vector<int> v {4, 1, 2, 7, 9, 6, 5, 3, 8};
    // nge(v);
    string i1 = "8+2/3+2^1*(1+3)";
    string i2 = "(8+2)/3+2^(1*1+3)";
    cout << "  " << infixeval(i1) << " " << infixtopostfix(i1) << endl;
    cout << "  " << infixeval(i2) << " " << infixtopostfix(i2) << endl;
}





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




#include<iostream>

using namespace std;

class mystack
{
    private:
        int* data;
        int cap;
        int tos;
    public:
        mystack(int cap)
        {
            this->data = new int[cap];
            this->cap = cap;
            this->tos = -1;
        }

        void push(int val)
        {
            if(tos == cap - 1)
            {
                cout << "Stack overflow" << endl;
                return;
            }
            tos++;
            data[tos] = val;
        }

        void pop()
        {
            if(tos == -1)
            {
                cout << "Stack underflow" << endl;
                return;
            }
            data[tos] = 0;
            tos--;
        }

        int top()
        {
            if(tos == -1)
            {
                cout << "Stack underflow" << endl;
                return -1;
            }

            return data[tos];
        }

        int size()
        {
            return tos + 1;
        }

        bool isEmpty()
        {
            if(tos == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

int main(int argc, char** argv)
{
    mystack ms(5);
    ms.push(10);
    ms.push(20);
    ms.push(30);
    ms.push(40);
    ms.push(50);
    ms.push(60);

    while(ms.size() > 0)
    {
        int val = ms.top(); ms.pop();
        cout << val << endl;
    }

    ms.pop();
}









//   graph
