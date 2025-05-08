#include <stdio.h>
#include <string.h>
void main() {
    char icode[10][30], str[20], opr[10];
    int i = 0; printf("\nEnter intermediate code:\t");
    do {
        scanf("%s", icode[i]);
    } while (strcmp(icode[i++], "exit") != 0);
       printf("\nTarget Code Generation\n"); i = 0;
    do {
        strcpy(str, icode[i]);
        switch (str[3]) {
            case '+':
                strcpy(opr, "ADD");
                break;
            case '-':
                strcpy(opr, "SUB");
                break;
            case '*':
                strcpy(opr, "MUL");
                break;
            case '/':
                strcpy(opr, "DIV");
                break; }
        printf("\n\tMov %c, R%d", str[2], i); 
        printf("\n\t%s %c, R%d, R%d", opr, str[0], i, i + 1);
        printf("\n\tMov R%d, %c", i + 1, str[4]);i++;} 
        while (strcmp(icode[i], "exit") != 0);} 
