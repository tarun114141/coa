#include<iostream>
#include<string>
#include<vector>

using namespace std;


class Student{
    public:
    int roll;
    string name;
    float Sgpa;
    string dept;

};

void Display( Student S[15] ){
    cout<<"Name\t\tRollno\tSgpa\tDepartment"<<endl;
    for(int i=0;i<15;i++){
        cout<<S[i].name<<"\t \t"<<S[i].roll<<"\t"<<S[i].Sgpa<<"\t"<<S[i].dept<<"\t"<<endl;
    }
}

//Quick sorting
int partion(Student S[],int st,int end){
    float pivot = S[end].Sgpa;
    int i = st - 1;
    for (int j = st; j < end; j++) {
        if (S[j].Sgpa > pivot) { // descending
            i++;
            swap(S[i], S[j]);
        }
    }
    swap(S[i + 1], S[end]);
    return i + 1;

}
void QuickSort(Student S[],int st,int end){
    if(st<end){
        int pivIdx=partion(S,st,end);
        QuickSort(S,st,pivIdx-1);
        QuickSort(S,pivIdx+1,end);
    }


}





//Searching students sgpa linear search

void LinearSearch(Student S[15],float target){
    cout<<"Students with Sgpa "<<target<<" are"<<endl;
    for(int i=0;i<15;i++){
        if(S[i].Sgpa==target){
            cout<<S[i].name<<"\t \t"<<S[i].roll<<"\t"<<S[i].Sgpa<<"\t"<<S[i].dept<<"\t"<<endl;
        }
    }

}


//Roll call using Bubble Sort
void BubleSort(Student S[15] ){
    for(int i=0;i<15-1;i++){
        for(int j=0;j<15-i-1;j++){
            if(S[j].roll>S[j+1].roll){
                swap(S[j].roll,S[j+1].roll);
                swap(S[j].name,S[j+1].name);
                swap(S[j].Sgpa,S[j+1].Sgpa);
                swap(S[j].dept,S[j+1].dept);

            }
        }
    }

}

//insertion sort with name

void InsertionSort(Student S[15]){
    for(int i=1;i<15;i++){
        Student curr=S[i];
        int prev=i-1;
        while(prev>=0 && S[prev].name>curr.name){
            S[prev+1]=S[prev];
            prev--;
        }
        S[prev+1]=curr;
    }

}


//Binary Search by Name
void BinarySearch(Student S[15] , string target){

    int low=0;
    int  high=14;
    while(low<=high){
        int mid=(low+high)/2;
        if(S[mid].name == target){
            cout<<"KEY FOUNDED"<<endl;
            cout<<S[mid].name<<"\t"<<S[mid].roll<<"\t"<<S[mid].Sgpa<<"\t"<<S[mid].dept<<"\t"<<endl;
            break;

        }else if(S[mid].name<target){
            low=mid+1;

        }else if(S[mid].name>target){
            high=mid-1;

        }else{
            return ;
        }
    } 

}

//Searc students dept using fibsearch

int  FibbSearch(Student S[15],string target){
    int offset =-1;
    int Fm1=1;
    int Fm2=0;
    int Fm=Fm2+Fm1;
    while(Fm<15){
        Fm2=Fm1;
        Fm1=Fm;
        Fm=Fm2+Fm1;
    }

    while(Fm>1){
        int i=min(offset+Fm2,15-1);
        if(S[i].name<target){
            Fm=Fm1;
            Fm1=Fm2;
            Fm2=Fm-Fm1;
            offset=i;
        }else if(S[i].name>target){
            Fm=Fm2;
            Fm1=Fm1-Fm2;
            Fm2=Fm-Fm1;

        }else{
            return i;
        }
    }
    if (Fm1&&offset+1 < 15&&S[offset+1].name==target)
        return offset+1;

    return -1;

}





int main(){

    Student S[15]={
        {101, "Tarun", 8.9, "Computer"},
        {112, "Divya", 9.6, "Computer"},
        {102, "Meera", 9.1, "IT"},
        {103, "Anil", 7.8, "Mechanical"},
        {104, "Kavya", 9.5, "Computer"},
        {109, "Vikas", 8.6, "Mechanical"},
        {105, "Rohit", 8.7, "Civil"},
        {106, "Simran", 8.2, "IT"},
        {107, "Aman", 9.4, "Computer"},
        {108, "Neha", 7.5, "ENTC"},
        {114, "Kiran", 8.4, "IT"},
        {110, "Pooja", 9.0, "IT"},
        {111, "Arjun", 8.3, "Civil"},
        {115, "Rohan", 9.2, "Computer"},
        {113, "Riya", 7.9, "ENTC"}
       
        
    };

    int choice;
    string target;
    float sgpaKey;
    cout<<"The original Dataset:"<<endl;
    Display(S);

    do{
        cout<<"\n==================== STUDENT DATABASE MENU ====================\n";
        cout<<"Press 1 for Sorting"<<endl;
        cout<<"Press 2 for Searching"<<endl;
        cout<<"Press 3 to Exit the program"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;
        
        if(choice==1){
        	int ch;
        	do{
        		cout<<"---------------Sorting----------------------"<<endl;
        		cout<<"1. Display Roll Call List (Bubble Sort)\n";
		        cout<<"2. Arrange List Alphabetically (Insertion Sort)\n";
		        cout<<"3. Quick sort"<<endl;
		        cout<<"4. Move Back"<<endl;
		        cout<<"Enter your choice: ";
		        cin>>ch;
		        
		        
			    switch(ch){
	            case 1:
	                cout<<"Roll Call List (Bubble Sort by Roll No):"<<endl;
	                BubleSort(S);
	                Display(S);
	                break;
	
	            case 2:
	                cout<<"List arranged Alphabetically (Insertion Sort):"<<endl;
	                InsertionSort(S);
	                Display(S);
	                break;
	
	
	            case 3:
	                cout<<"Quick Sort"<<endl;
                    QuickSort(S,0,14);
                    for(int i=0;i<10;i++){
                        cout<<S[i].name<<"\t \t"<<S[i].roll<<"\t"<<S[i].Sgpa<<"\t"<<S[i].dept<<"\t"<<endl;

                    }
	                break;
	                
	            case 4:
	                cout<<"Moving Back____"<<endl;
	                break;
	                
	            default:
	            	cout<<"Enter a valid choice"<<endl;
	            	break;
					}
				}while(ch!=4);
				
					
		}else if(choice==2){
			
			int cho;
			do{
				
		        cout<<"----------------Searching----------------------"<<endl;
		        cout<<"1. Search Students by SGPA (Linear Search)\n";
		        cout<<"2. Search Student by Name (Binary Search)\n";
		        cout<<"3. Check if Student belongs to Computer Dept (Fibonacci Search)\n";
		        cout<<"4. Move Back"<<endl;
				
		        cout<<"Enter your choice: ";
		        cin>>cho;
		        
			    switch(cho){

                case 1: 
                    cout<<"Enter the Sgpa you want to find: ";
                    float s;
                    cin>>s;
                    LinearSearch(S,s);
                    break;
			    case 2:
	                cout<<"\nEnter name to search (Binary Search): ";
	                cin>>target;
	                InsertionSort(S);   // ensure sorted before binary search
	                BinarySearch(S, target);
	                break;
	
	            case 3:
	                cout<<"\nEnter student name to check department (Fibonacci Search): ";
	                cin>>target;
	                InsertionSort(S);   // ensure sorted before Fibonacci search
	                {
	                    int index = FibbSearch(S, target);
	                    if (index != -1) {
	                        cout << "\nStudent found:\n";
	                        cout<<S[index].name<<"\t"<<S[index].roll<<"\t"<<S[index].Sgpa<<"\t"<<S[index].dept<<"\t"<<endl;
	                        if (S[index].dept == "Computer")
	                            cout<<S[index].name<<" belongs to the Computer Department."<<endl;
	                        else
	                            cout<<S[index].name << " does NOT belong to the Computer Department."<<endl;
	                    } else {
	                        cout << "Student with name " <<target <<" not found."<<endl;
	                    }
	                }
	                break;
	          
	            case 4:
	                cout<<"Moving Back"<<endl;
	                break;
	
	            default:
	                cout<<"\nInvalid Choice! Try Again.\n";
	        }
			    }while(cho!=4);
			    
			}else if(choice==3){
				cout<<"Exiting Program"<<endl;
			}else{
				cout<<"Enter a valid number"<<endl;
			}
		}while(choice!=3);
		
        

    return 0;
}
