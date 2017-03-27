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
 
 for(int i=0; i<strings;i++)
 {
   if(mass[i]!="\0")
    {
   fs.getline(mass[i], len , '\n');
   cout<< mass[i]<<endl;
    }
 }
 for (int i=1;i<strings;i++)
 {   
        APL[i].Team = strtok(mass[i],",");
        cout<<APL[i].Team<<endl;   
 }
 

 fs.close();
 return 0;
  }
}