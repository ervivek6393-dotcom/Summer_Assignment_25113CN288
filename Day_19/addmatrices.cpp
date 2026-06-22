 #include<iostream>
 using namespace std;
 int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    int a[n][n];
    int b[n][n];
    int sum[n][n];
    cout<<"Enter first matrix: "<<endl;
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin>>a[i][j];
        }
    }
    cout<<"Enter second matrix: "<<endl;
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++)
            cin>>b[i][j];
        }
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                sum[i][j] = a[i][j] + b[i][j];
            }
        }
        cout<<"Sum of matrices is: "<<endl;
        for(int i =0; i<n; i++){
            for(int j = 0; j<n; j++){
                cout<<sum[i][j]<<" ";
            }
            cout<<endl;
        }
        return 0;
    
        
    }

    
  