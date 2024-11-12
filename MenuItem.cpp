#include "MenuItem.h"

MenuItem::MenuItem() : id(0), name("Unknown"), price(0.0f), category("Unknown"), availability(0) {}

MenuItem::~MenuItem() {}
void MenuItem::updateavailability(int new_availability) {
    availability = new_availability;
}

void MenuItem::displayinfo() const {
    cout << "ID: " << id << ", Name: " << name << ", Price: " << price
         << ", Category: " << category << ", Availability: " << availability << endl;
}

int MenuItem::getId() const {
    return id;
}

string MenuItem::getName() const {
    return name;
}

float MenuItem::getPrice() const {
    return price;
}

string MenuItem::getCategory() const {
    return category;
}

int MenuItem::getAvailability() const {
    return availability;
}

void MenuItem::setName(const string& newName) {
    name = newName;
}

void MenuItem::setPrice(float newPrice) {
    price = newPrice;
}

void MenuItem::setCategory(const string& newCategory) {
    category = newCategory;
}

void MenuItem::setAvailability(int newAvailability) {
    availability = newAvailability;
}
