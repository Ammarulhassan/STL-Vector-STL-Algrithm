#include <iostream>

using namespace std;

// Class representing a product
class Product {
public:
    int id;
    string name;
    double price;

    // Default constructor
    Product() : id(0), name(""), price(0.0) {}

    // Constructor to initialize the product
    Product(int _id, const string& _name, double _price) : id(_id), name(_name), price(_price) {}
};

// Class representing the inventory management system
class InventoryManager {
private:
    static const int MAX_PRODUCTS = 100; // Maximum number of products in the inventory
    Product inventory[MAX_PRODUCTS]; // Array to store the products in the inventory
    int numProducts; // Number of products in the inventory

public:
    // Constructor to initialize the inventory
    InventoryManager() : numProducts(0) {}

    // Function to add a new product to the inventory
    void addProduct(int id, const string& name, double price) {
        // Check if the product with the given ID already exists
        for (int i = 0; i < numProducts; ++i) {
            if (inventory[i].id == id) {
                cout << "Product with ID " << id << " already exists. Cannot add duplicate products.\n";
                return;
            }
        }

        // Add the new product to the inventory
        if (numProducts < MAX_PRODUCTS) {
            inventory[numProducts++] = Product(id, name, price);
            cout << "Product added to the inventory.\n";
        }
        else {
            cout << "Cannot add more products. Inventory is full.\n";
        }
    }

    // Function to remove a product based on its ID
    void removeProduct(int id) {
        // Iterate through the inventory to find the product with the given ID
        for (int i = 0; i < numProducts; ++i) {
            if (inventory[i].id == id) {
                // Move the last valid product to the position of the removed product
                inventory[i] = inventory[numProducts - 1];
                --numProducts;

                cout << "Product with ID " << id << " removed from the inventory.\n";
                return;
            }
        }

        // If the product with the given ID is not found
        cout << "Product with ID " << id << " not found in the inventory.\n";
    }

    // Function to display the current inventory
    void displayInventory() {
        cout << "Inventory:\n";
        for (int i = 0; i < numProducts; ++i) {
            cout << "ID: " << inventory[i].id << ", Name: " << inventory[i].name << ", Price: " << inventory[i].price << "\n";
        }
    }
};

int main() {
    // Create an instance of the InventoryManager class
    InventoryManager inventoryManager;

    // Display the current inventory


    // Add some products to the inventory
    inventoryManager.addProduct(1, "NOKIA-1280", 15000);
    inventoryManager.addProduct(2, "IPHONE15", 1599);
    inventoryManager.addProduct(3, "OPOO-F2", 10000);

    // Display the current inventory again
    inventoryManager.displayInventory();

    // Remove a product from the inventory
    inventoryManager.removeProduct(2);

    // Display the updated inventory
    inventoryManager.displayInventory();

    return 0;
}
