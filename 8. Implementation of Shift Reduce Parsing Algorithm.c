#include <string.h>
#define MAX 100
char input[MAX], stack[MAX];
int top = -1, ip = 0;
void push(char c) { stack[++top] = c; }
void display() {
    printf("$");
    for (int i = 0; i <= top; i++) printf("%c", stack[i]); }
void reduce() {
    while (1) {
        if (top >= 0 && (stack[top] == 'a' || stack[top] == 'b')) {
            stack[top] = 'E'; printf("\t\tE->%c\n", stack[top]);
        } else if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '+' && stack[top - 2] == 'E') {
            top -= 2; printf("\t\tE->E+E\n");
        } else if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '*' && stack[top - 2] == 'E') {
            top -= 2; printf("\t\tE->E*E\n");
        } else break;}}
int main() {
    printf("SHIFT REDUCE PARSER\n\nGRAMMAR:\nE -> E+E\nE -> E*E\nE -> a\nE -> b\n\n");
    printf("Enter input: ");
    scanf("%s", input);
    printf("\nStack\t\tInput\t\tAction\n----------------------------------------\n");
    while (input[ip] != '\0') {
        push(input[ip]);
        display(); printf("\t\t%s\t\tShift %c\n", input + ip + 1, input[ip]);
        ip++;
        reduce();}
    reduce();
    printf("-------------------\n");
    if (top == 0 && stack[top] == 'E')
        printf("ACCEPTED\n");
    else
        printf("PARSING FAILED\n");
    return 0;}

