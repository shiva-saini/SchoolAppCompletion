#ifndef STUDENTREPOSITORY_H
#define STUDENTREPOSITORY_H
#include "../myfolder/StudentRecord.h"
#include <vector>
#include <string>

class StudentRepository {
public:
    vector<StudentRecord> showStudentDetails();
    vector<StudentRecord> findStudent(string& first_name, string& last_name);
    void updateStudentInfo(std::vector<StudentRecord>& students, StudentRecord& updatedStudent);
    void updateStudent(StudentRecord updatedStudent);
    vector<StudentRecord> giveAllStudentsDetails();
    void deleteStudentById(string id);
    void writeStudentToCSV(const std::string& filename, StudentRecord& student);
    void addStudentDetails(StudentRecord &student);
};

#endif // REPOSITORY_H