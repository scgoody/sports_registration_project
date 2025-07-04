#include <iostream>
#include <iomanip> 
#include <string>
#include <fstream>
#include <ctime>
#include "Player.h"
#include "Person.h"
using namespace std;

Player::Player() : Person()
{
	birthYear = 0;
	birthMonth = static_cast<Month>(0); // 0 = None, indicating user has not inputted birth month
	birthDay = 0;
	sex = NULL;
	for (int i = 0; i < 6; i++)
	{
		sports[i] = 0;
	}
}
Player::Player(string _fname, string _lname, string _email, string _phoneNum, string _jerseySize, int _birthYear, int _birthMonth, int _birthDay, bool _sex, bool _sports[]) : Person(_fname, _lname, _email, _phoneNum, _jerseySize)
{
	set(_fname, _lname, _email, _phoneNum, _jerseySize, _birthYear, _birthMonth, _birthDay, _sex, _sports);
}
void Player::set(string _fname, string _lname, string _email, string _phoneNum, string _jerseySize, int _birthYear, int _birthMonth, int _birthDay, bool _sex, bool _sports[])
{
	Person::set(_fname, _lname, _email, _phoneNum, _jerseySize);
	sex = _sex;
	birthYear = _birthYear;
	birthMonth = static_cast<Month>(_birthMonth);
	birthDay = _birthDay;
	for (int i = 0; i < NUM_SPORTS; i++)
	{
		sports[i] = _sports[i];
	}
}
void Player::set(int _id, string _fname, string _lname, string _email, string _phoneNum, string _jerseySize, int _birthYear, int _birthMonth, int _birthDay, bool _sex, bool _sports[])
{
	Person::set(_id, _fname, _lname, _email, _phoneNum, _jerseySize);
	sex = _sex;
	birthYear = _birthYear;
	birthMonth = static_cast<Month>(_birthMonth);
	birthDay = _birthDay;
	for (int i = 0; i < NUM_SPORTS; i++)
	{
		sports[i] = _sports[i];
	}
}
void Player::setPerson(Person _person)
{
	Person::set(_person.getFname(), _person.getLname(), _person.getEmail(), _person.getPhoneNum(), _person.getJerseySize());
}
void Player::setBirthYear(int _birthYear)
{
	birthYear = _birthYear;
}
void Player::setBirthMonth(int _birthMonth)
{
	birthMonth = static_cast<Month>(_birthMonth);
}
void Player::setBirthDay(int _birthDay)
{
	birthDay = _birthDay;
}
void Player::setSex(bool _sex)
{
	sex = _sex;
}
void Player::setSport(int sport, bool status)
{
	sports[sport] = status;
}
void Player::printHeaders()
{
	Person::printHeaders();
	cout << setw(15) << "Birth Year" << setw(15) << "Birth Month" << setw(10) << "Birth Day" << setw(5) << "Sex" << setw(5) << "FB" << " " << "Soc" << " " << "Vol" << " " << "Bball" << " " << "Swim" << " " << "Lax" << " " << "TF";
}
void Player::print()
{
	Person::print();
	cout << setw(15) << birthYear << setw(12) << birthMonth << setw(7) << birthDay << setw(7) << sex << setw(5);

	for (int i = 0; i < NUM_SPORTS - 1; i++)
	{
		cout << sports[i] << "   ";
	}

}
int Player::getAge()
{
	date.tm_year = birthYear - 1900;
	date.tm_mon = birthMonth - 1;
	date.tm_mday = birthDay;
	time_t normal = mktime(&date);
	time_t current;
	time(&current);
	int age = (difftime(current, normal) + 86400L / 2) / 86400L;
	return age;
}
int Player::getBirthYear() const
{
	return birthYear;
}
int Player::getBirthMonth() const
{
	return birthMonth;
}
int Player::getBirthDay() const
{
	return birthDay;
}
bool Player::getSex() const
{
	return sex;
}
string Player::getStrSex() const
{
	if (sex == 0)
		return "Male";
	else
		return "Female";
}