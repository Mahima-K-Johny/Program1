//Hotel billing system
#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

class hotel
{
public:
    int days,rooms,id,cost,cost2,time1,cost3,tcost=0;
    float gst,ttcost;
    string rtype,name,ftype,ftype2,gd;
public:
    void getdata()
    {
        cout<<"\nEnter name of the customer:";
        cin>>name;
        cout<<"\nEnter customer Id:";
        cin>>id;
        cout<<"\nEnter no.of days of stay:";
        cin>>days;
        cout<<"\nEnter no.of rooms:";
        cin>>rooms;
        cout<<"\nEnter N for normal and L for luxury";
        cout<<"\nEnter the type of room(N/L):";
        cin>>rtype;
        if(rtype=="N"||rtype=="n")
            cost=1500;
        else if(rtype=="L"||rtype=="l")
            cost=2500;
        else
            cout<<"\nInvalid";
        tcost=tcost+(cost*days*rooms);
    }
    void disp()
    {
        cout<<"\n\n*******#BILL FOR STAY*******";
        cout<<"\nCustomer Name:"<<name<<"\nCustomer Id:"<<id<<"\nNo.of days of stay:"<<days<<"\nNo.of rooms:"<<rooms<<"\nType of room:"<<rtype<<"\nTotal amount:"<<days*rooms*cost;
    }
    void fgetdata()
    {
        cout<<"\n\nEnter type of food(B-Buffet and N-Normal):";
        cin>>ftype;
        if(ftype=="B"||ftype=="b")
         {
            cost2=2500;
            fgetdatadisp();
             tcost=tcost+cost2;
         }
          else if(ftype=="N"||ftype=="n")
            nget();
    }
    void fgetdatadisp()
    {

           cout<<"\n\n********#BILL FOR FOOD********";
            cout<<"\nType of food:"<<ftype<<"\nCost:"<<cost2;

    }
    void nget()
    {
        cout<<"Enter veg(v),non-veg(n)or vegan(vg):";
        cin>>ftype2;
        if(ftype2=="v"||ftype2=="V")
            cost2=1200;
        else if(ftype2=="N"||ftype2=="n")
            cost2=1500;
        else if(ftype2=="vg"||ftype2=="VG")
            cost2=2000;
        tcost=tcost+cost2;
        ngetdisp();
    }
    void ngetdisp()
    {
        cout<<"\n\n********#BILL FOR FOOD********";
        cout<<"\nType of food:"<<ftype2<<"\nCost:"<<cost2;
    }
    void gym()
    {
        cout<<"\n\nDid u use gym facility(y/n):";
        cin>>gd;
        if(gd=="Y"||gd=="y")
        {
            cout<<"\nEnter no.of hrs:";
            cin>>time1;
        }
        cost3=500*time1;
        if(gd=="n"||gd=="N")
        {
            cout<<"No.of hrs=0\nCost=0";
            time1=0;
            cost3=0;
        }
        tcost=tcost+cost3;
    }
    void gymdisp()
    {
        cout<<"\n\n********#BILL FOR GYM********";
        cout<<"\nNo.of hours:"<<time1<<"\nCost:"<<cost3;
    }
    void calc()
    {
      cout<<"\n\nTotal cost:"<<tcost;
      gst=tcost*0.03;
      ttcost=tcost+gst;
      cout<<"\nGst:"<<gst;
      cout<<"\nNet amount:"<<ttcost;
    }
    void ttime()
    {
        time_t tt;
    struct tm * ti;

    time (&tt);
    ti = localtime(&tt);

    cout << "\n\t\tCurrent Day, Date and Time is "<< asctime(ti);
    }
};
int main()
{
    int q;
    hotel obj;
    do
    {
        cout<<"\n\n1-BILL FOR STAY\n2-BILL FOR FOOD\n3-BILL FOR GYM\n4-ALL BILLS\n";
        cin>>q;
        switch(q)
        {
        case 1:
            obj.getdata();
            obj.disp();
            break;
        case 2:
            obj.fgetdata();
             //obj.fgetdatadisp();
             break;
        case 3:
            obj.gym();
            obj.gymdisp();
            break;
        case 4:
            //obj.getdata();
            //obj.fgetdata();
            //obj.gym();
            cout<<"\t\t*******************PARADISE FALLS**********************";
            obj.ttime();
            obj.disp();
            obj.fgetdatadisp();
            obj.gymdisp();
            obj.calc();
            break;
        case 5:
            exit(0);
        }
    }while((q>=1)&&q<=4);
    return 0;
}

