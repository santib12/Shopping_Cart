#include "ShoppingCart.h"
#include "ItemToPurchase.h"
#include <iostream>
using namespace std;

ShoppingCart::ShoppingCart(){
    CustomerName = "none";
    CurrentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date){
    CustomerName = name;
    CurrentDate = date;
}

string ShoppingCart::GetCustomerName(){
    return CustomerName;
}

string ShoppingCart::GetDate(){
    return CurrentDate;
}

void ShoppingCart::AddItem(const ItemToPurchase& item){
    cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(const string& itemName){
    bool found = false;
    for(size_t i =0; i < cartItems.size(); i++){
        if(cartItems[i].GetName() == itemName){
            cartItems.erase(cartItems.begin() + i);
            found = true;
            break;
        }
    }
    if(!found){
        cout << "Item not found in cart. Nothing removed" << endl;
    }
}

void ShoppingCart::ModifyItem(const ItemToPurchase& item){
    bool found = false;
    for(size_t i =0; i < cartItems.size(); i++){
        if(cartItems[i].GetName() == item.GetName()){
            found = true;

            if(item.GetDescription() != "none"){
                cartItems[i].SetDescription(item.GetDescription());
            }
            if(item.GetPrice() != 0){
                cartItems[i].SetPrice(item.GetPrice());
            }
            if(item.GetQuantity() != 0){
                cartItems[i].SetQuantity(item.GetQuantity());
            }

            break;
        }
    }
    if(!found){
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}

int ShoppingCart::GetNumItemsInCart(){
    int totalQuant=0;

    for(size_t i =0; i < cartItems.size(); i++){
        totalQuant += cartItems[i].GetQuantity();
    }

    return totalQuant;
}

int ShoppingCart::GetCostOfCart(){
    int totalCost = 0;

    for(size_t i =0; i < cartItems.size(); i ++){
        totalCost += cartItems[i].GetPrice() * cartItems[i].GetQuantity();
    }
    return totalCost;
}

void ShoppingCart::PrintTotal(){
    if(cartItems.empty()){
        cout << "SHOPPING CART IS EMPTY" << endl; 
    }
    else{
        for (size_t i= 0; i < cartItems.size(); i++){
            cout << cartItems[i].GetName()<< " "
            << cartItems[i].GetQuantity() << " @ $"
            << cartItems[i].GetPrice() << " = $"
            << cartItems[i].GetPrice() * cartItems[i].GetQuantity()
            << endl;
        }

    }
    cout << endl << "Total: $" << GetCostOfCart() << endl; 
}

void ShoppingCart::PrintDescriptions(){
    cout << CustomerName << "'s Shopping Cart - " << CurrentDate << endl;
    cout << endl << "Item Descriptions" << endl;

    if(cartItems.empty()){
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    else{
        for(size_t i =0; i < cartItems.size(); i++){
            cartItems[i].PrintItemDescription();
        }
    }
}









