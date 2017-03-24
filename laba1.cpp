#include <iostream>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
const int len = 60 , strings = 20;

const char eol = '\n';
char mass[len][strings];

ifstream fs("/home/slavick/Рабочий стол/Labs/premier_league.csv",ios:: in|ios:: binary);
if(!fs)
 {
 fprintf(stderr, "File premier_league.csv was not opened \n");
 return 1;
 
 }
for(int i=0; i<strings;i++)
{

fs.getline(mass[i], len -1, eol);
cout<< mass[i]<<endl;
}

for(int j=0;j<strings;j++)
{
    for(int k=0;k < len;k++)
    {
     if (mass[k]!= "\n")
     
     
     else break;
    }
    cout<<endl;

}

fs.close();
return 0;

}