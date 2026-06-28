#include<iostream>
#include<string>
using namespace std;
int main(){
    int choice;
    int employeeID[100];
    string employeeName[100];
    int employeeage[100];
    string employeeDepartment[100];
    string Designation[100];
    float basicSalary[100];
    float bonus[100];
    float totalSalary[100];
    int totalEmployees = 0;
    do{
    cout<<"====EMPLOYEE MANAGEMENT SYSTEM===="<<endl;
    cout<<"1. Add Employee"<<endl;
    cout<<"2. Display Employee"<<endl;
    cout<<"3. Search Empployee"<<endl;
    cout<<"4. Update Employee"<<endl;
    cout<<"5. Delete Employee"<<endl;
    cout<<"6. Calculate Salary"<<endl;
    cout<<"7. Exit"<<endl;
    cout<<"Total Employees: "<<totalEmployees<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice){
        case 1:{
            cout<<"Enter Employee ID: ";
            cin>>employeeID[totalEmployees];
            bool idExists = false;
            for(int i =0; i<totalEmployees; i++){
                if(employeeID[i] == employeeID[totalEmployees]){
                    idExists = true;
                    break;
                }
            }
            if(!idExists){
                cout<<"Enter Employee Name: ";
                cin.ignore();
                getline(cin, employeeName[totalEmployees]);
                cout<<"Enter Employee Age: ";
                cin>>employeeage[totalEmployees];
                cout<<"Enter Employee Department: ";
                cin.ignore();
                getline(cin, employeeDepartment[totalEmployees]);
                cout<<"Enter Employee Designation: ";
                getline(cin, Designation[totalEmployees]);
                cout<<"Enter Basic Salary: ";
                cin>>basicSalary[totalEmployees];
                cout<<"Enter Bonus: ";
                cin>>bonus[totalEmployees];
                totalSalary[totalEmployees] = basicSalary[totalEmployees] + bonus[totalEmployees];
                totalEmployees++;
                cout<<"Employee added successfully!"<<endl;
            }else{
                cout<<"Employee with ID "<<employeeID[totalEmployees]<<" already exists!"<<endl;
            }
            
            break;
        }
        case 2:{
            cout<<"====DISPLAY EMPLOOYEE DETAILS===="<<endl;
            if(totalEmployees == 0){
                cout<<"No employees found!"<<endl;
                break;
            }
            for(int i =0; i<totalEmployees; i++){
                cout<<"employee "<<i+1<<":"<<endl;
                cout<<"--------------------------------"<<endl;
                    cout<<"Employee ID: "<<employeeID[i]<<endl;
                    cout<<"Employee Name: "<<employeeName[i]<<endl;
                    cout<<"Employee Agee: "<<employeeage[i]<<endl;
                    cout<<"Employee Department: "<<employeeDepartment[i]<<endl;
                    cout<<"Employee Designation: "<<Designation[i]<<endl;
                    cout<<"Employee Basic Salary: "<<basicSalary[i]<<endl;
                    cout<<"Employee Bonus: "<<bonus[i]<<endl;
                    cout<<"Employee Total Salary: "<<totalSalary[i]<<endl;
                    cout<<"--------------------------------"<<endl;
             
                        } break;
        }
        case 3:{
            cout<<"====SEARCH EMPLOYEE DETAILS===="<<endl;
            cout<<"Enter Employee ID: ";
            int searchID;
            cin>>searchID;
            bool found = false;
            for(int i =0; i<totalEmployees; i++){
                if(employeeID[i] == searchID){
                    cout<<"Employee ID: "<<employeeID[i]<<endl;
                    cout<<"Employee Name: "<<employeeName[i]<<endl;
                    cout<<"Employee Agee: "<<employeeage[i]<<endl;
                    cout<<"Employee Department: "<<employeeDepartment[i]<<endl;
                    cout<<"Employee Designation: "<<Designation[i]<<endl;
                    cout<<"Employee Basic Salary: "<<basicSalary[i]<<endl;
                    cout<<"Employee Bonus: "<<bonus[i]<<endl;
                    cout<<"Employee Total Salary: "<<totalSalary[i]<<endl;
                    found = true;
                    break;

                }
            }
            if(!found){
                cout<<"Employee with ID "<<searchID<<" not found!"<<endl;
            }
             break;
        }   
        case 4:{
            cout<<"====UPDATE EMPLOYEE DETAILS===="<<endl;
            cout<<"Enter Employee ID: ";
            int updateID;
            cin>>updateID;
            bool updated = false;
            for(int i =0; i<totalEmployees; i++){
                if(employeeID[i] == updateID){
                    cout<<"Enter Employee Name: ";
                    cin.ignore();
                    getline(cin, employeeName[i]);
                    cout<<"Enter Employee Age: ";
                    cin>>employeeage[i];
                    cout<<"Enter Employee Department: ";
                    cin.ignore();
                    getline(cin, employeeDepartment[i]);
                    cout<<"Enter Employee Designation: ";
                    getline(cin, Designation[i]);
                    cout<<"Enter Employee Basic Salary: ";
                    cin>>basicSalary[i];
                    cout<<"Enter Employee Bonus: ";
                    cin>>bonus[i];
                    totalSalary[i] = basicSalary[i] + bonus[i];
                    updated = true;
                    cout<<"Employee with ID "<<updateID<<" updated successfully!"<<endl;
                }
            }
            if(!updated){
                cout<<"Employee with ID "<<updateID<<" not found!"<<endl;
            }
            break;
        }
        case 5:{
            cout<<"====DELETE EMPLOYEE DETAILS===="<<endl;
            cout<<"Enter Employee ID: ";
            int deleteID;
            cin>>deleteID;
            bool deleted = false;
            for(int i =0; i<totalEmployees; i++){
                if(employeeID[i] == deleteID){
                    deleted = true;
                    for(int j =i; j<totalEmployees-1; j++){
                        employeeID[j] = employeeID[j+1];
                        employeeName[j] = employeeName[j+1];
                        employeeage[j] = employeeage[j+1];
                        employeeDepartment[j] = employeeDepartment[j+1];
                        Designation[j] = Designation[j+1];
                        basicSalary[j] = basicSalary[j+1];
                        bonus[j] = bonus[j+1];
                        totalSalary[j] = totalSalary[j+1];
                    }
                    totalEmployees--;
                    cout<<"Employee with ID "<<deleteID<<" deleted successfully!"<<endl;
                    break;
                }
            }
            if(!deleted){
                cout<<"Employee with ID "<<deleteID<<" not found!"<<endl;
            }
            break;
        }
        case 6:{
            cout<<"====CALCULATE EMPLOYEE SALARY===="<<endl;
           int searchID;
            cout<<"Enter Employee ID: ";
            cin>>searchID;
            bool found = false;
            for(int i =0; i<totalEmployees; i++){
                if(employeeID[i] == searchID){
                    cout<<"Employee Name: "<<employeeName[i]<<endl;
                    float hra = basicSalary[i] *0.20;
                    float da = basicSalary[i] *0.10;
                    float salary = basicSalary[i] + hra + da + bonus[i];
                   cout<<"Basic Salary: "<<basicSalary[i]<<endl;
                   cout<<"HRA: "<<hra<<endl;
                     cout<<"DA: "<<da<<endl;    
                     cout<<"Bonus: "<<bonus[i]<<endl;
                    cout<<"Total Salary: "<<salary<<endl;
                    found = true;           
                   
                    break;
                }
            }
            if(!found){
                cout<<"Employee with ID "<<searchID<<" not found!"<<endl;
            }
            break;
          
        }
        case 7:{
            cout<<"Exiting..."<<endl;
            break;
        }
    
    }
    
}
while(choice != 7);
}