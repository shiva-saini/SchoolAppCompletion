#include "ClassB.h"
#include "ClassA.h"
#include <iostream>

ClassA a;

void ClassB::methodB(ClassA &objA) {
    std::cout << "Method B from ClassB calling Method A from ClassA: ";
    objA.methodA();
}