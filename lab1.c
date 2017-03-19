#include <stdio.h>
#include <iostream>
#include <iomanip>
#include<string.h>

#define LEN 100

using namespace std;

int main ()
{
//work with fopen, fclose

  char Writed_str[] = {"\nThis is a string was created by Slavick!:)"}; 
  char str[LEN];
  FILE *file_ptr;
  file_ptr = fopen("new_file.txt", "r+a") ;
 // r,   w,    a,      r+, w+, a+,  rb,          wb
 //read, write, +text,    ,   ,   , read binary, write binary


  if(file_ptr!= NULL)
  {
     printf("File new_file.txt was succesfully created\n");    
    fputs(Writed_str,file_ptr);

     while(fgets(str, LEN, file_ptr))
     fprintf(stdout, "%s\n", str);
   }
   else
   {
     fprintf(stderr, "File new_file.txt was not opened or created\n");
     return 1;
   }

}         