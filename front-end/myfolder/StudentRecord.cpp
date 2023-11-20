#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "StudentRecord.h"
using namespace std;

class StudentRecord
{
private:
	string Id;
	string FirstName;
	string LastName;
	int Age;
	string PhoneNumber;
	double Gpa = 0.0;


public:
	StudentRecord()
	{
	}
	StudentRecord(string id, string firstName, string lastName, int age, string phone, double gpa)
	{
		this->Id = id;
		this->FirstName = firstName;
		this->LastName = lastName;
		this->Age = age;
		this->PhoneNumber = phone;
		this->Gpa = gpa;
	}
	string getFirst_name()
	{
		return this->FirstName;
	}
	void setFirst_name(string first_name)
	{
		this->FirstName = first_name;
	}
	string getLast_name()
	{
		return this->LastName;
	}

	void setLast_name(string last_name)
	{
		this->LastName = last_name;
	}

	string getId()
	{
		return this->Id;
	}

	void setId(string id)
	{
		this->Id = id;
	}
	int getAge()
	{
		return this->Age;
	}

	void setAge(int age)
	{
		this->Age = age;
	}
	string getPhone()
	{
		return this->PhoneNumber;
	}

	void setPhone(string phone)
	{
		this->PhoneNumber = phone;
	}

	double getGpa()
	{
		return this->Gpa;
	}

	void setGpa(double gpa)
	{
		this->Gpa = gpa;
	}
	void display()
	{
		cout << " Student ID : " << this->getId() << endl;
		cout << " First Name : " << this->getFirst_name() << endl;
		cout << " Last Name : " << this->getLast_name() << endl;
		cout << " Age :" << this->getAge() << endl;
		cout << " Phone Number : " << this->getPhone() << endl;
		cout << " Gpa : " << this->getGpa() << endl;
		cout << endl;
	}
};