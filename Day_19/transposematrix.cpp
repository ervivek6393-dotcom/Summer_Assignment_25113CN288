#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of matrix: ";
    cin>>n;
    int matrix[n][n];
    int transpose[n][n];
    cout<<"Enter the elements of matrix: "<<endl;
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin>>matrix[i][j];
        }
    }
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            transpose[j][i] = matrix[i][j];
        }
    }
    cout<<"Transpose Matrix: "<<endl;
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}