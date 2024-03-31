#include <stdio.h>

// Function to create a new user account
void createUser(int *customerId, char username[], char password[]) {
    printf("Create your login credentials\n");
    printf("Set your username: ");
    scanf("%s", username);
    printf("Set your password: ");
    scanf("%s", password);
    printf("Enter your customer ID: ");
    scanf("%d", customerId);
}

// Function to login user
int loginUser(const char stored[], const char input[]) {
    int i = 0;
    while (stored[i] != '\0' && input[i] != '\0') {
        if (stored[i] != input[i]) {
            return 0; // Failed login
        }
        i++;
    }
    if (stored[i] == '\0' && input[i] == '\0') {
        return 1; // Successful login
    }
    return 0; // Failed login
}
