#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 4

bool isStackFull(int);
bool isStackEmpty(int);
void push(int [], int, int*);
int pop(int [], int*);
void display(int[], int);
int peek(int [], int);
bool checkPalindrome(int); 

int main(void) {
    int stackArray[MAX];
    int top = -1;
    int element, choice;

    for(;;) {
        printf("\nSTACK OPERATIONS\n");
        printf("====================");
        printf("\n 1.Push\n 2.Pop\n 3.Display\n 4.Peek\n 5.CheckPalindrome\n 6.Demonstrate Overflow\n 7.Demonstrate Underflow\n 8.EXIT\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (!isStackFull(top)) {
                    printf("\nEnter element to be pushed onto the stack\n");
                    scanf("%d", &element);
                    push(stackArray, element, &top);
                } else {
                    printf("\nStack Overflow\n");
                }
                break;

            case 2:
                if (!isStackEmpty(top)) {
                    element = pop(stackArray, &top);
                    printf("\nPopped Element is %d\n", element);
                } else {
                    printf("\nStack Underflow\n");
                }
                break;

            case 3:
                if (!isStackEmpty(top)) {
                    display(stackArray, top);
                } else {
                    printf("\nStack Empty\n");
                }
                break;

            case 4:
                if (!isStackEmpty(top)) {
                    element = peek(stackArray, top);
                    printf("\nElement at the top of the stack is %d\n", element);
                } else {
                    printf("\nEmpty Stack\n");
                }
                break;

            case 5:
                printf("\nEnter number to be checked for a palindrome : ");
                scanf("%d", &element);
                if (checkPalindrome(element)) {
                    printf("\n%d is a palindrome\n", element);
                } else {
                    printf("\n%d is not a palindrome\n", element);
                }
                break;

            case 6:
                if (!isStackFull(top)) {
                    printf("\nThere are currently %d elements in Stack\nPush %d elements for Stack to overflow", top + 1, MAX - (top + 1));
                    while (!isStackFull(top)) {
                        printf("\nEnter an element : ");
                        scanf("%d", &element);
                        push(stackArray, element, &top);
                    }
                    printf("\nStack Overflow cannot push elements onto the stack\n");
                }
                break;

            case 7:
                if (!isStackEmpty(top)) {
                    printf("\nThere are currently %d elements in Stack\nPop out %d elements for Stack to Underflow", top + 1, MAX - (top + 1));
                    while (!isStackEmpty(top)) {
                        element = pop(stackArray, &top);
                        printf("\nPopped Element is %d\n", element);
                    }
                    printf("\nStack Underflow cannot pop elements from the stack\n");
                }
                break;

            case 8:
                exit(1);

            default:
                printf("\nWrong choice\n");
        }
    }

    return 0;
}

bool isStackFull(int top) {
    return top == MAX - 1;
}

bool isStackEmpty(int top) {
    return top == -1;
}

void push(int stack[], int element, int *top) {
    *top = *top + 1;
    stack[*top] = element;
}

int pop(int stack[], int *top) {
    int element;
    element = stack[*top];
    *top = *top - 1;
    return element;
}

void display(int stack[], int top) {
    int i;
    printf("\nStack Contents are: \n");
    for(i = top; i > -1; --i) {
        printf("\t%d\n", stack[i]);
    }
    printf("Stack has %d elements\n", top + 1);
}

int peek(int stack[], int top) {
    return stack[top];
}

bool checkPalindrome(int value) {
    int palindromeStack[10];
    int t = -1, digit, reversed = 0;
    int copyValue = value;
    
    while (copyValue != 0) {
        digit = copyValue % 10;
        push(palindromeStack, digit, &t);
        copyValue /= 10;
    }
    
    int p = 0;
    while (p <= t) {
        digit = palindromeStack[p];
        reversed = reversed * 10 + digit;
        p++;
    }
    
    return reversed == value;
}
