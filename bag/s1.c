#include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <string.h>
#include <errno.h>
# include "bagofwords.h"      // inthis userdefined have dotfunction,word_freqfunction,denom function

// int dot(struct word words[100],struct word words1[100],int nword,int nword1);
//float denom(struct word words[100],struct word words1[100],int nword,int nword1);
float result(int s,float b);   // in this function  explain result
//int word_freq(const char* str, struct word words[]);
int cmp_file(char *file_name) // in this function cmpare the txt files
{
    char *cmpr = (char *) malloc(sizeof(char) * 3);
    cmpr = "txt";
    char *ret;
    int a;
    ret = strstr(file_name,cmpr);  // first occurrence of the string in a given string. 
    if(ret == NULL)
    {
        ret="file cannot be open";
    }
    a=strcmp(ret,cmpr);
    return a;
}
char* open_file(char* re){             // in this function explain fileopening the files
    char* ch1=(char*)malloc(sizeof(char)*1000);
    FILE *fptr1;
    fptr1=fopen(re,"r+");              
    if(fptr1==NULL)
        perror("no file");
    fscanf(fptr1,"%[^EOF]s",ch1);
    //printf("%s\n",ch1 ); 
    return ch1;
                
}

void main(int argc ,char *argv[]){                      //implementing the command line arguments
    DIR *d;           //directory of d
    struct dirent *dir;
    char *re[100];
    d = opendir(argv[1]); // open the directory 
    int i=0;
    char** Filen=(char**)malloc(sizeof(char*)*100);

    while ((dir = readdir(d)) != NULL){                  // read the files
        if(strlen(dir->d_name)>2){

            int a = cmp_file(dir->d_name); // call the function file_cmp 
                if(a==0)
                {
                    Filen[i]=malloc(strlen(dir->d_name));
                    strcpy(Filen[i],dir->d_name);
                    i=i+1;
                }   
        }
            
    }
    char *d1 = (char*)malloc(sizeof(char)*100); // take the two strings
    char *d2 = (char*)malloc(sizeof(char)*100);
    int nword=0; 
    int nword1=0;
    int dp;
    float vp;
     struct word words[100];            // take the struct  objects
     struct word words1[100];
    for(int za=0;za<i;za++)            // display the matrix usinf for loops and diaplsy the txt names
    {
      printf("        ");
      printf("    %5s",Filen[za] );
    }   
    printf("\n");
    for (int z = 0; z < i; z++)
    {
      printf("    %s  ",Filen[z] );
      for (int y = 0; y < i; y++) 
      {
        if(strcmp(Filen[z],Filen[y])!=0 )
        {

        d1 = open_file(Filen[z]);                // call the function open the files
        d2 = open_file(Filen[y]);
        nword=word_freq(d1,words);
        nword1=word_freq(d2,words1);       // call the function word_frwq  and take the count of each word
        dp=dot(words,words1,nword,nword1);  // call the dot functuion  and  take the result of numerator
        vp=denom(words,words1,nword,nword1);  //call the denom function and take the result of denomnerator
        result(dp,vp);
      }
      else
      {
        char* m="00.00";   // if files same then print the 0
        printf("%12s",m);
      }
      }
      printf("\n");
    }

  }


float result(int s,float b) // this function expalin the result 
{
float x=(s/b)*100;
printf("%12.2f",x);
}

