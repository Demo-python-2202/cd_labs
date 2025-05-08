#include <stdio.h>
#include <string.h>
char input[50], stack[50] = "$", temp[10];
int i = 0;
void push(char *s) {
    strcat(stack, s);
}
void reduce() {
    int len = strlen(stack);
    if (stack[len - 2] == 'i' && stack[len - 1] == 'd') {
        stack[len - 2] = 'E'; stack[len - 1] = '\0'; // id -> E
    } else if (stack[len - 1] == 'E' && stack[len - 3] == 'E') {
        stack[len - 3] = 'E'; stack[len - 2] = '\0'; // E+E or E-E or E*E -> E
    }
}
int main() {
    printf("LR PARSING\nENTER THE EXPRESSION\n");
    scanf("%s", input);
    strcat(input, "$");
    printf("$\n");
    while (input[i] != '\0') {
        sprintf(temp, "%c", input[i++]);
        push(temp);
        printf("%s\n", stack);
        while (1) {
            int before = strlen(stack);reduce();
            if (before == strlen(stack)) break; printf("%s\n", stack);
        }}
    return 0;}
