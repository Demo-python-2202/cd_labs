#include <stdio.h>
#include <string.h>
int main() {
    int nfa[3][2][3] = {
        {{1,2,-1},{-1}},  // state 0
        {{-1},{2,-1}},    // state 1
        {{-1},{-1}}       };
    int final = 2, curr[10] = {0}, next[10], i, j, k, c = 1, n;
    char str[100];
    printf("Enter the string :\n");
    scanf("%s", str);
    printf("%c ", str[0]);
    for (i = 0; str[i]; i++) {
        int sym = str[i] - 'a', nc = 0;
        for (j = 0; j < c; j++) {
            int st = curr[j];
            for (k = 0; nfa[st][sym][k] != -1; k++) {
                int exists = 0;
                for (n = 0; n < nc; n++)
                    if (next[n] == nfa[st][sym][k]) exists = 1;
                if (!exists)
                    next[nc++] = nfa[st][sym][k]; }}
        if (nc == 0) {
            printf("-1\nSTRING NOT ACCEPTED\n");
            return 0;}
        for (j = 0; j < nc; j++) printf("%d ", next[j]);
        memcpy(curr, next, sizeof(next));
        c = nc;}
    for (i = 0; i < c; i++)
        if (curr[i] == final) {
            printf("\nSTRING ACCEPTED\n");
            return 0;}
    printf("\nSTRING NOT ACCEPTED\n");
    return 0;} 
