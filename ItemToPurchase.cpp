#include <iostream>
using namespace std;
#include "ItemToPurchase.h"

//default constructor
ItemToPurchase::ItemToPurchase(){
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
    itemDescription = "none";
}

ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity){
    itemName = name;
    itemDescription = description;
    itemPrice = price;
    itemQuantity = quantity;
}

void ItemToPurchase::SetName(string name){
    itemName = name;
}

string ItemToPurchase::GetName()const{
    return itemName;
}

void ItemToPurchase::SetPrice(int price){
    itemPrice = price;
}

int ItemToPurchase::GetPrice()const{
    return itemPrice;
}

void ItemToPurchase::SetQuantity(int quantity){
    itemQuantity = quantity;
}

int ItemToPurchase::GetQuantity()const{
    return itemQuantity;
}

void ItemToPurchase::SetDescription(string description){
    itemDescription = description;
}

string ItemToPurchase::GetDescription()const{
    return itemDescription;
}

void ItemToPurchase::PrintItemCost(string name, int quantity, int price){
    // outputs items name followed by quantity,price and subtotal
    int total = quantity * price;
    cout << name << " " << quantity << " $" << price << " = $" << total;
}

void ItemToPurchase::PrintItemDescription()const{
    //outputs item name and description 
    cout << itemName << ": " << itemDescription << endl;
}

