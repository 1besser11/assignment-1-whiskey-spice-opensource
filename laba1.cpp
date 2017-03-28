/*
 *
 * by Andrey and Slavick
 *
*/
#include <iostream>
#include<fstream>

using namespace std;
struct Team
{
    string name;
    string result;
    int point;
};
int  input_count();
void sort(Team * ,int);
Team* input();
void out(Team * ptr, int a);
int main(int argc, char *argv[])
{
	int count = input_count();
    Team * ptr = input();
    sort(ptr, count);
	out(ptr, count);
    return 0;
}

int input_count()
{
	ifstream fin("premier_league.csv");
    int a;
    fin >> a;
	return a;
}

Team* input()
{
    ifstream fin("premier_league.csv");
    int a;char c;
    fin >> a; fin>>c ;
    Team *ptr = new Team[a];
    for(int i = 0; i < a; ++i)
    {
        getline(fin,ptr[i].name, ',');
        getline(fin,ptr[i].result, '\n');
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
            if((int)ptr[i].result[j] == (int)ptr[i].result[j+2])
                ++ptr[i].point;           

        }
        
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
    
 }
 
 void out(Team * ptr, int a)
 {
      for (int i = 0; i < a; i++)
     {
	 	 cout << ptr[i].name << "  " <<ptr[i].point << endl;
 	}
	ofstream fout;
    fout.open("results.csv", ios_base::out);
    for (int g = 0; g < a; g++)
     {
	 	fout << ptr[g].name << "  " <<ptr[g].point << endl;
 	 }
	fout.close();
}
