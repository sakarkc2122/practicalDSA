#include <iostream>
#define MAX 10

using namespace std;

class Queue
{
    int Front,Rear;
    int queuee[MAX];
public:
    Queue() {Front = Rear = -1;}  //constructor

    int Enqueue(int item){
        if(Rear == MAX - 1) cout << "QUEUE OVERFLOW" << endl;
        else if(Front == -1 && Rear == -1){
            Front = Rear = 0;
            queuee[Rear] = item;
            cout << "ITEM INSERTED: " << item << endl;
        }
        else{
            Rear++;
            queuee[Rear] = item;
            cout << "ITEM INSERTED: " << item << endl;
        }
        return 0;
    }
    int Dequeue(){
        int item;
        if(Rear == -1) cout << "QUEUE UNDERFLOW" << endl;
        else if(Front == 0 && Rear == 0){
            item = queuee[Front];
            Front = Rear = -1;
            cout << "ITEM DELETED: " << item << endl;
        }
        else{
            item = queuee[Front];
            Front++;
            cout << "ITEM DELETED: " << item << endl;
        }
        return 0;
    }
    int Traverse(){
        if(Front == -1) cout << "QUEUE IS EMPTY" << endl;
        else{
            cout << "QUEUE ITEMS" << endl;
            for(int i = Front; i <= Rear; i++) cout << queuee[i] << "   ";
            cout << endl;
        }
        return 0;
    }
};

int main(){
    Queue obj1;
    int ch, val;
    cout << "1) ENQUEUE" << endl;
    cout << "2) DEQUEUE" << endl;
    cout << "3) TRAVERSE" << endl;
    cout << "4) EXIT" << endl;
    do{
        cout << "Enter choice:";
        cin >> ch;
        if(ch == 1){
            cout<<"Enter value to enqueue:" << endl;
            cin>>val;
            obj1.Enqueue(val);
        }
        else if(ch == 2)obj1.Dequeue();
        else if(ch == 3)obj1.Traverse();
    }while(ch != 4);
    return 0;
}
