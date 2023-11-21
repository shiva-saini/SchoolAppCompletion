// Service.h
#ifndef STUDENTSERVICE_H
#define STUDENTSERVICE_H
#include "../Repository/StudentRepository.h"
#include <vector>
#include <string>

class StudentService {
private:
    StudentRepository repository;

public:
    void addStudentDetails(StudentRecord student);
    void deleteStudentById(string id);
    void updateStudent(StudentRecord updatedStudent);
    vector<StudentRecord> giveAllStudentsDetails();
    // this will give all the students to the front-end and front-end will show these students
    vector<StudentRecord> findStudent(string& first_name, string& last_name);
    // this will give all the students that are there in the data base and front-end will show them
    // this will give the details of all the students
    vector<StudentRecord> showStudentDetails();
};

#endif // SERVICE_H
