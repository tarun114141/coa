#include<iostream>
#include<string>
using namespace std;

class Patient{
public:
    string name;
    int priority;

    
    Patient(){
        this->name="";
        this->priority=0;
    }

    Patient(string name,int p){
        this->name=name;
        this->priority=p;
    }
};


class Queue{
    Patient Q[10];
    int size=0;
    public:
        void Add_Patient(string name , int p){
            if(size>=10){
                cout<<"Queue is full cant add more patients"<<endl;
                return;
            }

            int i;
            for( i=size-1;i>=0 && Q[i].priority>p;i--){
                Q[i+1]=Q[i];
            }

            Q[i+1]=Patient(name,p);
            size++;

        }



    void Serve_Patient() {
        if(size==0) {
            cout<<"No patients to serve."<<endl;
            return;
        }

        cout<<"Now serving patient: "<< Q[0].name 
            <<" (Priority: "<< Q[0].priority << ")" << endl;

        for (int i=0;i<size-1;i++) {
            Q[i]=Q[i+1];
        }
        size--;
        }


        void ShowPatients() {
        if (size==0) {
            cout<<"No patients in queue."<<endl;
            return;
        }

        cout<<"--- Current Waiting List ---"<<endl;
        cout<<"Name\t\tPriority\n";
        cout<< "---------------------------"<<endl;
        for (int i = 0; i < size; i++) {
            cout<<Q[i].name<<"\t\t"<<Q[i].priority<<endl;
        }
        cout<<"---------------------------"<<endl;
    }

};




int main(){
    Queue H;
    int choice;
    string name;
    int p;

    do {
        cout<<"========== Hospital Appointment System ==================="<<endl;
        cout<<"1. Add Patient"<<endl;
        cout<< "2. Serve Patient"<<endl;
        cout<<"3. Show All Patients"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
                cout<<"Enter patient name: ";
                cin>>name;
                cout<<"Enter priority (smaller the number higher the priority): ";
                cin>>p;
                H.Add_Patient(name, p);
                break;

            case 2:
                H.Serve_Patient();
                break;

            case 3:
                H.ShowPatients();
                break;

            case 4:
                cout<<"The Program has ended_________________"<<endl;
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    }while(choice!=4);

    return 0;
}