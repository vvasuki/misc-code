/*
the sample c program: c documentation, my style.
i like to refer to sample code rather than the uncool english sentences in manuals, 
which are, in my opinion meant to be read only once. 
hopefully with this, when you return to a language after 2 years, 
you will be able to pick it up again in half an hour.
The starategy is to have this as a kind of reference and memory aid... 
you dont have to learn the vibhakti pratyaya all over again.
Book of reference in this case was: The C programming language (Ansi C) by Brian Kernighan and Dennis Ritchie.

finding help:
to get help about a c funtion, use pinfo or info.
*/
//run this with cc sample.c&&./a.out

/*
todo:
function accepting variable number of arguments.
*/

//including library files.
/*
Statements beginning with # are pre-processor statements.
c is a complied language. 
this here source code is processed to do some pre compilation processing, 
whereby preprocessor statements like ifdef, ifndef, define, include and such are evaluated. 
the resultant actual sorce code is compiled to object code. 
if any linking is required, that is done. 
then thou hast the executable... and heads and feet shall roll.
*/
// stdio.h is required for EOF, putchar, getchar
#include <stdio.h>

//Symbolic constant
#define CHICKEN65 65

//below ye see a variable of global scope.
int i100Global =100;
//function declaration
void printArgsToMain(int iNumOfArgs, char * * arrArg);
void basicPrintingParable();
void characterIO_Array_BitwiseOp_ifElseParable();
void copyStringParable();
/*ere ye see main. 
the function generally returns 0 to the environment on normal termination. 
int is the default return type. so it can be omitted.
*/
int main(int iNumOfArgs, char * * arrArg)
{
//below, ye see a parameter passed by value 
//and another by reference to its memory location, as arrays usually are. 
//what goes in the stack makes the diferrence.
printArgsToMain(iNumOfArgs,arrArg);
basicPrintingParable();
characterIO_Array_BitwiseOp_ifElseParable();
copyStringParable();
return 0;
}

//function definition
void printArgsToMain(int iNumOfArgs, char * * arrArg)
{
puts("aragarosa: ");
// below, ye see a variable with local or automatic scope.
int iCount;
// in ansi c, ye can not write stuff like for (int i=0, ... ) etc.
for(iCount=0;iCount<iNumOfArgs;iCount++)
	puts(arrArg[iCount]);
putchar('\n');
//ere you see the use of a variable of global scope.
printf("i100Global ist %d\n", i100Global);

//ere you see the use of a variable of global scope. 
//the existance of this variable is told to the compiler and linker throught the following statement.
extern int i200Global;
printf("i200Global ist %d\n",i200Global);
}

//by the way, global variables are generally automatically instantiated to 0.
int i200Global;

void basicPrintingParable(void)
{
//printing stuff: this works without including stdio.h in linux
printf("the sample c program\n");
/* 
escape sequence characters include:
       \"     double quote
       \NNN   character with octal value NNN (1 to 3 digits)
       \\     backslash
       \a     alert (BEL)
       \b     backspace
       \c     produce no further output
       \f     form feed
       \n     new line
       \r     carriage return
       \t     horizontal tab
       \v     vertical tab
       \xNN   byte with hexadecimal value NN (1 to 2 digits)
*/
int iTempFahr, iTempCel;
int iTempTableLowerLimit=0, iTempTableUpperLimit=300, iTempTableStep=20;
/*
datatypes include 
char which is 8 bits wide,
short which is 16 bits wide,
int, long, float, which are all 32 bits wide, 
double  which is 64 bits wide, 
long double which is 96 bits wide.
There are also qualifiers like signed and unsigned.
pointers are dealt well as unsigned integers.
there are other objects: arrays, structures, unions of the basic types, pointeres to them, and functions which return them.
*/
//below ye see the sizeof operator
printf("%d %d\n",sizeof(char),sizeof(short));
iTempFahr=iTempTableLowerLimit;
while(iTempFahr<=iTempTableUpperLimit)
{
	//note that the division 5/9 truncates.
	iTempCel=(iTempFahr-32)*5/9;
/*
behold, above you spied arithmatic operators, which include 
binary operators +,-,*,/,
unary operators -, +, --, ++
yea, these arithmatic operators, and the bitwise operators may be combined with the assignement operator = 
to give +=, |= and so on.
*/
	//fromatted output with right justification
	//explicit type casting shown below.
	printf("%3d\t%%\t%6.2f\n",iTempFahr,(float)iTempCel);
	iTempFahr+=iTempTableStep;
}
// %symbols used to tell printf the type of datatype being passed along:
printf("octale %o hexxo %x chaara %c decimal integer %d long \n",8,8,CHICKEN65,'A',33000);
//no arbitrary blocking (ecapsulation with {}) in C... for example can not block the following statement.
printf("double %lf long double %Lf\n",8.00000000008,(long double)8.000000007);
}

void characterIO_Array_BitwiseOp_ifElseParable()
{

//character input and output from and to a text stream
char cTmp;
//EOF is ^d in linux.
/*
note that a text stream is a sequence of characters divided by a \n or by EOF... 
for example, when getchar is invoked, 
characters strings like asdf\n are first buffered in to form a stream, 
and then, a single character is returned from the stream to the invoker of the getchar function.
when the stream is fully read, the stream is filled up again by reading stuff from the STDIN.
*/
int iWhiteSpaces=0;
int iWhiteSpaceCensus[3];
while((cTmp=getchar())!=EOF)
//(c=(getchar()!=EOF)) would give 0 or 1 as c's value.
{
//behold the logical operators: ||, &&, !
	if(cTmp=='\n'||cTmp==' '||cTmp=='\t') iWhiteSpaces++;
//there also exist the bitwise operators: |,&,~ which follow rules like 16&8=0, 16|8=24,~16=15
//behold arrays and decision making.
	if(cTmp=='\n')iWhiteSpaceCensus[0]++;
	else if (cTmp==' ')iWhiteSpaceCensus[1]++;
	else if (cTmp=='\t')iWhiteSpaceCensus[2]++;
	putchar(cTmp);
}
putchar('\n');
printf("number of white spaces your divine hand typed ist %d\n",iWhiteSpaces);
printf("the number of tabs thy vile dirty hand typed is %d\n",*(iWhiteSpaceCensus+2));
}

void copyStringParable()
{
//behold the pointers to memory locations, and how memory is allocated to them.
char *c=(char *) malloc(12);
strcpy(c,"oookle");
unsigned int x=(unsigned)c+strlen(c);
char *d=(char *)malloc(20);
char *e=d, *f=c;
int y;
printf("%c %d\n",*c,(y=23));
//behold, strings are terminated by 0, also called \0; or so the lib functions think.
while(*d++ =*c++);
printf("%s %s %u %u %u\n",f,e,x,c,d);

}

