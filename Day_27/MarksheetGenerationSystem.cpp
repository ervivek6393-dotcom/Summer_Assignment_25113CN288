#include<iostream>
#include<string>
using namespace std;
int main(){
    int studentID[100];
    string studentName[100];
    float english[100];
    float math[100];
    float science[100];
    float computer[100];
    float social[100];
    float totalMarks[100];
    float percentage[100];
    char grade[100];
    string result[100];
    int totalStudents = 0;
    int choice;
    do{
        cout<<"====MARKSHEET GENERATION SYSTEM===="<<endl;
        cout<<"1. Add Student Marks"<<endl;
        cout<<"2. Display Student Marks"<<endl;
        cout<<"3. Search Student Marks"<<endl;
        cout<<"4. Update Student Marks"<<endl;
        cout<<"5. Delete Student Marks"<<endl;
        cout<<"6. Calculate Student Result"<<endl;
        cout<<"7. Student Rank"<<endl;
        cout<<"8. Exit"<<endl;
        cout<<"Total Students: "<<totalStudents<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"====ADD STUDENT MARKS===="<<endl;
                cout<<"Enter Student ID: ";
                cin>>studentID[totalStudents];
                bool idExists = false;
                for(int i =0; i<totalStudents; i++){
                    if(studentID[i] == studentID[totalStudents]){
                        idExists = true;
                        break;
                    }
                }
                if(!idExists){
                    cout<<"Enter Student Name: ";
                    cin.ignore();
                    getline(cin, studentName[totalStudents]);
                    cout<<"Enter English Marks: ";
                    cin>>english[totalStudents];
                    if(english[totalStudents] < 0 || english[totalStudents] > 100){
                        cout<<"Invalid Marks! Please enter marks between 0 and 100."<<endl;
                        break;
                    }
                    cout<<"Enter Math Marks: ";
                    cin>>math[totalStudents];
                    if(math[totalStudents] < 0 || math[totalStudents] > 100){
                        cout<<"Invalid Marks! Please enter marks between 0 and 100."<<endl;
                        break;
                    }
                    cout<<"Enter Science Marks: ";
                    cin>>science[totalStudents];
                    if(science[totalStudents] < 0 || science[totalStudents] > 100){
                        cout<<"Invalid Marks! Please enter marks between 0 and 100."<<endl;
                        break;
                    }
                    cout<<"Enter Computer Marks: ";
                    cin>>computer[totalStudents];
                    if(computer[totalStudents] < 0 || computer[totalStudents] > 100){
                        cout<<"Invalid Marks! Please enter marks between 0 and 100."<<endl;
                        break;
                    }
                    cout<<"Enter Social Marks: ";
                    cin>>social[totalStudents];
                    if(social[totalStudents] < 0 || social[totalStudents] > 100){
                        cout<<"Invalid Marks! Please enter marks between 0 and 100."<<endl;
                        break;
                    }
                    totalMarks[totalStudents] = english[totalStudents] + math[totalStudents] + science[totalStudents] + computer[totalStudents] + social[totalStudents];
                    percentage[totalStudents] = (totalMarks[totalStudents]/500)*100;
                    if(english[totalStudents] >= 33 && math[totalStudents] >= 33 && science[totalStudents] >= 33 && computer[totalStudents] >= 33 && social[totalStudents] >= 33){
                        result[totalStudents] = "Pass";
                    }
                    else{
                        result[totalStudents] = "Fail";
                    }
                    if(percentage[totalStudents] >= 90){
                        grade[totalStudents] = 'A';
                        result[totalStudents] = "Pass";

                    }
                    else if(percentage[totalStudents] >= 80){
                        grade[totalStudents] = 'B';
                        result[totalStudents] = "Pass";

                    }
                    else if(percentage[totalStudents] >= 70){
                        grade[totalStudents] = 'C';
                        result[totalStudents] = "Pass";
                    }
                    else if(percentage[totalStudents] >= 60){
                        grade[totalStudents] = 'D';
                        result[totalStudents] = "Pass";
                    }
                    else{
                        grade[totalStudents] = 'F';
                        result[totalStudents] = "Fail";
                    }
                    totalStudents++;
                    cout<<"Student Marks added successfully!"<<endl;


                }
                break;
            }
            case 2:{
                cout<<"====DISPLAY STUDENT MARKS===="<<endl;
                cout<<"Total Students: "<<totalStudents<<endl;
                if(totalStudents == 0){
                    cout<<"No student marks found!"<<endl;
                    break;
                }
                for(int i =0; i<totalStudents; i++){
                    cout<<"Student "<<i+1<<":"<<endl;
                    cout<<"--------------------------------"<<endl;
                    cout<<"Student ID: "<<studentID[i]<<endl;
                    cout<<"Student Name: "<<studentName[i]<<endl;
                    cout<<"English Marks: "<<english[i]<<endl;
                    cout<<"Math Marks: "<<math[i]<<endl;
                    cout<<"Science Marks: "<<science[i]<<endl;
                    cout<<"Computer Marks: "<<computer[i]<<endl;
                    cout<<"Social Marks: "<<social[i]<<endl;
                    cout<<"Total Marks: "<<totalMarks[i]<<endl;
                    cout<<"Percentage: "<<percentage[i]<<"%"<<endl;
                    cout<<"Grade: "<<grade[i]<<endl;
                    cout<<"Result: "<<result[i]<<endl;
                    cout<<"--------------------------------"<<endl;
                }
                break;
            }
            case 3:{
                cout<<"====SEARCH STUDENT MARKS===="<<endl;
                cout<<"Enter Student ID: ";
                int searchID;
                cin>>searchID;
                bool found = false;
                for(int i =0; i<totalStudents; i++){
                    if(studentID[i] == searchID){
                        cout<<"Student ID: "<<studentID[i]<<endl;
                        cout<<"Student Name: "<<studentName[i]<<endl;
                        cout<<"English Marks: "<<english[i]<<endl;
                        cout<<"Math Marks: "<<math[i]<<endl;
                        cout<<"Science Marks: "<<science[i]<<endl;
                        cout<<"Computer Marks: "<<computer[i]<<endl;
                        cout<<"Social Marks: "<<social[i]<<endl;
                        cout<<"Total Marks: "<<totalMarks[i]<<endl;
                        cout<<"Percentage: "<<percentage[i]<<"%"<<endl;
                        cout<<"Grade: "<<grade[i]<<endl;
                        cout<<"Result: "<<result[i]<<endl;
                        found = true;
                        break;
                    }
                }
                if(!found){
                    cout<<"Student not found!"<<endl;
                }
                break;
            }
            case 4:{
                cout<<"====UPDATE STUDENT MARKS===="<<endl;
                cout<<"Enter Student ID: ";
                int updateID;
                cin>>updateID;
                bool found = false;
                for(int i =0; i<totalStudents; i++){
                    if(studentID[i] == updateID){
                        cout<<"Enter New Student Name: ";
                        cin.ignore();
                        getline(cin, studentName[i]);
                        cout<<"Enter New English Marks: ";
                        cin>>english[i];
                        cout<<"Enter New Math Marks: ";
                        cin>>math[i];
                        cout<<"Enter New Science Marks: ";
                        cin>>science[i];
                        cout<<"Enter New Computer Marks: ";
                        cin>>computer[i];
                        cout<<"Enter New Social Marks: ";
                        cin>>social[i];
                        totalMarks[i] = english[i] + math[i] + science[i] + computer[i] + social[i];
                        percentage[i] = (totalMarks[i]/500)*100;
                        if(english[i] >= 33 && math[i] >= 33 && science[i] >= 33 && computer[i] >= 33 && social[i] >= 33){
                            result[i] = "Pass";
                        }
                        else{
                            result[i] = "Fail";
                        }
                        if(percentage[i] >= 90){
                            grade[i] = 'A';
                            result[i] = "Pass";
                        }
                        else if(percentage[i] >= 80){
                            grade[i] = 'B';
                            result[i] = "Pass";
                        }
                        else if(percentage[i] >= 70){
                            grade[i] = 'C';
                            result[i] = "Pass";
                        }
                        else if(percentage[i] >= 60){
                            grade[i] = 'D';
                            result[i] = "Pass";
                        }
                        else{
                            grade[i] = 'F';
                            result[i] = "Fail";
                        }
                        found = true;
                        cout<<"Student Marks updated successfully!"<<endl;
                    
                    }
                    if(!found){
                        cout<<"Student not found!"<<endl;
                    }
                }
                break;
            }
            case 5:{
                cout<<"====DELETE STUDENT MARKS===="<<endl;
                cout<<"Enter Student ID: ";
                int deleteID;
                cin>>deleteID;
                bool deleted = false;
                for(int i =0; i<totalStudents; i++){
                    if(studentID[i] == deleteID){
                        deleted = true;
                        for(int j =i; j<totalStudents-1; j++){
                            studentID[j] = studentID[j+1];
                            studentName[j] = studentName[j+1];
                            english[j] = english[j+1];
                            math[j] = math[j+1];
                            science[j] = science[j+1];
                            computer[j] = computer[j+1];
                            social[j] = social[j+1];
                            totalMarks[j] = totalMarks[j+1];
                            percentage[j] = percentage[j+1];
                            grade[j] = grade[j+1];
                            result[j] = result[j+1];
                        }
                        totalStudents--;
                        cout<<"Student Marks deleted successfully!"<<endl;
                        break;
                    }
                }
                break;
            }
            case 6:{
                cout<<"====CALCULATE STUDENT RESULT===="<<endl;
                cout<<"Enter Student ID: ";
                int searchID;
                cin>>searchID;
                bool found = false;
                for(int i =0; i<totalStudents; i++){
                    if(studentID[i] == searchID){
                        cout<<"Student ID: "<<studentID[i]<<endl;
                        cout<<"Student Name: "<<studentName[i]<<endl;
                        cout<<"English Marks: "<<english[i]<<endl;
                        cout<<"Math Marks: "<<math[i]<<endl;
                        cout<<"Science Marks: "<<science[i]<<endl;
                        cout<<"Computer Marks: "<<computer[i]<<endl;
                        cout<<"Social Marks: "<<social[i]<<endl;
                        cout<<"Total Marks: "<<totalMarks[i]<<endl;
                        cout<<"Percentage: "<<percentage[i]<<"%"<<endl;
                        cout<<"Grade: "<<grade[i]<<endl;
                        cout<<"Result: "<<result[i]<<endl;
                        found = true;
                    }

                }
                if(!found){
                    cout<<"Student not found!"<<endl;
                }
                break;
            }
            case 7:{
                cout<<"====STUDENT RANK===="<<endl;
                cout<<"Enter Student ID: ";
                int searchID;
                cin>>searchID;
                bool found = false;
                for(int i =0; i<totalStudents; i++){
                    if(studentID[i] == searchID){
                        int rank = 1;
                        for(int j =0; j<totalStudents; j++){
                            if(totalMarks[j] > totalMarks[i]){
                                rank++;
                            }
                        }
                        cout<<"Student ID: "<<studentID[i]<<endl;
                        cout<<"Student Name: "<<studentName[i]<<endl;
                        cout<<"Total Marks: "<<totalMarks[i]<<endl;
                        cout<<"Percentage: "<<percentage[i]<<"%"<<endl;
                        cout<<"Grade: "<<grade[i]<<endl;
                        cout<<"Result: "<<result[i]<<endl;
                        cout<<"Rank: "<<rank<<endl;
                        found = true;
                    }
                }
                if(!found){
                    cout<<"Student not found!"<<endl;
                }
                break;
            }
            case 8:{
                cout<<"Exiting the program."<<endl;
                break;
            }
        }


    }
    while(choice != 8);
}
