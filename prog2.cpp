#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
unsigned long long int l,dsum=0,d=1;
int t,i,j,k,scount=0,flag=0;
char s[100],swpchr;
int totaldamage(char *str)
{
	d=1;dsum=0;
	for(j=0;j<strlen(str);j++)
	{
		if(s[j]=='S')
			dsum+=d;
		else
			d=d*2;
	}
}
int countshoot()
{
	scount=0;
	for(int m=0;m<strlen(s);m++)
	{
		if(s[m]=='S')
			scount++;
	}
}
int main()
{
	int swap;
	cin>>t;
	for(i=0;i<t;i++)
	{
		swap=-1;
		d=1; dsum=0;
		cin>>l;
		cin>>s;
		totaldamage(s);
		countshoot();
		if(scount>l)
		{
			flag=1;
			goto finalkhatam;
		}
		flag=0;
		if(dsum<=l)
		{
			swap=0;
			goto finalkhatam;
		}
		swap=0;
		while(dsum>l)
		{
			for(k=(strlen(s)-1);k>0;k--)
			{
				//cout<<k;
				if(s[k]=='S' && s[k-1]=='C')
				{
					swpchr=s[k];
					s[k]=s[k-1];
					s[k-1]=swpchr;
					//cout<<s<<" ";
					swap++;
					goto khatam;
				}
				else
					continue;
			}
			khatam:
			totaldamage(s);
		}
		finalkhatam:
		if(flag==0)
			cout<<"Case #"<<i+1<<": "<<swap<<endl;
		else
			cout<<"Case #"<<i+1<<": IMPOSSIBLE"<<endl;
	
	}
	return 0;
}