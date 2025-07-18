#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase{
    public:
    ItemToPurchase();
    ItemToPurchase(string name, string description, int price, int quantity);
    void SetName(string name);
    string GetName()const;
    void SetPrice(int price);
    int GetPrice()const;
    void SetQuantity(int quantity);
    int GetQuantity()const;
    void SetDescription(string description); // new member function 
    string GetDescription()const; //new memeber function 
    void PrintItemCost(string name, int quantity, int price); // new memeber function 
    void PrintItemDescription()const; // new member function 


    private:
    string itemName;
    int itemPrice;
    int itemQuantity;
    string itemDescription;
};

#endif