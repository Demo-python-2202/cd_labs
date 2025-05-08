#include <stdio.h>
#include <string.h>
#define MAX 10
typedef struct {
    char name[20];
    char type[10];
    int size;
} Symbol;
Symbol table[MAX];
int count = 0;
void insert(char* name, char* type, int size) {
    if (count >= MAX) {
        printf("Symbol Table Full!\n");
        return;}
    strcpy(table[count].name, name);
    strcpy(table[count].type, type);
    table[count].size = size;
    count++; }
void search(char* name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            printf("Found: %s (%s, Size: %d)\n", table[i].name, table[i].type, table[i].size);
            return;}}
    printf("Symbol not found.\n")}
void display() {
    printf("\nSymbol Table:\n-------------------------\n");
    for (int i = 0; i < count; i++)
        printf("%s\t%s\t%d\n", table[i].name, table[i].type, table[i].size);
    printf("-------------------------\n");}
int main() {
    insert("x", "int", 4);
    insert("y", "float", 4);
    insert("arr", "int[10]", 40);
    display();
    printf("\nSearch symbol: ");
    char key[20];
    scanf("%19s", key);  // Fixed potential buffer overflow
    search(key);
    return 0;}
