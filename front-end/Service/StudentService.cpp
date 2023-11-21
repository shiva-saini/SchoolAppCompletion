#include "StudentService.h"
#include "../Repository/StudentRepository.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

StudentRepository studentRepository;

void StudentService::addStudentDetails(StudentRecord student){
    studentRepository.addStudentDetails(student);
}

void StudentService::deleteStudentById(string id){
    studentRepository.deleteStudentById(id);
}


void StudentService::updateStudent(StudentRecord updatedStudent){
    studentRepository.updateStudent(updatedStudent);
}

vector<StudentRecord> StudentService::findStudent(string& first_name, string& last_name){
   return studentRepository.findStudent(first_name,last_name);
}

vector<StudentRecord> StudentService::showStudentDetails(){
    return studentRepository.showStudentDetails();
}

vector<StudentRecord> StudentService::giveAllStudentsDetails(){
    vector<StudentRecord> v = studentRepository.giveAllStudentsDetails();
    return v;
}