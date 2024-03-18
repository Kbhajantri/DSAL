#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *lbranch;
    struct node *rbranch;
};

typedef struct node* NODEPTR;

NODEPTR fnGetNode(void);
void fnFreeNode(NODEPTR x);
NODEPTR fnInsertNode(int iItem, NODEPTR root);
void fnInOrder(NODEPTR root);
void fnPreOrder(NODEPTR root);
void fnPostOrder(NODEPTR root);
void fnSearchBST(NODEPTR root, int iElem);

int main() {
    NODEPTR root = NULL;
    int iItem1, iItem2;

    printf("Create a BST of 2 Integers\n");

    printf("\nEnter the first number: ");
    scanf("%d", &iItem1);
    root = fnInsertNode(iItem1, root);

    printf("\nEnter the second number: ");
    scanf("%d", &iItem2);
    root = fnInsertNode(iItem2, root);

    for(;;) {
        int iChoice;
        printf("\n1. Inorder traversal\n2. Preorder traversal\n3. Postorder traversal\n4. Search\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &iChoice);

        switch(iChoice) {
            case 1:
                if(root == NULL) {
                    printf("\nTree is Empty\n");
                } else {
                    printf("\nInorder Traversal is :\n");
                    fnInOrder(root);
                    printf("\n");
                }
                break;
            case 2:
                if(root == NULL) {
                    printf("\nTree is Empty\n");
                } else {
                    printf("\nPreorder Traversal is :\n");
                    fnPreOrder(root);
                    printf("\n");
                }
                break;
            case 3:
                if(root == NULL) {
                    printf("\nTree is Empty\n");
                } else {
                    printf("\nPostorder Traversal is :\n");
                    fnPostOrder(root);
                    printf("\n");
                }
                break;
            case 4:
                printf("\nEnter the element to be searched : ");
                int iElem;
                scanf("%d", &iElem);
                fnSearchBST(root, iElem);
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong choice\n");
                break;
        }
    }

    return 0;
}

NODEPTR fnGetNode(void) {
    NODEPTR x = (NODEPTR)malloc(sizeof(struct node));
    if(x == NULL) {
        printf("\nOut of Memory");
        exit(0);
    }
    return x;
}

void fnFreeNode(NODEPTR x) {
    free(x);
}

NODEPTR fnInsertNode(int iItem, NODEPTR root) {
    NODEPTR temp, prev, cur;
    temp = fnGetNode();
    temp->info = iItem;
    temp->lbranch = NULL;
    temp->rbranch = NULL;

    if(root == NULL)
        return temp;

    prev = NULL;
    cur = root;

    while(cur != NULL) {
        prev = cur;

        if(iItem == cur->info) {
            printf("\nDuplicate items not allowed\n");
            fnFreeNode(temp);
            return root;
        }

        cur = (iItem < cur->info) ? cur->lbranch : cur->rbranch;
    }

    if(iItem < prev->info)
        prev->lbranch = temp;
    else
        prev->rbranch = temp;

    return root;
}

void fnPreOrder(NODEPTR root) {
    if(root != NULL) {
        printf("%d\t", root->info);
        fnPreOrder(root->lbranch);
        fnPreOrder(root->rbranch);
    }
}

void fnInOrder(NODEPTR root) {
    if(root != NULL) {
        fnInOrder(root->lbranch);
        printf("%d\t", root->info);
        fnInOrder(root->rbranch);
    }
}

void fnPostOrder(NODEPTR root) {
    if(root != NULL) {
        fnPostOrder(root->lbranch);
        fnPostOrder(root->rbranch);
        printf("%d\t", root->info);
    }
}

void fnSearchBST(NODEPTR root, int iElem) {
    if(root != NULL) {
        if(iElem < root->info)
            fnSearchBST(root->lbranch, iElem);
        else if(iElem > root->info)
            fnSearchBST(root->rbranch, iElem);
        else
            printf("\n%d is found in the BST\n", iElem);
    } else {
        printf("\n%d is not found in the BST\n", iElem);
    }
}
