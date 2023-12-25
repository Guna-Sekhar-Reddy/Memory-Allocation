// best fit

#include<iostream>

using namespace std;


struct best{
	int flag;
	int size;
	int psize;
};

int main()
{
	int n,m,s,j,sum=0,temp,id,swapped=0,count=0,k,tot=0;
	cout<<"Enter number of processes"<<endl;
	cin>>n;
	cout<<"Enter size of memory"<<endl;
	cin>>m;
	
	cout<<"Enter the number of segments u wnat to split"<<endl;
	cin>>s;
	
	struct best sf[s];
	
	cout<<"Enter the segment size"<<endl;
	for(int i=0;i<s;i++)
	{
		cin>>temp;
		sum=sum+temp;
		
		if(sum<=m)
		{
			sf[i].size=temp;
			//process continues
		}
		
		else
		{
			cout<<"memory size will be overloaded"<<endl;
			break;
		}
		j=i;
	}
	
	sf[j+1].size=m-(sum-temp);
	s=j+2;
	cout<<"s value "<<s<<endl;
	cout<<sf[j+1].size<<endl;

	cout<<"Enter flag bit for segment"<<endl;
	for(int i=0;i<s;i++)
	{
		cin>>sf[i].flag;							//flag->0 process is there; flag->1 process if not there
	}
	
	
	cout<<"Enter the process sizes"<<endl;
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	

	
	int old_min,new_min;
	for(int t=0;t<n;t++)
	{
	
		for(int a=0;a<s;a++)
		{
			if(sf[a].flag==1)
			{
				old_min=a;						//previous minimum
				
				break;
			}
		}

		new_min=-1;						//present minimum
		
		for(int i=0;i<s;i++)
		{
			if(sf[i].size>=arr[t]  && sf[i].flag==1)
			{
				
				if(sf[old_min].size>=sf[i].size || (sf[old_min].size<sf[i].size && sf[old_min].size<arr[t]))
				{
					new_min=i;
					old_min=new_min;
					//cout<<"new min in for condition is "<<new_min<<endl;
				}
				
			}
		}
		//cout<<"hello"<<endl;
	//	cout<<"new min is"<<sf[new_min].size<<endl;
		if(new_min==-1)
		{
			cout<<"the process is not allocated"<<endl;
		}
		else
		{
			sf[new_min].flag=0;
			cout<<"fragmentation of process "<<t<<" is "<<sf[new_min].size-arr[t]<<endl;
			tot=tot+sf[new_min].size-arr[t];
		}
	}
	
	cout<<"total fragmentation is "<<tot<<endl;
	
} 
