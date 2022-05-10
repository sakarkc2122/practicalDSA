#include<iostream>
using namespace std;

int fibonacci (int number)
{
    if (number == 0) return 0;
    else if (number==1) return 1;
    else return (fibonacci(number-1)+ fibonacci(number-2));
}
int main(){
    cout << fibonacci(5);
    return 0;
}
