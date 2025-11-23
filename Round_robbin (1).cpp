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
    void Enqueue(int data){
        if(curr_size==capacity){
            cout<<"Can't push queue if full"<<endl;
            return;
        }

        rear=(rear+1)%capacity;
        arr[rear]=data;
        curr_size++;

    }


    int Dequeue(){
        if(empty()){
            cout<<"The queue is already empty cant pop"<<endl;
            return -1;
        }
        int x= arr[front];
        front=(front+1)%capacity;
        curr_size--;
        return x;


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
    int n;  
    cout<<"Enter the number of Processes: ";
    cin>>n;
    int B_time[n];
    int W_time[n]={0};
    int R_B_time[n]={0};
    int T_A_time[n]={0};
    int C_time[n]={0};

    C_queue P(n);

    cout<<"Enter the brust time of processes"<<endl;
    for(int i=0;i<n;i++){
        cout<<"P"<<i+1<<" : ";
        cin>>B_time[i];
        R_B_time[i]=B_time[i];
    }
    
    int Q_time;
    cout<<"Enter quantum time of each process: ";
    cin>>Q_time;

    //enqueing the processes

    for(int i=0;i<n;i++){
        P.Enqueue(i+1);

    }
    int time=0;
    while(!P.empty()){
    
        int x= P.Dequeue()-1;
        cout<<"The P"<<x+1<<" will take time from "<<time<<" to ";
        if(R_B_time[x]>0){
            if(R_B_time[x] > Q_time){
                time+=Q_time;
                R_B_time[x] -= Q_time;
                P.Enqueue(x+1);

            }else{
                time+=R_B_time[x];
                C_time[x]=time;
                W_time[x]=C_time[x]-B_time[x];
                R_B_time[x]=0;
            }

            cout<<time<<" units of time to execute"<<endl;
        }
    }

    for(int i=0;i<n;i++){
        T_A_time[i]=B_time[i]+W_time[i];
        }


    cout<<"Table"<<endl;
    cout<<"Processes      B_time       W_time     T_A_Time       C_time"<<endl;
    for(int i=0;i<n;i++){
        cout<<"    P"<<i+1<<"           "<<B_time[i]<<"           "<<W_time[i]<<"         "<<T_A_time[i]<<"         "<<C_time[i]<<endl;
        
    }
    int avg_w_Time=0;
    int avg_T_A_Time=0;
    for(int i=0;i<n;i++){
        avg_w_Time+=W_time[i];
        avg_T_A_Time+=T_A_time[i];

    }

    cout<<"Average Waiting time: "<<avg_w_Time/n<<" units."<<endl;
    cout<<"Average Turn Around Time: "<<avg_T_A_Time/n<<" units."<<endl;
   

    return 0;
}