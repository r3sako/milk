#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *msgs[6] ;
const int NMsgs ;

typedef struct Node{
    int key;
    char *info;
    struct Node *left;
    struct Node *right;
    struct Node *next;
    struct Node *parent;
}Node;

Node *max(Node *node);
void clear(Node *tree);
Node *S_Find(Node *tree);
void D_Del(Node *tree);
Node *D_Find(Node *tree);
void print(Node *tree);
Node *Next(Node *x);
void print(Node *tree);
Node *insert(Node *tree, int k, char *info);
int dialog(const char *msgs[], int N);
int getInt(int *a);
Node *D_Add(Node *tree);


