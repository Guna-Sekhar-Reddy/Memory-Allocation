//first_fit 

#include<iostream>

using namespace std;

struct first{
	int flag;
	int size;
	int psize;
};

int main()
{
	int n,m,s,j,sum=0,temp,id,tot=0;
	cout<<"Enter number of processes"<<endl;
	cin>>n;
	cout<<"Enter size of memory"<<endl;
	cin>>m;
	
	cout<<"Enter the number of segments u wnat to split"<<endl;
	cin>>s;
	
	struct first sf[s];
	
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
	
	
	for(int t=0;t<n;t++){
	
	
		for(int i=0;i<s;i++)
		{
	
			if(sf[i].flag==1 && sf[i].size>=arr[t])
			{
				sf[i].flag=0;
				sf[i].psize=arr[t];
				tot=tot+sf[i].size-arr[t];
				cout<<"internal fragmentation after the process "<<t<<" allocation is "<<sf[i].size-arr[t]<<endl;
				break;
				
			}
			
			if(i==s-1)
			{
				cout<<"process "<<t<<" is not able to allocated"<<endl;
			}
			
		}
	}
	cout<<"total fragmentation is "<<tot<<endl;
	
}

