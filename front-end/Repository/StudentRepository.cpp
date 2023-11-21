// Repository.cpp
#include "StudentRepository.h"
#include "../myfolder/StudentRecord.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


void StudentRepository::updateStudentInfo(std::vector<StudentRecord>& students, StudentRecord& updatedStudent)
		{
			for (StudentRecord& student : students)
			{
				if (student.getId() == updatedStudent.getId())
				{
					student.setId(updatedStudent.getId());
					student.setFirst_name(updatedStudent.getFirst_name());
					student.setLast_name(updatedStudent.getLast_name());
					student.setAge(updatedStudent.getAge());
					break;
				}
			}

			std::string filename = "../data.csv";
			std::ofstream file(filename, std::ios::out);
			for (StudentRecord student : students)
			{
				addStudentDetails(student);
			}
}
vector<StudentRecord> StudentRepository::showStudentDetails()
		{
            // showing part front-end will handle
			vector<StudentRecord> allStudents = giveAllStudentsDetails();
            return allStudents;
			// if (allStudents.size() == 0)
			// {
			// 	cout << "No records found!!" << endl;
			// }
			// else
			// {
			// 	for (StudentRecord student : allStudents)
			// 	{
			// 		student.display();
			// 	}
			// }
		}
void StudentRepository::updateStudent(StudentRecord updatedStudent)
		{
			
			vector<StudentRecord> allStudents = giveAllStudentsDetails();
			// cout << allStudents.size() << endl;
			bool f = false;
			for (StudentRecord& student : allStudents)
			{
				cout << student.getId() << endl;
				if (student.getId() == updatedStudent.getId())
				{
					updateStudentInfo(allStudents, updatedStudent);
					f = true;
					break;
				}

			}

			if (f == false) {

				cout << "Student with this id doesn't exist in our databse" << endl;
				return;

			}else 
				cout << "Student updated successfully" << endl;
		}

vector<StudentRecord> StudentRepository::giveAllStudentsDetails()
		{
			ifstream inputFile;
			inputFile.open("../data.csv");
			string line;
			vector<StudentRecord> allStudents;
			while (getline(inputFile, line))
			{
				string studentId;
				string firstName;
				string lastName;
				int age;
				string phoneNumber;
				double gpa;
				string tempString;
				stringstream inputString(line);
				getline(inputString, studentId, ',');
				getline(inputString, lastName, ',');
				getline(inputString, firstName, ',');
				getline(inputString, tempString, ',');
				age = atoi(tempString.c_str());
				getline(inputString, phoneNumber, ',');
				tempString = "";
				getline(inputString, tempString, ',');
				gpa = atof(tempString.c_str());
				StudentRecord student(studentId, firstName, lastName, age, phoneNumber, gpa);
				allStudents.push_back(student);
				line = "";
			}

			return allStudents;
}

vector<StudentRecord> StudentRepository::findStudent(string& first_name, string& last_name)
{


    // if (first_name == "" || last_name == "")
    // {
    //     cout << "Name cannot be empty!!" << endl;
    //     return;
    // }
    vector<StudentRecord> allStudents = giveAllStudentsDetails();
    string fName = "", lName = "";
    for (int i = 0; i < first_name.size(); i++)
    {
        fName += tolower(first_name[i]);
    }
    for (int i = 0; i < last_name.size(); i++)
    {
        lName += tolower(last_name[i]);
    }

    vector<StudentRecord> searchedStudents;
    for (StudentRecord student : allStudents)
    {
        string fNameDb = "";
        string lNameDb = "";
        for (int i = 0; i < student.getFirst_name().size(); i++)
        {
            fNameDb += tolower(student.getFirst_name()[i]);
        }
        for (int i = 0; i < student.getLast_name().size(); i++)
        {
            lNameDb += tolower(student.getLast_name()[i]);
        }

        if (fNameDb == fName && lNameDb == lName)
        {
            searchedStudents.push_back(student);
        }
    }
    return searchedStudents;
   
}


void StudentRepository::deleteStudentById(string id)
		{
			if (id == "")
			{
				cout << "Enter a valid id" << endl;
				return;
			}
			vector<StudentRecord> allStudents = giveAllStudentsDetails();
			vector<StudentRecord> allUpdatedStudents;

			for (StudentRecord student : allStudents)
			{
				if (student.getId() == id)
				{
					continue;
				}
				if (student.getId() < id)
				{
					allUpdatedStudents.push_back(student);
				}
				else
				{
					int x = atoi(student.getId().c_str());
					x -= 1;
					student.setId(to_string(x));
					allUpdatedStudents.push_back(student);
				}
			}

			std::string filename = "../data.csv";
			std::ofstream file(filename, std::ios::out);
			for (StudentRecord student : allUpdatedStudents)
			{
				addStudentDetails(student);
			}
}

void StudentRepository::writeStudentToCSV(const std::string& filename, StudentRecord& student)
			{
				std::ofstream file(filename, std::ios::app); // Open the file in append mode
				// if(opn == false){
				//     file<<"\n";
				//     opn = true;
				// }
				if (file.is_open())
				{
					// Write student details to the CSV file
					file << student.getId() << "," << student.getLast_name() << "," << student.getFirst_name() << "," << student.getAge() << "," << student.getPhone() << "," << student.getGpa() << "\n";

					// Close the file
					file.close();
					std::cout << "Student details written to " << filename << std::endl;
				}
				else
				{
					std::cerr << "Unable to open the file " << filename << std::endl;
				}
			}
void StudentRepository::addStudentDetails(StudentRecord &student){
    std::string filename = "../data.csv";
	writeStudentToCSV(filename, student);
}


