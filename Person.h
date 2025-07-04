#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;

class Person
{
	static int nextID;
	int id;
	string fname, lname, email, phoneNum;
	string jerseySize;
public:
	Person();
	Person(string _fname, string _lname, string _email, string _phoneNum, string _jerseySize);
	void set(string _fname, string _lname, string _email, string _phoneNum, string _jerseySize);
	void set(int _id, string _fname, string _lname, string _email, string _phoneNum, string _jerseySize);
	void setFname(string _fname);
	void setLname(string _lname);
	void setEmail(string _email);
	void setPhoneNum(string _phoneNum);
	void setJerseySize(string _jerseySize);
	void setID(int _id);
	int getID() const;
	string getFname() const;
	string getLname() const;
	string getEmail() const;
	string getPhoneNum() const;
	string getJerseySize() const;
	void printHeaders();
	void print();
	friend Person registerPerson();
	friend Person login(fstream& _file, string fileName);
};
#endif PERSON_h