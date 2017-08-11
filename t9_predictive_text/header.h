
/*
    Adolfo Pineda, CSE 374, 07/20/2017,
    Homework 5: C data structures.

    Header file that contains all the function
    prototypes, libraries, and structs for the
    trie and t9 programs.

*/

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A single list node.
struct Node {
    char* string;
    struct Node* link[10];
};

int whichDigit(char letter);
char* trim(char* s);
void freeTree(struct Node*);
void makeTree(struct Node*, char*);
struct Node* form_node(char* word);
void findWord(struct Node*, char*);

#endif
