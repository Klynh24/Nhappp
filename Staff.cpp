#include "Staff.h"
#include <iostream>
using namespace std;

Staff::Staff() : staffid(0), name("Unknown"), position("Unknown"), salary(0.0f), shift("Unknown") {}

Staff::~Staff() {}

void Staff::displayInfo() const {
    cout << "Staff ID: " << staffid << endl;
    cout << "Name: " << name << endl;
    cout << "Position: " << position << endl;
    cout << "Salary: " << salary << endl;
    cout << "Shift: " << shift << endl;
}

void Staff::updateSalary(float new_salary) {
    salary = new_salary;
}

void Staff::assignShift(const string& new_shift) {
    shift = new_shift;
}

void Staff::addStaff(Staff* staff) {
    staffList.InsertLast(staff); 
}

void Staff::removeStaff(int staffid) {
    for (int i = 0; i < staffList.GetSize(); ++i) {
        if (staffList[i]->getStaffId() == staffid) {  
            staffList.Remove(i); 
            break;
        }
    }
}

int Staff::getStaffId() const {
    return staffid;
}

string Staff::getName() const {
    return name;
}

string Staff::getPosition() const {
    return position;
}

float Staff::getSalary() const {
    return salary;
}

string Staff::getShift() const {
    return shift;
}
