#include <conio.h>

#include <iostream>

#include <string.h>

 

using namespace std;

static int p = 0;

class busreserve

 

{

  char busn[4],arrival[5],depart[5];

  char  driver[10], from[10], to[10], seat[8][4][10],amt[10],date[10];

public:

  void insert_bus();

  void reservation();

  void empty();

  void show();

  void availability();

  void position(int i);

 

}bus[10];

 

void busreserve::insert_bus()

{

  cout<<"\n\n\nEnter bus no: ";

  cin>>bus[p].busn;

  cout<<"\nEnter Driver's name: ";

  cin>>bus[p].driver;

  cout<<"\nArrival time: ";

  cin>>bus[p].arrival;

  cout<<"\nDeparture time: ";

  cin>>bus[p].depart;

  cout<<"\nFrom: ";

  cin>>bus[p].from;

  cout<<"\nTo: ";

  cin>>bus[p].to;

  cout<<"\nDate: ";

  cin>>bus[p].date;

  cout<<"\nAmount: ";

  cin>>bus[p].amt;

  bus[p].empty();

  p++;

  cout<<"\n\nBus added Sucessfully ";

}

void busreserve::reservation()

 

{

   int seat;

   char number[5];

top:

  cout<<"\n\n\n\t\t\tBus no: ";

  cin>>number;

  int n;

  for(n=0;n<=p;n++)

{

   if(strcmp(bus[n].busn, number)==0)

   break;

}

while(n<=p)

{

    cout<<"\n\t\t\tSeat Number: ";

    cin>>seat;

    if(seat>32)

    {

       cout<<"\n\t\t\tThere are only 32 seats available in this bus.";

    }

    else

    {

 

    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)

    {

        cout<<"\t\t\tEnter passanger's name: ";

 

        cin>>bus[n].seat[seat/4][(seat%4)-1];

 

        cout<<"\t\t\tSeat Reserved Sucessfully\n\n ";

 

         cout<<"\n**************************************************************************************************************************************************";

 

         cout<<"\n\tBus no: "<<bus[n].busn <<"\t\t\t\t\t\t\t\t\t\t\t\tDate: "<<bus[n].date<<"\n\n\t\tDriver: "<<bus[n].driver<<"\t\tArrival time: "<<bus[n].arrival<<"\t\tDeparture time: "<<bus[n].depart<<"\t\tFrom: "<<bus[n].from<<"\t\tTo: "<< bus[n].to<<"\n";

 

         cout<<"\n**************************************************************************************************************************************************\n";

         cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tTotal Amount: "<<bus[n].amt<<"\n";

         cout<<"\n**************************************************************************************************************************************************\n";

        break;

 

      }

 

    else

 

      cout<<"\t\t\tThe seat no. is already reserved.\n";

      }

      }

      if(n>p)

      {

          cout<<"\t\t\tEnter correct bus no.\n";

          goto top;

      }

}

 

void busreserve::empty()

 

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

        strcpy(bus[p].seat[i][j], "Empty");

    }

  }

}

 

void busreserve::show()

{

  int n;

  char number[5];

  cout<<"\t\t\tEnter bus no: ";

  cin>>number;

  for(n=0;n<=p;n++)

  {

   if(strcmp(bus[n].busn, number)==0)

   break;

  }

 

while(n<=p)

 

{

 

  cout<<"\n**************************************************************************************************************************************************";

 

  cout<<"\n\t\t\tBus no: \t"<<bus[n].busn

 

  <<"\n\t\t\tDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"

 

  <<bus[n].arrival<<"\t\t\tDeparture time:"<<bus[n].depart

 

  <<"\n\t\t\tFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<

 

  bus[n].to<<"\t\t\tAmount: "<<bus[n].amt<<"\n";

 

  cout<<"**************************************************************************************************************************************************";

 

  bus[0].position(n);

 

  int a=1;

 

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(bus[n].seat[i][j],"Empty")!=0)

      cout<<"\n\t\t\tThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j];

    }

  }

break;

}

   if(n>p)

      cout<<"\t\t\tEnter correct bus no: ";

}

 

void busreserve::position(int l)

{

  int s=0;p=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

       s++;

      if(strcmp(bus[l].seat[i][j], "Empty")==0)

       {

           p++;

       }

    }

  }

  cout<<"\t\t\tThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;

 

  }

 

void busreserve::availability()

 

{

    for(int n=0;n<p;n++)

    {

    cout<<"\n**********************************************************************************************************************************************";

 

    cout<<"\n Bus no: "<<bus[n].busn<<"\n\n\tDriver: "<<bus[n].driver <<"\t\tArrival time: "<<bus[n].arrival<<"\t\tDeparture Time: "

 

    <<bus[n].depart<<"\tFrom: "<<bus[n].from<<"\t To: "

 

    <<bus[n].to<<"\t\tAmount: "<<bus[n].amt<<"\n";

 

    cout<<"*************************************************************************************************************************************************";

 

 

 

  }

 

}

 

int main()

{

  system("cls");

  int w;

  while(1)

  {

   cout<<"\n\n\n\n\n";

   cout<<"\t\t\tBus Reservation System \n\n";

   cout<<"\t\t\t1.Insert Bus\n\t\t\t2.Buses Available\n\t\t\t3.Display\n\t\t\t4. Bus Reservation. \n\t\t\t5.Exit";

   cout<<"\n\t\t\tEnter your choice:  ";

   cin>>w;

   switch(w)

   {

       case 1:

           bus[p].insert_bus();

           break;

       case 2:

           bus[0].availability();

           break;

       case 3:

           bus[0].show();

           break;

       case 4:

           bus[p].reservation();

           break;

       case 5:

 

           exit(0);

    }

  }

return 0;

}