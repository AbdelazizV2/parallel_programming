#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int userCount = 0;

int isUsernameTaken(const char *username) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return 1;
        }
    }
    return 0;
}

int registerUser() {
    if (userCount == MAX_USERS) {
        printf("Maximum number of users reached. Cannot register new user.\n");
        return 0;
    }

    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    if (isUsernameTaken(username)) {
        printf("Username is already taken. Please choose a different username.\n");
        return 0;
    }

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    userCount++;

    printf("User registered successfully.\n");
    return 1;
}

int authenticateUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            printf("Authentication successful. Welcome, %s!\n", username);
            return 1;
        }
    }

    printf("Authentication failed. Invalid username or password.\n");
    return 0;
}

int main() {
    int choice;

    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                authenticateUser();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
