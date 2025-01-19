#include <iostream>
using namespace std;

int main() {
    int a;
    cout<<"enter the num of inputs required";
    cin>>a;
    int b[a];
    cout<<"enter the inputs";
    for(int i=0;i<a;i++)
    {
        cin>>b[i];
    }
    int c;
    cout<<"enter the key";
    cin >> c;
    int a1=0;
    
    for(int i=0;i<a;i++)
    {if(b[i]==c)
    {
      cout<<"element found";
      break;
    }
    a1++;
    }
    
    
     if(a1==a)
     {
         cout<<"element not found";
     }
    
    
    return 0;
}
