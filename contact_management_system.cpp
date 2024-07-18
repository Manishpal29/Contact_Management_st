#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

//global declaration ;
string fname, lname, phone_num;

void addcontact();
void searchcontact();
void help();
void exit();
bool check_digits(string);
bool check_number(string);


int main()
{
	int choice;
	cout<<"\n\n\t\t\t Contact Management"<<endl;
	cout<<"\n\n\t\t 1.Create Contact \n\t\t 2.Search Contact \n\t\t 3.Help \n\t\t 4.Exit"<<endl;
	cout<<"\n\n\tEnter Your Choice=";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
				addcontact();
				break;		
		case 2:
				searchcontact();
				break;
						
		case 3:
				help();
				break;
		case 4:
				exit();
				break;
		default :
					cout<<"Invalid Input"<<endl;
					cout<<"Please Enter Valid Number... !"<<endl;
					break;
			
	}
}

void addcontact()
{
	ofstream  phone("number.txt",ios::app);
	system("cls");
	cout<<"\nEnter Your First Name=";
	cin>>fname;
	cout<<"\nEnter Your Last Name=";
	cin>>lname;
	cout<<"\nEnter Your Phone Number=";
	cin>>phone_num;
	
	if(check_digits(phone_num)==true)
	{
		if(check_number(phone_num)==true)
		{
			if(phone.is_open())
			{
				phone << fname <<" " << lname <<" " <<phone_num <<endl;
				cout<<"\n\t Contact Saved Successful !" ;
			}
			else
			{
				cout<<"\n\n\t Earror Opening File !";
			}
		}
			else
		{
		
			cout<<"\n\t\tPlease Enter Only Number...!"<<endl;
		}
	
	}
	else
	{
		cout<<"\n\n\t\t A Phone Number Must Contain 10 Digits";
	}
	phone.close();
}
void searchcontact()
{
	bool found = false;
	ifstream myfile("number.txt");
	string keyword;
	cout<<"\n\t Enter Name To Search= ";
	cin>>keyword;
	while(myfile >> fname >> lname >> phone_num )
	{
		if(keyword == fname || keyword == lname)
		{
			system("cls");
			cout<<"\n\n\t\t Contact Details...";
			cout<<"\n\n\t\tFirst Name= "<<fname;
			cout<<"\n\n\t\tLast Name= "<<lname ;
			cout<<"\n\n\t\tPhone Number="<<phone_num;
			found = true;
			break;
			
		}
		if(found == false)
		{
			cout<<"\n\tNo Such Contact Found";
		}
	}
}
bool check_digits(string ph_no)
{
	if(ph_no.length() == 10)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool check_number(string ph_no)
{
	bool check=true ;
	
	for(int i = 0; i < ph_no.length(); i++)
	{
		if(!(int(ph_no[i]) >= 48 && int(ph_no[i]) <= 57))
		{
			check = false;
			break;
		}	
	}
	
	if(check == true)
	{
		return true;
	}
	if(check == false)
	{
		return false;
	}
	
}
void help()
{
	cout<<"\nThis is Help Section"<<endl;
}
void exit()
{
	system("cls");
	cout<<"\n\n\n\t\t\t Thank You For Using......!"<<endl;
	exit(1);
}

