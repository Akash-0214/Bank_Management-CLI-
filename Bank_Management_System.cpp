#include <iostream>
#include <string>
#include <conio.h>//getch
#include <windows.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class banking{
	int completed;
	string id;
	int cash1;
	struct customer{
		string ID, name, fname, address;
		int cash, idcard;
		long phone;
	} customer[500];
	public:
		banking(){
			completed = 0;
		}
	public:
		void option();
		void newaccount();
		void display();
		void update();
		void search();
		void transaction();
		void logout();	
};

void banking::option(){	
	while(1){
	char select;
	cout<<"\n\n\n";
	cout<<"Enter 1 for Creating New Account."<<endl;
	cout<<"Enter 2 for Displaying the Customer Information."<<endl;
	cout<<"Enter 3 for Updating Customer Information."<<endl;
	cout<<"Enter 4 for Searching the Specific Customer."<<endl;
	cout<<"Enter 5 for Transaction Operationd like Deposit and Withdraw."<<endl;
	cout<<"Enter 6 for Logout."<<endl;
	cout<<"Enter Your Choice: ";
	cin>>select;
		switch(select){
			case '1':
				system("CLS");
				banking::newaccount();
				break;
			 case '2':
			 	system("CLS");
		    	banking::display();
		    	break;
			case '3':
			 	system("CLS");
		    	banking::update();
		    	break;
			case '4':
			 	system("CLS");
		    	banking::search();
		    	break;
			case '5':
			 	system("CLS");
		    	banking::transaction();
		    	break;	
		    case '6':
			 	system("CLS");
		    	banking::logout();
		    	break;	
}
}
}
void banking::newaccount(){
	cout<<"\n\n";
	cout<<"New Account Creating."<<endl;
	cout<<"Enter the Record customer"<<endl;
	cout<<"Enter Your ID: ";
	cin>>customer[completed].ID;
	cout<<"Enter Your Name: ";
	cin>>customer[completed].name;
	cout<<"Enter Your Father Name: ";
	cin>>customer[completed].fname;
	cout<<"Enter Your Phone Number: ";
	cin>>customer[completed].phone;
	cout<<"Enter Your ID Card Number: ";
	cin>>customer[completed].idcard;
	cout<<"Enter Your Cash: ";
	cin>>customer[completed].cash;
	completed++;	
}

void banking::display(){
	for(int i = 0; i < completed; i++){
		cout<<"Record of Customer."<<endl;
		cout<<"Customer Uniue ID: "<<customer[i].ID<<endl;
		cout<<"Customer Name: "<<customer[i].name<<endl;
		cout<<"Customer Father Name: "<<customer[i].fname<<endl;
		cout<<"Customer Phone No: "<<customer[i].phone<<endl;
		cout<<"Customer ID Card Number: "<<customer[i].idcard<<endl;
		cout<<"Customer Amount: "<<customer[i].cash<<endl;
		cout<<endl;
	}
}

void banking::update(){
	cout<<"Enter the ID of customer for updating the information: ";
	cin>>id;
	for(int i = 0; i < completed; i++){
		if(id == customer[i].ID){
			cout<<"Existing Record of Customer."<<endl<<endl;
			cout<<"Customer Uniue ID: "<<customer[i].ID<<endl;
			cout<<"Customer Name: "<<customer[i].name<<endl;
			cout<<"Customer Father Name: "<<customer[i].fname<<endl;
			cout<<"Customer Phone No: "<<customer[i].phone<<endl;
			cout<<"Customer ID Card Number: "<<customer[i].idcard<<endl;
			cout<<"Customer Amount: "<<customer[i].cash<<endl;
			cout<<endl;
			
			cout<<"\nUpdating the Customer Information"<<endl<<endl;
			cout<<"Enter Your ID: ";
			cin>>customer[i].ID;
			cout<<"Enter Your Name: ";
			cin>>customer[i].name;
			cout<<"Enter Your Father Name: ";
			cin>>customer[i].fname;
			cout<<"Enter Your Phone Number: ";
			cin>>customer[i].phone;
			cout<<"Enter Your ID Card Number: ";
			cin>>customer[i].idcard;
			cout<<"Enter Your Cash: ";
			cin>>customer[i].cash;
			
		}
		else if(i == completed - 1) {
			cout<<"Customer record not found."<<endl;;
		}
	}
}

void banking::search(){
	cout<<"Enter the ID of customer for Searching the information: ";
	cin>>id;
	for(int i = 0; i < completed; i++){
		if(id == customer[i].ID){
			cout<<"Customer Record is Found."<<endl<<endl;
			cout<<"Customer Uniue ID: "<<customer[i].ID<<endl;
			cout<<"Customer Name: "<<customer[i].name<<endl;
			cout<<"Customer Father Name: "<<customer[i].fname<<endl;
			cout<<"Customer Phone No: "<<customer[i].phone<<endl;
			cout<<"Customer ID Card Number: "<<customer[i].idcard<<endl;
			cout<<"Customer Amount: "<<customer[i].cash<<endl;
			cout<<endl;
		}
		else if(i == completed-1) {
			cout<<"Customer record not found."<<endl;;
		}
	}
}

void banking::transaction(){
	char select;
	int cash1;
	cout<<"Enter the ID of customer for Transaction the information: ";
	cin>>id;
	for(int i = 0; i < completed; i++){
		if(id == customer[i].ID){
			cout<<"Customer Record is Found."<<endl<<endl;
			cout<<"Customer Name: "<<customer[i].name<<endl;
			cout<<"Customer Existing Amount: "<<customer[i].cash<<endl;
			cout<<"Enter 1 for deposit amount."<<endl;
			cout<<"Enter 2 for Withdraw amount."<<endl;
			cout<<"Enter Your Choice: ";
			cin >> select;
			switch(select){
				case '1':
					cout<<"Enter the Amount for Deposits: ";
					cin>>cash1;	
					cout<<"Your Transaction is Processing Please Wait !"<<endl;
					Sleep(3000);
					customer[i].cash += cash1;
					cout<<"Transaction Done !"<<endl;
					cout<<"New Amount: "<<customer[i].cash<<endl;
					break;
				
				case '2':
					previouswithdraw:
					cout<<"Enter the Amount for Withdraw: ";
					cin>>cash1;	
					if(cash1 > customer[i].cash){
						cout<<"Your Amount is greater then existing Amount."<<endl;
						goto previouswithdraw;
					}
					cout<<"Your Transaction is Processing Please Wait !"<<endl;
					Sleep(3000);
					customer[i].cash -= cash1;
					cout<<"Transaction Done !"<<endl;
					cout<<"Existing Amount: "<<customer[i].cash<<endl;
					break;	
			}
		}
		else if(i == completed-1) {
			cout<<"Customer record not found."<<endl;
		}
}
}

void banking::logout(){
	cout<<"Logout from Bank Management";
	Sleep(2000);
	exit(0);
}

int main() {
	string uname, uname1;
	int pin, pin1;
	cout<<"\n\n\n\n\t\t\t\t\t\t\tBank Managemnt System \n\n\n";
	cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n\t\t\t\t\t\t\t\t Sign Up Here \n\n\n";
	cout<<"Enter Your Name: ";
	cin>>uname;
	cout<<"Enter Your 4 Digit Pin: ";
	cin>>pin;
	cout<<"Your Account is Creating. Please Wait ";
	for(int i = 0; i < 2; i++){
		cout<<".";
		Sleep(2000);
	}
	cout<<endl;
	system("CLS");
	cout<<"\n\n\n\t\t\t\t\tYour Account is Created Successfully. ";
	Sleep(2000);
	system("CLS");
	previouslogin:
	cout<<"\n\t\t\t\t\t\t\t Login Here \n\n\n";
	cout<<"Enter Your Name: ";
	cin>>uname1;
	cout<<"Enter Your 4 Digit Pin: ";
	cin>>pin1;
	if(uname1 == uname && pin1 == pin){
		system("CLS");
		banking obj;
		obj.option(); 
	}
	else if(uname1 != uname){
		cout<<"Incorrect Username !";
		goto previouslogin;
	}
	else if(pin1 != pin){
		cout<<"Incorrect Pin !";
		goto previouslogin;
	}
	
	return 0;
}





