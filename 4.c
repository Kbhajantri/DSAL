#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 50

void push(char [], int *, char);
char pop(char [], int *);
int precedence(char);

int main() {
    int i, j=0;
    char infixExpr[50], stack[50], postfixExpr[50], symbol;
    int top = -1;

    printf("\nEnter a valid infix expression\n");
    scanf("%s", infixExpr);
    push(stack, &top, '#'); // Push '#' onto the stack to mark the end

    for(i=0; infixExpr[i]!='\0'; ++i) {
        symbol = infixExpr[i];
        if(isalnum(symbol)) {
            postfixExpr[j++] = symbol;
        } else if(symbol == '(') {
            push(stack, &top, symbol);
        } else if(symbol == ')') {
            while(stack[top] != '(') {
                postfixExpr[j++] = pop(stack, &top);
            }
            pop(stack, &top); // Pop '('
        } else {
            while(precedence(stack[top]) >= precedence(symbol)) {
                if(stack[top] != '(' && stack[top] != '#') {
                    postfixExpr[j++] = pop(stack, &top);
                } else {
                    break;
                }
            }
            push(stack, &top, symbol);
        }
    }
    while(stack[top] != '#') {
        postfixExpr[j++] = pop(stack, &top);
    }
    postfixExpr[j] = '\0';

    printf("\nInfix Expression is %s\n", infixExpr);
    printf("\nPostfix Expression is %s\n", postfixExpr);

    return 0;
}

void push(char Stack[], int *top, char element) {
    *top = *top + 1;
    Stack[*top] = element;
}

char pop(char Stack[], int *top) {
    char element;
    element = Stack[*top];
    *top = *top - 1;
    return element;
}

int precedence(char ch) {
    int precVal;
    switch(ch) {
        case '#' : precVal = -1; break;
        case '(' : precVal = 0; break;
        case '+' :
        case '-' : precVal = 1; break;
        case '*' :
        case '/' :
        case '%' : precVal = 2; break;
        case '^' : precVal = 3; break;
        default: precVal = -2; break; // Assuming other operators have lowest precedence
    }
    return precVal;
}
