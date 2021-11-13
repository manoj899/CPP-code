#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool findme(int n,int k,int x,int y){
    vector<int> arr(n,0);
    unordered_map<int,int> mp;
    for(int i=x; i< n; i = i+k>n?((i+k)%n):(i+k)){
        if(arr[i] == 0)
         { if(i == y){
            //  cout<<i<<endl;
                return true;
            }
            // cout<<i<<endl;
            arr[i]++;
         }
        else if(arr[i] != 0){
            // cout<<i<<endl;
            return false;
        }
        
        if(i == n-1){
            i =0;
        }
    }
}


int main() {
    
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k,x,y;
        cin>>n>>k>>x>>y;
        // scanf("%d %d %d %d",&n,&k,&x,&y);
        cout <<findme(n,k,x,y);
    }
	// your code goes here
	return 0;
}
