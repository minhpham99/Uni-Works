#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include"randomResponse.h"
#include"keywordFinding.h"
#include"saveInput.h"

/**************************************** MAIN *************************************************/

int main() {
    char functionName[20];
    char *query, *greetings, *random, *bot, *answer, *response;
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
    printf("7. aboutYou\n");

    printf("\nPlease enter the function to be tested, or \"quit\" to stop the program: ");
    scanf("%[^\n]s", functionName);

        if (strcmp(functionName, "userGreetings") == 0) {
            greetings = malloc(strlen(greetings));
            greetings = userGreetings("hi\n");
            printf("%s", greetings);
            free(greetings);
        }
        else if (strcmp(functionName, "userQuery") == 0 ) {
            query = userQuery("Where is Latvia?");
            printf("\nWhere is Latvia located? %s\n", query);

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

            answer = returnAnswer("where", "Latvia");
            printf("%s\n", answer);

            answer = returnAnswer("where", "Turkey");
            printf("%s\n", answer);

            answer = returnAnswer("population", "China");
            printf("%s\n", answer);

            answer = returnAnswer("population", "Romania");
            printf("%s\n", answer);

            // incorrect input
            answer = returnAnswer("what", "hi");
            printf("%s\n", answer);

        }
        else if(strcmp(functionName, "aboutYou") == 0) {
            response = aboutYou();
            printf("%s\n", response);
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
