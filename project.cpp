#include <iostream>
#include <string>
using namespace std;
// Defining a Structure
struct Item{
    int id;
    string name;
    int quantity;
    float price;
};

// Defining Function to Add Item
void addItem(Item inventory[], int &itemCount){
    cout << endl;
    cout << "Enter item ID: ";
    cin >> inventory[itemCount].id;
    cin.ignore(); // to ignore \n character left in cin buffer
    cout << "Enter item Name: ";
    getline(cin, inventory[itemCount].name);
    cout << "Enter item Quantity: ";
    cin >> inventory[itemCount].quantity;
    cout << "Enter item price: PKR";
    cin >> inventory[itemCount].price;

    //incrementing itemCount
    itemCount++;
    cout << "Item Added Successfully!" << endl;
}

// Defining Function to Display Inventory
void diplay(const Item inventory[], int itemCount){
    cout << endl;
    cout << "--- Inventory List ---" << endl;
    for(int i = 0; i<itemCount; i++){
        cout << "ID: " << inventory[i].id ;
        cout << ", Name: " << inventory[i].name ;
        cout << ", Quantity: " << inventory[i].quantity ;
        cout << ", Price: PKR " << inventory[i].price << endl ;
    }
}
// Defining Function to Search Item
void search(const Item inventory[], int itemCount){
    // Searching via ID
    int id;
    cout << endl;
    cout << "Enter Item ID to Search: ";
    cin >> id;

    // Using flag 
    bool found = false;
    for(int i = 0; i< itemCount; i++){
        // validating if user input id matches with any id in inventory
        if(inventory[i].id== id){
            cout << "Item Found: " << endl;
            cout << "ID: " << inventory[i].id;
            cout << ", Name: " << inventory[i].name;
            cout << ", Price: PKR " << inventory[i].price << endl;
            found = true; // making flag true
            break;
        }
    }
    // if id not found
    if(!found){
        cout << "Item with ID " << id << " not found." << endl;
    }
}
// Defining Function to update the item's quantity
void update(Item inventory[], int itemCount){
    int id, newQuantity;
    cout << endl;
    cout << "Enter item ID to update Quantity: " ;
    cin >> id;

    // Using flag to find the item and then update
    bool found = false;
    for(int i = 0; i< itemCount; i++){
        if(inventory[i].id == id){
            cout << "Current quantity of " << inventory[i].name << ": " << inventory[i].quantity << endl;
            cout << "Enter new quantity: " ;
            cin >> newQuantity;
            inventory[i].quantity = newQuantity;
            cout << "Quantity updated Successfully!" << endl;
            found = true;
            break;
        }
    }
    // checking if not found 
    if(!found){
        cout << "Item with ID " << id << "not found." << endl;
    }
}
// making function to delete item
void deleteItem(Item inventory[], int &itemCount){
    int id;
    cout << endl;
    cout << "Enter item ID to delete: ";
    cin >> id;

    int index = -1;
    for(int i = 0; i< itemCount; i++){
        if(inventory[i].id == id){
            index = i;
            break;
        }
    }
    if(index == -1){
        cout << "Item with ID " << id << " not found." << endl;
    }else {
        // shifting items to fill the gap of deleted item
        for(int i = index; i<itemCount-1; i++){
            inventory[i] = inventory[i+1];
        }
        itemCount--;
        cout << "Item deleted Successfully!" << endl;
    }
}
int main(){
    const int maxItem = 100;
    Item inventory[maxItem];
    int itemCount=0;
    int choice;
    // Displaying Menu
    do{
        cout << endl;
        cout << "--- Inventory Management System ---" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Display Inventory" << endl;
        cout << "3. Search Item" << endl;
        cout << "4. Update Item Quantity" << endl;
        cout << "5. Delete Item" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Accessing specific Task from Menu Using Switch
        switch (choice){
            case 1:
                addItem(inventory, itemCount);
                break;
            case 2:
                diplay(inventory,itemCount);
                break;
            case 3:
                search(inventory,itemCount);
                break;
            case 4:
                update(inventory,itemCount);
                break;
            case 5:
                deleteItem(inventory,itemCount);
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }while(choice!=6);
    

    return 0;

}