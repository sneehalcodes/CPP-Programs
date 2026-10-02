#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int productId;
    string productName;
    float price;
    int monthlySales[12];
    int totalQuantity;
    float totalBill;

public:
    void acceptDetails() {
        cout << "Enter Product ID: ";
        cin >> productId;
        cin.ignore();

        cout << "Enter Product Name: ";
        getline(cin, productName);

        cout << "Enter Price per unit: ";
        cin >> price;

        cout << "Enter monthly sales for 12 months: ";
        totalQuantity = 0;

        for (int i = 0; i < 12; i++) {
            cin >> monthlySales[i];
            totalQuantity += monthlySales[i];
        }

        totalBill = totalQuantity * price;
    }

    void displayDetails() {
        cout << "\nProduct ID: " << productId << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Price: " << price << endl;
        cout << "Total Quantity Sold: " << totalQuantity << endl;
        cout << "Total Bill: " << totalBill << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of products: ";
    cin >> n;

    Product products[10];

    for (int i = 0; i < n; i++) {
        cout << "\n--- Enter details for Product " << i + 1 << " ---\n";
        products[i].acceptDetails();
    }

    cout << "\n========== PRODUCT DETAILS ==========\n";

    for (int i = 0; i < n; i++) {
        products[i].displayDetails();
    }

    return 0;
}