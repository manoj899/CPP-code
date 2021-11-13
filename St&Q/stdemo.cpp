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

        bool operator<(const Interval& o) const
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






