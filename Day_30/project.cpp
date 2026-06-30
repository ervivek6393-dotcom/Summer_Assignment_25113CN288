#include<iostream>
#include<string>
using namespace std;
// Global Arrays
int employeeID[100];
string employeeName[100];
int age[100];
string gender[100];
string department[100];
float salary[100];
bool activeStatus[100]; // Array to track active status of employees
int totalEmployee =0;

// Function Prototypes
void addEmployee(){
     if(totalEmployee<100){
                    cout<<"Enter Employee ID: ";
                    cin>>employeeID[totalEmployee];
                    bool exists = false;
                    for(int i=0;i<totalEmployee;i++){
                        if(employeeID[i]==employeeID[totalEmployee]){
                            exists = true;
                            break;
                        }
                    }
                    if(exists){
                        cout<<"Employee with ID "<<employeeID[totalEmployee]<<" already exists!"<<endl;
                        return;
                    }
                    cout<<"Enter Employee Name: ";
                    cin.ignore();
                    getline(cin, employeeName[totalEmployee]);
                    cout<<"Enter Age: ";
                    cin>>age[totalEmployee];
                    if(age[totalEmployee]<18 || age[totalEmployee]>65){
                        cout<<"Invalid age! Employee age must be between 18 and 65."<<endl;
                        return;
                    }
                    cout<<"Enter Gender: ";
                    cin.ignore();
                    getline(cin, gender[totalEmployee]);
                    cout<<"Enter Department: ";
                    getline(cin, department[totalEmployee]);
                    cout<<"Enter Salary: ";
                    cin>>salary[totalEmployee];
                    if(salary[totalEmployee]<0){
                        cout<<"Invalid salary! Salary cannot be negative."<<endl;
                        return;
                    }
                   activeStatus[totalEmployee] = true;
                    totalEmployee++;
                }else{
                    cout<<"Maximum employee limit reached!"<<endl;
                }
}
void searchEmployee(){
     int searchID;
                cout<<"Enter Employee ID to search: ";
                cin>>searchID;
                bool found = false;
                for(int i=0;i<totalEmployee;i++){
                    if( activeStatus[i] && employeeID[i]==searchID){
                        cout<<"Employee Found!"<<endl;
                        cout<<"-----------------------------"<<endl;
                        cout<<"ID: "<<employeeID[i]<<endl;
                        cout<<"Name: "<<employeeName[i]<<endl;
                        cout<<"Age: "<<age[i]<<endl;
                        cout<<"Gender: "<<gender[i]<<endl;
                        cout<<"Department: "<<department[i]<<endl;
                        cout<<"Salary: "<<salary[i]<<endl;
                        cout<<" Active Status: "<<(activeStatus[i] ? "Active" : "Inactive")<<endl;
                        cout<<"-----------------------------"<<endl;
                        found = true;
                        break;
                    }
                }
                if(!found){
                    cout<<"Employee not found!"<<endl;
                }
}
void displayEmployeeDetails(){
        if(totalEmployee==0){
                    cout<<"No employees to display!"<<endl;
                }else{
                    cout<<"Employee Details:"<<endl;
                    cout<<"-----------------------------"<<endl;
                    for(int i=0;i<totalEmployee;i++){
                        if(!activeStatus[i]) continue; // Skip inactive employees
                        cout<<"ID: "<<employeeID[i]<<endl;
                        cout<<"Name: "<<employeeName[i]<<endl;
                        cout<<"Department: "<<department[i]<<endl;
                        cout<<"Salary: "<<salary[i]<<endl;
                        cout<<"-----------------------------"<<endl;
                    }
                    
                }
}
void updateEmployeeDetails(){
      int updateID;
                cout<<"Enter Employee ID to update: ";
                cin>>updateID;
                bool found = false;
                for(int i=0;i<totalEmployee;i++){
                    if( activeStatus[i] && employeeID[i]==updateID){
                        cout<<"Employee Found!"<<endl;
                        cout<<"Enter new details:"<<endl;
                        cout<<"Enter Employee Name: ";
                        cin.ignore();
                        getline(cin, employeeName[i]);
                        cout<<"Enter Age: ";
                        cin>>age[i];
                        if(age[i]<18 || age[i]>65){
                            cout<<"Invalid age! Employee age must be between 18 and 65."<<endl;
                            return;
                        }
                        cout<<"Enter Gender: ";
                        cin.ignore();
                        getline(cin, gender[i]);
                        cout<<"Enter Department: ";
                        getline(cin, department[i]);
                        cout<<"Enter Salary: ";
                        cin>>salary[i];
                        if(salary[i]<0){
                            cout<<"Invalid salary! Salary cannot be negative."<<endl;
                            return;
                        }
                        found = true;
                        break;
                    }
                }
                if(!found){
                    cout<<"Employee not found!"<<endl;
                }

}
void deleteEmployee(){
     int deleteID;
                cout<<"Enter Employee ID to delete: ";
                cin>>deleteID;
                bool found = false;
                for(int i=0;i<totalEmployee;i++){
                    if( activeStatus[i] && employeeID[i]==deleteID){
                        activeStatus[i] = false; // Mark the employee as inactive
                        cout<<"Employee Deleted Successfully!"<<endl;
                        found = true;
                        return; // Exit the function after deletion
                       }
                }
                if(!found){
                    cout<<"Employee Not Found!"<<endl;
                }
                
            }

void calculateTotalSalary(){
      float totalSalary = 0;
                for(int i=0;i<totalEmployee;i++){
                    if(activeStatus[i]){
                        totalSalary += salary[i];
                    }
                }
                cout<<"Total Salary of all employees: "<<totalSalary<<endl;
}
void increaseSalary(){
      int increaseID;
                float increaseAmount;
                cout<<"Enter Employee ID to increase salary: ";
                cin>>increaseID;
                cout<<"Enter amount to increase: ";
                cin>>increaseAmount;
                bool found = false;
                for(int i=0;i<totalEmployee;i++){
                    if( activeStatus[i] && employeeID[i]==increaseID){
                        if(increaseAmount <= 0){
                            cout<<"Invalid increase amount! It must be positive."<<endl;
                           return;
                        }
                        salary[i] += increaseAmount;
                        cout<<"Salary updated successfully!"<<endl;
                        found = true;
                        break;
                    }
                }
                if(!found){
                    cout<<"Employee not found!"<<endl;
                }

    
}
void findHighestSalary(){
        if(totalEmployee==0){
                    cout<<"No employees to evaluate!"<<endl;
                }else{
                    int highestIndex = -1;
                    for(int i=0;i<totalEmployee;i++){
                        if( activeStatus[i] && (highestIndex == -1 || salary[i] > salary[highestIndex])){
                            highestIndex = i;
                        }
                    }
                    cout<<"Employee with Highest Salary:"<<endl;
                    cout<<"ID: "<<employeeID[highestIndex]<<endl;
                    cout<<"Name: "<<employeeName[highestIndex]<<endl;
                    cout<<"Salary: "<<salary[highestIndex]<<endl;
                }
    
}
void findLowestSalary(){
      if(totalEmployee==0){
                    cout<<"No employees to evaluate!"<<endl;
                }else{
                    int lowestIndex = -1;
                    for(int i=0;i<totalEmployee;i++){
                        if( activeStatus[i] && (lowestIndex == -1 || salary[i] < salary[lowestIndex])){
                            lowestIndex = i;
                        }
                    }
                    cout<<"Employee with Lowest Salary:"<<endl;
                    cout<<"ID: "<<employeeID[lowestIndex]<<endl;
                    cout<<"Name: "<<employeeName[lowestIndex]<<endl;
                    cout<<"Salary: "<<salary[lowestIndex]<<endl;
                }
    
}
void sortEmployeesBySalary(){
        for(int i=0;i<totalEmployee-1;i++){
                    for(int j=0;j<totalEmployee-i-1;j++){
                        if( activeStatus[j] && salary[j]>salary[j+1]){
                            swap(employeeID[j], employeeID[j+1]);
                            swap(employeeName[j], employeeName[j+1]);
                            swap(age[j], age[j+1]);
                            swap(gender[j], gender[j+1]);
                            swap(department[j], department[j+1]);
                            swap(salary[j], salary[j+1]);
                            swap(activeStatus[j], activeStatus[j+1]);
                        }
                    }
                }
                cout<<"Employees sorted by salary (highest to lowest):"<<endl;
                for(int i=0;i<totalEmployee;i++){
                    cout<<"ID: "<<employeeID[i]<<", Name: "<<employeeName[i]<<", Age: "<<age[i]<<", Salary: "<<salary[i]<<endl;
                }
}
void searchEmployeesByDepartment(){
       string searchDepartment;
                cout<<"Enter Department to search: ";
                cin.ignore();
                getline(cin, searchDepartment);
                bool found = false;
                for(int i=0;i<totalEmployee;i++){
                    if(activeStatus[i] && department[i]==searchDepartment){
                        cout<<"ID: "<<employeeID[i]<<", Name: "<<employeeName[i]<<", Age: "<<age[i]<<", Salary: "<<salary[i]<<endl;
                        found = true;
                    }
                }
                if(!found){
                    cout<<"No employees found in this department!"<<endl;
                }


}
void countMaleFemaleEmployees(){
      int maleCount = 0;
                int femaleCount = 0;
                for(int i=0;i<totalEmployee;i++){
                    if(!activeStatus[i]) continue; // Skip inactive employees
                if(gender[i]=="Male" || gender[i]=="Female"){
                    if(gender[i]=="Male"){
                        maleCount++;
                    }else if(gender[i]=="Female"){
                        femaleCount++;
                    }
                }
                }
                cout<<"Male Employees: "<<maleCount<<endl;
                cout<<"Female Employees: "<<femaleCount<<endl;


}
void displayActiveEmployees(){
      cout<<"Active Employees:"<<endl;
                bool found = false;
                for(int i=0;i<totalEmployee;i++){
                    if(activeStatus[i]){
                        cout<<"ID: "<<employeeID[i]<<", Name: "<<employeeName[i]<<", Age: "<<age[i]<<", Salary: "<<salary[i]<<endl;
                        found = true;
                    }
                }
                if(!found){
                    cout<<"No active employees found!"<<endl;
                }


}
void totalEmployeesCount(){
     int activeCount=0;

    for(int i=0;i<totalEmployee;i++){

        if(activeStatus[i]){
            activeCount++;
        }

    }

    int deletedCount=totalEmployee-activeCount;

    cout<<"Total Employees : "<<totalEmployee<<endl;
    cout<<"Active Employees : "<<activeCount<<endl;
    cout<<"Deleted Employees : "<<deletedCount<<endl;




}
void exitProgram(){
    cout<<"Exiting the program. Goodbye!"<<endl;

}
int main(){
    int choice;
    do{
        cout<<"==== Mini Employee Management System ===="<<endl;
        cout<<"1. Add Employee"<<endl;
        cout<<"2. Search Employee"<<endl;
        cout<<"3. Display Employee Details"<<endl;
        cout<<"4. Update Employee Details"<<endl;
        cout<<"5. Delete Employee"<<endl;
        cout<<"6. Calculate Total Salary"<<endl;
        cout<<"7. Increase Salary"<<endl;
        cout<<"8. Find Employee with Highest Salary"<<endl;
        cout<<"9. Find Employee with Lowest Salary"<<endl;
        cout<<"10. Sort Employees by Salary"<<endl;
        cout<<"11. Search Employees by Department"<<endl;
        cout<<"12. Display Active Employees"<<endl;
        cout<<"13. Total Employees: "<<totalEmployee<<endl;
        cout<<"14. Count Male and Female Employees"<<endl;
        cout<<"15. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{
            addEmployee();
            break;
            }
            case 2:{
                searchEmployee();
                break;
            }
            case 3:{
                displayEmployeeDetails();
                break;
            }
            case 4:{
                updateEmployeeDetails();
                break;
            }
            case 5:{
                deleteEmployee();
                break;
            }
            case 6:{
                calculateTotalSalary();
                break;
            }
            case 7:{
                increaseSalary();
                break;
            }
            case 8:{
                findHighestSalary();
                break;
            }
            case 9:{
                findLowestSalary();
                break;

            }
            case 10:{
                sortEmployeesBySalary();
                break;
            }
            case 11:{
                searchEmployeesByDepartment();
                break;
            }
            case 12:{
                displayActiveEmployees();
                break;
            }
            case 13:{
                totalEmployeesCount();
                break;
            }
            case 14:{
                countMaleFemaleEmployees();
                break;
            }
            case 15:{
                exitProgram();
                break;
            }
            default:{
                cout<<"Invalid choice! Please try again."<<endl;
                break;
            }

        }
    }while(choice!=15);
    return 0;
}