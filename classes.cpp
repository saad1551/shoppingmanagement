#include <iostream>
#include <string>
#include "classes.h"

using namespace std;

Authentication::Authentication()
{
    username = "saadashraf";
    password = "12345678";
}

Authentication::~Authentication()
{

}

void Authentication::CheckUserName(string username)
{
    if (this->username.compare(username) != 0)
    {
        cout << "This username doesn't exist";
    }
}

void Authentication::CheckPassword(string password)
{
    if (this->password.compare(password) != 0)
    {
        cout << "Incorrect Password";
    }
}

Product::Product()
{
    cout << "Enter Product name: ";
    getline(cin, productName);

    cout << "Enter Product price: ";
    cin >> productPrice;

    cout << "Enter Product quantity: ";
    cin >> productQuantity;

    cout << "Add Product Description: ";
    getline(cin, productDescription);
}

Product::~Product()
{
    cout << productName << " removed from the store inventory";
}

void Product::EditProduct()
{
    while(1)
    {
        int editChoice;
        cout << "Choose an attribute to edit\n";
        cout << "1: Name\n2:Price\n3:Quantity\n4:Description\n5:Close Editor\n";
        cin >> editChoice;

        int editorCloser = 0;

        switch(editChoice)
        {
            case 1:
                cout << "Enter Product name: ";
                getline(cin, productName);
                break;

            case 2:
                cout << "Enter Product price: ";
                cin >> productPrice;
                getline(cin, productName);
                break;

            case 3:     
                cout << "Enter Product quantity: ";
                cin >> productQuantity;
                break;

            case 4:
                cout << "Add Product Description: ";
                getline(cin, productDescription);
                break;

            case 5:
                editorCloser = 1;
                break;
        }

        if (editorCloser == 1)
        {
            break;
        }
    }
}

void Product::RemoveProduct()
{
    Product::~Product();
}

void Inventory::AddProduct(string productName)
{
    Products.push_back(productName);
    no_of_Products++;
}

void Product::RemoveProduct()
{
    for (int i = 0; i < Products.size(); i++)
    {
        if (Products[i].compare(productName) == 0)
        {
            Products.erase(Products.begin() + i);
        }
    }
}

Order::Order()
{
    orderNumber = ++orderCount;

    cout << "Enter Customer Name: ";
    getline(cin, customerName);

    while(1)
    {
        cout << "Enter Customer Contact Number: (without spaces) ";
        getline(cin, customerContact);

        int phoneChecker = 0;
        for (int i = 0; i < customerContact.size(); i++)
        {
            if (!isdigit(customerContact[i]))
            {
                phoneChecker++;
            }
        }
        if (phoneChecker == customerContact.size())
        {
            break;
        }
        else
        {
            cout << "Invalid phone number entered";
        }
    }

    int productChoice;
    while (1)
    {
        cout << "Choose a product\n";
        int i;
        for (i = 1; i <= Inventory::Products.size(); i++)
        {
            cout << i << ": " << Inventory::Products[i]; 
        }
        cout << i << ": Exit";
        cin >> productChoice;
        if (productChoice <= 0 || productChoice > Inventory::Products.size() + 1)
        {
            cout << "Invalid Choice";
            continue;
        }
        if (productChoice == Inventory::Products.size() + 1)
        {
            break;
        }
        else
        {
            OrderedProducts.push_back(Inventory::Products[productChoice]);
        }
    }
    cout << "Enter Customer Address: ";
    getline(cin, customerAddress);
};

void ShowOrderHistory(string Name)
{
    for (int i = 0; i < Orders.size(); i++)
    {
        if (Orders[i].customerName.compare(Name) == 0)
        {
            cout << "Order Date: ";
            Orders[i].orderDate.PrintDate();
            cout << "Products Ordered: ";
            for (int j = 0; j < Orders[i].OrderedProducts.size(); j++)
            {
                cout << " " << Orders[i].OrderedProducts[j];
            }
        }
    }
}