#include<iostream>
#include<vector>

using namespace std;

ostream& operator<<(ostream& o, const vector<int>& v)const
{
    for(int i = 0; i < v.size(); i++){
        ostream << v[i] << " ";
    }
    ostream << endl;
}

int main(int argc, char** argv)
{
    vector<int> v {1, 2, 3, 4, 5};
    cout << v << endl;
    return 0;
}