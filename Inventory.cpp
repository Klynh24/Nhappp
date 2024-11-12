#include "Inventory.h"

Inventory::Inventory() : item_id(0), name("Unknown"), quantity(0), supplier("Unknown"), low_stock_warning(10) {}

Inventory::~Inventory() {}

void Inventory::update_stock(int new_quantity) {
    quantity = new_quantity;
}

bool Inventory::check_infor() const {
    return quantity > low_stock_warning;
}

void Inventory::display_infor() const {
    cout << "Item ID: " << item_id << ", Name: " << name << ", Quantity: " << quantity
         << ", Supplier: " << supplier << ", Low Stock Warning: " << low_stock_warning << endl;
}

int Inventory::getItemId() const {
    return item_id;
}

string Inventory::getName() const {
    return name;
}

int Inventory::getQuantity() const {
    return quantity;
}

string Inventory::getSupplier() const {
    return supplier;
}

int Inventory::getLowStockWarning() const {
    return low_stock_warning;
}

void Inventory::setItemId(int newId) {
    item_id = newId;
}

void Inventory::setName(const string& newName) {
    name = newName;
}

void Inventory::setQuantity(int newQuantity) {
    quantity = newQuantity;
}

void Inventory::setSupplier(const string& newSupplier) {
    supplier = newSupplier;
}

void Inventory::setLowStockWarning(int newWarning) {
    low_stock_warning = newWarning;
}
