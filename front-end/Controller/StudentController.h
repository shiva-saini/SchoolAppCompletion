// Controller.h
#ifndef STUDENTCONTROLLER_H
#define STUDENTCONTROLLER_H
#include "../Service/StudentService.h"
#include <string>

class StudentController {

private:
    StudentService service;
    
public:
    void handleUserInput(const std::string &input);
    void displayAllData();
    
};

#endif // CONTROLLER_H
