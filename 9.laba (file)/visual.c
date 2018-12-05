#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char name[225], c, a[3], b[10], e[4], d[10], f[2], exitchar, temp, s[4], n_stringc[3], *estr, q_5_n_string[3], *abc, ch[1], *t, *pointer_list[25], sorting[1], c1_string[10], c2_string[10];
int  edit, q, i, k, z, n_stringi[2], p, o, j, p, m, qq, mm, aa, sortingg, delet, pp, pl, jj, cc, ss, ss2, n, bb, nn, ii;
char r_string[4], r2_string[4];
long pos;
double tt;
struct mybas
{
	char obl[25];
	double plosha;
	double nas;		
};
struct mybas *y, *x1;
struct mybas u[50], bn[50];


FILE*file;

	menu()
{
	do
	{
	system("cls");
	printf(">  what you want to do?\n");
	printf(">1-create a new file\n");
	printf(">2-read the file\n");
	printf(">3-delete the file\n");
	printf(">4-create a record in file\n");
	printf(">5-read string(s) of file\n");
	printf(">6-edit file\n");
	printf(">7-organize the file\n");
	printf(">8-insert string\n");
	printf(">9-delete string from the file\n");
	printf(">");
	gets(a);
	q = atoi (a);
	if(strlen(a)>1||strlen(a)<=0){printf ("\n>Enter only number of unit.\n\n>Press any key to continue\n\n");getch();j=0;}
	else{printf("\n");j=1;}	
}while(j!=1);
}

	q_1()
{
do
{
	printf(">Enter name (255 max) and format (.txt) of file\n>");	
	gets(name);
	for(ii=0; name[ii]!=0; ii++){}
	if(strlen(name)>255||strlen(name)<4||name[ii-1]!=116||name[ii-2]!=120||name[ii-3]!=116||name[ii-4]!=46){printf(">Please, follow the example\n\n");j=0;}
	else
	{			
		if((file=fopen(name, "r"))!=NULL){printf("\n>This file already exist\n");fclose(file);j=1;}
		else
		{
			printf(">Creating file\n\n");
			file=fopen(name, "a");
			fprintf(file, "Your list\n");	
			if (file == NULL) {printf (">Error creating, this file can not be created\n");j=1;}
			else {printf (">Done\n");j=1;}				
			fclose(file);
		}
	}
}while(j!=1);
}


	q_2()
{
q=0;
do
{	
	printf(">Enter name (255 max) and format (.txt) of file\n>");		
	gets(name);
	if((strlen(name)>255||strlen(name)<4)){printf (">Please, follow the example\n\n");j=0;}
	else
	{			
		do
		{
			printf(">Do you want open the file? (1)\n>or\n>Do you want to see the information here? (2)\n>");
			gets(a);
			p = atoi (a);
			if(p!=1&&p!=2||strlen(a)>1){printf(">Please, choose the type\n\n");j=0;}else{j=1;}
		}while(j!=1);
		if (p==1)
		{
			printf(">Reading file\n\n");
			if (( file=fopen (name, "r" )) != NULL)
			{
				rewind(file);
				fgets(c1_string, 10, file);fseek (file, 2, 1);
				fgets(c2_string, 10, file);
				if(strcmp(c1_string, "Your list")!=0){printf(">This is not your file! :(\n\n");j=1;fclose(file);}
				else 				
				{	
					if(strcmp(c2_string, "\0")==0){printf(">This file is empty\n");j=1;fclose(file);}
					else
					{
						system(name);
						fclose(file);
						printf("\n>Done\n");
						j=1;
					}
				}
			}else{printf(">Error reading file, this file does not exist\n");fclose(file);j=1;}			
		}
		else if(p==2)
		{
			printf(">Reading file\n\n");
			y=&u[0];
			char f,*h,*v;
			h=(char*)calloc(50,sizeof(char));
			v=(char*)calloc(50,sizeof(char));
			if (( file=fopen (name, "r" )) != NULL)
			{	
				rewind(file);
				fgets(c1_string, 10, file);fseek (file, 2, 1);
				fgets(c2_string, 10, file);	
				if(strcmp(c1_string, "Your list")!=0){printf(">This is not your file! :(\n\n");j=1;fclose(file);}
				else 				
				{
					if(strcmp(c2_string, "\0")==0){printf(">This file is empty\n");j=1;fclose(file);}
					else
					{			
						fseek(file, 11, 0);
						printf(">--------Name------------Square-------------Population-------------------\n\n\n");
						for(i=0; !feof(file); i++)
						{
							y=&u[i];
							fgets((*y).obl,50,file);
							fgets(h,50,file);
							y->plosha=atof(h);
							fgets(v,50,file);
							y->nas=atof(v);
							{						
								printf(">%d)\n",i+1);
					 			printf("	%s",y->obl);
				 				printf("			%.2lf\n",y->plosha);
								printf("						%.0lf\n\n",y->nas);
							}								
						}
						printf(">--------------------------------------------------------------------------\n\n\n");
						free(v);
						free(h);
						fclose(file);
						printf("\n>Done\n");
					}
				}
			}else{printf(">Error reading file, this file does not exist\n");fclose(file);j=1;}	
		}else{printf(">Choose one of units\n");j=0;}
	}
}while(j!=1);
}


	q_3()
{
do
{
	printf(">Enter name (255 max) and format (.txt) of file\n>");
	gets(name);
	if((strlen(name)>255||strlen(name)<5)){printf (">Please, follow the example\n\n");j=0;}
	else
	{		
		file=fopen(name, "r");
		rewind(file);
		fgets(c1_string, 10, file);
		if(strcmp(c1_string, "Your list")!=0){printf("\n>Deliting file\n\n");printf(">This is not your file! :(\n");fclose(file);j=1;}	
		else
		{	
			fclose(file);
			printf("\n>Deliting file\n");
			if(-1 == remove (name))
			{
				printf(">Error deliting file, this file does not exist\n");
				fclose(file);
				j=1;
			}
			else{printf("\n>Done\n");fclose(file);j=1;}	
		}
	}
}while(j!=1);
}


	q_4()
{
do
{
	printf(">Enter name (255 max) and format (.txt) of file\n>");	
	gets(name);
	if((strlen(name)>255||strlen(name)<4)){printf (">Please, follow the example\n\n");j=0;}
	else
	{				
		file=fopen(name, "r+");
		if(file==NULL){printf(">Error opening file, this file does not exist\n");fclose(file);j=1;}		
		else
		{	
			rewind(file);
			fgets(c1_string, 10, file);fseek (file, 2, 1);
			if(strcmp(c1_string, "Your list")!=0){printf("\n>This is not your file! :(\n");fclose(file);j=1;}
			else
			{
				fgets(c2_string, 10, file);
				if(strcmp(c2_string, "\0")==0){pp=0;}
				else{pp=1;}
				char f,*h,*v;
				h=(char*)calloc(50,sizeof(char));
				v=(char*)calloc(50,sizeof(char)); 
				for(i=0; !feof(file); i++)
				{
					y=&u[i];
					fgets((*y).obl,50,file);
					fgets(h,50,file);
					y->plosha=atof(h);
					fgets(v,50,file);
					y->nas=atof(v);																	
				}
				if(i>=25){printf("\n>This file is full, please, create one\n");fclose(file);j=1;}
				else
				{
					do
					{
						printf(">There are %d strings in this file\n", i);
						printf(">How many strings would you record to? (totally 25 MAX)\n>");			
						gets(e);
						z = atoi (e);	
						if	(z==0||z>25-i){printf("\n>Please, read the task\n\n");jj=0;nn=0;}
						else
						{								
							for(n=0; e[n]!=0; n++)
							{
								if(e[n]!=49&&e[n]!=50&&e[n]!=51&&e[n]!=52&&e[n]!=53&&e[n]!=54&&e[n]!=55&&e[n]!=56&&e[n]!=57&&e[n]!=48){printf ("\n>Please, read the task\n\n");jj=0;nn=0;break;}
								else{jj=1;nn=1;}																																	
							}						
						}if(nn==1){jj=1;}
					}while(jj!=1);								
					fseek(file, 0L, SEEK_END);			
					struct mybas arr[z];
					for (k=0; k<z; k++)
					{
						do
						{
							printf(">Enter name of district (MAX 255 characters)\n>");
							gets(arr[k].obl);
							if((strlen(arr[k].obl)>255||strlen(arr[k].obl)<1)){printf (">Enter name of district (less than 255 characters)\n\n");j=0;}
							else{if(k!=0||pp==1){fprintf(file, "\n");}fprintf(file, "%s\n", arr[k].obl);j=1;}						
						}while(j!=1);
						do
						{
							printf(">Enter square\n>");					
							gets(b);
							arr[k].plosha=atof(b);
							if(arr[k].plosha>510100000||arr[k].plosha<=0){printf (">Enter only numbers from 0 to 510100000 (not exponential form)\n\n");j=0;nn=0;}
							else
							{								
								for(n=0; b[n]!=0; n++)
								{
									if(b[n]!=49&&b[n]!=50&&b[n]!=51&&b[n]!=52&&b[n]!=53&&b[n]!=54&&b[n]!=55&&b[n]!=56&&b[n]!=57&&b[n]!=48){printf (">Enter only numbers from 0 to 510100000 (not exponential form)\n\n");j=0;nn=0;break;}
									else{j=1;nn=1;}																																	
								}						
							}if(nn==1){fprintf(file, "%.0lf\n",arr[k].plosha);j=1;}
						}while(j!=1);
						do
						{
							printf(">Enter number of population\n>");
							gets(d);
							arr[k].nas=atoi(d);
							if(arr[k].nas>7000000000||arr[k].nas<=0){printf (">Enter only numbers from 0 to 7000000000 (not exponential form)\n\n");j=0;nn=0;}
							else
							{								
								for(n=0; d[n]!=0; n++)
								{
									if(d[n]!=49&&d[n]!=50&&d[n]!=51&&d[n]!=52&&d[n]!=53&&d[n]!=54&&d[n]!=55&&d[n]!=56&&d[n]!=57&&d[n]!=48){printf (">Enter only numbers from 0 to 7000000000 (not exponential form)\n\n");j=0;nn=0;break;}
									else{j=1;nn=1;}																																	
								}						
							}if(nn==1){fprintf(file, "%.0f", arr[k].nas);j=1;}
						}while(j!=1);
					//	p=0;
					}			
					printf("\n>Done\n");
					fclose(file);
				}
			}
		}
	}
}while(j!=1);
}


	q_5()
{	
do
{
	printf(">Enter name (255 max) and format (.txt) of file\n>");
	gets(name);
	if((strlen(name)>255||strlen(name)<5)){printf (">Please, follow the example\n\n");j=0;}
	else
	{
		printf(">Reading file\n\n");
		y=&u[0];
		char f,*h,*v;
		h=(char*)calloc(50,sizeof(char));
		v=(char*)calloc(50,sizeof(char));
		if (( file=fopen (name, "r" )) != NULL)
		{	
			rewind(file);
			fgets(c1_string, 10, file);fseek (file, 2, 1);
			fgets(c2_string, 10, file);	
			if(strcmp(c1_string, "Your list")!=0){printf(">This is not your file! :(\n");fclose(file);j=1;}
			else 				
			{
				if(strcmp(c2_string, "\0")==0){printf(">This file is empty\n");fclose(file);j=1;}
				else
				{
					rewind(file);
					fseek(file, 11, 0);
					for(i=0; !feof(file); i++)
						{
							y=&u[i];
							fgets((*y).obl,50,file);
							fgets(h,50,file);
							y->plosha=atof(h);
							fgets(v,50,file);
							y->nas=atof(v);							
						}
						printf(">You have %d strings in your file\n", i);
					do
					{								
						printf(">From which string you want to start?\n>");
						gets(r_string);
						ss=atoi(r_string);
						if(ss>i||ss<=0||strlen(r_string)>3){printf(">Please, choose one of strings\n\n");j=0;nn=0;}
						else
						{								
							for(n=0; r_string[n]!=0; n++)
							{
								if(r_string[n]!=49&&r_string[n]!=50&&r_string[n]!=51&&r_string[n]!=52&&r_string[n]!=53&&r_string[n]!=54&&r_string[n]!=55&&r_string[n]!=56&&r_string[n]!=57&&r_string[n]!=48){printf(">Please, choose one of strings\n\n");j=0;nn=0;break;}
								else{j=1;nn=1;}																																	
							}						
						}if(nn==1){j=1;}
					}while(j!=1);						
					do
					{
						printf("\n>Enter second string (above the first)\n>or\n>press the same, as first, to see this string\n>");
						gets(r2_string);
						ss2=atoi(r2_string);
						if(ss2<ss||ss2>i||ss2==0||strlen(r2_string)>3){printf(">Please, read the task\n\n");j=0;nn=0;}
						else
						{								
							for(n=0; r2_string[n]!=0; n++)
							{
								if(r2_string[n]!=49&&r2_string[n]!=50&&r2_string[n]!=51&&r2_string[n]!=52&&r2_string[n]!=53&&r2_string[n]!=54&&r2_string[n]!=55&&r2_string[n]!=56&&r2_string[n]!=57&&r2_string[n]!=48){printf(">Please, read the task\n\n");j=0;nn=0;break;}
								else{j=1;nn=1;}																																	
							}						
						}if(nn==1){j=1;}
					}while(j!=1);
					printf(">--------Name------------Square-------------Population-------------------\n\n\n");
					do
					{
						printf(">%d)\n",ss);
						printf("	%s",u[ss-1].obl);
				 		printf("			%.2lf\n",u[ss-1].plosha);
						printf("						%.0lf\n\n",u[ss-1].nas);
						ss++;
					}while(ss<=ss2);
					printf("\n>-----------------------------------------------------------------------\n\n\n");	
					fclose(file);
				}
			}	
			j=1;
		}else{printf(">Error reading file, this file does not exist\n");fclose(file);j=1;}
	}
}while(j!=1);
}


	q_6()
{
do
{
	printf(">Enter name (255 max) and format (.txt) of file\n>");
	gets(name);
	if((strlen(name)>255||strlen(name)<5)){printf (">Please, follow the example\n\n");j=0;}
	else
	{
		char f,*h,*v;
		h=(char*)calloc(50,sizeof(char));
		v=(char*)calloc(50,sizeof(char));
		if (( file=fopen (name, "r+" )) != NULL)
		{			
			rewind(file);
			fflush(file);
			fgets(c1_string, 10, file);fseek (file, 2, 1);
			fgets(c2_string, 10, file);	
			if(strcmp(c1_string, "Your list")!=0){printf("\n>This is not your file! :(\n");fclose(file);j=1;}
			else 				
			{
				if(strcmp(c2_string, "\0")==0){printf(">This file is empty\n");fclose(file);j=1;}
				else
				{
					fseek(file, 11, 0);
					printf(">--------Name------------Square-------------Population-------------------\n\n\n");
					for(i=0; !feof(file); i++)
					{
						y=&u[i];
						fgets((*y).obl,50,file);
						fgets(h,50,file);
						y->plosha=atof(h);
						fgets(v,50,file);
						y->nas=atof(v);
						{						
							printf(">%d)\n",i+1);
					 		printf("	>%s",y->obl);
				 			printf("			>%.2lf\n",y->plosha);
							printf("						>%.0lf\n\n",y->nas);
						}								
					}
					printf(">------------------------------------------------------------------------\n\n");	
					free(v);
					free(h);
					fclose(file);	
					do
					{
						printf(">Which string you want to edit?\n>");
						gets(s);
						edit = atoi (s);
						if (edit>i||edit<=0||strlen(s)>4){printf("\n>Please, choose the string\n\n");cc=0;nn=0;}
						else
						{
							for(n=0; s[n]!=0; n++)
							{
								if(s[n]!=49&&s[n]!=50&&s[n]!=51&&s[n]!=52&&s[n]!=53&&s[n]!=54&&s[n]!=55&&s[n]!=56&&s[n]!=57&&s[n]!=48){printf(">Please, choose the string\n\n");cc=0;nn=0;break;}
								else{cc=1;nn=1;}																																	
							}						
						}if(nn==1){cc=1;}
					}while(cc!=1);
					printf(">Enter a new string\n\n");
					do
					{
						printf(">Enter name of district (MAX 255 characters)\n>");
						gets(u[edit-1].obl);
						if((strlen(u[edit-1].obl)>255||strlen(u[edit-1].obl)<1)){printf (">Plese, read the task\n\n");j=0;}
						else{j=1;}						
					}while(j!=1);
					do
					{
						printf(">Enter square\n>");						
						gets(b);
						u[edit-1].plosha=atof(b);
						if(u[edit-1].plosha>510100000||u[edit-1].plosha<=0||u[edit-1].plosha=='\n'){printf (">Plese, enter integer square from 0 to 510100000 (not exponential form)\n\n");j=0;nn=0;}
						else
						{								
							for(n=0; b[n]!=0; n++)
							{
								if(b[n]!=49&&b[n]!=50&&b[n]!=51&&b[n]!=52&&b[n]!=53&&b[n]!=54&&b[n]!=55&&b[n]!=56&&b[n]!=57&&b[n]!=48){printf (">Plese, enter integer square from 0 to 510100000 (not exponential form)\n\n");j=0;nn=0;break;}
								else{j=1;nn=1;}																																	
							}						
						}if(nn==1){j=1;}																			
					}while(j!=1);
					do
					{
						printf(">Enter number of population\n>");
						gets(d);
						u[edit-1].nas=atof(d);
						if(u[edit-1].nas>7000000000||u[edit-1].nas<=0||u[edit-1].nas=='\n'){printf (">Plese, enter number of population from 0 to 7000000000 (not exponential form)\n\n");j=0;nn=0;}
						else
						{								
							for(n=0; d[n]!=0; n++)
							{
								if(d[n]!=49&&d[n]!=50&&d[n]!=51&&d[n]!=52&&d[n]!=53&&d[n]!=54&&d[n]!=55&&d[n]!=56&&d[n]!=57&&d[n]!=48){printf (">Plese, enter number of population from 0 to 7000000000 (not exponential form)\n\n");j=0;nn=0;break;}
								else{j=1;nn=1;}																																	
							}						
						}if(nn==1){j=1;}							
					}while(j!=1);
					file=fopen(name,"w");
					fprintf(file, "Your list\n");
					fseek(file, 11, 0);
					for(qq=0; qq<i; qq++)
					{
						if(qq!=0){fprintf(file, "\n");}
						fprintf(file, "%s",u[qq].obl);
						if(qq==edit-1){fprintf(file, "\n");}
						fprintf(file, "%.0lf\n",u[qq].plosha);
						fprintf(file, "%.0lf",u[qq].nas);				
					}
					fclose(file);
					printf("\n>Done\n");
					j=1;				
				}
			}
		}else {printf(">Error opening file, this file does not exist\n");fclose(file);j=0;}		
	}
}while(j!=1);
}


	q_7()
{
do
{
	printf(">Enter name (255 max) and format (.txt) of file\n>");
	gets(name);
	if((strlen(name)>255||strlen(name)<5)){printf (">Please, follow the example\n\n");j=0;}
	else
	{
		if (( file=fopen (name, "r" )) == NULL){printf("\n>This file does not exist, try another\n\n");j=0;}
		else
		{
			rewind(file);
			fflush(file);
			fgets(c1_string, 10, file);fseek (file, 2, 1);
			fgets(c2_string, 10, file);	
			if(strcmp(c1_string, "Your list")!=0){printf("\n>This is not your file! :(\n\n");j=1;fclose(file);}
			else 				
			{
				if(strcmp(c2_string, "\0")==0){printf(">This file is empty\n");fclose(file);j=1;}
				else
				{					
					do
					{		
						printf(">Choose measure to sort\n>Name (1)\n>Square (2)\n>Population (3)\n>");			
						gets(ch);
						mm=atoi(ch);
						if(strlen(ch)>1||mm!=1&&mm!=2&&mm!=3){printf(">Please, read the task\n\n");j=0;}else{j=1;}
					}while(j!=1);
													
					char f,*h,*v;
					h=(char*)calloc(50,sizeof(char));
					v=(char*)calloc(50,sizeof(char));
					rewind(file);
					fseek(file, 11, 0);
					fflush(file);
					for(i=0; !feof(file); i++)
					{
						y=&u[i];
						fgets((*y).obl,50,file);
						fgets(h,50,file);
						y->plosha=atof(h);
						fgets(v,50,file);
						y->nas=atof(v);
					}
					fclose(file);
					switch (mm)
					{				
						case 1:
						{
							for (aa=0; aa<i; aa++) 
							{
								pointer_list[aa]=u[aa].obl;		
							}				
							for (aa=1; aa<i; aa++)
							{							
								while ( aa>0 && (strcmp(pointer_list[aa-1],pointer_list[aa])) > 0 )
								{
										t=pointer_list[aa];
										pointer_list[aa]=pointer_list[aa-1];
										pointer_list[aa-1]=t;
										tt=u[aa].plosha;
										u[aa].plosha=u[aa-1].plosha;
										u[aa-1].plosha=tt;
										tt=u[aa].nas;
										u[aa].nas=u[aa-1].nas;
										u[aa-1].nas=tt;
										aa--;
								}	
							}							
							do
							{
								printf ("You want to sort the list by ascending (1), or by descending (2)?\n");
								gets(sorting);
								sortingg=atoi(sorting);
								if(sortingg!=1&&sortingg!=2||strlen(sorting)>1){printf(">Please, read the task\n\n");j=0;}else{j=1;}
							}while(j!=1);					
							if (( file=fopen (name, "w" )) == NULL){printf(">This file does not exist, try another\n");j=0;fclose(file);break;}
							else
							{
								switch (sortingg)
								{
									case 1:
									{
										fprintf(file, "Your list\n");
										for(aa=0; aa<i; aa++)
										{
											if(aa!=0){fprintf(file, "\n");}
											fprintf(file, "%s",pointer_list[aa]);
											fprintf(file, "%.0lf\n",u[aa].plosha);
											fprintf(file, "%.0lf",u[aa].nas);
										}
										break;
									}
									case 2:
									{
										fprintf(file, "Your list\n");
										for(aa=i-1; aa>=0; aa--)
										{
											if(aa!=i-1){fprintf(file, "\n");}
											fprintf(file, "%s",pointer_list[aa]);
											fprintf(file, "%.0lf\n",u[aa].plosha);
											fprintf(file, "%.0lf",u[aa].nas);
										}
										break;								
									}
								}
								j=1;
								fclose(file);
								printf("\n>Done\n");
								break;
							}
						}
						
						case 2:
						{
							for (aa=0; aa<i; aa++) 
							{
								pointer_list[aa]=u[aa].obl;		
							}				
							for (aa=1; aa<i; aa++)
							{							
								while ( aa>0 && (u[aa-1].plosha>u[aa].plosha) > 0 )
								{
										t=pointer_list[aa];
										pointer_list[aa]=pointer_list[aa-1];
										pointer_list[aa-1]=t;
										tt=u[aa].plosha;
										u[aa].plosha=u[aa-1].plosha;
										u[aa-1].plosha=tt;
										tt=u[aa].nas;
										u[aa].nas=u[aa-1].nas;
										u[aa-1].nas=tt;
										aa--;
								}	
							}							
							do
							{
								printf ("You want to sort the list by ascending (1), or by descending (2)?\n");
								gets(sorting);
								sortingg=atoi(sorting);
								if(sortingg!=1&&sortingg!=2||strlen(sorting)>1){printf(">Please, read the task\n\n");j=0;}else{j=1;}
							}while(j!=1);
							if (( file=fopen (name, "w" )) == NULL){printf(">This file does not exist, try another\n");j=0;fclose(file);break;}
							else
							{
								switch (sortingg)
								{
									case 1:
									{
										fprintf(file, "Your list\n");
										for(aa=0; aa<i; aa++)
										{
											if(aa!=0){fprintf(file, "\n");}
											fprintf(file, "%s",pointer_list[aa]);
											fprintf(file, "%.0lf\n",u[aa].plosha);
											fprintf(file, "%.0lf",u[aa].nas);
										}
										break;
									}
									case 2:
									{
										fprintf(file, "Your list\n");
										for(aa=i-1; aa>=0; aa--)
										{
											if(aa!=i-1){fprintf(file, "\n");}
											fprintf(file, "%s",pointer_list[aa]);
											fprintf(file, "%.0lf\n",u[aa].plosha);
											fprintf(file, "%.0lf",u[aa].nas);
										}
										break;								
									}
								}						
								j=1;
								fclose(file);
								printf("\n>Done\n");
								break;
							}					
						}						
						case 3:
						{
							for (aa=0; aa<i; aa++) 
							{
								pointer_list[aa]=u[aa].obl;		
							}				
							for (aa=1; aa<i; aa++)
							{							
								while ( aa>0 && (u[aa-1].nas>u[aa].nas) > 0 )
								{
									t=pointer_list[aa];
									pointer_list[aa]=pointer_list[aa-1];
									pointer_list[aa-1]=t;
									tt=u[aa].plosha;
									u[aa].plosha=u[aa-1].plosha;
									u[aa-1].plosha=tt;
									tt=u[aa].nas;
									u[aa].nas=u[aa-1].nas;
									u[aa-1].nas=tt;
									aa--;
								}	
							}													
							do
							{
								printf ("You want to sort the list by ascending (1), or by descending (2)?\n");
								gets(sorting);
								sortingg=atoi(sorting);
								if(sortingg!=1&&sortingg!=2||strlen(sorting)>1){printf(">Please, read the task\n\n");j=0;}else{j=1;}
							}while(j!=1);
							if(sortingg!=1&&sortingg!=2){printf(">Please, enter name and choose type of sorting\n\n");j=0;}
							else
							{
								if (( file=fopen (name, "w" )) == NULL){printf(">This file does not exist, try another\n");fclose(file);j=0;}
								else
								{
									switch (sortingg)
									{
										case 1:
										{
											fprintf(file, "Your list\n");
											for(aa=0; aa<i; aa++)
											{
												if(aa!=0){fprintf(file, "\n");}
												fprintf(file, "%s",pointer_list[aa]);
												fprintf(file, "%.0lf\n",u[aa].plosha);
												fprintf(file, "%.0lf",u[aa].nas);
											}
											break;
										}
										case 2:
										{
											fprintf(file, "Your list\n");
											for(aa=i-1; aa>=0; aa--)
											{
												if(aa!=i-1){fprintf(file, "\n");}
												fprintf(file, "%s",pointer_list[aa]);
												fprintf(file, "%.0lf\n",u[aa].plosha);
												fprintf(file, "%.0lf",u[aa].nas);
											}											
											break;								
										}
									}
									j=1;
									fclose(file);
									printf("\n>Done\n");
									break;
								}
							}
						}						
						default:
						{
							printf (">Please, enter name and choose the item\n");
							j=0;
						}							
					}
				}
			}
		}
	}
}while(j!=1);
}


	q_8()
{
do
{	
	printf(">Enter name (255 max) and format (.txt) of file\n>");
	gets(name);
	if((strlen(name)>255||strlen(name)<5)){printf (">Please, follow the example\n\n");j=0;}
	else
	{
		char f,*h,*v;
		h=(char*)calloc(50,sizeof(char));
		v=(char*)calloc(50,sizeof(char));
		if (( file=fopen (name, "r+" )) != NULL)
		{
			rewind(file);
			fflush(file);
			fgets(c1_string, 10, file);fseek (file, 2, 1);
			fgets(c2_string, 10, file);	
			if(strcmp(c1_string, "Your list")!=0){printf(">This is not your file! :(\n");j=1;fclose(file);}
			else 				
			{
				if(strcmp(c2_string, "\0")==0){printf(">This file is empty\n");j=1;fclose(file);}
				else
				{				
					fflush(file);
					fseek(file,11,0);
					printf(">--------Name------------Square-------------Population-------------------\n\n\n");
					for(i=0; !feof(file); i++)
					{
						y=&u[i];
						fgets((*y).obl,50,file);
						fgets(h,50,file);
						y->plosha=atof(h);
						fgets(v,50,file);
						y->nas=atof(v);
						{						
							printf(">%d)\n",i+1);
					 		printf("	%s",y->obl);
				 			printf("			%.2lf\n",y->plosha);
							printf("						%.0lf\n\n",y->nas);
						}	  				
					}
					printf(">------------------------------------------------------------------------\n\n\n");
					free(v);
					free(h);
					fclose(file);
					if(i>=25){printf(">This file is full, please, create one\n\n");fclose(file);j=1;}	
					else
					{			
						do
						{
							printf(">After which string you want insert?\n>or\n>Press '0' to insert in the start\n>");
							gets(s);
							edit = atoi(s);
							if(edit<0||edit>i||strlen(s)>3){printf(">Please, choose one of the string\n\n");j=0;nn=0;}
							else
							{
								for(n=0; s[n]!=0; n++)
								{
								//	printf(">s[%d]:%c\n", n, s[n]);
									if(s[n]!=49&&s[n]!=50&&s[n]!=51&&s[n]!=52&&s[n]!=53&&s[n]!=54&&s[n]!=55&&s[n]!=56&&s[n]!=57&&s[n]!=48){printf(">Please, choose the string\n\n");j=0;nn=0;break;}
									else{j=1;nn=1;}																																	
								}						
							}if(nn==1){j=1;}
						}
						while(j!=1);		
						printf(">Enter a new string\n");
							do
							{
								printf(">Enter name of district\n");
								gets(bn[edit-1].obl);
								if((strlen(bn[edit-1].obl)>255||strlen(bn[edit-1].obl)<1)){printf (">Please, read the task\n\n");j=0;}
								else{j=1;}						
							}while(j!=1);
							do
							{
								printf(">Enter square (from 0 to 510100000)\n>");
								gets(b);
								bn[edit-1].plosha=atof(b);
								if(bn[edit-1].plosha>510100000||bn[edit-1].plosha<=0||bn[edit-1].plosha=='\n'){printf (">Please, enter integer square from 0 to 510100000 (not exponential form)\n\n");j=0;nn=0;}
								else
								{								
									for(n=0; b[n]!=0; n++)
									{
										if(b[n]!=49&&b[n]!=50&&b[n]!=51&&b[n]!=52&&b[n]!=53&&b[n]!=54&&b[n]!=55&&b[n]!=56&&b[n]!=57&&b[n]!=48){printf (">Please, enter integer square from 0 to 510100000 (not exponential form)\n\n");j=0;nn=0;break;}
										else{j=1;nn=1;}																																	
									}						
								}if(nn==1){j=1;}																		
							}while(j!=1);
							do
							{
								printf(">Enter number of population (from 0 to 7000000000)\n>");
								gets(d);
								bn[edit-1].nas=atof(d);
								if(bn[edit-1].nas>7000000000||bn[edit-1].nas<=0||bn[edit-1].nas=='\n'){printf (">Plese, enter number of population from 0 to 7000000000 (not exponential form)\n\n");j=0;nn=0;}
								else
								{								
									for(n=0; d[n]!=0; n++)
									{
										if(d[n]!=49&&d[n]!=50&&d[n]!=51&&d[n]!=52&&d[n]!=53&&d[n]!=54&&d[n]!=55&&d[n]!=56&&d[n]!=57&&d[n]!=48){printf (">Plese, enter number of population from 0 to 7000000000 (not exponential form)\n\n");j=0;nn=0;break;}
										else{j=1;nn=1;}																																	
									}						
								}if(nn==1){j=1;}								
							}while(j!=1);	
							file=fopen(name,"w");
							fprintf(file, "Your list\n");
							for(qq=0; qq<=i; qq++)
							{
								if(qq==edit){if(qq!=0){fprintf(file, "\n");}fprintf(file, "%s\n",bn[edit-1].obl);fprintf(file, "%.0f\n",bn[edit-1].plosha);fprintf(file, "%.0f",bn[edit-1].nas);}
								else{}													
								if(qq!=i)
								{	if(qq!=0||edit==0){fprintf(file, "\n");}		
									else{}							
									fprintf(file, "%s",u[qq].obl);
									fprintf(file, "%.0lf\n",u[qq].plosha);
									fprintf(file, "%.0lf",u[qq].nas);
								}
							}			
					fclose(file);
					printf("\n>Done\n");
					}
				}
			}
		}else{printf("\n>Error opening file\n");j=1;fclose(file);}	
	}
}while(j!=1);
}


	q_9()
{
do
{
	printf(">Enter name (255 max) and format (.txt) of file\n>");
	gets(name);
	if((strlen(name)>255||strlen(name)<5)){printf (">Please, follow the example\n\n");j=0;}
	else
	{
		char f,*h,*v;
		h=(char*)calloc(50,sizeof(char));
		v=(char*)calloc(50,sizeof(char));
		if (( file=fopen (name, "r+" )) != NULL)
		{
			rewind(file);
			fflush(file);
			fgets(c1_string, 10, file);fseek (file, 2, 1);
			fgets(c2_string, 10, file);	
			if(strcmp(c1_string, "Your list")!=0){printf(">This is not your file! :(\n");j=1;fclose(file);}
			else 				
			{
				if(strcmp(c2_string, "\0")==0){printf(">This file is empty\n");j=1;fclose(file);}
				else
				{
					fflush(file);
					rewind(file);
					fseek(file,11,0);
					printf(">--------Name------------Square-------------Population-------------------\n\n\n");
					for(i=0; !feof(file); i++)
					{
						y=&u[i];
						fgets((*y).obl,50,file);
						fgets(h,50,file);
						y->plosha=atof(h);
						fgets(v,50,file);
						y->nas=atof(v);
						{						
							printf(">%d)\n",i+1);
					 		printf("	%s",y->obl);
				 			printf("			%.2lf\n",y->plosha);
							printf("						%.0lf\n\n",y->nas);
						}	  				
					}
					printf(">------------------------------------------------------------------------\n\n\n");
					free(v);
					free(h);
					fclose(file);				
					do
					{	
						printf(">Which string you want to delete?\n>");				
						gets(s);
						edit = atoi (s);
						if(edit<=0||edit>i||strlen(s)>3){printf(">Please, choose one of the string\n\n");j=0;nn=0;}
						else
						{
							for(n=0; s[n]!=0; n++)
							{
								if(s[n]!=49&&s[n]!=50&&s[n]!=51&&s[n]!=52&&s[n]!=53&&s[n]!=54&&s[n]!=55&&s[n]!=56&&s[n]!=57&&s[n]!=48){printf(">Please, choose the string\n\n");j=0;nn=0;break;}
								else{j=1;nn=1;}																																	
							}						
						}if(nn==1){j=1;}
					}while(j!=1);
					file=fopen (name, "w");
					fprintf(file, "Your list\n");
					if(edit==1)
					{
						for(delet=0; delet<i; delet++)
						{
							if(delet==edit-1){}
							else
							{		
								if(delet!=1){fprintf(file, "\n");}
								fprintf(file, "%s",u[delet].obl);
								fprintf(file, "%.0lf\n",u[delet].plosha);
								fprintf(file, "%.0lf",u[delet].nas);
							}
						}
					}
					else if(edit!=1)
					{
						for(delet=0; delet<i; delet++)
						{
							if(delet==edit-1){}
							else
							{		
								if(delet!=0){fprintf(file, "\n");}
								fprintf(file, "%s",u[delet].obl);
								fprintf(file, "%.0lf\n",u[delet].plosha);
								fprintf(file, "%.0lf",u[delet].nas);
							}
						}
					}
					fclose(file);
					printf(">Done");
					j=1;						
				}
			}
		}else{printf(">Error opening file, this file does not exist\n\n");j=1;fclose(file);}		
	}
}while(j!=1);
}


	main()
{
do
{	system("cls");
	menu();
	switch(q)
	{
		case 1:
		{
			q_1();
			break;
		}
		case 2:
		{
			q_2();
			break;
		}
		case 3:
		{
			q_3();
			break;
		}
		case 4:
		{
			q_4();
			break;
		}
		case 5:
		{
			q_5();
			break;
		}
		case 6:
		{
			q_6();
			break;
			
		}
		case 7:
		{
			q_7();
			break;			
		}
		case 8:
		{
			q_8();
			break;
			
		}
		case 9:
		{
			q_9();
			break;
			
		}
		default:
		{
			printf (">Please, choose the item (press any key to restart)\n");
			q=2;
			getch();
		}
	}

if(q==2){fflush(stdin);}
else
{
	printf ("\n>Enter 'y' to restart\n");		
	exitchar = getch();
}
fflush(stdin);	
}while ( (exitchar == 'y')||(exitchar == 'Y')||(q==2));	 
return 0;
}
