
#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H

#include <string>
using namespace std;

class StudentRecord {
private:
    string Id;
    string FirstName;
    string LastName;
    int Age;
    string PhoneNumber;
    double Gpa;

public:
    StudentRecord();
    StudentRecord(string id, string firstName, string lastName, int age, string phone, double gpa);

    string getFirst_name();
    void setFirst_name(string first_name);
    string getLast_name();
    void setLast_name(string last_name);
    string getId();
    void setId(string id);
    int getAge();
    void setAge(int age);
    string getPhone();
    void setPhone(string phone);
    double getGpa();
    void setGpa(double gpa);
    void display();
};

#endif
