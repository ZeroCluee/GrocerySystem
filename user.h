#ifndef USER_H
#define USER_H

typedef struct {
    char username[20];
    char password[20];
    char customerID[20];
} User;

void registerUser(User *user);
int loginUser(User *user);

#endif
