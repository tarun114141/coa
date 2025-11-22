#include <iostream>
#include <list>
using namespace std;

// ===== LINEAR PROBING =====
class LinearHash{
    int table[6];
public:
    LinearHash(){
        for(int i=0;i<6;i++)
            table[i] = -1;
    }


    void insert(int key) {
        int index=key % 6;
        int start=index;
        while (table[index]!=-1) {
            index=(index+1)%6;
            if(index==start) {
                cout<<"Hash table full"<<endl;
                return;
            }
        }
        table[index]=key;
    }

    void display() {
        cout<<"--- Linear Probing Hash Table ---"<<endl;
        for(int i=0;i<6;i++)
            cout<<i<<" --> "<<table[i]<<endl;
    }
    
};

// ===== SEPARATE CHAINING =====
class ChainHash {
    list<int> table[20];
public:
    void insert(int key){
        int index=key%20;
        table[index].push_back(key);
    }

    void display(){
        cout<<"--- Separate Chaining Hash Table ---"<<endl;
        for (int i=0;i<20;i++) {
            cout<<i<<" --> ";
            for (int val:table[i])
                cout<<val<<" -> ";
            cout << "NULL"<<endl;
        }
    }
};

// ===== QUADRATIC PROBING =====
class QuadHash {
    int table[11];
public:
    QuadHash(){
        for (int i=0;i<11;i++)
            table[i] = -1;
    }

    void insert(int key) {
        int index=key%11;
        int i=0;
        while(table[(index+i*i) % 11]!= -1) {
            i++;
            if (i==11) {
                cout<<"Hash table full!"<<endl;
                return;
            }
        }
        table[(index+i*i)%11]=key;
    }

    void display() {
        cout<< "--- Quadratic Probing Hash Table ---"<<endl;
        for (int i=0;i<11;i++)
            cout<<i<<" --> "<<table[i]<<endl;
    }
};

// ===== MAIN PROGRAM =====
int main() {
    int choice;
    do {
        cout<<" HASH TABLE IMPLEMENTATION"<<endl;
        cout<<"=============================="<<endl;
        cout<<"1. Linear Probing (Cold Drinks)"<<endl;
        cout<<"2. Separate Chaining (Student Marks)"<<endl;
        cout<<"3. Quadratic Probing (Mango Shop)"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
        case 1:{
            LinearHash ht;
            int keys[]={5, 12, 19, 6, 13, 7};
            for (int key:keys)
                ht.insert(key);
            ht.display();
            break;
        }

        case 2:{
            ChainHash ht;
            int data[]={33,56,78,12,10,67,89,99,100,23,45,71,39,62,59,90,91,20,75,66};
            for (int key:data)
                ht.insert(key);
            ht.display();
            break;
        }

        case 3:{
            QuadHash ht;
            int mangoes[]={25,15,10,5,11,19,16,36,42,28,32};
            for (int key:mangoes)
                ht.insert(key);
            ht.display();
            break;
        }

        case 4:
            cout<<"Exiting program... "<<endl;
            break;

        default:
            cout<<"Invalid choice! Try again."<<endl;
        }

    } while (choice!=4);

    return 0;
}
