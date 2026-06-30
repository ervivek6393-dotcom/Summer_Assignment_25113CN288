#include <iostream>
#include <string>
using namespace std;
int main()
{
    int rollNo[100];
    string studentName[100];
    int age[100];
    string gender[100];
    string course[100];
    int marks[100];
    float percentage[100];
    char grade[100];
    bool activeStatus[100];
    int totalStudents = 0;
    int choice;
    do
    {
        cout << "======= STUDENT RECORD MANAGEMENT SYSTEM =======" << endl;
        cout << "1. Add Student Record" << endl;
        cout << "2. Display Student Records" << endl;
        cout << "3. Search Student Record" << endl;
        cout << "4. Update Student Record" << endl;
        cout << "5. Delete Student Record" << endl;
        cout << "6. Calculate Total Marks" << endl;
        cout << "7. Calculate Percentage" << endl;
        cout << "8. Assign Grade" << endl;
        cout << "9. Find Topper" << endl;
        cout << "10. Find Lowest Marks" << endl;
        cout << "11. Sort Students by Marks" << endl;
        cout << "12. Count Passed and Failed Students" << endl;
        cout << "13. Display Class Statistics" << endl;
        cout << "14. Total Number of Students" << endl;
        cout << "15. Exit" << endl;
        cout << "Enter Your Choice : " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "==== ADD STUDENT RECORD ====" << endl;
            if (totalStudents >= 100)
            {
                cout << "Student Record Full! Cannot add more students." << endl;
            }
            else
            {
                cout << "Enter Roll Number: ";
                cin >> rollNo[totalStudents];
                bool idExists = false;
                for (int i = 0; i < totalStudents; i++)
                {
                    if (rollNo[i] == rollNo[totalStudents])
                    {
                        idExists = true;
                        break;
                    }
                }
                if (idExists)
                {
                    cout << "Student with Roll Number " << rollNo[totalStudents] << " already exists!" << endl;
                    break;
                }
                cin.ignore(); // To ignore the newline character after roll number input
                cout << "Enter Student Name: ";
                getline(cin, studentName[totalStudents]);
                cout << "Enter Age: ";
                cin >> age[totalStudents];
                if (age[totalStudents] <= 0)
                {
                    cout << "Invalid Age! Must be positive." << endl;
                    break;
                }
                cin.ignore(); // To ignore the newline character after age input
                cout << "Enter Gender: ";
                getline(cin, gender[totalStudents]);
                cout << "Enter Course: ";
                getline(cin, course[totalStudents]);
                activeStatus[totalStudents] = true; // Assuming new student is active
                totalStudents++;
                cout << "Student Record Added Successfully!" << endl;
            }
            break;
        }
        case 2:
        {
            cout << "==== DISPLAY STUDENT RECORDS ====" << endl;
            if (totalStudents == 0)
            {
                cout << "No student records available!" << endl;
            }
            else
            {
                for (int i = 0; i < totalStudents; i++)
                {
                    cout << "Roll Number: " << rollNo[i] << endl;
                    cout << "Student Name: " << studentName[i] << endl;
                    cout << "Age: " << age[i] << endl;
                    cout << "Gender: " << gender[i] << endl;
                    cout << "Course: " << course[i] << endl;
                    cout << "Marks: " << marks[i] << endl;
                    cout << "Percentage: " << percentage[i] << "%" << endl;
                    cout << "Grade: " << grade[i] << endl;
                    cout << "Active Status: " << (activeStatus[i] ? "Active" : "Inactive") << endl;
                    cout << "------------------------------" << endl;
                    cout << endl;
                }
            }
            break;
        }
        case 3:
        {
            cout << "==== SEARCH STUDENT RECORD ====" << endl;
            if (totalStudents == 0)
            {
                cout << "No student records available!" << endl;
            }
            else
            {
                int searchRollNo;
                cout << "Enter Roll Number to search: ";
                cin >> searchRollNo;
                bool found = false;
                for (int i = 0; i < totalStudents; i++)
                {
                    if (rollNo[i] == searchRollNo)
                    {
                        cout << "Student Found!" << endl;
                        cout << "Roll Number: " << rollNo[i] << endl;
                        cout << "Student Name: " << studentName[i] << endl;
                        cout << "Age: " << age[i] << endl;
                        cout << "Gender: " << gender[i] << endl;
                        cout << "Course: " << course[i] << endl;
                        cout << "Active Status: " << (activeStatus[i] ? "Active" : "Inactive") << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Student Not Found!" << endl;
                }
            }
            break;
        }
        case 4:
        {
            cout << "==== UPDATE STUDENT RECORD ====" << endl;

            if (totalStudents == 0)
            {
                cout << "No Student Records Available!" << endl;
            }
            else
            {

                int updateRollNo;

                cout << "Enter Roll Number: ";
                cin >> updateRollNo;

                bool found = false;

                for (int i = 0; i < totalStudents; i++)
                {

                    if (activeStatus[i] && rollNo[i] == updateRollNo)
                    {

                        cin.ignore();

                        cout << "Enter New Student Name: ";
                        getline(cin, studentName[i]);

                        cout << "Enter New Age: ";
                        cin >> age[i];

                        cin.ignore();

                        cout << "Enter New Gender: ";
                        getline(cin, gender[i]);

                        cout << "Enter New Course: ";
                        getline(cin, course[i]);

                        cout << "Enter New Marks: ";
                        cin >> marks[i];

                        percentage[i] = (marks[i] / 500.0) * 100;

                        if (percentage[i] >= 90)
                            grade[i] = 'A';
                        else if (percentage[i] >= 80)
                            grade[i] = 'B';
                        else if (percentage[i] >= 70)
                            grade[i] = 'C';
                        else if (percentage[i] >= 60)
                            grade[i] = 'D';
                        else
                            grade[i] = 'F';

                        cout << "Student Updated Successfully!" << endl;

                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    cout << "Student Not Found!" << endl;
                }
            }

            break;
        }
        
    case 5:
    {
        cout << "==== DELETE STUDENT RECORD ====" << endl;
        if (totalStudents == 0)
        {
            cout << "No student records available!" << endl;
        }
        else
        {
            int deleteRollNo;
            cout << "Enter Roll Number to delete: ";
            cin >> deleteRollNo;
            bool found = false;
            for (int i = 0; i < totalStudents; i++)
            {
                if (rollNo[i] == deleteRollNo)
                {
                    for (int j = i; j < totalStudents - 1; j++)
                    {
                        rollNo[j] = rollNo[j + 1];
                        studentName[j] = studentName[j + 1];
                        age[j] = age[j + 1];
                    }
                    totalStudents--;
                    cout << "Student Record Deleted Successfully!" << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Student Not Found!" << endl;
            }
        }
        break;
    }
    case 6:
    {
        cout << "==== CALCULATE TOTAL MARKS ====" << endl;
        if (totalStudents == 0)
        {
            cout << "No student records available!" << endl;
        }
        else
        {
            for (int i = 0; i < totalStudents; i++)
            {
                cout << "Enter Marks for Student " << studentName[i] << " (Roll No: " << rollNo[i] << "): ";
                cin >> marks[i];
            }
            cout << "Total Marks Calculated Successfully!" << endl;
        }
        break;
    }
    case 7:
    {
        cout << "==== CALCULATE PERCENTAGE ====" << endl;
        if (totalStudents == 0)
        {
            cout << "No student records available!" << endl;
        }
        else
        {
            for (int i = 0; i < totalStudents; i++)
            {
                percentage[i] = (marks[i] / 500.0) * 100; // Assuming total marks is 500
            }
            cout << "Percentage Calculated Successfully!" << endl;
        }
        break;
    }
    case 8:
    {
        cout << "==== ASSIGN GRADE ====" << endl;
        if (totalStudents == 0)
        {
            cout << "No student records available!" << endl;
        }
        else
        {
            for (int i = 0; i < totalStudents; i++)
            {
                if (percentage[i] >= 90)
                {
                    grade[i] = 'A';
                }
                else if (percentage[i] >= 80)
                {
                    grade[i] = 'B';
                }
                else if (percentage[i] >= 70)
                {
                    grade[i] = 'C';
                }
                else if (percentage[i] >= 60)
                {
                    grade[i] = 'D';
                }
                else
                {
                    grade[i] = 'F';
                }
            }
            cout << "Grades Assigned Successfully!" << endl;
        }
        break;
    }
    case 9:
    {
        cout << "==== FIND TOPPER ====" << endl;
        if (totalStudents == 0)
        {
            cout << "No student records available!" << endl;
        }
        else
        {
            int topperIndex = 0;
            for (int i = 1; i < totalStudents; i++)
            {
                if (marks[i] > marks[topperIndex])
                {
                    topperIndex = i;
                }
            }
            cout << "Topper Student:" << endl;
            cout << "Roll Number: " << rollNo[topperIndex] << endl;
            cout << "Student Name: " << studentName[topperIndex] << endl;
            cout << "Marks: " << marks[topperIndex] << endl;
        }
        break;
    }
    case 10:
    {
        cout << "==== FIND LOWEST MARKS ====" << endl;
        if (totalStudents == 0)
        {
            cout << "No student records available!" << endl;
        }
        else
        {
            int lowestIndex = 0;
            for (int i = 1; i < totalStudents; i++)
            {
                if (marks[i] < marks[lowestIndex])
                {
                    lowestIndex = i;
                }
            }
            cout << "Student with Lowest Marks:" << endl;
            cout << "Roll Number: " << rollNo[lowestIndex] << endl;
            cout << "Student Name: " << studentName[lowestIndex] << endl;
            cout << "Marks: " << marks[lowestIndex] << endl;
        }
        break;
    }
    case 11:
    {
        cout << "==== SORT STUDENTS BY MARKS ====" << endl;
        if (totalStudents == 0)
        {
            cout << "No student records available!" << endl;
        }
        else
        {
            for (int i = 0; i < totalStudents - 1; i++)
            {
                for (int j = 0; j < totalStudents - i - 1; j++)
                {
                    if (marks[j] > marks[j + 1])
                    {
                        swap(rollNo[j], rollNo[j + 1]);
                        swap(studentName[j], studentName[j + 1]);
                        swap(age[j], age[j + 1]);
                        swap(gender[j], gender[j + 1]);
                        swap(course[j], course[j + 1]);
                        swap(marks[j], marks[j + 1]);
                        swap(percentage[j], percentage[j + 1]);
                        swap(grade[j], grade[j + 1]);
                        swap(activeStatus[j], activeStatus[j + 1]);
                    }
                }
            }
            cout << "Students Sorted by Marks Successfully!" << endl;
        }
        break;
    }
    case 12:
    {
        cout << "==== COUNT PASSED AND FAILED STUDENTS ====" << endl;
        if (totalStudents == 0)
        {
            cout << "No student records available!" << endl;
        }
        else
        {
            int passedCount = 0;
            int failedCount = 0;
            for (int i = 0; i < totalStudents; i++)
            {
                if (grade[i] != 'F')
                {
                    passedCount++;
                }
                else
                {
                    failedCount++;
                }
            }
            cout << "Total Passed Students: " << passedCount << endl;
            cout << "Total Failed Students: " << failedCount << endl;
        }
        break;
    }
    case 13:
    {
        cout << "==== DISPLAY CLASS STATISTICS ====" << endl;
        if (totalStudents == 0)
        {
            cout << "No student records available!" << endl;
        }
        else
        {
            int totalMarks = 0;
            int highestMarks = marks[0];
            int lowestMarks = marks[0];
            for (int i = 0; i < totalStudents; i++)
            {
                totalMarks += marks[i];
                if (marks[i] > highestMarks)
                {
                    highestMarks = marks[i];
                }
                if (marks[i] < lowestMarks)
                {
                    lowestMarks = marks[i];
                }
            }
            float averageMarks = static_cast<float>(totalMarks) / totalStudents;
            cout << "Total Students: " << totalStudents << endl;
            cout << "Average Marks: " << averageMarks << endl;
            cout << "Highest Marks: " << highestMarks << endl;
            cout << "Lowest Marks: " << lowestMarks << endl;
        }
        break;
    }
    case 14:
    {
        cout << "==== TOTAL NUMBER OF STUDENTS ====" << endl;
        int activeCount = 0;
        int deletedCount = 0;
        for (int i = 0; i < totalStudents; i++)
        {
            if (activeStatus[i] == 'A')
            {
                activeCount++;
            }
            else
            {
                deletedCount++;
            }
        }
        cout << "Total Students: " << totalStudents << endl;
        cout << "Active Students: " << activeCount << endl;
        cout << "Deleted Students: " << deletedCount << endl;
        break;
    }
    case 15:
    {
        cout << "Exiting Student Record Management System. Goodbye!" << endl;
        break;
    }
    default:
    {
        cout << "Invalid Choice! Please try again." << endl;
        break;
    }
    }
}
while (choice != 15);
return 0;
}