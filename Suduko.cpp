#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

int N;


bool isSafe(vector<vector<int>>&grid, int row, int col, int num){
    for(int i=0;i<N;i++){
        //row
        if(grid[row][i]==num){
            return false;
        }   
    }
    for(int i=0;i<N;i++){
        if(grid[i][col]==num){
            return false;
        }
    }
    

    //sub box
    int z=sqrt(N);
    int S_row=row-row % z;
    int S_col=col-col % z;
    for(int i=0;i<z;i++){
        for(int j=0;j<z;j++){
            if(grid[i+S_row][j+S_col]==num){
                return false;
            }
        }
    }
    return true;

}

bool solveSudoku(vector<vector<int>> &grid){
    int row=-1;
    int col=-1;
    bool isEmpty=false;
    

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j]==0){
                row=i;
                col=j;
                isEmpty=true;
                break;
            }
        }
    }

    // if(isEmpty) break;

    if (!isEmpty) return true;


    for (int num=1;num<=N;num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) return true;
            grid[row][col] = 0; 
        }
    }
    return false;
}








void Print(vector<vector<int>> &grid){
    for(int i=0;i<N;i++){
        cout<<"| ";
        for(int j=0;j<N;j++){

            cout<<grid[i][j]<<" | ";
        }
        
        cout<<endl;

    }
}




int main(){
    int x;
    
    vector<vector<int>>grid;
    cout<<"______Suduko___________"<<endl;
    cout<<"1. For 4X4 suduko"<<endl;
    cout<<"2. For 9X9 suduko"<<endl;
    cout<<"3. For 16X16 suduko"<<endl;
    cout<<"Enter which type of suduko grid do you want: ";
    cin>>x;
    switch(x){
        case(1):{
            N=4;
            grid={{1, 0,   0, 4},
                  {0, 0,   0, 2},

                  {0, 1,   0, 0},
                  {3, 0,   0, 0}};
                  break;
                }
        
        case(2):{
            N=9;
            grid={  {3, 0, 6,   5, 0, 8,   4, 0, 0},
                    {5, 2, 0,   0, 0, 0,   0, 0, 0},
                    {0, 8, 7,   0, 0, 0,   0, 3, 1},

                    {0, 0, 3,   0, 1, 0,   0, 8, 0},
                    {9, 0, 0,   8, 6, 3,   0, 0, 5},
                    {0, 5, 0,   0, 9, 0,   6, 0, 0},

                    {1, 3, 0,   0, 0, 0,   2, 5, 0},
                    {0, 0, 0,   0, 0, 0,   0, 7, 4},
                    {0, 0, 5,   2, 0, 6,   3, 0, 0}    };
                    break;
        }

        case(3):{
            N=16;
            grid={  { 0,  0,  0,  0,   2,  0,  0, 13,   0, 11,  0,  0,   8,  0,  0,  0},
                    { 0,  0, 16,  0,   0,  0,  0,  0,   0,  0,  0, 14,   0,  0,  0,  0},
                    {12,  0,  0,  0,   0,  0,  3,  0,   0,  0,  0,  0,   0,  7,  0,  0},
                    { 0,  0,  0,  8,   0,  0,  0,  0,   5,  0,  0,  0,   0,  0,  2,  0},

                    { 0,  7,  0,  0,   0,  0, 14,  0,   0,  0,  0,  0,   0, 12,  0,  0},
                    { 0, 10,  0,  0,   0,  0,  0,  0,   0,  0,  6,  0,   0,  0,  0, 11},
                    { 0,  0,  0,  6,   0,  4,  0,  0,   0, 12,  0,  0,   0,  0,  0,  0},
                    { 0,  0,  9,  0,   0, 15,  0,  0,   0,  0,  0,  0,   4,  0,  0,  0},

                    { 0,  0,  0,  5,   0,  0,  0,  0,   0,  3,  0,  0,   0,  0, 16,  0},
                    { 8,  0,  0,  0,   0, 12,  0,  0,   0,  0,  0,  7,   0,  0,  0,  0},
                    {14,  0,  0,  0,   0,  0,  6,  0,   0,  0,  0,  0,   0,  0,  0,  9},
                    { 0,  0,  0,  0,   1,  0,  0,  0,   0,  0,  0,  0,   0,  0,  5,  0},

                    { 0,  0, 13,  0,   0,  0,  0,  0,   0,  0,  0, 12,   0,  0,  0,  0},
                    { 0,  0,  0,  0,   0,  0,  9,  0,   0,  0,  4,  0,   0,  0,  0,  0},
                    { 0,  5,  0,  0,   0,  0,  0,  0,   2,  0,  0,  0,   0,  0, 10,  0},
                    { 0,  0,  0,  7,   0,  0,  0,  0,   0,  9,  0,  0,   0,  0,  0,  0}  };
        }
        default: {
            cout<<"Enter a valid grid";
        }
    }




    if (solveSudoku(grid))
        Print(grid);
    else
        cout<<"No solution exists";

    return 0;



    return 0;
}