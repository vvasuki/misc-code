#include<stdio.h>

#include<time.h>

#include<string.h>
//for memset

#define FILE_AMMA "/home/guest/vishvas/progs/c/progs/amma.txt"

void printColorfully(char* strMsg)
{

	printf("\033[2J \033[12;24H");
	// clear screen, move cursor
	// see man console_codes for details
	printf("\t\t%s\n",strMsg);
	int j,i;
	for(j=1, i=20;i<20000;i+=3000, j+=1)
	{
		printf("%c\a ",7,strMsg);
		//sound(i);
		//delay(1000);
		//nosound();
	}
	getc(stdin);

}

void printAlarm(int iYr, int iMn, int iDay)
{
	char strMsg[100];
	memset(strMsg,0,100);
	sprintf(strMsg,"there is an appointment dated %d %d %d",iYr, iMn, iDay);
	printColorfully(strMsg);
}

int main()
{
	//printf("\n%s\n",SYSTEM);
	FILE *ammaFile = fopen(FILE_AMMA,"r");
	if(ammaFile == 0)
	{
		printf("\nunable to open amma.txt.\n");
		return 1;
	}

	int iYr, iMn, iDay;
	char strMsg[100];
	time_t iCurTime = time(0);
	//printf("\ntime is %ul\n", iCurTime);
	struct tm* today;

	today=localtime(&iCurTime);
	today->tm_year+=1900;
	today->tm_mon++;
        //printf("\nday is %d %d %d\n", today->tm_year, today->tm_mon, today->tm_mday);

	while(1)
	{
		iYr=iMn=iDay=0;

		fscanf(ammaFile,"%d %d %d",&iYr, &iMn, &iDay);
		while(!feof(ammaFile)&&fgetc(ammaFile)!='\n');
	
        	//printf("\n%d %d %d \n",iYr, iMn, iDay);

		if(iYr==0)
			return 0;
		if(iMn == 0 || iDay==0)
		{
			memset(strMsg,0,100);
		        sprintf(strMsg,"\ninvalid entry in file: %d %d %d \n",iYr, iMn, iDay);
			printColorfully(strMsg);
			return 1;
		}
		if(iYr<today->tm_year)
			printAlarm(iYr,iMn,iDay);
		else if (iYr == today->tm_year && iMn < today->tm_mon)
			printAlarm(iYr,iMn,iDay);
                else if (iYr == today->tm_year && iMn == today->tm_mon && iDay<=today->tm_mday)
			printAlarm(iYr,iMn,iDay);

	
	}

	fclose(ammaFile);
	return 0;
/*

		int j;


		for(j=1, i=100;i<1100;i+=100, j+=1)
		{
			textcolor(j);
			clrscr();
			printf("\n\n\n\n\n\n\n\n\n\n\n\t\t %s",msg);
			sound(i);
			delay(1000);
			nosound();
		}

		getch();
	}
*/
}
