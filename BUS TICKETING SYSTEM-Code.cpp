#include<iostream>
#include<string.h>
#include<cstdlib>
#include<fstream>
using namespace std;


struct ticket 
{
char dest[10];
char period[6][20]={"6am","8AM","10AM","12PM","8PM","10PM"};
int available[6][6]={{40,40,40,40,40,40},
					 {40,40,40,40,40,40},
					 {40,40,40,40,40,40},
					 {40,40,40,40,40,40},
					 {40,40,40,40,40,40},
					 {40,40,40,40,40,40}};
char reset,next;
int quan;
int seat[6][6]={{0,0,0,0,0,0},
				{0,0,0,0,0,0},
				{0,0,0,0,0,0},
				{0,0,0,0,0,0},
				{0,0,0,0,0,0},
				{0,0,0,0,0,0}};
float price=0;	};

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

//display
void Statement()
{	
	cout << " \n ***********************[TICKET PURCHASES SYSTEM]*******************";
	cout << " \n *                                                                 *";
	cout << " \n * Select your destination :                               Price:  *\n";
	cout << " \n * 1.Temerloh                                             RM 9.60  *";
	cout << " \n * 2.Kuantan                                              RM 19.90 *";
	cout << " \n * 3.Kuala Lumpur                                         RM 15.60 *";
	cout << " \n * 4.Ipoh                                                 RM 45.60 *";
	cout << " \n * 5.Pasir Puteh                                          RM 30.00 *";
	cout << " \n * 6.Kota Bharu                                           RM 46.60 *\n";
	cout << " \n *                          Time Depart:                           *\n";	
	cout <<	" \n * 1...6.00AM               2...8.00AM              3...10.00AM    *";
	cout << " \n * 4...12.00PM              5...8.00PM              6...10.00PM    *";
	cout << " \n *******************************************************************";	}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

//input data
int no(ticket bus[],int &iD,int &time)
{	
	cout<<"\nEnter number of destination	: ";
	cin>>iD;
	cout<<"\nEnter time			: ";
	cin>>time;
	
	time = time - 1;		
	
	cout<<"\nRemain ticket: "<<	bus[iD].available[iD][time];
	
	cout<<"\nEnter quantity of ticket: ";
				cin>>bus[iD].quan;	          	      		
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

//check available ticket	
 void check(ticket bus[],int iD,int time)
{
		if (iD==1)
		{
			strcpy(bus[iD].dest,"Temerloh");
			bus[iD].price= 9.60 *bus[iD].quan;
			bus[iD].available[iD][time]=bus[iD].available[iD][time]-bus[iD].quan;
			bus[iD].seat[iD][time]=bus[iD].seat[iD][time]+bus[iD].quan;
		}
		else if(iD==2)
		{
			strcpy(bus[iD].dest,"Kuantan");
				bus[iD].price=19.90 *bus[iD].quan;
			bus[iD].available[iD][time]=bus[iD].available[iD][time]-bus[iD].quan;
		bus[iD].seat[iD][time]=bus[iD].seat[iD][time]+bus[iD].quan;
		}
		else if(iD==3)
		{
			strcpy(bus[iD].dest,"Kuala Lumpur");
				bus[iD].price=15.60 *bus[iD].quan;
			bus[iD].available[iD][time]=bus[iD].available[iD][time]-bus[iD].quan;
			bus[iD].seat[iD][time]=bus[iD].seat[iD][time]+bus[iD].quan;
			}
		else if(iD==4)
		{
			strcpy(bus[iD].dest,"Ipoh");
				bus[iD].price=45.60*bus[iD].quan;
			bus[iD].available[iD][time]=bus[iD].available[iD][time]-bus[iD].quan;
		bus[iD].seat[iD][time]=bus[iD].seat[iD][time]+bus[iD].quan;
		}
		else if(iD==5)
		{
			strcpy(bus[iD].dest,"Pasir Puteh");
				bus[iD].price=30.00 *bus[iD].quan;
			bus[iD].available[iD][time]=bus[iD].available[iD][time]-bus[iD].quan;
			bus[iD].seat[iD][time]=bus[iD].seat[iD][time]+bus[iD].quan;
		}
		else
		{
		strcpy(bus[iD].dest,"Kota Bharu");
		bus[iD].price=46.60 *bus[iD].quan;
		bus[iD].available[iD][time]=bus[iD].available[iD][time]-bus[iD].quan;
		bus[iD].seat[iD][time]=bus[iD].seat[iD][time]+bus[iD].quan;
			}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

//checkout
void display (ticket bus[],int iD,int time)
{
	cout << "\n Your Destination 	: "<<bus[iD].dest;
	cout << "\n Time			: "<<bus[iD].period[time];
	cout << "\n Ticket Quantity 	: "<<bus[iD].quan;    
	cout << "\n Total Ticket Price	: RM "<<bus[iD].price;	
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int main()
{
	ticket bus[6];
	char select;
	int iD,time;
	ofstream outfile;
	
    cout<<"\nStart new session(ENTER N): ";
    cin>>select;
 	system("CLS");

	while(toupper(select) !='Y')
	{
		while (toupper(select) =='N')
		{
	    	Statement();
	    	no(bus,iD,time);
			check(bus,iD,time);	
			display (bus,iD,time);
			
		   	cout<<"\nConfirm?(Y/N): ";
			cin>>select;
	
			if(toupper(select)=='N')
			{
				bus[iD].available[iD][time]=bus[iD].available[iD][time]+bus[iD].quan;
					bus[iD].seat[iD][time]=bus[iD].seat[iD][time]-bus[iD].quan;
			}
 
	 		else if(toupper(select) != 'Y' && toupper(select) !='N')
   		 	{
   		 		cout<<"\n !invalid!";
	       		cout<<"\nConfirm?(Y/N): ";
	  			cin>>select;
   		 	}
   		 	system("CLS");
    	}

		system("CLS");
	
		cout << "\n Your Destination 	: "<<bus[iD].dest;
		cout << "\n Time			: "<<bus[iD].period[time];
		cout << "\n Ticket Quantity 	: "<<bus[iD].quan;    
		cout << "\n Total Ticket Price	: RM "<<bus[iD].price;
		
		//generate ticket
		bus[iD].price = bus[iD].price / bus[iD].quan;
		outfile.open("Ticket.txt",ios::app);
		for(int i=0; i<bus[iD].quan;i++)
		{			bus[iD].seat[iD][time]=i+1;

			outfile<<"______________________";
			outfile<<"\n       TICKET"<<endl;
			outfile<<"\nDestination : "<<bus[iD].dest;
			outfile<<"\nDepart time : "<<bus[iD].period[time];
			outfile<<"\nSeat 		: "<<bus[iD].seat[iD][time];
			outfile<<"\nPrice : "<<bus[iD].price<<endl;
		
		}
		outfile.close();

		cout<<"\nStart new session(ENTER N): ";
    	cin>>select;
		system("CLS");
		
		while(toupper(select) !='N')
		{
			cout<<"\nIvalid!!!!";
			cout<<"\nStart new session(ENTER N): ";
    		cin>>select;
    		system("CLS");
		}

	}

cin.get();
cin.get();

}
