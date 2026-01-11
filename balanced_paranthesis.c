#include <stdio.h>
#include <string.h>

int isBalanced(char *str) {
    char stack[50];
    int top = -1;
    char ch, pop;

    for (int i = 0; i < strlen(str); i++) {
        ch = str[i];

        // Push opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }

        // Check closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1)
                return 0; // No matching opening bracket

            pop = stack[top--];

            if ((ch == ')' && pop != '(') ||
                (ch == '}' && pop != '{') ||
                (ch == ']' && pop != '[')) {
                return 0; // Mismatched pair
            }
        }
    }

    // If stack is empty → balanced
    if (top == -1)
        return 1;
    else
        return 0;
}

int main() {
    char str[50];

    printf("Enter an expression: ");
    scanf("%s", str);

    if (isBalanced(str))
        printf("The parentheses are balanced.\n");
    else
        printf("The parentheses are not balanced.\n");

    return 0;
}