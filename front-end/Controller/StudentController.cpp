#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "../myfolder/StudentRecord.h"
#include "../Service/StudentService.h"
using namespace std;

string generateId()
{
	StudentService studentService;
	vector<StudentRecord> allStudents = studentService.giveAllStudentsDetails();
	long long int n = allStudents.size();
	int id = n > 0 ? stoi(allStudents[n - 1].getId()) : 0;
	return to_string(id + 1);
}

StudentRecord inputDetails()
{
	string id = generateId();
	string first_name;
	string last_name;
	int age;
	string phone;
	double gpa;
	cout << "Enter First Name : " << endl;
	cin >> first_name;
	cout << "Enter Last Name : " << endl;
	cin >> last_name;
	cout << "Enter age : " << endl;
	cin >> age;
	cout << "Enter Phone : " << endl;
	cin >> phone;
	cout << "Enter Gpa : " << endl;
	cin >> gpa;
	StudentRecord student(id, last_name, first_name, age, phone, gpa);
	return student;
}


StudentRecord inputDetailsToUpdate()
	{
		string id;
		string first_name;
		string last_name;
		int age;
		string phone = "";
		double gpa = 0.00;
		cout << "Enter student Id : " << endl;
		cin >> id;
		cout << "Enter First Name : " << endl;
		cin >> first_name;
		cout << "Enter Last Name : " << endl;
		cin >> last_name;
		cout << "Enter age : " << endl;
		cin >> age;
		StudentRecord student(id, last_name, first_name, age, phone,gpa);
		return student;
	}

int main()
{
	bool f = false;
    StudentService studentService;
	while (1) {

		cout << "-------------------------------------Welcome to School App-----------------------------------" << endl;
		cout << endl;
		cout << endl;
		cout << "Enter 0 to enter the help menu" << endl;
		cout << endl;
		int help;
		cin >> help;
		if (help == 0)
		{
			cout << "----HELP MENU-----" << endl;
			cout << "1 . Add Student " << endl;
			cout << "2 . Delete Student by id" << endl;
			cout << "3 . Modify Student by Name and Age " << endl;
			cout << "4 . Search Student by name " << endl;
			cout << "5 . Show all the students " << endl;
			cout << "6 . Exit " << endl;
			cout << "Enter your choice" << endl;
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 1:
				//this input details will be called at the front - end side and front - end will send this to middleware and then middle ware will call it and pass student object
				studentService.addStudentDetails(inputDetails());
				break;
			case 2:
                {
                    //first front-end will take id , which has to be deleted and then front-end will pass this id to middle ware the middle ware will call the function and pass this id to that function
                    string id;
                    cout<<"Enter student's id"<<endl;
                    cin>>id;
                    studentService.deleteStudentById(id);
                    // cout << "Student Deleted successfully" << endl;
                }

			break;
			case 3:
                {   
                    // front - end will take the data to be updated and then pass it to middle ware then middle ware will call this function and pass the student's data which has to be updated
                    studentService.updateStudent(inputDetailsToUpdate());
                    // cout<<"Student Updated"<<endl;
                    
                }
			break;
			case 4:
                {
                    // front-end will take data from the user and pass it to middleware and then middle ware will pass this data to back-end and back-end will return valid students
                    string first_name;
                    string last_name;
                    cout << "Enter first name" << endl;
                    cin >> first_name;
                    cout << "Enter last name" << endl;
                    cin >> last_name;
                    vector<StudentRecord> students = studentService.findStudent(first_name, last_name);
                    cout<<"All the students with the given name"<<endl;
                    for(StudentRecord st:students){
                        st.display();
                        cout<<endl;
                    }
                }
			break;
			case 5:
				//this funtion will be called by front end and then middlware will call this function and back-end will return all the data to middle ware and middleware will pass this data to front-end and then front - end will show this data or we can show this data in middleware it self
               {
                    vector<StudentRecord> all = studentService.giveAllStudentsDetails();
                    for(StudentRecord st:all){
                        st.display();
                        cout<<endl;
                    }
               }
                
				break;
			case 6:
				f = true;
				exit(0);
				break;
			default:
				break;
			}
		}
		if (f) {
			break;
		}
	}
}