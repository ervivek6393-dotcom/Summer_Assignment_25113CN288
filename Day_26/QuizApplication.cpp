#include<iostream>
using  namespace std;
int main(){
    int choice;
    int score = 0;
    int answer[10];
    int correctAnswer[10] = {1, 2, 2, 1, 1, 2, 1, 2, 3, 1};
    cout<<"===QUIZ APPLICATION==="<<endl;
    cout<<"1. Start Quiz"<<endl;
    cout<<"===Instructions==="<<endl;
    cout<<"1. The quiz consits of 10 questions."<<endl;
    cout<<"2. Each question has 4 options only one of them are correct."<<endl;
    cout<<"3. Each correct answer will be awarded 4 marks and each wrong answer will be deducted 1 mark."<<endl;
    cout<<"4. The total marks will be calculated at the end of the quiz."<<endl;
    cout<<"5. The quiz will be end in 10 minutes. After starting the quiz, you have to answer all the question with in the 10 minutes."<<endl;
    cout<<"6. Try to attempts all the questions."<<endl;
    cout<<"Enter your choice:";
    cin>>choice;
    if(choice == 1){
        cout<<"Starting quiz..."<<endl;
    }
    else{
        cout<<"Quit"<<endl;
    }

    cout<<"2. Quit"<<endl;
    switch(choice){
        case 1:{
        cout<<"Start Quiz"<<endl;
        break;
        }
        case 2:{
            cout<<"Quit"<<endl;
            break;

        }




    }
    cout<<"Q1. What is the capital of India?"<<endl;
    cout<<"1. New Delhi"<<endl;
    cout<<"2.New York"<<endl;
    cout<<"3. Kabul"<<endl;
    cout<<"4. Pakistan"<<endl;
    cout<<"Enter your answer:";
    cin>>answer[0];
    correctAnswer[0] = 1;
    cout<<"Q2. What is the currency of India?"<<endl;
    cout<<"1. Dollar"<<endl;
    cout<<"2. Rupee"<<endl;
    cout<<"3. Pound"<<endl;
    cout<<"4. Euro"<<endl;
    cout<<"Enter your answer:";
    cin>>answer[1];
    correctAnswer[1] = 2;
    cout<<"Q3. What is the national animal of India?"<<endl;
    cout<<"1. Lion"<<endl;
    cout<<"2. Tiger"<<endl;
    cout<<"3. Elephant"<<endl;
    cout<<"4. Peacock"<<endl;
    cout<<"Enter your answer:";
    cin>>answer[2];
    correctAnswer[2] = 2;
    cout<<"Q4. Who is the first Prime Minister Of India?"<<endl;
    cout<<"1. Jawaharlal Nehru"<<endl;
    cout<<"2. Indira Gandhi"<<endl;
    cout<<"3. Rajiv Gandhi"<<endl;
    cout<<"4. Narendra Modi"<<endl;
    cout<<"Enter your answer:";
    cin>>answer[3];
    correctAnswer[3] = 1;
    cout<<"Q5. Who is the founder of CPP?"<<endl;
    cout<<"1. Bjarne Stroustrup"<<endl;
    cout<<"2. James Gosling"<<endl;
    cout<<"3. Dennis Ritchie"<<endl;
    cout<<"4. Guido van Rossum"<<endl;
    cout<<"Enter your answer:";
    cin>>answer[4];
    correctAnswer[4] = 1;
    cout<<"Q6. How many bytes does a  integer data type take in c++?"<<endl;
    cout<<"1. 2 bytes"<<endl;
    cout<<"2. 4 bytes"<<endl;
    cout<<"3. 8 bytes"<<endl;
    cout<<"4. 16 bytes"<<endl;
    cout<<"Enter your answer:";
    cin>>answer[5];
    correctAnswer[5] = 2;
    cout<<"Q7. What is  the work of Break statement in c++?"<<endl;
    cout<<"1. To terminate the loop"<<endl;
    cout<<"2. To skip the loop"<<endl;
    cout<<"3. To continue the loop"<<endl;
    cout<<"4. To exit the loop"<<endl;
    cout<<"Enter your answer:";
    cin>>answer[6];
    correctAnswer[6] = 1;
    cout<<"Q8. What is the output of the following code?"<<endl;
    cout<<"int main(){"<<endl;
    cout<<"    cout<<\"Hello, World!\"<<endl;"<<endl;
    cout<<"    return 0;"<<endl;
    cout<<"}"<<endl;
    cout<<"1. Hello, world!"<<endl;
    cout<<"2. Hello, World!"<<endl;
    cout<<"3. hello, world!"<<endl;
    cout<<"4. hello, World!"<<endl;
    cout<<"Enter your answer:";
    cin>>answer[7];
    correctAnswer[7] = 1;
    cout<<"Q9. What is the mistake in the following code?"<<endl;
    cout<<"int main(){"<<endl;
    cout<<"   int a = 10;"<<endl;
    cout<<"   int b = 20;"<<endl;
    cout<<"   cout<<a + b<<endl;"<<endl;
    cout<<"   return 0;"<<endl;
    cout<<"}"<<endl;
    cout<<"1. Missing semicolon after 'int a = 10'"<<endl;
    cout<<"2. Missing semicolon after 'int b = 20'"<<endl;
    cout<<"3. Missing semicolon after 'cout<<a + b<<endl'"<<endl;
    cout<<"4. Missing semicolon after 'return 0'"<<endl;
    cout<<"Enter your answer:";
    cin>>answer[8];
    correctAnswer[8] = 1;
    cout<<"Q10. What is header file in code?"<<endl;
    cout<<"1. A file that contains the declarations of funtions and variables"<<endl;
    cout<<"2. A file that contains the definitions of funtions and variables"<<endl;
    cout<<"3. A file that contains the implementation of funtions and variables"<<endl;
    cout<<"4. A file that contains the documentaton of funtions and variables"<<endl;
    cout<<"Enter your answer:";
    cin>>answer[9];
    correctAnswer[9] = 1;
    for(int i = 0; i<10; i++){
        if(answer[i] == correctAnswer[i]){
            score += 4;
        }
        else{
            score -= 1;

        }
        }
          cout<<"\n====Results===="<<endl;
          cout<<"Total Score: "<<score<<endl;
          return 0;


   
    }
  
    

