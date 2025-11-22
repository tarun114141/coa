#include<iostream>
#include<string.h>
using namespace std;


class Node{
	public:
		int prn;
		int TrainNumber;
		string clas;
		string name;
		Node* next;
		
		Node(int p,int t,string c,string n){
			prn=p;
			TrainNumber=t;
			clas=c;
			name=n;
			next=NULL;
		}
		
};

class LL{
	public:
	Node* head;
	Node* tail;
	LL(){
		head=tail=NULL;
	}
	
	 void Insert_front(int p,int t,string c,string n){
        Node* newNode=new Node(p,t,c,n);
        if(head==NULL){
            head=tail=newNode;
            return;
              
        }else{
            newNode->next=head;
            head=newNode;
        }
    }
     void Print(Node* h){
        Node* temp=h;
        while(temp!=NULL){
            cout<<"PRN:"<<temp->prn<<" "<<"Train Number:"<<temp->TrainNumber<<" "<<"Class:"<<" "<<temp->clas<<" "<<"Name of the passanger:"<<" "<<temp->name<<endl;
            temp=temp->next;
        }  
    }

	 void Sort(){
        if(head==NULL||head->next==NULL){
            return;
        }
        Node* h1;
        Node* h2;
        for(h1=head;h1->next!=NULL;h1=h1->next){
            for(h2=h1->next;h2!=NULL;h2=h2->next){
                if(h1->prn > h2->prn){
                    int temp1=h1->prn;
                    h1->prn=h2->prn;
                    h2->prn=temp1;
                    int temp2=h1->TrainNumber;
                    h1->TrainNumber=h2->TrainNumber;
                    h2->TrainNumber=temp2;
                    string temp3=h1->clas;
                    h1->clas=h2->clas;
                    h2->clas=temp3;
                    string temp4=h1->name;
                    h1->name=h2->name;
                    h2->name=temp4;


                }
            }
        }


    }

	void Delete(int pos) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    // Case 1: delete head
    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        if (head == NULL) tail = NULL;  // if list became empty
        delete temp;
        return;
    }

    // Case 2: delete at other position
    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        if (temp->next == NULL) {   // position out of range
            cout << "Invalid Position" << endl;
            return;
        }
        temp = temp->next;
    }

    Node* nodeToDelete = temp->next;
    if (nodeToDelete == NULL) {
        cout << "Invalid Position" << endl;
        return;
    }

    temp->next = nodeToDelete->next;

    // Update tail if last node is deleted
    if (nodeToDelete == tail) {
        tail = temp;
    }

    delete nodeToDelete;
}


Node* Merge(Node* h1,Node* h2){
        if(h1==NULL||h2==NULL){
            return h1==NULL? h2:h1;
        }

        if(h1->prn<=h2->prn){
            h1->next=Merge(h1->next,h2);
            return h1;
        }else{
            h2->next=Merge(h1,h2->next);
            return h2;
        }


    }


void Update(Node* h,int prn){
    Node* temp=h;
    while(temp->prn!=prn){
        temp=temp->next;
        if(temp==NULL){
            cout<<"PRN not found"<<endl;
            return;
        }

        }
    int p,t;
    string c,n;
    cout<<"Enter new prn"<<endl;
    cin>>p;
    cout<<"Enter train number"<<endl;
    cin>>t;
    cout<<"Enter the class"<<endl;
    cin>>c;
    cout<<"Enter the name of the passanger"<<endl;
    cin>>n;
    temp->prn=p;
    temp->TrainNumber=t;
    temp->clas=c;
    temp->name=n;

    }    
    
};


int main(){
	LL L1,L2,obj;
	// L1.Insert_front(20,1180,"A3","Tarun");
	// L1.Insert_front(22,1180,"A2","Rohan");
	// obj.Print(L1.head);
	// L2.Insert_front(21,1150,"A2","Ishan");
	// //L1.Delete(1);
	// cout<<"L1_Delete"<<endl;
	// L1.Print(L1.head);
    // L1.Sort();
    // L2.Sort();
	// cout<<"Merge"<<endl;
	// Node* tar=obj.Merge(L1.head,L2.head);
	// obj.Print(tar);
    // // obj.Update(tar,21);
    // // obj.Print(tar);


    int m=1;
    while(m==1){
        int ch;
        cout<<"-------------MENU----------------"<<endl;
        cout<<"Press 1 to create a list"<<endl;
        cout<<"Press 2 to create second list"<<endl;
        cout<<"Press 3 to Delete fron the first linked list"<<endl;
        cout<<"Press 4 to Delete fron the second linked list"<<endl;
        cout<<"Press 5 update the first linked list"<<endl;
        cout<<"Press 6 to update the second linked list"<<endl;
        cout<<"Press 7 to merge both the linked list"<<endl;
        cout<<"Press 8 to update form the merged and updating the final linked list"<<endl;
        cout<<"Press 0 to exit "<<endl;
        cout<<"Enter your choise: ";
        cin>>ch;
        switch(ch){
             case 0:
                m=0;
                break;
            case 1:{
                int n;
                cout<<"Enter how many nodes you want to insert"<<endl;
                cin>> n;
                while(n--){
                    int pr,tr;
                    string cl,nm;
                    cout<<"Enter the prn"<<endl;
                    cin>>pr;
                    cout<<"Enter train number"<<endl;
                    cin>>tr;
                    cout<<"Enter the class"<<endl;
                    cin>>cl;
                    cout<<"Enter the name of the passanger"<<endl;
                    cin>>nm;
                    L1.Insert_front(pr,tr,cl,nm);

                }
            
                obj.Print(L1.head);
                break;
            }


            case 2:{
                int n;
                cout<<"Enter how many nodes you want to insert"<<endl;
                cin>> n;
                while(n--){
                    int pr,tr;
                    string cl,nm;
                    cout<<"Enter the prn"<<endl;
                    cin>>pr;
                    cout<<"Enter train number"<<endl;
                    cin>>tr;
                    cout<<"Enter the class"<<endl;
                    cin>>cl;
                    cout<<"Enter the name of the passanger"<<endl;
                    cin>>nm;
                    L2.Insert_front(pr,tr,cl,nm);
                   }
                obj.Print(L2.head);
                break;
              }


            case 3:{
                int p;
                cout<<"Enter the position you want to delete"<<endl;
                cin>>p;
                L1.Delete(p);
                obj.Print(L1.head);
                break;

            }

            case 4:{
                int p;
                cout<<"Enter the position you want to delete"<<endl;
                cin>>p;
                L2.Delete(p);
                obj.Print(L2.head);
                break;

            }
            case 5:{
                int x;
                cout<<"Ente the prn of the node you want to update"<<endl;
                cin>>x;
                obj.Update(L1.head,x);
                obj.Print(L1.head);
                break;
                
            }
            case 6:{
                int x;
                cout<<"Ente the prn of the node you want to update"<<endl;
                cin>>x;
                obj.Update(L2.head,x);
                obj.Print(L2.head);
                break;
                
            }
            case 7:{
                L1.Sort();
                L2.Sort();
                Node* hy=obj.Merge(L1.head,L2.head);
                obj.Print(hy);
                break;

            }
            case 8:{
                Node * hy=obj.Merge(L1.head,L2.head);
                int x;
                cout<<"Ente the prn of the node you want to update"<<endl;
                cin>>x;
                obj.Update(hy,x);
                obj.Print(hy);
                break;
            }

           
            
            default:{
                cout<<"Enter a valid choise  ++++++++++"<<endl;
            }
        }

    }


    cout<<"The Program has ended>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    

	
	
	return 0;
}
