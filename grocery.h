#ifndef GROCERY_H
#define GROCERY_H

typedef struct {
    int *items;
    int *quantities;
    int itemCount;
    float total;
} ShoppingList;

void displayMenu();
void initShoppingList(ShoppingList *list);
void addToShoppingList(ShoppingList *list, int choice, int quantity);
float calculateTotal(const ShoppingList *list);
void printShoppingList(const ShoppingList *list);
void freeShoppingList(ShoppingList *list);
void saveShoppingList(const ShoppingList *list, const char *filename);
void loadShoppingList(ShoppingList *list, const char *filename);
int searchItem(const char *itemName);

#endif
