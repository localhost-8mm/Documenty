#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct MNT
{
    char mname[10];
    int mdtp,kpdtp,pp,kp;
}mnt;

struct KPDTP
{
    char key[10],def[10];
}kpdt[5];
char pnt[10][10];
int pnt_cnt,kpdt_cnt;
void print_mnt()
{
    printf("#tname\tmdp\tkpdtp\t#pp\t#p\n");
    printf("\t%s\t%d\t%d\t%d\t%d\n",mnt.mname,mnt.mdtp,mnt.kpdtp,mnt.pp,mnt.kp);
}
void print_pnt()
{
    int i;
    printf("#tpname\n");
        for(i=0;i<pnt_cnt;i++)
    {   printf("%d\t%s\n",i+1,pnt[i]);
    }
}
void make_pnt_kpdt(char*s)
{

int i=0,j=0;
char temp[10];
strcat(s,",");
while(s[i]!='=')
{
    if(s[i]==',')
    {
        temp[i]='\0';
        j=0;
        strcpy(pnt[pnt_cnt++],temp);
    }
        else
        {
        temp[j++]=s[i];   
        }
    i++;
    }
while(s[i]!='\0')
        {
            if(s[i]=='=')
              {
                  temp[j]='\0';
                  j=0;
                  strcpy(pnt[pnt_cnt++],temp);
                  strcpy(kpdt[kpdt_cnt].key,temp);
              } 
              else if(s[i]==',')
              {
                temp[j]='\0';
                j=0;
                strcpy(kpdt[kpdt_cnt++].def,temp);
              }
              else
              {
                temp[j++]=s[i];       
              }
              i++;
              mnt.pp=pnt_cnt-kpdt_cnt;
              mnt.kp=kpdt_cnt;
        }
        int main()
        {
        FILE*fp;
        char fname[20],buff[80],t1[20],t2[20],t3[20];
        int i,j;
        printf("Enter soucre file name :");
        scanf("%s",fname);
        fp=fopen(fname,"r");
        if(fp==NULL)
        {
            printf("file %s is not found \n",fname);
            exit(1);
        }
        while(fgets(buff,80,fp)!=NULL)
        {
            scanf(buff,"%s%s%s",t1,t2,t3);
                if(strcmp(t1,"MACRO")==0)
                {
                    fgets(buff,80,fp);
                    sscanf(buff,"%s%s",t1,t2);
                    strcpy(mnt.mname,t1);
                    mnt.mdtp=mnt.kpdtp=1;
                    make_pnt_kpdt(t2);
                    break;
                }
        }
    fclose(fp);
    print_mnt();
    print_pnt();
    return 0;
}  

