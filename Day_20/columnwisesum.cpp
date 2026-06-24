#include<iostream>
using namespace std;
int main(){
    int n; 
    cout<<"Enter the size of matrix: ";
    cin>>n;
    int matrix[n][n];
    cout<<"Enter the elements of matrix: "<<endl;
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin>>matrix[i][j];
        }
    }
    int col_sum[n] = {0};
    for(int j =0; j<n; j++){
        for(int i =0; i<n; i++){
            col_sum[j] += matrix[i][j];
        }
    }
    cout<<"Column wise sum:"<<endl;
    for(int j =0; j<n; j++){
        cout<<"Sum of column "<<j+1<<" is: "<<col_sum[j]<<endl;
    }
    return 0;
}