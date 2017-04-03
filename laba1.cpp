#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cassert>

using namespace std;

struct Team
{
    string name;
    string result;
    int point;
};
void Delete_Empty_Line ();
int  input_count();
void sort(Team * ,int);
Team* input(int);
void out(Team * ptr, int count);
int main(int argc, char *argv[])
{
    Delete_Empty_Line ();
	int count = input_count();
    Team * ptr = input(count);
    sort(ptr, count);
	out(ptr, count);
    return 0;
    
}
void Delete_Empty_Line (void)
{
    ifstream FileInput ("premier_league.csv", ifstream::in);
    ofstream FileOutput ("premier_league1.csv", ofstream::out);
    assert(FileInput);
    assert(FileOutput);
 
    string String_Of_File;
    while (FileInput)
    {
        getline(FileInput, String_Of_File);
        if (!String_Of_File.empty())
        {
            FileOutput << String_Of_File;
            FileOutput << endl;
        }   
    }
    FileInput.close();
    FileOutput.close();
}

int input_count()
{
    int lines = 0;
    char s;
    FILE *fp = fopen("premier_league1.csv","r");
    while((s=getc(fp))!=EOF)
    {        
        if(s == '\n')
        lines++;
    }
    fclose(fp);
    return lines;    
}

Team* input(int count)
{
    ifstream f("premier_league1.csv");
    int* a = new int ;
    char*  b = new char ;
    f >> *a;f >>*b;
    Team *ptr = new Team[count];

    for(int i = 0; i < count; ++i)
    {
    
        ptr[i].point = 0;
        getline(f,ptr[i].name, ',');
        getline(f,ptr[i].result, '\n');
        
    }
    delete a; delete b;
    return ptr;
}

void sort(Team * ptr,int count)
{
    int match = 10;
    for(int i = 0; i < count; ++i)
    {
        for(int j = 0; j < 40 ; j += 4)
        {
            if((int)ptr[i].result[j] > (int)ptr[i].result[j+2])
                ptr[i].point += 3;
            else if((int)ptr[i].result[j] == (int)ptr[i].result[j+2])
                ++ptr[i].point;
        }
       
    }
    for(int i = 0 ; i < count -1 ; i++ )
    {
        for( int j = 0; j < count-i-1; j++)
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
 
 void out(Team * ptr, int count)
 {
	ofstream fout;
    fout.open("results.csv", ios_base::out);
    for (int g = 0; g < count; g++)
     {
     	fout << ptr[g].name << "," <<ptr[g].point << endl;
 	 }
	fout.close();
}

