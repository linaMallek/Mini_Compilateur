%{
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "syntax.tab.h"
extern nb_lignes;
extern col;
extern YYSTYPE yylval ;
%}
/*definition des entités lexical*/ 
lettre [a-zA-Z]
chiffre [0-9]
IDF {lettre}({lettre}|{chiffre})*
cst {chiffre}+
%%
"DO" {col=col+yyleng;return (mc_do);}
{IDF} {return idf;col=col+yyleng;}
{cst} {return cst;col=col+yyleng;}
'id' {return mc_id; col=col+yyleng;}
"=" {return aff;col=col+yyleng;}
'If' {return mc_IF;col=col+yyleng;}
"(" {return par_ouv;col=col+yyleng;}
")" {return par_fer;col=col+yyleng;}
'Then' {return mc_then;col=col+yyleng;}
'Else' {return mc_else;col=col+yyleng;}
";" {return pvg;}
'While' {return mc_while;col=col+yyleng;}
"-" {return moins;col=col+yyleng;}
"+" {return add;col=col+yyleng;}
"*" {return mul;col=col+yyleng;}
"/" {return division;col=col+yyleng;}
">" {return sup;col=col+yyleng;}
"<" {return inf;col=col+yyleng;}
"<=" {return inf_eg;col=col+yyleng;}
">=" {return sup_eg;col=col+yyleng;}
"==" {return egale;col=col+yyleng;}
[ \t] {col++;}
\n {nb_lignes++;col=col+yyleng;}
. printf("L'erreur lexical a la ligne %d \n",nb_lignes);
%%

