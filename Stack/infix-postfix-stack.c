#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

// ==========================================
// 1. Stack for Characters (Used in Infix -> Postfix)
// ==========================================
char charStack[MAX];
int charTop = -1;

void pushChar(char c) {
    charStack[++charTop] = c;
}

char popChar() {
    return charStack[charTop--];
}

char peekChar() {
    return charStack[charTop];
}

int isCharStackEmpty() {
    return charTop == -1;
}

// Operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Convert Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if (c == ' ') continue; // Ignore spaces

        // If operand (alphanumeric), add directly to output
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // Left parenthesis: push to stack
        else if (c == '(') {
            pushChar(c);
        }
        // Right parenthesis: pop until '(' is encountered
        else if (c == ')') {
            while (!isCharStackEmpty() && peekChar() != '(') {
                postfix[j++] = popChar();
            }
            popChar(); // Remove '(' from stack
        }
        // Operator
        else {
            while (!isCharStackEmpty() && peekChar() != '(' &&
                   precedence(peekChar()) >= precedence(c)) {
                postfix[j++] = popChar();
            }
            pushChar(c);
        }
    }

    // Pop remaining operators
    while (!isCharStackEmpty()) {
        postfix[j++] = popChar();
    }

    postfix[j] = '\0'; // Null-terminate string
}

// ==========================================
// 2. Stack for Integers (Used in Evaluation)
// ==========================================
int intStack[MAX];
int intTop = -1;

void pushInt(int val) {
    intStack[++intTop] = val;
}

int popInt() {
    return intStack[intTop--];
}

// Evaluate Postfix Expression
int evaluatePostfix(char postfix[]) {
    int i = 0;
    char c;

    while ((c = postfix[i++]) != '\0') {
        if (c == ' ') continue;

        // If digit, convert char to int and push
        if (isdigit(c)) {
            pushInt(c - '0');
        }
        // If operator, pop two operands and compute
        else {
            int b = popInt();
            int a = popInt();

            switch (c) {
                case '+': pushInt(a + b); break;
                case '-': pushInt(a - b); break;
                case '*': pushInt(a * b); break;
                case '/': pushInt(a / b); break;
                case '^': pushInt((int)pow(a, b)); break;
            }
        }
    }

    return popInt();
}

// ==========================================
// Main Function
// ==========================================
int main() {
    char infix[] = "(2 + 3) * 4";
    char postfix[MAX];

    // 1. Infix to Postfix
    infixToPostfix(infix, postfix);
    printf("Infix   : %s\n", infix);
    printf("Postfix : %s\n", postfix);

    // 2. Evaluate Postfix
    int result = evaluatePostfix(postfix);
    printf("Result  : %d\n", result);

    return 0;
}