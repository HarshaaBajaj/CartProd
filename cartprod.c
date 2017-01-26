#include <stdio.h>
#include <stdlib.h>
#define CHUNK 1024 
void main()
{
char bufa[CHUNK], bufb[CHUNK];
char buf[CHUNK];
size_t nbytes = 200;    /*this is the variable for the number of bytes initially allocated for your stream*/
char *your_string1;
char *your_string;
FILE *fp1,*fp2;
int linesa=0, j=1;
int i,a;
fp1 = fopen("file1.txt", "r");
fp2=fopen("file2.txt","r"); 
your_string = (char *) malloc (nbytes + 1);
your_string1 = (char *) malloc (nbytes + 1);
while ( fgets(bufa,sizeof bufa,fp1))
    linesa++;
fclose(fp1);
fp1 = fopen("file1.txt", "r");
if (fp1&&fp2) 
{		
	while( !feof( fp1 ) )
	{
		a=getline(&your_string1, &nbytes, fp1);
		while((fgets(bufb,sizeof bufb,fp2))>0)
		{
			printf("\nCartesian Set:%d\n",j);
			j++;
			puts(your_string1);
			fputs(bufb,stdout);
			if(feof(fp2)!=0)
				{
				printf("\nEnd of file two reached\n");
				linesa--;
				if(linesa>0){
				i=getline(&your_string, &nbytes, fp1);
				your_string1= your_string;
				rewind(fp2);
				}
				}
			
		}
	}
}
else 
	printf("\n Error in opening files\n");
fclose(fp1);
fclose(fp2);
}
