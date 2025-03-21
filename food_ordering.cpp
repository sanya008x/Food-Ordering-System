#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;
// Structure to store ordered item details
struct OrderItem {
    string name;
    int quantity;
    int price;
};
// Function to get valid integer input
int getValidInteger(string prompt, int min, int max) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < min || value > max) {
            cout << "Error: Please enter a valid option between " << min << " and " << max << ".\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return value;
        }
    }
}
// Function to get valid 'Y' or 'N' input
char getValidYesNo(string prompt) {
    char choice;
    while (true) 
    {
        cout << prompt;
        cin >> choice;
        if (choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n') {
            return choice;
        } 
        else 
        {
            cout << "Error: Please enter a valid response (Y/N).\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
int main() {
    vector<OrderItem>orders;
    char orderMore;
    int category, item, quantity, totalAmount = 0, pizzaSize;
    string name;
    cout << "************************ Welcome to Uber Eats ************************\n\n";
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    do {
        category = getValidInteger(
            "\nWhat would you like to order?\n"
            "1. Pizza\n2. Burger\n3. Sandwich\n4. Biryani\n5. Desserts\n6. Beverages\n"
            "Enter your choice (1-6): ", 
            1, 6
        );
        string itemName;
        int price = 0;
        // Menu handling for each category
        switch (category) {
            case 1:
                cout << "\n1) Margherita Pizza - Rs 200\n2) Cheese n Corn Pizza - Rs 300\n";
                cout << "3) Paneer Barbeque Pizza - Rs 350\n4) Chicken Tandoori Pizza - Rs 450\n";
                item = getValidInteger("\nEnter your choice (1-4): ", 1, 4);
                pizzaSize = getValidInteger("\nChoose Pizza Size:\n1) Small\n2) Medium (+100 Rs)\n3) Large (+200 Rs)\nEnter size (1-3): ", 1, 3);
                if (item == 1) itemName = "Margherita Pizza", price = 200;
                else if (item == 2) itemName = "Cheese n Corn Pizza", price = 300;
                else if (item == 3) itemName = "Paneer Barbeque Pizza", price = 350;
                else if (item == 4) itemName = "Chicken Tandoori Pizza", price = 450;
                if (pizzaSize == 2) price += 100;
                else if (pizzaSize == 3) price += 200;
                break;
            case 2:
                cout << "\n1) Double Cheese Veg Burger - Rs 175\n2) Spicy Paneer Burger - Rs 150\n";
                cout << "3) Chicken Zinger Burger - Rs 180\n4) Crispy Chicken Burger - Rs 200\n";
                item = getValidInteger("\nEnter your choice (1-4): ", 1, 4);
                itemName = (item == 1) ? "Double Cheese Veg Burger" : (item == 2) ? "Spicy Paneer Burger" : 
                           (item == 3) ? "Chicken Zinger Burger" : "Crispy Chicken Burger";
                price = (item == 1) ? 175 : (item == 2) ? 150 : (item == 3) ? 180 : 200;
                break;
            case 3:
                cout << "\n1) Paneer Tikka Sandwich - Rs 75\n2) Creamy Cheese Spinach Corn Sandwich - Rs 120\n";
                cout << "3) Chicken Keema Sandwich - Rs 150\n4) Grilled Vegetable Sandwich - Rs 110\n";
                item = getValidInteger("\nEnter your choice (1-4): ", 1, 4);
                itemName = (item == 1) ? "Paneer Tikka Sandwich" : (item == 2) ? "Cheese Spinach Sandwich" : 
                           (item == 3) ? "Chicken Keema Sandwich" : "Grilled Vegetable Sandwich";
                price = (item == 1) ? 75 : (item == 2) ? 120 : (item == 3) ? 150 : 110;
                break;
            case 4:
                cout << "\n1) Paneer Tikka Dum Biryani - Rs 250\n2) Masala Dum Biryani - Rs 200\n";
                cout << "3) Mutton Dum Biryani - Rs 300\n4) Chicken Dum Biryani - Rs 275\n";
                item = getValidInteger("\nEnter your choice (1-4): ", 1, 4);
                itemName = (item == 1) ? "Paneer Tikka Dum Biryani" : (item == 2) ? "Masala Dum Biryani" : 
                           (item == 3) ? "Mutton Dum Biryani" : "Chicken Dum Biryani";
                price = (item == 1) ? 250 : (item == 2) ? 200 : (item == 3) ? 300 : 275;
                break;
            case 5:
                cout << "\n1) Chocolate Sundae - Rs 180\n2) Banana Pancakes- Rs 110\n";
                cout << "3) Blueberry Cheesecake-Rs 225 \n4) Dark Chocolate Brownie-Rs 230\n";
                item = getValidInteger("\nEnter your choice (1-4): ", 1, 4);
                itemName = (item == 1) ? "Chocolate Sundae" : (item == 2) ? "Banana Pancakes" : 
                           (item == 3) ? "Blueberry Cheesecake" : "Dark Chocolate Brownie";
                price = (item == 1) ? 180 : (item == 2) ? 110 : (item == 3) ? 225 : 230;
                break;
            case 6:
                cout << "\n1) Brownie Nutty Shake - Rs 275\n2) Virgin Mojito - Rs 150\n";
                cout << "3) Cold Coffee - Rs 120\n4) Kitkat Shake - Rs 210\n";
                item = getValidInteger("\nEnter your choice (1-4): ", 1, 4);
                itemName = (item == 1) ? "Brownie Nutty Shake" : (item == 2) ? "Virgin Mojito" : 
                           (item == 3) ? "Cold Coffee" : "Kitkat Shake";
                price = (item == 1) ? 275 : (item == 2) ? 150 : (item == 3) ? 120 : 210;
                break;
        }
        quantity = getValidInteger("Enter quantity: ", 1, 100);
        totalAmount += price * quantity;
        orders.push_back({itemName, quantity, price * quantity});
        orderMore = getValidYesNo("Would you like to order anything else? (Y/N): ");
    } 
    while (orderMore == 'Y' || orderMore == 'y');
    double gst = totalAmount * 0.05;
    double finalAmount = totalAmount + gst;
    cout << "\n********************* ORDER BILL ************************\n\n";
    cout << "Cashier: Henry Cavill\n";
    cout << "Customer Name: " << name << endl;
    cout << "Your Order:\n";
    for (const auto& order : orders)
    {
        cout << order.name << " x " << order.quantity << " = Rs " << order.price << "\n\n";
    }
    cout << "--------------------------------------------------------\n";
    cout << "Sub Total: Rs " << totalAmount << "\n";
    cout << "TAX (5%): Rs " << gst << "\n";
    cout << "Total: Rs " << finalAmount << "\n\n";
    cout << "Your order will be ready soon.\nThank you for ordering from Uber Eats!\n\n";
    cout << "*********************************************************\n";
    return 0;
}
