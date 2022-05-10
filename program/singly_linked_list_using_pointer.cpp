#include<iostream>
#include<iostream>
using namespace std;

class Singlylist{
    int data;
    Singlylist *next;
public:
    void insertstart(Singlylist **Head_ref, int item){
        Singlylist *slist = new Singlylist();
        cout<<"slist address: "<<slist<<endl;
        slist->data = item;
        slist->next = *Head_ref;
        *Head_ref = slist;
        cout<<"Slist->data: "<< slist->data<<"\t";
        cout<<"Slist->next: "<< slist->next<<"\t"<<endl;
        cout<<"*Head_ref: "<< *Head_ref<<endl;
        cout<<endl;
    }
    void insertafter(Singlylist **Head_ref,int after, int item){
        Singlylist *ptr = *Head_ref;
        Singlylist *slist = new Singlylist();
        cout << "slist address: " << slist << endl;
        slist->data = item;
        while(ptr->data != after){
            ptr = ptr->next;
        }
        slist->next = ptr->next;
        ptr->next = slist;
        cout << "Slist->data: " << slist->data << "\t";
        cout << "Slist->next: " << slist->next << "\t" << endl;
        cout << "previous->next: " << ptr->next << "\t" << endl;
        cout << "*Head_ref: " << *Head_ref << endl;
        cout << endl;
    }

    void insertbefore(Singlylist **Head_ref, int before, int item){
        Singlylist *slist = new Singlylist();
        Singlylist *ptr = *Head_ref;
        Singlylist *preptr = ptr;
        cout << "Address of slist: " << slist << endl;
        slist->data = item;
        while(ptr->data != before){
            preptr = ptr;
            ptr = ptr-> next;
        }
        slist->next = ptr;
        preptr->next = slist;
        cout << "Slist->data: " << slist->data << "\t";
        cout << "Slist->next: " << slist->next << "\t" << endl;
        cout << "previous->next: " << preptr->next << "\t" << endl;
        cout << "*Head_ref: " << *Head_ref << endl;
        cout << endl;

    }
    void insertend(Singlylist **Head_ref, int item){
        Singlylist *slist = new Singlylist();
        Singlylist *ptr = *Head_ref;
        cout<<"slist address: "<<slist<<endl;
        slist->data = item;
        slist->next = NULL;
        if(*Head_ref == NULL) *Head_ref = slist;
        while(ptr->next != NULL) ptr = ptr->next;
        ptr->next = slist;
        cout << "Slist->data: " << slist->data << "\t";
        cout << "Slist->next: " << slist->next << "\t" << endl;
        cout << "previous->next: " << ptr->next << "\t" << endl;
        cout << "*Head_ref: " << *Head_ref << endl;
        cout << endl;
    }

    void removestart(Singlylist **Head_ref){
        Singlylist *ptr = *Head_ref;
        *Head_ref = ptr->next;
        delete ptr;
    }
    void removeafter(Singlylist **Head_ref, int after){
        Singlylist *ptr = *Head_ref;
        Singlylist *preptr = ptr;
        while(preptr->data != after){
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        delete ptr;
    }
    void removebefore(Singlylist **Head_ref, int before){
        Singlylist *postptr = *Head_ref;
        Singlylist *ptr = postptr;
        Singlylist *preptr = ptr;
        while(postptr->data != before){
            preptr = ptr;
            ptr = postptr;
            postptr = postptr->next;
        }
        preptr->next = postptr;
        delete ptr;
    }
    void removeend(Singlylist **Head_ref){
        Singlylist *ptr = *Head_ref;
        Singlylist *preptr = *Head_ref;
        while(ptr->next != NULL){
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
        delete ptr;
    }
    void display(Singlylist *node){
        cout << "item in the list are: " << endl;
        while(node != NULL){
            cout << node->data << "\t";
            node = node->next;
        }
        cout << endl;
    }

};

int main(){
    Singlylist s1;
    Singlylist *Head = NULL;
    int val, after, before;
    char ch;
    cout << "1) INSERT START" << endl;
    cout << "2) INSERT AFTER" << endl;
    cout << "3) INSERT BEFORE" << endl;
    cout << "4) INSERTEND" << endl;
    cout << "5) REMOVE START" << endl;
    cout << "6) REMOVE AFTER" << endl;
    cout << "7) REMOVE BEFORE" << endl;
    cout << "8) REMOVE END" << endl;
    cout << "9) Display list" << endl;
    cout << "q) EXIT" << endl;
    do{
        cout << "Enter choice: ";
        cin >> ch;
        switch(ch){
        case '1':
            cout << "Enter the first value: " << endl;
            cin >> val;
            s1.insertstart(&Head, val);
            break;
        case '2':
            cout << "Enter the value after which you want to enter item: ";
            cin >> after;
            cout << "Enter the value you want to add: ";
            cin >> val;
            s1.insertafter(&Head, after, val);
            break;
        case '3':
            cout << "Enter the value before which you want to add item: ";
            cin >> before;
            cout << "Enter the value: ";
            cin >> val;
            s1.insertbefore(&Head, before, val);
            break;
        case '4':
            cout << "Enter the last value: " << endl;
            cin >> val;
            s1.insertend(&Head, val);
            break;
        case '5':
            s1.removestart(&Head);
            break;
        case '6':
            cout << "Enter the value after which you want to delete item: ";
            cin >> after;
            s1.removeafter(&Head, after);
            break;
        case '7':
            cout << "Enter the value before which you want to delete item: ";
            cin >> before;
            s1.removebefore(&Head, before);
            break;
        case '8':
            s1.removeend(&Head);
            break;
        case '9':
            s1.display(Head);
            break;
        case 'q':
            break;
        default:
            cout << "Please enter the correct choice" << endl;
            break;
        }
    }while(ch != 'q');
    return 0;
}
