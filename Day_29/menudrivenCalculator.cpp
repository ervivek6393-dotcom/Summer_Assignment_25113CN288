#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int choice;
    do{
        cout<<"==== MENU DRIVEN CALCULATOR ===="<<endl;
        cout<<"1. Addition"<<endl;
        cout<<"2. Subtraction"<<endl;
        cout<<"3. Multiplication"<<endl;
        cout<<"4. Division"<<endl;
        cout<<"5. Square Root"<<endl;
        cout<<"6. Power"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter Your Choice : "<<endl;
        cin>>choice;
        switch(choice){
            case 1: {
                cout<<"==== ADDITION ===="<<endl;
                double num1, num2;
                cout<<"Enter First Number: ";
                cin>>num1;
                cout<<"Enter Second Number: ";
                cin>>num2;
                double result = num1 + num2;
                cout<<"Result: "<<result<<endl;
                break;
            }
            case 2: {
                cout<<"==== SUBTRACTION ===="<<endl;
                double num1, num2;
                cout<<"Enter First Number: ";
                cin>>num1;
                cout<<"Enter Second Number: ";
                cin>>num2;
                double result = num1 - num2;
                cout<<"Result: "<<result<<endl;
                break;
            }
            case 3: {
                cout<<"==== MULTIPLICATION ===="<<endl;
                double num1, num2;
                cout<<"Enter First Number: ";
                cin>>num1;
                cout<<"Enter Second Number: ";
                cin>>num2;
                double result = num1 * num2;
                cout<<"Result: "<<result<<endl;
                break;
            }
            case 4: {
                cout<<"==== DIVISION ===="<<endl;
                double num1, num2;
                cout<<"Enter First Number: ";
                cin>>num1;
                cout<<"Enter Second Number: ";
                cin>>num2;
                if(num2 == 0){
                    cout<<"Error: Division by zero is not allowed!"<<endl;
                } else {
                    double result = num1 / num2;
                    cout<<"Result: "<<result<<endl;
                }
                break;
            }
            case 5: {
                cout<<"==== SQUARE ROOT ===="<<endl;
                double num;
                cout<<"Enter Number: ";
                cin>>num;
                if(num < 0){
                    cout<<"Error: Square root of negative number is not defined!"<<endl;
                } else {
                    double result = sqrt(num);
                    cout<<"Result: "<<result<<endl;
                }
                break;
            }
            case 6: {
                cout<<"==== POWER ===="<<endl;
                double base, exponent;
                cout<<"Enter Base: ";
                cin>>base;
                cout<<"Enter Exponent: ";
                cin>>exponent;
                double result = pow(base, exponent);
                cout<<"Result: "<<result<<endl;
                break;
            }
            case 7: {
                cout<<"Exiting the calculator. Goodbye!"<<endl;
                break;
            }
        }

    }
    while(choice != 7);
}