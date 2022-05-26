#include "func.h"

int main(){
    int rc;
    Node *tree = NULL;

    while((rc = dialog(msgs, NMsgs))){

        if(rc == 0)
        break;

        if (rc == 1){
            tree = D_Add(tree);
            if (tree != NULL)
            printf("Key was inserted!\n");
            printf("\n");
        }

        if(rc == 2){
            Node *tmp = D_Find(tree);
            if(tmp != NULL){
                D_Del(tmp);
                printf("Key was deleted\n");
            }
            else
            printf("Key was not found\n");
        }

        if (rc == 3){
            Node *tmp = D_Find(tree);
            if(tmp != NULL)
            printf("key: %d | info: %d\n", tmp->key, tmp->info);
            else
            printf("Key was not found\n");
        }

        if (rc == 4){
            Node *tmp = S_Find(tree);
            if(tmp != NULL)
            printf("key: %d | info: %d\n", tmp->key, tmp->info);
            else
            printf("Key doesnt exist\n");
        }

        if (rc == 5)
        print(tree);
    }
    printf("That's all. Bye!\n");
    clear(tree);
    return 0;
}



