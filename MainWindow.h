#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//giao diện chính của ứng dụng
#include <QMainWindow>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QInputDialog>
#include "Database.h" // Giả sử bạn đã có file database.h

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void userLoggedIn(const User& user); 

private slots: //Các hàm này sẽ được gọi khi có tín hiệu tương ứng kết nối đến chúng.
    // Login/Logout
    void on_loginButton_clicked();
    void on_logoutButton_clicked();

    // Menu Management
    void on_addMenuItemButton_clicked();
    void on_editMenuItemButton_clicked();
    void on_deleteMenuItemButton_clicked();
    void on_menuListWidget_itemClicked(QListWidgetItem *item); 

    // Order Management
    void on_createOrderButton_clicked();
    void on_viewOrderButton_clicked();
    void on_updateOrderStatusButton_clicked();
    void on_orderListWidget_itemClicked(QListWidgetItem *item); 

    // Staff Management
    void on_addStaffButton_clicked();
    void on_editStaffButton_clicked();
    void on_deleteStaffButton_clicked();
    void on_staffListWidget_itemClicked(QListWidgetItem *item); 

    // Customer Management
    void on_addCustomerButton_clicked();
    void on_editCustomerButton_clicked();
    void on_deleteCustomerButton_clicked();
    void on_customerListWidget_itemClicked(QListWidgetItem *item); 

    // Inventory Management
    void on_addInventoryItemButton_clicked();
    void on_editInventoryItemButton_clicked();
    void on_deleteInventoryItemButton_clicked();
    void on_inventoryListWidget_itemClicked(QListWidgetItem *item); 

    // Table Management
    void on_addTableButton_clicked();
    void on_editTableButton_clicked();
    void on_deleteTableButton_clicked();
    void on_tableListWidget_itemClicked(QListWidgetItem *item); 

private:
    Database db;
    User currentUser; 

    // Helper functions
    void showLoginDialog();
    void showMenuManagementWidget();
    void showOrderManagementWidget();
    void showStaffManagementWidget();
    void showCustomerManagementWidget();
    void showInventoryManagementWidget();
    void showTableManagementWidget();
    void showError(const QString& message);
    void loadMenuItems(); 
    void loadOrders(); 
    void loadStaff(); 
    void loadCustomers(); 
    void loadInventoryItems(); 
    void loadTables(); 
    void refreshUI(); 

    // Input dialogs
    void showAddMenuItemDialog();
    void showEditMenuItemDialog(int menuItemId);
    void showAddOrderDialog();
    void showEditOrderStatusDialog(int orderId);
    void showAddStaffDialog();
    void showEditStaffDialog(int staffId);
    void showAddCustomerDialog();
    void showEditCustomerDialog(int customerId);
    void showAddInventoryItemDialog();
    void showEditInventoryItemDialog(int inventoryItemId);
    void showAddTableDialog();
    void showEditTableDialog(int tableId);
};
#endif // MAINWINDOW_H