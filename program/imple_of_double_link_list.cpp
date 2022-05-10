#include<iostream>
#include<iostream>
using namespace std;

class Doublylist{
    int data;
    Doublylist *next;
    Doublylist *prev;
public:
    void insertstart(Doublylist **Head_ref, int item){
        Doublylist *dlist = new Doublylist();
        Doublylist *ptr = *Head_ref;
        cout<<"dlist address: "<<dlist<<endl;
        dlist->data = item;
        dlist->next = *Head_ref;
        if(*Head_ref == NULL){
            ptr = dlist;
            ptr->prev = NULL;
        }
        else{
            dlist->next = *Head_ref;
            dlist->prev = NULL;
            ptr->prev = dlist;
        }

        *Head_ref = dlist;
        cout << "dlist->prev: " << dlist->prev << "\t";
        cout << "dlist->data: " << dlist->data << "\t";
        cout << "dlist->next: " << dlist->next << "\t"<<endl;
        cout << "*Head_ref: " << *Head_ref << endl;
        cout << endl;
    }
    void display(Doublylist *node){
        cout << "item in the list are: " << endl;
        while(node != NULL){
            cout << node->data << "\t";
            node = node->next;
        }
        cout << endl;
    }

};

int main(){
    Doublylist d1;
    Doublylist *Head = NULL;
    int val;
    char ch;
    cout << "1) INSERT START" << endl;
    cout << "7) Display list" << endl;
    cout << "8) EXIT" << endl;
    do{
        cout << "Enter choice: ";
        cin >> ch;
        switch(ch){
        case '1':
            cout << "Enter the first value: " << endl;
            cin >> val;
            d1.insertstart(&Head, val);
            break;
        case '7':
            d1.display(Head);
            break;
        case '8':
            break;
        default:
            cout << "Please enter the correct choice" << endl;
            break;
        }
    }while(ch != '8');
    return 0;
}
