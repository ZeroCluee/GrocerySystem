#include <stdio.h>

// Function to display the grocery menu
void displayMenu() {
    printf("\nWelcome to the Grocery Store\n");
    printf("1. Rice - ₹10\n");
    printf("2. Bread - ₹2\n");
    printf("3. Milk - ₹3\n");
    printf("4. Eggs - ₹5\n");
    printf("5. Exit\n");
}

// Function to calculate the bill
float calculateBill(int choice, int quantity) {
    float price;
    switch (choice) {
        case 1:
            price = 10.0;
            break;
        case 2:
            price = 2.0;
            break;
        case 3:
            price = 3.0;
            break;
        case 4:
            price = 5.0;
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }
    return price * quantity;
}
