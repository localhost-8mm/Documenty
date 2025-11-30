#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
    char line[80];
    struct node *next;
}NODE;
NODE *first,*last;
int len,changed;
NODE * get_node(char *s)
{
    NODE *p;
    p=(NODE*)malloc(sizeof(NODE));
    strcpy(p->line,s);
    p->next=NULL;
    return p;
}
void save(char fname[])
{
    FILE *fp;
    NODE *p;
    fp = fopen(fname,"w");
    p = first;
    while(p!=NULL)
    {
        fputs(p->line,fp);
        p=p->next;
    }
    fclose(fp);
    changed=0;
}

void create(char fname[])
{
    NODE *p;
    FILE *fp;
    char buff[80];
    fp = fopen(fname,"r");
    if(fp==NULL)
    {
            printf("File %s not found.\n",fname);
            exit(1);
    }
    while(fgets(buff,80,fp)!=NULL)
    {
         p = get_node(buff);

        if(first==NULL)
            first = p;
         else
            last->next = p;
            last = p;
         
            len++;
    }
fclose(fp);
}
void append()
{
    NODE *p;
    char buff[80];
    fflush(stdin);
    fgets(buff,80,stdin);
     p = get_node(buff);
        if(first==NULL)
            first = p;
        else
           last->next = p;
        last=p;
        len++;
    
    changed=1;
}
void find()
{
        NODE *p,*p1;
        int i;
         char buff[80];
        printf("\n enter the pattern");
        fgets(buff,80,stdin);
        for(p=first;p!=NULL;p=p->next)
        {
            if(strstr(p->line,buff))
                    printf("%s",p->line);
        }
}
void print(int n1,int n2)
{
        NODE *p,*p1;
        int i;
        //print all the lines
        //printf("\n n1=%d n2=%d",n1,n2);
        for(p=first;p!=NULL;p=p->next)
        printf("%s",p->line);
                
                /* p n1 p 5
for(i=1,p=first;i<n1&&p!=NULL;i++, p=p->next);
         printf("%s",p1->line);*/
           
           /* p n1 n2
for(i=1,p=first;i<n1&&p!=NULL;i++, p=p->next); //till n1th line
 
for(i=n1,p1=p;i<=n2&&p1!=NULL;i++, p1=p1->next) // n1 to n2
        printf("%s",p1->line); */
        }

void move(int n1, int n2)
{
    NODE *p,*q,*t,*p1;
    int i;
    i=1;
for(p=first,i=1;p!=NULL&&i<n1-1;i++,p=p->next);
    p1 = p->next;// node to be cut 
    p->next = p1->next;// node is cut 
 
   while(i<n2)
    {
        i++;
        q=p;
        p=p->next;
    }
    if(p==first)
    {
         p1->next=first;
        first=p1;
    }
    else
    {
        q->next=p1;
        p1->next=p;
    }
       changed=1;
}
void copy(int n1, int n2)
{
    NODE *p,*q,*t;
    int i;
    i=1;
    for(p=first,i=1;p!=NULL&&i<n1;i++,p=p->next);

    t = get_node(p->line);// copied node
    i=1;
    p=q=first;
    while(i<n2)
    {
        i++;
        q=p;
        p=p->next;
    }
    if(p==first)
    {
         t->next=first;
        first=t;
    }
    else
    {
        q->next=t;
        t->next=p;
    }
    len++;
    changed=1;
}
void insert(int n1)
{
    NODE *p,*p1,*p2;
    int i;
    char buff[80];
  for(i=1,p=first;i<n1-1&&p!=NULL;i++,p=p->next);
  //printf("\n %s",p->line);
  printf("Enter text ");
    fflush(stdin);
    fgets(buff,80,stdin);
    p1 = get_node(buff);
    p2 = p->next;
    p1->next = p2;
    p->next = p1;
    changed=1;
}
void del(int n1)
{
    NODE *p,*p1,*p2;
    int i;
    for(i=1,p=first;i<n1-1&&p!=NULL;i++,p=p->next);
  printf("\n %s",p->line);
    p1 = p->next;
    p2 = p1->next;
    p->next = p2;
    free(p1);
    changed=1;
}
void help()
{
    printf("\n Help");
    printf("\n append:   a (enter) \n insert: i 3 (enter) \n delete: d 4(enter) \n print:  p (all) \n p 3(specific) p 3 5(range)");
    printf("\n move: m 3 5 \n copy: c 4 6");
}
int main()
{
    char buff[80],ch,fname[30]="";
    int n1,n2;
    printf("\n enter file name");
    scanf("%s",fname);
    fflush(stdin);
    create(fname);

while(1)
{
    printf("$");
    fflush(stdin);
    fgets(buff,80,stdin); //c 3 6
    sscanf(buff,"%c %d %d",&ch,&n1,&n2);
    switch(ch)
    {
        case 'f': find(); break;
        case 'm': move(n1,n2);
                    break;
        case 'd': del(n1);
                    break;
        case 'c': copy(n1,n2);
                    break;
        case 'i': insert(n1);
                    break;
        case 'p':print(n1,n2);
                break;
        case 'a':
                append();
                break;
        case 's':
            if(changed==1)
            {
                   save(fname);
             }
         break;
         case 'h':help(); break;
     case 'e':
           
 exit(0);
 default:
 printf("Invalid command.\n");
 }
}
return 0;
}