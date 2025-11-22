#include<iostream>
#include<string>
using namespace std;


class Node{
    public:
        int O_num;
        int NO_p;
        string types;
        string P_s;
        Node* next;
        Node(int n,int p,string t,string s){
            O_num=n;
            NO_p=p;
            types=t;
            P_s=s;
            next=NULL;

        }



};

class C_LL{
    public:
    Node * head;
    Node * tail;
    C_LL(){
        head=tail=NULL;
    }

   void push_back(int n,int p,string t, string s){
        Node * newNode=new Node(n,p,t,s);
        if(head==NULL){
            head=tail=newNode;
            tail->next=head;
        }else{
            tail->next=newNode;
            tail=newNode;
            tail->next=head;
        }

    }


    void pop_front(){
        if(head==NULL){
            cout<<"There are no orders left"<<endl;
            return;
        }
         if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
        }
        cout<<"Order number "<<head->O_num<<" has beeen served"<<endl;
        Node* temp=head;
        head =head->next;
        tail->next =head; 
        delete temp;
    }
    void Print(){
        if(head==NULL){
            cout<<"There are no order remaining"<<endl;
            return;
        }
        Node* temp=head;
        cout<<"Order id"<<" ------ Number of pizza"<<" ------ Type of Pizza"<<" ----Size of Pizza"<<endl;
        do{
            
            cout<<temp->O_num<<"  ----------------  "<<temp->NO_p<<"  ---------------  "<<temp->types<<"  -----------  "<<temp->P_s<<endl;
            temp=temp->next;
                
            }while(temp!=head);
        
        }


};

int main(){
    C_LL L1;
    int a=1001;
    do{
        int ch;
        cout<<"*******************************************************"<<endl;
        cout<<"Press 1 to place your Pizza order"<<endl;
        cout<<"Press 2 to serve the Pizza order"<<endl;
        cout<<"Press 3 to see all the remaining orders"<<endl;
        cout<<"Press 0 to exit the Program"<<endl;
        cout<<"********************************************************"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch){
            case 1:{
                int b,h,v;
                string c,d;
                cout<<"Enter the number of pizza you want: ";
                cin>>b;

                cout<<"Enter the type of pizza you want: "<<endl;;
                cout<<"1. Normal_Cheese\n2. Double_Cheese\n3. Cheese_Volcano\n4. Margereta\n5. Peprono"<<endl;
                cout<<"Enter: ";
                
                cin>>h;
                switch (h)
                {
                case 1:
                    c="Normal_Cheese";
                    break;
                case 2:
                    c="Double_Cheese";
                break;
                case 3:
                    c="Cheese_Volcano";
                break;
                case 4:
                    c="Margereta";
                break;
                case 5:
                    c="Peproni";
                break;
                
                default:
                    cout<<"Enter a valid choice"<<endl;
                    break;
                }
                cout<<"Enter the size of your pizza "<<endl;
                cout<<"1. Regular\n2. Medium\n3. Large"<<endl;
                cout<<"Enter : ";
                cin>>d;
                L1.push_back(a,b,c,d);
                
                
                cout<<"********Your order has been placed with the order id of "<<a<<endl;
                a++;
                break;
            }

            case 2:{
                
                L1.pop_front();
                break;
                

            }
            case 3:{
                cout<<"Remaining Orders -----------------"<<endl;
                L1.Print();
                break;
            }
            case 0:{
                a=0;
                cout<<"-----The program has been ended-----"<<endl;
                break;
            }
            default:{
                cout<<"Enter a valid choicd"<<endl;
                break;
            }

        }
    }while(a!=0);
    L1.push_back(01,3,"DOUBL_CHEES","Medium");
    L1.push_back(02,3,"DOUBL_CHEES","Medium");
    L1.push_back(03,3,"DOUBL_CHEES","Medium");
    L1.Print();

    L1.pop_front();
    L1.Print();
    return 0;


}