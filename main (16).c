/* Program on lexical analysis and parser */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define MAX 30

char a[30];
int top=-1,i;

void error()
{
printf("Syntax Error");
printf("\nGiven String is not accepted\n");
exit(0);
}

void push(char k[]) //Pushes The Set Of Characters on to the Stack
{
  for(i=0;k[i]!='\0';i++)
  {
    if(top<30)
    a[++top]=k[i];
  }
}

void push1(char k)  //Pushes 1 Character on to the Stack
{
    if(top<30)
    a[++top]=k;
}

char TOS()        //Returns TOP of the Stack
{
  return a[top];
}

void pop()       //Pops 1 element from the Stack
{
  if(top>=0)
    a[top--]='\0';
}

void pop7()
{
    if(top>=0)
    {
       a[top--]='\0';
       a[top--]='\0';
       a[top--]='\0';
       a[top--]='\0';
       a[top--]='\0';
       a[top--]='\0';
       a[top--]='\0';
    }
}

void pop6()
{
    if(top>=0)
    {
       a[top--]='\0';
       a[top--]='\0';
       a[top--]='\0';
       a[top--]='\0';
       a[top--]='\0';
       a[top--]='\0';
    }
}

void pop3()
{
    if(top>=0)
    {
       a[top--]='\0';
       a[top--]='\0';
       a[top--]='\0';
    }
}

void pop2()
{
    if(top>=0)
    {
       a[top--]='\0';
       a[top--]='\0';
    }
}

void pop4()
{
    if(top>=0)
    {
       a[top--]='\0';
       a[top--]='\0';
       a[top--]='\0';
       a[top--]='\0';
    }
}

void display()  //Displays Elements Of Stack
{
  for(i=0;i<=top;i++)
    printf("%c",a[i]);
}

void display1(char p[],int m) //Displays The Present Input String
{
  int l;
  printf("\t\t");
  for(l=m;p[l]!='\0';l++)
    printf("%c",p[l]);
}

char* stack()
{
     return a;
}

int main()
{
   char str[MAX];
   int state=0;
   int i=0, j, startid=0, endid, startcon, endcon;

   for(j=0; j<MAX; j++)
      str[j]=NULL;          //Initialise NULL

   printf("*** Program on Lexical Analysis ***");
   printf("\n\nEnter the string (Give space as underscore and $ at end of string) : \n");
   gets(str);               //Accept input string
   str[strlen(str)]=' ';

   printf("\n\nAnalysis:\n");

   while(str[i]!=NULL)
   {
      if(str[i]=='_') //To eliminate spaces
         printf("'_'     : Space\n");
      switch(state)
      {
         case 0: if(str[i]=='i') state=1;            //if or int
                 else if(str[i]=='b') state=4;       //begin
                 else if(str[i]=='e') state=8;       //end
                 else if(str[i]=='m') state=10;      //main
                 else if(str[i]=='f') state=13;      //for
                else if(str[i]=='$')
                {
                    printf("$     : End of string");
                    break;
                }
                 else if(str[i]==',') state=29;
                 //special character ','

                 else if(isalpha(str[i]))
                 {
                 	state=16;
                 	startid=i;
                 } //identifiers

                 else if(str[i]=='<') state=18;
                 //relational '<' or '<=' or '<>'

                 else if(str[i]=='>') state=20;
                 //relational '>' or '>='

                 else if(str[i]=='=') state=22;
                 //relational '==' or assignment '='

                 else if(isdigit(str[i]))
                 {
                 	state=24; startcon=i;
                 }
		         //constant

                 else if(str[i]=='(') state=25;
                 //special characters '('

                 else if(str[i]==')') state=26;
                 //special characters ')'

                 else if(str[i]==';') state=27;
                 //special characters ';'

                  else if(str[i]=='+' && str[i+1]=='+') state=28;
                 //operator '++'

                 break;

         //States for 'if'
         case 1: if(str[i]=='f') state=2;
                 else if(str[i]=='n') state=3;
                 else { state=16; startid=i-1; i--; }
                 break;
         case 2: if(str[i]=='(' || str[i]==NULL)
                 {
                    printf("if 	: Keyword\n");
                    state=0;
                    i--;
                 }
                 else { state=16; startid=i-2; i--; }
                 break;
        case 3: if(str[i]=='t' && (str[i+1]=='_' ||str[i+1]==NULL))
                 {
                     i++;
                    printf("int 	: Keyword\n");
                    state=0;
                    i--;
                 }
                 else { state=16; startid=i-4; i--; }
                 break;

        //States for 'begin'
        case 4: if(str[i]=='e') state=5;
                 else { state=16; startid=i-1; i--; }
                 break;
        case 5 :if(str[i]=='g') state=6;
                 else { state=16; startid=i-2; i--; }
                 break;
        case 6: if(str[i]=='i') state=7;
                 else { state=16; startid=i-3; i--; }
                 break;
        case 7: if(str[i]=='n' && (str[i+1]=='_' ||str[i+1]==NULL))
                 {
                     i++;
                    printf("begin 	: Keyword\n");
                    state=0;
                    i--;
                 }
                 else { state=16; startid=i-5; i--; }
                 break;

        //States for 'end'
        case 8 :if(str[i]=='n') state=9;
                 else { state=16; startid=i-1; i--; }
                 break;
        case 9 : if(str[i]=='d' && (str[i+1]=='_' ||str[i+1]==NULL))
                 {
                     i++;
                    printf("end 	: Keyword\n");
                    state=0;
                    i--;
                 }
                 else { state=16; startid=i-3; i--; }
                 break;

        //States for main
        case 10: if(str[i]=='a') state=11;
                 else { state=16; startid=i-1; i--; }
                 break;
        case 11:if(str[i]=='i') state=12;
                 else { state=16; startid=i-2; i--; }
                 break;
        case 12:if(str[i]=='n' && (str[i+1]=='_' ||str[i+1]=='('))
                 {
                     i++;
                    printf("main 	: Keyword\n");
                    state=0;
                    i--;
                 }
                 else { state=16; startid=i-4; i--; }
                 break;

         //States for 'for'
         case 13: if(str[i]=='o') state=14;
                  else { state=16; startid=i-1; i--; }
                  break;
         case 14: if(str[i]=='r') state=15;
                  else { state=16; startid=i-2; i--; }
                  break;
	     case 15: if(str[i]=='(' || str[i]==NULL)
                  {
                     printf("for 	: Keyword\n");
                     state=0;
                     i--;
                  }
                  else { state=16; startid=i-3; i--; }
                  break;

         //States for identifiers
         case 16:

         if(isalnum(str[i]))
         {
         	state=17; i++;
         }
         else if(str[i]==NULL||str[i]=='<'||str[i]=='>'||str[i]=='('||str[i]==')'
                 ||str[i]==';'||str[i]=='='||str[i]=='+'||str[i]=='-'||str[i]=='_'||str[i]==',') state=17;
                  i--;
                  break;

         case 17:

                 if(str[i]==NULL || str[i]=='<' || str[i]=='>' || str[i]=='('||str[i]==','||str[i]=='_'
                || str[i]==')' || str[i]==';' || str[i]=='=' || str[i]=='+' ||str[i]=='-')
                  {
                     endid=i-1;
                     for(j=startid; j<=endid; j++)
                        printf("%c", str[j]);
                     printf(" 	: Identifier\n");
                     state=0;
                     i--;
                  }
                  break;

         //States for relational operator '<' & '<='
         case 18: if(str[i]=='=') state=19;
                  else if(str[i]=='>') state=30;
                  else if(isalnum(str[i]))
                  {
                     printf("< 	: Relational operator\n");
                     i--;
                     state=0;
                  }
                  break;
         case 19: if(isalnum(str[i]))
                  {
                     printf("<= 	: Relational operator\n");
                     i--;
                     state=0;
                  }
                  break;
        case 30: if(isalnum(str[i]))
                  {
                     printf("<> 	: Relational operator\n");
                     i--;
                     state=0;
                  }

         //States for relational operator '>' & '>='
         case 20: if(str[i]=='=') state=21;
                  else if(isalnum(str[i]))
                  {
                     printf("> 	: Relational operator\n");
                     i--;
                     state=0;
                  }
                  break;
         case 21: if(isalnum(str[i]))
                  {
                     printf(">= 	: Relational operator\n");
                     i--;
                     state=0;
                  }
                  break;

         //States for relational operator '==' & assignment operator '='
         case 22: if(str[i]=='=') state=23;
                  else
                  {
                     printf("= 	: Assignment operator\n");
                     i--;
                     state=0;
                  }
                  break;
         case 23: if(isalnum(str[i]))
                  {
                     printf("== 	: Relational operator\n");
                     state=0;
                     i--;
                  }
                  break;

         //States for constants
         case 24: if(isalpha(str[i]))
                  {
                     printf("\n\n*** ERROR ***");
                     puts(str);
                     for(j=0; j<i; j++)
                        printf(" ");
		          printf("^");
                     printf("\nError at position %d\nAlphabet cannot follow digit", i);
                     state=99;
                  }
                else if(str[i]=='(' || str[i]==')' || str[i]=='<' || str[i]=='>' ||
                         str[i]==NULL || str[i]==';' || str[i]=='=')
                  {
                     endcon=i-1;
                     for(j=startcon; j<=endcon; j++)
                        printf("%c", str[j]);
                     printf(" 	: Constant\n");
                     state=0;
                     i--;
                  }
                  break;

         //State for special character '('
         case 25: printf("( 	: Special character\n");
                  startid=i;
                  state=0;
                  i--;
                  break;

         //State for special character ')'
         case 26: printf(") 	: Special character\n");
                  state=0;
                  i--;
                  break;

         //State for special character ';'
         case 27: printf("; 	: Special character\n");
                  state=0;
                  i--;
                  break;

          //State for operator '+'
         case 28: printf("++ 	: Operator\n");
                  state=0;
                  i--;
                  break;

         //State for special character ','
         case 29: printf(", 	: Special character\n");
                  state=0;
                  i--;
                  break;
         //Error State
         case 99: goto END;
      }
      i++;
   }

   printf("\nEnd of Token extraction\n\n");
   parse(str);
   END:
   return 0;
}

void parse(char ip[30])
{
  char r[20],st,an;
  int ir,ic,j=0,k; //  1                 2   3     4          5          6
  char t[10][24][30]={"main()_begin_end","!","!","if(C)A;","for(B;C;P)Z;","!","!","!","TI,I,I,I;","!","!","!","!","!","!","!","!","!","!","!","!","!","!","!",
		   "!","!","!","!","!","!","!","!","int_","!","!","!","!","!","!","!","!","!","!","!","!","!","!","!",
		   "!","!","!","!","!","!","!","!","!","!","ERE","!","ERE","!","!","ERE","ERE","!","!","!","!","!","!","!",
		   "!","!","!","!","!","!","!","!","!","!","g=r","!","!","!","!","!","!","!","!","!","!","!","!","!",
		   "!","!","!","!","!","!","!","!","!","!","!","!","r=1","!","!","!","!","!","!","!","!","!","!","!",
		   "!","!","!","!","!","!","!","!","!","!","!","!","!","!","++r","!","!","!","!","!","!","!","!","!",
		   "!","!","!","!","!","!","!","!","!","!","g=1","!","!","!","!","!","!","!","!","!","!","!","!","!",
		   "!","!","!","!","!","!","!","!","!","!","g","!","r","!","!","p","q","!","!","!","!","!","!","!",
		   "!","!","!","!","!","!","!","!","!","!","I","!","I","!","!","I","I","!","!","!","!","!","!","!",
		   "!","!","!","!","!","!","!","!","!","!","!","!","!","!","!","!","!","!","<",">","<=",">=","<>","=="};

  printf("\nParsing Table\n\n");

  for(i=0;i<10;i++)
  {
      for(j=0;j<24;j++)

        printf("%s  ",t[i][j]);
      printf("\n");
  }

  printf("\nParsing\n\n");
  printf("\nStack\t\tInput\t\tOutput\n\n");
  push("$S");
  display();
  printf("\t\t%s\n",ip);

  for(j=0;ip[j]!='\0';)
  {
   TEMP:
    if(TOS()=='m')
      {
	pop7();
	display();
	display1(ip,j+7);
	printf("\t\tPOP\n");
	j=j+7;
      }
    if(TOS()=='b')
      {
	pop6();
	display();
	display1(ip,j+6);
	printf("\t\tPOP\n");
	j=j+6;
      }
    if(TOS()=='e')
      {
	pop3();
	display();
	display1(ip,j+3);
	printf("\t\tPOP\n");
	j=j+3;
      }
    if(TOS()=='i')
      {
          st=TOS();
          pop();
          if(TOS()=='f')
            {
            push1(st);
            pop2();
            display();
            display1(ip,j+2);
            printf("\t\tPOP\n");
            j=j+2;
            }
        else if(TOS()=='n')
              {
                push1(st);
                pop4();
                display();
                display1(ip,j+4);
                printf("\t\tPOP\n");
                j=j+4;
              }
          }
     if(TOS()=='f')
          {
            pop3();
            display();
            display1(ip,j+3);
            printf("\t\tPOP\n");
            j=j+3;
          }
     if(TOS()=='<')
      {
          st=TOS();
          pop();
          if(TOS()=='=')
            {
            push1(st);
            pop2();
            display();
            display1(ip,j+2);
            printf("\t\tPOP\n");
            j=j+2;
            goto NEXT1;
            }
          push1(st);
     }
     NEXT1:
     if(TOS()=='<')
      {
          st=TOS();
          pop();
          if(TOS()=='>')
            {
            push1(st);
            pop2();
            display();
            display1(ip,j+2);
            printf("\t\tPOP\n");
            j=j+2;
            goto NEXT2;
            }
          push1(st);
     }
     NEXT2:
     if(TOS()=='>')
      {
          st=TOS();
          pop();
          if(TOS()=='=')
            {
            push1(st);
            pop2();
            display();
            display1(ip,j+2);
            printf("\t\tPOP\n");
            j=j+2;
            goto NEXT3;
            }
          push1(st);
     }
     NEXT3:
     if(TOS()=='=')
      {
          st=TOS();
          pop();
          if(TOS()=='=')
            {
            push1(st);
            pop2();
            display();
            display1(ip,j+2);
            printf("\t\tPOP\n");
            j=j+2;
            goto NEXT4;
            }
          push1(st);
     }
     NEXT4:
     if(TOS()=='+')
      {
          st=TOS();
          pop();
          if(TOS()=='+')
            {
            push1(st);
            pop3();
            display();
            display1(ip,j+3);
            printf("\t\tPOP\n");
            j=j+3;
            }
     }
     if(TOS()=='r')
      {
          st=TOS();
          pop();
          if(TOS()=='=')
            {
            push1(st);
            pop3();
            display();
            display1(ip,j+3);
            printf("\t\tPOP\n");
            j=j+3;
            }
          else
          {
              push1(st);
              pop();
              display();
              display1(ip,j+1);
              printf("\t\tPOP\n");
              j=j+1;
          }
     }
     if(TOS()=='g')
      {
          st=TOS();
          pop();
          if(TOS()=='=')
            {
            push1(st);
            pop3();
            display();
            display1(ip,j+3);
            printf("\t\tPOP\n");
            j=j+3;
            }
          else
          {
              push1(st);
              pop();
              display();
              display1(ip,j+1);
              printf("\t\tPOP\n");
              j=j+1;
          }
     }
     if(TOS()=='(')
      {
	pop();
	display();
	display1(ip,j+1);
	printf("\t\tPOP\n");
	j++;
      }
  if(TOS()==an)
      {
	pop();
	display();
	display1(ip,j+1);
	printf("\t\tPOP\n");
	j++;
      }
    if(TOS()==';')
      {
	pop();
	display();
	display1(ip,j+1);
	printf("\t\tPOP\n");
	j++;
      }
    if(TOS()==',')
      {
	pop();
	display();
	display1(ip,j+1);
	printf("\t\tPOP\n");
	j++;
      }
    if(TOS()==')')
      {
	pop();
	display();
	display1(ip,j+1);
	printf("\t\tPOP\n");
	j++;
      }
    an=ip[j];
    st=TOS();
      if(st=='S')ir=0;
      else if(st=='T')ir=1;
      else if(st=='C')ir=2;
      else if(st=='A')ir=3;
      else if(st=='B')ir=4;
      else if(st=='P')ir=5;
      else if(st=='Z')ir=6;
      else if(st=='I')ir=7;
      else if(st=='E')ir=8;
      else if(st=='R')ir=9;
      else if(TOS()=='$'&& an=='$')break;
      else
        {
	    error();
	    break;
	    }
      if(an=='m')
      {
          j++;
          an=ip[j];
          if(an=='a')
          {
              j++;
              an=ip[j];
              if(an=='i')
              {
                  j++;
                  an=ip[j];
                  if(an=='n')
                  {
                      j++;
                      an=ip[j];
                      if(an=='(')
                      {
                          j++;
                          an=ip[j];
                          if(an==')')
                          {
                              j++;
                              an=ip[j];
                              if(an=='_')
                                {
                                ic=0;
                                strcpy(r,strrev(t[ir][ic]));
                                strrev(t[ir][ic]);
                                pop();
                                push(r);
                                display();
                                display1(ip,j-6);
                                printf("\t\t%c->%s\n",st,t[ir][ic]);
                                j=j-6;
                                an=ip[j];
                                }
                          }
                      }
                  }
              }
          }
          goto TEMP;
      }
      else if(an=='b')
      {
          j++;
          an=ip[j];
          if(an=='e')
          {
              j++;
              an=ip[j];
              if(an=='g')
              {
                  j++;
                  an=ip[j];
                  if(an=='i')
                  {
                      j++;
                      an=ip[j];
                      if(an=='n')
                      {
                          j++;
                          an=ip[j];
                          if(an=='_')
                          {
                                ic=1;
                                strcpy(r,strrev(t[ir][ic]));
                                strrev(t[ir][ic]);
                                pop();
                                push(r);
                                display();
                                display1(ip,j-5);
                                printf("\t\t%c->%s\n",st,t[ir][ic]);
                                j=j-5;
                                an=ip[j];
                          }
                      }
                  }
              }
          }
          goto TEMP;
      }
      else if(an=='e')
      {
          j++;
          an=ip[j];
          if(an=='n')
          {
              j++;
              an=ip[j];
              if(an=='d')
              {
                ic=2;
                strcpy(r,strrev(t[ir][ic]));
                strrev(t[ir][ic]);
                pop();
                push(r);
                display();
                display1(ip,j-2);
                printf("\t\t%c->%s\n",st,t[ir][ic]);
                j=j-2;
                an=ip[j];
                }
          }
          goto TEMP;
      }
      else if(an=='i')
        {
        j++;
        an=ip[j];
        if(an=='f')
            {
            ic=3;
            strcpy(r,strrev(t[ir][ic]));
            strrev(t[ir][ic]);
            pop();
            push(r);
            display();
            display1(ip,j-1);
            printf("\t\t%c->%s\n",st,t[ir][ic]);
            j--;
            an=ip[j];
            }
         else if(an=='n')
         {
                    ic=8;
                strcpy(r,strrev(t[ir][ic]));
                strrev(t[ir][ic]);
                pop();
                push(r);
                display();
                display1(ip,j-1);
                printf("\t\t%c->%s\n",st,t[ir][ic]);
                j=j-1;
                an=ip[j];
         }
        goto TEMP;
        }
      else if(an=='f')
        {
            j++;
            an=ip[j];
            if(an=='o')
            {
                j++;
                an=ip[j];
                if(an=='r')
                {
                ic=4;
                strcpy(r,strrev(t[ir][ic]));
                strrev(t[ir][ic]);
                pop();
                push(r);
                display();
                display1(ip,j-2);
                printf("\t\t%c->%s\n",st,t[ir][ic]);
                j=j-2;
                an=ip[j];
                }
            }
        goto TEMP;
      }
      else if(an==';')
      {
        ic=5;
        strcpy(r,strrev(t[ir][ic]));
        strrev(t[ir][ic]);
        pop();
        push(r);
      }
      else if(an=='(')
      {
        ic=6;
        strcpy(r,strrev(t[ir][ic]));
        strrev(t[ir][ic]);
        pop();
        push(r);
      }
      else if(an==')')
      {
        ic=7;
        strcpy(r,strrev(t[ir][ic]));
        strrev(t[ir][ic]);
        pop();
        push(r);
      }
      else if(an==',')
        {
            ic=9;
            strcpy(r,strrev(t[ir][ic]));
            strrev(t[ir][ic]);
            pop();
            push(r);
       }
      else if(an=='g')
      {
        ic=10;
        strcpy(r,strrev(t[ir][ic]));
        strrev(t[ir][ic]);
        pop();
        push(r);
      }
      else if(an=='r')
      {
        ic=12;
        strcpy(r,strrev(t[ir][ic]));
        strrev(t[ir][ic]);
        pop();
        push(r);
      }
      else if(an=='1')
      {
        ic=13;
        strcpy(r,strrev(t[ir][ic]));
        strrev(t[ir][ic]);
        pop();
        push(r);
      }
      else if(an=='+')
        {
        j++;
        an=ip[j];
        if(an=='+')
            {
            ic=14;
            strcpy(r,strrev(t[ir][ic]));
            strrev(t[ir][ic]);
            pop();
            push(r);
            display();
            display1(ip,j-1);
            printf("\t\t%c->%s\n",st,t[ir][ic]);
            j--;
            an=ip[j];
            }
        goto TEMP;
        }
      else if(an=='p')
      {
        ic=15;
        strcpy(r,strrev(t[ir][ic]));
        strrev(t[ir][ic]);
        pop();
        push(r);
      }
      else if(an=='q')
      {
        ic=16;
        strcpy(r,strrev(t[ir][ic]));
        strrev(t[ir][ic]);
        pop();
        push(r);
      }
      else if(an=='$')
      {
        ic=17;
        strcpy(r,strrev(t[ir][ic]));
        strrev(t[ir][ic]);
        pop();
        push(r);
      }
      else if(an=='<')
        {
        j++;
        an=ip[j];
        if(an=='=')
            {
            ic=20;
            strcpy(r,strrev(t[ir][ic]));
            strrev(t[ir][ic]);
            pop();
            push(r);
            display();
            display1(ip,j-1);
            printf("\t\t%c->%s\n",st,t[ir][ic]);
            j--;
            an=ip[j];
            }
        else if(an=='>')
        {
            ic=22;
            strcpy(r,strrev(t[ir][ic]));
            strrev(t[ir][ic]);
            pop();
            push(r);
            display();
            display1(ip,j-1);
            printf("\t\t%c->%s\n",st,t[ir][ic]);
            j--;
            an=ip[j];
        }
        else
        {
        j--;
        ic=18;
        strcpy(r,strrev(t[ir][ic]));
        strrev(t[ir][ic]);
        pop();
        push(r);
        an=ip[j];
        }
        goto TEMP;
      }
      else if(an=='>')
        {
        j++;
        an=ip[j];
        if(an=='=')
            {
            ic=21;
            strcpy(r,strrev(t[ir][ic]));
            strrev(t[ir][ic]);
            pop();
            push(r);
            display();
            display1(ip,j-1);
            printf("\t\t%c->%s\n",st,t[ir][ic]);
            j--;
            an=ip[j];
            }
        else
            {
                j--;
                ic=19;
                strcpy(r,strrev(t[ir][ic]));
                strrev(t[ir][ic]);
                pop();
                push(r);
                an=ip[j];
            }
        goto TEMP;
      }
      else if(an=='=')
        {
        j++;
        an=ip[j];
        if(an=='=')
            {
            ic=23;
            strcpy(r,strrev(t[ir][ic]));
            strrev(t[ir][ic]);
            pop();
            push(r);
            display();
            display1(ip,j-1);
            printf("\t\t%c->%s\n",st,t[ir][ic]);
            j--;
            an=ip[j];
            }
         else
         {
        j--;
        ic=11;
        strcpy(r,strrev(t[ir][ic]));
        strrev(t[ir][ic]);
        pop();
        push(r);
        an=ip[j];
         }
        goto TEMP;
      }
      if(TOS()=='e')
      {
	   pop();
       display();
       display1(ip,j);
       printf("\t\t%c->%c\n",st,238);
      }
      else
        {
        display();
        display1(ip,j);
        printf("\t\t%c->%s\n",st,t[ir][ic]);
        }
      if(TOS()=='$'&& an=='$')
      break;
      if(TOS()=='!')
        {
	    error();
	    }
    }

    k=strcmp(stack(),"$");
    if(k==0 && i==strlen(ip))
    printf("\nGiven String is not accepted\n");
    else
    printf("\nGiven String is accepted\n");
}




