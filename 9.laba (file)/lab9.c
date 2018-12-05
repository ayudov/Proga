#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

FILE *fil;
typedef struct
{
    char city[30];
    float square;
    long int people;
}record;

record reg[50];

char* name;
int i,k,ch,q;

void create();
void open();
void delf();
void ad();
void show();
void edit();
void sort();
void del();

int main()
{
    int er,erf,n;
    char str[10];
    char *error;
    do
    {   do
        {
        er=0;
        printf("\n\n\nFile.\n1. Create.\n2. Open.\n3. Delete.\n4. Exit.\n");
        scanf("%s",&str);
        n=strtol(str,&error,10);
        if(strlen(error)!=0||n<1||n>4)
        {
            printf("\nEnter only number 1-4!\n");
            fflush(stdin);
            er=1;
            continue;
        }
        } while (er==1);
        er=1;
        switch(n)
        {
            case 1:
                create();
                break;
            case 2:
                open();
                break;
            case 3:
                delf();
                break;
            case 4:
                exit(0);
                break;
        }
        if((n==2)&&(k==0))
        {
            do
            {
                erf=0;
                printf("\nRecording.\n1. Add.\n2. Show.\n3. Edit.\n4. Sorting.\n5. Insert.\n6. Delete.\n7. Exit\n");
                if (scanf("%d", &n)!=1||n<1||n>7)
                {
                    printf("\nEnter only number 1-6!\n");
                    fflush(stdin);
                    erf=1;
                    continue;
                }
                switch(n)
            {
            case 1:
                ad();
                break;
            case 2:
                show();
                break;
            case 3:
                edit();
                break;
            case 4:
                q=0;
                sort();
                break;
            case 5:
                q=1;
                ad();
                sort();
                break;
            case 6:
                del();
                break;
            case 7:
                erf=1;
                fclose(fil);
                break;
            }
            }while(erf==0);
        }
    }
    while(er==1);
}

void create()
{
    printf("\nEnter the file name.\n");
    name=(char*) malloc(20);
    scanf("%s", name);
    if((fil=fopen(name, "r"))!=NULL)
    {
        printf("\nFile with the same name already exists.\n");
        fclose(fil);
    }
    else
    {
        if ((fil=fopen(name, "w"))!=NULL)
        {
            printf("\nThe file was created.\n");
            fclose(fil);
        }
        else
        {
            printf ("\nThe file is not created.\n");
            getch();
            exit(1);
        }
    }
}

void open()
{
    k=0;
    printf("\nEnter the file name to open.\n");
    name=(char*) malloc(20);
    scanf("%s", name);
    if((fil=fopen(name, "r"))!=NULL)
    {
        printf("\nThe file was opened.\n");
        fclose(fil);
    }
    else
    {
        printf("\nCan not open file. Incorrect name.\n");
        k=1;
    }
  }

void delf()
{
    printf("\nEnter the file name to delete.\n");
    name=(char*) malloc(20);
    scanf("%s", name);
    if((fil=fopen(name, "r"))!=NULL)
    {
        fclose(fil);
        remove(name);
        printf("\nFile deleted.\n");
    }
    else
    {
        printf("\nCan not delete file. Incorrect name.\n");
    }
    fclose(fil);
}

void ad()
{
    fil=fopen(name, "a");
    int n;

    printf("\nEnter the number of entries.\n");
    if((scanf("%d",&n)==1)&&(getchar()=='\n')&&(n>0)&&(n<=10))
    {
        for (i=0;i<n;i++)
        {
        printf("\nEnter: City name, City area, Population =>");
        fflush(stdin);
        if((scanf("%s%f%d",&reg[i].city,&reg[i].square,&reg[i].people)==3)&&(getchar()=='\n')&&(reg[i].square>0)&&(reg[i].people>0))
        {
            fprintf(fil,"%s %f %d ",reg[i].city,reg[i].square,reg[i].people);
        }
        else{printf("\nError. Try again.\n");i=i-1;}}
        fputc('\n',fil);
    }
    else
    {
        ("\nNumber of records must be 1<=z<=10.\n");
    }
    fclose(fil);
}

void show()
{
    fil=fopen(name,"r");

    i=1;
    printf("\nNUMB                 NAME     SQUARE     POPULATION\n");
    while(!feof(fil))
    {
        if((fscanf(fil,"%s%f%d",&reg[i].city,&reg[i].square,&reg[i].people))==3)
        {
            printf("\nN(%2d)==>%15s %10.2f %10d",i,reg[i].city,reg[i].square,reg[i].people);i++;
        }
    }
    fclose(fil);
}

void edit()
{
    fil=fopen(name,"r");
    i=1;
    while(!feof(fil))
    {
        fscanf(fil,"%s%f%d",&reg[i].city,&reg[i].square,&reg[i].people);
        i++;
    }

    int n=i-2,str,ch;

    for(i=1;i<=n;i++)printf("\nN(%2d)==>%15s %10.2f %10d",i,reg[i].city,reg[i].square,reg[i].people);
    printf("\nWhat line need to change?\n");
    if((scanf("%d",&str)==1)&&(getchar()=='\n')&&(str>0)&&(str<n+1))
    {
        printf("\nWhat change?:\n1. Name city.\n2. Square.\n3. Number of people.\n");
        if((scanf("%d",&ch)==1)&&(getchar()=='\n')&&(ch>0)&&(ch<4))
        {
            if(ch==1)
            {
                printf("\nEnter new City name: ");
                (scanf("%s",&reg[str].city));
            }
            if(ch==2)
            {
                printf("\nEnter new Square: ");
                (scanf("%f",&reg[str].square));
            }
            if(ch==3)
            {
                printf("\nEnter new Population: ");
                (scanf("%d",&reg[str].people));
            }
            fflush(stdin);
        }
    }
    else
    {
        printf("\nEnd work.\n");
    }

    fil=fopen(name,"w");
    remove(name);
    for (i=1;i<=n;i++)
    {
        fprintf(fil,"%s %f %d ",reg[i].city,reg[i].square,reg[i].people);
        fputc('\n',fil);
    }
    fclose(fil);
}

void sort()
{
    fil=fopen(name,"r");
    i=1;
    while(!feof(fil))
    {
        fscanf(fil,"%s%f%d",&reg[i].city,&reg[i].square,&reg[i].people);
        i++;
    }

    int n=i-2,str,j,l;
    record p;
    if((q==0)||(ch==0))
    {
        printf("\nWhat sorting?:\n1. Alphabet.\n2. Square.\n3. Population.\n");
        if((scanf("%d",&ch)==1)&&(getchar()=='\n')&&(ch>0)&&(ch<4))
        {
            printf("\nGOOD!\n");
        }
    }
    if(ch==1)
    {
        for(j=1; j<=n; j++)
        {
            for(l=1; l<=n; l++)
            {
                if(strcmp(reg[j].city,reg[l].city)<0)
                {
                    p=reg[j];
                    reg[j]=reg[l];
                    reg[l]=p;
                }
            }
        }
        printf("\nNUMB                 NAME     SQUARE     POPULATION\n");
        for(i=1;i<=n;i++)printf("\nN(%2d)==>%15s %10.2f %10d",i,reg[i].city,reg[i].square,reg[i].people);
    }
    if(ch==2)
    {
        for(j=1; j<=n; j++)
        {
            for(l=1; l<=n; l++)
            {
                if(reg[j].square<reg[l].square)
                {
                    p=reg[j];
                    reg[j]=reg[l];
                    reg[l]=p;
                }
            }
        }
        printf("\nNUMB                 NAME     SQUARE     POPULATION\n");
        for(i=1;i<=n;i++)printf("\nN(%2d)==>%15s %10.2f %10d",i,reg[i].city,reg[i].square,reg[i].people);
    }
    if(ch==3)
    {
        for(j=1; j<=n; j++)
        {
            for(l=1; l<=n; l++)
            {
                if(reg[j].people<reg[l].people)
                {
                    p=reg[j];
                    reg[j]=reg[l];
                    reg[l]=p;
                }
            }
        }
        printf("\nNUMB                 NAME     SQUARE     POPULATION\n");
        for(i=1;i<=n;i++)printf("\nN(%2d)==>%15s %10.2f %10d",i,reg[i].city,reg[i].square,reg[i].people);
    }

    fil=fopen(name,"w");
    remove(name);
    for (i=1;i<=n;i++)
    {
        fprintf(fil,"%s %f %d ",reg[i].city,reg[i].square,reg[i].people);
        fputc('\n',fil);
    }
    fclose(fil);
}

void del()
{
    fil=fopen(name,"r");
    i=1;
    while(!feof(fil))
    {
        fscanf(fil,"%s%f%d",&reg[i].city,&reg[i].square,&reg[i].people);
        i++;
    }

    int n=i-2,str;

    for(i=1;i<=n;i++)printf("\nN(%2d)==>%15s %10.2f %10d",i,reg[i].city,reg[i].square,reg[i].people);
    printf("\nWhat line need to delete?\n");
    if((scanf("%d",&str)==1)&&(getchar()=='\n')&&(str>0)&&(str<n+1))
    {
        for(i=str;i<n;i++)
        {
            reg[i]=reg[i+1];
        }
    }

    fil=fopen(name,"w");
    remove(name);
    for (i=1;i<n;i++)
    {
        fprintf(fil,"%s %f %d ",reg[i].city,reg[i].square,reg[i].people);
        fputc('\n',fil);
    }
    fclose(fil);
}
