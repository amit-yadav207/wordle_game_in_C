bool isCorrectGuess(char *guess, char *ans, char *letters, int *score,char* usedLetters);
void clear();
void hrline();
void gameHeading(char* color,char* difLevel);
void printInsructs(int total_atmpts);
void setDiffLevel(int*total_atmpts,char**difLevel,char**fileName,char**color);
void getRandomWord(FILE**fptr,char**chosenWord);
void getInput(char**color,char**userInput,int num_of_atmpts);
void viewScoreBoard(FILE**sfptr,char**fileName);
int getLineCount(FILE**sfptr);