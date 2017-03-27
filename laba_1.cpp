// Андрея
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct team{
    int points;
    char name[21];

};



int main()
{
    FILE *f = fopen("/home/slavick/Рабочий стол/Labs/premier_league.csv", "r");
    if (f==NULL)cout<<"error";
    char delim1 = ',';
    char delim2 = '\n';
    char match[3];
    int number = 0;
    char p;
    char score[3];
    while((p = fgetc(f))!=delim2 ) {
    }
    team *t = new team;
    int i = 0;
    while(p!=EOF){
        while((p=fgetc(f))!=delim1 && p!=EOF) 
        {
            t[number].name[i++]=p;
        }
        i = 0;

        t[number].points=0;
        int k1 = 0;
    for(int k=0;k<10;k++){
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
        
}



fclose(f);
int prpr = 4;
team temp;
for(int i = 0; i < 20;i++)
    {            
        for(int j = 0; j < 20; j++) 
        {     
            if (t[j + 1].points < t[j].points) 
            {
                temp = t[j + 1]; 
                t[j + 1] = t[j]; 
                t[j] = temp;
            }
        }
    }

    for(int i =20; i>0;i--)
    cout<<i<<t[i].name<<t[i].points<<endl;
int k = 0;

FILE *gg=fopen("//home/slavick/Рабочий стол/Labs/result.csv","w");
 for(int ii = 20, kk=0; ii>0;ii--,kk++){
fprintf(gg,"%i,%s,%i\n",kk+1, t[ii].name, t[ii].points);
}
fclose(gg);
system("pause");
}