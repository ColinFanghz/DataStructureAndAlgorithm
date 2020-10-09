#include <iostream>
#include <string>

using namespace std;

// Get the next array
int* getNext(string p)
{
	int* next = new int[p.length()];
	next[0] = -1;                     //while the first char not match, i++,j++
	int j = 0;
	int k = -1;

	while (j < (int)p.length() - 1)
	{
		if (k == -1 || p[j] == p[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}

	return next;
}

int KMP(string T, string p)
{
	int i=0;
	int j=0;
	int* next=getNext(T);
	while (i < (int)T.length() && j < (int)p.length())
	{
		if (j == -1 || T[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j=next[j];
		}
	}
	if (j == (int)p.length())
	{
		return i-j;
	}
	return -1;
}


int main()
{
	string S = "ColinFang is a idiot";
	string T = "Fang";

	cout<<KMP(S,T)<<endl;

	return 0;
}
