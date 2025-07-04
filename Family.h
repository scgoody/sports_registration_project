#ifndef FAMILY_H
#define FAMILY_H
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;
class Family : public Person
{
	double balance, donations;
public:
	Family();
	Family(string _fname, string _lname, string _email, string _phoneNum, string _jerseySize);
	void set(string _fname, string _lname, string _email, string _phoneNum, string _jerseySize);
	void set(int _id, string _fname, string _lname, string _email, string _phoneNum, string _jerseySize, double _balance, double _donations);
	void setBalance(double _balance);
	void setDonations(double _donations);
	double getBalance() const;
	double getDonations() const;
	string payBalance(double payment);
	void makeDonation(double _donation);
	friend Family getFam(fstream&, int);
};
#endif FAMILY_H
