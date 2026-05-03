#include<stdlib.h>
#include<stdio.h>
unsigned int KMP(char* target,char* son)
{
	unsigned int i=0,//母串指针 
		j=0;//子串指针 
	while(son[j])
		j++;
	unsigned int *PM=(unsigned int*)malloc(j*sizeof(int));//部分匹配值数组
	unsigned int *next=(unsigned int*)malloc(j*sizeof(int));//KMP数组 
	if(PM==NULL||KMP==NULL)return 0; 
	PM[0]=0;
	unsigned int count=0;//最长公共前后缀 
	j=1;
	while(son[j])//计算部分匹配值 
	{
		if(son[count]==son[j])
		{
			count++;
			PM[j++]=count;
		}
		else if(count==0)
		{
			PM[j++]=count;
		}
		else 
		{
			count=PM[count-1];//部分匹配值回溯 
		}
	}
	next[0]=0;
	unsigned int k;
	for(k=1;k<j;k++)
		next[k]=PM[k-1];
	for(k=0;k<j;k++)
	printf("%d ",next[k]);
	printf("\n");
	for(k=1;k<j;k++)
	{
		
		if(son[k]==son[next[k]])
			while(son[k]==son[next[k]]&&next[k]!=0)
			{
				next[k]=next[next[k]];
			}
		
	}//next->nextval
	for(k=0;k<j;k++)
		printf("%d ",next[k]);
		printf("\n");
	j=0;
	while(target[i])
	{
		if(target[i]==son[j])
		{
			i++;
			j++;
		}
		else if(j==0)
		{
			i++;
		}
		else
		{
			j=next[j];
		}
		if(son[j]=='\0')return i-j+1;
	}
	return 0;
}

int main()
{
	char target[]="ABACBAABABAABCCBAABAAABCAC";
	char son[]="AAAB";
	
	printf("%d",KMP(target,son));
	return 0;
	
}






