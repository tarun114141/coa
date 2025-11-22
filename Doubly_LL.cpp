#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
        Node * pre;
        Node(int val){

            data=val;
            next=pre=NULL;
        }

};

class D_LList{
     public:
    Node * head;
    Node * tail;
    D_LList(){
        head=tail=NULL;

    }
   

    void Print(Node* h){
        Node* temp=h;
        while(temp!=NULL){
            cout<<temp->data<<"<=>";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void push_front(int val){
        Node * newNode= new Node(val);

        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head->pre=newNode;
            head=newNode;
        }

    }

    void push_back(int val){
        Node * newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->pre=tail;
            tail->next=newNode;
            tail=newNode;
        }

    }

    void pop_front(){
        if(head==NULL){
            return;
        }
        Node * temp=head;
        head=head->next;
        if(head!=NULL){
            head->pre=NULL;
            temp->next=NULL;
            delete temp;
        }
    }

    void pop_back(){
        if(head==NULL){
            return;
        }
        Node * temp=tail;
        tail=tail->pre;
        if(tail!=NULL){
            tail->next=NULL;
        }
        tail->pre=NULL;
        delete temp;
    }
    
    void Sort(){
        if (head == NULL || head->next == NULL) {
            return;
            }
        Node* i;
        Node* j;
        for (i=head;i->next!=NULL;i=i->next) {
            for (j=i->next;j!=NULL;j =j->next) {
                if (i->data>j->data) {
                    int temp=i->data;
                    i->data=j->data;
                    j->data=temp;
                    }
                }
            }
        }
    
        void Delete(int val) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    // Case 1: delete head
    if (head->data == val) {
        pop_front();   // reuse existing function
        cout << "Deleted " << val << " from list" << endl;
        return;
    }

    // Case 2: delete tail
    if (tail->data == val) {
        pop_back();    // reuse existing function
        cout << "Deleted " << val << " from list" << endl;
        return;
    }

    // Case 3: delete middle node
    Node* temp = head->next;
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value not found in list" << endl;
        return;
    }

    // unlink the node
    temp->pre->next = temp->next;
    if (temp->next != NULL) {
        temp->next->pre = temp->pre;
    }

    delete temp;
    cout << "Deleted " << val << " from list" << endl;
    }
    
    
    int Search(int val){
        Node* temp=head;
        int i=0;     
        while(temp!=NULL){
            if(temp->data==val){
                return i;
            }
            temp=temp->next;
            i++;
        }
        return -1;

    }


    Node* Merge(Node* h1,Node* h2){
        if(h1==NULL||h2==NULL){
            return h1==NULL? h2:h1;
        }

        if(h1->data<=h2->data){
            h1->next=Merge(h1->next,h2);
            return h1;
        }else{
            h2->next=Merge(h1,h2->next);
            return h2;
        }


    }

               

};



int main(){
    D_LList L1, L2, L3, obj;
    int ch,val;

    do {
        cout<<"==== MENU ===="<<endl;
        cout<<"1. Insert into first linked list"<<endl;
        cout<<"2. Insert into second linked list"<<endl;
        cout<<"3. Sort first linked list"<<endl;
        cout<<"4. Sort second linked list"<<endl;
        cout<<"5. Merge first and second linked list"<<endl;
        cout<<"6. Search in merged list"<<endl;
        cout<<"7. Print all lists"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter choice: "<<endl;
        cin>>ch;

        switch(ch){
            case 1:
                int n;
                cout<<"Enter how many nodes you want to enter"<<endl;
                cin>>n;
                while(n--){
                    cout<<"Enter value: ";
                    cin>>val;
                    L1.push_back(val);
                }
                break;

            case 2:
                int m;
                cout<<"Ente how many nodes you want to enter"<<endl;
                cin>>m;
                while(m--){
                    cout<<"Enter value: ";
                    cin>>val;
                    L2.push_back(val);
                }
                break;

            case 3:
                L1.Sort();
                cout<<"First list sorted."<<endl;
                break;

            case 4:
                L2.Sort();
                cout<<"Second list sorted."<<endl;
                break;

            case 5:
                L1.Sort();
                L2.Sort();
                L3.head=obj.Merge(L1.head,L2.head);
                cout<<"Lists merged."<<endl;
                break;

            case 6:
                cout<<"Enter value to search: "<<endl;
                cin>>val;
                if(L3.head==NULL){
                    cout<<"Merged list is empty."<<endl;
                }else{
                    int pos=L3.Search(val);
                    if(pos==-1) cout<<"Not found."<<endl;
                    else cout<<"Found at position "<<pos<<endl;
                }
                break;

            case 7:
                cout<<"First List: "; obj.Print(L1.head);
                cout<<"Second List: "; obj.Print(L2.head);
                cout<<"Merged List: "; obj.Print(L3.head);
                break;
               case 8:{
                int v;
                cout<<"Enter from which list you want to delete"<<endl;
                cin>>v;
                switch(v){
                    case 1:{
                        int val;
                        cout<<"Enter the value you want to delete: ";
                        cin>>val;
                        cout<<"The value has been deleted"<<endl;
                        L1.Delete(val);
                        obj.Print(L1.head);
                    break;
                    }
                    case 2:{
                        int val;
                        cout<<"Enter the value you want to delete: ";
                        cin>>val;
                        cout<<"The value has been deleted"<<endl;
                        L2.Delete(val);
                        obj.Print(L2.head);
                    break;
                    }
                    case 3:{
                        int val;
                        cout<<"Enter the value you want to delete: ";
                        cin>>val;
                        cout<<"The value has been deleted"<<endl;
                        L3.Delete(val);
                        obj.Print(L3.head);
                    break;
                    }
                }
                break;
               }
        
            

            case 0:
                cout<<"+++++++++++Program has ended++++++++++++"<<endl;
                break;

            default:
                cout<<"Invalid choice"<<endl;
        }
    }while(ch!=0);

    return 0;
}