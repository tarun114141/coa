#include<iostream>
#include<string>
using namespace std;





class Book{
    public:
    int Id;
    string name,writer;
    
    
    
void addBook(){

    cout<<"Enter the name of the book"<<endl;
    cin>>name;
    cout<<"Enter the ID of the book"<<endl;
    cin>>Id;
    cout<<"Enter the name of the writer"<<endl;
    cin>>writer;
    cout<<"The Book has been ADDED"<<endl;
    

}

void Display(){
    cout<<"Name: "<<name<<endl;
    cout<<"ID: "<<Id<<endl;
    cout<<"Writers name: "<<writer<<endl;

}

void Remove(){
	
	
	name="";
	writer="";
	Id=-1;
	
	cout<<"The Book has been removed"<<endl;	
}
void Update(){
	
	cout<<"Enter the new id"<<endl;
	cin>>Id;
	cout<<"Enter the name of writer"<<endl;
	cin>>writer;
	cout<<"Enter the name of Book"<<endl;
	cin>>name;
	cout<<"The book has been updated"<<endl;
}


};








int main(){

   int  mo=1;
    Book B[10];
    int c=0;
    while(mo!=0){
        int ch;
        cout<<"============++++ Menu ++++++==========="<<endl;
        cout<<"Press 1 to add new Book"<<endl;
        cout<<"Press 2 to see the info of Book by ID"<<endl;
        cout<<"Press 3 to see the info of Book by name"<<endl;
        cout<<"Press 4 to delete book"<<endl;
        cout<<"Press 5 to update the book"<<endl;
        cout<<"Press 6 to see all books"<<endl;
        cout<<"To exit Press 7"<<endl;



        cin>>ch;
       

        switch(ch){
            case 1:{
                if(c<10){
                
                    B[c].addBook();
                    c++;
                }
                break;
            }
            case 2:{
                int id;
                cout<<"Enter the Id of the book"<<endl;
                cin>>id;
                bool found1=false;
                for(int i=0;i<c;i++){
                    if(id==B[i].Id){
                        B[i].Display();
                        found1=true;
                        }
                   
                }
                if(!found1){
                    cout<<"No Book found in the database"<<endl;
                }
                break;
            }
            case 3:{
                string nm;
                cout<<"Enter the name of the book"<<endl;
                cin>>nm;
                bool found2 =false;
                for(int i=0;i<c;i++){
                    if(nm==B[i].name){
                        B[i].Display();
                        found2 =true;
                    }
                   
                }
                 if(!found2){
                        cout<<"No Book found in the database"<<endl;
                    }
                break;
            }
            case 4:{
            	cout<<"Enter the ID of the book you want to delete"<<endl;
            	int io;
            	cin>>io;
            	bool found3= false;
    
                for(int i=0;i<c;i++){
                    if(io==B[i].Id){
                        B[i].Remove();
                        found3=true;
                        }
                   
                }
                if(!found3){
                        cout<<"No Book found in the database"<<endl;
                    }
            	
				break;
			}
			case 5:{
				cout<<"Enter the ID of the book you want to update"<<endl;
            	int io;
            	cin>>io;
            	bool found4= false;
    
                for(int i=0;i<c;i++){
                    if(io==B[i].Id){
                        B[i].Update();
                        found4=true;
                        }
                   
                }
                if(!found4){
                        cout<<"No Book found in the database"<<endl;
                    }
				
				break;
			}
            case 6:{
                for(int i=0;i<c;i++){
                    B[i].Display();
                }
                break;
            }
            
            case 7:{
                mo=0;
                cout<<"---------------The program has ended--------------------"<<endl;
                break;
            default:
                cout<<"Enter a valid choise"<<endl;
                break;
            }
        }
            
    }
    return 0;
}









