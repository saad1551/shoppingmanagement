#include <iostream>
#include <string>
#include <vector>

#define CURRENTYEAR 2023
#define CURRENTMONTH 5
#define CURRENTDAY 3

using namespace std;

class Order;
vector<Order> Orders;

class Date
{
    friend class Order;
    int day;
    int month;
    int year;
    public:
    Date()
    {
        day = CURRENTDAY;
        month = CURRENTMONTH;
        year = CURRENTYEAR;
    }
    void PrintDate()
    {
        cout << day << "/" << month << "/" << year;
    }
};

class Authentication
{
    string username;
    string password;

    public:
    Authentication();
    ~Authentication();
    void CheckUserName(string username);
    void CheckPassword(string password);
};


class Inventory
{
    static int no_of_Products;
    protected:
    static vector<string> Products;
    friend class Order;
    public:
    virtual void AddProduct(string productName);
    virtual void RemoveProduct() = 0;

};

class Product: public Inventory
{
    friend class Order;

    string productName;
    double productPrice;
    static int productQuantity;
    string productDescription;

    public:
    Product();
    ~Product();
    virtual void AddProduct(string productName);
    void EditProduct();
    virtual void RemoveProduct();
};

class Order
{
    static int orderCount;
    Date orderDate;
    vector<string> OrderedProducts;
    int orderNumber;
    string customerName;
    string customerContact;
    string customerAddress;

    public:
    Order();
    friend void ShowOrderHistory(string customerName);
};

