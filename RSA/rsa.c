#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#define pb push_back
using namespace std;
bool checkprime(int a)
{
   if(a<=1){return false;}
   for(int i=2;i<sqrt(a);i++)
   {
   	if(a%i==0){return false;}
   }
   return true;
}
bool checkcoprime(int a,int b)
{
  if(__gcd(a,b)==1)return true;
  else return false;
}
string inttobinary(int a)
{
	string b="";
	while(a!=0)
	{
		if(a%2==1)b="1"+b;
		else b="0"+b;
		a/=2;
	}
	return b;
}
int numericciphertext(int m,int n,string s)
{
	int c=1;
	for(int i=0;i<s.size();i++)
	{
       c=(c*c)%n;
       if(s.at(i)=='1') c=(c*m)%n;
	}
	return c;
}

void rsa()
{
	int p,q;
	cout<<"Enter two different prime numbers: ";
	cin>>p>>q;
	while(!(checkprime(p)&&checkprime(q))||p==q)
	{
		cout<<"\ninvalid input!!please enter again :";
		cin>>p>>q;
	}
	int n=1;
	n=p*q;
	cout<<"n="<<n<<"\n";
	if(n<127){cout<<"\nError!! n should be greator than 127\n";exit(0);}
	int totient=1;
	totient=(p-1)*(q-1);
	cout<<"totient="<<totient<<"\n";
    int e;
    cout<<"Enter a number that is coprime with totient(make sure that it is different from above two prime numbers to make encryption better): ";
    cin>>e;
    while(!checkcoprime(e,totient))
    {
    	cout<<"\ninvalid input!!please enter again :";
    	cin>>e;
    }
    cout<<"public key components (n,e) are : "<<n<<" "<<e<<"\n";
    int k=1;
    while((1+k*totient)%e!=0){k++;}
    cout<<"k="<<k<<"\n";
    
    int d=(1+(k*totient))/e;
    cout<<"d="<<d<<"\n";
    cout<<"Private key components (d,n) are : "<<d<<" "<<n<<"\n";
    cout<<"Now Enter a message to encrypt: ";
    string message;
    cin.ignore();
    getline(cin,message);
    cout<<"\033c";
    cout<<"\nEncrypted message:";
    vector<int>v;
    for(int i=0;i<message.size();i++)
    {
    	int m=(int)message.at(i);
    	string s=inttobinary(e);
    	int z=numericciphertext(m,n,s);
    	v.pb(z);
    	cout<<z<<" ";
    }
    cout<<"\nEnter Private key to get decrypted message:";
    int d1,count=3;
    cin>>d1;
    while(d1!=d&&count>1)
    	{    count--;
    		cout<<"invalid key!! "<<count<<"tries left. Enter correct key:";
    		cin>>d1;
    	}
    	if(count==1)
    	{
    		exit(0);
    	}
    	else
    	{
    		int decry[v.size()];
           for(int i=0;i<v.size();i++)
           {
           	 int m=v.at(i);
           	 string s=inttobinary(d);
             decry[i]=numericciphertext(m,n,s);
           }
           cout<<"DECRYPTED MESSAGE IS : ";
           for(int i=0;i<v.size();i++)
           {
           	cout<<(char)decry[i];
           }

    	}
}
int loop()
{
	cout<<" \n\n         RSA MESSAGE ENCRYPTION AND DECRYPTION  \n";
   int x;
   cout<<"1.Start\n2.Exit\n";
   cin>>x;
   switch(x)
   {
   	case 1:
   	     rsa();
   	     break;
   	case 2:
   	     exit(0);
   	default:
   	     exit(0);         
   }
}
int main()
{
   
	while(1)
	{
		loop();
	}

}
