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
int  Input_Count();
void Sorting(Team * ,int);
Team* input();
void Output(Team * ptr, int a);
int main(int argc, char *argv[])
{
	int count = Input_Count();
    Team * ptr = input();
    Sorting(ptr, count);
	Output(ptr, count);
    return 0;
}

int Input_Count()
{
	ifstream Input_stream("premier_league.csv");
    int a;
    Input_stream >> a;
	return a;
}

Team* input()
{
    ifstream Input_stream("premier_league.csv");
    int a;char c;
    Input_stream >> a; Input_stream>>c ;
    Team *ptr = new Team[a];
    for(int i = 0; i < a; ++i)
    {
        getline(Input_stream,ptr[i].name, ',');
        getline(Input_stream,ptr[i].result, '\n');
    }
   
    return ptr;
}

void Sorting(Team * ptr,int a)
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
 
 void Output(Team * ptr, int a)
 {
    for (int i = 0; i < a; i++)
    {
	 	 cout << ptr[i].name << "  " <<ptr[i].point << endl;
 	}
	ofstream Output_Stream("results.csv", ios_base::out);
    for (int g = 0; g < a; g++)
     {
	 	Output_Stream << ptr[g].name << "  " <<ptr[g].point << endl;
 	 }
	Output_Stream.close();
}
