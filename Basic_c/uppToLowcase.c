#include<stdio.h>
#include<string.h>
int main(int n,char *a[])
{
	if(n!=2)
	printf("Invalid Input");
	else
	{
		FILE *f,*fp;
		char ch,s[80],w[80];
		int i=0,j=0,k=0;
		f=fopen(a[1],"r");
		fp=fopen("targetfile.c","w");
		if(f==NULL)
		printf("file not present");
		else
		{
			while(fgets(s,79,f)!=NULL)
			{
				j=0;
				for(i=0;i<strlen(s);i++)
				{
					if(s[i]>='a'&& s[i]<='z' || s[i]>='A' && s[i]<='Z')
						w[j++]=s[i];
					else
					{
						w[j]='\0';
						j=0;
						if(strcmp(w,"FILE")==0 || strcmp(w,"NULL")==0 || strcmp(w,"SEEK_CUR")==0 || strcmp(w,"SEEK_SET")==0
						   ||strcmp(w,"SEEK_END")==0|| strcmp(w,"S_IREAD")==0 || strcmp(w,"S_IWRITE")==0 ||strcmp(w,"EOF")==0)
						   fputs(w,fp);
						else
						{
							for(k=0;k<strlen(w);k++)
							{
								if(w[k]>='A'&& w[k]<='Z')
								fputc(w[k]+32,fp);
								else
								fputc(w[k],fp);
							}
						}
						fputc(s[i],fp);
					}
				}
			}
		}
		fclose(fp);
		fclose(f);
	}
}
