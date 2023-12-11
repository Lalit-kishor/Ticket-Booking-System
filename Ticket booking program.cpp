#include <conio.h>
#include <cstdio>
#include<limits>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

static int t = 0;

class Airport

{

    char flight_number[5], flight_name[20], flight_arrival[10], flight_depart[10], from[20], to[20], flight_seat[8][4][20];

public:

    void add_new_flight();

    void reservation();
    
    void cancellation();

    void empty();

    void view();

    void avail();

    void position(int i);

}flight[50];

void border_line(char ch)

{

    for (int x=80; x>0; x--)

        cout<<ch;

}

void Airport::add_new_flight()

{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout<<"Enter flight Number: ";

    cin.getline(flight[t].flight_number,5);

    cout<<"\nEnter flight Name: ";

    cin.getline(flight[t].flight_name,20);

    cout<<"\nArrival Time: ";

    cin.getline(flight[t].flight_arrival,10);

    cout<<"\nDeparture: ";

    cin.getline(flight[t].flight_depart,10);

    cout<<"\nFrom: ";

    cin.getline(flight[t].from,20);

    cout<<"\nTo: ";

    cin.getline(flight[t].to,20);

    flight[t].empty();
    cout<<"\nNew flight Added Successfully \t\t\t";
    t++;

}

void Airport::reservation()

{

    int flight_seat;

    char no[5];

top:

    cout<<"flight Number: ";

    cin>>no;

    int y;

    for(y=0; y<=t; y++)

    {

        if(strcmp(flight[y].flight_number, no)==0)

            break;

    }

    while(y<=t)

    {

        cout<<"\nSeat Number: ";

        cin>>flight_seat;

        if(flight_seat>32)

        {

            cout<<"\nThere are only 32 Seats Available in this flight.";

        }

        else

        {

            if (strcmp(flight[y].flight_seat[flight_seat/4][(flight_seat%4)-1], "-")==0)

            {

                cout<<"Enter Passenger's Name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
                cin.getline(flight[y].flight_seat[flight_seat/4][(flight_seat%4)-1],20);
                cout<<"\nTicket has been booked Successfully.🎉"
                break;

            }

            else

                cout<<"This Seat Number is Already Reserved.😥\n";

        }

    }

    if(y>t)

    {

        cout<<"Enter Correct flight Number.\n";

        goto top;

    }

}

void Airport::cancellation()
{
    int flight_seat;

    char no[5];

    top:

    cout<<"flight Number: ";

    cin>>no;

    int y;

    for(y=0; y<=t; y++)

    {

        if(strcmp(flight[y].flight_number, no)==0)

            break;

    }

    while(y<=t)

    {

        cout<<"\nSeat Number: ";

        cin>>flight_seat;

        if(flight_seat>32)

        {

            cout<<"\nThere are only 32 Seats Available in this flight.";

        }

        else

        {

            if (strcmp(flight[y].flight_seat[flight_seat/4][(flight_seat%4)-1], "-")!=0)

            {
                strcpy(flight[y].flight_seat[flight_seat/4][(flight_seat%4)-1], "-");  // cancelled
                cout<<"Ticket has been cancelled Successfully.\n";
                break;

            }

            else

                cout<<"This Seat Number is Already Cancelled.\n";

        }

    }

    if(y>t)

    {

        cout<<"Enter Correct flight Number.\n";

        goto top;

    }
}

void Airport::empty()

{

    for(int x=0; x<8; x++)

    {

        for(int z=0; z<4; z++)

        {

            strcpy(flight[t].flight_seat[x][z], "-");

        }

    }

}

void Airport::view()

{

    int m;

    char number[5];

    cout<<"Enter flight Number: ";

    cin>>number;

    for(m=0; m<=t; m++)

    {

        if(strcmp(flight[m].flight_number, number)==0)

            break;

    }

    while(m<=t)

    {

        border_line('*');
        cout<<endl;
        
        cout<<"flight Number: \t"<<flight[m].flight_number

            <<"\nflight Name: \t"<<flight[m].flight_name<<"\t\tArrival Time: \t"

            <<flight[m].flight_arrival<<"\tDeparture Time:\t"<<flight[m].flight_depart

            <<endl<<"\nFrom: \t\t"<<flight[m].from<<"\t\tTo: "<<

            flight[m].to<<"\n";

        border_line('*');

        flight[0].position(m);

        int d=1;

        for (int x=0; x<8; x++)

        {

            for(int y=0; y<4; y++)

            {

                d++;

                if(strcmp(flight[m].flight_seat[x][y],"-")!=0)

                    cout<<"\nThe Seat no "<<(d-1)<<" is Reserved for "<<flight[m].flight_seat[x][y]<<".";

            }

        }

        break;

    }

    if(m>t)

        cout<<"Enter Correct flight Number: ";

}

void Airport::position(int l)

{

    int r=0;
    t=0;

    for (int x =0; x<8; x++)

    {

        cout<<"\n";

        for (int z = 0; z<4; z++)

        {

            r++;

            if(strcmp(flight[l].flight_seat[x][z], "-")==0)

            {

                cout.width(5);

                cout.fill(' ');

                cout<<r<<".";

                cout.width(10);

                cout.fill(' ');

                cout<<flight[l].flight_seat[x][z];

                t++;

            }

            else

            {

                cout.width(5);

                cout.fill(' ');

                cout<<r<<".";

                cout.width(10);

                cout.fill(' ');

                cout<<flight[l].flight_seat[x][z];

            }

        }

    }

    cout<<"\n\nThere are "<<t<<" Seats Empty in flight Number: "<<flight[l].flight_number;

}

void Airport::avail()

{


    for(int y=0; y<t; y++)

    {

        border_line('*');
        cout<<endl;
        
        cout<<"flight Number: \t"<<flight[y].flight_number<<"\nflight Name: \t"<<flight[y].flight_name

            <<"\t\tArrival Time: \t"<<flight[y].flight_arrival<<"\tDeparture Time:   "

            <<flight[y].flight_depart<<endl<<"\nFrom: \t\t"<<flight[y].from<<"\t\tTo: "

            <<flight[y].to<<"\n";

        border_line('*');

        //border_line('_');

    }

}

int main()

{

    system("cls");

    int w;

    while(1)

    {
        //system("cls");
        cout<<"\n\n";
        cout<<"\t\t\t\t\t\t-------------------------------------\n";
        cout<<"\t\t\t\t\t\t|   SIMPLE flight RESERVATION SYSTEM   |\n";
        cout<<"\t\t\t\t\t\t-------------------------------------\n";
        cout<<"\n";

        cout<<"\n\n";

        cout<<"\t\t\t\t\t\t\t1.Add New flight Number\n\t\t\t\t\t\t\t"

            <<"2.Show Available flightes\n\t\t\t\t\t\t\t"

            <<"3.Available seats\n\t\t\t\t\t\t\t"

            <<"4.Book Ticket \n\t\t\t\t\t\t\t"

            <<"5.Cancel Ticket \n\t\t\t\t\t\t\t"

            <<"6.Exit";

        cout<<"\n\n\n\t\t\t\t\t\tEnter your Choice:- ";

        cin>>w;

        switch(w)

        {

        case 1:
            flight[t].add_new_flight();

            break;
        
        case 2:
            flight[0].avail();

            break;

        case 3:
            flight[0].view();

            break;
            
        case 4:
            flight[t].reservation();

            break;

        case 5:
            flight[t].cancellation();

            break;

        case 6:
            exit(0);

        }

    }

    return 0;

}
