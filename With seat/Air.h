#ifndef AIR_H
#define AIR_H
#include<iostream>
#include<array>
#include<string>
#include<vector>

using namespace std;

class Customer{
	public:
		
	string name;
	string surname;
	int IdNo;
	string Email; 
	string gender;
	int phone;   
	
	Customer(string,string, int, string, string, int);
	
	//set functions
	void setName(string);
	void setSurname(string);
	void setIdNo(int);
	void setEmail(string);
	void setGender(string);
	void setPhone(int);
	//get functions
	
	string getName();
	string getSurname();
	int getIdNo();
	string getEmail();
	string getGender();
	int getPhone();
	
	//other functions
	void Register();
	void newReg();
	void delReg();
	
	void readRegistration();
	
	//
	string toStringp();
	void ejjectthepassdata();
	
	
};

class Ticket{
	public:
		
	string date; 
	string source;
	 
	
	Ticket(string,string);
	
	//get functions
	string getSource();
	string getDate();
	
	//set functions
	void setDate(string);
	void setSource(string);
	
	
	//other functions
	
	void showTicket();
	void cleanTickets();
	void takeTicket();
	void takeseat();
	
    
};
class Flight{
	public:
		
	string destination;
	string date2;
	
		
	Flight(string,string);
	
	//get functions
	string getDate();
	string getDestination();
	
	//set functions
	void setDestination(string);
	void setDate(string);
	
    //other functions
	void devOptions();
	void newFlight();
	void deleteFlight();
	void showFlights();
	
	//
	string toStringf();
	void ejjecttheflightdata();
	
};

#endif
