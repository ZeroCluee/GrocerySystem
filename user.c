#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

void registerUser(User *user) {
    printf("Enter a new username: ");
    scanf("%s", user->username);
    printf("Enter a new password: ");
    scanf("%s", user->password);
    printf("Enter a customer ID: ");
    scanf("%s", user->customerID);
}

int loginUser(User *user) {
    char username[20];
    char password[20];

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    if (strcmp(username, user->username) == 0 && strcmp(password, user->password) == 0) {
        printf("Login successful!\n");
        return 1;
    } else {
        printf("Invalid username or password!\n");
        return 0;
    }
}
