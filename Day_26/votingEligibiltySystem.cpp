#include<iostream>
using namespace std;
int main(){
    int age;
    int choice;
    
    cout<<"===VOTING ELIGIBILITY SYSTEM==="<<endl;
    cout<<"1. CHECK ELIGIBILITY FOR VOTING"<<endl;
    cout<<"2. VOTING RULES"<<endl;
    cout<<"3. EXIT"<<endl;
    cout<<"Enter your choice:";
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"Are You citizen of India? (1 for Yes, 0 for No): ";
        cin>>choice;
        if(choice == 0){
            cout<<"You are not eligible to vote"<<endl;
            return 0;
        }
        else {
            cout<<"You are a citizen of India"<<endl; 
            cout<<"Are you a registered voter? (1 for Yes, 0 for No): ";
            cin>>choice;

        }
        
         if(choice == 0){
            cout<<"You are not eligible to vote because you are not a registered voter"<<endl;
            return 0; 
        }
        cout<<"Enter your age: ";
        cin>>age;
        if(age >= 18){
            cout<<"You are  eligible to vote"<<endl;
        }
        else{
            cout<<"You are not eligible to vote because you are under 18 years old"<<endl;
        }
        break;
        case 2:
        cout<<"Voting Rules:"<<endl;
        cout<<"1. You must be a citizen of India."<<endl;
        cout<<"2. You must be at least 18 years old."<<endl;
        cout<<"3. You must be a registered voter."<<endl;
        break;
        case 3:
        cout<<"Thank you! Goodbye!"<<endl;
        break;
        default:
        cout<<"Invalid Choice!"<<endl;
    }
    return 0;
        
    }

    
