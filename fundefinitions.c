#include "header.h"
#include "colors.h"
struct PreGuess
{
    char ch;
    char*color;
};
typedef struct PreGuess preGuess;//previous guess ,alphabet and bg color
bool isCorrectGuess(char *guess, char *ans, char *letters, int *score, char *usedLetters,preGuess *pg,int noa,int total_atmpts)
{
    int temp_score = 0;
    const int sizeOfWord = 5;
    char clue[6] = {'-', '-', '-', '-', '-'};
    // first for loop for marking all the character which are at right spot
    for (int i = 0; i < sizeOfWord; i++)
    {
        char x = guess[i];
        x = (x | ' '); // lowercase
        if (ans[i] == x)
        {
            clue[i] = 'G';   // guessed correctly and at correct place
            temp_score += 2; // correct position so gained 2 points
        }
    }
    for (int i = 0; i < sizeOfWord; i++) // ans
    {
        for (int j = 0; j < sizeOfWord; j++) // guess
        {
            char x = guess[j];
            x = (x | ' '); // lowercase
            if (ans[i] == x && clue[j] != 'G')
            {
                clue[j] = 'Y';   // wrong position
                temp_score += 1; // present but wrong position so gained 1 points
                                 // break;
            }
        }
    }
    printf("\n\t\tCLUE \t   \t:  ");
    int num=5*(noa-1);
    for (int i = 0; i < sizeOfWord; i++) // print clue string
    {
        char x = guess[i];
        x = (x & '_'); // upppercase
        if (clue[i] == 'G')
        {
            printf(BG_GREEN " %c " COLOR_RESET " ", x);
            pg[num].color=BG_GREEN;
            
        }
        else if (clue[i] == 'Y')
        {
            printf(BG_YELLOW " %c " COLOR_RESET " ", x);
             pg[num].color=BG_YELLOW;
        }
        else{
            printf(BG_DIM " %c " COLOR_RESET " ", x);
             pg[num].color=BG_DIM;
        }
        pg[num].ch=x;
        num++;
    }

    for (int i = 0; i < 30; i++)
    {

        for (int j = 0; j < sizeOfWord; j++)
        {
            char x = guess[j];
            x = (x & '_'); // upppercase
            if (x == letters[i] && clue[j] == 'G')
                usedLetters[i] = 'g'; // GREEN
            else if (x == letters[i] && clue[j] == 'Y')
                usedLetters[i] = 'y'; // YELLOW
            else if (x == letters[i] && clue[j] == '-')
                usedLetters[i] = 'n'; // purple
        }
    }
    printf("\n\n\t\t\t\t\t    Keyboard\t\t\t\tPrevious Guess\n\n\t\t\t    ");
    int j, k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (j =i*10;j<10*(i+1); j++)
        {
            if (usedLetters[j] == 'g')
                printf(BG_GREEN " %c " COLOR_RESET " ", letters[j]);
            else if (usedLetters[j] == 'y')
                printf(BG_YELLOW " %c " COLOR_RESET " ", letters[j]);
            else if (usedLetters[j] == 'n') // not present
                printf(BG_DIM  " %c " COLOR_RESET " ", letters[j]);
            else if (usedLetters[j] == ' ') 
               printf(COLOR_RESET  " %c " COLOR_RESET " ", 32);
            else
                printf(BG_BLACK " %c " COLOR_RESET " ", letters[j]);
        }
        printf("\t\t");
        int l=k+sizeOfWord;
         while(k<l&&k<5*total_atmpts)
         {
              printf("%s %c " COLOR_RESET ,pg[k].color,pg[k].ch);
             k++;
         }
     printf("\n\t\t\t\t\t\t\t\t\t\t");
     l=k+sizeOfWord;
      while(k<l&&k<5*total_atmpts)
         {
              printf("%s %c " COLOR_RESET,pg[k].color,pg[k].ch);
             k++;
         }
         printf("\n\t\t\t    ");
    }
if(total_atmpts==7)
{
  printf("\r\t\t\t\t\t\t\t\t\t\t");
  int k=30;
    int l=k+sizeOfWord;
      while(k<l&&k<5*total_atmpts)
         {
              printf("%s %c " COLOR_RESET,pg[k].color,pg[k].ch);
             k++;
         }  
}
    *score += temp_score; // increment final score
    printf("\n\t\tSCORE\t   \t:  " BOLD_MODE "%d" COLOR_RESET, temp_score);
    printf("\n\n");
    // chheck if clue array is totally filled with 'G'
    return strcmp("GGGGG", clue) == 0;
}
 
 
    void clear() {
    #ifdef _WIN32
        system("cls"); // for Windows
    #else
        system("clear"); // for Linux and other UNIX-based systems
    #endif
}
 
void hrline()
{
    // printf("\t\t------------------------------------------------------------------------------------------------");
    printf("\t\t................................................................................................\n");
}

void gameHeading(char* color,char* difLevel)
{
            printf("\n\t\t\t\t   ##################################################################\t\t\n");
            printf("\t\t\t\t   ##\t\t\t\t\t\t\t\t   ##\n");
            printf("\t\t\t\t   ##\t\t\t\t\t\t\t\t   ##\n");
            printf("\t\t\t\t   ##\t\t          " BG_GREEN " W " COLOR_RESET " " BG_BLUE " O " COLOR_RESET " " BG_RED " R " COLOR_RESET " " BG_BLUE " D " COLOR_RESET " " BG_GREEN " L " COLOR_RESET " " BG_RED " E " COLOR_RESET "   \t\t   ##\n");
            printf("\t\t\t\t   ##\t\t\t\t\t\t\t\t   ##\n");
            printf("\t\t\t\t   ##\t\t\t    "ITALIC_MODE" game in C language "COLOR_RESET"  \t\t   ##\n");
            printf("\t\t\t\t   ##\t\t\t\t\t\t\t\t   ##\n");
            printf("\t\t\t\t   ##\t\t\t\t\t\t\t\t   ##\n");
            printf("\t\t\t\t   ##################################################################\t\t\n");
            printf("\n\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  DIFFICULTY LEVEL : %s %s " COLOR_RESET "  <<<<<<<<<<<<<<<<<<<<<<<<<<\n\n", color, difLevel);
}

void printInsructs(int total_atmpts)
{
            printf("\n\t\t" BOLD_MODE "INSTRUCTIONS TO PLAY THIS GAME : " COLOR_RESET);
            printf("\n--->A word of " BOLD_MODE "5 letters" COLOR_RESET " is randomly selected from the dictionary");
            printf("\n--->You have to Enter a " BOLD_MODE "5 letters word" COLOR_RESET " having some meaning and should be present in dictionary");
            printf("\n--->You have only " BOLD_MODE "%d attempts" COLOR_RESET " to guess the correct word", total_atmpts);
            printf("\n\n--->Letter is " BOLD_MODE "present" COLOR_RESET " and is " BOLD_MODE "at right position" COLOR_RESET " then color     : " BG_GREEN "    " COLOR_RESET);
            printf("\n\n--->Letter is " BOLD_MODE "present" COLOR_RESET " and is " BOLD_MODE "NOT at right position " COLOR_RESET "then color : " BG_YELLOW "    " COLOR_RESET);
            printf("\n\n--->Letter is " BOLD_MODE "NOT present" COLOR_RESET " then color                          : " BG_DIM "    " COLOR_RESET "\n");
}

void setDiffLevel(int*total_atmpts,char**difLevel,char**fileName,char**color)
{
        printf("\n\t\t\t\t" BOLD_MODE ">>>>>>>>>>>>>>>>>>>>>>>>>>SET DIFFICULTY LEVEL<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" COLOR_RESET "\n");
        printf("\n\t\tPress " COLOR_GREEN "1" COLOR_RESET ", For " COLOR_GREEN " EASY " COLOR_RESET " level");
        printf("\n\t\tPress " COLOR_YELLOW "2" COLOR_RESET ", For" COLOR_YELLOW " MEDIUM " COLOR_RESET " level");
        printf("\n\t\tPress " COLOR_RED "3" COLOR_RESET ", For" COLOR_RED " HARD " COLOR_RESET " level");
        printf("\n\t\tEnter your choice  :  ");
         int level;                                   // setting difficulty level
        
        scanf("%d", &level);
        switch (level)
        {
        case 1:
            *difLevel = "EASY";
            *total_atmpts = 7; // seven chance for level easy
            *fileName = "sb_easy.txt";
            *color = BG_GREEN;
            break;
        case 2:
            *difLevel = "MEDIUM";
            *total_atmpts = 5;
            *fileName = "sb_medium.txt";
            *color = BG_YELLOW;
            break;
        case 3:
            *difLevel = "HARD";
            *total_atmpts = 3;
            *fileName = "sb_hard.txt";
            *color = BG_RED;
            break;
        }
}

void getRandomWord(FILE**fptr,char**chosenWord)
{
     int wordCount = 415; // from file
            srand(time(NULL));
            int idx = (rand() % wordCount) + 1;
            while ((fscanf(*fptr, "%s", *chosenWord)) == 1 && idx--);
            fclose(*fptr);
}

void getInput(char**color,char**userInput,int num_of_atmpts)
{
     hrline();
            printf("\n\t\t\t\t\t\t##############################################\t\t");
            printf("\n\t\t\t\t\t\t#                   ROUND %s %d " COLOR_RESET "                #\t\t", *color, num_of_atmpts + 1);
            printf("\n\t\t\t\t\t\t##############################################\t\t\n");
            printf("\n\t\tEnter your word_%d : ", num_of_atmpts + 1);
                // while (getchar() != '\n');
            scanf("%s", *userInput);
                // fflush(stdin);
            printf("\n\t\tYOUR GUESS \t:  ");
            for (int i = 0; (*userInput)[i] != '\0' && i < 5; i++)//precedence order imp
            {
                printf(" %c  ", (*userInput)[i]);
            }
}

void viewScoreBoard(FILE**sfptr,char**fileName)
{
 printf("\n\t\tWANT TO VIEW SCORE BOARD ? (y/n)  :  ");
            char choice;
            scanf("\n%c", &choice);
            if (choice == 'y'||choice == 'Y')
            {
                *sfptr = fopen(*fileName, "r");
                char ch;
                while ((ch = getc(*sfptr)) != EOF)
                {
                    if (ch == ' ')
                        printf(" ");
                    else if (ch == '\t')
                        printf("\t");
                    else
                        printf("%c", ch);
                }
                fclose(*sfptr);
                // free(fileName);
                *fileName = NULL;
            }

}

int getLineCount(FILE**sfptr)
{
            char c;
            int count = -11;//skipping heading
            for (c = getc(*sfptr); c != EOF; c = getc(*sfptr))
            {
                if (c == '\n') // Increment count if this character is newline
                    count = count + 1;
            }
            return count;
}
