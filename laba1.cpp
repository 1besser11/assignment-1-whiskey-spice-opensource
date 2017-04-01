/*
 *
 * by Andrey and Slavick
 *
 */
#include <iostream>
#include <fstream>
//#include <math.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
struct Team
{
    string name;
    string result;
    int point;
};
int  input_count();
void sort(Team * ,int);
Team* input(int);
void out(Team * ptr, int a);
int main(int argc, char *argv[])
{
	int count = input_count();
    Team * ptr = input(count);
    sort(ptr, count);
	out(ptr, count);
    return 0;
}

int input_count()
{
    int lines = 0;
    char s;
    FILE *fp = fopen("premier_league.csv","r");
    while((s=fgetc(fp))!=EOF)
    {
        if(s == '\n')
        lines++;
    }



    //cout << lines;
    fclose(fp);
    return lines;
    
}

/*int input_count()
{
	ifstream fin("premier_league.csv");
    int a;
    fin >> a;
	return a;
}*/

Team* input(int count)
{
    ifstream f("premier_league.csv");
    int a;
    char  b;
    f >> a;f >>b;
    Team *ptr = new Team[a];

    for(int i = 0; i < count; ++i)
    {
        ptr[i].point = 0;
        getline(f,ptr[i].name, ',');
        getline(f,ptr[i].result, '\n');
    }
    return ptr;
}

void sort(Team * ptr,int a)
{
    int match = 10;
    for(int i = 0; i < a; ++i)
    {
        for(int j = 0; j < 40 ; j += 4)
        {
            if((int)ptr[i].result[j] > (int)ptr[i].result[j+2])
                ptr[i].point += 3;
            else if((int)ptr[i].result[j] == (int)ptr[i].result[j+2])
                ++ptr[i].point;


        }
       // cout << ptr[i].name << "  " <<ptr[i].point << endl;
    }
    for(int i = 0 ; i < a -1 ; i++ )
    {
        for( int j = 0; j < a-i-1; j++)
        {
            if( ptr[j].point < ptr[j+1].point)
            {
                Team temp = ptr[j+1];
                ptr[j+1] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
    for (int i = 0; i < a; i++)
     {
	 	 cout << ptr[i].name << "  " <<ptr[i].point << endl;
 	}
 }
 
 void out(Team * ptr, int a)
 {
	ofstream fout;
    fout.open("results.csv", ios_base::out);
    for (int g = 0; g < a; g++)
     {
	 	fout << ptr[g].name << "," <<ptr[g].point << endl;
 	 }
	fout.close();
}

