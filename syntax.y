%{
#include<stdio.h>
#include <string.h>
#include<math.h>
int nb_lignes=1;
int col=0;
int yyparse();
int yylex();
int yyerror(char *s);
%}
%union {
int entier;
char* str;
}
%left add minus
%left mul division
%nonassoc UM  
%token mc_do idf cst aff mc_IF par_ouv par_fer mc_then mc_else
        pvg  mc_while moins add mul division sup inf inf_eg  sup_eg egale mc_id
%%
%start S ;
S:entete body fin pvg
  { printf("\nLe programme est  syntaxiquement correcte\n");} 
;
entete: mc_do mc_id aff mc_IF par_ouv condt par_fer
;
body: mc_then inst pvg  mc_else inst pvg
;
fin: mc_while condt
;
condt: idf sup types
                |idf inf types
                |idf sup_eg types
                |idf inf_eg types
                |idf egale types
;

inst: idf aff expr
;

expr: expr minus expr %prec UM
    | expr add expr
    | expr mul expr
    | expr division expr
    | types
    ;

types: idf
        |cst;
   
%%
main()
{
  yyparse();

  afficher();
  
}
yywrap()
{}
yyerror (char*msg)
{
printf("Erreur syntaxique a la ligne %d et a la colonne %d \n", nb_lignes, col);
}