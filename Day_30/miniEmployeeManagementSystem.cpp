#include<iostream>
#include<string>
using namespace std;
int main(){
    int employeeID[100];
    string employeeName[100];
    int age[100];
    string gender[100];
    string department[100];
    float salary[100];
    bool activeStatus[100];
    int totalEmployee = 0;
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
        cout<<"14.Count Male and Female Employees"<<endl;
        cout<<"15. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{
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
                        break;
                    }
                    cout<<"Enter Employee Name: ";
                    cin.ignore();
                    getline(cin, employeeName[totalEmployee]);
                    cout<<"Enter Age: ";
                    cin>>age[totalEmployee];
                    if(age[totalEmployee]<18 || age[totalEmployee]>65){
                        cout<<"Invalid age! Employee age must be between 18 and 65."<<endl;
                        break;
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
                        break;
                    }
                   activeStatus[totalEmployee] = true;
                    totalEmployee++;
                }else{
                    cout<<"Maximum employee limit reached!"<<endl;
                }
                break;
            }
            case 2:{
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
                        cout<<"Active Status: "<<activeStatus[i]<<endl;
                        cout<<"-----------------------------"<<endl;
                        found = true;
                        break;
                    }
                }
                if(!found){
                    cout<<"Employee not found!"<<endl;
                }
                break;
            }
            case 3:{
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
                break;

            }
            case 4:{
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
                        cout<<"Enter Gender: ";
                        cin.ignore();
                        getline(cin, gender[i]);
                        cout<<"Enter Department: ";
                        getline(cin, department[i]);
                        cout<<"Enter Salary: ";
                        cin>>salary[i];
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
                int deleteID;
                cout<<"Enter Employee ID to delete: ";
                cin>>deleteID;
                bool found = false;
                for(int i=0;i<totalEmployee;i++){
                    if( activeStatus[i] && employeeID[i]==deleteID){
                        for(int j=i;j<totalEmployee-1;j++){
                            employeeID[j]=employeeID[j+1];
                            employeeName[j]=employeeName[j+1];
                            age[j]=age[j+1];
                            gender[j]=gender[j+1];
                            department[j]=department[j+1];
                            salary[j]=salary[j+1];
                            activeStatus[j]=activeStatus[j+1];
                        }
                        totalEmployee--;
                        activeStatus[totalEmployee] = false; // Mark the last employee as inactive
                        activeStatus[i] = false; // Mark the deleted employee as inactive
                        cout<<"Employee deleted successfully!"<<endl;
                        found = true;
                        break;
                    }
                }
                if(!found){
                    cout<<"Employee not found!"<<endl;
                }
                break;
            }
            case 6:{
                float totalSalary = 0;
                for(int i=0;i<totalEmployee;i++){
                    if(activeStatus[i]){
                        totalSalary += salary[i];
                    }
                }
                cout<<"Total Salary of all employees: "<<totalSalary<<endl;
                break;
            }
            case 7:{
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
                            found = true; // Mark as found to avoid "Employee not found" message
                            break;
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
                break;
            }
            case 8:{
                if(totalEmployee==0){
                    cout<<"No employees to evaluate!"<<endl;
                }else{
                    int highestIndex = 0;
                    for(int i=1;i<totalEmployee;i++){
                        if( activeStatus[i] && salary[i]>salary[highestIndex]){
                            highestIndex = i;
                        }
                    }
                    cout<<"Employee with Highest Salary:"<<endl;
                    cout<<"ID: "<<employeeID[highestIndex]<<endl;
                    cout<<"Name: "<<employeeName[highestIndex]<<endl;
                    cout<<"Salary: "<<salary[highestIndex]<<endl;
                }
                break;
            }
            case 9:{
                if(totalEmployee==0){
                    cout<<"No employees to evaluate!"<<endl;
                }else{
                    int lowestIndex = 0;
                    for(int i=1;i<totalEmployee;i++){
                        if( activeStatus[i] && salary[i]<salary[lowestIndex]){
                            lowestIndex = i;
                        }
                    }
                    cout<<"Employee with Lowest Salary:"<<endl;
                    cout<<"ID: "<<employeeID[lowestIndex]<<endl;
                    cout<<"Name: "<<employeeName[lowestIndex]<<endl;
                    cout<<"Salary: "<<salary[lowestIndex]<<endl;
                }
                break;
            }
            case 10:{
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
                break;

            }
            case 11:{
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
                break;
            }
            case 12:{
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
                break;
            }
            case 13:{
                cout<<"Total Employees: "<<totalEmployee<<endl;
                cout<<"Active Employees: ";
                int activeCount = 0;
                for(int i=0;i<totalEmployee;i++){
                    if(activeStatus[i]){
                        activeCount++;
                    }
                    cout<<"Deleted Employees: ";
                int deletedCount = totalEmployee - activeCount;
                cout<<deletedCount<<endl;

                }
                break;
            }
            case 14:{
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
                break;
            }
            case 15:{
                cout<<"Exiting the program. Goodbye!"<<endl;
                break;
            }
            default:{
                cout<<"Invalid choice! Please try again."<<endl;
                break;
            }

        }
    }
    while(choice!=15);
    return 0;
}