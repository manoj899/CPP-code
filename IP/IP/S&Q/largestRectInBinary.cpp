#include<iostream>
#include<stack>
#include<vector>

using namespace std;



    
    
     int largestRectangleArea(vector<int>& bars) {
        
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
   for(int i = 0; i< bars.size(); i++)
   {

       int width = rb[i] - lb[i] -1;
       int area = bars[i] * width;

       if(area > max)
       {
           max = area;
       }
   }
    return max;

  }
    
    
    int maximalRectangle(vector<vector<int>>& matrix)
    {
        
        
        for(int i=1; i< matrix.size(); i++)
        {   for(int j=0; j< matrix[i].size(); j++)
         {
          
            matrix[i][j] = matrix[i-1][j] + matrix[i][j];
            
         }  
        }
        
        int max=0;
        for(int i=0; i<matrix.size(); i++)
        {
            int z = largestRectangleArea(matrix[i]);
            
            if(z > max)
            {
                max = z;
            }
        }
        
        return max;
    }

        
        
   


int main(int argc,char** argv)
{
    vector<vector<int>> matrix{
  {1,0,1,1,1},
  {1,0,1,1,1},
  {1,1,1,1,1},
  {1,0,1,1,1}
    };

    cout<<maximalRectangle(matrix);
}
        
        
        
    