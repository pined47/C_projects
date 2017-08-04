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
    int val;
    char* string;
    struct Node* sequence;
    struct Node* link[10];
};

void makeTree(struct Node*, char*);
struct Node* form_node(int, char*);
//void print(struct Node*);
int whichDigit(char);
void findWord(struct Node*, char*);
void findWordOld(struct Node*, char*);
char* trim (char*);

int main(int argc, char** argv) {
    //char* list = argv[1];
    FILE* inputFile;
    inputFile = fopen(argv[1], "r");
    
    //inputFile = fopen(list, "r");
    
    /*if (inputFile == NULL) {
       /fprintf(stderr, "File %s could not be read\n", list);
        exit(0);
    }*/
    
    struct Node * root = form_node(20, NULL);
    //struct Node * root = (struct Node*)malloc(sizeof(struct Node));
    //root->val = 20; // filler, this is the root node
    //root->string = NULL;
    
    /*char letter;
    letter = 'a';
    letter = letter + 3;
    printf("%d\n", letter);
    printf("%c\n", letter);
    int digit = whichDigit(letter);
    printf("%d\n", digit);
    int digit2 = whichDigit('z');
    printf("%d\n", digit2);*/
    
    
    /*char word[] = "abs"; // 227
    char* wordPtr = word;
    
    char otherWord[] = "dave"; // 3283
    char* otherWordPtr = otherWord;
    
    char word1[] = "cat"; // 228
    char* wordPtr1 = word1;
    
    char word2[] = "ab";
    char* wordPtr2 = word2;
    
    char word3[] = "ba";
    char* wordPtr3 = word3;
    
    char word4[] = "ca";
    char* wordPtr4 = word4;
    
    char word5[] = "cap";
    char* wordPtr5 = word5;
    
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    
    root->val = 20; // filler, this is the root node
    root->string = NULL;
    //makeTree(root, wordPtr);
    
    struct Node* temp = root;
    
    
    //printf("Check 1\n");
    makeTree(root, wordPtr);
    makeTree(root, otherWordPtr);
    makeTree(root, wordPtr1);   
    //printf("Check 2\n");
    makeTree(root, wordPtr2);
    makeTree(root, wordPtr3);
    makeTree(root, wordPtr4);
    makeTree(root, wordPtr5);
    //printf("Check 3\n");
    
    temp = root;
    findWord(temp, wordPtr);
    temp = root;
    findWord(temp, otherWordPtr);
    temp = root;
    findWord(temp, wordPtr1);
    temp = root;
    
    temp = temp->link[2];
    temp = temp->link[2];
    printf("%s\n", temp->string);
    if(temp->sequence != NULL) {
        temp = temp->sequence;
        printf("%s\n", temp->string);
    }
    
    if(temp->sequence != NULL) {
        temp = temp->sequence;
        printf("%s\n", temp->string);
    }
    
    temp = root;
    temp = temp->link[2];
    temp = temp->link[2];
    temp = temp->link[7];
    
    if(temp->sequence != NULL) {
        temp = temp->sequence;
        printf("%s\n", temp->string);
    }
    //temp = root;*/
    
    
    
    //temp = root;
    //findWord(temp, otherWordPtr);
    
    /*makeTree(root, wordPtr1);
    temp = root;
    findWord(temp, wordPtr1);*/
    
    char str[100];
    //int j;
    while ((fgets(str, 100, inputFile)) != NULL) {
    //for (j = 0; j < 40; j++) {
        //fgets(str, 100, inputFile);
        /* int size = strlen(str) - 2;
        printf("Size of string is %d\n", size);
        char strCopy[size];
        printf("Size of string is %d\n", size);
        int i = 0;
        while(str[i] != '\n') {
            strCopy[i] = str[i];
            i++;
        } */
        
        /* //for (int i = 0; i < size; i++) {
            char c = str[i];
            if(c >= 97 && c <= 122) {
                strCopy[i] = str[i];
            }    
        //} */
        
        //strncpy(strCopy, str, strlen(str));
        //printf("%d\n", strlen(str));
        
        char* strTrim = trim(str);
        
        //printf("%s\n", str);
        //printf("Fuck this other shit\n");
        //printf("%s\n", str);
        //printf("%s\n", strTrim);
        //printf("%d\n", strlen(str));
        //printf("%d\n", strlen(strTrim));
        //printf("\n");
        makeTree(root, strTrim);
        //findWordOld(root, strTrim);
        
    }
    
    int sum[100];
    char input[100];
    
    int numCount = 0;
    printf("Enter \"exit\" to quit.\n");
    printf("Enter Key Sequence (or \"#\" for next word):\n");
    fgets(input, 100, stdin);
    int enable = 0;
    while (strcmp(input, "exit\n") != 0) {
        if (feof(stdin)) {
            break;
        }
        char inputCopy[100] = ""; // FOR SOME FUCKING REASON, IT STAYS THE SAME
        
        //printf("character: %c\n", input[0]);
        //printf("string: %s\n", input);
        //printf("length: %d\n", strlen(input));
        strncpy(inputCopy, input, strlen(input));
        trim(inputCopy);
        findWord(root, inputCopy);
        /*strncpy(inputCopy, input, strlen(input));
        trim(inputCopy);
        printf("%s outside the loop\n", inputCopy);
        printf("%d outside the loop\n", strlen(inputCopy));
        findWord(root, inputCopy);*/
        //printf("Enter \"exit\" to quit.\n");
        printf("Enter Key Sequence (or \"#\" for next word):\n");
        fgets(input, 100, stdin);
        if (strcmp(input, "#\n") == 0) {
            enable = 1;
            while (strcmp(input, "#\n") == 0) {
                strncat(inputCopy, input, strlen(inputCopy + 1));
                trim(inputCopy);
                findWord(root, inputCopy);
                printf("Enter Key Sequence (or \"#\" for next word):\n");
                fgets(input, 100, stdin);
            }
        }
        //printf("decimal value: %d\n", inputCopy[0]);
        //printf("length: %d\n", strlen(inputCopy));
    }
    
    //////////////////////////
    // CURRENT TESTS 7/6/17 //
    //////////////////////////
    
    /*char word[] = "abs"; // 227
    char otherWord[] = "aardvark"; // 22738275
    char word2[] = "zebra"; // 93272
    
    makeTree(root, otherWord);
    makeTree(root, word);
    makeTree(root, word2);
    //printf("here maybe?\n");
    findWordOld(root, word);
    findWordOld(root, otherWord);
    findWordOld(root, word2);*/
    
    /*char word[] = "zymogen";
    //char* wordPtr = word;
 
    char word1[] = "able"; // 2229
    char* wordPtr1 = word1;
    
    char otherWord[] = "aardvark"; // 22738275
    char* otherWordPtr = otherWord;
    
    char word2[] = "abs";
    
    char word3[] = "zebra";*/ // 93272
    
    //char word2[] = "bas"; // 227
    //char* wordPtr2 = word2;
    
    //char word3[] = "cas"; // 227
    //char* wordPtr3 = word3;
    
    //makeTree(root, otherWord);
    //makeTree(root, word);
    //makeTree(root, word1);
    //makeTree(root, word2);
    //makeTree(root, word3);
    
    /*findWordOld(root, word);
    findWordOld(root, word1);
    findWordOld(root, word2);
    //findWord(root, word2);
    //findWord(root, otherWord);
    //findWord(root, otherWord);
    //findWord(root, word1);*/
    
    return 0;
}

void makeTree (struct Node* root, char* word) {
    
    struct Node* temp = root;
    for(int i = 0; i < strlen(word); i++) {
        int val = whichDigit(word[i]);
        //printf("%d", val);
        if(temp->link[val] == NULL) {
            if (i == strlen(word) - 1) {
                //printf("zebra should go in here: %s\n", word);
                temp->link[val] = form_node(val, word);
            } else {
                temp->link[val] = form_node(val, NULL);
            }
            temp = temp->link[val];
        } else {
            
            //if (temp->link[val]->string != NULL && i == strlen(word) - 1) {
            if (i == strlen(word) - 1 && temp->link[val]->string == NULL) {
                temp->link[val]->string = (char*)malloc(sizeof(char)*strlen(word));
                temp->link[val]->string = strncpy(temp->link[val]->string, word, strlen(word));
                //printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
                //printf("the word %s made it in here\n", word);
                //printf("this is the word that's being copied: %s\n", temp->link[val]->string = word);
            } else if (i == strlen(word) - 1 && (strcmp(temp->link[val]->string, word) != 0)) {
                //printf("point fity five\n");
                //printf("(I expect bas to be in here) the word %s made it in here\n", word);
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
            //printf("%s\n", temp->string);
            //printf("%d\n", i);
            //printf("%d\n", strncmp(temp->string, word, strlen(word)));
            /*if(i == strlen(word) - 1) {
                if(temp->string != NULL) {
                    int compare = strncmp(temp->string, word, strlen(word));
                    //printf("%s\n", temp->string);
                    //printf("%s\n", word);
                    //printf("%d\n", strncmp(temp->string, word, strlen(word)));
                    if (compare != 0) {
                        //printf("%s\n", temp->string);
                        //printf("made it in here\n");
                        while(temp != NULL) {
                            if(temp->sequence == NULL) {
                                temp->sequence = form_node(val, word);
                                temp = temp->sequence;
                            }
                            temp = temp->sequence;
                        }
                    }
                } else {
                    temp->string = word;
                }
            //}
            //temp = temp->link[val];
        }
    }*/
    
}


// Return a new linked list containing the integers in p[0..len-1]
/*struct List * from_array(int len, int* p) {
  struct List * ans = NULL;
  int i;
  //for (i = len-1; i >= 0; --i) {
  for (i = 7; i>= 0; --i) {
    struct List * next = from_int(p[i + 2]);
    next->tail = ans;
    ans = next;
  }
  return ans;
}*/

// Print lst to stdout
void findWord(struct Node* root, char* word) {
    //temp = temp->link[whichDigit(word[0])];
    struct Node* temp = root;
    for (int i = 0; i < strlen(word); i++) {
        int val = (int)word[i] - 48;
        int numSign = (int)word[i];
        //if (strcmp(word[i], '#') != 0) {
        if (numSign != 35) {
        //int val = whichDigit(); // 2
            if (temp->link[val] != NULL) {
                temp = temp->link[val];
                if (i == (strlen(word) - 1)) {
                    if(temp->string != NULL) {
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
        /*if (temp->string != NULL) {
            printf("%s\n", temp->string);
        }*/
        /*if(temp != NULL) {
            printf("%d", temp->val);
        } else {
            printf("    Not found in current dictionary.\n");
            break;
        }*/
        //temp = temp->link[val];
    }
    //printf("\n");
    
    /*if (temp->string != NULL) {
        printf("    '%s'\n", temp->string);
    } else {
        printf("    Not found in current dictionary.\n");
    }*/
    /*if (temp->string != NULL) {
        printf("this is the word i'm looking for: %s\n", word);
        printf("this is the word that's in here : %s\n", temp->string);
        if (strcmp(temp->string, word) != 0) {
        printf("point 3\n");
        while(strcmp(temp->string, word) != 0) {
            temp = temp->link[0];
        }
            printf("This is the word you're looking for huh? %s\n", temp->string);
        }
        //printf("this is the word that's found: %s\n", temp->string);
    }*/
    //printf("this is the word i'm looking for: %s\n", word);
    /*if (temp->string != NULL) {
        printf("this is the word that's found: %s\n", temp->string);
    }*/
    
    /*if (strcmp(temp->string, word) != 0) {
        printf("point 3\n");
        while(strcmp(temp->string, word) != 0) {
            temp = temp->link[0];
        }
        printf("This is the word you're looking for huh? %s\n", temp->string);
    }*/
    //printf("%s\n", temp->string);
    /*if(temp->sequence != NULL) {
        temp = temp->sequence;
        printf("%s\n", temp->string);
    }*/
    //while (lst != NULL) {
        
    //}
    
    /*printf("[");
    while (lst != NULL) {        // could just say while (lst) ...
        printf(" %d ", lst->val);
        if (lst->link == NULL) {
            printf("%s\n", lst->string);
        }
        lst = lst->link;
    }
    
    printf("]\n");*/
}


// Print lst to stdout
void findWordOld(struct Node* root, char* word) {
    //temp = temp->link[whichDigit(word[0])];
    struct Node* temp = root;
    for (int i = 0; i < strlen(word); i++) {
        int val = whichDigit(word[i]); // 2
        temp = temp->link[val];
        /*if (temp->string != NULL) {
            printf("%s\n", temp->string);
        }*/
        if(temp != NULL) {
            printf("%d", temp->val);
        } else {
            printf("Oh shit son back the fuck up\n");
            break;
        }
        //temp = temp->link[val];
    }
    printf("\n");
    printf("this is the word i'm looking for: %s\n", word);
    if (temp->string != NULL) {
        printf("this is the word that's found: %s\n", temp->string);
    }
    if (strcmp(temp->string, word) != 0) {
        printf("point 3\n");
        while(strcmp(temp->string, word) != 0) {
            temp = temp->link[0];
        }
        printf("This is the word you're looking for huh? %s\n", temp->string);
    }
    //printf("%s\n", temp->string);
    /*if(temp->sequence != NULL) {
        temp = temp->sequence;
        printf("%s\n", temp->string);
    }*/
    //while (lst != NULL) {
        
    //}
    
    /*printf("[");
    while (lst != NULL) {        // could just say while (lst) ...
        printf(" %d ", lst->val);
        if (lst->link == NULL) {
            printf("%s\n", lst->string);
        }
        lst = lst->link;
    }
    
    printf("]\n");*/
}

// return a new node containing integer x and a null tail field
struct Node* form_node(int x, char* word) {
    struct Node* ans = (struct Node*)malloc(sizeof(struct Node));
    //ans->string = strdup(word);
    //ans->string = (char*)malloc(100);
    if (word != NULL) {
        //ans->string = strdup(word);
        ans->string = (char*)malloc(sizeof(char)*strlen(word));
        ans->string = strncpy(ans->string, word, strlen(word));
    } else {
        ans->string = NULL;
    }
    ans->val = x;
    //ans->string = word;
    ans->sequence = NULL;
    int i;
    for(i = 0; i < 10; i++) {
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

char *trim (char *s) {
    int i = strlen(s) - 1;
    if ((i > 0) && (s[i] == '\n'))
        s[i] = '\0';
    return s;
}