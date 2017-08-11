
/*
    Adolfo Pineda, CSE 374, 07/20/2017,
    Homework 5: C data structures.

    This program builds the trie data structure,
    a version of the search tree, to be used with
    the t9 predictive text program.

*/

#ifndef TRIE_C
#define TRIE_C

#include "header.h"

// Returns a new node that contains a null tail field
// and the word that is passed in.
struct Node* form_node(char* word) {
    struct Node* ans = (struct Node*)malloc(sizeof(struct Node));
    if (word != NULL) {
        ans->string = (char*)malloc(sizeof(char)*strlen(word));
        strncpy(ans->string, word, strlen(word));
    } else {
        ans->string = NULL;
    }
    for (int i = 0; i < 10; i++) {
        ans->link[i] = NULL;
    }
    return ans;
}

// Passes in a word and a tree, then adds
// the new word onto the tree.
void makeTree(struct Node* root, char* word) {
    struct Node* temp = root;
    for (int i = 0; i < strlen(word); i++) {
        int val = whichDigit(word[i]);
        if (temp->link[val] == NULL) {
            if (i == strlen(word) - 1) {
                temp->link[val] = form_node(word);
            } else {
                temp->link[val] = form_node(NULL);
            }
            temp = temp->link[val];
        } else {
            // For the condition that the nodes already exist for
            // that word but does not have the word itself.
            if (i == strlen(word) - 1 && temp->link[val]->string == NULL) {
                temp->link[val]->string =
                    (char*)malloc(sizeof(char)*strlen(word));
                strncpy(temp->link[val]->string, word, strlen(word));
            // For the condition that there's more than one word for
            // the same number sequence.
            } else if (i == strlen(word) - 1 &&
                (strcmp(temp->link[val]->string, word) != 0)) {
                temp = temp->link[val];
                while (temp->link[0] != NULL) {
                    temp = temp->link[0];
                }
                temp->link[0] = form_node(word);
            } else {
                temp = temp->link[val];
            }
        }
    }
}

// Passes in the tree and the word to be searched for.
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

#endif
