struct word { // structure of string and count
char str[100];    
int count;        
}w;
int dot(struct word words[100],struct word words1[100],int nword,int nword1) // this function expalin the dot product of two files
{
int s=0;
int d=0;
for(int q=0;q<nword;q++)
{
  for(int j=0;j< nword1;j++)
   {
      if(strcmp(words[q].str,words1[j].str)==0)
      {
       s=s+words[q].count*words1[j].count;
      }
    }
}
return s;
}
float denom(struct word words[100],struct word words1[100],int nword,int nword1)  // this function expalin the denom of two files
{
 int h=0;
 int h1=0;
 for(int r=0;r<nword;r++)
 {
  h=h+pow(words[r].count,2);
 }
 for(int r1=0;r1<nword1;r1++)
 {
  h1=h1+pow(words1[r1].count,2);
 }
 float b=sqrt((h*h1));
 return b;
}

int word_freq(const char *str, struct word words[])  // this function expalin the word_freq 
{
char punct_str [] =" .,;/@#!&^(){}[]|""><?$*_-+=~`%':!?'\"\n\t";  // remove special character
char *tmp_str;  
char *wptr;     
int nword;       
int i;
nword = 0;
tmp_str = strdup(str);        // take duplicate  of the sting from another string
wptr = strtok(tmp_str, punct_str);   // split the words
while (wptr != NULL)
{
    for(i = 0; i < nword; i++)
    {

        if (strcmp(wptr, words[i].str) == 0) // compare the word and  structure word
            break; 
    }
        if (i < nword) 
            words[i] .count++;    
        else
        {            
        strcpy(words[nword].str, wptr); 
        words[nword].count= 1; 
        ++nword;    
        }
wptr = strtok(NULL, punct_str); 
}
return nword;
}