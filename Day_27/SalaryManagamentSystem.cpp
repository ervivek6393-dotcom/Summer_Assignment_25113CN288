#include<iostream>
#include<string>
using namespace std;
int main(){
   int employeeID[100];
   string employeeName[100];
   float basicSalary[100];
   float hra[100];
   float da[100];
   float tax[100];
   float bonus[100];
   float netSalary[100];
   int totalEmployees = 0;
   int choice;
   cout<<"====SALARY MANAGEMENT SYSTEM===="<<endl;
   do{
    cout<<"1. Add Employee Salary Details"<<endl;
    cout<<"2. Display Employee Salary Details"<<endl;
    cout<<"3. Search Employee Salary Details"<<endl;
    cout<<"4. Update Employee Salary DEtails"<<endl;
    cout<<"5. Delete Employee Salary Details"<<endl;
    cout<<"6. Calculate Employee Salary"<<endl;
    cout<<"7. Salary Slip"<<endl;
    cout<<"8. Exit"<<endl;
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
            if(idExists){
                cout<<"Employee ID already exists!"<<endl;
                break;
            }
            cout<<"Enter Employee Name: ";
            cin.ignore();
            getline(cin, employeeName[totalEmployees]);
            cout<<"Enter Basic Salary: ";
            cin>>basicSalary[totalEmployees];
            if(basicSalary[totalEmployees] < 0){
                cout<<"Basic Salary cannot be negative!"<<endl;
                break;
            }
            cout<<"Enter Bonus: ";
            cin>>bonus[totalEmployees];
            if(bonus[totalEmployees] < 0){
                cout<<"Bonus cannot be negative!"<<endl;
                break;
            }
            hra[totalEmployees] = basicSalary[totalEmployees]*0.20;
            da[totalEmployees] = basicSalary[totalEmployees]*0.10;
            tax[totalEmployees] = (basicSalary[totalEmployees]+hra[totalEmployees]+da[totalEmployees])*0.10;
            netSalary[totalEmployees] = basicSalary[totalEmployees]+hra[totalEmployees]+ da[totalEmployees]+bonus[totalEmployees]-tax[totalEmployees];
            totalEmployees++;
            cout<<"Employee Salary Details added successfully!"<<endl;
            break;


        }
        case 2:{
            cout<<"====DISPLAY EMPLOYEE SALARY DETAILS===="<<endl;
            if(totalEmployees == 0){
                cout<<"No employee salary details found!"<<endl;
                break;
            }
            for(int i =0; i<totalEmployees; i++){
                cout<<"Employee"<<i+1<<":"<<endl;
                cout<<"--------------------------------"<<endl;
                cout<<"Employee ID: "<<employeeID[i]<<endl;
                cout<<"Employee Name: "<<employeeName[i]<<endl;
                cout<<"Basic Salary: "<<basicSalary[i]<<endl;
                cout<<"HRA: "<<hra[i]<<endl;
                cout<<"DA: "<<da[i]<<endl;
                cout<<"Bonus: "<<bonus[i]<<endl;
                cout<<"Tax: "<<tax[i]<<endl;
                cout<<"Net Salary: "<<netSalary[i]<<endl;
                cout<<"--------------------------------"<<endl;
            }
            break;
        }
        case 3:{
            cout<<"====SEARCH EMPLOYEE SALARY DETAILS===="<<endl;
            int searchID;
            cout<<"Enter Employee ID: ";
            cin>>searchID;
            bool found = false;
            for(int i =0; i<totalEmployees; i++){
                if(employeeID[i] == searchID){
                    cout<<"Employee ID: "<<employeeID[i]<<endl;
                    cout<<"Employee Name: "<<employeeName[i]<<endl;
                    cout<<"Basic Salary: "<<basicSalary[i]<<endl;
                    cout<<"HRA: "<<hra[i]<<endl;
                    cout<<"DA: "<<da[i]<<endl;
                    cout<<"Bonus: "<<bonus[i]<<endl;
                    cout<<"Tax: "<<tax[i]<<endl;
                    cout<<"Net Salary: "<<netSalary[i]<<endl;
                    cout<<"Employee Salary Details found!"<<endl;
                    found = true;
                    break;
                }
            }
            if(!found){
                cout<<"Employee not found!"<<endl;
            }
            break;
        }
        case 4:{
            cout<<"====UPDATE EMPLOYEE SALARY DETAILS===="<<endl;
            int updateID;
            cout<<"Enter Employee ID: ";
            cin>>updateID;
            bool found = false;
            for(int i =0; i<totalEmployees; i++){
                if(employeeID[i] == updateID){
                    cout<<"Enter New Basic Salary: ";
                    cin>>basicSalary[i];
                    if(basicSalary[i] <= 0){
                        cout<<"Invalid Basic Salary!"<<endl;
                        break;
                    }
                    cout<<"Enter New Bonus: ";
                    cin>>bonus[i];
                    if(bonus[i] < 0){
                        cout<<"Invalid Bonus!"<<endl;
                        break;
                    }
                    hra[i] = basicSalary[i]*0.20;
                    da[i] = basicSalary[i]*0.10;
                    tax[i] = (basicSalary[i]+hra[i]+da[i])*0.10;
                    netSalary[i] = basicSalary[i]+hra[i]+ da[i]+bonus[i]-tax[i];
                    cout<<"Employee Salary Details updated successfully!"<<endl;
                    found = true;
                    break;
                }
            }
            if(!found){
                cout<<"Employee not found!"<<endl;
            }
            break;
        }
        case 5:{
            cout<<"====DELETE EMPLOYEE SALARY DETAILS===="<<endl;
            int deleteID;
            cout<<"Enter Employee ID: ";
            cin>>deleteID;
            bool deleted = false;
            for(int i =0; i<totalEmployees; i++){
                if(employeeID[i] == deleteID){
                    deleted = true;
                    // Shift elements to the left to remove the employee
                    for(int j = i; j<totalEmployees-1; j++){
                        employeeID[j] = employeeID[j+1];
                        employeeName[j] = employeeName[j+1];
                        basicSalary[j] = basicSalary[j+1];
                        hra[j] = hra[j+1];
                        da[j] = da[j+1];
                        bonus[j] = bonus[j+1];
                        tax[j] = tax[j+1];
                        netSalary[j] = netSalary[j+1];
                    }
                    totalEmployees--;
                    break;
                }
            }
            if(deleted){
                cout<<"Employee deleted successfully!"<<endl;
            }else{
                cout<<"Employee not found!"<<endl;
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
                    cout<<"Basic Salary: "<<basicSalary[i]<<endl;
                    cout<<"HRA: "<<hra[i]<<endl;
                    cout<<"DA: "<<da[i]<<endl;
                    cout<<"Bonus: "<<bonus[i]<<endl;
                    cout<<"Tax: "<<tax[i]<<endl;
                    cout<<"Net Salary: "<<netSalary[i]<<endl;
                    found = true;
                    break;
                }
            }
            if(!found){
                cout<<"Employee not found!"<<endl;
            }
            break;
        }
        case 7:{
            cout<<"============================="<<endl;
            cout<<"       SALARY SLIP"<<endl;
            cout<<"============================="<<endl;
            cout<<"Enter Employee ID: ";
            int slipID;
            cin>>slipID;
            bool found = false;
            for(int i =0; i<totalEmployees; i++){
                if(employeeID[i] == slipID){
                    cout<<"Employee ID: "<<employeeID[i]<<endl;
                    cout<<"Employee Name: "<<employeeName[i]<<endl;
                    cout<<"-----------------------------"<<endl;
                    cout<<"Basic Salary: "<<basicSalary[i]<<endl;
                    cout<<"HRA: "<<hra[i]<<endl;
                    cout<<"DA: "<<da[i]<<endl;
                    cout<<"Bonus: "<<bonus[i]<<endl;
                    cout<<"Tax: "<<tax[i]<<endl;
                    cout<<"-----------------------------"<<endl;
                    cout<<"Net Salary     : "<<netSalary[i]<<endl;
                    cout<<"============================="<<endl;
                    found = true;
                    break;
                }
            }
            if(!found){
                cout<<"Employee not found!"<<endl;
            }
            break;
        }
        case 8:{
            cout<<"Exiting..."<<endl;
            break;
        }
    }
   }
    while(choice != 8);
}