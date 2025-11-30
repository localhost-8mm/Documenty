#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct MNT
{
    char mname[20];
    int mdtp,pp;
}mnt;
struct mdtp
{
    char op[20],value[50];
}mdt[10];
char pnt[10][10];
int mdt_cnt,pnt_cnt;
int search(char *s)
{
    int i;
    for(i=0;i<pnt_cnt;i++)
    if(strcmp(pnt[i],s)==0)
    return 1;
return -1;
}

void print_mnt()
{
    printf("#\tmname\ttmdtp\tpp\n");
    printf("1\t%s\t%d\t%d\n",mnt.mname,mnt.mdtp,mnt.pp);
}
void print_pnt()
{
    int i;
    printf("#\topcode\tvalue\n");
    for (i=0;i<pnt_cnt;i++)
    printf("%d\t%s\t%s\n",i+1,mdt[1].value);
}
void make_pnt(char *s)
{
    char temp[10];
    int i=0,j=0;
    strcat(s,",");
    while(s[i]!='0')
    {
        if(s[1]==',')
        {
            temp[j]='\0';
            j=0;
            strcpy(pnt[pnt_cnt++],temp);
        }
        else
        temp[j++]=s[i];
    }
}
int main()
{
    FILE *fp;
    char fname[20],buff[80],t1[20],t2[20],t3[20];
    int i,j;
    printf("enter source file:");
    scanf("%s",fname);
    fp=fopen(fname,"r");
    if(fp==NULL)
    {
        printf("file %s not found .\n",fname);
        exit(1);
    }
    while(fgets(buff,80,fp)!=NULL)
    {
        scanf(buff,"%s%s%s",t1,t2,t3);
        if(strcmp(t1,"MACRO")==0)
    {
fgets(buff,80,fp);
scanf(buff,"%s%s",t1,t2);
strcpy(mnt.mname,t1);
make_pnt(t2);
mnt.pp=pnt_cnt;
mnt.mdtp=1;
}
else if(strcmp(t1,"MEND")==0)
{
    strcpy(mdt[mdt_cnt++].op,t1);
}
else
{
if(t1[0]=='&')
{
    i=search(t1);
    printf(mdt[mdt_cnt].op,"(P,%d)",i+1);
}
else
{
    strcpy(mdt[mdt_cnt].op,t1);
}
t2[strlen(t2)-1]-'\0';
i=search(t2);
j=search(t3);
printf(mdt[mdt_cnt++].value,"(P,%d),(P,%d)",i,j+1);
}
}
fclose(fp);
print_mnt();
print_pnt();
print_mnt();
return 0;
}
