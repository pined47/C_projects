
/*
    Adolfo Pineda, CSE 374, 07/20/2017,
    Homework 5: C data structures.

    This program emulates the T9 predictive
    text that the first cellphones with text
    messaging used. Below is a legend of the
	numbers with their corresponding letters:

	2 ABC 
	3 DEF 
	4 GHI 
	5 JKL 
	6 MNO
	7 PQRS
	8 TUV 
	9 WXYZ
    
*/

#ifndef T9_C
#define T9_C

#include "header.h"

// Uses a dictionary (list of words) to build and run
// the t9 predictive text program.
int main(int argc, char** argv) {
    FILE* inputFile;
    inputFile = fopen(argv[1], "r");
    struct Node * root = form_node(NULL);
    char str[100];
    // Creates the tree using the passed in dictionary
    while ((fgets(str, 100, inputFile)) != NULL) {
        char* strTrim = trim(str);
        makeTree(root, strTrim);
    }
    char input[100];
    printf("Enter \"exit\" to quit.\n");
    printf("Enter Key Sequence (or \"#\" for next word):\n");
    fgets(input, 100, stdin);
    while (strcmp(input, "exit\n") != 0) {
        if (feof(stdin)) {
            break;
        }
        char inputCopy[100] = "";
        strncpy(inputCopy, input, strlen(input));
        trim(inputCopy);
        findWord(root, inputCopy);
        printf("Enter Key Sequence (or \"#\" for next word):\n");
        fgets(input, 100, stdin);
        if (strcmp(input, "#\n") == 0) {
            while (strcmp(input, "#\n") == 0) {
                strncat(inputCopy, input, strlen(inputCopy + 1));
                trim(inputCopy);
                findWord(root, inputCopy);
                printf("Enter Key Sequence (or \"#\" for next word):\n");
                fgets(input, 100, stdin);
            }
        }
    }
    freeTree(root);
    fclose(inputFile);
    return 0;
}

// Deallocates memory used by the program.
void freeTree(struct Node* root) {
    if (root != NULL) {
        for (int i = 0; i < 10; i++) {
            if (root->link[i] != NULL) {
                freeTree(root->link[i]);
            }
        }
        if (root->string != NULL) {
            free(root->string);
        }
        free(root);
    }
}

// Passes in a letter and returns the integer
// value associated with that letter.
int whichDigit(char letter) {
    int digit[26];
    digit[0] = 2;
    digit[1] = 2;
    digit[2] = 2;
    digit[3] = 3;
    digit[4] = 3;
    digit[5] = 3;
    digit[6] = 4;
    digit[7] = 4;
    digit[8] = 4;
    digit[9] = 5;
    digit[10] = 5;
    digit[11] = 5;
    digit[12] = 6;
    digit[13] = 6;
    digit[14] = 6;
    digit[15] = 7;
    digit[16] = 7;
    digit[17] = 7;
    digit[18] = 7;
    digit[19] = 8;
    digit[20] = 8;
    digit[21] = 8;
    digit[22] = 9;
    digit[23] = 9;
    digit[24] = 9;
    digit[25] = 9;
    return digit[letter - 97];
}

// Trims the string that's passed in.
char *trim(char *s) {
    int i = strlen(s) - 1;
    if ((i > 0) && (s[i] == '\n'))
        s[i] = '\0';
    return s;
}

#endif
