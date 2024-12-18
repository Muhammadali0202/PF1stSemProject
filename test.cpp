#include <iostream>
#include <string>
using namespace std;

// Define a structure for items
struct Item {
    int id;
    string name;
    int quantity;
    float price;
};

// Function to add an item to inventory
void addItem(Item inventory[], int &itemCount) {
    cout << "\nEnter item ID: ";
    cin >> inventory[itemCount].id;
    cin.ignore(); // To ignore newline character left in input buffer
    cout << "Enter item name: ";
    getline(cin, inventory[itemCount].name);
    cout << "Enter item quantity: ";
    cin >> inventory[itemCount].quantity;
    cout << "Enter item price: ";
    cin >> inventory[itemCount].price;

    itemCount++;
    cout << "Item added successfully!\n";
}

// Function to display all items in inventory
void displayInventory(const Item inventory[], int itemCount) {
    cout << "\n--- Inventory List ---\n";
    for (int i = 0; i < itemCount; i++) {
        cout << "ID: " << inventory[i].id
             << ", Name: " << inventory[i].name
             << ", Quantity: " << inventory[i].quantity
             << ", Price: $" << inventory[i].price << endl;
    }
}

// Function to search for an item by ID
void searchItem(const Item inventory[], int itemCount) {
    int id;
    cout << "\nEnter item ID to search: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            cout << "Item found: "
                 << "ID: " << inventory[i].id
                 << ", Name: " << inventory[i].name
                 << ", Quantity: " << inventory[i].quantity
                 << ", Price: $" << inventory[i].price << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Item with ID " << id << " not found.\n";
    }
}

// Function to update an item's quantity
void updateItemQuantity(Item inventory[], int itemCount) {
    int id, newQuantity;
    cout << "\nEnter item ID to update quantity: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            cout << "Current quantity of " << inventory[i].name << ": " << inventory[i].quantity << endl;
            cout << "Enter new quantity: ";
            cin >> newQuantity;
            inventory[i].quantity = newQuantity;
            cout << "Quantity updated successfully!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Item with ID " << id << " not found.\n";
    }
}

// Function to delete an item by ID
void deleteItem(Item inventory[], int &itemCount) {
    int id;
    cout << "\nEnter item ID to delete: ";
    cin >> id;

    int index = -1;
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Item with ID " << id << " not found.\n";
    } else {
        // Shift items to fill the gap left by the deleted item
        for (int i = index; i < itemCount - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        itemCount--;
        cout << "Item deleted successfully!\n";
    }
}

// Main function
int main() {
    const int MAX_ITEMS = 100;
    Item inventory[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    do {
        cout << "\n--- Inventory Management System ---\n";
        cout << "1. Add Item\n";
        cout << "2. Display Inventory\n";
        cout << "3. Search Item\n";
        cout << "4. Update Item Quantity\n";
        cout << "5. Delete Item\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem(inventory, itemCount);
                break;
            case 2:
                displayInventory(inventory, itemCount);
                break;
            case 3:
                searchItem(inventory, itemCount);
                break;
            case 4:
                updateItemQuantity(inventory, itemCount);
                break;
            case 5:
                deleteItem(inventory, itemCount);
                break;
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
