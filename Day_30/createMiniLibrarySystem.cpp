#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int bookID[100];
    string bookTitle[100];
    string bookAuthor[100];
    string bookGenre[100];
    float bookPrice[100];
    bool issuedStatus[100];
    bool activeStatus[100];
    int totalBooks = 0;
    int choice;
    do{
        cout<<"======= MINI LIBRARY MANAGEMENT SYSTEM ======="<<endl;
        cout<<"1. Add Book"<<endl;
        cout<<"2. Display Books"<<endl;
        cout<<"3. Search Book"<<endl;
        cout<<"4. Update Book"<<endl;
        cout<<"5. Delete Book"<<endl;
        cout<<"6. Issue Book"<<endl;
        cout<<"7. Return Book"<<endl;
        cout<<"8. Count Available and Issued Books"<<endl;
        cout<<"9. Find Most Expensive Book"<<endl;
        cout<<"10. Find Cheapest Book"<<endl;
        cout<<"11. Sort Books by Price"<<endl;
        cout<<"12. Search Books by Genre"<<endl;
        cout<<"13. Display Active Books"<<endl;
        cout<<"14. Total Number of Books"<<endl;
        cout<<"15. Exit"<<endl;
        cout<<"Enter Your Choice : "<<endl;
        cin>>choice;
        switch(choice){
            case 1: {
                cout<<"==== ADD BOOK ===="<<endl;
                if(totalBooks >= 100){
                    cout<<"Library Full! Cannot add more books."<<endl;
                }
                else{
                    cout<<"Enter Book ID: ";
                    cin>>bookID[totalBooks];
                    bool idExists = false;
                    for(int i = 0; i < totalBooks; i++){
                        if(bookID[i] == bookID[totalBooks]){
                            idExists = true;
                            break;
                        }
                    }
                    if(idExists){
                        cout<<"Book with ID "<<bookID[totalBooks]<<" already exists!"<<endl;
                        break;
                    }
                    cin.ignore(); // To ignore the newline character after book ID input
                    cout<<"Enter Book Title: ";
                    getline(cin, bookTitle[totalBooks]);
                    cout<<"Enter Book Author: ";
                    getline(cin, bookAuthor[totalBooks]);
                    cout<<"Enter Book Genre: ";
                    getline(cin, bookGenre[totalBooks]);
                    cout<<"Enter Book Price: ";
                    cin>>bookPrice[totalBooks];
                    if(bookPrice[totalBooks] < 0){
                        cout<<"Invalid Price! Cannot be negative."<<endl;
                        break;
                    }
                    issuedStatus[totalBooks] = false;
                    activeStatus[totalBooks] = true;
                    totalBooks++;
                }
                cout<<"Book Added Successfully!"<<endl;
                break;
            }
            case 2: {
                cout<<"==== DISPLAY BOOKS ===="<<endl;
                if(totalBooks == 0){
                    cout<<"No books available!"<<endl;
                }
                else{
                    for(int i = 0; i < totalBooks; i++){
                        if(!activeStatus[i])
                        continue; // Skip inactive books
                        cout<<"Book ID: "<<bookID[i]<<endl;
                        cout<<"Book Title: "<<bookTitle[i]<<endl;
                        cout<<"Book Author: "<<bookAuthor[i]<<endl;
                        cout<<"Book Genre: "<<bookGenre[i]<<endl;
                        cout<<"Book Price: $"<<bookPrice[i]<<endl;
                        cout<<"Issued Status: "<<(issuedStatus[i] ? "Issued" : "Available")<<endl;
                        cout<<"Active Status: "<<(activeStatus[i] ? "Active" : "Inactive")<<endl;
                        cout<<"------------------------------"<<endl;
                    }
                }
                break;
            }
            case 3: {
                cout<<"==== SEARCH BOOK ===="<<endl;
                if(totalBooks == 0){
                    cout<<"No books available!"<<endl;
                }
                else{
                    int searchID;
                    cout<<"Enter Book ID to search: ";
                    cin>>searchID;
                    bool found = false;
                    for(int i = 0; i < totalBooks; i++){
                        if(activeStatus[i] && bookID[i] == searchID){
                            cout<<"Book Found!"<<endl;
                            cout<<"Book ID: "<<bookID[i]<<endl;
                            cout<<"Book Title: "<<bookTitle[i]<<endl;
                            cout<<"Book Author: "<<bookAuthor[i]<<endl;
                            cout<<"Book Genre: "<<bookGenre[i]<<endl;
                            cout<<"Book Price: $"<<bookPrice[i]<<endl;
                            cout<<"Issued Status: "<<(issuedStatus[i] ? "Issued" : "Available")<<endl;
                            cout<<"Active Status: "<<(activeStatus[i] ? "Active" : "Inactive")<<endl;
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        cout<<"Book Not Found!"<<endl;
                    }
                }
                break;
            }
            case 4: {
                cout<<"==== UPDATE BOOK ===="<<endl;
                if(totalBooks == 0){
                    cout<<"No books available!"<<endl;
                }
                else{
                    int updateID;
                    cout<<"Enter Book ID to update: ";
                    cin>>updateID;
                    bool found = false;
                    for(int i = 0; i < totalBooks; i++){
                        if(activeStatus[i] && bookID[i] == updateID){
                            cin.ignore(); // To ignore the newline character after book ID input
                            cout<<"Enter New Book Title: ";
                            getline(cin, bookTitle[i]);
                            cout<<"Enter New Book Author: ";
                            getline(cin, bookAuthor[i]);
                            cout<<"Enter New Book Genre: ";
                            getline(cin, bookGenre[i]);
                            cout<<"Enter New Book Price: ";
                            cin>>bookPrice[i];
                            if(bookPrice[i] < 0){
                                cout<<"Invalid Price! Cannot be negative."<<endl;
                                break;
                            }
                            cout<<"Book Updated Successfully!"<<endl;
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        cout<<"Book Not Found!"<<endl;
                    }
                }
                break;
            }
            case 5: {
                cout<<"==== DELETE BOOK ===="<<endl;
                if(totalBooks == 0){
                    cout<<"No books available!"<<endl;
                }
                else{
                    int deleteID;
                    cout<<"Enter Book ID to delete: ";
                    cin>>deleteID;
                    bool found = false;
                    for(int i = 0; i < totalBooks; i++){
                        if(activeStatus[i] && bookID[i] == deleteID){
                            activeStatus[i] = false;
                            issuedStatus[i] = false; // Reset issued status when deleting
                            cout<<"Book Deleted Successfully!"<<endl;
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        cout<<"Book Not Found!"<<endl;
                    }
                }
                break;
            }
            case 6: {
                cout<<"==== ISSUE BOOK ===="<<endl;
                if(totalBooks == 0){
                    cout<<"No books available!"<<endl;
                }
                else{
                    int issueID;
                    cout<<"Enter Book ID to issue: ";
                    cin>>issueID;
                    bool found = false;
                    for(int i = 0; i < totalBooks; i++){
                        if(activeStatus[i] && bookID[i] == issueID){
                            if(issuedStatus[i]){
                                cout<<"Book is already issued!"<<endl;
                            }
                            else{
                                issuedStatus[i] = true;
                                cout<<"Book Issued Successfully!"<<endl;
                            }
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        cout<<"Book Not Found!"<<endl;
                    }
                }
                break;
            }
            case 7: {
                cout<<"==== RETURN BOOK ===="<<endl;
                if(totalBooks == 0){
                    cout<<"No books available!"<<endl;
                }
                else{
                    int returnID;
                    cout<<"Enter Book ID to return: ";
                    cin>>returnID;
                    bool found = false;
                    for(int i = 0; i < totalBooks; i++){
                        if(activeStatus[i] && bookID[i] == returnID){
                            if(!issuedStatus[i]){
                                cout<<"Book is not issued!"<<endl;
                            }
                            else{
                                issuedStatus[i] = false;
                                cout<<"Book Returned Successfully!"<<endl;
                            }
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        cout<<"Book Not Found!"<<endl;
                    }
                }
                break;
            }
            case 8: {
                cout<<"==== COUNT AVAILABLE AND ISSUED BOOKS ===="<<endl;
                if(totalBooks == 0){
                    cout<<"No books available!"<<endl;
                }
                else{
                    int availableCount = 0;
                    int issuedCount = 0;
                    for(int i = 0; i < totalBooks; i++){
                        if(!activeStatus[i]){
                            continue; // Skip inactive books
                        }
                        if(issuedStatus[i]){
                            issuedCount++;
                        }
                        else{
                            availableCount++;
                        }
                    }
                    cout<<"Total Available Books: "<<availableCount<<endl;
                    cout<<"Total Issued Books: "<<issuedCount<<endl;
                }
                break;
            }
            case 9: {
                cout<<"==== FIND MOST EXPENSIVE BOOK ===="<<endl;
                if(totalBooks == 0){
                    cout<<"No books available!"<<endl;
                }
                else{
                    int expensiveIndex = -1;
                    for(int i = 0; i < totalBooks; i++){
                        if(activeStatus[i]){
                            if(expensiveIndex == -1 || bookPrice[i] > bookPrice[expensiveIndex]){
                                expensiveIndex = i;
                            }
                        }
                    }
                    cout<<"Most Expensive Book:"<<endl;
                    cout<<"Book ID: "<<bookID[expensiveIndex]<<endl;
                    cout<<"Book Title: "<<bookTitle[expensiveIndex]<<endl;
                    cout<<"Book Author: "<<bookAuthor[expensiveIndex]<<endl;
                    cout<<"Book Genre: "<<bookGenre[expensiveIndex]<<endl;
                    cout<<"Book Price: $"<<bookPrice[expensiveIndex]<<endl;
                    cout<<"Issued Status: "<<(issuedStatus[expensiveIndex] ? "Issued" : "Available")<<endl;
                    cout<<"Active Status: "<<(activeStatus[expensiveIndex] ? "Active" : "Inactive")<<endl;
                }
                break;
            }
            case 10: {
                cout<<"==== FIND CHEAPEST BOOK ===="<<endl;
                if(totalBooks == 0){
                    cout<<"No books available!"<<endl;
                }
                else{
                    int cheapestIndex = -1;
                    for(int i = 0; i < totalBooks; i++){
                        if(activeStatus[i]){
                            if(cheapestIndex == -1 || bookPrice[i] < bookPrice[cheapestIndex]){
                                cheapestIndex = i;
                            }
                        }
                    }
                    cout<<"Cheapest Book:"<<endl;
                    cout<<"Book ID: "<<bookID[cheapestIndex]<<endl;
                    cout<<"Book Title: "<<bookTitle[cheapestIndex]<<endl;
                    cout<<"Book Author: "<<bookAuthor[cheapestIndex]<<endl;
                    cout<<"Book Genre: "<<bookGenre[cheapestIndex]<<endl;
                    cout<<"Book Price: ₹"<<bookPrice[cheapestIndex]<<endl;
                    cout<<"Issued Status: "<<(issuedStatus[cheapestIndex] ? "Issued" : "Available")<<endl;
                    cout<<"Active Status: "<<(activeStatus[cheapestIndex] ? "Active" : "Inactive")<<endl;
                }
                break;
            }
            case 11: {
                cout<<"==== SORT BOOKS BY PRICE ===="<<endl;
                if(totalBooks == 0){
                    cout<<"No books available!"<<endl;
                }
                else{
                    for(int i = 0; i < totalBooks - 1; i++){
                        for(int j = 0; j < totalBooks - i - 1; j++){
                            if(bookPrice[j] > bookPrice[j + 1]){
                                swap(bookID[j], bookID[j + 1]);
                                swap(bookTitle[j], bookTitle[j + 1]);
                                swap(bookAuthor[j], bookAuthor[j + 1]);
                                swap(bookGenre[j], bookGenre[j + 1]);
                                swap(bookPrice[j], bookPrice[j + 1]);
                                swap(issuedStatus[j], issuedStatus[j + 1]);
                                swap(activeStatus[j], activeStatus[j + 1]);
                            }
                        }
                    }
                    cout<<"Books Sorted by Price Successfully!"<<endl;
                }
                break;
            }
            case 12: {
                cout<<"==== SEARCH BOOKS BY GENRE ===="<<endl;
                if(totalBooks == 0){
                    cout<<"No books available!"<<endl;
                }
                else{
                    string searchGenre;
                    cin.ignore(); // To ignore the newline character after previous input
                    cout<<"Enter Book Genre to search: ";
                    getline(cin, searchGenre);
                    bool found = false;
                    for(int i = 0; i < totalBooks; i++){
                        if(activeStatus[i] && bookGenre[i] == searchGenre){
                            cout<<"Book Found:"<<endl;
                            cout<<"Book ID: "<<bookID[i]<<endl;
                            cout<<"Book Title: "<<bookTitle[i]<<endl;
                            cout<<"Book Author: "<<bookAuthor[i]<<endl;
                            cout<<"Book Genre: "<<bookGenre[i]<<endl;
                            cout<<"Book Price: $"<<bookPrice[i]<<endl;
                            cout<<"Issued Status: "<<(issuedStatus[i] ? "Issued" : "Available")<<endl;
                            cout<<"Active Status: "<<(activeStatus[i] ? "Active" : "Inactive")<<endl;
                            found = true;
                        }
                    }
                    if(!found){
                        cout<<"No Books Found in Genre: "<<searchGenre<<endl;
                    }
                }
                break;
            }
            case 13: {
                cout<<"==== DISPLAY ACTIVE BOOKS ===="<<endl;
                if(totalBooks == 0){
                    cout<<"No books available!"<<endl;
                }
                else{
                    bool found = false;
                    for(int i = 0; i < totalBooks; i++){
                        if(activeStatus[i]){
                            cout<<"Book ID: "<<bookID[i]<<endl;
                            cout<<"Book Title: "<<bookTitle[i]<<endl;
                            cout<<"Book Author: "<<bookAuthor[i]<<endl;
                            cout<<"Book Genre: "<<bookGenre[i]<<endl;
                            cout<<"Book Price: $"<<bookPrice[i]<<endl;
                            cout<<"Issued Status: "<<(issuedStatus[i] ? "Issued" : "Available")<<endl;
                            cout<<"Active Status: Active"<<endl;
                            cout<<"------------------------------"<<endl;
                            found = true;
                        }
                    }
                    if(!found){
                        cout<<"No Active Books Found!"<<endl;
                    }
                }
                break;
            }
            case 14: {
                cout<<"==== TOTAL NUMBER OF BOOKS ===="<<endl;
                int activeCount = 0;
                int inactiveCount = 0;
                for(int i = 0; i < totalBooks; i++){
                    if(activeStatus[i]){
                        activeCount++;
                    }
                    else{
                        inactiveCount++;
                    }
                }
                cout<<"Total Books in Library: "<<totalBooks<<endl;
                cout<<"Active Books: "<<activeCount<<endl;
                cout<<"Inactive Books: "<<inactiveCount<<endl;
                break;
            }
            case 15: {
                cout<<"Exiting the program. Goodbye!"<<endl;
                break;
            }
            default: {
                cout<<"Invalid Choice! Please try again."<<endl;
                break;
            }
           
        }
    }
    while(choice != 15);
    return 0;
}