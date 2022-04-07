#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
#include<ctype.h>
#include<dos.h>
#include <windows.h>    //  header file for gotoxy
#include <iostream> //header file for standard input output

#define dsize 5
#define isize 5

using namespace std;

COORD coord= {0,0}; // this is global variable
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

#include <stdlib.h>
void clrscr()
{
   system("cls");
}

#include<time.h>
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

#include <cstdio>

//-------------------------------------------------------------------------------------------------------//

int avlflight[ 5 ] = { 19, 24, 31, 47, 53 };
char dflight[ dsize ][ 20 ] = { "DELHI", "MUMBAI", "CHENNAI", "KOLKATA", "ASSAM" };
char iflight[ isize ][ 20 ] = { "ITALY", "DUBAI", "AMERICA", "CANADA", "SWEDEN" };

class DRAW   {
	       public:
	       void LINE_HOR(int, int, int, char);
	       void LINE_VER(int, int, int, char);
	       void BOX(int, int, int, int, char);

	       };
void DRAW :: LINE_HOR(int column1, int column2, int row,  char c)
{
	  for(int col= column1; col <= column2; col++)
	  {
		    gotoxy(col, row);
		    cout<<c;
	  }
}
void DRAW :: LINE_VER(int row1, int row2, int column, char c)
{
	for(int r = row1; r<=row2; r++)
	{
	     gotoxy(column, r);
	     cout<<c;
	}
}
void DRAW :: BOX (int column1, int row1,int column2, int row2, char c)
{
	char ch = 218;
	char c1, c2, c3, c4;
	char f=196, g=179;
	if (c == ch)
	{
		c1=218;
		c2=191;
		c3=192;
		c4=217;
		f=196;
		g=179;
	}
	else
	{
	       c1=c;
	       c2=c;
	       c3=c;
	       c4=c;
	       f=c;
	       g=c;
	 }
	 gotoxy(column1, row1);
	 cout<<c1;
	 gotoxy(column2, row1);
	 cout<<c2;
	 gotoxy(column1, row2);
	 cout<<c3;
	 gotoxy(column2, row2);
	 cout<<c4;
	 column1++;
	 column2--;
	 LINE_HOR(column1,column2,row1,f);
	 LINE_HOR(column1,column2,row2,f);
	 column1--;
	 column2++;
	 row1++;
	 row2--;
	 LINE_VER(row1,row2,column1,g);
	 LINE_VER(row1,row2,column2,g);
}



class address{
		protected:
			int hno;
			char city[10];
			long pincode;
		public:
			void getaddr()
			{
				cout<< "\n\n\t\t Enter House / Flat Number : ";
				cin>>hno;
				cout<<"\n\t\t Enter City : ";
				gets(city);
				cout<<"\n\t\t Enter Your Pincode : ";
				cin>>pincode;
			}

			void showaddr()
			{
				cout<<"House No. "<<hno<<", "<<city<<" "<<pincode;
			}
	     };

class dates{    //check after full
		protected:
		int dd, mm, yy;
		public:
		void getdate()
		{
			cin>>dd>>mm>>yy;
		}
		void showdate();
	   };

void dates :: showdate()
{
	char month[10];
	switch(mm)
	{
		case 1: strcpy(month,"January");
			break;
		case 2: strcpy(month,"February");
			break;
		case 3: strcpy(month,"March");
			break;
		case 4: strcpy(month,"April");
			break;
		case 5: strcpy(month,"May");
			break;
		case 6: strcpy(month,"June");
			break;
		case 7: strcpy(month,"July");
			break;
		case 8: strcpy(month,"August");
			break;
		case 9: strcpy(month,"September");
			break;
		case 10: strcpy(month,"October");
			 break;
		case 11: strcpy(month,"November");
			 break;
		case 12: strcpy(month,"December");
			 break;
	}
	cout<<month<<" "<<dd<<" , "<<yy;
}

class flight{
		protected:
		char loc[20];
		char dest[20];
		long dis;
		public:
		int h,m; //Flight Duration

		char* retloc()
		{
			return(loc);
		}
		char* retdest()
		{
			return(dest);
		}
		long retdis()
		{
			return(dis);
		}
		void addis();
		void addis1();
		void showdis();
		void showdis1();
	    };

void flight::addis() //Add Distance
{
	clrscr();
	fstream file;
	file.open("places.dat",ios::app|ios::binary);
	cout << "\n\t International : ";
	for(int i = 0;i < 5;i++)
	{
		for(int j = 0;j < 5;j++)
		{
			strcpy(loc,dflight[i]);
			strcpy(dest,iflight[j]);
			cout<<"\nEnter Distance between "<<loc<<" and "<< dest <<" : ";
			cin>>dis;
			cout<<"\n Enter Flight Time : ";
			cin>>h>>m;
			cout<<endl;
			file.write((char*)this,sizeof(flight));
		}
	}
	file.close();
	getch();
}

void flight::addis1() //Add Distance
{
	clrscr();
	fstream file;
	file.open("places.dat",ios::app|ios::binary);
	cout << "\n\t Domestic : ";

	for(int i = 0;i < 5;i++)
	{
		for(int j = 0;j < 5;j++)
		{
			if(strcmpi(dflight[i],dflight[j])==0)
				j++;
			strcpy(loc,dflight[i]);
			strcpy(dest,dflight[j]);
			cout<<"\nEnter Distance between "<<loc<<" and "<< dest <<" : ";
			cin>>dis;
			cout<<"\n Enter Flight Time : ";
			cin>>h>>m;
			cout<<endl;
			file.write((char*)this,sizeof(flight));
		}
	}
	file.close();
	getch();
}

void flight::showdis()
{
	clrscr();
	int i;
	fstream file;
	file.open("places.dat",ios::in|ios::binary);
	int rec = 0;
	cout<<"\n\t\t\tInternational and Domestic  \n";
	cout<<"\t";
	for(int i = 0; i < 56; i++ )
		cout<<"-";
	cout<<endl<<"\t| Location   |  Destination  |   Distance  |    Time   |\n\t";

	for(int i = 0; i < 56; i++ )
		cout<<"-";
	cout<<endl<<"\t";

	while(file.read((char*)this,sizeof(flight)))
	{
		if( rec == 20 )
		{
			for( i = 0; i < 56; i++ )
				cout << "-";
			getch();
			clrscr();
		}
		cout << "|" <<setw( 11 ) << loc << " |" << setw( 14 ) << dest << " |"
		<< setw( 9 ) << dis << " km |" << setw( 4 ) << h << "H " << m << "M+ |"
		<< endl << "\t";
		rec++;
	}
	for( i = 0; i < 56; i++ )
		cout << "-";
	file.close();
	getch();
}

class seats{
		public:
		int noflight;
		int bseats;
		int eseats;
		seats()
		{
			bseats = 20;
			eseats = 30;
		}
		void modifyseats( int, char, char);
		void showseats();
		int checkseats( int, char );
};

void writeseats()
{
	fstream file;
	file.open( "seats.dat", ios::out | ios::binary );
	seats s;

	for( int i = 0; i < 5; i++ )
	{
		s.noflight = avlflight[ i ];
		file.write( ( char* )&s, sizeof( s ) );
	}
	file.close();
}

void seats::modifyseats( int f, char c, char a )
{
	// f= flight no., c = class( b/e ), a = kind of operation( i/d)

	fstream file;
	file.open( "seats.dat", ios::in | ios::out | ios::binary);
	while( file.read( (char*)this, sizeof(seats) ) )
	{
		if( noflight == f)
		{
			if( c == 'b' )
				if( a == 'i' )
					bseats++;
				else
					bseats--;

			else
				if( a == 'i' )
					eseats++;
				else
					eseats--;

			int s = sizeof(seats);
			file.seekg(-s,ios::cur);
			file.write((char*)this,sizeof(seats));
			break;
		}
	}
}

void seats::showseats()
{
	fstream file;
	clrscr();
	int i;

	//writeseats();
	file.open("seats.dat",ios::in|ios::binary);
	cout<<"\n\t\t";
	for(int i = 0; i < 34; i++ )
		cout << '-';
	cout<<"\n\t\t| Flight No. |   Available Seats |\n\t\t";
	for(i = 0; i < 34; i++ )
		cout << '-';
	cout<<"\n\t\t|            | Business | Economy|\n\t\t";
	for(i=0;i<34;i++)
		cout << '-';
	while( file.read( (char*)this, sizeof(seats) ) )
	{
		cout << "\n\t\t|   " << noflight << "       |  " << bseats << "      |  " << eseats << "    |\n\t\t";
		for( i = 0; i < 34; i++ )
			cout << '-';
	}
	file.close();
	getch();
}

int seats::checkseats(int f,char c)
{
	fstream file;
	file.open("seats.dat",ios::in|ios::binary);
	int s;
	while(file.read((char*)this,sizeof(seats)))
	{
		if(noflight==f)
		{
			if(c=='b')
					s=bseats;
				else
					s=eseats;
				break;
		}
	}
	file.close();
	return(s);
}

class fbooking : private address, private dates, public flight
{
	protected:

	int resno;
	char fname[ 20 ], lname[ 20 ];
	char gender;
	int age;
	char phone[ 11 ];
	char email[ 30 ];
	char location[ 20 ], destination[ 20 ];
	unsigned int distance;
	int flightno;
	char airline[ 25 ];
	char fclass[ 15 ];
	char ftype[ 15];
	char fstatus[ 15 ];
	unsigned long price;
	public:
		fbooking()
		{
			resno = 10;
		}
		int allotres();
		void calprice();
		void getf( char[] );
		void getpasinfo();
		void modifyinfo(int);
		void showf();
		void writefile();
		void canceltic();
		void showtic();
		int retres()
		{
			return( resno );
		}
};

int fbooking::allotres()
{
	fstream file;
	fbooking f;
	file.open( "myflight.dat", ios::in | ios::binary );
	int r;
	while( file.read( (char*)&f, sizeof(f) ) )
		r = f.retres();
	file.close();
	if( r <=0 )
		return( 10 );
	else
		return( ++r );
}

void fbooking::calprice()
{
	flight f;
	fstream file;
	int rate;
	file.open( "places.dat", ios::in | ios::binary );
	if( strcmpi( ftype, "DOMESTIC" ) == 0 )
	{
		if( strcmpi( airline, "JET AIRWAYS" ) == 0 )
        {
            if( strcmpi( fclass, "BUSINESS" ) == 0 )
				rate = 13;
			else
				rate = 8;
        }
		else if( strcmpi( airline, "AIR INDIA" ) == 0 )
        {
            if( strcmpi( fclass, "BUSINESS" ) == 0 )
				rate = 8;
			else
				rate = 5;

        }
		else if( strcmpi( airline, "EMIRATES" ) == 0 )
        {
            if( strcmpi( fclass, "BUSINESS" ) == 0 )
				rate = 11;
			else
				rate = 6;
        }
		else if( strcmpi( airline, "LUFTHANSA" ) == 0 )
        {
            if( strcmpi( fclass, "BUSINESS" ) == 0 )
				rate = 10;
			else
				rate = 7;
        }
		else if( strcmpi( airline, "SPICEJET" ) == 0 )
        {
            if( strcmpi( fclass, "BUSINESS" ) == 0 )
				rate = 12;
			else
				rate = 8;
        }

	}
	if( strcmpi( ftype, "INTERNATIONAL" ) == 0 )
	{
		if( strcmpi( airline, "JET AIRWAYS" ) == 0 )
        {
            if( strcmpi( fclass, "BUSINESS" ) == 0 )
				rate = 8;
			else
				rate = 5;
        }
        else if( strcmpi( airline, "AIR INDIA" ) == 0 )
        {
            if( strcmpi( fclass, "BUSINESS" ) == 0 )
				rate = 6;
			else
				rate = 2;
        }
		else if( strcmpi( airline, "EMIRATES" ) == 0 )
        {
            if( strcmpi( fclass, "BUSINESS" ) == 0 )
				rate = 7;
			else
				rate = 6;
        }
		else if( strcmpi( airline, "LUFTHANSA" ) == 0 )
        {
            if( strcmpi( fclass, "BUSINESS" ) == 0 )
				rate = 8;
			else
				rate = 4;
        }
		else if( strcmpi( airline, "SPICEJET" ) == 0 )
        {
            if( strcmpi( fclass, "BUSINESS" ) == 0 )
				rate = 9;
			else
				rate = 3;
        }
	}
	while( file.read( (char*)&f, sizeof(flight) ) )
	{
		if( strcmpi(f.retloc(), location) == 0 && strcmpi(f.retdest(), destination) == 0 )
		{
			dis = f.retdis();
			price = rate *f.retdis();
			h = f.h;
			m = f.m;
			break;
		}
	}
	file.close();
}



void fbooking::getf(char a[15])
{
	clrscr();
	flight f;
	fstream file;
	//calprice();
	resno=allotres();
	strcpy(ftype,a);

    int i;
	cout<<"\n\n\tReservation Number : "<<resno;
	//delay(1500);

	//Take Location
	int found=0;    int e;
	do
	{
		gotoxy(9,9);
		cout<<"Enter 0 to exit";
		gotoxy(9,5);
		cout<<"Available locations are Delhi,Mumbai,Chennai,Kolkata,Assam";
		gotoxy(9,7);
		cout<<"Please Enter your location : ";

		/*  The below fgets function is used to avoid buffer overflow,
            a buffer overflow, or buffer overrun, is an anomaly where a program, while writing data to a buffer,
            overruns the buffer's boundary and overwrites adjacent memory locations.
            Buffers are areas of memory set aside to hold data, often while moving it from one section of a program to another,
            or between programs. Buffer overflows can often be triggered by malformed inputs;
            if one assumes all inputs will be smaller than a certain size and the buffer is created to be that size,
            then an anomalous transaction that produces more data could cause it to write past the end of the buffer.
            If this overwrites adjacent data or executable code, this may result in erratic program behavior,
            including memory access errors, incorrect results, and crashes.
        */

		fgets(location, sizeof location, stdin);

		/*  Using fgets, the newline may be retained in the string -- it then becomes part of the comparison.
            As we do not want the newline at the end of the string, as it will skip the location part when we run the program,
            therefore the below code will remove it.
		*/

		if(fgets(location, sizeof location, stdin))
        {
           size_t end = strlen(location) - 1; /* find position of last character */
           if(location[end] == '\n') /* see if it is a newline */
           {
             location[end] = '\0'; /* get rid of the newline */
           }
        }

		if(location[0]=='0')
			return;
		for(int i=0;i<20;i++)
			location[i]=toupper(location[i]);

		for(i=0;i<5;i++)
			if(strcmpi(location,dflight[i])==0)
				found=1;

		if (found==0)
		{
			clrscr();
			cout<<"\n\n\tSorry,There is no flight available from "<<location<<" at this moment";
			cout<<"\n\n\tPlease enter the location from the following : \n";
			for(i=0;i<5;i++)
				cout<<"\t"<<i+1<<"."<<dflight[i]<<endl;
			getch();
			return;
		}
	}while(found==0);

	//Take destination
	int opt;
	do
	{
	found=1;
		do
		{
			clrscr();
			cout<<"\n\n\tChoose your destination : \n\n";
			for(int i=0;i<5;i++)
				if(strcmpi(ftype,"Domestic")==0)
					cout<<"\tPress "<<i+1<<" : "<<dflight[i]<<endl;
				else
					cout<<"\tPress "<<i+1<<" : "<<iflight[i]<<endl;
			cout<<"\n\n\tYour choice : ";
			cin>>opt;
		}while(opt>5||opt<1);

		if(strcmpi(ftype,"Domestic")==0)
		{
			strcpy(destination,dflight[opt-1]);
			if(strcmpi(location,destination)==0)
			{
				clrscr();
				cout<<"\n\n\tYour location and destination cannot be same";
				getch();
				found=0;
			}
		}
		else
			strcpy(destination,iflight[opt-1]);
	}while(found==0);

	do
	{
		clrscr();
		DRAW d;
		d.BOX(14,3,69,19,218);
		d.LINE_HOR(16,67,5,'*');
		gotoxy(21,4);
		cout<<"PLEASE CHOOSE AN ARLINE FROM THE FOLLOWING";
		gotoxy(19,6);
		cout<<"Press 1 : TO TRAVEL THROUGH JET AIRWAYS";
		gotoxy(19,8);
		cout<<"Press 2 : TO TRAVEL THROUGH AIR INDIA";
		gotoxy(19,10);
		cout<<"Press 3 : TO TRAVEL THROUGH EMIRATES";
		gotoxy(19,12);
		cout<<"Press 4 : TO TRAVEL THROUGH LUFTHANSA";
		gotoxy(19,14);
		cout<<"Press 5 : TO TRAVEL THROUGH SPICEJET";
		gotoxy(19,16);
		cout<<"Press 6 : TO GO TO MAIN MENU";
		gotoxy(19,18);
		cout<<"Your choice : ";
		cin>>opt;
	}while(opt>6||opt<1);
	switch(opt)
	{
		case 1: strcpy(airline,"JET AIRWAYS");
			break;
		case 2: strcpy(airline,"AIR INDIA");
			break;
		case 3: strcpy(airline,"EMIRATES");
			break;
		case 4: strcpy(airline,"LUFTHANSA");
			break;
		case 5: strcpy(airline,"SPICEJET");
			break;
		case 6: return;
	}
	do
	{
		clrscr();
		cout<<"\n\n\n\tChose a preferable class to travel";
		cout<<"\n\n\tPress 1 : To Travel from Economy class"
		    <<"\n\n\tPress 2 : To Travel from Business class"
		    <<endl<<"\n\n\n\t Your choice : ";
		cin>>opt;
	}while(opt<1||opt>2);

	switch(opt)
	{
		case 1: strcpy(fclass,"ECONOMY");
			break;
		case 2: strcpy(fclass,"BUSINESS");
			break;
	}

	for(int i=0;i<5;i++)
		if(strcmpi(location,dflight[i])==0)
			flightno=avlflight[i];

	char ch;
	if(strcmpi(fclass,"ECONOMY")==0)
		ch='e';
	else
		ch='b';
	seats s;

	if(s.checkseats(flightno,ch)==0)
	{
		clrscr();
		cout<<"\n\n\tAll"<<fclass<<"CLASS seats from"<<location<<"are full!!!";
		cout<<"\n\n\tPlease try booking from another class";
		cout<<"\n\n\tInconvenience is highly regreted";
		getch();
		return;
	}
	else
		getpasinfo();
	clrscr();
	cout<<"\n\n\tPlease wait while we process your request..";
	calprice();
	//delay(2500);

	clrscr();
	char choi;
	DRAW d;
	d.BOX(8,2,74,24,218);
	gotoxy(16,4);
	cout<<"Thank you for traveling with "<<airline;
	gotoxy(13,6);
	cout<<"Reservation Number is "<<resno;
	gotoxy(13,8);
	cout<<"Your flight Number is "<<flightno;
	gotoxy(13,10);
	cout<<"Flight duration : "<<h<<"hr & "<<m<<"min";
	gotoxy(13,12);
	cout<<"Distance : "<<dis<<" Kms";
	gotoxy(13,14);
	cout<<"Baggage allowance is 40 kg";
	gotoxy(13,16);
	cout<<"Boarding starts at 7 A.M ";
	gotoxy(13,18);
	cout<<"Please prove your Identity at the time of Boarding ";
	gotoxy(13,20);
	cout<<"TICKET PRICE : Rs "<<price;
	gotoxy(13,22);
	cout<<"Press Y to confirm your ticket : ";
	fflush(stdin);
	cin>>choi;
	choi=toupper(choi);
    if (choi=='Y')
	{
		strcpy(fstatus,"CONFIRMED");
		s.modifyseats(flightno,ch,'d'); //Here d means increse
		clrscr();
		gotoxy(31,11);
		cout<<"Ticket confirmed";
		getch();
	}
	else
	{
		strcpy(fstatus,"NOT CONFIRMED");
		clrscr();
		gotoxy(31,11);
		cout<<"TICKET NOT CONFIRMED";
		getch();
	}

    writefile();
}

void fbooking::getpasinfo()
{
	int i;
	clrscr();
	DRAW d;
	d.BOX(8,2,74,24,218);
	gotoxy(14,3);
	cout<<"Enter the following information of the passenger";
	gotoxy(13,5);
	cout<<"First Name : ";
	gotoxy(13,7);
	cout<<"Last Name : ";
	gotoxy(13,9);
	cout<<"Gender (M/F) : ";
	gotoxy(13,11);
	cout<<"Age : ";
	gotoxy(13,13);
	cout<<"House/Flat Number : ";
	gotoxy(13,15);
	cout<<"City : ";
	gotoxy(13,17);
	cout<<"Pincode : ";
	gotoxy(13,19);
	cout<<"Date for departure(dd mm yyyy) : ";
	gotoxy(13,21);
	cout<<"Email Address : ";
	gotoxy(13,23);
	cout<<"Contact Number : ";

    fflush(stdin);
	gotoxy(26,5);
	gets(fname);
		for(int i=0;i<20;i++)
			fname[i]=toupper(fname[i]);
	fflush(stdin);
	gotoxy(25,7);
	gets(lname);
		for(i=0;i<20;i++)
			lname[i]=toupper(lname[i]);
	 fflush(stdin);
	 gotoxy(28,9);
	 cin>>gender;
	 gender=toupper(gender);
	 gotoxy(19,11);
	 cin>>age;
	 gotoxy(33,13);
	 cin>>hno;
	 fflush(stdin);
	 gotoxy(20,15);
	 gets(city);
	 gotoxy(23,17);
	 cin>>pincode;
	 gotoxy(46,19);
	 getdate();
	 fflush(stdin);
	 gotoxy(29,21);
	 gets(email);
	 fflush(stdin);
	 gotoxy(30,23);
	 gets(phone);

}

void fbooking::modifyinfo(int res)
{
	clrscr();
	fstream file;
	file.open("myflight.dat",ios::in|ios::out|ios::binary);
	int found=0;
	while(file.read((char*)this,sizeof(fbooking)))
	{
		if(resno==res)
		{
			found=1;
			if(strcmpi(fstatus,"CONFIRMED")==0)
			{
				getpasinfo();
				int b=sizeof(fbooking);
				file.seekg(-b,ios::cur);
				file.write((char*)this,sizeof(fbooking));
			}
			else
				cout<<"\n\n\tYour ticket is not CONFIRMED ";
			break;
		}
	}
	file.close();

	if(found==0)
	{
		cout<<"\n\n\n\tInvalid Resesrvatioon number!!!";
		return;
	}

	//Do the same for conflights.dat

	file.open("conflights.dat",ios::in|ios::out|ios::binary);
	while(file.read((char*)this,sizeof(fbooking)))
	{
		if(resno==res)
		{
			int b=sizeof(fbooking);
			file.seekg(-b,ios::cur);
			file.write((char*)this,sizeof(fbooking));
		}
	}
	file.close();
}

void fbooking::showf()
{
	clrscr();
	DRAW d;
	d.BOX(1,1,79,19,218);
	d.LINE_HOR(2,78,3,196);
	d.LINE_VER(4,18,44,179);
	gotoxy(27,2);
	cout<<"RESERVATION NUMBER : "<<resno;
	gotoxy(4,4);
	cout<<"Name : "<<lname<<" "<<fname;
	gotoxy(46,4);
	cout<<"Age : "<<age;
	gotoxy(4,6);
	cout<<"Gender : "<<gender;
	gotoxy(4,8);
	cout<<"Address : ";
	showaddr();
	gotoxy(4,10);
	cout<<"Phone Number : "<<phone;
	gotoxy(4,12);
	cout<<"Email : "<<email;
	gotoxy(4,14);
	cout<<"Location : "<<location;
	gotoxy(4,16);
	cout<<"Destination : "<<destination;
	gotoxy(4,18);
	cout<<"Distance : "<<dis<<" Kms";
	gotoxy(57,2);
	cout<<"STATUS : "<<fstatus;
	gotoxy(46,6);
	cout<<"Flight Type : "<<ftype;
	gotoxy(46,8);
	cout<<"Travelling in : "<<fclass<<"CLASS";
	gotoxy(46,10);
	cout<<"TICKET PRICE : Rs "<<price;
	gotoxy(46,12);
	cout<<"Flight duration : "<<h<<" hr "<<m<<" min";
	gotoxy(46,14);
	cout<<"Departure : ";
	showdate();
	gotoxy(46,16);
	cout<<"Flight number : "<<flightno;
	gotoxy(46,18);
	cout<<"Airline : "<<airline;
}

void fbooking::writefile()
{
	fstream file;
	file.open("myflight.dat",ios::app|ios::binary);
	file.write((char*)this,sizeof(fbooking));
	file.close();

	if(strcmpi(fstatus,"CONFIRMED")==0)
	{
		file.open("conflights.dat",ios::app|ios::binary);
		file.write((char*)this,sizeof(fbooking));
		file.close();
	}
}

void fbooking::canceltic()
{
	clrscr();
	fstream file1,file2;

	int tres;
	cout<<"\n\n\tEnter Your Reservation Number : ";
	cin>>tres;

	//Delete record from conflights.dat

	file1.open("conflights.dat",ios::in|ios::binary);
	file2.open("temp.dat",ios::out|ios::binary);

	if(!file1||!file2)
	{
		cout<<"ERROR";
		getch();
		return;
	}
	int found=0;
	while(file1.read((char*)this,sizeof(fbooking)))
	{
		if(tres!=retres())
			file2.write((char*)this,sizeof(fbooking));
		else
		{
			found=1;
			showf();
			char ch;
			cout<<"\n\n\n\tNOTE : ONLY 80% REFUND IS PROVIDED ON CANCELATION OF TICKET";
			cout<<"\n\n\tARE YOU SURE YOU WANT TO DELETE(Y/N) : ";
			cin>>ch;
			if(ch=='n'||ch=='N')
			{
				file2.write((char*)this,sizeof(fbooking));
				found=2;
			}
			else
			{
				clrscr();
				//Increase the no. of seats
				seats s;
				char ch;
				if(strcmpi(fclass,"Economy")==0)
					ch='e';
				else
					ch='b';
				s.modifyseats(flightno,ch,'i');

				cout<<"\n\n\tYour Ticket has been CANCELLED SUCESSFULLY."
				<<"\n\n\tRefund of Rs "<<0.80*price
				<<" has been credited to your account.";
				cout<<"\n\n\n\t(Press any key to continue)";
				getch();
			}
		}
	}
	file1.close();
	file2.close();

	remove("conflights.dat");;
	rename("temp.dat","conflights.dat");

	if(!found)
	{
		cout<<"\n\n\tNo record found...";
		getch();
		return;
	}

	//Now change status to 'Unconfirmed' from myflight.dat

	if(found==2)
		return;
	fstream file3;
	file3.open("myflight.dat",ios::in|ios::out|ios::binary);

	while(file3.read((char*)this,sizeof(fbooking)))
		if(tres==resno)
		{
			int s=sizeof(fbooking);
			strcpy(fstatus,"NOT CONFIRMED");
			file3.seekg(-s,ios::cur);
			file3.write((char*)this,sizeof(fbooking));
		}
	file3.close();
}

void fbooking::showtic()
{
	clrscr();
	fstream file;
	file.open("myflight.dat",ios::in|ios::binary);
	int res;
	cout<<"\n\n\tPlease Enter your reservation number : ";
	cin>>res;
	int found=0;
	while(file)
	{
		file.read((char*)this,sizeof(fbooking));
		if(resno==res)
		{
			found=1;
			clrscr();
			if(strcmpi(fstatus,"CONFIRMED")==0)
			{
				cout<<"\n\n\tYour ticket is CONFIRMED";
				cout<<"\n\n\tPRESS ANY KEY TO VIEW YOUR TICKET";
				getch();
				showf();
			}
			else
				cout<<"\n\n\tYour ticket is NOT CONFIRMED";
			break;
		}
	}
	if(found==0)
	{
		cout<<"\n\n\n\tInvalid reservation number!!!";
	}
	getch();
	file.close();
}

class admin:public fbooking
{
	char password[20];
	public:
	admin(char pw[20])
	{
		strcpy(password,pw);
	}
	int amenu();
	void showfile();
	void showt();
	int countrec(char*);
	int verify();
};

int admin::verify()
{
	char pw[20];
	int i=0;
	char ch;
	DRAW d;
	d.BOX(12,4,67,12,'\4');
	d.LINE_HOR(13,66,6,196);
	gotoxy(34,5);
	cout<<"VERIFICATION";
	gotoxy(14,8);
	cout<<"Enter admin password to continue : ";
	do
	{
		pw[i]=getch();
		cout<<"*";
		i++;
	}while(pw[i-1]!=13);
	pw[i-1]='\0';
	return(strcmp(password,pw));
}

void admin::showfile()
{
	fstream file;
	file.open("myflight.dat",ios::in|ios::binary);
	if(!file)
	{
		cout<<"Unable to open file";
		getch();
		return;
	}
	fbooking f;

	while(file.read((char*)&f,sizeof(f)))
	{
		f.showf();
		getch();
	}
	file.close();
}

int admin::countrec(char name[20])
{
	fstream file;
	file.open(name,ios::in|ios::binary);
	int rec=0;
	fbooking f;
	while(file.read((char*)&f,sizeof(f)))
		rec++;
	file.close();
	return(rec);
}

void admin::showt()
{
	clrscr();
	DRAW d;
	fstream file;
	file.open("myflight.dat",ios::in|ios::binary);
	if(!file)
	{
		cout<<"Unable to open file";
		getch();
		return;
	}

	d.LINE_HOR(1,79,1,'*');
	d.LINE_HOR(1,79,3,'-');
	d.LINE_VER(2,24,10,'|');
	d.LINE_VER(2,24,30,'|');
	d.LINE_VER(2,24,45,'|');
	d.LINE_VER(2,24,57,'|');
	d.LINE_VER(2,24,72,'|');


	gotoxy(2,2);
	cout<<"Res no.";
	gotoxy(19,2);
	cout<<"Name";
	gotoxy(36,2);
	cout<<"Type";
	gotoxy(49,2);
	cout<<"Class";
	gotoxy(62,2);
	cout<<"Flight";
	gotoxy(74,2);
	cout<<"Status";


	int y=4;
	int rec=0;
	while(file.read((char*)this,sizeof(fbooking)))
	{
		if(rec==10)
		{
			rec=0;
			getch();
			clrscr();
			d.LINE_HOR(1,79,1,'*');
			d.LINE_HOR(1,79,3,'-');
			d.LINE_VER(2,24,10,'|');
			d.LINE_VER(2,24,30,'|');
			d.LINE_VER(2,24,46,'|');
			d.LINE_VER(2,24,57,'|');
			d.LINE_VER(2,24,72,'|');

			gotoxy(2,2);
			cout<<"Res no.";
			gotoxy(19,2);
			cout<<"Name";
			gotoxy(34,2);
			cout<<"Type";
			gotoxy(49,2);
			cout<<"Class";
			gotoxy(62,2);
			cout<<"Flight";
			gotoxy(74,2);
			cout<<"Status"<<endl;

			for(int i=0;i<79;i++)
				cout<<"-";
			cout<<endl;
			y=4;
		}

	 gotoxy(3,y);
	 cout<<resno;
	 gotoxy(12,y);
	 cout<<lname<<" "<<fname;
	 gotoxy(32,y);
	 cout<<ftype;
	 gotoxy(48,y);
	 cout<<fclass;
	 gotoxy(64,y);
	 cout<<flightno;
	 gotoxy(74,y);
		if(strcmpi(fstatus,"CONFIRMED")==0)
			cout<<"C";
		else
			cout<<"N.C";
		gotoxy(1,y+1); //Move cursor to the next line
		for(int i=0;i<79;i++)
			cout<<"-";
		cout<<endl;
		y+=2;
		rec++;
	}
	getch();
	file.close();
}

class bug{
		char name[30];
		char email[30];
		char phone[11];
		char content[200];

		public:
		void report();
		void showbug();
	 };

void bug::report()
{
	clrscr();
	fstream file;
	file.open("bugs.txt",ios::app|ios::binary);

	gotoxy(4,18);
	cout<<"To exit enter 0 and then press enter key";
	gotoxy(4,3);
	cout<<"Enter your Name : ";
	gotoxy(4,5);
	cout<<"Enter your email ID : ";
	gotoxy(4,7);
	cout<<"Enter your contact number : ";

	fflush(stdin);
	gotoxy(22,3);
	gets(name);
		if(name[0]=='0')
			return;
	fflush(stdin);
	gotoxy(26,5);
	gets(email);
		if(email[0]=='0')
			return;
	fflush(stdin);
	gotoxy(33,7);
	gets(phone);
		if(phone[0]=='0')
			return;

	clrscr();
	cout<<"\n\n\tEnter your query/Bug : (# to stop)\n\n";
	cin.getline(content,200,'#');

	clrscr();
	cout<<"\n\tThank you "<<name<<" For reaching us."<<endl<<"\tOur developers will contact you shortly.";
	getch();

	file.write((char*)this,sizeof(bug));
	file.close();
}

void bug::showbug()
{
	clrscr();
	fstream file;
	DRAW d;
	file.open("bugs.txt",ios::in|ios::binary);
	while(file.read((char*)this,sizeof(bug)))
	{
		cout<<"\n"<<content;
		cout<<"\nName: "<<name;
		cout<<"\t Email : "<<email;
		cout<<"\t    Phone : "<<phone;
	}
	file.close();
}
void menu()
{
	DRAW d;
	//d.BOX(14,5,66,18,'*');
	d.BOX(16,7,63,15,'*');
	d.LINE_HOR(18,60,10,196);
	gotoxy(22,9);
	cout<<"WELCOME TO SPARROW AIRLINE SERVICES";
	gotoxy(27,12);
	cout<<"PRESS ANY KEW TO CONTINUE";
	getch();
}


int mainmenu()
{
	clrscr();
	DRAW d;
	int choice;
	d.BOX(8,2,74,24,218);
	d.LINE_HOR(9,73,4,196);
	gotoxy(27,3);
	cout<<"SPARROW AIRLINE SERVICE";
	gotoxy(18,6);
	cout<<"PRESS 1 : TO BOOK A DOMESTIC FLIGHT";
	gotoxy(18,8);
	cout<<"PRESS 2 : TO BOOK AN INTERNATIONAL FLIGHT";
	gotoxy(18,10);
	cout<<"PRESS 3 : TO CHECK STATUS OF YOUR TICKET";
	gotoxy(18,12);
	cout<<"PRESS 4 : TO CANCEL YOUR TICKET";
	gotoxy(18,14);
	cout<<"PRESS 5 : TO CHANGE/MODIFY PASSENGER DETAILS";
	gotoxy(18,16);
	cout<<"PRESS 6 : FOR A QUERY/REPORT A BUG";
	gotoxy(18,18);
	cout<<"PRESS 7 : FOR ADMIN ACCESS";
	gotoxy(18,20);
	cout<<"PRESS 8 : TO EXIT";
	gotoxy(18,22);
	cout<<"Enter your choice here : ";
	cin>>choice;
	return(choice);
}
int decmenu()
{
	clrscr();
	DRAW d;
	int dec;
	d.BOX(10,4,66,16,'*');
	gotoxy(13,6);
	cout<<"PRESS 1 : TO ADD DISTANCE FOR INTERNATIONAL FLIGHTS";
	gotoxy(13,8);
	cout<<"PRESS 2 : TO ADD DISTANCE FOR DOMESTIC FLIGHTS";
	gotoxy(13,10);
	cout<<"PRESS 3 : TO VIEW INFORMATION OF PLACE";
	gotoxy(13,12);
	cout<<"PRESS 4 : TO GO BACK TO ADMIN MENU";
	gotoxy(13,14);
	cout<<"Enter your choice here : ";
	cin>>dec;
	return(dec);
}

int admin::amenu()
{
	clrscr();
	int opt;
	DRAW d;
	d.BOX(8,2,74,24,218);
	d.LINE_HOR(9,73,4,196);
	gotoxy(33,3);
	cout<<"ADMIN MENU";
	gotoxy(18,6);
	cout<<"PRESS 1 : TO COUNT RECORDS";
	gotoxy(18,8);
	cout<<"PRESS 2 : TO VIEW ALL RECORDS IN TABULAR FORM";
	gotoxy(18,10);
	cout<<"PRESS 3 : TO VIEW ALL TICKETS";
	gotoxy(18,12);
	cout<<"PRESS 4 : TO VIEW AVAILABLE SEATS IN FLIGHTS";
	gotoxy(18,14);
	cout<<"PRESS 5 : TO VIEW OR ADD INFORMATION OF PLACES";
	gotoxy(18,16);
	cout<<"PRESS 6 : TO VIEW QUERIES/BUGS REPORTED BY USER";
	gotoxy(18,18);
	cout<<"PRESS 7 : TO GO BACK TO MAIN MENU";
	gotoxy(18,20);
	cout<<"PRESS 8 : TO EXIT THE PROGREAMME";
	gotoxy(18,22);
	cout<<"Enter your choice here : ";
	cin>>opt;
	return(opt);
}

int main()
{
	clrscr();
	int choice,opt,dec;
	fbooking f;
	flight c;
	menu();
	do
	{
		choice=mainmenu();

		switch(choice)
		{
			case 1: f.getf("Domestic");
				break;
			case 2: f.getf("International");
				break;
			case 3: f.showtic();
				break;
			case 4: f.canceltic();
				break;
			case 5: clrscr();
				int res;
				cout<<"\n\n\tPlease enter reservation number : ";
				cin>>res;
				f.modifyinfo(res);
				getch();
				break;
			case 6: bug b;
				b.report();
				break;
			case 7: admin a("1234");
				clrscr();
				if(a.verify()!=0)
				{	gotoxy(14,10);
					cout<<"Invalid password( Press any key to continue)";
					getch();
					break; //Incorrect password
				}
				else
				do
				{
					opt=a.amenu();
					switch(opt)
					{
						case 1: clrscr();
                                cout<<"\n\n\tNumber of records in myflight.dat/Total records : "<<a.countrec("myflight.dat");
                                cout<<"\n\n\tNumber of records in conflight.dat/Confirmed Tickets :    "<<a.countrec("conflight.dat")<<endl;
                                getch();
                                break;
						case 2: a.showt();
                                break;
						case 3: a.showfile();
                                break;
						case 4: {
                                    seats s;
                                    char l;
                                    //writeseats();
                                    s.checkseats(5,l);
                                    s.showseats();
                                    break;
                                }
						case 5: {
                                    clrscr();
                                    do
                                    {
                                        dec=decmenu();
                                        switch(dec)
                                        {
                                            case 1: c.addis();
                                                break;
                                            case 2: c.addis1();
                                                break;
                                            case 3: c.showdis();
                                                break;
                                         }//End of third switch
                                    }while(dec!=4);
                                    break;
                                }
						case 6: bug b;
                                b.showbug();
                                getch();
                                break;
						case 8: exit(0);
					}  //End of second switch
				}while(opt!=7);
				break;
		}   //End of first switch
	}while(choice!=8);
}
