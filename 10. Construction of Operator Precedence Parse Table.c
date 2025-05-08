#include <stdio.h>
#include <string.h>
#define N 4
char symbols[N] = {'i', '+', '*', '$'};
char table[N][N];
int get_index(char c) {
    for (int i = 0; i < N; i++)
        if (symbols[i] == c)
            return i;
    return -1;}
void print_table() {
    printf("\n**** OPERATOR PRECEDENCE TABLE ****\n\n\t");
    for (int i = 0; i < N; i++)
        printf("%c\t", symbols[i]);
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%c\t", symbols[i]);
        for (int j = 0; j < N; j++) {
            if (table[i][j] == 'a')
                printf("acc\t");
            else if (table[i][j])
                printf("%c\t", table[i][j]);
            else
                printf("e\t");}
        printf("\n"); }}
int main() {   char input[50], stack[50] = "$"; int top = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            printf("Enter the value for %c %c: ", symbols[i], symbols[j]);
            scanf(" %c", &table[i][j]); }
    print_table();
    printf("\nEnter the input string: ");
    scanf("%s", input);
    strcat(input, "$");
    printf("\n%-25s%-25s%-20s\n", "STACK", "INPUT STRING", "ACTION");
    int ip = 0;
    while (1) {
        char a = stack[top];
        char b = input[ip];
        int row = get_index(a);
        int col = get_index(b);
        printf("%-25s%-25s", stack, input + ip);
        if (table[row][col] == '<' || table[row][col] == '=') {
            stack[++top] = input[ip++];
            stack[top + 1] = '\0';
            printf("Shift %c\n", stack[top]);
        } else if (table[row][col] == '>') {
            stack[top--] = '\0';
            printf("Reduce\n");
        } else if (table[row][col] == 'a') {
            printf("Accepted\n");
            break;} else {
            printf("Rejected\n");
            break; }}
    return 0;}
