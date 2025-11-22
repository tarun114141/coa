#include<iostream>
using namespace std;


class C_queue{
    int *arr;
    int curr_size;
    int rear,front;
   
    int capacity;

public:
    C_queue(int size){
        this->capacity=size;
        arr=new int[capacity];
        front=0;
        rear=-1;
        curr_size=0;

    }
    void Push(int data){
        if(curr_size==capacity){
            cout<<"Can't push queue if full"<<endl;
            return;
        }

        rear=(rear+1)%capacity;
        arr[rear]=data;
        curr_size++;

    }


    void Pop(){
        if(empty()){
            cout<<"The queue is already empty cant pop"<<endl;
            return;
        }
        front=(front+1)%capacity;
        curr_size--;


    }

    bool empty(){
        return curr_size==0;
    }


   void Print(){
        if(empty()){
        cout<<"Queue is empty\n";
        return;
        }
    int temp=front;
    for (int i=0;i<curr_size;i++) {
        cout<<arr[temp]<<" ";
        temp=(temp+1) %capacity;
        }
    cout<<endl;
    }

};

int main() {
    int size;
    cout << "Enter queue capacity: ";
    cin >> size;

    C_queue q(size);

    int choice, value;

    do {
        cout << "\n====== Circular Queue Menu ======\n";
        cout << "1. Push (Insert)\n";
        cout << "2. Pop (Remove)\n";
        cout << "3. Display Queue\n";
        cout << "4. Check if Empty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                q.Push(value);
                break;

            case 2:
                q.Pop();
                break;

            case 3:
                q.Print();
                break;

            case 4:
                if (q.empty())
                    cout << "Queue is empty.\n";
                else
                    cout << " Queue is not empty.\n";
                break;

            case 5:
                cout << " Exiting program.\n";
                break;

            default:
                cout << " Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}