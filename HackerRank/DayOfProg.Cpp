#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter year: "<<endl;
    int year;
    cin>>year;
    string str;
    if(year == 1918)
       str="26.09.1918";
    else if((year%4==0 && (year<1919 || year%100 != 0) || year%400==0))
       str="12.09."+to_string(year);
    else
       str="13.09."+to_string(year);
    cout<<"Date is: "<<str;
    return 0;         
}