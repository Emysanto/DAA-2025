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
    int j=0;
    for(int i=0;i<a;i++)
    { j=0;
        while(j!=i)
        {if(b[i]<b[j] || b[j]==b[i])
        {c=b[j];
        b[j]=b[i];
        b[i]=c;}
        j++;
        }
        
        
    }
    cout<<"The sorted array by insertion sort is:";
     for(int i=0;i<a;i++)
    {
        cout<<b[i]<<" ";
    }
    
    
    return 0;
}
