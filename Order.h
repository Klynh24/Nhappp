#ifndef ORDER_H
#define ORDER_H

#include "Database.cpp"

class Order {
    private:
      int orderid;
      List <const MenuItem *> items;
      List <Staff *> staffs;
      List <Order> order;
      int quantities;
      double totalprice;
      string status;
      int createdby;
    public:
      Order();
      ~Order();
      float calculatetotal() const;
      void update_status(string& new_status);
      void add_item(const MenuItem* item, int quantity);
      void remove_item(int item_id);
};

#endif