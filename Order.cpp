#include "Order.h"
#include "MenuItem.h"  
#include "Staff.h"      
#include <iostream>
#include <cassert>

using namespace std;

Order::Order() : orderid(0), quantities(0), totalprice(0.0), status("Pending"), createdby(0) {}

Order::~Order() {}

float Order::calculatetotal() const {
    float total = 0.0;
    for (int i = 0; i < items.GetSize(); ++i) {
        total += items[i]->getPrice() * quantities;  
    }
    return total;
}

void Order::update_status(string& new_status) {
    status = new_status;
}

void Order::add_item(const MenuItem* item, int quantity) {
    items.InsertLast(item); 
    quantities += quantity;  
    totalprice = calculatetotal(); 
}

void Order::remove_item(int item_id) {
    for (int i = 0; i < items.GetSize(); ++i) {
        if (items[i]->getId() == item_id) {  
            items.Remove(i);  
            --quantities;  
            totalprice = calculatetotal(); 
            break;
        }
    }
}
