#ifndef STAFF_H
#define STAFF_H

#include "List.h"
#include "Order.h"  

class Staff {
private:
    List<Staff*> staffList;    
    int staffid;               
    string name;               
    string position;           
    float salary;              
    string shift;              
    List<Order*> order;        

public:
    Staff();
    ~Staff();
    
    void displayInfo() const;           
    void updateSalary(float new_salary); 
    void assignShift(const string& new_shift); 
    void addStaff(Staff* staff);         
    void removeStaff(int staffid);      

    int getStaffId() const;             
    string getName() const;             
    string getPosition() const;          
    float getSalary() const;             
    string getShift() const;             
};

#endif
