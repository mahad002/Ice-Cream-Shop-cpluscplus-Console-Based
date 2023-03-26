#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <string>
#include <cmath>
#include <time.h>
#include <cctype>

using namespace std;

struct Address{
    char* City;
    char* Location;

};

struct Customer{
    string name;
    int custID;
    int purchase=0;
    int *perweek;
    int age;
    bool disc = false;
};

struct Flavor{
    int flavorID;
    int Price[2];

};

struct ICEOutlet{
    int OutletID;
    string Outletname;
    Address Outlet_Add;
    Customer* TopCus = new Customer[10];
    Customer* Total = new Customer[30];
    Flavor Menu[4];
    int Tcus=30;
    //Customer Cus

}Shops[50];

void WeeklyPurchase()
{
    int Total=0;
    for(int i=0; i<50; i++)
    {
        for(int j=0; j<Shops[i].Tcus; j++)
        {
            if(Shops[i].Total[j].purchase > 2000)
            {
                Shops[i].Total[j].disc = true;
            }
        }
    }
    for(int j=0; j<50; j++)
    {
        cout<<"------------------------------------------\n";
        for(int i=0; i<Shops[j].Tcus; i++)
        {
            Total+=Shops[j].Total[i].purchase;
        }
        cout<<"Outlet "<<j<<" Total Weekly Purchase: "<<Total;
        cout<<endl;
        cout<<"------------------------------------------\n";
        Total=0;
    }
}

void TopCustomers()
{
    int x=0;
    Customer Temp;
    bool nomoreswaps = false;
    while(x==0)
    {
        int Shop;
        cout<<"-----------------------------------------\n";
        cout<<"Select OUTLET: \n";
        cin>>Shop;
        cout<<"------------------------------------------\n";

        while(nomoreswaps==false)
        {
            nomoreswaps = true;
            for(int i=0; i<Shops[Shop].Tcus; i++)
            {
                if(Shops[Shop].Total[i].purchase<Shops[Shop].Total[i+1].purchase)
                {
                    Temp=Shops[Shop].Total[i];
                    Shops[Shop].Total[i] = Shops[Shop].Total[i+1];
                    Shops[Shop].Total[i+1] = Temp;
                    nomoreswaps = false;
                }
            }
        }

        for(int i=0; i<10; i++)
        {
            Shops[Shop].TopCus[i]=Shops[Shop].Total[i];
            Shops[Shop].Total[i].disc=true;
            Shops[Shop].TopCus[i].disc=true;
        }

        cout<<"------------------------------------------\n";
        cout<<"Top Customers \n";
        cout<<"------------------------------------------\n";
        for(int i=0; i<10; i++)
        {
            cout<<"Customer ID: "<<Shops[Shop].TopCus[i].custID<<endl;
            cout<<"Customer Name: "<<Shops[Shop].TopCus[i].name<<endl;
            cout<<"Total Purchase: "<<Shops[Shop].TopCus[i].purchase<<endl<<endl;
        }

        nomoreswaps = false;
        cout<<"You want to check more? Press '0' for Yes!\n";
        cin>>x;
    }
}

void Revenue()
{
    int Revenue=0;
    for(int i=0; i<50; i++)
    {
        for(int j=0; j<30; j++)
        {
            Revenue+=Shops[i].Total[j].purchase;
        }
        cout<<"--------------------------------------\n";
        cout<<"Outlet: "<<Shops[i].OutletID<<"\t"<<"Revenue: "<<Revenue<<endl;
        cout<<"--------------------------------------\n";
        Revenue=0;

    }
}

void AgeAnalysis()
{
    int S=0, M=0, L=0;

    for(int i=0; i<50; i++)
    {
        for(int j=0; j<Shops[i].Tcus; j++)
        {
            if(Shops[i].Total[j].disc==true)
            {
                if(Shops[i].Total[j].age <= 13)
                {
                    S++;
                }
                else if(Shops[i].Total[j].age <= 30)
                {
                    M++;
                }
                else
                {
                    L++;
                }
            }
        }
    }
    cout<<"------------------------------------------\n";
    cout<<"Age Analysis\n";
    cout<<"------------------------------------------\n";
    cout<<"Number of Kids: "<<S<<endl;
    cout<<"Number of Young Adults: "<<M<<endl;
    cout<<"Number of Adults: "<<L<<endl;
    cout<<"------------------------------------------\n";
}

void name(string &name)
{
    string letters="AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
    for(int i=0; i<rand()%9+2; i++)
    {
        name+=letters[rand()%52];
    }
}

void Customer0(Customer* Cus)
{
    for(int i=0; i<30; i++)
    {
        name(Cus[i].name);
        Cus[i].custID=i;
        Cus[i].perweek=new int [2];
        for(int j=0; j<2; j++)
        {
            Cus[i].perweek[j]=0;
        }
        Cus[i].age=rand()%100+2;
    }
}

void Outlet0(ICEOutlet* Shops)
{
    char* num[]={"0","1","2","3","4","5","6","7","8","9"};
    for(int i=0; i<50; i++)
    {
        Shops[i].OutletID=i;
        name(Shops[i].Outletname);
        if(i<10)
            Shops[i].Outlet_Add.City = "A";
        else if(i<20)
            Shops[i].Outlet_Add.City = "B";
        else if(i<30)
            Shops[i].Outlet_Add.City = "C";
        else if(i<40)
            Shops[i].Outlet_Add.City = "D";
        else
            Shops[i].Outlet_Add.City = "E";

        Shops[i].Outlet_Add.Location = num[i%10];
        Shops[i].Menu[0].flavorID=1;
        Shops[i].Menu[0].Price[0]=30;
        Shops[i].Menu[0].Price[1]=120;
        Shops[i].Menu[1].flavorID=2;
        Shops[i].Menu[1].Price[0]=40;
        Shops[i].Menu[1].Price[1]=130;
        Shops[i].Menu[2].flavorID=3;
        Shops[i].Menu[2].Price[0]=40;
        Shops[i].Menu[2].Price[1]=130;
        Shops[i].Menu[3].flavorID=4;
        Shops[i].Menu[3].Price[0]=25;
        Shops[i].Menu[3].Price[1]=110;

        Customer0(Shops[i].Total);
        //Shops[i].Tcus = 30;
        //Shops[i].Total = new Customer[Shops[i].Tcus];
    }
}

void purchase0(ICEOutlet &Shops)
{
    int Quantity = rand()%2;
    int Cus = rand()%Shops.Tcus;
    bool Disc;
    Disc = false;
    int i;
    while(i<10)
    {
        i++;
        if(Shops.Total[Cus].custID==Shops.TopCus[i].custID)
        {
            if(Quantity==1)
            {
                Disc = true;
                Shops.Total[Cus].purchase = Shops.Total[Cus].purchase + (Shops.Menu[rand()%4].Price[Quantity] - ((5/100)*(Shops.Menu[rand()%4].Price[Quantity])));
            }
            else
                continue;
        }
    }
    if(Disc==false)
    {
        Shops.Total[Cus].purchase = Shops.Total[Cus].purchase + Shops.Menu[rand()%4].Price[Quantity];
    }
}
int main()
{
    //Address place;
    //Customer cust[1000];
    int x=1, Ncus=0;

    Flavor Menu[4];

    Menu[0].flavorID=1;
    Menu[0].Price[0]=30;
    Menu[0].Price[1]=120;
    Menu[1].flavorID=2;
    Menu[1].Price[0]=40;
    Menu[1].Price[1]=130;
    Menu[2].flavorID=3;
    Menu[2].Price[0]=40;
    Menu[2].Price[1]=130;
    Menu[3].flavorID=4;
    Menu[3].Price[0]=25;
    Menu[3].Price[1]=110;

    Outlet0(Shops);

    int v, city, Outlet;

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<7; j++)
        {
            while(x!=0)
            {
                /*cout<<"--------------------------------------------\n                   ICE\n--------------------------------------------\n";
                cout<<" Select City: \n  1.A\n  2.B\n  3.C\n  4.D\n  5.E\n\n--------------------------------------------\n";
                cin>>city;

                cout<<"--------------------------------------------\n Select Shop: \n 0 1 2 3 4 5 6 7 8 9 \n--------------------------------------------\n";
                cin>>Outlet;

                v=((city-1)*10)+Outlet;

                cout<<"Enter Customer Name: "<<endl;
                cin>>Shops[v].Total[Shops[v].Tcus].name;
                cout<<"Enter Age: "<<endl;
                cin>>Shops[v].Total[Shops[v].Tcus].age;
                cout<<"Customer ID: "<<endl;
                cin>>Shops[v].Total[Shops[v].Tcus].custID;
                cout<<"Enter Purchase: "<<endl;
                cin>>Shops[v].Total[Shops[v].Tcus].purchase;
                (Shops[v].Tcus)++;*/

                cout<<"--------------------------------------------\n                   ICE\n--------------------------------------------\n";
                cout<<"How many customer should be simulated?\n";
                cin>>x;
                cout<<"--------------------------------------------\n";


                for(int i=0; i<x; i++)
                {
                    purchase0(Shops[rand()%50]);
                }

                //cin.ignore(256,'\n');
                //cin.clear();


                cout<<"More Customer? Press '0' for NO! "<<endl;
                cin>>x;
            }
        }
        WeeklyPurchase();
    }

    cout<<endl<<endl;
    TopCustomers();
    cout<<endl<<endl;
    AgeAnalysis();
    cout<<endl<<endl;
    Revenue();


    for(int i=0;i<50;i++)
    {
        for(int j=0;j<30;j++)
        {
                delete [] Shops[i].Total[j].perweek;
        }
        delete [] Shops[i].Total;
    }

    return 0;
}
