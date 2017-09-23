#include <stdio.h>
int main(int iArgCount, char ** arrArgs)
{
if(iArgCount == 0)
{	
	printf("\n usage: charToAscii character \n");
	return 1;
}
else
{
	printf("\n%d %x %o in dec, hex, oct.\n",*(*(arrArgs+1)),*(*(arrArgs+1)),*(*(arrArgs+1)));
	return 0;
}
}

