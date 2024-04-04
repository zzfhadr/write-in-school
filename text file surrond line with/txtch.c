#include <stdio.h>
#include <string.h>
//this program read every lines in a txt file, and add " " to every lines. example:
//line1 in ew.txt is:sfdf
//and you will get surround.bat line1 is :"sfdf"
//this program will create a file surround.bat, so the file input can't have same name to it 
//I guess it will never happen, right?

void delnextiln(char * str)
{
	int i;
	for (i=0;;i++)
	{
		if (*(str+i)=='\n')
		{
			*(str+i)='\0';
			break;
		}

	}
}
int main(int argc, char *argv[])
{
	FILE *fp_in, *fp_out;
	char file_name[250]={0};
	if( argc == 2 ) {
		strcpy(file_name,argv[1]);		//commandline argument directly allows to compress the file
	}
   	else if( argc > 2 ) {
      		printf("Too many arguments supplied.\n");
      		return 0;
   	}
   	else {
		printf("Please enter the file \t: "); //else a prompt comes to enter the file name
		scanf("%s",file_name);
   	}
	if(strlen(file_name)>=250){ 
		printf("ERROR: Enter a file name less than 50 chars");
		return 0;
	}
	if((fp_in = fopen(file_name,"r"))==NULL){	//open the file stream
		printf("\nERROR: File entered not exist\n");
		return 0;
	}
	 char str[300];
	 int ret;
	 ret = remove("surround.bat");
	  if(ret == 0) {
      printf("already have a file named surround.bat, it's removed. I guess it's not a big deal UwU\n");
   } else {
      printf("U_U Nothing happened\n");
   }
	 fp_out=fopen("surround.bat","w");
    while (fgets(str, 300, fp_in) != NULL) {
    	fprintf(fp_out,"%c", '"');
    	delnextiln(str);
        fprintf(fp_out,"%s", str);
        fprintf(fp_out,"%c\n", '"');
    }
    fclose(fp_out);
    fclose(fp_in);
        ret = remove(file_name);
   if(ret == 0) {
      printf("I removed the original file,It's ok, you have surround.txt now");
   } else {
      printf("What happened!!??");
   }
   return 0;	 
}