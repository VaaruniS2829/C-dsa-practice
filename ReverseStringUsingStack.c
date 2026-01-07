#include <stdio.h>
#include <string.h>

int top = -1;
char stack[50];

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int main() {
    char str[50];
    printf("Enter string: ");
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++)
        push(str[i]);

    for (int i = 0; i < strlen(str); i++)
        str[i] = pop();

    printf("Reversed string: %s", str);
    return 0;
}
