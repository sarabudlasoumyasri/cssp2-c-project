#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <dirent.h>
# include "finger.h"
int hash1[100]={0};
int hash2[100]={0};
int cmp_file(char *file_name)                         //this function  explain the only takeing the txtfiles
{
    char *cmpr = (char *) malloc(sizeof(char) * 3);
    cmpr = "txt";
    char *ret;
    int a;
    ret = strstr(file_name,cmpr);         //// first occurrence of the string in a given string. 
    if(ret == NULL)
    {
        ret="file cannot be open";
    }
    a=strcmp(ret,cmpr);
    return a;
}

void percent_commonhash(int hash1[100], int arraylen1, int hash2[100], int arraylen2) //in this function calculate the per cent
{
	int i,j,e=0;
	float percent=0;
	for(i=0;i<arraylen1;i++)
	{
		for(j=0;j<arraylen2;j++)
		{
			if(hash1[i]==hash2[j])
			{
				e=e+1;
			}
		}
	}
	//printf("e=%d\n",e);
	percent=(float)(2*e)/(arraylen1+arraylen2);
	printf("%10.2f",percent*100 );

}
void main(int argc,char *argv[]){        //implementing the command line arguments
    DIR *d;                                   // take the directory
    struct dirent *dir;
    char *re[100];
    d = opendir(argv[1]);                // opens the directory
    int i=0;
    char** Filen=(char**)malloc(sizeof(char*)*100);
    while ((dir = readdir(d)) != NULL){                        //read the files
        if(strlen(dir->d_name)>2){
            int a = cmp_file(dir->d_name);       //call the file_cmp function
                if(a==0)                                    // if txt files then copy the in Filen[i]
                {
                    Filen[i]=malloc(strlen(dir->d_name));
                    strcpy(Filen[i],dir->d_name);
                    i=i+1;
                }   
        }
            
    }
     for(int y=0;y<i;y++){                  //it is use for matrix display txt names
        printf("     ");
        printf("%8s",Filen[y] );
     }
  
    int k=0,r=0;
     float e[i][i];
     for(int t=0;t<i;t++){
        printf("\n%8s",Filen[t] );
         for(int n=0;n<i;n++){
            if(Filen[t]!=Filen[n]){    // take the two different files
            	char f1[100][100]={'\0'};
				char f2[100][100]={'\0'};
				int len1=store_kgram(Filen[t],f1);          // it is call the store _kgram function
				int len2=store_kgram(Filen[n],f2);
	//printf("%d/n",len1);
				int arraylen1=remove_spaces(f1,len1,hash1);  // it is call the remove_space function
				int arraylen2=remove_spaces(f2,len2,hash2);
				percent_commonhash(hash1,arraylen1,hash2,arraylen2);  //it is call the percent_commonhash function
				}
				else{
					float e=0.00;            // if  two files  empty then print zero
				printf("%10.2f");     // print the percent of files
				}
			}
			//printf("\n");
		}
	}
