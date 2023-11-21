#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "StudentRecord.h"
using namespace std;





	StudentRecord::StudentRecord()
	{
	}
	StudentRecord::StudentRecord(string id, string firstName, string lastName, int age, string phone, double gpa)
	{
		this->Id = id;
		this->FirstName = firstName;
		this->LastName = lastName;
		this->Age = age;
		this->PhoneNumber = phone;
		this->Gpa = gpa;
	}
	string StudentRecord::getFirst_name()
	{
		return this->FirstName;
	}
	void StudentRecord::setFirst_name(string first_name)
	{
		this->FirstName = first_name;
	}
	string StudentRecord::getLast_name()
	{
		return this->LastName;
	}

	void StudentRecord::setLast_name(string last_name)
	{
		this->LastName = last_name;
	}

	string StudentRecord::getId()
	{
		return this->Id;
	}

	void StudentRecord::setId(string id)
	{
		this->Id = id;
	}
	int StudentRecord::getAge()
	{
		return this->Age;
	}

	void StudentRecord::setAge(int age)
	{
		this->Age = age;
	}
	string StudentRecord::getPhone()
	{
		return this->PhoneNumber;
	}

	void StudentRecord::setPhone(string phone)
	{
		this->PhoneNumber = phone;
	}

	double StudentRecord::getGpa()
	{
		return this->Gpa;
	}

	void StudentRecord::setGpa(double gpa)
	{
		this->Gpa = gpa;
	}
	void StudentRecord::display()
	{
		cout << " Student ID : " << this->getId() << endl;
		cout << " First Name : " << this->getFirst_name() << endl;
		cout << " Last Name : " << this->getLast_name() << endl;
		cout << " Age :" << this->getAge() << endl;
		cout << " Phone Number : " << this->getPhone() << endl;
		cout << " Gpa : " << this->getGpa() << endl;
		cout << endl;
	}
