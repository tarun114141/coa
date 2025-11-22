#include<iostream>
using namespace std;

class Sparse_Matrix {
    public:
    int row,col,val;



    void Transpose(Sparse_Matrix S[10]){
        int a;
        for(int i=0;i<=S[0].val;i++){
            a=S[i].row;
            S[i].row=S[i].col;
            S[i].col=a;
        }
        cout<<"Transposed matrix"<<endl;
        for(int i=0;i<=S[0].val;i++){
        
            cout<<S[i].row<<" "<<S[i].col<<" "<<S[i].val<<endl;
        }
    }



    void fastTranspose(Sparse_Matrix S[10], Sparse_Matrix T[10]) {
   
    T[0].row = S[0].col;
    T[0].col = S[0].row;
    T[0].val = S[0].val;

    int numCols = S[0].col;
    int numVals = S[0].val;

   
    int t_array[numCols + 1] = {0};   
    int idx_array[numCols + 1];       // To store starting position of each col in T
    idx_array[0] = 1;                 // First element starts at position 1

    // Step 3: Count elements in each column of S
    for (int i = 1; i <= numVals; i++) {
        t_array[S[i].col]++;
    }

    // Step 4: Calculate starting index for each column in T
    for (int i = 1; i <= numCols; i++) {
        idx_array[i] = idx_array[i - 1] + t_array[i - 1];
    }

    // Step 5: Place elements into T
    for (int i = 1; i <= numVals; i++) {
        int col = S[i].col;
        int loc = idx_array[col];

        T[loc].row = S[i].col;
        T[loc].col = S[i].row;
        T[loc].val = S[i].val;

        idx_array[col]++; // Move index forward
             }   
        }




    void Addition(Sparse_Matrix S1[10], Sparse_Matrix S2[10]) {
        Sparse_Matrix S3[20];  // increased size for safety
        if(S1[0].row!=S2[0].row || S1[0].col!=S2[0].col){
            cout<<"Matrices can not be added as their dimensions are not same"<<endl;
            return;
        }
        int i=1, j=1, k=1;
        int l1 = S1[0].val, l2 = S2[0].val;

        S3[0].row = S1[0].row;
        S3[0].col = S1[0].col;

        while(i <= l1 && j <= l2) {
            if(S1[i].row == S2[j].row) {
                if(S1[i].col == S2[j].col) {
                    // same position → add values
                    S3[k].row = S1[i].row;
                    S3[k].col = S1[i].col;
                    S3[k].val = S1[i].val + S2[j].val;
                    i++; j++; k++;
                }
                else if(S1[i].col < S2[j].col) {
                    S3[k] = S1[i];
                    i++; k++;
                }
                else {  // FIXED: compare with S2[j].col
                    S3[k] = S2[j];
                    j++; k++;
                }
            }
            else if(S1[i].row < S2[j].row) {
                S3[k] = S1[i];
                i++; k++;
            }
            else {
                S3[k] = S2[j];
                j++; k++;
            }
        }

        // copy leftovers
        while(i <= l1) {
            S3[k] = S1[i];
            i++; k++;
        }
        while(j <= l2) {
            S3[k] = S2[j];
            j++; k++;
        }

        S3[0].val = k - 1;

        cout << "Addition of Matrix\n";
        for(int p=0; p<=S3[0].val; p++) {
            cout << S3[p].row << " " << S3[p].col << " " << S3[p].val << endl;
        }
    }

void Multiplication(Sparse_Matrix S1[10],Sparse_Matrix T[10]){
    Sparse_Matrix R[10];
    if(S1[0].col!=T[0].col){
        cout<<"The Two matrices can't be Multiplied"<<endl;
        return ;
    }
    R[0].row=S1[0].row;
    R[0].col=T[0].row;
    R[0].val=0;
    int t=1;
    for(int i=0;i<T[0].row;i++){
        for(int j=0;j<T[0].col;j++){
            int sum=0;
            for(int x=1;x<=S1[0].val;x++){
                if(S1[x].row!=i)
                    continue;
                for(int y=1;y<=T[0].val;y++){
                    if(T[y].row!=j)
                        continue;
                    if(S1[x].col==T[y].col){
                        sum +=S1[x].val*T[y].val;
                    }
                }
            }
            if(sum!=0){
                R[t].row=i;
                R[t].col=j;
                R[t].val=sum;
                t++;

            }
        }
    }
    R[0].val=t-1;
    cout<<"The Result of the Multiplication of two matrices:-----"<<endl;
    for(int i=0;i<=R[0].val;i++){
        cout<<R[i].row<<" "<<R[i].col<<" "<<R[i].val<<endl;
    }





}



};
Sparse_Matrix T[10];


void Input(Sparse_Matrix S1[10]){
    int a,b;
	cout<<"Enter the dimensions of the Sparse Matrix"<<endl;
	cout<<"Enter the number of rows"<<endl;
	cin>>a;
	cout<<"Enter the number of cols"<<endl;
	cin>>b;
	int A[a][b];
	cout<<"Enter the sparse matrix: "<<endl;
	
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			cin>>A[i][j];
		}
//		cout<<endl;
	}
	
	cout<<"Your Matrix"<<endl;
	for(int i=0;i<a;i++){
	for(int j=0;j<b;j++){
		cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}

    int c=1;
	
	
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			if(A[i][j]!=0){
				S1[c].row=i;
				S1[c].col=j;
				S1[c].val=A[i][j];
				c++;
			}
		}
	}
	S1[0].row=a;
	S1[0].val=c-1;
    S1[0].col=b;
	
	//Class output
	cout<<"Triplet Representation of Sparse matrix"<<endl;
	for(int i=0;i<=S1[0].val;i++){
		cout<<S1[i].row<<" "<<S1[i].col<<" "<<S1[i].val<<endl;
	}
}




int main(){
    Sparse_Matrix S1[10],S2[10],S3[10],obj;
    cout<<"Enter what you want to do:"<<endl;
    cout<<"Press 1 for the transpose of a matrix"<<endl;
    cout<<"Press 2 for the fast transpose of a matrix"<<endl;
    cout<<"Press 3 for the addition of two matrices"<<endl;
    cout<<"Press 4 for the multiplication of two matrices"<<endl;

    int ch;
    cin>>ch;
    


    switch(ch){
        case 1:{
            Input(S1);
            obj.Transpose(S1);
            break;

        }
        
        case 2:{
            Input(S1);
            obj.fastTranspose(S1,T);
            cout<<"Your Fast transposed matrix"<<endl;
            for(int i=0;i<=T[0].val;i++){
                cout<<T[i].row<<" "<<T[i].col<<" "<<T[i].val<<endl;
            }
            break;
        }
        
        case 3:{
            Input(S1);
            Input(S2);
            obj.Addition(S1,S2);
            break;


        }
        case 4:{
            Input(S1);
            Input(S2);
            obj.fastTranspose(S2,T);
            obj.Multiplication(S1,T);
            break;

        }

    }



    return 0;
}