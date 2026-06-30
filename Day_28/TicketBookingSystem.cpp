#include<iostream>
#include<string>
using namespace std;
int main(){
    int bookingID[100];
    string passengerName[100];
    int age[100];
    string gender[100];
    string source[100];
    string destination[100];
    int seatNumber[100];
    string coachType[100];
    float ticketPrice[100];
    bool booked[100];
    int totalBookings = 0;
    int choice;

    do{
    cout<<"==== TICKET BOOKING SYSTEM ===="<<endl;
    cout<<"1. Book Ticket"<<endl;
    cout<<"2. Display All Bookings"<<endl;
    cout<<"3. Search Booking"<<endl;
    cout<<"4. Cancel Booking"<<endl;
    cout<<"5. Update Booking"<<endl;
    cout<<"6. Ticket Price Calculator"<<endl;
     cout<<"7. Print Ticket"<<endl;
    cout<<"8. Exit"<<endl;
    cout<<"Enter Your Choice :"<<endl;
    cin>>choice;
    switch(choice){
        case 1: {
            cout<<"==== BOOK TICKET ===="<<endl;
            cout<<"Enter Bookking ID"<<endl;
            cin>>bookingID[totalBookings];
            bool bookingExist = false;
            for(int i =0; i<totalBookings; i++){
                if(bookingID[i] == bookingID[totalBookings]){
                    bookingExist = true;
                    break;

                }
                if(!bookingExist){
                    cout<<"Enter Passaenger Name"<<endl;
                    cin.ignore();
                    getline(cin, passengerName[totalBookings]);
                    cout<<"Enter Age"<<endl;
                    cin>>age[totalBookings];
                    if(age[totalBookings] <= 0){
                        cout<<"Invalid Age!"<<endl;
                        break;
                    }
                    cout<<"Enter Gender"<<endl;
                    cin.ignore();
                    getline(cin, gender[totalBookings]);
                    cout<<"Enter Source"<<endl;
                    getline(cin, source[totalBookings]);
                    cout<<"Enter DEstination"<<endl;
                    getline(cin, destination[totalBookings]);
                    cout<<"Enter Seat Number"<<endl;
                    cin>>seatNumber[totalBookings];         
                    cout<<"Enter Coach Type (AC/Non-AC)"<<endl;
                    cin>>coachType[totalBookings];
                    totalBookings++;
                    cout<<"Ticket Booked Successfully!"<<endl;
                    if(coachType[totalBookings] != "AC" && coachType[totalBookings] != "Non-AC"){
                        cout<<"Invalid Coach Type!"<<endl;
                        break;
                    }
                }
            }
            break;

        }
        case 2: {
            cout<<"==== DISPLAY ALL BOOKINGS ===="<<endl;
            if(totalBookings == 0){
                cout<<"No Bookings Found!"<<endl;
                break;
            }
            for(int i =0; i<totalBookings; i++){
                cout<<"Booking "<<i+1<<":"<<endl;
                cout<<"--------------------------------"<<endl;
                cout<<"Booking ID: "<<bookingID[i]<<endl;
                cout<<"Passenger Name: "<<passengerName[i]<<endl;
                cout<<"Age: "<<age[i]<<endl;
                cout<<"Gender: "<<gender[i]<<endl;
                cout<<"SOurce: "<<source[i]<<endl;
                cout<<"Destination: "<<destination[i]<<endl;
                cout<<"Seat Number: "<<seatNumber[i]<<endl;
                cout<<"Coach Type: "<<coachType[i]<<endl;
                cout<<"Ticket Price: "<<ticketPrice[i]<<endl;
                cout<<"Booking Status: "<<(booked[i] ? "Booked" : "Cancelled")<<endl;
                cout<<"--------------------------------"<<endl;
            }
            break;
        }
        case 3: {
            cout<<"==== SEARCH BOOKING ===="<<endl;
            cout<<"Enter Booking ID"<<endl;
            int searchBooking;
            cin>>searchBooking;
            bool found = false;
            for(int i =0; i<totalBookings; i++){
                if(bookingID[i] == searchBooking){
                    cout<<"Booking ID: "<<bookingID[i]<<endl;
                    cout<<"Passenger Name: "<<passengerName[i]<<endl;
                    cout<<"Age: "<<age[i]<<endl;
                    cout<<"Gender: "<<gender[i]<<endl;
                    cout<<"Source: "<<source[i]<<endl;
                    cout<<"Destination: "<<destination[i]<<endl;    
                    found = true;
                    break;
                }
            }
            if(!found){
                cout<<"Booking not found!"<<endl;
            }
            break;
        }
        case 4: {
            cout<<"==== CANCEL BOOKING ===="<<endl;
            cout<<"Enter Booking ID"<<endl;
            int cancelBooking;
            cin>>cancelBooking;
            bool cancelled = false;
            for(int i =0; i<totalBookings; i++){
                if(bookingID[i] == cancelBooking){
                    booked[i] = false;
                    cancelled = true;
                    cout<<"Booking Cancelled Successfully!"<<endl;
                    break;
                }
            }
            if(!cancelled){
                cout<<"Booking Not Found!"<<endl;
            }
            break;

        }   
        case 5: {
            cout<<"==== UPDATE BOOKING ===="<<endl;
            cout<<"Enter Booking ID"<<endl;
            int updateBooking;
            cin>>updateBooking;
            bool found = false;
            for(int i =0; i<totalBookings; i++){
                if(bookingID[i] == updateBooking){
                    cout<<"Enter New Passenger Name"<<endl;
                    cin.ignore();
                    getline(cin, passengerName[i]);
                    cout<<"Enter New Age"<<endl;
                    cin>>age[i];
                    if(age[i] <= 0){
                        cout<<"Invalid Age!"<<endl;
                        break;
                    }

                }
                if(!found){
                    cout<<"Booking Not Found!"<<endl;
                }
            }
            break;
        }
        case 6: {
            cout<<"==== TICKET PRICE CALCULATOR ===="<<endl;
            cout<<"Enter Booking ID"<<endl;
            int priceBooking;
            cin>>priceBooking;
            bool found = false;
            for(int i =0; i<totalBookings; i++){
                if(bookingID[i] == priceBooking){
                    if(coachType[i] == "AC"){
                        ticketPrice[i] = 1000;
                    }
                    else{
                        ticketPrice[i] = 500;
                    }
                    cout<<"Ticket Price: "<<ticketPrice[i]<<endl;
                    found = true;
                    break;
                }
            }
            if(!found){
                cout<<"Booking Not Found!"<<endl;
            }
            break;

        }
        case 7: {
            cout<<"==== PRINT TICKET ===="<<endl;
            cout<<"Enter Booking ID"<<endl;
            int printBooking;
            cin>>printBooking;
            bool found = false;
            for(int i =0; i<totalBookings; i++){
                if(bookingID[i] == printBooking){
                    cout<<"Booking ID: "<<bookingID[i]<<endl;
                    cout<<"Passenger Name: "<<passengerName[i]<<endl;
                    cout<<"Age: "<<age[i]<<endl;
                    cout<<"Coach Type: "<<coachType[i]<<endl;
                    cout<<"Ticket Price: "<<ticketPrice[i]<<endl;
                    found = true;
                    break;
                }
            }
            if(!found){
                cout<<"Booking Not Found!"<<endl;
            }
            break;
        }
        case 8: {
            cout<<"Exiting Ticket Booking System..."<<endl;
            break;
        }
        default: {
            cout<<"Invalid Choice!"<<endl;
            break;
        }
    }    
} 
while(choice != 8);
return 0;
}
