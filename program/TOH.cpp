#include<iostream>
using namespace std;

//tower of HANOI function implementation
int TOH(int n,char ini, char mid, char last)
{
	if(n==1)
	{
		cout<<"Move Disk "<<n<<" from "<<ini<<" to "<<last<<endl;
		return 0;
	}

	TOH(n-1,ini,last,mid);
	cout<<"Move Disk "<<n<<" from "<<ini<<" to "<<last<<endl;
	TOH(n-1,mid,ini,last);
	return 0;
}

//main program
int main()
{
	int n;
	cout<<"Enter no. of disks:";
	cin>>n;
	//calling the TOH
	TOH(n,'A','B','C');

	return 0;
}

// How to use recursion in stack?
