#include<iostream>
#include<sstream>
#include<string>
#include "Air.h"
#include <fstream>
#include<array>


using namespace std;


Customer::Customer(string n,string s, int id, string em, string gen, int ph){
	
	name=n;
	surname=s;
	IdNo=id;
	Email=em;
	gender=gen;
	phone=ph;
	
	
}

//constructor for ticket class

Ticket::Ticket(string d,string s){
	date=d;
	source=s;
	
}
//constructor for flight class

Flight::Flight(string de,string da){
	destination=de;
	date2=da;
	
}

	//set and get functions
	
	void Customer::setName(string n){
		name=n;
	}
	void Customer::setSurname(string n){
		surname=n;
	}
	
	void Customer::setIdNo(int i){
		IdNo=i;
	}
	
	void Customer::setEmail(string E){
		Email=E;
	}
	
	void Customer::setGender(string G) {
		gender=G;
	}
	
	void Customer::setPhone(int P){
		phone=P;
	}
	string Customer::getName(){
	return name;
}
string Customer::getSurname(){
	return surname;
}
	int Customer::getIdNo(){
		return IdNo;
	}
	string Customer::getEmail(){
		return Email;
	}
	
	string Customer::getGender(){
		return gender;
	}
	int Customer::getPhone(){
		return phone;
	}


	void Ticket::setSource(string p){
		source=p;
	}
	
	void Ticket::setDate(string k) {
		date=k;
	}
	string Ticket::getSource(){
		return source;
	}
	string Ticket::getDate(){
		return date;
	}
	void Flight::setDestination(string p){
		destination=p;
	}
	
	void Flight::setDate(string k) {
		date2=k;
	}
	string Flight::getDestination(){
		return destination;
	}
	string Flight::getDate(){
		return date2;
	}

//set and get functions	
	
		
		
//customer class
	
	void Customer::ejjectthepassdata(){
	ofstream doc;
	doc.open("Passenger.txt", ios::app);
	doc<<toStringp();
	doc.close();
}



string Customer::toStringp(){
	ostringstream output;
	
	output<<"Name: "<<name<<endl<<endl<<"Surname: "<<surname<<endl<<endl<<"IdNo: "<<IdNo<<endl<<endl<<"E-mail: "<<Email<<endl<<endl<<"Gender: "<<gender<<endl<<endl<<"Phone: "<<phone<<endl<<endl<<endl<<endl;
	
	return output.str();
}


void Customer::Register(){
		int select1;
		
	while(select1!=3){
		
		cout<<endl<<"1-) New registration"<<endl<<"2-) Delete registrations"<<endl<<"3-) Go back"<<endl<<endl;
		cin>>select1;
		switch (select1)
		{
			
			case 1:{
				
			newReg();
			exit;
			break;
		}
			
			case 2:{
				
			
			delReg();
			exit;
			break;
		}
			case 3:
			system("CLS");
			exit;
			break;
			
			default:
			cout<<"Invalid Choice"<<endl;
			break;
		}

   }
}

void Customer::newReg(){
		int Phones, ids;
	string n,s,Emails,Genders;
	
readRegistration();

	
		cout<<"Enter name :"<<endl;
		cin>>n;
		cout<<"Enter surname :"<<endl;
		cin>>s;
		cout<<"Enter Id:"<<endl;
		cin>>ids;
		cout<<"Enter Email:"<<endl;
		cin>>Emails;
		cout<<"Enter Gender:"<<endl;
		cin>>Genders;
		cout<<"Enter phone:"<<endl;
		cin>>Phones;
		Customer r1(n,s,ids,Emails,Genders,Phones);
		r1.toStringp();
		r1.ejjectthepassdata();
}

void Customer::delReg(){
ofstream ofs;
ofs.open("Passenger.txt", ofstream::out | ofstream::trunc);
ofs.close();
}

void Customer::readRegistration(){
	cout<<endl;
	string Customer;
			ifstream read("Passenger.txt");
		while (getline (read, Customer)) {
  cout << Customer<<endl;;
}

read.close();
	
}




//ticket class


void Ticket::cleanTickets(){
	int selectcleantic;
	
	
		
	cout<<"Are you sure that you want to delete the tickets?"<<endl;
		
	cout<<endl<<"1-) Yes"<<endl<<"2-) No"<<endl<<endl;
		cin>>selectcleantic;
	
	switch(selectcleantic){
	
	case 1:
		{
		
		ofstream ofs;
     ofs.open("Ticket.txt", ofstream::out | ofstream::trunc);
      ofs.close();
      break;
  }
  
      case 2:
	  {
		break;
	  }
      
      
      default:
      	cout<<"Invalid Choice."<<endl;
      
      }
  }



void Ticket::takeTicket(){
	
	int classs;
	int selecttic;
	string da,so,pass;
	Ticket t1(da,so);
	
	//

ofstream log("Ticket.txt", std::ios_base::app | std::ios_base::out);
	
	
cout<<"Enter date (DD/MM/YYYY) (The date you want to fly off):"<<endl;
cin>>da;
cout<<"Enter source(From where?): "<<endl;
cin>>so;

cout<<endl;
	
	
//transferring passenger data
	
ifstream infile("Passenger.txt");
log<<"Passenger Informations:"<<endl<<endl;;
while(getline(infile, pass)){
	log << pass<<endl;
}
    
cout<<endl;	
infile.close();
	
	
	
cout<<"Current available flights:"<<endl;
string flights;
	ifstream read2("Flights.txt");
	while (getline (read2, flights)) {
  cout << flights<<endl;
}

read2.close();

cout<<endl;

cout<<"Select your flight (1,2,3...) (To where?)"<<endl;
cin>>selecttic;

cout<<endl;

string line;
ifstream flight2("Flights.txt");
for(int i = 0; i < selecttic; ++i){

getline(flight2, line);
}
cout<<line<<endl<<endl;

//transferring informations
log<<endl;
log<<"Flight informations:"<<endl<<endl;
log<<"From : "<<so<<endl<<endl;
log<<"To : "<<line<<endl<<endl;
log<<"Date : "<<da<<endl<<endl;


cout<<"Select class:"<<endl<<endl<<"1-) First class"<<endl<<"2-) Business class"<<endl<<"3-) Economic class"<<endl<<endl;
cin>>classs;

log<<"Class: ";
switch(classs){
	case 1:
		log<<"First class"<<endl<<endl;
	break;
	
	case 2:
		log<<"Business class"<<endl<<endl;
	break;
	
	case 3:
		log<<"Economic class"<<endl<<endl;
	break;
	
	default:
		cout<<"invaild choice"<<endl;
	
}

system("CLS");

t1.showTicket();

cout<<"Have a good flight! :)"<<endl;

log.close();

}


void Ticket::showTicket(){
	
		string tickets;
	ifstream read3("Ticket.txt");
	while (getline (read3, tickets)) {
  cout << tickets<<endl;
}

read3.close();
	
}





//flight class




string Flight::toStringf(){
	ostringstream outputt;
	
	outputt<<destination<<" - "<<date2<<endl;
	
	return outputt.str();
}

void Flight::ejjecttheflightdata(){
	ofstream doc;
	doc.open("Flights.txt", ios::app);
	doc<<toStringf();
	doc.close();
}

void Flight::devOptions(){
	
	int select2;
	while(select2!=3){
	cout<<"1-) New flight"<<endl<<"2-) Delete flights"<<endl<<"3-) Go back"<<endl<<endl;
	
	cin>>select2;
	
	switch(select2){
		
		case 1:
		newFlight();
		break;
	
		case 2:
		deleteFlight();
		break;
		
		case 3:{
		break;
	}
		default:
			cout<<"Invalid choice"<<endl;
			break;
	}
	
	
}
	
}

void Flight::newFlight(){
	string s, d;
	int selectf;
	
	
	while(selectf!=2){
		cout<<endl;
		
		showFlights();
		
	cout<<"1-)Add new flight (Up to 8)"<<endl<<"2-) Go back"<<endl<<endl;
	cin>>selectf;
	
	switch(selectf){
	
	
	case 1:{
		
	
	cout<<"Enter Location :"<<endl;
		cin>>s;
		cout<<"Enter Time :"<<endl;
		cin>>d;
		Flight f2 (s,d);
	 f2.toStringf();
	 f2.ejjecttheflightdata();
	 break;
}



    case 2:
    	
	break;
    
    default:
    	cout<<"invalid choice"<<endl;

	 
	 }
	 
	}


}

void Flight:: deleteFlight(){
ofstream ofs;
ofs.open("Flights.txt", std::ofstream::out | std::ofstream::trunc);
ofs.close();
	
}


void Flight::showFlights(){
	cout<<endl;
	cout<<"Current available flights:"<<endl<<endl;
string flights;
	ifstream read2("Flights.txt");
	while (getline (read2, flights)) {
  cout << flights<<endl;
}

read2.close();
cout<<endl;	
}











//MAIN FUNCTION

//"S" for selected
int main () {
		
	int select;
	int PhoneS, idS;
	string n,s,EmailS,GenderS, datesF,datesT, destinationS,sourceS;
	Customer r1(n,s,idS,EmailS,GenderS,PhoneS);
	Flight f1(destinationS,datesF);
	Ticket t2(sourceS,datesT);
	 
	 
	cout<<"Welcome to airline flight reservation system."<<endl<<endl;

	

while(select!=8){
	
cout<<"*********************************************************************************************************"<<endl;

cout<<endl<<"1-) Registration options"<<endl<<"2-) Show current tickets"<<endl<<"3-) Flight schedule"<<endl<<"4-) Pick a ticket"<<endl<<"5-) Show Passenger infos"<<endl<<"6-) Admin options"<<endl<<"7-) Clean Tickets"<<endl<<"8-) Exit"<<endl<<endl;
cout<<"Select to continue."<<endl;
cin>>select;
	switch (select){
		
		case 1:
		system("CLS");
		r1.Register();
		
		break;
	
		case 2:
		system("CLS");
		t2.showTicket();
			
		break;	
	
		
		case 3:
		system("CLS");
		f1.showFlights();
		break;
		
		
		case 4:
		system("CLS");
		t2.takeTicket();	
		break;
			
		case 5:
		system("CLS");
		r1.readRegistration();
		break;
		
		case 6:
		system("CLS");	
		f1.devOptions();
		break;
			
		case 7:
			system("CLS");
			t2.cleanTickets();
		break;
		
		case 8:
		break;
		
		default:
		cout<<"Invalid Choice"<<endl;	
			
	
}

	}

}

	

