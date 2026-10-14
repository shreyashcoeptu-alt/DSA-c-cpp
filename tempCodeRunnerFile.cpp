#include <iostream>
#include <vector>
using namespace std;


int queue[100];
int front = 0;
int rear = -1;

void enqueue(int x){
    rear++;
    queue[rear] = x;
}

void dequeue(){
    if(front > rear){
        cout << "Queue is Empty!"
    }else {
        cout << "Deleted :" << queue[front] << endl;
        front++;
    }
}

void display(){
    if(front > rear){
        cout<< "Queue is Empty\n";
    }else {
        for(int i = front; i < rear; i++){
            cout << queue[i] << " ";
        }
        cout << endl;
    }

}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
   

    display();
    dequeue();
    dequeue();
    display();

    return 0;

}