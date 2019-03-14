int store_kgram(char fn[50], char f[100][100])             // in this function calculate the  length of files

{
	FILE *fp;
	fp=fopen(fn,"r");
	char c;
	int i=0,j=0;
	while(1)
	{
		c=fgetc(fp);
		//printf("%c",c);

		int ascii=(int)(c);         
		if(c==EOF)
		
			break;
		
		else if(c==' '|| c=='\n')           
		{
			f[i][j]='\0';
			i++;
			j=0;
			
		}
		if((ascii>=65 && ascii <=90) || (ascii>=97 && ascii<=122))
		{
		f[i][j]=c;
		strlwr(f[i]);            //convert the lowercase 
		j++;

		

		}

	}
	int len=i+1;
	
	fclose(fp);
	return len;
}
int remove_spaces(char f[100][100],int len,int hash[100])     //in this remove the spaces and  calculate the sum  of the  words and calculate array length
{
	char a[500]={'\0'};
	int i=0,j,p=0,q,r,x,y;
	char rd[100][100]={'\0'};
 	//hash[100]={0};
 	int arraylen=0;
	while(i<len)
	{
		j=0;
		while(f[i][j]!='\0')
		{
			a[p]=f[i][j];
			p++;
			j++;
		}
		i++;		
	}
	//printf("%s",a);
	//printf("%d",strlen(a));
	int k=5;
	for(i=0;i<strlen(a)-9;i++)
	{
		p=0;
		y=i;
		while(p<k){         //then divide the words with k=5;
			rd[i][p]=a[y];
			p++;
			y++;
		}
		//printf("%s/n",rd[i]);
		//printf("%c/n",a[i]);

	}
	long long s;
	int g=0;
	for(q=0;q<i;q++)
	{
		s=0;
		g=0;
		//printf("%s/n",rd[q]);
		for(r=0;r<strlen(rd[q]);r++)     
		{
			s+=(rd[q][r]*pow(k,k-(r+1))); //calculate the sum of words 
			g=s%10007;
			//printf("%llu/n",s);
			hash[q]=g;



		}
		//printf("%d\n",hash[q]);
		
	}
	arraylen=q;
	//printf("%d/n",arraylen);
	return arraylen;
	
}