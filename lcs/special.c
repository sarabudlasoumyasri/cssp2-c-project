char* specialcharacter(char* s){        // this function explain the specialcharacter
    strlwr(s);
    int i=0,j=0;
    int a=strlen(s);
    char* data=(char*)malloc(sizeof(char)*1000);
    while(i!=a)
    {
        if(s[i]==32 || s[i]>=65 && s[i]<=90 || s[i]>=97 && s[i]<=122)
        {
            data[j]=s[i];
            j++;

        }
        i++;
    }
    data[i]='\0';
    //printf("%s\n", data);
    return data;
}
float Lcs(char*e,char*r){        // this function expain the large common string length
    int i=0,j=0,c=0;
    for(int i=0;i<strlen(e);i++){
        int x=i;
        int y=x;
        for(int j=0;j<strlen(r);j++){
            if(x<strlen(e)){
                if (e[x]==r[j]){
                    x+=1;
                    //printf("%c\n",s1[x] );
                    if((x-i)>c){
                        c=x-i;      // count the large word length
                        int k;
                        for( k=i;k<x;i++){
                            t[k]=e[x];               // display large word
                            //printf("%c",t[k]);
                        }
                        t[k]='\0';
                    }
                } 
                else{
                    x=y;
                }   
            }
        }
    } 
    return(c);
}   