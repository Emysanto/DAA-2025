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
    int c=0;
    int j=1;
    while(j!=a)
    {for(int i=0;i<a;i++)
    { if(b[i+1]<b[i] || b[i]==b[i+1])
        {c=b[i];
        b[i]=b[i+1];
        b[i+1]=c;}
        
        }
        j++;
    }
    cout<<"The sorted array by bubble sort is:";
     for(int i=0;i<a;i++)
    {
        cout<<b[i]<<" ";
    }
    
    
    return 0;
}
