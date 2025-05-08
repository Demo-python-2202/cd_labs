Lex File
%{
#include "y.tab.h"
#include <math.h>
#include <stdlib.h>
%}

%%

([0-9]+|[0-9]*\.[0-9]+([eE][\-+]?[0-9]+)?) {
    yylval.dval = atof(yytext);
    return NUMBER;
}

log|LOG      { return LOG; }
ln           { return LN; }
sin|SIN      { return SINE; }
cos|COS      { return COS; }
tan|TAN      { return TAN; }
mem|MEM      { return MEM; }

[\t ]        ; // skip whitespace
\$           { return 0; }
\n           { return '\n'; }
.            { return yytext[0]; }

%%

int yywrap() {
    return 1;
}


Yacc File:
%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double memvar;
int yyerror(const char *s);
int yylex();
%}

%union {
    double dval;
}

%token <dval> NUMBER
%token <dval> MEM
%token LOG SINE LN COS TAN
%left '+' '-'
%left '*' '/'
%right '^'
%left LOG SINE LN COS TAN
%nonassoc UMINUS
%type <dval> expression

%%

start:
    statement '\n'
  | start statement '\n'
  ;

statement:
    MEM '=' expression { memvar = $3; }
  | expression { printf("Answer = %g\n", $1); }
  ;

expression:
    expression '+' expression     { $$ = $1 + $3; }
  | expression '-' expression     { $$ = $1 - $3; }
  | expression '*' expression     { $$ = $1 * $3; }
  | expression '/' expression
      {
          if ($3 == 0)
              yyerror("Divide by zero");
          else
              $$ = $1 / $3;
      }
  | expression '^' expression     { $$ = pow($1, $3); }
  | '-' expression %prec UMINUS   { $$ = -$2; }
  | '(' expression ')'            { $$ = $2; }
  | LOG expression                { $$ = log10($2); }
  | LN expression                 { $$ = log($2); }
  | SINE expression               { $$ = sin($2 * M_PI / 180); }
  | COS expression                { $$ = cos($2 * M_PI / 180); }
  | TAN expression                { $$ = tan($2 * M_PI / 180); }
  | NUMBER                        { $$ = $1; }
  | MEM                           { $$ = memvar; }
  ;

%%

int main() {
    printf("\nEnter expression:\n");
    return yyparse();
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}
