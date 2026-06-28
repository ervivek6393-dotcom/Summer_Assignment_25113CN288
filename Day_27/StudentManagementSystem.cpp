#include<iostream>
#include<string>
using namespace std;
int main(){
    int choice;
    int totalStudents = 0;
    int studentID[100];
    string studentName[100];
    int studentAge[100];
    float studentMarks[100];
    char grade[100];
    int semester[100];
    string course[100];
    do{
    cout<<"====STUDENT MANAGEMENT SYSTEM===="<<endl;
    cout<<"1. Add Student"<<endl;
    cout<<"2. Display Student"<<endl;
    cout<<"3. Search Student"<<endl;
    cout<<"4. Update Student"<<endl;
    cout<<"5. Delete Student"<<endl;
    cout<<"6. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice){
        case 1:{
            cout<<"Enter Student ID: ";
            cin>>studentID[totalStudents];
            bool idExists = false;
            for(int i =0; i<totalStudents; i++){
                if(studentID[i] == studentID[totalStudents]){
                    idExists = true;
                    break;
                }
            }
            if(idExists){
                cout<<"Student with ID "<<studentID[totalStudents]<<" already exists!"<<endl;
                break;
            }
            cout<<"Enter Student Name: ";
            cin.ignore();
            getline(cin, studentName[totalStudents]);
            cout<<"Enter Student Age: ";
            cin>>studentAge[totalStudents];
            cout<<"Enter Student Marks: ";
            cin>>studentMarks[totalStudents];
            if(studentMarks[totalStudents] >= 90){
                grade[totalStudents] = 'A';
            }
            else if(studentMarks[totalStudents] >= 80){
                grade[totalStudents] = 'B';
            }
            else if(studentMarks[totalStudents] >= 70){
                grade[totalStudents] = 'C';
            }
            else if(studentMarks[totalStudents] >= 60){
                grade[totalStudents] = 'D';
            }
            else{
                grade[totalStudents] = 'F';
            }
            cout<<"Enter Student Semester: ";
            cin>>semester[totalStudents];
            cout<<"Enter Student Course: ";
            cin.ignore();
            getline(cin, course[totalStudents]);
            totalStudents++;
            cout<<"student added successfully!"<<endl;
        
            break;
        }
            
            case 2:{
                if(totalStudents == 0){
                    cout<<"No students found!"<<endl;
                    break;
                }
            for(int i =0; i<totalStudents; i++){
                cout<<"--------------------------------"<<endl;
                cout<<"student Id : "<<studentID[i]<<endl;
                cout<<"student Name : "<<studentName[i]<<endl;
                cout<<"student Age : "<<studentAge[i]<<endl;
                cout<<"student Marks : "<<studentMarks[i]<<endl;
                cout<<"student Grade : "<<grade[i]<<endl;
                cout<<"student semester : "<<semester[i]<<endl;
                cout<<"student Coourse : "<<course[i]<<endl;
                cout<<"--------------------------------"<<endl;


            }
            break;
        }
            case 3:{
            int searchID;
            bool found = false;
            cout<<"Enter Student ID to search: ";
            cin>>searchID;
            for(int i =0; i<totalStudents; i++){
                if(studentID[i] == searchID){
                    cout<<"--------------------------------"<<endl;
                    cout<<"student ID : "<<studentID[i]<<endl;
                    cout<<"student Name : "<<studentName[i]<<endl;
                    cout<<"student Age : "<<studentAge[i]<<endl;
                    cout<<"student Marks : "<<studentMarks[i]<<endl;
                    cout<<"student Grade : "<<grade[i]<<endl;
                    cout<<"student semester : "<<semester[i]<<endl;
                    cout<<"student Coourse : "<<course[i]<<endl;
                    cout<<"--------------------------------"<<endl;
                    found = true;
                 }   
            }
            if(!found){
                cout<<"Student not found!"<<endl;
            }
            break;
        }
            case 4:{
            int updateID;
            bool updated = false;
            cout<<"Enter Student ID to update: ";
            cin>>updateID;
            for(int i =0; i<totalStudents; i++){
                if(studentID[i] == updateID){
                    cout<<"Enter Student Name: ";
                    cin.ignore();
                    getline(cin, studentName[i]);
                    cout<<"Enter Student Age: ";
                    cin>>studentAge[i];
                    cout<<"Enter Student Marks: ";
                    cin>>studentMarks[i];
                    if(studentMarks[i] >= 90){
                        grade[i] = 'A';
                    }
                    else if(studentMarks[i] >= 80){
                        grade[i] = 'B';
                    }
                    else if(studentMarks[i] >= 70){
                        grade[i] = 'C';
                    }
                    else if(studentMarks[i] >= 60){
                        grade[i] = 'D';
                    }
                    else{
                        grade[i] = 'F';
                    }
                    cout<<"Enter Student Semester: ";
                    cin>>semester[i];
                    cout<<"Enter Student Course: ";
                    cin.ignore();
                    getline(cin, course[i]);
                    updated = true;
                    cout<<"Student updated successfully!"<<endl;
                }
            }
            if(!updated){
                cout<<"Student not found!"<<endl;
            }
            break;
        }
            case 5:{
            int deleteID;
            bool deleted = false;
            cout<<"Enter Student ID to delete: ";
            cin>>deleteID;
            for(int i =0; i<totalStudents; i++){
                if(studentID[i] == deleteID){
                    deleted = true;
                    for(int j =i; j<totalStudents-1; j++){
                        studentID[j] = studentID[j+1];
                        studentName[j] = studentName[j+1];
                        studentAge[j] = studentAge[j+1];
                        studentMarks[j] = studentMarks[j+1];
                        course[j] = course[j+1];
                        semester[j] = semester[j+1];
                        grade[j] = grade[j+1];
                       
                    }
                    totalStudents--;
                    cout<<"Student deleted successfully!"<<endl;

                }
            }
            if(!deleted){
                cout<<"Student not found!"<<endl;
            }
            break;
        }
            case 6:{
            cout<<"Exiting..."<<endl;
            break;
            }
    }
}
while(choice != 6);
}