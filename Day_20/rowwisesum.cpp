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
    int row_sum[n] = {0};
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            row_sum[i] += matrix[i][j];
        }
    }
    cout<<"Row wise sum:"<<endl;
    for(int i =0; i<n; i++){
        cout<<"Sum of row "<<i+1<<" is: "<<row_sum[i]<<endl;
    }
    return 0;
}