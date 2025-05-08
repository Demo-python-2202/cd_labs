#include <stdio.h>
#include <string.h>
int temp_count = 1;
void generate_code(FILE *out, const char *op, const char *arg1, const char *arg2, const char *res) {
    fprintf(out, "%s=%s%s%s\n", res, arg1, op, arg2);
}
void process_expression(FILE *in, FILE *out) {
    char line[100], lhs[10], rhs[90];
    char t[10];
    fgets(line, sizeof(line), in);
    sscanf(line, "%[^=]=%s", lhs, rhs);
    char *token = strtok(rhs, " ");
    strcpy(t, "t1");
    while (token != NULL) {
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0) {
            char op[2];
            strcpy(op, token);
            token = strtok(NULL, " ");
            char operand1[10], operand2[10];
            strcpy(operand1, token);
            token = strtok(NULL, " ");
            strcpy(operand2, token);
            char temp[10];
            sprintf(temp, "t%d", temp_count++);
            generate_code(out, op, operand1, operand2, temp);
            strcpy(t, temp);
        } else {
            strcpy(t, token);}
        token = strtok(NULL, " ");    }
    fprintf(out, "%s=%s\n", lhs, t);}
int main() {
    FILE *in, *out;
    in = fopen("sum.txt", "r");
    if (in == NULL) {
        printf("Error opening input file\n");
        return 1; }
    out = fopen("out.txt", "w");
    if (out == NULL) {
        printf("Error opening output file\n");
        return 1;  }
    process_expression(in, out);
    fclose(in);
    fclose(out);
    printf("Intermediate code generated in out.txt\n");
    return 0;
}
