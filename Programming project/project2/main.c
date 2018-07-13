#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include"randomResponse.h"
#include"keywordFinding.h"
#include"saveInput.h"

#define answerSize 150

/**************************************** MAIN *************************************************/

int main() {
    char user[200];
    char *bot;
    bool isRunning;
    int i;
    time_t t, start, end;
    srand((unsigned)time(&t));
    float timeTaken;

    // clear the screen, make the UI looks nicer
    system("clear");

    // introduction
    printf("Hi! My name is Ariel and I will be your guru about countries around the world.\n");
    printf("You also can learn an interesting fact, ");
    printf("or I can tell you more about myself ;)\n");
    printf("I hope you enjoy the conversation and learn something new\n");

    // time the chat
    time(&start);

    // user would have to greet first
    printf("\n>>>User: ");
    fgets(user, sizeof(user), stdin);

    // save the input
    saveInput(user);

    bot = malloc(answerSize);

    bot = userGreetings(user);
    printf(">>>Ariel: %s", bot);

    // initialise to keep the program run
    isRunning = true;

    // the prompt for user to enter query
    while(isRunning) {
        printf(">>>User: ");
        fgets(user, sizeof(user), stdin);

        // save everything user enters into a file
        saveInput(user);

        // if user enters something
        if (strcmp(user, "\n")!=0) {
            for ( i = 0; i < strlen(user); i++) {
                if ((strcmp(user, "hi\n") == 0 ) || (strcmp(user, "hello\n") == 0)) {
                    bot = "Hello\n";
                }
                else if ((strstr(user, "interesting") != NULL) || (strstr(user, "fact") !=NULL)) {
                    bot = randomFacts();
                }
                else if (strstr(user, "about you") != NULL) {
                    bot = botFacts();
                }
                else if ((strstr(user, "capital") !=NULL) || (strstr(user, "Where") !=NULL) || (strstr(user, "population") !=NULL) ) {
                    bot = userQuery(user);
                }

                // make the bot sounds more human
                else if (strstr(user, "thank") !=NULL) {
                    bot = "No problem :)\n";
                }
                // some fun features
                else if (strstr(user, "terminator") !=NULL) {
                  bot = "No I am not the terminator, but if you keep talking about it I will terminate you(and you'll never know when).\n";
                }
                else if ((strstr(user, "I") !=NULL) || (strstr(user, "I'm") != NULL) || (strstr(user, "My") !=NULL)) {
                  bot = aboutYou();
                }
                else if ((strstr(user, "you") !=NULL) || (strstr(user, "you're") != NULL)) {
                  bot = "Well, thank you\n";
                  if (strstr(user, "Who") !=NULL) {
                      bot = "I am who I am\n";
                  }
                  else if (strstr(user, "What") !=NULL) {
                      bot = "I am what I am\n";
                  }
                }

                // if user wants to quit the program
                else if (strstr(user, "bye") != NULL) {
                    bot = "Good bye! I hope you learn something new or have your question answered!\n";
                    isRunning = false;
                }

                // if user enters anything unknown
                else {
                    bot = "I'm sorry, I don't understand.\n";
                }
            }
        }

        // if user press enter without input
        else {
            bot = "Say something I'm giving up on you\n";
        }
        
        printf(">>>Ariel: %s", bot);
    }

    // stop the clock calculate the time taken
    time(&end);
    timeTaken = difftime(end, start);
    printf("\nTotal chat time: %.2fs\n", timeTaken);

    return 0;
}