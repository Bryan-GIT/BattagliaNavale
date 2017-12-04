#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>

void stampMat(int idim,int jdim,char t1[10][10],char t2[10][10]);
void setMat(int idim,int jdim, int carattere ,char t[10][10]);
void spUP(char t[10][10],int dim);
void muve(char t1[10][10],char t2[10][10]);
void muve2(char t1[10][10],char t2[10][10]);
void direction(int n,char t1[10][10],char t2[10][10],int x,int y);
float TIMESLEEP = 0.333333;

int main(){
 const int MAXSTRING = 20;
 const int IDIM = 10;
 const int JDIM = 10;
 system("color 0A");

 int i = 0 ;
 int j = 0 ;

 int key =0;

 int x=0;
 int y=0;

 char celle = 95;
 char  T1[IDIM][ JDIM];
   char  T2[IDIM][ JDIM];


   setMat(IDIM,JDIM,celle,T1);
   setMat(IDIM,JDIM,celle,T2);
   Sleep(TIMESLEEP);
   stampMat(IDIM,20,T1,T2);
   muve(T1,T2);
   muve2(T2,T1);

 system("PAUSE");
}
void setMat(int idim,int jdim, int carattere ,char t[10][10]){
 int i,j;
 for ( i = 0 ; i <  idim ; i++)
   {
     for (j = 0 ; j < jdim ; j++)
     {
       t[i][j] = carattere;

     }
   }
   }
void stampMat(int idim,int jdim,char t1[10][10],char t2[10][10]){
 int i,j;
 printf("\n\t   A  B  C  D  E  F  G  H  I  J       A  B  C  D  E  F  G  H  I  J  \n");
 printf("\t -------------------------------------------------------------------\n");
 for ( i = 0 ; i <  idim; i++)
 {
   if (i< idim-1){
                printf("\t%d|",i+1);
       }else{
                printf("       %d|",i+1);
             }
   for (j = 0 ; j < jdim; j++)
   {
       if(j==10){
                    printf("  |  ");
                   }
       if(j<10){
         printf(" %c ",t1[i][j] );
        }

        if(j>=10){
         printf(" %c ",t2[i][j-10] );
        }

   if(j==jdim-1){
               printf(" |\n");
            }
   }
 printf("\t -------------------------------------------------------------------\n");
   }
}
void muve(char t1[10][10],char t2[10][10]){
 int key =0;
 char c;
 int x=0;
 int y=0;
 int a=1;
   while(a){
      if (_kbhit()) {
           key = getch();
           c=t1[y][x];
           if(key == 80 ){
             t1[y][x]=c;
             y=(y+1)%10;
             Sleep(TIMESLEEP);
             system("cls");
       t1[y][x]=254;
       stampMat(10,20,t1,t2);
       fflush(stdin);
     }
           if(key == 72 ){
             t1[y][x]=c;
             y=(y+9)%10;
             Sleep(TIMESLEEP);
             system("cls");
       t1[y][x]=254;
       stampMat(10,20,t1,t2);
       fflush(stdin);
     }
           if(key == 77 ){
       t1[y][x]=c;
             x=(x+1)%10;
             Sleep(TIMESLEEP);
             system("cls");
       t1[y][x]=254;
       stampMat(10,20,t1,t2);
       fflush(stdin);
     }
           if(key == 75){
             t1[y][x]=c;
             x=(x+19)%10;
             Sleep(TIMESLEEP);
             system("cls");
       t1[y][x]=254;
       stampMat(10,20,t1,t2);
       fflush(stdin);
     }
     if(key == 49 ){
       direction(1,t1,t2,x,y);
       x=0;
       y=0;
     }
     if(key == 50 ){
       direction(2,t1,t2,x,y);
       x=0;
       y=0;
     }
     if(key == 51 ){
       direction(3,t1,t2,x,y);
       x=0;
       y=0;
     }
     if(key == 52 ){
       direction(4,t1,t2,x,y);
       x=0;
       y=0;
     }
       }
 }
}
void muve2(char t1[10][10],char t2[10][10]){
 int key =0;
 int x=0;
 int y=0;
 int a=1;
   while(a){
      if (_kbhit()) {
           key = _getch();
           if(key == 80){
             t1[y][x]=95;
             y=(y+1)%10;
             Sleep(TIMESLEEP);
             system("cls");
       t1[y][x]=254;
       stampMat(10,20,t2,t1);
       fflush(stdin);
     }
           if(key == 72){
             t1[y][x]=95;
             y=(y+9)%10;
             Sleep(TIMESLEEP);
             system("cls");
       t1[y][x]=254;
       stampMat(10,20,t2,t1);
       fflush(stdin);
     }
           if(key == 77 ){
       t1[y][x]=95;
             x=(x+1)%10;
             Sleep(TIMESLEEP);
             system("cls");
       t1[y][x]=254;
       stampMat(10,20,t2,t1);
       fflush(stdin);
     }
           if(key == 75 ){

             t1[y][x]=95;
             x=(x+19)%10;
             Sleep(TIMESLEEP);
             system("cls");
       t1[y][x]=254;
       stampMat(10,20,t2,t1);
       fflush(stdin);
     }
     if(key == 105 ){
             a=0;
     }
       }
 }
}

    // 80 giu dir 1
 // 75 sinistra dir 3
 // 77 destra dir 4
 // 72 su dir 2

void direction(int n,char t1[10][10],char t2[10][10],int x,int y){
 int key=0;
 int control_correct_pos = 0;
 int count_n=0;
 int i=0;
 int a=1;
 int dir= 0;
 while(a){
   Sleep(1);
   if (_kbhit()) {
           key = _getch();
           if(key == 80){
             control_correct_pos = 0;
             dir=1;
             count_n=0;
             Sleep(TIMESLEEP);
             system("cls");
             for (i=0;i<n;i++){

                   if(t1[y+i][x]!=219){
                   count_n ++;
                        }
                   }

               if (count_n!=n || y+n > 10){
                 control_correct_pos=1;
                 stampMat(10,20,t1,t2);
               }else{
               for (i=0;i<n;i++){
                 t1[y+i][x]=219;
           }
         stampMat(10,20,t1,t2);
         for (i=0;i<n;i++){
                 t1[y+i][x]=95;
         }
       }
       fflush(stdin);
     }
           if(key == 72){
             control_correct_pos = 0;
             dir=2;
             count_n=0;
             Sleep(TIMESLEEP);
             system("cls");
             for (i=0;i<n;i++){
                   if(t1[y-i][x]!=219){
                   count_n ++;
                        }
                   }
               if (count_n!=n || y-n < -1){
                 control_correct_pos=1;
                 stampMat(10,20,t1,t2);
               }else{
               for (i=0;i<n;i++){
                 t1[y-i][x]=219;
           }
                   printf("%d",n);
         stampMat(10,20,t1,t2);

         for (i=0;i<n;i++){
                 t1[y-i][x]=95;
           }
       }

       fflush(stdin);
     }
           if(key == 77 ){
             control_correct_pos = 0;
             dir=4;
             count_n=0;
             Sleep(TIMESLEEP);
       system("cls");

       for (i=0;i<n;i++){
                   if(t1[y][x+i]!=219){
                   count_n ++;
                        }
                   }

               if (count_n!=n || x+n > 10 || t1[y][x+n]==219){
                 control_correct_pos=1;
                 stampMat(10,20,t1,t2);
               }else{

                 for (i=0;i<count_n;i++){
                   t1[y][x+i]=219;
             }
         stampMat(10,20,t1,t2);
         for (i=0;i<count_n;i++){
               t1[y][x+i]=95;
         }
       }
       fflush(stdin);
     }
           if(key == 75 ){
             control_correct_pos = 0;
             dir=3;
             count_n=0;
             Sleep(TIMESLEEP);
             system("cls");

             for (i=0;i<n;i++){
                   if(t1[y][x-i]!=219){
                   count_n ++;
                        }
                   }
               if (count_n!=n || x-n < -1){
                 control_correct_pos=1;
                 stampMat(10,20,t1,t2);
               }else{
               for (i=0;i<n;i++){
                 t1[y][x-i]=219;
           }
         stampMat(10,20,t1,t2);
         for (i=0;i<n;i++){
                 t1[y][x-i]=95;
         }
               }

       fflush(stdin);
     }
     if(key == 105 && control_correct_pos == 0){
             break;
     }

       }
 }
     if(dir==1){
     for (i=0;i<n;i++){
       if(x+1<10)
         t1[y+i][x+1]=176;
             t1[y+i][x]=219;
             if(x-1>-1)
               t1[y+i][x-1]=176;
     }
     if(y-1>-1){
       t1[y-1][x]=176;
       t1[y-1][x+1]=176;
       t1[y-1][x-1]=176;
           }
     if(y+n<10){
       t1[y+n][x]=176;
               t1[y+n][x+1]=176;
               t1[y+n][x-1]=176;
               }
   }
 if(dir==2){
     for (i=0;i<n;i++){
       if(x+1<10)
         t1[y-i][x+1]=176;
             t1[y-i][x]=219;
             if(x-1>-1)
               t1[y-i][x-1]=176;
     }
     if(y-n>-1){
       t1[y-n][x]=176;
       t1[y-n][x+1]=176;
       t1[y-n][x-1]=176;
           }
     if(y+1<10){
       t1[y+1][x]=176;
       t1[y+1][x+1]=176;
       t1[y+1][x-1]=176;
           }
   }
 if(dir==3){
     for (i=0;i<n;i++){
       if(y+1<10)
         t1[y+1][x-i]=176;
             t1[y][x-i]=219;
             if(y-1>-1)
               t1[y-1][x-i]=176;
     }
     if(x-n>-1){
       t1[y][x-n]=176;
       t1[y+1][x-n]=176;
       t1[y-1][x-n]=176;
           }
     if(x+1<10){
       t1[y][x+1]=176;
       t1[y+1][x+1]=176;
       t1[y-1][x+1]=176;
           }
   }
 if(dir==4){
     for (i=0;i<n;i++){
       if(y+1<10)
         t1[y+1][x+i]=176;
             t1[y][x+i]=219;
             if(y-1>-1)
               t1[y-1][x+i]=176;
     }
     if(x+n<10){
       t1[y][x+n]=176;
       t1[y+1][x+n]=176;
       t1[y-1][x+n]=176;
           }
     if(x-1>-1){
       t1[y][x-1]=176;
           t1[y+1][x-1]=176;
           t1[y-1][x-1]=176;
               }
   }
}
