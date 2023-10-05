#include<iostream>
using namespace std;
void swapref(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void swapval(int a, int b){
    int temp;
    temp=a;
    a=b;
    b=temp;

}
int main(){
    int p,q,ch;
    cout<<"Enter two nos : ";
    cin>>p>>q;
        cout<<"\n\tMENU OF SWAP\n\n";
        cout<<"1.Swap with value\n2.Swap with address\n3.Exit";
        cout<<"\n\nEnter you choice : ";
        cin>>ch;
        cout<<"\nBefore swapping values in function p="<<p<<" q="<<q;
        switch(ch){
            case 1:swapval(p,q);break;
            case 2:swapref(&p,&q);break;
        }
        cout<<"\nAfter swapping values in function p="<<p<<" q="<<q;
    }
