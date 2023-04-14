#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{

   char name[20];
   char code[20];
   char type[20];
   char val[20];
   int taille ;
 } elt0;

typedef struct Element Element;
struct Element
{
    elt0 info ;
    Element *suivant;
};

typedef struct Pile Pile;
struct Pile
{
    Element *premier;
};

void empiler(Pile *pile, elt0 nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (pile == NULL || nouveau == NULL)
    {
        printf("erreur");
    }

    strcpy(nouveau->info.name , nvNombre.name);
    strcpy(nouveau->info.code , nvNombre.code);
    strcpy(nouveau->info.type , nvNombre.type);
    strcpy(nouveau->info.val ,nvNombre.val);
    nouveau->info.taille = 0;
    nouveau->suivant = pile->premier;
    pile->premier = nouveau;
}

elt0 depiler(Pile *pile)
{
    if (pile == NULL)
    {
        printf("EXIT_FAILURE");
    }
   elt0 nombreDepile;
    strcpy(nombreDepile.name,"0");
    strcpy(nombreDepile.type , "0");
    strcpy(nombreDepile.code , "0");
    strcpy(nombreDepile.val , "0");
    nombreDepile.taille=0;
    Element *elementDepile = pile->premier;

    if (pile != NULL && pile->premier != NULL)
    {
        strcpy(nombreDepile.name , elementDepile->info.name);
        strcpy(nombreDepile.code , elementDepile->info.code);
        strcpy(nombreDepile.type , elementDepile->info.type);
        strcpy(nombreDepile.val,elementDepile->info.val);
        nombreDepile.taille=elementDepile->info.taille;
        pile->premier = elementDepile->suivant;
        free(elementDepile);
    }

    return nombreDepile;
}


int Pilevide(Pile *P){
    if (P==NULL) return 1  ; else return 0; //pas vide
}

Pile *initialiser()
{
    Pile *pile = malloc(sizeof(*pile));
    pile->premier = NULL;
}

elt0 SommetPile (Pile *p)
{
    Element *elementDepile = p->premier;
    return elementDepile->info;
}
// partie des mots clet et separateurs

typedef struct elt1
{
   char name[40];
   char type[40];
} elt1;

typedef struct Element1 Element1;
struct Element1
{
    elt1 info ;
    Element1 *suivant;
};

typedef struct Pile1 Pile1;
struct Pile1
{
    Element1 *premier1;
};

void empiler1(Pile1 *pile, elt1 nvNombre)
{
    Element1 *nouveau = malloc(sizeof(*nouveau));
    if (pile == NULL || nouveau == NULL)
    {
        printf("erreur");
    }

    strcpy(nouveau->info.name,nvNombre.name);
    strcpy(nouveau->info.type,nvNombre.type);
    nouveau->suivant = pile->premier1;
    pile->premier1 = nouveau;
}

elt1 depiler1(Pile1 *pile)
{
    if (pile == NULL)
    {
        printf("EXIT_FAILURE");
    }
   elt1 nombreDepile;
    strcpy(nombreDepile.name,"0");
    strcpy(nombreDepile.type , "0");

    Element1 *elementDepile = pile->premier1;

    if (pile != NULL && pile->premier1 != NULL)
    {
        strcpy(nombreDepile.name , elementDepile->info.name);
        strcpy(nombreDepile.type , elementDepile->info.type);
        pile->premier1 = elementDepile->suivant;
        free(elementDepile);
    }

    return nombreDepile;
}

int Pilevide1(Pile1 *P){
    if (P==NULL) return 1  ; else return 0; //pas vide
}

Pile1 *initialiser1()
{
    Pile1 *pile = malloc(sizeof(*pile));
    pile->premier1 = NULL;
}
elt1 SommetPile1 (Pile1 *p)
{   Element1 *elementDepile = p->premier1;
    return elementDepile->info;
}


Pile *PC ; Pile1 *PM; Pile1*PS;
void initialisation(){

    PC=initialiser();
    PM=initialiser1();
    PS=initialiser1();
}


void inserer (char entite[], char code[],char type[],char val[], int y){elt1 x2;elt0 x0;elt1 x1;
    switch (y){
         case 0:/*insertion dans la table des IDF et CONST*/

          strcpy(x0.name,entite);
          strcpy(x0.type,type);
          strcpy(x0.code,code);
          strcpy(x0.val,val);
          empiler(PC,x0);
          break;
         case 1:/*insertion dans la table des mots clés*/

          strcpy(x1.name,entite);
          strcpy(x1.type,code);
          empiler1(PM,x1);

          break;
         case 2:/*insertion dans la table des séparateurs*/

          strcpy(x2.name,entite);
          strcpy(x2.type,code);
          empiler1(PS,x2);
          break;
          default : printf("erreur"); break
          ;
    }
}

// fct rechercher
void rechercher (char entite[], char code[],char type[],char val[],int o)
{
    elt0 y;Pile *Pi; elt1 y1;elt1 y2; Pile1 *Pmm;Pile1 *Pss;
Pi=initialiser(); Pmm=initialiser1(); Pss=initialiser1();
Pi=initialiser();
switch(o) {

case 0 :
   if (Pilevide(PC)==1){
    PC=initialiser();
    inserer(entite,code,type,val,0);}

else{

            while((PC->premier!=NULL) && (strcmp(SommetPile(PC).name,entite)!=0)){
              y=depiler(PC);
              empiler(Pi,y);


             }
          if (PC->premier==NULL){inserer(entite,code,type,val,0);}

             while(Pi->premier!=NULL) {
               y=depiler(Pi);
               empiler(PC,y);
               }


               }
break;
case 1 :
if (Pilevide1(PM)==1){
    PM=initialiser1();
    inserer(entite,code,type,val,1);}

else{

            while((PM->premier1!=NULL) && (strcmp(SommetPile1(PM).name,entite)!=0)){

              y1=depiler1(PM);
              empiler1(Pmm,y1);


             }
          if (PM->premier1==NULL){inserer(entite,code,type,val,1);}

             while(Pmm->premier1!=NULL) {
               y1=depiler1(Pmm);
               empiler1(PM,y1);
               }


               }

break;

case 2 :
    if (Pilevide1(PS)==1){
    PS=initialiser1();
    inserer(entite,code,type,val,2);}

else{

            while((PS->premier1!=NULL) && (strcmp(SommetPile1(PS).name,entite)!=0)){

              y2=depiler1(PS);
              empiler1(Pss,y2);

             }
          if (PS->premier1==NULL){inserer(entite,code,type,val,2);}

             while(Pss->premier1!=NULL) {
               y2=depiler1(Pss);
               empiler1(PS,y2);
               }


               }

break;
default : printf("erreur !"); break;


}

}
void afficher0(Pile *pile)
{

printf("/***************Table des symboles IDF*************/\n");
printf("____________________________________________________________________\n");
printf("\t| Nom_Entite |  Code_Entite | Type_Entite | Val_Entite| Taille\n");
printf("____________________________________________________________________\n");
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *actuel = pile->premier;

    while (actuel != NULL)
    {
        printf("\t|%11s |%11s | %11s | %11s | %11d \n", actuel->info.name,actuel->info.code,actuel->info.type,actuel->info.val,actuel->info.taille);
        actuel = actuel->suivant;
    }

    printf("\n");
}
void afficher1(Pile1 *pile)
{


printf("_____________________________________\n");
printf("\t| NomEntite |  CodeEntite | \n");
printf("_____________________________________\n");
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element1 *actuel = pile->premier1;

    while (actuel != NULL)
    {
        printf("\t|%10s |%12s | \n", actuel->info.name,actuel->info.type);
        actuel = actuel->suivant;
    }

    printf("\n");
}
void afficher()
{

afficher0(PC);
printf("\n/***************Table des symboles mots clés*************/\n");
afficher1(PM);
printf("\n");
printf("\n/***************Table des symboles   *************/\n");
afficher1(PS);
}
Pile1 *p; //la pile ou je sauvegarde les IDFs pour leurs donner un type




void sauvegarder (char entite[],int n)
{
char t[10]; elt1 xx;
 Pile *pi;
 elt0 x;
 pi=initialiser();
 elt1 x1;
 strcpy(x1.type,"0");
if (n==0){
if (Pilevide1(p)==1){p=initialiser1();}
   strcpy(x1.name,entite);
   empiler1(p,x1);
}
else {
strcpy(t,entite);
while (p->premier1!=NULL){
while(PC->premier!=NULL)
{
 if (strcmp(SommetPile(PC).name,SommetPile1(p).name)==0)
    {  x=depiler(PC);
       strcpy(x.type,t);
       empiler(pi,x);
    }
    else{
       x=depiler(PC);
       empiler(pi,x);}
}
while(pi->premier!=NULL) {
    x=depiler(pi);
    empiler(PC,x);}
xx=depiler1(p);}}}



int doubleDeclaration(char entite[])
{ Pile *Pi=initialiser(); elt0 y; char r[20];
while(PC->premier!=NULL){
          if  (strcmp(SommetPile(PC).name,entite)==0)
          {  strcpy(r,SommetPile(PC).type);}
              y=depiler(PC);
              empiler(Pi,y);
             }
             while(Pi->premier!=NULL) {
               y=depiler(Pi);
               empiler(PC,y);
               }
         if(strcmp(r,"")==0){return 0;}  else {return -1;}  

               }
// fonction qui verifie 

int VerifSigne(int n,char entite[])
{ Pile *Pi=initialiser(); elt0 y; char r[20]; int x=1;
switch(n)
{
case 0: // type integer dollar 

 while(PC->premier!=NULL)
               {
          if  (strcmp(SommetPile(PC).name,entite)==0)
              {strcpy(r,SommetPile(PC).type);x=0;}
              y=depiler(PC);
              empiler(Pi,y);
             }
              while(Pi->premier!=NULL) 
              {
               y=depiler(Pi);
               empiler(PC,y);
               }
if (x==1){printf("Cette IDF %s n'as Pas etait declarer",entite);exit(1);}
if(strcmp(r,"INTEGER")==0){return 0;}  else {return -1;}  
break;
case 1 : // compatibilé avec float 
 while(PC->premier!=NULL)
               {
          if  (strcmp(SommetPile(PC).name,entite)==0)
              {strcpy(r,SommetPile(PC).type);x=0;}
              y=depiler(PC);
              empiler(Pi,y);
             }
              while(Pi->premier!=NULL) 
              {
               y=depiler(Pi);
               empiler(PC,y);
               }
if (x!=0){printf("Cette IDF %s n'as Pas etait declarer",entite);exit(1);}
if(strcmp(r,"FLOAT")==0){return 0;}  else {return -1;}  
break;
case 2 : // compatibilé avec string 
 while(PC->premier!=NULL)
               {
          if  (strcmp(SommetPile(PC).name,entite)==0)
              {strcpy(r,SommetPile(PC).type);x=0;}
              y=depiler(PC);
              empiler(Pi,y);
             }
              while(Pi->premier!=NULL) 
              {
               y=depiler(Pi);
               empiler(PC,y);
               }
if (x!=0){printf("Cette IDF %s n'as Pas etait declarer",entite);exit(1);}
if(strcmp(r,"STRING")==0){return 0;}  else {return -1;}  
break;
case 3 : 
 while(PC->premier!=NULL)
               {
          if  (strcmp(SommetPile(PC).name,entite)==0)
              {strcpy(r,SommetPile(PC).type);x=0;}
              y=depiler(PC);
              empiler(Pi,y);
             }
              while(Pi->premier!=NULL) 
              {
               y=depiler(Pi);
               empiler(PC,y);
               }
if (x!=0){printf("Cette IDF %s n'as Pas etait declarer",entite);exit(1);}
if(strcmp(r,"CHAR")==0){return 0;}  else {return -1;}  
break;

}

}


// sauvegarder la valeur 
void sauvegarderVal(char ss[],char s[])
{
    Pile *Pi=initialiser(); elt0 y; char r[20];
   /* for (int i=0;i<=7;i++)
    {
    r[i]=s[i];
    }
    printf("la valeur de wina1 est %s\n",r);*/
while(PC->premier!=NULL)
              {
               printf("%s",s);
          if  (strcmp(SommetPile(PC).name,ss)==0)
              { 
              y=depiler(PC);
              strcpy(y.val,s);
              empiler(Pi,y);}

              y=depiler(PC);
              empiler(Pi,y);}
              printf("la valeur de wina1 est %s \n",r);
              while(Pi->premier!=NULL)
              {
               y=depiler(Pi);
               empiler(PC,y);
               }

}

// chercher val idf 
int verifVal(char ss[])
{
    Pile *Pi=initialiser(); elt0 y; char r[20];
   /* for (int i=0;i<=7;i++)
    {
    r[i]=s[i];
    }
    printf("la valeur de wina1 est %s\n",r);*/
while(PC->premier!=NULL)
              {
             
          if  (strcmp(SommetPile(PC).name,ss)==0)
              { 
              y=depiler(PC);
              if((strcmp(y.type,"INTEGER")==0) ||(strcmp(y.type,"FLOAT")==0)){return 0;}
              else{return 1;}
              empiler(Pi,y);}

              y=depiler(PC);
              empiler(Pi,y);}
             
              while(Pi->premier!=NULL)
              {
               y=depiler(Pi);
               empiler(PC,y);
               }

}
