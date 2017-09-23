#include <stdio.h>
#include <string.h>
#include <io.h>
//writ by vishvas
void writeToLog(char *message, int messageSize)
{
	int file;
	file = _open( "c:\\tmp.txt", _O_RDWR | _O_CREAT, 
                               _S_IREAD | _S_IWRITE);
	if(file==-1)
		  printf( "The file 'c:\\tmp.txt' was not opened\n" );
	_write(file,message,messageSize);
	_close( file);
}

//writ by vishvas
char * convertToHex(char *bytes,int size)
{
	if (size == 0)
		return "";
	char finalhash[200];
	char hexval[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	for(int j = 0; j < size; j++){
		finalhash[j*2] = hexval[((bytes[j] >> 4) & 0xF)];
		finalhash[(j*2) + 1] = hexval[(bytes[j]) & 0x0F];
		//printf("%c\n",finalhash[j*2]);
		//printf("%c\n",finalhash[j*2+1]);
		}
	finalhash[size*2]=0;
	return finalhash;

}

//writ by vishvas
char * testConvertToHex()
{
char bytes[]={0x12,0x23,0x4a};
char* chars=convertToHex(bytes,3);
printf("%s\n",chars);
return chars;
}

//writ by vishvas
char * writeToLogTest()
{
char bytes[]={0x12,0x23,0x4a};
char* chars=convertToHex(bytes,3);
writeToLog(chars,strlen(chars));
return chars;
}


void main()
{
	getchar();
}