#include <stdio.h>
#include <ctype.h>

#define MAX 10


char opStack[MAX];
int opTop = -1;

void pushChar(char c){
    opStack[++opTop] = c;
}

char popChar(){
    return opStack[opTop--];
}

char peekChar(){
    return (opTop == -1) ? '\0' : opStack[opTop];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void infixtopostfix(char infix[], char postfix[]){

    int k = 0;
    for(int i = 0; infix[i] != '0\n' ; i++){
        char ch = infix[i];
        if (isalnum(ch)){
            opStack[k++] = ch;
        }

        else if {
            if(ch == '('){
                pushChar(ch);
            }
        } else if{

            if(ch == ")"){
                while(opTop != -1 && peekChar() != '('){
                    postfix[k++] = popChar();
                }
            }

        }

        else {
            while (opTop)
        }

        
    }
}


int main(){

    char infix[] = "((2+3)*4)-6";
    char postfix[MAX];

    infixtopostfix(infix, postfix);
}


































































// void infixToPostfix(char infix[], char postfix[]) {
//     int k = 0;
//     for (int i = 0; infix[i] != '\0'; i++) {
//         char ch = infix[i];

//         // 1. Operand -> direct to output
//         if (isalnum(ch)) {
//             postfix[k++] = ch;
//         }
//         // 2. Opening bracket -> push to stack
//         else if (ch == '(') {
//             pushChar(ch);
//         }
//         // 3. Closing bracket -> pop until '('
//         else if (ch == ')') {
//             while (opTop != -1 && peekChar() != '(') {
//                 postfix[k++] = popChar();
//             }
//             popChar(); // Remove '('
//         }
//         // 4. Operator -> pop higher/equal precedence operators first
//         else {
//             while (opTop != -1 && precedence(peekChar()) >= precedence(ch)) {
//                 postfix[k++] = popChar();
//             }
//             pushChar(ch);
//         }
//     }
//     // Pop remaining operators
//     while (opTop != -1) {
//         postfix[k++] = popChar();
//     }
//     postfix[k] = '\0';
// }

// int main() {
//     char infix[] = "((2+3)*4)-6";
//     char postfix[MAX];

//     infixToPostfix(infix, postfix);
//     printf("Infix Expression:   %s\n", infix);
//     printf("Postfix Expression: %s\n", postfix);

// }