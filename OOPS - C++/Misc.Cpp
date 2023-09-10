#include <iostream>
using namespace std;

struct student{
    int id;
    double marks;
    string name;
};

class A{
  int a = 2;
  int b = 4;

  public:
    //friend function
    friend int mul(A k){
      return (k.a * k.b);
    }
};

int main(){
  // Greedy Alignment | Padding
  student s1;
  s1.name = "A";
  s1.id = 154;
  s1.marks = 8.68;
  cout<<sizeof(s1)<<endl;

  // Friend Function
  A obj;
  int res = mul(obj);
  cout<<res<<endl;
  return 0;
}