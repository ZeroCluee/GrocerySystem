#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grocery.h"

#define RICE_PRICE 10
#define BREAD_PRICE 2
#define MILK_PRICE 3
#define EGGS_PRICE 5

void displayMenu() {
    printf("\n");
    printf("───────────────────────────────\n");
    printf("      Welcome to the Grocery Store\n");
    printf("───────────────────────────────\n");
    printf("1. Rice          - ₹%d\n", RICE_PRICE);
    printf("2. Bread         - ₹%d\n", BREAD_PRICE);
    printf("3. Milk          - ₹%d\n", MILK_PRICE);
    printf("4. Eggs          - ₹%d\n", EGGS_PRICE);
    printf("5. Exit\n");
    printf("───────────────────────────────\n");
}

void initShoppingList(ShoppingList *list) {
    list->items = (int *)malloc(0 * sizeof(int));
    list->quantities = (int *)malloc(0 * sizeof(int));
    list->itemCount = 0;
    list->total = 0.0;
}

void addToShoppingList(ShoppingList *list, int choice, int quantity) {
    list->items = (int *)realloc(list->items, (list->itemCount + 1) * sizeof(int));
    list->quantities = (int *)realloc(list->quantities, (list->itemCount + 1) * sizeof(int));

    list->items[list->itemCount] = choice;
    list->quantities[list->itemCount] = quantity;
    list->itemCount++;
}

float calculateTotal(const ShoppingList *list) {
    float total = 0.0;
    for (int i = 0; i < list->itemCount; i++) {
        switch (list->items[i]) {
            case 1:
                total += RICE_PRICE * list->quantities[i];
                break;
            case 2:
                total += BREAD_PRICE * list->quantities[i];
                break;
            case 3:
                total += MILK_PRICE * list->quantities[i];
                break;
            case 4:
                total += EGGS_PRICE * list->quantities[i];
                break;
            default:
                printf("Invalid item ID!\n");
        }
    }
    return total;
}

void printShoppingList(const ShoppingList *list) {
    printf("\n");
    printf("──────────────────────────────────────────\n");
    printf("          Your Shopping List\n");
    printf("──────────────────────────────────────────\n");
    printf("Item          Quantity     Total Price\n");
    printf("──────────────────────────────────────────\n");
    for (int i = 0; i < list->itemCount; i++) {
        switch (list->items[i]) {
            case 1:
                printf("Rice          %8d       %10.2f\n", list->quantities[i], RICE_PRICE * list->quantities[i]);
                break;
            case 2:
                printf("Bread         %8d       %10.2f\n", list->quantities[i], BREAD_PRICE * list->quantities[i]);
                break;
            case 3:
                printf("Milk          %8d       %10.2f\n", list->quantities[i], MILK_PRICE * list->quantities[i]);
                break;
            case 4:
                printf("Eggs          %8d       %10.2f\n", list->quantities[i], EGGS_PRICE * list->quantities[i]);
                break;
            default:
                printf("Invalid item ID!\n");
        }
    }
    printf("──────────────────────────────────────────\n");
}

void freeShoppingList(ShoppingList *list) {
    free(list->items);
    free(list->quantities);
}

void saveShoppingList(const ShoppingList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        for (int i = 0; i < list->itemCount; i++) {
            fprintf(file, "%d %d\n", list->items[i], list->quantities[i]);
        }
        fclose(file);
    } else {
        printf("Error: Unable to open file for writing.\n");
    }
}

void loadShoppingList(ShoppingList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        int item, quantity;
        while (fscanf(file, "%d %d", &item, &quantity) == 2) {
            addToShoppingList(list, item, quantity);
        }
        fclose(file);
    } else {
        printf("Error: Unable to open file for reading.\n");
    }
}

int searchItem(const char *itemName) {
    if (strcmp(itemName, "Rice") == 0) return 1;
    if (strcmp(itemName, "Bread") == 0) return 2;
    if (strcmp(itemName, "Milk") == 0) return 3;
    if (strcmp(itemName, "Eggs") == 0) return 4;
    return -1;
}
