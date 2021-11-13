#include<iostream>
#include<stack>

using namespace std;

class mystack
{
    private:
    int* data; // ask ta
    int cap ;
    int tos ;

    public:

  mystack(int cap){

      this->data = new int[cap];
      this->cap = cap;
      this->tos= -1;
  }

  void push(int val){
      tos++;
      data[tos]= val;
  }

  void pop(){
      if(tos == -1){

          cout<<"underflow"<<endl;

      }

      int val = data[tos];

      data[tos] = 0;
      tos--;
      cout<<val;
  }


int size(){
    return tos+1;
}


bool isempty(){
    if(tos ==-1){
        return true;
    }
    else{
        return false;
    }
}

};


  int main()
   {

    mystack ms = new mystack(5);
    ms.push(10);
    ms.push(20);
    ms.push(30);
    ms.push(40);
    ms.push(50);
    ms.push(60);
    
    while(ms.size()>0){

        int val = ms.pop();
        cout<<val;

    }

    ms.pop();
}