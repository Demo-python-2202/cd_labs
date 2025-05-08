#include <stdio.h>
#include <string.h>
#include <ctype.h>
int isKeyword(char *s) {
    char *kw[] = {"if","else","while","do","for","int","float","return","char"};
    for (int i = 0; i < 9; i++)
        if (!strcmp(s, kw[i])) return 1;
    return 0; }
int main() {
    FILE *fp = fopen("source.txt", "r");
    char ch, str[20], ops[] = "+-*/%=", i = 0;
    if (!fp) return printf("File error\n"), 1;
    while ((ch = fgetc(fp)) != EOF) {
        if (strchr(ops, ch)) printf("Operator: %c\n", ch);
        else if (isalnum(ch)) str[i++] = ch;
        else if ((ch == ' ' || ch == '\n' || ch == ';' || ch == ',') && i) {
            str[i] = '\0'; i = 0;
            printf("%s: %s\n", isKeyword(str) ? "Keyword" : "Identifier", str); }}
    fclose(fp);
    return 0; }
