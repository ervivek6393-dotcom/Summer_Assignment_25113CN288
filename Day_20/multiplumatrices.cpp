#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of matrix: ";
    cin>>n;
    int a[n][n];
    int b[n][n];
    int multiply[n][n];
    cout<<"Enter first matrix: "<<endl;
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin>>a[i][j];
        }
    }
    cout<<"Enter second matrix: "<<endl;
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin>>b[i][j];
        }
    }
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            multiply[i][j] = 0;
            for(int k =0; k<n; k++){
                multiply[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    cout<<"Multiplication of matrices is: "<<endl;
    for(int i = 0; i<n; i++){
        for(int j =0; j<n; j++){
            cout<<multiply[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}