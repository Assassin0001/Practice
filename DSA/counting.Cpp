#include <iostream>
using namespace std;

void printCounting(int);

int main(){
    int n;
    cout<<"Enter number for counting:";
    cin>>n;
    printCounting(n);
    return 0;
}

void printCounting(int n){
    int m =n;
    cout<<"In descending order:-"<<endl;
    while(m!=0){
        cout<<m<<" ";
        m--;
    }
    cout<<endl;
    cout<<"In ascending order:-"<<endl;
    int i=1;
    while(i<=n){
        cout<<i<<" ";
        i++;
    }
}