#include <iostream>
#include <iomanip> 
#include <string>
#include <fstream>
#include <ctime>
#include "Person.h"
#include "Player.h"
#include "Family.h"
using namespace std;

enum Sport { NoSport, Football, Soccer, Volleyball, Basketball, Swim, Lacross, Track };
enum AgeGroup{NoAge, U4, U5, U6, U7, U8, U9, U10, U11, U12, U13, U14, U15, U16, U17, U18};
enum Season{NoSeason,Fall, Winter, Spring, Summer};

int Person::nextID = 1;

Person login(fstream& _file, string fileName);
void sportsMenu();
string getSport(int _sport);
void ageGroupMenu();
string getAgeGroup(int _age);
Person registerPerson();
Player registerPlayer(Person & _person, int _sport);
Player getPlayer(fstream& _file, int _personID);
void viewDonationsMenu();
Family getFam(fstream& , int);
void viewBalanceMenu(); 
void displayUserMenu();
void displayAdminMenu();
void displayPlayerMenu();
float getPrice(int);
void openFile(fstream& _file, string fileName);
void closeFile(fstream& _file, string fileName);


int main()
{
	fstream file;

	Person person;
	Player player;
	Family family;

	
	int userType, _id, id, userOpt, opt;
	string firstName, lastName, _email, _phoneNum, _sport, success, _ageGroup;
	string jsize;
	int bYear, bMonth, bDay, _sportInt, ageGroupInt, age, sexOpt, sport;
	bool _sex, _sports[NUM_SPORTS];
	do
	{
		double _balance, _donations, totBalance, totDonations, _payment;
		displayUserMenu();
		cin >> userType; 

		switch (userType) {
		case 1:
			person = login(file,"adminUsers");
			
			displayAdminMenu();
			cin >> userOpt;
			int famID;
			while (userOpt != 6)
			{
				switch (userOpt)
				{
				case 1: // balances
					file.open("balances.txt");
					if (!file) 
					{
						file.close();
						file.open("balances.txt", ios::out);
						file.close();
					}
					file.close();
					file.open("balances.txt", ios::out | ios::in |ios::ate);
					file.seekp(0, ios::end);
					do
					{
						viewBalanceMenu();
						cin >> opt;
						switch (opt)
						{
						case 1: // all
							totBalance = 0;
							file.clear();
							file.seekg(0L, ios::beg);
							while (file >> famID)
							{
								file >> _balance;
								totBalance += _balance;
							}
							cout << "The current total balance amount of all accounts is: " << totBalance << endl;
							break;
						case 2: // family id
							int fID;
							totBalance = 0;
							cout << "Enter family ID: ";
							cin >> fID;
							file.clear();
							file.seekg(0L, ios::beg);
							while (file >> famID)
							{
								file >> _balance;
								if (famID == fID)
								{
									totBalance += _balance;
								}
							}
							cout << "Total balance currently associated with family ID " << fID << ": " << totBalance << endl;
							break;
						case 3:
							break;
						default: // invalid opt
							cout << "Invalid Entry" << endl;
							break;
						}
					} while (opt != 3);
					file.close();
					break;
				case 2: // donations
					openFile(file, "donations"); 
					do
					{
						viewDonationsMenu();
						cin >> opt;
						switch (opt)
						{
						case 1: // all
							totDonations = 0;
							file.clear();
							file.seekg(0L, ios::beg);
							while (file >> famID)
							{
								file >> _donations;
								totDonations += _donations; 
							}
							cout << "The current total donations recieved are: " << totDonations << endl;
							break;
						case 2: // family id
							int fID;
							totDonations = 0;
							cout << "Enter family ID: ";
							cin >> fID;
							file.clear();
							file.seekg(0L, ios::beg);
							while (file >> famID)
							{
								file >> _donations;
								if (famID == fID)
								{
									cout << _donations << endl;
									totDonations += _donations;
								}
							}
							cout << "Total donations contributed by family ID " << fID << ": " << totDonations << endl;
							break;
						case 3:
							break;
						default: // invalid opt
							cout << "Invalid Entry" << endl;
							break;
						}
					} while (opt != 3);
					closeFile(file, "donations");
					break;
				case 3: // view players

					openFile(file, "playerUsers");
					file.clear();
					file.seekg(0L, ios::beg);
					player.printHeaders();
					cout << endl;
					while (file >> _id)
					{
						file >> firstName >> lastName >> _email >> _phoneNum >> jsize >> bYear >> bMonth >> bDay >> _sex;
						for (int i = 0;i < NUM_SPORTS-1; i++)
						{
							file >> _sports[i];
						}
						player.set(_id, firstName, lastName, _email, _phoneNum, jsize, bYear, bMonth, bDay, _sex, _sports);
						player.print();
						cout << endl;
					}
					closeFile(file, "playerUsers");
					break;
				case 4: // view parents

					openFile(file, "familyUsers");
					file.clear();
					file.seekg(0L, ios::beg);
					family.printHeaders();
					cout << endl;
					while (file >> _id)
					{
						file >> firstName >> lastName >> _email >> _phoneNum >> jsize;
						file >> _balance >> _donations;
						family.set(_id, firstName, lastName, _email, _phoneNum, jsize, _balance, _donations);
						family.print();
						cout << endl;
					}
					closeFile(file, "familyUsers");
					break;
				case 5: // view a team roster
					_sportInt = 0;
					while (_sportInt < 1 || _sportInt > 7)
					{
						sportsMenu();
						cin >> _sportInt;
					}
					ageGroupInt = 0;
					while (ageGroupInt < 1 || ageGroupInt > 15)
					{
						ageGroupMenu();
						cin >> ageGroupInt;
					}
					cout << "1. Male" << endl;
					cout << "2. Female" << endl;
					cout << "Enter 1 or 2: ";
					cin >> sexOpt;
					if (sexOpt == 1)
					{
						cout << getAgeGroup((ageGroupInt + 2)*365) << " Male " << getSport(_sportInt) << endl;
						openFile(file, "Male" + getSport(_sportInt) + getAgeGroup((ageGroupInt + 2) * 365));
						file.seekg(0L, ios::beg);
						cout << "Player ID   First Name" << setw(10) << "Last Name" << setw(15) << "Age (Days)" << endl;
						while(file >> _id)
						{
							file >> firstName >> lastName >> age;
							cout << _id << setw(15) << firstName << setw(10) << lastName << setw(20) << age << endl;
						}
						closeFile(file, "Male" + getSport(_sportInt) + getAgeGroup(ageGroupInt + 2));
					}
					else if (sexOpt == 2)
					{
						openFile(file, "Female" + getSport(_sportInt) + getAgeGroup(ageGroupInt + 2));
						file.seekg(0L, ios::beg);
						while (file >> _id)
						{
							file >> firstName >> lastName >> age;
							cout << _id << firstName << lastName << age << endl;
						}
						closeFile(file, "Female" + getSport(_sportInt) + getAgeGroup(ageGroupInt + 2));
					}
					else
						cout << "Invalid Entry" << endl;
					break;
				default: // invalid userOpt
					cout << "Invalid Entry" << endl;
					break;
				}
				displayAdminMenu();
				cin >> userOpt;
			}
			break;
		case 2:
			person = login(file, "familyUsers");
			family = getFam(file, person.getID());
			displayPlayerMenu();
			cin >> userOpt;
			while (userOpt != 6)
			{
				switch (userOpt)
				{
				case 1: //register
					sport = 0;
					while (sport < 1 || sport > 7)
					{
						sportsMenu();
						cin >> sport;
					}
					person = registerPerson();
					player = registerPlayer(person, sport);
					// updating team file
					_ageGroup = getAgeGroup(player.getAge()); 
					openFile(file, player.getStrSex() + getSport(sport) + _ageGroup); 
					file.seekp(0L, ios::end); 
					file << player.getID() << " " << player.getFname() << " " << player.getLname() << " " << player.getAge() << endl;
					closeFile(file, player.getStrSex() + getSport(sport) + _ageGroup);
					// updating player file
					openFile(file, "playerUsers");
					file.clear(); 
					file.seekp(0L, ios::end);
					file << player.getID() << " " << player.getFname() << " " << player.getLname() << " " << player.getEmail() << " " << player.getPhoneNum() << " " << player.getBirthYear() << " " << player.getBirthMonth() << " " << player.getBirthDay() << " " << player.getSex() << " ";
					for (int i = 1;i < sport; i++)
					{
						file << 0 << " ";
					}
					file << 1 << " ";
					for (int i = sport + 1;i <= NUM_SPORTS; i++)
					{
						file << 0;
						if(i<NUM_SPORTS)
						file << " ";
					}
					file << endl;
					closeFile(file, "playerUsers");
					// updating balance file
					openFile(file, "balances");
					file.clear();
					file.seekp(0L, ios::end);
					file << family.getID() << " " << getPrice(sport) << endl;
					closeFile(file, "balances");

					break; 
				case 2: //view registrations

						// reading from player file
						openFile(file, "playerUsers");
						file.clear();
						file.seekg(0L, ios::beg);
						player.printHeaders();
						cout << endl;
						while (file >> id)
						{
							file >> firstName >> lastName >> _email >> _phoneNum >> jsize >> bYear >> bMonth >> bDay >> _sex;
							for (int i = 0;i < NUM_SPORTS-1; i++)
							{
								file >> _sports[i];
							}
							player.set(id, firstName, lastName, _email, _phoneNum, jsize, bYear, bMonth, bDay, _sex, _sports);
							player.print();
							cout << endl;
						}
						closeFile(file, "playerUsers");
	
					break;
				case 3: //view account details
					// reading from fam file
					openFile(file, "familyUsers");
					file.clear();
					file.seekg(0L, ios::beg);
					family.printHeaders();
					cout << endl;
					while (file >> _id)
					{
						file >> firstName >> lastName >> _email >> _phoneNum >> jsize;
						file >> _balance >> _donations;
						if(_id == family.getID())
						{
							family.set(_id, firstName, lastName, _email, _phoneNum, jsize, _balance, _donations);
							family.print();
							cout << endl;
						}
					}
					closeFile(file, "familyUsers");
					break;
				case 4: //pay bill
					totBalance = 0;
					openFile(file, "balances");
					file.clear();
					file.seekg(0L, ios::beg);
					while (file >> famID)
					{
						file >> _balance;
						if (famID == family.getID())
						{
							totBalance += _balance;
							family.setBalance(totBalance);
						}
					}
					
					cout << "Your balance is: " << totBalance << endl;
					cout << "How much would you like to pay?: ";
					cin >> _payment;
					
					if (_payment <= 0)
					{
						cout << "Error: Payment must be positive value" << endl;
					}
					else
					{
						success = family.payBalance(_payment);
						cout << success << endl;
						_payment = 0 - _payment;
						if (success == "Payment processed")
						{
							// updating balance file
							file.clear();
							file.seekp(0L, ios::end);
							file << family.getID() << " " << _payment << endl;
						}
					}
					closeFile(file, "balances");
					break;
				case 5: //make donation
					cout << "How much would you like to donate?: ";
					cin >> _donations;
					if (_donations <= 0)
					{
						cout << "Error: Donation must be positive value" << endl;
					}
					else
					{
						family.makeDonation(_donations);
					}
					// updating donation file
					openFile(file, "donations");
					
					file.clear();
					file.seekp(0L, ios::end);
					file << family.getID() << " " << _donations << endl;
					closeFile(file, "donations");
					break;
				default:
					cout << "Invalid Entry" << endl;
					break;
				}
				displayPlayerMenu();
				cin >> userOpt;
			}
			break;
		case 5: // close program
			continue;
			break;
		default:
			cout << "Invalid Entry" << endl;
			break;
		}
	} while (userType != 3);

	system("pause");
	return 0;
}


void displayUserMenu()
{
	cout << "1. Administrator" << endl;
	cout << "2. Parent" << endl;
	cout << "3. Close program" << endl;
	cout << "Please select user type: ";
}

Person login(fstream& _file, string fileName)
{
	bool login = 0;
	Person temp;
	string firstName, lastName, _email, _phoneNum, jsize;
	int id, _id;
	while(login==0)
	{
		cout << "Enter user ID or 0 to create a new account: ";
		cin >> id;
		if (id == 0)
		{
			openFile(_file, fileName);
			temp = registerPerson();
			_file << temp.getID() << " " << temp.getFname() << " " << temp.getLname() << " " << temp.getEmail() << " " << temp.getPhoneNum() << " " << temp.getJerseySize();
			if (fileName == "familyUsers")
			{
				_file << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0;
			}
			_file << endl;
			closeFile(_file, fileName);
			cout << "User successfully created! Your ID is: " << temp.getID() << endl;
			login = 1;
		}
		else
		{
			openFile(_file, fileName);
			_file.clear();
			_file.seekg(0, ios::beg);
			while (_file >> _id >> firstName >> lastName >> _email >> _phoneNum >> jsize)
			{
				if (id == _id)
				{
					temp.set(_id, firstName, lastName, _email, _phoneNum, jsize);
					cout << "User successfully found!" << endl;
					login = 1;
				}
			}
			closeFile(_file, fileName);
		}
		if (login == 0)
			cout << "Error logging in: please try again." << endl;
	}
	return temp;
}

Player getPlayer(fstream& _file, int _personID)
{
	Player temp;
	int _id, bYear, bMonth, bDay;
	string firstName, lastName, _email, _phoneNum;
	string jsize;
	bool _sex, _sports[NUM_SPORTS];
	openFile(_file, "playerUsers");
	_file.clear();
	_file.seekg(0, ios::beg);
	while (_file >> _id)
	{
		_file >> firstName >> lastName >> _email >> _phoneNum >> jsize >> bYear >> bMonth >> bDay >> _sex;
		for (int i = 0;i < NUM_SPORTS; i++)
		{
			_file >> _sports[i];
		}
		if (_id == _personID)
		{
			temp.set(_id, firstName, lastName, _email, _phoneNum, jsize, bYear, bMonth, bDay, _sex, _sports);
		}
	}
	closeFile(_file, "playerUsers");
	return temp;
}
Family getFam(fstream& _file, int _personID)
{
	Family temp;
	string firstName, lastName, _email, _phoneNum, jsize;
	int _id;
	double _balance, _donations;
	openFile(_file, "familyUsers");
	_file.clear();
	_file.seekg(0, ios::beg);
	while (_file >> _id)
	{
		_file >> firstName >> lastName >> _email >> _phoneNum >> jsize;
		_file >> _balance >> _donations;
		if (_id == _personID)
		{
			temp.set(_id, firstName, lastName, _email, _phoneNum, jsize, _balance, _donations); 
		}
	}
	closeFile(_file, "familyUsers");
	return temp;
}

void displayAdminMenu()
{
	cout << "1. View balances" << endl;
	cout << "2. View donations" << endl;
	cout << "3. View all players" << endl;
	cout << "4. View all families" << endl;
	cout << "5. View teams" << endl;
	cout << "6. Log out" << endl;
	cout << "Select an option (1-6): ";
}

void viewBalanceMenu()
{
	cout << "1. View net balance of all accounts" << endl;
	cout << "2. View an account's balance by family ID" << endl;
	cout << "3. Back" << endl;
	cout << "Select an option (1-3): ";
}
void viewDonationsMenu()
{
	cout << "1. View net donations of all accounts" << endl;
	cout << "2. View an account's donations by family ID" << endl;
	cout << "3. Back" << endl;
	cout << "Select an option (1-3): ";
}
void displayPlayerMenu()
{
	cout << "1. Register" << endl;
	cout << "2. View registration status" << endl;
	cout << "3. View account details" << endl;
	cout << "4. Pay bill" << endl;
	cout << "5. Make a donation" << endl;
	cout << "6. Log out" << endl;
	cout << "Select an option (1-6): ";
}

void sportsMenu()
{
	cout << "1. Football" << endl;
	cout << "2. Soccer" << endl;
	cout << "3. Volleyball" << endl;
	cout << "4. Basketball" << endl;
	cout << "5. Swim" << endl;
	cout << "6. Lacross" << endl;
	cout << "7. Track & Field" << endl;
	cout << "Enter the integer corresponding to your sport choice: ";
}
string getSport(int _sport)
{
	switch (_sport)
	{
	case 1:
		return "Football";
		break;
	case 2:
		return "Soccer";
		break;
	case 3:
		return "Volleyball";
		break;
	case 4:
		return "Basketball";
		break;
	case 5:
		return "Swim";
		break;
	case 6:
		return "Lacross";
		break;
	case 7:
		return "Track & Field";
		break;
	default:
		return "None";
		break;
	}
}

float getPrice(int _sport)
{
	switch (_sport)
	{
	case 1:
		return 300;
		break;
	case 2:
		return 150;
		break;
	case 3:
		return 150;
		break;
	case 4:
		return 200;
		break;
	case 5:
		return 100;
		break;
	case 6:
		return 250;
		break;
	case 7:
		return 100;
		break;
	default:
		return 0;
		break;
	}
}

void ageGroupMenu()
{
	cout << "1. U4" << endl;
	cout << "2. U5" << endl;
	cout << "3. U6" << endl;
	cout << "4. U7" << endl;
	cout << "5. U8" << endl;
	cout << "6. U9" << endl;
	cout << "7. U10" << endl;
	cout << "8. U11" << endl;
	cout << "9. U12" << endl;
	cout << "10. U13" << endl;
	cout << "11. U14" << endl;
	cout << "12. U15" << endl;
	cout << "13. U16" << endl;
	cout << "14. U17" << endl;
	cout << "15. U18" << endl;
	cout << "Enter the integer corresponding to your age group choice: ";
}
string getAgeGroup(int _age)
{
	if (_age < 4 * 365)
		return "U4";
	else if (_age < 5 * 365)
		return "U5";
	else if (_age < 6 * 365)
		return "U6";
	else if (_age < 7 * 365)
		return "U7";
	else if (_age < 8 * 365)
		return "U8";
	else if (_age < 9 * 365)
		return "U9";
	else if (_age < 10 * 365)
		return "U10";
	else if (_age < 11 * 365)
		return "U11";
	else if (_age < 12 * 365)
		return "U12";
	else if (_age < 13 * 365)
		return "U13";
	else if (_age < 14 * 365)
		return "U14";
	else if (_age < 15 * 365)
		return "U15";
	else if (_age < 16 * 365)
		return "U16";
	else if (_age < 17 * 365)
		return "U17";
	else if (_age < 18 * 365)
		return "U18";
	else
		return "invalid age group";
}

Person registerPerson()
{
	Person temp;
	string _fname, _lname, _email, _phoneNum;
	string _jerseySize;
	cout << "Enter first name: ";
	cin >> _fname;
	cout << "Enter last name: ";
	cin >> _lname;
	cout << "Enter email: ";
	cin >> _email;
	cout << "Enter phone number: ";
	cin >> _phoneNum;
	cout << "Enter jersey size (S, M, or L): ";
	cin >> _jerseySize; 
	temp.set(_fname, _lname, _email, _phoneNum, _jerseySize);
	return temp;
}

Player registerPlayer(Person & _person, int _sport)
{
	Player temp;
	int _birthYear, _birthMonth, _birthDay;
	int sexEntry;
	bool _sex, _sports[NUM_SPORTS];
	cout << "Enter birth year: ";
	cin >> _birthYear;
	do
	{
		cout << "Enter integer of birth month (1-12): ";
		cin >> _birthMonth;
	} while (_birthMonth > 12 || _birthMonth < 1);
	do
	{
		cout << "Enter birth day (1-31): ";
		cin >> _birthDay;
	} while (_birthDay < 1 || _birthDay > 31);
	do
	{
		cout << "1. Male" << endl << "2. Female" << endl << "Enter integer corresponding to player sex: ";
		cin >> sexEntry;
	} while (sexEntry != 1 && sexEntry != 2);
	if (sexEntry == 1)
		_sex = 0;
	else
		_sex = 1;
	for (int i = 0; i < NUM_SPORTS; i++)
	{
		_sports[i] = 0;
	}
	_sports[_sport] = 1;
	temp.set(_person.getFname(), _person.getLname(), _person.getEmail(), _person.getPhoneNum(), _person.getJerseySize(), _birthYear, _birthMonth, _birthDay, _sex, _sports);
	return temp;
}




void openFile(fstream & _file, string fileName)
{
	_file.open(fileName + ".txt");
	if (!_file)
	{
		_file.close();
		_file.open(fileName + ".txt", ios::out);
		_file.close();
	}
	_file.close();
	_file.open(fileName + ".txt", ios::out | ios::in | ios::ate);
	_file.seekp(0, ios::end);
}

void closeFile(fstream & _file, string fileName)
{
	_file.close();
}