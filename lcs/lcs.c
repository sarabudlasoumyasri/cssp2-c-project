# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <string.h>
#include <errno.h>
# include "special.h" // this headerfile expalin the special characterfunction and lcs function 
int cmp_file(char *file_name)                         //this function  explain the only takeing the txtfiles
{
    char *cmpr = (char *) malloc(sizeof(char) * 3);
    cmpr = "txt";
    char *ret;
    int a;
    ret = strstr(file_name,cmpr);         //// first occurrence of the string in a given string. 
    if(ret == NULL)
    {
        ret="file can not be open";
    }
    a=strcmp(ret,cmpr);
    return a;
}
char* open_file(char* re){                       //this funtion explain the file opening
    char* ch1=(char*)malloc(sizeof(char)*1000);
    FILE *fptr1;
    fptr1=fopen(re,"r+");
    if(fptr1==NULL)
        perror("no file");
    fscanf(fptr1,"%[^EOF]s",ch1);
      return ch1;
                
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
        printf("         ");
        printf("%8s",Filen[y] );
     }
  
    int k=0,r=0;            
     float e[i][i];
     for(int t=0;t<i;t++){
        printf("\n%8s",Filen[t] );
         for(int n=0;n<i;n++){
            if(Filen[t]!=Filen[n]){                // if files different then enter in to condition
                char* ch1=(char*)malloc(sizeof(char)*100);           //take the two strings
                char* ch2=(char*)malloc(sizeof(char)*100);
                 ch1=open_file(Filen[t]);         //call the fileopen function
                 ch2=open_file(Filen[n]);  
                 //printf("%s\n",ch1 );
                 //printf("%s\n",ch2 );
                 char* n1=(char*)malloc(sizeof(char)*100);
                 char* n2=(char*)malloc(sizeof(char)*100);        // take the two strings
                 //char* w=(char*)malloc(sizeof(char)*100);
                 n1=specialcharacter(ch1);                //call the funtion specialchacter
                 n2=specialcharacter(ch2);
                 float w;
                 if(strlen(n1)>strlen(n2)){           //if file1> file2 then enter the loop
                     w=Lcs(n1,n2);           // then call the lcs function
                }
                else{
                     w=Lcs(n2,n1);
                }

                
                 //printf("lcs is %f\n",w );
                 float d=strlen(n1)+strlen(n2);      //calculate the length of two strings
                 //printf("length is %f\n",d );
                 float y=((2*w)/d)*100;                //calculate the percentage of two strings
                 //printf("%.2f\n",y );
                 e[t][n]=y;       // display in matrix
             }
            else{
                 e[t][n]=0;        //if two files same then display 0
            }
            printf("    %0.2f        ",e[t][n] );        // dispaly the answer in matrix
        }
        printf("\n");
    }
 }

