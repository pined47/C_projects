
/*
the number 0 represents a space
1 represents a set of symbols such as { , . ! ? } etc
2 ABC 
3 DEF 
4 GHI 
5 JKL 
6 MNO
7 PQRS 
8 TUV 
9 WXYZ

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// a single list node
struct Node {
    char* string;
    int val;
    struct Node* link[10];
};

void makeTree(struct Node*, char*);
void freeTree(struct Node*);
struct Node* form_node(int, char*);
int whichDigit(char letter);
void findWord(struct Node*, char*);
char* trim(char* s);

int main(int argc, char** argv) {
    FILE* inputFile;
    inputFile = fopen(argv[1], "r");
    struct Node * root = form_node(20, NULL);
    char str[100];
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


void makeTree(struct Node* root, char* word) {
    struct Node* temp = root;
    for (int i = 0; i < strlen(word); i++) {
        int val = whichDigit(word[i]);
        if (temp->link[val] == NULL) {
            if (i == strlen(word) - 1) {
                temp->link[val] = form_node(val, word);
            } else {
                temp->link[val] = form_node(val, NULL);
            }
            temp = temp->link[val];
        } else {
            if (i == strlen(word) - 1 && temp->link[val]->string == NULL) {
                temp->link[val]->string =
                    (char*)malloc(sizeof(char)*strlen(word));
                strncpy(temp->link[val]->string, word, strlen(word));
            } else if (i == strlen(word) - 1 &&
                (strcmp(temp->link[val]->string, word) != 0)) {
                temp = temp->link[val];
                while (temp->link[0] != NULL) {
                    temp = temp->link[0];
                }
                temp->link[0] = form_node(20, word);
            } else {
                temp = temp->link[val];
            }
        }
    }
}

// Print lst to stdout
void findWord(struct Node* root, char* word) {
    struct Node* temp = root;
    for (int i = 0; i < strlen(word); i++) {
        int val = (int)word[i] - 48;
        int numSign = (int)word[i];
        if (numSign != 35) {
            if (temp->link[val] != NULL) {
                temp = temp->link[val];
                if (i == (strlen(word) - 1)) {
                    if (temp->string != NULL) {
                        printf("    '%s'\n", temp->string);
                    } else {
                        printf("    Not found in current dictionary.\n");
                        break;
                    }
                }
            } else {
                printf("    Not found in current dictionary.\n");
                break;
            }
        } else if (numSign == 35) {
            if (temp->link[0] != NULL) {
                temp = temp->link[0];
                if (i == (strlen(word) - 1)) {
                    printf("    '%s'\n", temp->string);
                }
            } else {
                printf("    There are no more T9onyms\n");
                printf("\n");
                break;
            }
        } else {
            printf("    Not found in current dictionary.\n");
            break;
        }
    }
}

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

// return a new node containing integer x and a null tail field
struct Node* form_node(int x, char* word) {
    struct Node* ans = (struct Node*)malloc(sizeof(struct Node));
    if (word != NULL) {
        ans->string = (char*)malloc(sizeof(char)*strlen(word));
        //ans->string = strncpy(ans->string, word, strlen(word));
        strncpy(ans->string, word, strlen(word));
    } else {
        ans->string = NULL;
    }
    ans->val = x;
    int i;
    for (i = 0; i < 10; i++) {
        ans->link[i] = NULL;
    }
    return ans;
}

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

char *trim(char *s) {
    int i = strlen(s) - 1;
    if ((i > 0) && (s[i] == '\n'))
        s[i] = '\0';
    return s;
}
