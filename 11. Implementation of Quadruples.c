#include <stdio.h>
#include <string.h>
int temp_count = 1;
void print_quad(const char *op, const char *arg1, const char *arg2, const char *res) {
    printf("%-4s %-4s %-4s %-4s\n", op, arg1, arg2, res);}
int main() {
    char expr[100], left[10], right[90]; char t1[10], t2[10], t3[10], t4[10], t5[10];
    printf("Enter a String : "); fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';sscanf(expr, "%[^=]=%s", left, right);  
    printf("\nop   a1   a2   res\n");  
    sprintf(t1, "t%d", temp_count++);
    print_quad(":=", "c", "", t1); 
    sprintf(t2, "t%d", temp_count++);     
    print_quad("*", "b", t1, t2); 
    sprintf(t3, "t%d", temp_count++);      
    print_quad(":=", "c", "", t3); 
    sprintf(t4, "t%d", temp_count++);     
    print_quad("*", "b", t3, t4); 
    sprintf(t5, "t%d", temp_count++);      
    print_quad("-", t2, t4, t5);  
    print_quad(":=", t5, "", left);        
    return 0;} 
