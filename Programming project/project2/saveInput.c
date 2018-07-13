#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include"saveInput.h"

// save all user input to a separate file
void saveInput(char userInput[]) {
    int i;
    int length = strlen(userInput);
    // append the input into the last line
    FILE *saveFile = fopen("inputList.txt", "a");

    if (strcmp(userInput, "\n")!=0) {
        fwrite(userInput, 1, length, saveFile);
    }

    fclose(saveFile);
}