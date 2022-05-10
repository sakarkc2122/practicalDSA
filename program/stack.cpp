#include <iostream>
#define SIZE 5

using namespace std;

class Stack
{
    int stack[SIZE], top;
public:

    Stack(){
        top = -1;
    }   //Constructor for initializing top

    int push(int num){
        if(top == SIZE-1){
            cout << "STACK OVERFLOW" << endl;
        }   //Stack is full
        else{
            top++;
            stack[top] = num;
            cout << num << " is push" << endl;
        }   //incrementing top by 1
        return 0; //I want to know this annoying line of code why exist??
                  //I don't want to return anything then simply why can't we ignore it?
                  //why does compiler give warning?
    }
    int pop(){
        int num;
        if(top == -1){
            cout << "STACK UNDERFLOW" << endl;
        }   //Stack is empty
        else{
            num = stack[top];
            top--;
            cout << "ELEMENT DELETED: " << num << endl;
        }   //decreasing top by 1
        return 0;
    }
    int traverse(){
        if(top == -1){
            cout << "STACK IS EMPTY" << endl;
        }
        else{
            cout << "STACK ELEMENTS";
            for(int i = top; i >= 0; i--){
                cout << stack[i] << endl;
            }
        }
        return 0;
    }
    bool Search(int num){
        int i = top;
        //if(top == -1) cout << "there is no element in the stack" << endl;
        for(i; i >= 0; i--){
            if(stack[i] == num){
                return true;
                break;
            }   //return true if the value is present in stack
        }
        return false;   //return false if the value is not present in stack
    }
};

int main()
{
    Stack obj1;
    int ch, val;
    bool test;
    cout << "1) Push in stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Display stack" << endl;
    cout << "4) Search" << endl;
    cout << "5) Exit" << endl;
    do{
        cout << "Enter choice:";
        cin >> ch;
        if(ch == 1){
            cout<<"Enter value to be pushed:" << endl;
            cin>>val;
            obj1.push(val);
        }
        else if(ch == 2)obj1.pop();
        else if(ch == 3)obj1.traverse();
        else if(ch == 4){
            cout << "Enter value to be searched:" << endl;
            cin >> val;
            test = obj1.Search(val);
            if(test == true) cout << val << " is present in stack" << endl;
            else cout << val << " is not present in stack" << endl;
        }
    }while(ch != 5);
    return 0;
}
