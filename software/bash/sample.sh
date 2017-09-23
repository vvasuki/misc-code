#! /bin/bash
#welcome to the bash programming manual.. maah style.

clear #this clears the screen
#hither variables are defined.
iTmp=23
strTmp="Raman"

#the read function: input from the stdin
read iTmp
read iTmp strTmp

#the echo function: output to stdout
echo $iTmp  \t $strTmp\n\n
#note how $var refers to the variable's value.. whereas the var refers to the variable itself.

#arithmetic operators [+-*/] and expressions.. the expr command
#notice how stuff inside `` [not '']  gets evaluated as a command first.
#iTmp1=78
#iTmp= $iTmp + $iTmp1
#echo $iTmp

pwd
#control structures:
#if construct
if grep controll sample.*
then
	echo pattern found
elif grep trol
then
	echo trol ist found.
else
	echo pattern not found
fi

#case construct
strTmp = `date +%m%d`;
case $strTmp in 
	02/19)	echo my bdy;
        #08/24)  echo my bdy;
	#*)	echo "nothing day.\n";
esac

