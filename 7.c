#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char usn[11], name[40], prog[4];
    int sem;
    char ph[11];
    struct node *link;
};

typedef struct node* PTR;

PTR get(void);
void freeN(PTR);
PTR insrear(PTR);
PTR delfront(PTR);
PTR insfront(PTR);
PTR delrear(PTR);
void disp(PTR);

int main() {
    PTR first = NULL;
    int ch, num, i;
    printf("\nEnter the number of Students N : ");
    scanf("%d", &num);
    for(i = 0; i < num; i++) {
        printf("Enter Data for Node %d : ", i + 1);
        first = insfront(first);
    }
    for(;;) {
        printf("\nQUEUE OPERATIONS");
        printf("\n====================");
        printf("\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                first = insfront(first);
                break;
            case 2:
                first = insrear(first);
                break;
            case 3:
                first = delfront(first);
                break;
            case 4:
                first = delrear(first);
                break;
            case 5:
                disp(first);
                break;
            case 6:
                exit(0);
        }
    }
    return 0;
}

PTR get() {
    PTR newborn;
    newborn = (PTR)malloc(sizeof(struct node));
    if(newborn == NULL) {
        printf("\nMemory Overflow");
        exit(0);
    }
    printf("\nEnter USN : ");
    scanf("%s", newborn->usn);
    printf("Enter name : ");
    scanf("%s", newborn->name);
    printf("Enter Program name : ");
    scanf("%s", newborn->prog);
    printf("Enter semester : ");
    scanf("%d", &newborn->sem);
    printf("Enter Phone no : ");
    scanf("%s", newborn->ph);
    return newborn;
}

void freeN(PTR x) {
    free(x);
}

PTR insrear(PTR first) {
    PTR temp, cur;
    temp = get();
    temp->link = NULL;
    if(first == NULL)
        return temp;
    cur = first;
    while(cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}

PTR delfront(PTR first) {
    PTR temp;
    if(first == NULL) {
        printf("\nSLL is empty cannot delete");
        return first;
    }
    temp = first;
    first = first->link;
    printf("\nNode deleted is %s : ", temp->name);
    freeN(temp);
    return first;
}

void disp(PTR first) {
    PTR curr;
    int count = 0;
    if(first == NULL) {
        printf("\nSLL is empty ");
        return;
    }
    printf("\nThe contents of SLL are : ");
    curr = first;
    printf("\nUSN\t\tName\tProgram\tSem\tPhone num");
    while(curr != NULL) {
        printf("\n%10s\t%s\t%s\t%d\t%s", curr->usn, curr->name, curr->prog, curr->sem, curr->ph);
        curr = curr->link;
        count++;
    }
    printf("\n\nSLL has %d nodes", count);
}

PTR insfront(PTR first) {
    PTR temp;
    temp = get();
    temp->link = NULL;
    temp->link = first;
    first = temp;
    return first;
}

PTR delrear(PTR first) {
    PTR cur, prev;
    if(first == NULL) {
        printf("\nSLL is empty cannot delete");
        return first;
    }
    prev = NULL;
    cur = first;
    if(cur->link == NULL) {
        printf("\nNode deleted for %s : ", cur->name);
        freeN(cur);
        return NULL;
    }
    // Additional code for deleting rear not provided in the original code
    return first;
}
