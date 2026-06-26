#include<iostream>
using namespace std;
int main(){
    int number, guess;
    int diffculty;
    int choice;
    int attempts;
    cout<<"===NUMBER GUESSING GAME==="<<endl;
    cout<<"1. Play"<<endl;
    cout<<"2. Rules"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice){
        case 1: 
        cout<<"Let's play the game!"<<endl;
        cout<<"Choose the diffuculty Level:"<<endl;
        cout<<"1. Easy (3 attempts)"<<endl;
        cout<<"2. Medium (5 attempts)"<<endl;
        cout<<"3. Hard (7 attempts)"<<endl;
        cout<<"Enter your choice: ";
        cin>>diffculty;
        switch(diffculty){
            case 1:
            attempts = 3;
            break;
            case 2:
            attempts = 5;
            break;
            case 3:
            attempts = 7;
            break;

            default:
            cout<<"Invalid Difficulty!"<<endl;
            return 0;

        }
        break;
        case 2:
        cout<<"Rules of the game:"<<endl;
        cout<<"1. The player has to guess a number between 1 and 100."<<endl;
        cout<<"2. The player will be given hints if the guess is too high or too Low."<<endl;
        cout<<"3. Choosing the right number. Player will be awarded by 100 points. If the palyer fails to guess the number, he/she will be awarded -10 points on every wrong guess."<<endl;
        cout<<"4. The player have to guess the number in the given number of attempts. Other wise they have to start the game agian."<<endl;
        return 0;
        case 3:
        cout<<"Exiting the game. Goodbye!"<<endl;
        return 0;

        default:
        cout<<"Invalid choice!"<<endl;
        return 0;
    }
    cout<<"Enter a number between  1 and 100: ";
    cin>>number;
    while(number < 1 || number > 100){
        cout<<"Invalid number! Enter again:\n";
        cin>>number;
    }
    int count = 0;
    int score = 100;
    do{
        cout<<"Attempts left: "<<attempts - count<<endl;
        cout<<"Guess the number: ";
        cin>>guess;
        count++;
        if(guess < number){
            cout<<"Too Low! Try again."<<endl;
            score -= 10;
        }
        else if(guess > number){
            cout<<"Too High! Try again."<<endl;
            score -= 10;
        }
       
        else{
            cout<<"Congratulations! You guessed the number."<<endl;
            cout<<"You took "<<count<<" attempts to guess the number."<<endl;
            cout<<"Your score:"<<score<<endl;
            
            
        }
        }
        while(guess != number && count < attempts);
        if(guess != number){
            cout<<"Game Over!"<<endl;
            cout<<"The number was: "<<number<<endl;
        }
        return 0;
    } 