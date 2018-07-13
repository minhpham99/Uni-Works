#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>

#define answerSize 150

/************************************** FUNCTIONS ***********************************/

// greets the user
char *userGreetings(char userInput[]) {
    char *botGreetings;
    char *fileArray[6];
    char fileLine[26];
    bool isGreeting = false;
    int i;

    botGreetings = malloc(30 * sizeof(char));

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
        botGreetings = "don't you ever say hello?\n";
    }

    return botGreetings;
}

// response with a random interesting facts
char *randomFacts(char userInput[]) {
    char *funFacts;
    char *fileArray[100];
    char fileLine[1000];
    bool isRandom = false;
    int i = 0;

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
char *botFacts(char userInput[]) {
    char *selfFacts;
    char *fileArray[100];
    char fileLine[1000];
    bool isBot = false;
    int i = 0;

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
    selfFacts = fileArray[rand()%15];

    return selfFacts;
}

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

                botAnswer = malloc(answerSize + 1);

                // appending answers here
                strcpy(halfAnswer1, "The capital city of ");
                strcpy(halfAnswer2, " is ");
                halfAnswer3 = returnAnswer(keyword1, keyword2);

                strcat(halfAnswer1, keyword2);
                strcat(halfAnswer1, halfAnswer2);
                strcat(halfAnswer1, halfAnswer3);

                strcat(botAnswer, strcat(halfAnswer1, "\n"));
            }
            else if (strstr(userInput, "continent") != NULL) {

                halfAnswer1 = malloc(200 * sizeof(char));
                halfAnswer2 = malloc(3 * sizeof(char));
                halfAnswer3 = malloc(40 * sizeof(char));
                responseSize = strlen(halfAnswer1);

                botAnswer = malloc(answerSize + 1);

                // appending answers here
                strcpy(halfAnswer1, keyword2);
                strcpy(halfAnswer2, " is located in ");
                halfAnswer3 = returnAnswer(keyword1, keyword2);

                strcat(halfAnswer1, halfAnswer2);
                strcat(halfAnswer1, halfAnswer3);

                strcat(botAnswer, strcat(halfAnswer1, "\n"));
            }
            else if (strstr(userInput, "population") != NULL) {
                halfAnswer1 = malloc(200 * sizeof(char));
                halfAnswer2 = malloc(3 * sizeof(char));
                halfAnswer3 = malloc(40 * sizeof(char));
                responseSize = strlen(halfAnswer1);

                botAnswer = malloc(answerSize + 1);

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

/**************************************** MAIN *************************************************/

int main() {
    char functionName[20];
    char *query, *greetings, *random, *bot, *answer, *keyword1;
    time_t t;
    srand((unsigned)time(&t));
    bool testRunning = true;

    // list out each functions
    printf("\n**********TEST FILE**********\n\n");
    printf("This is the test file for different functions in programming project 2.\n");
    printf("1. userGreetings\n");
    printf("2. userQuery\n");
    printf("3. randomFacts\n");
    printf("4. botFacts\n");
    printf("5. saveInput\n");
    printf("6. returnAnswer\n");

    printf("\nPlease enter the function to be tested, or \"quit\" to stop the program: ");
    scanf("%[^\n]s", functionName);

        if (strcmp(functionName, "userGreetings") == 0) {
            greetings = malloc(strlen(greetings));
            greetings = userGreetings("hi\n");
            printf("%s", greetings);
            free(greetings);
        }
        else if (strcmp(functionName, "userQuery") == 0 ) {
            query = userQuery("Which continent is South Africa located?");
            printf("\nWhere is South Africa located? %s\n", query);

            query = userQuery("What is the capital city of South Africa?");
            printf("\nWhat is the capital city of South Africa? %s\n", query);

            query = userQuery("What is the population of China?");
            printf("\nWhat is the population of China? %s\n", query);

            // incorrect input (bot cannot identify keywords)
            query = userQuery("What is the weather like in Hanoi?");
            printf("\nWhat is the weather like in Hanoi? %s\n", query);
        }
        else if (strcmp(functionName, "randomFacts") == 0) {
            random = randomFacts("interesting fact\n");
            printf("\n%s\n", random);
        }
        else if (strcmp(functionName, "botFacts") == 0) {
            // need to have 25 facts otherwise it can return null
            bot = botFacts("tell me about you\n");
            printf("%s\n", bot);
        }
        else if(strcmp(functionName, "saveInput") == 0) {
            // there should be a blank line after if it's the last one
            saveInput("Line1\n");
            saveInput("Line2\n");

            // should not save this one
            saveInput("\n");
            printf("File is created and saved\n");
        }
        else if(strcmp(functionName, "returnAnswer") == 0) {
            answer = returnAnswer("capital", "Sri Lanka");
            printf("%s\n", answer);

            // second keyword incorrect
            answer = returnAnswer("capital", "Hanoi");
            printf("%s\n", answer);

            answer = returnAnswer("capital", "South Africa");
            printf("%s\n", answer);

            answer = returnAnswer("continent", "South Sudan");
            printf("%s\n", answer);

            answer = returnAnswer("continent", "Turkey");
            printf("%s\n", answer);

            answer = returnAnswer("population", "China");
            printf("%s\n", answer);

            answer = returnAnswer("population", "Romania");
            printf("%s\n", answer);

            // incorrect input
            answer = returnAnswer("what", "hi");
            printf("%s\n", answer);

        }
        else if(strcmp(functionName, "quit") == 0) {
            printf("You have quit the test program\n");
        }
        // error handling
        else {
            printf("Function doesn't exist!(or just check your spelling/case)\n");
        }

    return 0;
}
