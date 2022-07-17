2.lex

%{
#include "y.tab.h"
%}
%%
a return A;
b return B;
.|\n return yytext[0];
%%

2.y

%{
#include<stdio.h>
#include<stdlib.h>
%}
%token A B
%%
str:S '\n' {return 0;}
S:A S
S:B
;
%%
main()
{
printf("enter string\n");
yyparse();
printf("valid\n");
}
int yyerror()
{
printf("error\n");
exit(0);
}
