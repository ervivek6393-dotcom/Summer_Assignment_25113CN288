#include<iostream>
#include<string>
using namespace std;
int main(){
    int accountNumber[100];
    string accountHolderName[100];
    string accountType[100];    
    string mobileNumber[100];
    string address[100];
    float balance[100];
    bool accountActive[100] = {0};
    float lastDeposit[100] = {0};
    float lastWithdraw[100] = {0};
    float lastTransfer[100] = {0};
    int totalAccounts = 0;
    int choice;
    do{
    cout<<"==== BANK ACCOUNT MANAGEMENT SYSTEM ===="<<endl;
    cout<<"1. Create Account"<<endl;
    cout<<"2. Display All Accounts"<<endl;
    cout<<"3. Search Account"<<endl;
    cout<<"4. Deposit Money"<<endl;
    cout<<"5. Withdraw Money"<<endl;
    cout<<"6. Transfer Money"<<endl;
    cout<<"7. Update Account"<<endl;
    cout<<"8. Delete Account"<<endl;
    cout<<"9. Mini Statement"<<endl;
    cout<<"10. Exit"<<endl;
    cout<<"Enter Your Choice :"<<endl;
    cin>>choice;
    switch(choice){
        case 1: {
            cout<<"==== CREATE ACCOUNT ===="<<endl;
            cout<<"Enter Account Number"<<endl;
            cin>>accountNumber[totalAccounts];
            bool accountExist = false;
            for(int i =0; i<totalAccounts; i++){
                if(accountNumber[i] == accountNumber[totalAccounts] ){
                    accountExist = true; 
                    break;
                }
            }
            if(!accountExist){
                cout<<"Enter Account Holder Name"<<endl;
                cin.ignore();
                getline(cin, accountHolderName[totalAccounts]);
                cout<<"Enter Mobile Number"<<endl; 
                cin>>mobileNumber[totalAccounts];
                if(mobileNumber[totalAccounts].length() != 10){
                    cout<<"Invalid Mobile Number!"<<endl;
                    break;
                }
            
                cout<<"Enter Address"<<endl;
                cin.ignore();
                getline(cin, address[totalAccounts]);
                cout<<"Enter Account Type (Savings/Current)"<<endl;
                cin>>accountType[totalAccounts];
                if(accountType[totalAccounts] != "Savings" && accountType[totalAccounts] != "Current"){
                    cout<<"Invalid Account Type!"<<endl;
                    break;
                }
                cout<<"Enter Opening Balance"<<endl;
                cin>>balance[totalAccounts];
                if(balance[totalAccounts] >= 500 ){
                    accountActive[totalAccounts] = true;
                    totalAccounts++;
                    cout<<"Account Created Successfully!"<<endl;
                }
                else{
                    cout<<"Minimum Opening Balance should be 500!"<<endl;
                }
            }
            break;
            
        }
        case 2: {
            cout<<"==== DISPLAY ALL ACCOUNTS ===="<<endl;
            if(totalAccounts == 0){
                cout<<"No Accounts Found!"<<endl;
                break;
            }
            for(int i =0; i<totalAccounts; i++){
                cout<<"Account "<<i+1<<":"<<endl;
                cout<<"--------------------------------"<<endl;
                cout<<"Account Number: "<<accountNumber[i]<<endl;
                cout<<"Account Holder Name: "<<accountHolderName[i]<<endl;
                cout<<"Mobile Number: "<<mobileNumber[i]<<endl;
                cout<<"Address: "<<address[i]<<endl;
                cout<<"Account Type: "<<accountType[i]<<endl;
                cout<<"Balance: "<<balance[i]<<endl;
                cout<<"Account Status: "<<(accountActive[i] ? "Active" : "Inactive")<<endl;
                cout<<"--------------------------------"<<endl;
            }
            break;
        }
        case 3: {
            cout<<"==== SEARCH ACCOUNT ===="<<endl;
            cout<<"Enter Account Number"<<endl;
            int searchAccount;
            cin>>searchAccount;
            bool found = false;
            for(int i =0; i<totalAccounts; i++){
                if(accountNumber[i] == searchAccount){
                    cout<<"Account Number: "<<accountNumber[i]<<endl;
                    cout<<"Account Holder Name: "<<accountHolderName[i]<<endl;
                    cout<<"Mobile Number: "<<mobileNumber[i]<<endl;
                    cout<<"Address: "<<address[i]<<endl;
                    cout<<"Account Type: "<<accountType[i]<<endl;
                    cout<<"Balance: "<<balance[i]<<endl;
                    cout<<"Account Status: "<<(accountActive[i] ? "Active" : "Inactive")<<endl;
                    found = true;
                    break;
                }
            }
            if(!found){
                cout<<"Account Not Found!"<<endl;
            }
            break;
        }
        case 4: {
            cout<<"==== DEPOSIT MONEY ===="<<endl;
            cout<<"Enter Account Number"<<endl;
            int depositAccount;
            cin>>depositAccount;
            bool found = false;
            for(int i =0; i<totalAccounts; i++){
                if(accountNumber[i] == depositAccount){
                    cout<<"Enter Amount to Deposit"<<endl;
                    float depositAmount;

                    cin>>depositAmount;
                    if(depositAmount <= 0){
                        cout<<"Invalid Amount!"<<endl;
                        break;
                    }
                    balance[i] += depositAmount;
                    lastDeposit[i] = depositAmount;
                    cout<<"Amount Deposited Successfully!"<<endl;
                    cout<<"current Balance: "<<balance[i]<<endl;
                    found = true;
                    break;
                }
            }
            if(!found){
                cout<<"Account Not Found!"<<endl;
            }
            break;
        }
        case 5: {
            cout<<"==== WITHDRAW MONEY ===="<<endl;
            cout<<"Enter Account Number"<<endl;
            int withdrawAccount;
            cin>>withdrawAccount;
            cout<<"Enter Amount to Withdraw"<<endl;
            float withdrawMoney;
            cin>>withdrawMoney;
            if(withdrawMoney <= 0){
                cout<<"Invalid Amount!"<<endl;
                break;
            }
            bool found = false;
            for(int i =0; i<totalAccounts; i++){
                if(accountNumber[i] == withdrawAccount){
                    if(balance[i] - withdrawMoney < 500){
                        cout<<"Insufficient Balance! Minimum Balance should be 500!"<<endl;
                        break;
                    }
                    balance[i] -= withdrawMoney;
                    lastWithdraw[i] = withdrawMoney;
                    cout<<"Amount Withdrawn Successfully!"<<endl;
                    cout<<"Remaining Balance: "<<balance[i]<<endl;
                    found = true;
                    break;
                }
            }
            if(!found){
                cout<<"Account Not Found!"<<endl;
            }
            break;
        }
        case 6: {
            cout<<"==== TRANSFER MONEY ===="<<endl;
            cout<<"Enter Sender Account Number"<<endl;
            int senderAccount;
            cin>>senderAccount;
            cout<<"Enter Receiver Account Number"<<endl;
            int receiverAccount;
            cin>>receiverAccount;
            cout<<"Enter Amount to Transfer"<<endl;
            float transferAmount;
            cin>>transferAmount;
            if(transferAmount <= 0){
                cout<<"Invalid Amount!"<<endl;
                break;
            }
            int senderIndex = -1;
            int receiverIndex = -1;
            for(int i =0; i<totalAccounts; i++){
                if(accountNumber[i] == senderAccount){
                    senderIndex = i;
                    if(balance[i] - transferAmount < 500){
                        cout<<"Insufficient Balance! Minimum Balance should be 500!"<<endl;
                        break;
                    }
                    balance[i] -= transferAmount;
                }
                if(accountNumber[i] == receiverAccount){
                    receiverIndex = i;
                    balance[i] += transferAmount;
                    lastTransfer[i] = transferAmount;
                }
            }
            if(senderIndex == -1){
                cout<<"Sender Account Not Found!"<<endl;
            }
            if(receiverIndex == -1){
                cout<<"Receiver Account Not Found!"<<endl;
            }
            break;
            if(balance[senderIndex] - transferAmount < 500){
                cout<<"Insufficient Balance! Minimum Balance should be 500!"<<endl;
                break;
            }
            balance[senderIndex] -= transferAmount;
            balance[receiverIndex] += transferAmount;
            cout<<"Amount Transferred Successfully!"<<endl;
            break;
        }
        case 7: {
            cout<<"==== UPDATE ACCOUNT ===="<<endl;
            cout<<"Enter Account Number"<<endl;
            int updateAccount;
            cin>>updateAccount;
            bool found = false;
            for(int i =0; i<totalAccounts; i++){
                if(accountNumber[i] == updateAccount){
                    cout<<"Enter New Account Holder Name"<<endl;
                    cin.ignore();
                    getline(cin, accountHolderName[i]);
                    cout<<"Enter New Mobile Number"<<endl;
                    cin>>mobileNumber[i];
                    if(mobileNumber[i].length() != 10){
                        cout<<"Invalid Mobile Number!"<<endl;
                        break;
                    }
                    cout<<"Enter New Address"<<endl;
                    cin.ignore();
                    getline(cin, address[i]);
                    cout<<"Enter New Account Type (Savings/Current)"<<endl;
                    cin>>accountType[i];
                    if(accountType[i] != "Savings" && accountType[i] != "Current"){
                        cout<<"Invalid Account Type!"<<endl;
                        break;
                    }
                    found = true;
                    cout<<"Account Updated Successfully!"<<endl;
                }
            }
            if(!found){
                cout<<"Account Not Found!"<<endl;
            }
            break;

        } 
        case 8: {
            cout<<"==== DELETE ACCOUNT ===="<<endl;
            cout<<"Enter Account Number"<<endl;
            int deleteAccount;
            cin>>deleteAccount;
            bool deleted = false;
            for(int i =0; i<totalAccounts; i++){
                if(accountNumber[i] == deleteAccount){
                    deleted = true;
                    for(int j =i; j<totalAccounts-1; j++){
                        accountNumber[j] = accountNumber[j+1];
                        accountHolderName[j] = accountHolderName[j+1];
                        mobileNumber[j] = mobileNumber[j+1];
                        address[j] = address[j+1];
                        accountType[j] = accountType[j+1];
                        balance[j] = balance[j+1];
                        accountActive[j] = accountActive[j+1];
                    }
                    totalAccounts--;
                    cout<<"Account Deleted Successfully!"<<endl;
                    break;
                }
            }
            if(!deleted){
                cout<<"Account Not Found!"<<endl;
            }
            break;
        }
        case 9: {
            cout<<"==== MINI STATEMENT ===="<<endl;
            cout<<"Enter Account Number"<<endl;
            int miniStatementAccount;
            cin>>miniStatementAccount;
            bool found = false;
            for(int i =0; i<totalAccounts; i++){
                if(accountNumber[i] == miniStatementAccount){
                    cout<<"Account Number: "<<accountNumber[i]<<endl;
                    cout<<"Account Holder Name: "<<accountHolderName[i]<<endl;
                    cout<<"Mobile Number: "<<mobileNumber[i]<<endl;
                    cout<<"Address: "<<address[i]<<endl;
                    cout<<"Account Type: "<<accountType[i]<<endl;
                    cout<<"Balance: "<<balance[i]<<endl;
                    cout<<"Last Deposit: "<<lastDeposit[i]<<endl;
                    cout<<"Last Withdraw: "<<lastWithdraw[i]<<endl;
                    cout<<"Last Transfer: "<<lastTransfer[i]<<endl;
                    cout<<"Account Status: "<<(accountActive[i] ? "Active" : "Inactive")<<endl;
                    cout<<"Thank You for Banking with Us!"<<endl;
                    found = true;
                }
            }
            if(!found){
                cout<<"Account Not Found!"<<endl;
            }
            break;

        } 
        case 10: {
            cout<<"Exiting the Program!"<<endl;
            break;
        }
        
    }
   
}
while(choice != 10);
}