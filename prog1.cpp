	#include <iostream>
	using namespace std;

	int main()
	{
		bool done = false;
		unsigned long long int n,l[1000000000];
		int t,i,j,k,m,temp,index=-1;
		cin>>t;
		for(i=0;i<t;i++)
		{
			cin>>n;
			if(n>2)
			{
				for(j=0;j<n;j++)
					cin>>l[j];
				while(!done)
				{
					done=true;
					for(k=0;k<(n-2);k++)
					{
						if(l[k]>l[k+2])
						{
							done=false;
							temp=l[k];
							l[k]=l[k+2];
							l[k+2]=temp;
						}
					}
				}
				index=-1;
				for(m=0;m<(n-1);m++)
				{
				if(l[m]>l[m+1])
					{
						index=m;
						break;
					}
				}
				// for(int o=0;o<n;o++)
					// cout<<l[o];
				if(index==-1)
					cout<<"Case #"<<i+1<<": OK"<<endl;
				else
					cout<<"Case #"<<i+1<<": "<<index<<endl;
			}
			done=false;
		}
		return 0;
	}