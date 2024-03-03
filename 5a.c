#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void push(int [], int*, int);
int pop(int [], int*);

int main() {
    int stack[50], i, op1, op2, result;
    char expression[50], symbol;
    int top = -1;

    printf("\nEnter a valid postfix expression\n");
    scanf("%s", expression);

    for(i = 0; i < strlen(expression); i++) {
        symbol = expression[i];
        if(isdigit(symbol)) {
            push(stack, &top, symbol - '0'); // Convert character to integer
        } else {
            op2 = pop(stack, &top);
            op1 = pop(stack, &top);
            switch(symbol) {
                case '+' : result = op1 + op2; break;
                case '-' : result = op1 - op2; break;
                case '*' : result = op1 * op2; break;
                case '/' : result = op1 / op2; break;
                case '%' : result = op1 % op2; break;
                case '^' : result = (int)pow(op1, op2); break;
            }
            push(stack, &top, result);
        }
    }
    result = pop(stack, &top);
    printf("\nValue of %s expression is %d\n", expression, result);

    return 0;
}

void push(int stack[], int *top, int element) {
    (*top)++;
    stack[*top] = element;
}

int pop(int stack[], int *top) {
    int element = -1; // Default value if stack is empty
    if (*top >= 0) { // Check if the stack is not empty
        element = stack[*top];
        (*top)--;
    }
    return element;
}
