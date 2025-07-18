#include <iostream>
#include <iomanip>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"
using namespace std;


void PrintMenu() {
    cout << "MENU" << endl;
   cout << "a - Add item to cart" << endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl;
   cout << "q - Quit";
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
    cin.ignore();

    if(option == 'a'){
        string name, description;
        int price, quantity;

        cout << "ADD ITEM TO CART" << endl;
        cout << "Enter item name:" << endl;
        getline(cin,name);

        cout <<"Enter item description:" << endl;
        getline(cin,description);

        cout << "Enter the item price:" << endl;
        cin >> price;

        cout << "Enter the item quantity" << endl;
        cin >> quantity;

        
        ItemToPurchase item;
        item.SetName(name);
        item.SetDescription(description);
        item.SetPrice(price);
        item.SetQuantity(quantity);

        theCart.AddItem(item);
    }
    else if(option =='d'){
        string name;
        cin.ignore();
        cout << "REMOVE ITEM FROM CART" << endl;
        cout << "Enter name of item to remove" << endl;
        getline(cin,name);
        theCart.RemoveItem(name);
    }
    else if(option =='c'){
        string name;
        int quantity;
        cin.ignore();
        cout << "CHNAGE ITEM QUANTITY" << endl;
        cout << "Enter the item name:" << endl;
        getline(cin,name);

        cout <<"Enter the new quantity" << endl;
        cin >> quantity;

        ItemToPurchase tempItem;
        tempItem.SetName(name);
        tempItem.SetQuantity(quantity);

        theCart.ModifyItem(tempItem);
    }
    else if(option == 'i'){
        cout << "OUPUT ITEMS' DESCRIPTIONS" << endl;
        theCart.PrintDescriptions();
    }
    else if(option == 'o'){
        cout << "OUTPUT SHOPPING CART" << endl;
        cout << theCart.GetCustomerName() << "'s Shopping Cart - " << theCart.GetDate() << endl;
        cout << "Number of items: " << theCart.GetNumItemsInCart() << endl;
        cout << endl;
        theCart.PrintTotal();
    }
   
}

int main() {
    string CustomerName;
    string Date;

    cout << "Enter customer's name:" << endl;
    getline(cin,CustomerName);
    cout << "Enter today's date:" << endl;
    getline(cin, Date);
    //cout << endl;

    cout << "Customer name: " << CustomerName << endl;
    cout << "Today's date: " << Date << endl;
    cout << endl;

    ShoppingCart cart(CustomerName, Date);
    char option = ' ';
    //PrintMenu();
    while(option != 'q'){
        cout << endl;
        PrintMenu();
        cout << endl << "Choose an option:" << endl;
        cin >> option;

        while(option != 'a' && option != 'd'&& option != 'c' && option != 'i' && option != 'o' && option != 'q'){
            cout << "Choose an option:" << endl;
            cin >> option;
        }

        if(option != 'q'){
        ExecuteMenu(option,cart);
        } while(option != 'q');
    }

   
   
   return 0;
}