#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
using namespace std;
int main()
{
	int a[]={10, 10, 15, 20, 30, 30, 30, 30, 20, 10, 10};
	int size=11;
	vector<int> v(a, a+11);
	vector<int>::const_iterator i;
	//cout<<v.size()<<endl;
	vector<int> histogramContainer;
	histogramContainer.resize(3,0);
	//*************Histogram
	for(i=v.begin();i!=v.end();i++)
	{
		if(*i>=0 && *i<=12)
			{histogramContainer[0]++;}
		if(*i>=13 && *i<=24)
			{histogramContainer[1]++;}
		if(*i>=25 && *i<=36)
			{histogramContainer[2]++;}
	}
	for(int j=0;j<3;j++)
	{
		cout<<histogramContainer[j]<<"\t";
	}
	//*************Thresholding
	vector<int> threshold;
	int x=0;
	cout<<"\nThreshold:"<<endl;
	for(i=v.begin();i!=v.end();i++)
	{
		if(*i>=22)
			threshold.push_back(1);
		else
			threshold.push_back(0);

		cout<<threshold[x]<<"\t";
		x++;
	}
	vector<int> morph;
	morph.resize(3,1);
	//*************Erosion
	vector<int> erosion;
	erosion.reserve(11);
	cout<<"\nerosion:"<<endl;
	for(int m=0;m<size;m++)
	{
		
		{if(m==0 || m==size-1)
		{erosion[m]=threshold[m];}
		else
			if(threshold[m-1]==morph[0] && threshold[m]==morph[1] && threshold[m+1]==morph[2])
				erosion[m]=threshold[m];
			else
				erosion.push_back(0);
		}

		cout<<erosion[m]<<"\t";
	}
	//*************Dialation
	vector<int> dialate;
	dialate.reserve(11);
	cout<<"\nDialation:"<<endl;
	for(int m=0;m<size;m++)
	{
		if(m==0 )
					{dialate[m-1]=threshold[m-1];}	
		else{
			if(threshold[m]==morph[1])
			{
				dialate[m]=1;
				dialate[m-1]=1;
				dialate[m+1]=1;
			}

			else
			{
				if(dialate[m]!=1)
				dialate[m]=threshold[m];
			}
		}
	}
	for(int m=0;m<size;m++)
	{
		cout<<dialate[m]<<"\t";
	}
	//*********Convolution
	vector<int> conv(11);
	int avg;
	cout<<"Convolution:"<<endl;
	for(int m=0;m<11;m++)
	{
		if(m==0 || m==10)
		{
			conv[m]=v[m];
		}
		else
		{
			avg=(v[m-1]+v[m]+v[m+1])/3;
			conv[m]=avg;
		}
		cout<<conv[m]<<"\t";
	}
	
	}
