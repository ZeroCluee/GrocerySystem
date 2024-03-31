#include <stdio.h>
#include<conio.h>
// Function declarations
void displayMenu();
void createUser(int *customerId, char username[], char password[]);
int loginUser(const char username[], const char password[]);
float calculateBill(int choice, int quantity);

int main() {
    char username[20];
    char password[20];
    int customerId;
    int choice;
    int quantity;
    float total = 0;
    char ch;

    printf("Welcome to Our Grocery Store!\n");

    // Creating a new account
    printf("Create your login credentials\n");
    printf("Set your username: ");
    scanf("%s", username);
    printf("Set your password: ");
    scanf("%s", password);

    printf("Enter your customer ID: ");
    scanf("%d", &customerId);

    printf("\nAccount created successfully!\n");

    while (1) {
        printf("\nLogin\n");
        char input_username[20];
        char input_password[20];
        
        printf("Enter your username: ");
        scanf("%s", input_username);
        printf("Enter your password: ");
        scanf("%s", input_password);

        if (loginUser(username, input_username) && loginUser(password, input_password)) {
            printf("Login successful, %s!\n", username);
            break;
        } else {
            printf("Invalid username or password! Please try again.\n");
        }
    }

    printf("\nWelcome, %s!\n", username);
    printf("Customer ID: %d\n", customerId);

    while (1) {
        displayMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("\nThank you for shopping with us, %s!\n", username);
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter quantity for Rice: ");
                scanf("%d", &quantity);
                total += calculateBill(1, quantity);
                printf("%d kg of Rice added to the bill (₹%.2f).\n", quantity, calculateBill(1, quantity));
                break;
            case 2:
                printf("Enter quantity for Bread: ");
                scanf("%d", &quantity);
                total += calculateBill(2, quantity);
                printf("%d loaves of Bread added to the bill (₹%.2f).\n", quantity, calculateBill(2, quantity));
                break;
            case 3:
                printf("Enter quantity for Milk: ");
                scanf("%d", &quantity);
                total += calculateBill(3, quantity);
                printf("%d liter(s) of Milk added to the bill (₹%.2f).\n", quantity, calculateBill(3, quantity));
                break;
            case 4:
                printf("Enter quantity for Eggs: ");
                scanf("%d", &quantity);
                total += calculateBill(4, quantity);
                printf("%d Egg(s) added to the bill (₹%.2f).\n", quantity, calculateBill(4, quantity));
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    printf("Total bill: ₹%.2f\n", total);
    while((ch=getch()) != '\n')
            {
                break;
            }
    return 0;
}
