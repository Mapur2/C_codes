#include<stdio.h>
#include<string.h>
// removal of "the"
void main()
{
   char str[100],rm[15];
   char word[15];
   int len, i, j=0, p, k;
   printf("Enter\n");
   gets(str);
   
   strcat(str," ");
   len=strlen(str);
   printf("Enter remove word ");
   gets(rm);
   
   for(i=0;str[i]!='\0';i++){
   	if(str[i]!=' ')
   		word[j++]=str[i];
   	else{
   		word[j]='\0';
   		j=0;
   		if(strcmp(word,rm)==0){
   			//Shift character in main string

   			p=i+1;
   			for(k=i-strlen(rm);str[p]!='\0';k++,p++){printf("%c\n",str[k]);
   				str[k]=str[p];
   				printf("%c\n",str[k]);
			   }
			   str[k]='\0';
			   i=-1;
		   }
	   }
   }
   printf("%s",str);
}
