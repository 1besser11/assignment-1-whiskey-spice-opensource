//Моя
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;
const int len = 60 , strings = 21;

char mass[len][strings];
typedef struct 
{
    int Points;
    char* Team;
}Table;
Table APL[20];
char temp;
char* score;

int main()
{
ifstream fs("/home/slavick/Рабочий стол/Labs/premier_league.csv",ios:: in|ios:: binary);
if(!fs)
 {
 fprintf(stderr, "File premier_league.csv was not opened \n");
 return 1;
 }

else{
 
 for(int i=0; i<=strings;i++)
 {
   if(!fs.eof())
    {
   fs.getline(mass[i], len , '\n');
   cout<< mass[i]<<endl;
   }
 for (int i=1;i<strings;i++)
 {   
        APL[i].Team = strtok(mass[i],",");
        cout<<APL[i].Team<<endl;   
 }
/*
 for(int k=0;k<10;k++)
 {
    while(p!=EOF  &&(p =fgetc(f))!=delim1  &&  p !=delim2 ) 
    {
        score[k1++] = p;
    }

if(score[0]>score[2])
t[number].points +=3;
else if(score[0]==score[2])
t[number].points += 1;
k1 = 0;
    }
   if (p!=EOF) number++;
        
}*/


 fs.close();
 return 0;
  }
}