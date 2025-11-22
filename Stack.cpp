#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }

};
class Stack{
    public:
        Node* head;
        Node* tail;
    public:
    Stack(){
        head=tail=NULL;
    }

    //Insert Functions_______________________________________________________________
    void Push(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
              
        }else{
            newNode->next=head;
            head=newNode;
        }
    }

    void Pop() {
        if (head == NULL) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == NULL) tail = NULL;  
            delete temp;
            return;

    
    }

    void Print(){
        Node* temp=head;
        while(temp!=NULL){
        cout<<temp->data<< ' ';
        temp=temp->next;
        }
        cout<<endl;
    }


    int Top(){
    if (head==NULL){
        cout<<"Stack is underflowed"<<endl;
        return -1; 
    }
    return head->data;
}


};


int main(){
    Stack S;
    S.Push(20);
    S.Push(10);
    S.Push(30);
    S.Push(90);
    S.Print();
    S.Pop();
    S.Print();
    cout<<S.Top()<<endl;

    return 0;


}