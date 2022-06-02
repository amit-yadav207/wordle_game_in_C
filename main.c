#include "header.h"       //custom header file
#include "colors.h"       //custom header file
#include "declarations.h" //custom header file
int main()
{
    char choice;
    do
    {
        clear();
        char *chosenWord = malloc(6 * sizeof(char));               // for storing word read from file
        int num_of_atmpts = 0;                                     // to keep track of number of times attempted
        FILE *sfptr = NULL;                                        // scorefile pointer for storing score
        char *difLevel;                                            // for storing name of difficulty level
        char *fileName = NULL;                                     // storing file name
        char *color = NULL;                                        // storing color
        int total_atmpts;                                          //  total attempts set
        setDiffLevel(&total_atmpts, &difLevel, &fileName, &color); // setting difficulty level//sending address of pointers
        clear();
        char letters[] = {"QWERTYUIOPASDFGHJKLZXCVBNM"}; // to show which letters are not used in previous guesses
        char usedLetters[] = {"QWERTYUIOPASDFGHJKLZXCVBNM"};
        int score = 0;                        // to keep the track of score in each round
        char pname[30];                       // for storing player name
        FILE *fptr = fopen("words.txt", "r"); // for getting random word from this FILE

        if (fptr != NULL)
        {
            gameHeading(color, difLevel);      // printing heading
            printInsructs(total_atmpts);       // instructions
            getRandomWord(&fptr, &chosenWord); // getting random word from word.txt
            // printf("%s\n", chosenWord);
            //  get words from player and send chosenWord and user input to a function to check if it;s correct
            char *userInput = malloc(6 * sizeof(char));
            bool isCorrect = false;
            while (num_of_atmpts < total_atmpts)
            {
                getInput(&color, &userInput, num_of_atmpts);
                num_of_atmpts += 1;
                isCorrect = isCorrectGuess(userInput, chosenWord, letters, &score, usedLetters);
                if (isCorrect)
                    break;
            }
            if (isCorrect)
            {
                hrline();
                printf("\n\n\t\t*****************" COLOR_GREEN "CONGRATULATIONS!!! , You guessed the correct word in " COLOR_YELLOW "%d attempt(s)" COLOR_RESET "***************\n\n", num_of_atmpts);
                hrline();
            }
            else
            {
                hrline();
                printf("\n\t\t-----------------------" COLOR_RED "OOPS!,you couldn't guess the correct words in %d attempts" COLOR_RESET "-----------------\n", total_atmpts);
                printf("\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> CORRECT WORD WAS : " COLOR_GREEN "\'%s\'" COLOR_RESET " <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n",
                       chosenWord);
                hrline();
                // free all the allocated memory
            }
            while (getchar() != '\n')
                ;
            printf("\n\t\tYOUR NAME ?       :  ");
            fgets(pname, 30, stdin);
            pname[strlen(pname) - 1] = '\0'; // removing trailing newline character from string
            int finalScore = score + 10 * (total_atmpts - num_of_atmpts);
            printf("\n\t\tYOUR FINAL SCORE  : " BOLD_MODE " %d" COLOR_RESET " out of " BOLD_MODE "%d" COLOR_RESET "\n", finalScore, 10 * total_atmpts); // rest of attempts assign full score
            // opening respective file
            sfptr = fopen(fileName, "ab+");
            // count lines in file
            int count = getLineCount(&sfptr); // getting serial number
            fprintf(sfptr, "\t\t\t  %02d\t\t\t  %-24s  %d\n\n", count / 2 + 1, pname, finalScore);
            fclose(sfptr);                     // closing file
            viewScoreBoard(&sfptr, &fileName); // opening score file
        }
        else
        {
            printf("\n\t\tOOPS! Couldn't open the file...\n");
        }
        free(chosenWord);
        chosenWord = NULL;
        printf("\n\t\tWANT TO PLAY AGAIN ? (y/n)  :  ");
        scanf("\n%c", &choice);
    } while (choice != 'n' && choice != 'N');
    return 0;
}
