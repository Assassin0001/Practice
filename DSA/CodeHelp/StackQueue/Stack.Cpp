#include<stack>
#include<iostream>

using namespace std;

class Stack{
    public:

    int *arr;
    int size;
    int top;

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else cout<<"Stack Overflow"<<endl;
    }

    void pop(){
        if(top >= 0)    top--;
        else cout<<"Stack Underflow"<<endl;
    }
    
    int peek(){
        if(top >= 0 && top < size)  return arr[top];
        else {
            cout <<"Stack is empty"<<endl;
            return -1;
        }
    }

    bool empty(){
        if(top >= 0) return false;
        else true;
    }

};

int main(){
    /*stack<int> s;
    s.push(2);
    s.push(3);
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.empty();
    */

    Stack st(3);
    st.push(3);
    st.push(5);
    st.push(9);
    st.push(10);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek();
    return 0;
}