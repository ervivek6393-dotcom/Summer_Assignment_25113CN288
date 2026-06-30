#include<iostream>
#include<string>
using namespace std;
int main(){
    int contactID[100];
    string contactNames[100];
    string phone[100];
    string address[100];
    bool active[100];
    int totalContacts = 0;
    int choice;
    do{
        cout<<"==== CONTACT MANAGEMENT SYSTEM ===="<<endl;
        cout<<"1. Add Contact"<<endl;
        cout<<"2. Display All Contacts"<<endl;
        cout<<"3. Search Contact"<<endl;
        cout<<"4. Update Contact"<<endl;
        cout<<"5. Delete Contact"<<endl;
        cout<<"6. Sort Contacts"<<endl;
        cout<<"7. Count Contacts"<<endl;
        cout<<"8. Exit"<<endl;
        cout<<"Enter Your Choice : "<<endl;
        cin>>choice;
        switch(choice){
            case 1: {
                cout<<"==== ADD CONTACT ===="<<endl;
                
                cout<<"Enter Contact ID"<<endl;
                cin>>contactID[totalContacts];
                bool contactExist = false;
                for(int i =0; i<totalContacts; i++){
                    if(contactID[i] == contactID[totalContacts]){
                        contactExist = true;
                        break;
                    }
                }
                if(!contactExist){
                    cout<<"Enter Contact Name"<<endl;
                    cin.ignore();
                    getline(cin, contactNames[totalContacts]);
                    cout<<"Enter Phone Number"<<endl;
                    cin>>phone[totalContacts];
                    if(phone[totalContacts].length() != 10){
                        cout<<"Invalid Phone Number!"<<endl;
                        continue;
                    }
                    cout<<"Enter Email Address"<<endl;
                    cin.ignore();
                    getline(cin, address[totalContacts]);
                    active[totalContacts] = true;
                    totalContacts++;
                    cout<<"Contact Added Successfully!"<<endl;
                }
                break;
            }
            case 2: {
                cout<<"==== ALL CONTACTS ===="<<endl;
                
                for(int i = 0; i < totalContacts; i++){
                    if(active[i]){
                        cout<<"Account "<<i+1<<":"<<endl;
                        cout<<"------------------------"<<endl;
                        cout<<"Contact ID: "<<contactID[i]<<endl;
                        cout<<"Name: "<<contactNames[i]<<endl;
                        cout<<"Phone: "<<phone[i]<<endl;
                        cout<<"Email: "<<address[i]<<endl;
                        cout<<"------------------------"<<endl;
                    }
                }
                break;
            }
            case 3: {
                cout<<"==== SEARCH CONTACT ===="<<endl;
                cout<<"Enter Contact ID"<<endl;
                int searchContact;
                cin>>searchContact;
                bool found = false;
                for(int i =0; i<totalContacts; i++){
                    if(contactID[i] == searchContact && active[i]){
                        cout<<"Contact ID: "<<contactID[i]<<endl;
                        cout<<"Name: "<<contactNames[i]<<endl;
                        cout<<"Phone: "<<phone[i]<<endl;
                        cout<<"Email: "<<address[i]<<endl;
                        found = true;
                        break;

                    }
                    if(!found){
                        cout<<"Contact Not Found!"<<endl;
                    }
                
                }
                break;
            }
            case 4: {
                cout<<"==== UPDATE CONTACT ===="<<endl;
                cout<<"Enter Contact ID"<<endl;
                int updateContact;
                cin>>updateContact;
                bool found = false;
                for(int i =0; i<totalContacts; i++){
                    if(contactID[i] == updateContact && active[i]){
                        cout<<"Enter New Contact Name"<<endl;
                        cin.ignore();
                        getline(cin, contactNames[i]);
                        cout<<"Enter New Phone Number"<<endl;
                        cin>>phone[i];
                        if(phone[i].length() != 10){
                            cout<<"Invalid Phone Number!"<<endl;
                            break;
                        }
                        cout<<"Enter New Email Address"<<endl;
                        cin.ignore();
                        getline(cin, address[i]);
                        found = true;
                        cout<<"Contact Updated Successfully!"<<endl;
                        break;
                    }

                }
                break;
            }
            case 5: {
                cout<<"==== DELETE CONTACT ===="<<endl;
                cout<<"Enter Contact ID"<<endl;
                int deleteContact;
                cin>>deleteContact;
                bool deleted = false;
                for(int i =0; i<totalContacts; i++){
                    if(contactID[i] == deleteContact && active[i]){
                        deleted = true;
                        active[i] = false;
                        cout<<"Contact Deleted Successfully!"<<endl;
                        break;
                    }
                }
                if(!deleted){
                    cout<<"Contact Not Found!"<<endl;
                }
                break;
            }
            case 6: {
                cout<<"==== SORT CONTACTS ===="<<endl;
                for(int i = 0; i < totalContacts - 1; i++){
                    for(int j = 0; j < totalContacts - i - 1; j++){
                        if(contactNames[j] > contactNames[j + 1]){
                            swap(contactNames[j], contactNames[j + 1]);
                            swap(contactID[j], contactID[j + 1]);
                            swap(phone[j], phone[j + 1]);
                            swap(address[j], address[j + 1]);
                            swap(active[j], active[j + 1]);
                        }
                    }
                }
                cout<<"Contacts Sorted Successfully!"<<endl;
                break;
            }
            case 7: {
                cout<<"==== COUNT CONTACTS ===="<<endl;
                int count = 0;
                for(int i = 0; i < totalContacts; i++){
                    if(active[i]){
                        count++;
                    }
                }
                cout<<"Total Contacts: "<<totalContacts<<endl;
                cout<<"Total Active Contacts: "<<count<<endl;
                cout<<"Total Deleted Contacts: "<<totalContacts - count<<endl;
                
                break;
            }
            case 8: {
                cout<<"Exiting Contact Management System..."<<endl;
                break;
            }

            
        }
    }
    while(choice != 8);
    return 0;
    

}