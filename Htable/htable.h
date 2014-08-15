#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;
template <class T>

class htable
{
private:
	vector<vector < pair<string, T> > > vec;
	int size;
	int Hfunc(string key)
	{
		int h = 0;
		for (int i = 0; i < key.length(); ++i)
		{
			h = (h * 150 + key[i]) % (size-1);
		}
		return h;
	}

	int find(string element)
	{
		int i = 0;
		int h = Hfunc(element);
		for (i = 0; i < vec[h].size(); ++i)
		{
			if (vec[h][i].first == element)
			{
				return h;
			}
		}
		throw exception("there isn't your element to find");
	}

public:
	htable(int n)
	{
		size = n;
		vec.resize(size);
	}

	void insert(pair<string, T> element)
	{
		vec[Hfunc(element.first)].push_back(element);
	}

	bool check_pair(pair<string, T> element)
	{
		int i = 0;
		int h = Hfunc(element.first);
		for ( i = 0; i < vec[h].size(); ++i)
		{
			if (vec[h][i] == element)
			{
				return true;
			}
		}
		return false;
	}
	bool check_name(string element)
	{
		int i = 0;
		int h = Hfunc(element);
		for (i = 0; i < vec[h].size(); ++i)
		{
			if (vec[h][i].first == element)
			{
				return true;
			}
		}
		return false;
	}
	void printElement(string element)
	{
		if (check_name(element))
		{
			int ind = find(element);
			for (int i = 0; i < vec[ind].size(); ++i)
			{
					cout << vec[ind][i].first << " " << vec[ind][i].second <<endl;
			}
		}
		else
			throw exception("there isn't your element to print");
	}
};