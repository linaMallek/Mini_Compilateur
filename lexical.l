%{
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "syntax.tab.h"
#include "ts.h"
extern int nb_lignes;
extern int col;
extern YYSTYPE yylval ;
%}
/*definition des entités lexical*/ 
lettre [a-zA-Z]
chiffre [0-9]
IDF {lettre}({lettre}|{chiffre})*
cst {chiffre}+
%%
"DO" {rechercher(yytext,"Mot cle","",0,1);printf("Do \n");col=col+yyleng;return (mc_do);}
"id" {rechercher(yytext,"Mot cle","",0,1);printf("id \n"); col=col+yyleng;return mc_id;}
"If" {rechercher(yytext,"Mot cle","",0,1);printf("If \n"); return mc_IF;col=col+yyleng;}
"Then" {rechercher(yytext,"Mot cle","",0,1);printf("Then \n");return mc_then;col=col+yyleng;}
"Else" {rechercher(yytext,"Mot cle","",0,1);printf("Else \n");return mc_else;col=col+yyleng;}
"While" {rechercher(yytext,"Mot cle","",0,1);printf("while \n");return mc_while;col=col+yyleng;}
{IDF} {rechercher(yytext,"IDF","","",0);printf("idf \n");col=col+yyleng;return idf;}
{cst} {rechercher(yytext,"cst","","",0);printf("cst \n");col=col+yyleng;return cst;}
"=" {rechercher(yytext,"sep"," ",0,2);printf("Affecter \n");return aff;col=col+yyleng;}
"(" {rechercher(yytext,"sep"," ",0,2);printf("par_ouvrt \n");return par_ouv;col=col+yyleng;}
")" {rechercher(yytext,"sep"," ",0,2);printf("par_fer \n");return par_fer;col=col+yyleng;}
";" {rechercher(yytext,"sep"," ",0,2);printf("pvg");return pvg;}
"-" {rechercher(yytext,"sep"," ",0,2);return moins;col=col+yyleng;}
"+" {rechercher(yytext,"sep"," ",0,2);return add;col=col+yyleng;}
"*" {rechercher(yytext,"sep"," ",0,2);return mul;col=col+yyleng;}
"/" {rechercher(yytext,"sep"," ",0,2);return division;col=col+yyleng;}
">" {rechercher(yytext,"sep"," ",0,2);return sup;col=col+yyleng;}
"<" {rechercher(yytext,"sep"," ",0,2);printf("inf");return inf;col=col+yyleng;}
"<=" {rechercher(yytext,"sep"," ",0,2);return inf_eg;col=col+yyleng;}
">=" {rechercher(yytext,"sep"," ",0,2);return sup_eg;col=col+yyleng;}
"=="  {rechercher(yytext,"sep"," ",0,2);return egale;col=col+yyleng;}
[ \t] {col++;}
\n {nb_lignes++;col=col+yyleng;}
. printf("L'erreur lexical a la ligne %d \n",nb_lignes);
%%

