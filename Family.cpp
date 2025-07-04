#include <iostream>
#include <iomanip> 
#include <string>
#include <fstream>
#include <ctime>
#include "Family.h"
#include "Person.h"
using namespace std;
Family::Family() : Person()
{
	balance = 0;
	donations = 0;
}
Family::Family(string _fname, string _lname, string _email, string _phoneNum, string _jerseySize) : Person(_fname, _lname, _email, _phoneNum, _jerseySize)
{
	balance = 0;
	donations = 0;
}
void Family::set(string _fname, string _lname, string _email, string _phoneNum, string _jerseySize) //new fam
{
	Person::set(_fname, _lname, _email, _phoneNum, _jerseySize);
	balance = 0;
	donations = 0;
}
void Family::set(int _id, string _fname, string _lname, string _email, string _phoneNum, string _jerseySize, double _balance, double _donations) //redefine existing fam
{
	Person::set(_id, _fname, _lname, _email, _phoneNum, _jerseySize);
	balance = _balance;
	donations = _donations;
}
void Family::setBalance(double _balance)
{
	balance = _balance;
}
void Family::setDonations(double _donations)
{
	donations = _donations;
}
double Family::getBalance() const
{
	return balance;
}
double Family::getDonations() const
{
	return donations;
}
string Family::payBalance(double payment)
{
	if (payment <= balance && payment > 0)
	{
		balance -= payment;
		return "Payment processed";
	}
	else
		return "Error: invalid payment amount";
}
void Family::makeDonation(double _donation)
{
	donations += _donation;
}