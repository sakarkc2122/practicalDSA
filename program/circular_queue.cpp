#include <iostream>
#define MAX 5
using namespace std;

class CQueue{
    int cqueue[MAX];
    int Front, Rear;
public:
    CQueue() {Front = Rear = -1;}

    int Enqueue(int item){
        if((Front == 0 && Rear == MAX-1) || (Rear == (Front-1)%(MAX-1))) cout << "QUEUE OVERFLOW" << endl;
        else if(Front == -1){
            Front = Rear = 0;
            cqueue[Rear] = item;
        }   //insert first element
        else if(Rear == MAX-1 && Front != 0){
            Rear = 0;
            cqueue[Rear] = item;
        }   //insert into empty space after any dequeue
        else{
            Rear++;
            cqueue[Rear] = item;
        }   //enqueue
        return 0;
    }

    int Dequeue(){
        cout << "Element deleted from queue is: " << cqueue[Front] << endl;
        if(Front == -1) cout << "QUEUE UNDERFLOW" << endl;
        if(Front == Rear) Front = Rear = -1;    //if only one element is there
        else if(Front == MAX-1) Front = 0;      //if front point to max size
                                                //then dequeuing means front should point to 0
                                                //which almost similar to empty queue
        else Front++;   //normal dequeue if not overflow condition meet
        return 0;
    }

    int Traverse(){
        if(Front == -1) cout << "QUEUE IS EMPTY" << endl;
        cout << "QUEUE ITEMS" << endl;
        if(Rear >= Front){
            for(int i = Front; i <= Rear; i++) cout << cqueue[i] << "   ";
        }
        else{
            //two conditions if Rear < Front:
            //1. Front to Max
            //2. 0 to Rear this completes the full circle
            for(int i = Front; i < MAX; i++) cout << cqueue[i] << "    ";
            for(int i = 0; i <= Rear; i++) cout << cqueue[i] << "   ";
        }
        cout << endl;
        return 0;
    }
};
int main(){
    CQueue obj1;
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
