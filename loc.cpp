//
//Program for calculating how many lines of code are within a file,
//not including spaces.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class LOC
{
	public:
	LOC(int x, string file);
	int method_count(int x, string file);
};


LOC::LOC(int x, string file)
{
	string line;
	int count = x;
	ifstream infile;
	infile.open(file.c_str());
	if(infile.fail())
	{
		cout<<"Cant access file..."<<endl;
	}
	istringstream line_string;
	getline(infile, line);
	
	while(!infile.eof())
	{
		LOC(x,file);
		count++;
		if(line.empty())
		{
			count--;
		}
		for(int i=0; i<5; i++)
		{
			if(line[i] == '/' and line[i+1] == '/')
			{
				count--;
			}
		}
		getline(infile,line);
	}
	infile.close();
	cout<<"LOC: "<<count<<endl;
}

int method_count::method_count(int x, string file)
{
	string line;
	int count = x;
	ifstream infile;
	infile.open(file.c_str());
	if(infile.fail())
	{
		cout<<"Cant access file..."<<endl;
	}
	istringstream line_string;
	getline(infile,line);
	while(!infile.eof())
	{
		for(int i=0; i<10; i++)
		{
			if(line[i] == ':' and line[i+1] == ':')
			count++;
			int bracket_count;
			while(bracket_count!=0)
			{
				bracket_count = 0;
				getline(infile,line);
				count++;
				if(line.empty())
				{
					count--;
				}
				for(i=0;i<10;i++)
				{
					if(line[i]=='/' and line[i+1]=='/')
					{
						count--;
					}
				}
				for(i=0;i<10;i++)
				{
					if(line[i]=='{')
					{
						bracket_count++;
					}
					else if(line[i]=='}')
					{
						bracket_count--;
					}
				}
				getline(infile,line);
			}
		}
	}
	infile.close();
	cout<<"Method count is: "<<count<<endl;
}

int main()
{
	string file;
	cout<<"Enter File Name: ";
	cin>>file;
	cout<<endl;
	method_count(0,file);
	LOC(0,file);
	return 0;
}
