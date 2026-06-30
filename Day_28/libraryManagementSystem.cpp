#include<iostream>
#include<string>
using namespace std;
int main(){
    int bookID[100];
    string bookName[100];
    string authorName[100];
    string category[100];
    int quantity[100];
    bool issued[100];
    string issuedTo[100];
    int totalBooks = 0;
    int  choice;
    do{
        cout<<"====LIBRARY MANAGEMENT SYSTEM===="<<endl;
        cout<<"1. Add Book"<<endl;
        cout<<"2. Display Books"<<endl;
        cout<<"3. Search Book"<<endl;
        cout<<"4. Update Book"<<endl;
        cout<<"5. Delete Book"<<endl;
        cout<<"6. Issue Book"<<endl;
        cout<<"7. Return Book"<<endl;
        cout<<"8. Display Issued Books"<<endl;
        cout<<"9. Fine Calculation"<<endl;
        cout<<"10. Exit"<<endl;
        cout<<"Total Books: "<<totalBooks<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"==== ADD BOOK ===="<<endl;
                cout<<"Enter Book ID: ";
                cin>>bookID[totalBooks];
                bool idExists = false;
                for(int i =0; i<totalBooks; i++){
                    if(bookID[i] == bookID[totalBooks]){
                        idExists = true;
                        break;
                    }
                }
                if(!idExists){
                    cout<<"Enter Book Name: ";
                    cin.ignore();
                    getline(cin, bookName[totalBooks]);
                    cout<<"Enter Author Name: ";
                    getline(cin, authorName[totalBooks]);
                }
                else{
                    cout<<"Book ID already exists!"<<endl;
                    break;
                }
                cout<<"Enter Category: ";
                getline(cin, category[totalBooks]);
                cout<<"Enter Quantity: ";
                cin>>quantity[totalBooks];
                if(quantity[totalBooks] < 0){
                    cout<<"Invalid Quantity!"<<endl;
                    break;
                }
                issued[totalBooks] = false;
                totalBooks++;
                cout<<"Book added successfully!"<<endl;
                break;

                
            }
            case 2:{
                cout<<"==== DISPLAY BOOKS ===="<<endl;
                cout<<"Total Books: "<<totalBooks<<endl;
                if(totalBooks == 0){
                    cout<<"No books found!"<<endl;
                    break;
                }
                for(int i =0; i<totalBooks; i++){
                    cout<<"Book "<<i+1<<":"<<endl;
                    cout<<"--------------------------------"<<endl;
                    cout<<"Book ID: "<<bookID[i]<<endl;
                    cout<<"Book Name: "<<bookName[i]<<endl;
                    cout<<"Author Name: "<<authorName[i]<<endl;
                    cout<<"Category: "<<category[i]<<endl;
                    cout<<"Quantity: "<<quantity[i]<<endl;
                    cout<<"Status: "<<(issued[i] ? "Issued" : "Available")<<endl;
                    cout<<"--------------------------------"<<endl;
                    if(issued[i]){
                        cout<<"Issued To: "<<issuedTo[i]<<endl;
                    }
                }
                break;
            }
            case 3:{
                cout<<"==== SEARCH BOOK===="<<endl;
                cout<<" Enter Book ID: ";
                int searchID;
                cin>>searchID;
                bool found = false;
                for(int i =0; i<totalBooks; i++){
                    if(bookID[i] == searchID){
                        cout<<"Book ID: "<<bookID[i]<<endl;
                        cout<<"Book Name: "<<bookName[i]<<endl;
                        cout<<"Author Name: "<<authorName[i]<<endl;
                        cout<<"Category: "<<category[i]<<endl;
                        cout<<"Quantity: "<<quantity[i]<<endl;
                        cout<<"Status: "<<(issued[i] ? "Issued" : "Available")<<endl;
                        found = true;
                    }
                }
                if(!found){
                    cout<<"Book not found!"<<endl;
                }
                break;
            }
            case 4:{
                cout<<"==== UPDATE BOOK ===="<<endl;
                cout<<"Enter Book ID: ";
                int updateID;
                cin>>updateID;
                bool found = false;
                for(int i =0; i<totalBooks; i++){
                    if(bookID[i] == updateID){
                        cout<<"Enter New Book Name: ";
                        cin.ignore();
                        getline(cin, bookName[i]);
                        cout<<"Enter New Author Name: ";
                        getline(cin, authorName[i]);
                        cout<<"Enter New Category: ";
                        getline(cin, category[i]);
                        cout<<"Enter New Quantity: ";
                        cin>>quantity[i];
                        if(quantity[i] < 0){
                            cout<<"Invalid Quantity!"<<endl;
                            break;
                        }
                        found = true;
                        cout<<"Book updated successfully!"<<endl;
                    }
                }
                if(!found){
                    cout<<"Book not found!"<<endl;
                }
                break;
            }
            case 5:{
                cout<<"==== DELETE BOOK ===="<<endl;
                cout<<"Enter Book ID: ";
                int deleteID;
                cin>>deleteID;
                bool deleted = false;
                for(int i =0; i<totalBooks; i++){
                    if(bookID[i] == deleteID){
                        deleted = true;
                        for(int j =i; j<totalBooks-1; j++){
                            bookID[j] = bookID[j+1];
                            bookName[j] = bookName[j+1];
                            authorName[j] = authorName[j+1];
                            category[j] = category[j+1];
                            quantity[j] = quantity[j+1];
                            issued[j] = issued[j+1];
                            issuedTo[j] = issuedTo[j+1];
                        }
                        totalBooks--;
                        cout<<"Book deleted successfully!"<<endl;
                        break;
                    }
                }
                if(!deleted){
                    cout<<"Book not found!"<<endl;
                }
                break;

            }
            case 6:{
                cout<<"==== ISSUE BOOK ===="<<endl;
                cout<<"Enter Book ID: ";
                int issueID;
                cin>>issueID;
                bool found = false;
                for(int i =0; i<totalBooks; i++){
                    if(bookID[i] == issueID){
                        found = true;
                        if(issued[i]){
                            cout<<"Book is already issued!"<<endl;
                        }
                        else{
                            cout<<"Enter Issued To (Student Name): ";
                            cin.ignore();
                            getline(cin, issuedTo[i]);
                            if(quantity[i] <= 0){
                                cout<<"Book is out of stock!"<<endl;
                                break;
                            }
                            else{
                                cout<<"Enter Issued To (Student Name): ";
                                cin.ignore();
                                getline(cin, issuedTo[i]);
                            }
                            issued[i] = true;
                            quantity[i]--;
                            cout<<"Book issued successfully!"<<endl;
                        }
                    }
                }
                if(!found){
                    cout<<"Book not found!"<<endl;
                }
                break;
            }
            case 7:{
                cout<<"==== RETURN BOOK ===="<<endl;
                cout<<"Enter Book ID: ";
                int returnID;
                cin>>returnID;
                bool found = false;
                
                for(int i =0; i<totalBooks; i++){
                    if(bookID[i] == returnID){
                        if(!issued[i]){
                            cout<<"Book is not issued!"<<endl;
                        }
                        else{
                            issued[i] = false;
                            quantity[i]++;
                            issuedTo[i] = "";
                            cout<<"Book returned successfully!"<<endl;
                        }
                        found = true;

                    }
                }
                if(!found){
                    cout<<"Book not found!"<<endl;
                }
                break;
            }
            case 8:{
                cout<<"==== DISPLAY ISSUED BOOKS ===="<<endl;
                bool found = false;
                for(int i =0; i<totalBooks; i++){
                    if(issued[i]){
                        cout<<"Book ID: "<<bookID[i]<<endl;
                        cout<<"Book Name: "<<bookName[i]<<endl;
                        cout<<"Author Name: "<<authorName[i]<<endl;
                        cout<<"Category: "<<category[i]<<endl;
                        cout<<"Quantity: "<<quantity[i]<<endl;
                        cout<<"Issued To: "<<issuedTo[i]<<endl;
                        found = true;
                    }
                }
                if(!found){
                    cout<<"No books are currently issued!"<<endl;
                }
                break;

            }
            case 9:{
                cout<<"==== FINE CALCULATION ===="<<endl;
                cout<<"Enter Book ID: ";
                int fineID;
                cin>>fineID;
                bool found = false;
                for(int i =0; i<totalBooks; i++){
                    if(bookID[i] == fineID){
                        found = true;
                        if(!issued[i]){
                            cout<<"Book is not issued!"<<endl;
                        }
                        else{
                            int daysLate;
                            cout<<"Enter number of days late: ";
                            cin>>daysLate;
                            if(daysLate < 0){
                                cout<<"Invalid number of days!"<<endl;
                                break;
                            }
                            double fineAmount = daysLate * 5; // Assuming ₹5 fine per day
                            cout<<"Fine Amount: ₹"<<fineAmount<<endl;
                        }
                    }
                }
                if(!found){
                    cout<<"Book not found!"<<endl;
                }
                break;

            }
            case 10:{
                cout<<"Exiting the program."<<endl;
                break;
            }
        }
    }
    while(choice != 10);
}