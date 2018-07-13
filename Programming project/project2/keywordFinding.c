#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include"keywordFinding.h"

// return the answer base on two keywords
char *returnAnswer(char *word1, char *word2) {
    char k1[15];
    char k2[30];
    char ans[55];
    char fileLine[100];
    char *answer;
    int i;

    // default answer, if no or not enough keyword is found
    answer = "Keyword(s) not found";

    FILE *fileOpen = fopen("queryK&A.txt", "r");

    if (!fileOpen) {
        fputs("Error: file not found\n", stdout);
        exit(0);
    }

    while (fgets(fileLine, sizeof(fileLine), fileOpen)) {
        if (sscanf(fileLine, " %[^,],%[^,],%[^\n] ", k1, k2, ans) == 3) {
            // search for keywords in the file
            if (strstr(word1, k1) != NULL) {
                if (strstr(word2, k2) != NULL) {
                // assign the final answer
                answer = strndup(ans, 55);
                }
            }
        }
    }

    fclose(fileOpen);

    return answer;
}

// look for keywords in query and return answer
char *userQuery(char userInput[]) {
    char keyword1[15];
    char keyword2[30];
    char ans[55];
    char fileLine[100];
    // split up the long answer
    char *halfAnswer1;
    char *halfAnswer2;
    char *halfAnswer3;
    char *botAnswer;
    int i, responseSize;
    bool keyword1Found;
    bool keyword2Found;

    // default answer
    botAnswer = "Sorry I don't have information on this at the moment\n";

    FILE *fileOpen = fopen("queryK&A.txt", "r");

    if (!fileOpen) {
        fputs("Error: file not found\n", stdout);
        exit(0);
    }

    while (fgets(fileLine, sizeof(fileLine), fileOpen)) {
        if (sscanf(fileLine, " %[^,],%[^,],%[^\n] ", keyword1, keyword2, ans) != 3) {
            printf("Not enough knowledge\n");
            exit(0);
        }
        // comparing one keyword at a time
        if (strstr(userInput, keyword1)) {
            keyword1Found = true;
            if (strstr(userInput, keyword2)) {
                keyword2Found = true;
            }
            else keyword2Found = false;
        }
        else {
            keyword1Found = false;
            if (strstr(userInput, keyword2)) {
                keyword2Found = true;
            }
            else keyword2Found = false;
        }

        // return the answer as a string
        if (keyword1Found && keyword2Found) {
            if (strstr(userInput, "capital") != NULL) {

                halfAnswer1 = malloc(200 * sizeof(char));
                halfAnswer2 = malloc(3 * sizeof(char));
                halfAnswer3 = malloc(40 * sizeof(char));
                responseSize = strlen(halfAnswer1);

                botAnswer = malloc(responseSize + 1);

                // appending answers here
                strcpy(halfAnswer1, "The capital city of ");
                strcpy(halfAnswer2, " is ");
                halfAnswer3 = returnAnswer(keyword1, keyword2);

                strcat(halfAnswer1, keyword2);
                strcat(halfAnswer1, halfAnswer2);
                strcat(halfAnswer1, halfAnswer3);

                strcat(botAnswer, strcat(halfAnswer1, "\n"));
            }
            if (strstr(userInput, "Where") != NULL) {

                halfAnswer1 = malloc(200 * sizeof(char));
                halfAnswer2 = malloc(3 * sizeof(char));
                halfAnswer3 = malloc(40 * sizeof(char));
                responseSize = strlen(halfAnswer1);

                botAnswer = malloc(responseSize + 1);

                // appending answers here
                strcpy(halfAnswer1, keyword2);
                strcpy(halfAnswer2, " is located in ");
                halfAnswer3 = returnAnswer(keyword1, keyword2);

                strcat(halfAnswer1, halfAnswer2);
                strcat(halfAnswer1, halfAnswer3);

                strcat(botAnswer, strcat(halfAnswer1, "\n"));
            }
            if (strstr(userInput, "population") != NULL) {
                halfAnswer1 = malloc(200 * sizeof(char));
                halfAnswer2 = malloc(3 * sizeof(char));
                halfAnswer3 = malloc(40 * sizeof(char));
                responseSize = strlen(halfAnswer1);

                botAnswer = malloc(responseSize + 1);

                // appending answers here
                strcpy(halfAnswer1, "There are ");
                strcpy(halfAnswer2, " people live in ");
                halfAnswer3 = returnAnswer(keyword1, keyword2);

                strcat(halfAnswer1, halfAnswer3);
                strcat(halfAnswer1, halfAnswer2);
                strcat(halfAnswer1, keyword2);

                strcat(botAnswer, strcat(halfAnswer1, "\n"));
            }
        }

    }

    fclose(fileOpen);

    return botAnswer;
}