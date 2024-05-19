#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "grocery.h"

int main() {
    User user;
    ShoppingList list;

    printf("Welcome! Please register.\n");
    registerUser(&user);

    printf("Please log in to continue.\n");
    while (!loginUser(&user));

    initShoppingList(&list);

    int choice, quantity;
    while (1) {
        displayMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Thank you for shopping with us!\n");
            break;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);
        addToShoppingList(&list, choice, quantity);
    }

    list.total = calculateTotal(&list);
    printShoppingList(&list);
    printf("Total bill: ₹%.2f\n", list.total);

    saveShoppingList(&list, "shopping_list.txt");

    freeShoppingList(&list);

    printf("Your shopping list has been saved.\n");
    printf("Thank you for shopping with us! Please visit again.\n");

    return 0;
}
