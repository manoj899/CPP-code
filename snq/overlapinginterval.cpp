#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class interval{
    public:

    int start;
    int end;

       interval(int start,int end){
           this->start =start;
           this->end = end;

       }
       bool operator < (const interval & o) const
       {
           return this ->start <o.start;
       }
};


void overlappinginterval(vector<int>& start,vector<int>& ends){

    vector<interval> intvs;

    for(int i=0;i<start.size();i++){
        
        interval intv(start[i], ends[i]);
        intvs.push_back(intv);
    }

    sort( intvs.begin(),intvs.end() );

    stack<interval> st;
    st.push(intvs[0]);

    for(int i=1;i<intvs.size();i++){
        if(intvs[i].start<= st.top().end)
        {
            st.top().end = max(st.top().end intvs[i].end);
        }
        else
        {
            st.push(intvs[i])
        }
    }
}