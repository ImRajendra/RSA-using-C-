#include<fstream>
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
void encrypt()
{
	ofstream fout;
	ofstream file;
	string str;
    long int pt, ct, key = 3, k,n;
    n=53*59;
	char ch;
    Enter:cout<<"Enter file name\n";
    cin>>str;
    ifstream fin(string(str+".txt").c_str());
    if(!fin)
    {
    	cout<<"File not found enter valid file name\n";
    	goto Enter;
	}
    fout.open("sample.txt");
    file.open(string(str+"key.txt").c_str());
    while (!fin.eof())
    {
        fin.get(ch);
        if(ch==' ')
        {
        	fout<<1;
        	continue;
		}
		pt=ch;
        pt = pt - 96;
        k = 1;
        for (int j = 0; j < key; j++){
            k = k * pt;
            k = k % n;
        }
        file<<k<<"\t";
        ct = k + 96;
        ch=ct;
        fout<<ch;
    }
    fin.close();
    fout.close();
    file.close();
    remove(string(str+".txt").c_str());
    rename("sample.txt",string(str+".txt").c_str());
    cout<<"THE FILE ECRYPTION IS SUCCESFULL\n";
}

void decrypt()
{
	ofstream fout;
	ifstream file;
	string str;
long int pt, ct, key = 2011, k,n;
char ch;
int c=0;
n=53*59;
    l1:cout<<"Enter file name\n";
    cin>>str;
    ifstream fin(string(str+".txt").c_str());
    if(!fin)
    {
    	cout<<"Enter a valid file\n";
    	goto l1;
	}
    fout.open("sample.txt");
    file.open(string(str+"key.txt").c_str());
    if(!file)
    {
    	cout<<"Decryption failed Key file not found\n";
    	return;
	}
    
    while (!fin.eof())
    {
    	fin.get(ch);
    	if(ch=='1')
		{
			fout<<" ";
			c=0;
			continue;
		}
		else{
		file>>ct;
        k = 1;
        for (int j = 0; j < key; j++)
        {
            k = k * ct;
            k = k % n;
        }
        ch= k + 96;
        fout<<ch;}
    }
    fin.close();
    fout.close();
    file.close();
    remove(string(str+".txt").c_str());
    rename("sample.txt",string(str+".txt").c_str());
    cout<<"THE FILE DECRYPTION IS SUCCESFULL\n";
    remove(string(str+"key.txt").c_str());
}

int main()
{
	int n;
	cout<<"\t\t________________________________\n";
	cout<<"\t\tRSA ALGORITHM IMPLEMENTATION\n";
	cout<<"\t\t---------------------------------\n";
	while(1){
	cout<<"Enter your option\n\t1.Encrypt\t2.Decrypt\t3.exit\n";
	cin>>n;
	switch(n)
	{
		case 1:encrypt();
		break;
		case 2:cout<<"Note:Key file must exist for decryption\n";
				decrypt();
				break;
		case 3:exit(0);
		break;
		default:
		cout<<"ENter valaid\n";	
	}
}
}
