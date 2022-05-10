#include <bits/stdc++.h>

using namespace std;

void pointer(int **q){
    cout << "q: " << q << endl;
    cout << "*q: " << *q << endl;
    cout << "&q: " << &q << endl;
    cout << "**q: " << **q << endl;
    cout << "&*q: " << &*q << endl;
    cout << "*&q: " << *&q << endl;
}

int main(void){
    int a = 100;
    int *p= &a;
    cout << "value of a: " << a << endl;
    cout << "address of a: " << &a << endl;

    cout << "value of p: " << p << endl;
    cout << "address of p: " << &p << endl;
    cout << "value of *p: " << *p << endl;
    pointer(&p);
    return 0;
}
/*variable : a
value of variable : a = 100
address of variable : &a = 0x50

pointer variable : p
value of pointer variable : *p = &a i.e. p = 0x50 and *p = 100
address of pointer variable : &p = 0x60

pointer variable : q
int **q = &p
i.e.    q = 0x60
        *q = 0x50
        **q = 100
        &q = new address 0x70
        *&q = &*q = q = 0x60

int ***r = & q
i.e.    r = 0x70
        *r = 0x60
        **r = 0x50
        ***r = 100
        &r = new address 0x80


Finally:

***r            **q             *p              a

address 3       address 2       address 1       100

address 4       address 3       address 2       address 1

### 12 pointer, array, and function declarators (in any combinations)
    modifying an arithmetic, structure, union, or void type in a declaration.


*/
