#ifndef DATABASE_H
#define DATABASE_H
// file này dùng để: để quản lý kết nối và tương tác với cơ sở dữ liệu SQLite trong dự án 
#include <iostream>
#include <string>
#include <sqlite3.h>
#include <stdexcept>
#include <optional> 

#include "User.h"
#include "MenuItem.h"
#include "Order.h"
#include "Staff.h"
#include "Inventory.h"
#include "bcrypt.h" 
#include "List.h" 

using namespace std;

class Database {
private:
    sqlite3 *db;
    string dbFileName; 

    bool executeQuery(const string& query, const string& errorMessage);
    int getLastInsertedId();

public:
    Database();
    ~Database();

    bool openDatabase(const string& filename); //Mở kết nối với cơ sở dữ liệu có tên file 
    void closeDatabase(); //Đóng kết nối với cơ sở dữ liệu.

    /* Giải thích về optional:
        Phương thức như addUser, getUser, updateUser trả về optional<User>. 
        Điều này có nghĩa là thay vì trả về một đối tượng người dùng trực tiếp, 
        phương thức có thể trả về một giá trị hợp lệ (User) hoặc không có giá trị nào (thông qua nullopt).

        optional cho phép bạn xử lý các trường hợp không tìm thấy dữ liệu 
        mà không cần dùng con trỏ nullptr hoặc giá trị không xác định, giúp mã nguồn trở nên an toàn hơn.*/

    // === User ===
    optional<User> addUser(const User& user);
    optional<User> updateUser(const User& user);
    bool deleteUser(int user_id);
    optional<User> getUser(int user_id);
    optional<User> getUserByUsername(const string& username);
    bool authenticate(const string& username, const string& password); 

    // === MenuItem ===
    optional<MenuItem> addMenuItem(const MenuItem& item);
    optional<MenuItem> updateMenuItem(const MenuItem& item);
    bool deleteMenuItem(int item_id);
    optional<MenuItem> getMenuItem(int item_id);
    List<MenuItem> getAllMenuItems(); 

    // === Order ===
    optional<Order> addOrder(const Order& order);
    optional<Order> updateOrder(const Order& order);
    bool deleteOrder(int order_id);
    optional<Order> getOrder(int order_id);
    List<Order> getAllOrders(); 

    // === Staff ===
    optional<Staff> addStaff(const Staff& staff);
    optional<Staff> updateStaff(const Staff& staff);
    bool deleteStaff(int staff_id);
    optional<Staff> getStaff(int staff_id);
    List<Staff> getAllStaff(); 


    // === Inventory ===
    optional<Inventory> addInventoryItem(const Inventory& item);
    optional<Inventory> updateInventoryItem(const Inventory& item);
    bool deleteInventoryItem(int item_id);
    optional<Inventory> getInventoryItem(int item_id);
    List<Inventory> getAllInventoryItems(); 

};

#endif