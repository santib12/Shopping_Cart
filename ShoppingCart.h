#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H
#include <string>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart{
    public:
    ShoppingCart();
    ShoppingCart(string name, string date);
    string GetCustomerName();
    string GetDate();
    void AddItem(const ItemToPurchase& item);
    void RemoveItem(const string& itemName);
    void ModifyItem(const ItemToPurchase& item);
    int GetNumItemsInCart();
    int GetCostOfCart();
    void PrintTotal();
    void PrintDescriptions();

    private:
    string CustomerName;
    string CurrentDate;
    vector<ItemToPurchase> cartItems;

};

#endif