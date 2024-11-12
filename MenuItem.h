#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
#include <string>
#include "Inventory.h" 

using namespace std;

class MenuItem {
private:
    List<Inventory *> status_inventory;  
    List<MenuItem *> menuitem;            
    int id;                              
    string name;                          
    float price;                         
    string category;                      
    int availability;                     

public:
    MenuItem();

    ~MenuItem();
    void updateavailability(int new_availability);
    void displayinfo() const;
    int getId() const;

    string getName() const;
    float getPrice() const;
    string getCategory() const;
    int getAvailability() const;

    void setName(const string& newName);
    void setPrice(float newPrice);
    void setCategory(const string& newCategory);
    void setAvailability(int newAvailability);
};

#endif
