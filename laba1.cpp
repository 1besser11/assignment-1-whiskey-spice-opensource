/*
 *
 * by Andrey and Slavick
 *
*/
#include <iostream>
#include <fstream>

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
    int a;
    char c;
    fin >> a; fin>>c;
    Team *ptr = new Team[a];
    for(int i = 0; i < a; ++i)
    {
<<<<<<< HEAD
        getline(fin,ptr[i].name, ',');
        getline(fin,ptr[i].result, '\n');
    }
    return ptr;
}

void sort(Team * ptr,int a)
{
    int match = 10;
    for(int i = 0; i < a; ++i)
=======
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
>>>>>>> 1012a8a0d0a89370d66243ee55ae1d7960b490d6
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

   // cout<<a<<ptr[1].name<<"\n\n";
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