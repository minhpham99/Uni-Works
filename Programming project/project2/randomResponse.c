#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include"randomResponse.h"

// greets the user
char *userGreetings(char userInput[]) {
    char *botGreetings;
    char *fileArray[6];
    char fileLine[26];
    bool isGreeting = false;
    int i;

    botGreetings = malloc(50 * sizeof(char));

    // get greetings from this file
    FILE *fileOpen = fopen("greetings.txt", "r");
     if (!fileOpen) {
        fputs("Error: file not found\n", stdout);
        exit(0);
    }

    while (fgets(fileLine, sizeof fileLine, fileOpen) != NULL) {
        fileArray[i] = strndup(fileLine, sizeof fileLine);
        i++;
    }

    fclose(fileOpen);

    // check for greeting words
    for (i = 0 ; i < 6; i++) {
        if (strcmp(userInput, fileArray[i]) == 0) {
            isGreeting = true;
        }
    }
    if (isGreeting == true) {
        botGreetings = fileArray[rand()%6];
    }
    else {
        botGreetings = "Don't you ever say hello?\n";
    }

    return botGreetings;
}

// response with a random interesting facts
char *randomFacts() {
    char *funFacts;
    char *fileArray[100];
    char fileLine[1000];
    int i = 0;

    funFacts = malloc(100 * sizeof(char));

    // get facts from this file
    FILE *fileOpen = fopen("funfacts.txt", "r");
     if (!fileOpen) {
        fputs("Error: file not found\n", stdout);
        exit(0);
    }

    while (fgets(fileLine, sizeof fileLine, fileOpen) != NULL) {
        fileArray[i] = strdup(fileLine);
        i++;
    }

    fclose(fileOpen);

    // randomly pick a string from the file
    funFacts = fileArray[rand()%49];

    return funFacts;
}

// reponse with a random fact about the bot
char *botFacts() {
    char *selfFacts;
    char *fileArray[20];
    char fileLine[1000];
    int i = 0;

    selfFacts = malloc(50 * sizeof(char));

    // get facts from this file
    FILE *fileOpen = fopen("botFacts.txt", "r");
     if (!fileOpen) {
        fputs("Error: file not found\n", stdout);
        exit(0);
    }

    while (fgets(fileLine, sizeof fileLine, fileOpen) != NULL) {
        fileArray[i] = strdup(fileLine);
        i++;
    }

    fclose(fileOpen);

    // randomly pick a string from the file
    selfFacts = fileArray[rand()%20];

    return selfFacts;
}

// response when user talks about themselves
char *aboutYou() {
    char *isInteresting;
    char *fileArray[5];
    char fileLine[100];
    int i = 0;

    isInteresting = malloc(50 * sizeof(char));

    // get facts from this file
    FILE *fileOpen = fopen("aboutYou.txt", "r");
     if (!fileOpen) {
        fputs("Error: file not found\n", stdout);
        exit(0);
    }

    while (fgets(fileLine, sizeof fileLine, fileOpen) != NULL) {
        fileArray[i] = strdup(fileLine);
        i++;
    }

    fclose(fileOpen);

    // randomly pick a string from the file
    isInteresting = fileArray[rand()%5];

    return isInteresting;
}