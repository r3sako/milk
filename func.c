#include "func.h"

const char *msgs[] = {"0. Quit", "1. Add", "2. Delete", "3. Find", "4. Special F", "5. Show"};
const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);

Node *min(Node *node){
    if (node){
        if (node->left != NULL)
        return min(node->left);
    }
    return node;
}

Node *max(Node *node){
    if (node){
        if (node->right != NULL)
        return max(node->right);
    }
    return node;
}

void clear(Node *tree){
    Node *p = min(tree);

    Node *ptr;
    Node *tmp;
    while(p != NULL){
	ptr = p->next;
	tmp = p->right;
	free(p->info);
	free(p);

        if (tmp == NULL)
        p = ptr;

        else
        p = min(tmp);
    }
    printf("\n");
}

Node *S_Find(Node *tree){
    int k, n;
    printf("Enter key: ");
    n = getInt(&k);
    if(n==0)
    return NULL;

    while (tree != NULL){
        if (tree->key > k){
            tree = tree->left;
        }
        else if (tree->key < k){
            tree = tree->right;
        }
        else{
            if (tree->right){
                tree = tree->right;
                return min(tree);
            }else
            return(tree->next);
        }
    }
    return tree;
}

Node *D_Find(Node *tree){
    int k, n;
    printf("Enter key: ");
    n = getInt(&k);
    if(n==0)
    return NULL;

    while (tree != NULL){
        if (tree->key > k){
            tree = tree->left;
        }
        else if (tree->key < k){
            tree = tree->right;
        }
        else{
            return tree;
        }
    }
    return tree;
}

void D_Del(Node *tree){
    if (tree->left && tree->right) {
        Node *locMin = min(tree->right);
        tree->key = locMin->key;
	free(tree->info);
	tree->info = malloc(sizeof(char)*strlen(locMin->info)+1);
        strcpy(tree->info, locMin->info);
        D_Del(locMin);
        return;
    } else if (tree->left) {
        if (tree == tree->parent->left) {
            tree->parent->left = tree->left;
            tree->left->parent = tree->parent;
	    Node *locMax = max(tree->left->right);
	    locMax->next = tree->next;
        } else {
            tree->parent->right = tree->left;
            tree->left->parent = tree->parent;
	    Node *locMax = max(tree->left->right);
	    locMax->next = tree->next;
        }
    } else if (tree->right) {
        if (tree == tree->parent->right) {
            tree->parent->right = tree->right;
            tree->right->parent = tree->parent;
        } else {
            tree->parent->left = tree->right;
            tree->right->parent = tree->parent;
        }
    } else {
        if (tree == tree->parent->left){
            tree->parent->left = NULL;
        } else {
            tree->parent->right = NULL;
        }
    }
    free(tree->info);
    free(tree);
}

void print(Node *tree){
    Node *p = min(tree);

    while(p != NULL){
        printf("(%d|%s) -> ", p->key, p->info);

        if (p->right == NULL)
        p = p->next;

        else
        p = min(p->right);
    }
    printf("\n");
}

Node *Next(Node *x){
    Node *ptr = NULL;

    if(x->right != NULL)
    return min(x);

    ptr = x->parent;

    while ((ptr != NULL)&&(ptr->key < x->key)){
        x = ptr;
        ptr = ptr->parent;
    }
    return ptr;
}

Node *insert(Node *tree, int k, char *info){
    static Node *parent = NULL;

    if(tree == NULL){
        Node *leaf =  malloc(sizeof(Node));
	leaf->info = malloc(sizeof(char)*(strlen(info)+1));
        strcpy(leaf->info, info);
        leaf->key = k;
        leaf->left = leaf->right = NULL;
        leaf->parent = parent;
        leaf->next = Next(leaf);
        return leaf;
    }

    parent = tree;
    if (tree->key >= k)
    tree->left = insert(tree->left, k, info);

    if (tree->key < k)
    tree->right = insert(tree->right, k, info);

    return tree;
}

int getInt(int *a){
    int e;

    do{
        e = scanf("%d", a);
        if (e < 0){
            return 0;
        }
        if (e == 0){
            printf("%s\n", "Error! Repeat input");
            scanf("%*c");
        }
    } while (e == 0);
    return 1;
}

Node *D_Add(Node *tree){
    int k, n;
    char *info;

    printf("Enter key: ");
    n = getInt(&k);
    if(n == 0)
    return 0;

    info = readline("Enter info: ");

    tree = insert(tree, k, info);
    free(info);
    return tree;
}

int dialog(const char *msgs[], int N){
    char *errmsg = "";
    int rc;
    int i, n;

    for(i = 0; i < N; ++i)
    puts(msgs[i]);

    do{
        puts(errmsg);
        errmsg = "You are wrong. Repeate, please!";
        puts("Make your choice: ");
        n = getInt(&rc);
        if(n == 0)
        rc = 0;
    }while(rc < 0 || rc >= N);

    return rc;
}

