#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;
static const int NUM_SPORTS = 7;
enum Month { NoMonth, Janurary, Feburary, March, April, May, June, July, August, September, October, November, December };

class Player : public Person
{
	struct tm date = { 0 };
	int birthYear, birthDay;
	Month birthMonth;
	bool sex, sports[NUM_SPORTS];
public:
	Player();
	Player(string _fname, string _lname, string _email, string _phoneNum, string _jerseySize, int _birthYear, int _birthMonth, int _birthDay, bool _sex, bool _sports[]);
	void set(string _fname, string _lname, string _email, string _phoneNum, string _jerseySize, int _birthYear, int _birthMonth, int _birthDay, bool _sex, bool _sports[]);
	void set(int _id, string _fname, string _lname, string _email, string _phoneNum, string _jerseySize, int _birthYear, int _birthMonth, int _birthDay, bool _sex, bool _sports[]);
	void setPerson(Person _person);
	void setBirthYear(int _birthYear);
	void setBirthMonth(int _birthMonth);
	void setBirthDay(int _birthDay);
	void setSex(bool _sex);
	void setSport(int sport, bool status);
	void printHeaders();
	void print();
	int getAge();
	int getBirthYear() const;
	int getBirthMonth() const;
	int getBirthDay() const;
	bool getSex() const;
	string getStrSex() const;
	//friend enum Month;
	friend Player registerPlayer(Person _person, int _sport);
	friend Player getPlayer(fstream& _file, int _personID);
};
#endif PLAYER_H
