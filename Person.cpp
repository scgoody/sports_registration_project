#include <iostream>
#include <iomanip> 
#include <string>
#include <fstream>
#include <ctime>
#include "Person.h"
using namespace std;
Person::Person()
{
	id = 0;
	fname = "";
	lname = "";
	email = "";
	phoneNum = "";
	jerseySize = "";
}
Person::Person(string _fname, string _lname, string _email, string _phoneNum, string _jerseySize)
{
	id = nextID;
	nextID++;
	set(_fname, _lname, _email, _phoneNum, _jerseySize);
}

void Person::set(string _fname, string _lname, string _email, string _phoneNum, string _jerseySize)
{
	id = nextID;
	nextID++;
	fname = _fname;
	lname = _lname;
	email = _email;
	phoneNum = _phoneNum;
	jerseySize = _jerseySize;
}
void Person::set(int _id, string _fname, string _lname, string _email, string _phoneNum, string _jerseySize)
{
	id = _id;
	fname = _fname;
	lname = _lname;
	email = _email;
	phoneNum = _phoneNum;
	jerseySize = _jerseySize;
}
void Person::setFname(string _fname)
{
	fname = _fname;
}
void Person::setLname(string _lname)
{
	lname = _lname;
}
void Person::setEmail(string _email)
{
	email = _email;
}
void Person::setPhoneNum(string _phoneNum)
{
	phoneNum = _phoneNum;
}
void Person::setJerseySize(string _jerseySize)
{
	jerseySize = _jerseySize;
}
void Person::setID(int _id)
{
	id = _id;
}
int Person::getID() const
{
	return id;
}
string Person::getFname() const
{
	return fname;
}
string Person::getLname() const
{
	return lname;
}
string Person::getEmail() const
{
	return email;
}
string Person::getPhoneNum() const
{
	return phoneNum;
}
string Person::getJerseySize() const
{
	return jerseySize;
}
void Person::printHeaders()
{
	cout << "ID" << setw(10) << "First Name" << setw(15) << "Last Name" << setw(15) << "Phone Number" << setw(15) << "Jersey Size" << setw(15);
}
void Person::print()
{
	cout << id << setw(5) << fname << setw(15) << lname << setw(15) << email << setw(15) << phoneNum << setw(15) << jerseySize << setw(10);
}
