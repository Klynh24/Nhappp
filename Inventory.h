#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include "MenuItem.h"  
#include "List.h"

using namespace std;

class Inventory {
private:
    List<Inventory *> inventory;  
    List<MenuItem *> menuitem;    
    int item_id;                  
    string name;                  
    int quantity;                 
    string supplier;              
    int low_stock_warning;        

public:
    Inventory();
    ~Inventory();
    void update_stock(int new_quantity);
    bool check_infor() const;
    void display_infor() const;

    int getItemId() const;
    string getName() const;
    int getQuantity() const;
    string getSupplier() const;
    int getLowStockWarning() const;

    void setItemId(int newId);
    void setName(const string& newName);
    void setQuantity(int newQuantity);
    void setSupplier(const string& newSupplier);
    void setLowStockWarning(int newWarning);
};

#endif
