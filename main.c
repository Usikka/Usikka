#include<stdio.h>
#include<string.h>
struct Directory{
  char dname[10] , fname[100][100];
  int fno ;
} dir[100];
void main()
{
  int i,j,a;
  int dno=0;
  char del[100];
  char search[100];
  char temp[100];
  char save[100];  
  do
  {
    int b = 0;
    printf("1.Create Directory\n2.Create File\n3.Delete Directory\n4.Delete File\n5.Search\n6.Display All Files\n7.Exit\n");
    scanf("%d", &a);
    switch (a)
    {
     case 1: printf("Enter new directory name :");
             scanf("%s",dir[dno].dname);
             dno++;
             break;

     case 2: printf("Enter filename : ");
             scanf("%s",temp);
             printf("Enter save directory:");
             scanf("%s",save);
             b=1;
             for(i=0;i<=dno;i++)
             {
               if(strcmp(save,dir[i].dname)==0)
               {
                 strcpy(dir[i].fname[dir[i].fno],temp);
                 dir[i].fno++;
                 b=0;
               }
             }
             if(b==1)
              printf("No such directory\n");
            
             break;

     case 3: printf("Enter Directory to be deleted :");
             scanf("%s",save);
             b=1;
             for(i=0;i<=dno;i++)
             {
              if(strcmp(save,dir[i].dname)==0)
              {
               strcpy(dir[i].dname,"null");
               printf("File Deleted\n");
               b=0;
              }

             }
             if(b==1)
              printf("No such file\n");

             break;
     case 4: printf("Enter Directory : ");
             scanf("%s",save);
             printf("Enter Filename : ");
             scanf("%s",temp);
             b=1;
             for(i=0;i<=dno;i++)
             {
              if(strcmp(save,dir[i].dname)==0)
              {
               for(j=0;j<=dir[i].fno;j++)
               {
                if(strcmp(temp,dir[i].fname[j])==0)
                {
                 strcpy(dir[i].fname[j],"null");
                 b=0;
                }
               }
              }
             }
             if(b==1)
               printf("No such file\n");

             break;
     case 5: printf("Enter file to be searched:");
             scanf("%s",search);
             b=1;
             for(i=0;i<=dno;i++)
             {
              for(j=0;j<=dir[i].fno;j++)
              {
               if(strcmp(search,dir[i].fname[j])==0)
               { 
                printf("File found at %s\n",dir[i].dname);
                b=0;
               }
              }
             }
             if(b==1)
              printf("No such file\n");
             break;
     case 6: for(i=0;i<=dno;i++)
             {
              if(strcmp(dir[i].dname , "null")==0) 
               continue;
              printf("   %s   \n",dir[i].dname);
              for(j=0;j<=dir[i].fno;j++)
              {
               if(strcmp(dir[i].fname[j], "null")==0)
                continue;
               printf("%s\n",dir[i].fname[j]);
              }
             }
           break;
    }
  }while(a<7);
}