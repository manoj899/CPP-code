#include<iostream>
#include<vector>
#include<stack>
#include<cmath>

using namespace std;

bool hasDuplicate(string& str){
    stack<char> st;

    for(int i=0; i< str.size(); i++){

        char ch = str[i];
        if(ch == ')'){

            if(st.top() == '('){
                return true;
            }
            else{
                while(st.top() != '('){
                    st.pop();
                }
                st.pop(); // to remove opening  '(' symbol too
            }
        }
        else{
            st.push(ch);
        }
    }

    return false;
}

bool isbalanced(string exp){

    stack<char> st;

    for(int i=0; i<exp.size(); i++){

        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){

           st.push(exp[i]);
        }
        else if(exp[i] == ')')
        {
            if(st.size() == 0 || st.top() != '(')
            {
                return false;
            }
            else{
                     st.pop();
            }
        }
        else if(exp[i] == '}')
        {
            if(st.size() == 0 || st.top() != '{')
            {
                return false;
            }
            else{
                     st.pop();
            }
        }
        else if(exp[i] == ']')
        {
            if(st.size() == 0 || st.top() != '[')
            {
                return false;
            }
            else{
                     st.pop();
            }
        }
    }
    if(st.size() >0)
    {
        return false;
    }
    else{
        return true;
    }
}

vector<int> NGE1(vector<int> arr){
// left to right
// here it is dealing with index in stack
    vector<int> res(arr.size());
    stack<int> st;

    for(int i=0; i< arr.size(); i++){

        while(st.size() > 0 && arr[st.top()] < arr[i])
        {
               res[st.top()] = arr[i];
               st.pop();    
        }

        st.push(i);
    }

    while(st.size() > 0)
    {
        res[st.top() ] = -1;
        st.pop();
    }

    return res;
/* this is O(n)  no of push and pop are equal i,e n */
}

vector<int> NGE2(vector<int> arr){
//  right to left
/* --> stack get pop untill stack size is 0 
 -->  or all smaller element get pop
 -->    if element are not able  to pop its next element , it mean its nge;
     */

    vector<int> res(arr.size());
    stack<int> st;

    res[arr.size() -1]  = -1;
    st.push(arr[arr.size() -1]);

    for(int i = arr.size() -2; i >= 0; i--)
    {
        while(st.size() >0 && arr[i] > st.top()){
        st.pop();
        }

        res[i] = st.size()==0? -1: st.top();//for filling corresponding places
        st.push(arr[i]);

       
    } return res;
}

// vector<int> nser(vector<int> arr){


//     stack<int> st;
//     vector<int> res;

//     res[arr.size()-1] = -1;

//     for(int i = 0; i< arr.size()-1; i++){

//         if( st.top() < arr[i]){

//             st.push();
//         }
//         else{
//                     int c =i;
//             while(st.top() > arr[i] && st.size() >0){
                
//                 res[c] = arr[i];
//                 c--; // here problem occue that how to access pre index of result
//                 // thats why we have to do it by putting index in stack
//                 st.pop();
//             }
//         }
//     }
// }

vector<int> nser(vector<int> bars)
{
    vector<int> rb(bars.size());
    stack<int> st;

    for(int i=0; i<bars.size(); i++)
   {        // smallest element on right
        while(st.size() > 0 && bars[st.top()] > bars[i])
        {
            bars[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    while(st.size() >0)
    {
        rb[st.top()] = bars.size();
        st.pop();
    }

    return rb;
}

int LargestArHistogram(vector<int>& bars)
{
    vector<int> rb (bars.size());   // right boundary
    vector<int> lb (bars.size());   // left boundary

    stack<int> st;   // storing index in stack 

/*to deal with histogram you have to deal with index of 
  smaller left side elementelement (lb) & smaller right sideelement(rb)
  bcoz these index help in finding the width of a single bar...*/

    for(int i=0; i<bars.size(); i++)
   {        // smallest element on right 
        while(st.size() > 0 && bars[st.top()] > bars[i])
        {
            rb[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    while(st.size() >0)
    {
        rb[st.top()] = bars.size();
        st.pop();
    }

    for(int i = bars.size() -1; i>= 0; i--)
    {  // smallest element on left
        while(st.size() > 0 && bars[st.top()] > bars[i])
        {
            lb[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    while(st.size() >0)
    {
        lb[st.top()] = -1;
        st.pop();
    }
   
   // finding width and area 
   int max =0;
   for(int i = 0; i< bars.size(); i++){

       int width = rb[i] - lb[i] -1;
       int area = bars[i] * width;

       if(area > max)
       {
           max = area;
       }
   }
  return max;

}

vector<int> maxInSlidingWindow(vector<int> arr,int k){

    vector<int> ng(arr.size());
    stack<int> st;

    for(int i=0; i< arr.size(); i++){

        while(st.size() >0 && arr[st.top()] < arr[i])
        {  cout<<"!!!!"<<endl;
            ng[st.top()] = i;
             st.pop();
        }

         st.push(i);                 
    }

    while(st.size()>0){

        // cout<<"sttttt"<<endl;
            ng[st.top()] = arr.size();
            st.pop();
        }

       
       int i=0; 
       int j =0;
       vector<int> res(arr.size() -k +1); 
        while(i < res.size())
        {        
                if(i > j){

                     j = i;
                }  
            
             // j shouldnt exceed window size 
                while(ng[j] < i+k){
            // if nge lies inside window then jump j to that pt.    
                j =ng[i];
                // cout<<"****";
                cout<<ng[j];
                // cout<<"  "<<i+k;

                }

        // nge lies outside window then tum hi to answer ho hmare(that current index)     
                res[i] = arr[j];
                i++;
                // cout<<"))))";
        }
   return res;
}

void ddid(string &str){
    stack<int> st;
    int val =0;

    for(int i=0; i<= str.length(); i++)
    {
        st.push(val++);
        if(i == str.length() || str[i] == 'i'){
            while(st.size() >0){
                cout<<st.top();
                st.pop();
            }
        }
    }
}

int getpriority(char op)
{
    switch(op)
    {
        
        case '+':
        case '-': 
                 return 1;
                 break;
                 
        case '*':
        case '/':
        case '%': 
                 return 2;
                 break;
                 
        case '^': 
                 return 3;
                 break;
        default:
             break;
    }
}

int getvalue(int v1, int v2, char op)
{
    switch(op)
    {
        case '+': 
                 return v1+v2;
                 break;
                 
        case '-': 
                 return v1-v2;
                 break;
                 
        case '*': 
                 return v1*v2;
                 break;
                 
        case '/': 
                 return v1/v2;
                 break;
                 
        case '%': 
                 return v1%v2;
                 break;
                 
        case '^': 
                 return pow(v1,v2);
                 break;
        default:
             break;
    }
}

// int infix123(string exp)
// {
//     stack<char> os;
//     stack<int> vs;

//     for(int i =0; i< exp.size(); i++)
//     {
//         char ch = exp[i];
//         if(ch >= '0' && ch <= '9')//operand
//         {
//             vs.push(ch -48);
//         }
//         else if( ch == '(')
//         {
//             os.push(ch);
//         }
//         else if(ch ==')')
//         {
//             while(os.top() != '(')
//             {
//                 int v2 = vs.top(); vs.pop();
//                 int v1 = vs.top(); vs.pop();
//                 char op = os.top(); os.pop(); 
//                 int res = getvalue(v1, v2, op);
//                 vs.push(res);
//             }
//             os.pop();
//         }
//         else{
//             while(os.size() != 0 && os.top() != '(' &&
//             getpriority(os.top()) >= getpriority(ch))
//             {
//                 int v2 = vs.top(); vs.pop();
//                 int v1 = vs.top(); vs.pop();
//                 char op = os.top(); os.pop(); 
//                 int res = getvalue(v1, v2, op);
//                 vs.push(res);
//             }

//             os.push(ch);
//         }
//     }

//     while(os.size() != 0)
//     {
//           int v2 = vs.top(); vs.pop();
//                 int v1 = vs.top(); vs.pop();
//                 char op = os.top(); os.pop(); 
//                 int res = getvalue(v1, v2, op);
//                 vs.push(res);
//     }

//     return vs.top();
// }



int infix123(string exp)
{
    stack<char> os;
    stack<int> vs;
    stack<string> post;
    stack<string> pre;

    for(int i =0; i< exp.size(); i++)
    {
        char ch = exp[i];
        if(ch >= '0' && ch <= '9')//operand
        {
            vs.push(ch -48);
            post.push(to_string(ch-48));
            pre.push(to_string(ch-48));
        }
        else if( ch == '(')
        {
            os.push(ch);
        }
        else if(ch ==')')
        {
            while(os.top() != '(')
            {
                int v2 = vs.top(); vs.pop();
                int v1 = vs.top(); vs.pop();
                char op = os.top(); os.pop(); 
                int res = getvalue(v1, v2, op);
                vs.push(res);

                string postv2 = post.top(); post.pop();
                string postv1 = post.top(); post.pop();
                post.push(postv1 + postv2 + op);

                string prev2 = pre.top(); pre.pop();
                string prev1 = pre.top(); pre.pop();
                pre.push(op + prev1 + prev2);
            }
            os.pop();
        }
        else{
            while(os.size() != 0 && os.top() != '(' &&
            getpriority(os.top()) >= getpriority(ch))
            {
                int v2 = vs.top(); vs.pop();
                int v1 = vs.top(); vs.pop();
                char op = os.top(); os.pop(); 
                int res = getvalue(v1, v2, op);
                vs.push(res);

                string postv2 = post.top(); post.pop();
                string postv1 = post.top(); post.pop();
                post.push(postv1 + postv2 + op);

                string prev2 = pre.top(); pre.pop();
                string prev1 = pre.top(); pre.pop();
                pre.push(op + prev1 + prev2);
            }

            os.push(ch);
        }
    }

    while(os.size() != 0)
    {
          int v2 = vs.top(); vs.pop();
                int v1 = vs.top(); vs.pop();
                char op = os.top(); os.pop(); 
                int res = getvalue(v1, v2, op);
                vs.push(res);

                string postv2 = post.top(); post.pop();
                string postv1 = post.top(); post.pop();
                post.push(postv1 + postv2 + op);

                string prev2 = pre.top(); pre.pop();
                string prev1 = pre.top(); pre.pop();
                pre.push(op + prev1 + prev2);
    }

    cout<<"Post order = "<<post.top() <<endl;
    cout<<"Pre order = "<< pre.top() <<endl;
    return vs.top();
}

int postfix123(string exp)
{
    stack<int> vs;
    stack<string> pre;
    stack<string> in;
    

    for(int i =0; i< exp.size(); i++)
    {
        char ch = exp[i];

        if(ch >= '0' && ch <= '9')
        {
            vs.push(ch -48);
            pre.push(to_string(ch-48));
            in.push(to_string(ch-48));
        }
        else{
            int v2 = vs.top(); vs.pop();
            int v1 = vs.top(); vs.pop();
            int res = getvalue(v1, v2,ch);
            vs.push(res);

            string prev2 = pre.top(); pre.pop();
            string prev1 = pre.top(); pre.pop();
            pre.push(ch+ prev1 + prev2);

            string inv2 = in.top(); in.pop();
            string inv1 = in.top(); in.pop();
            in.push("(" + inv1 + ch +inv2 +")");

        }
    }
    cout<<"Preorder = "<<pre.top() <<endl; 
    cout<<"Inorder = "<<in.top() <<endl;
    return vs.top();
}

vector<int> slidingInterval(vector<int> ){
    stack<int> st;
    
}
int main(int argc,char** argv){

    // string s = "(a + (b+c)))";
   /// cout<<hasDuplicate(s)<<endl ;

    // string p = "[a+(b+c)}]";
    // cout<<isbalanced(p);

    // vector<int> arr {5,9,8,3,2,7,16,4,14,19,3};
    // vector<int> res = nser(arr);
    // for(int i=0; i< res.size(); i++)
    // {
    //     cout<<res[i] <<" ";
    // }

     vector<int> bars {6 , 2, 5, 4, 5, 1,6};
     
     int max = LargestArHistogram(bars);
     cout<<max<<endl;

    // vector<int> arr{5,9,3,1,8,6,7,2,11,4,17,9};
    // vector<int> res = maxInSlidingWindow(arr,5);
    // for(int i=0; i<res.size(); i++)
    // {
    //     cout<<res[i]<<" ";
    // }
    // cout<<endl;

    // string s = "ddd";
    // ddid(s);
    // // cout<<endl;
    // string exp = "8+3^(4/(3-1))";
    // cout<<infix123(exp)<<endl;

    // string post = "324*1/-32";
    // cout<<postfix123(post)<<endl;

}