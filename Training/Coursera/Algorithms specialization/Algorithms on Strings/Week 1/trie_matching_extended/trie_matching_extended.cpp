#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters = 4;
int const NA = -1;

struct Node
{
	int next[Letters];
	bool patternEnd;

	Node()
	{
		fill(next, next + Letters, NA);
		patternEnd = false;
	}
};

int letterToIndex(char letter)
{
	switch (letter)
	{
	case 'A':
		return 0;
		break;
	case 'C':
		return 1;
		break;
	case 'G':
		return 2;
		break;
	case 'T':
		return 3;
		break;
	default:
		assert(false);
		return -1;
	}
}

vector<int> solve(string text, int n, vector<string> patterns)
{
	vector<int> result;

	// write your code here
	vector<Node> trie;
	trie.push_back(Node());
	for (auto x : patterns)
	{
		int node = 0;
		for (int i = 0; i < x.size(); i++)
		{
			if (trie[node].next[letterToIndex(x[i])] == NA)
			{
				trie[node].next[letterToIndex(x[i])] = trie.size();
				trie.push_back(Node());
			}
			node = trie[node].next[letterToIndex(x[i])];
		}
		trie[node].patternEnd = true;
	}

	for (int i = 0; i < text.size(); i++)
	{
		int node = 0;
		for (int j = i; j < text.size(); j++)
		{

			if (trie[node].next[letterToIndex(text[j])] != NA)
			{
				node = trie[node].next[letterToIndex(text[j])];
				if (trie[node].patternEnd)
				{
					result.push_back(i);
					break;
				}
			}
			else
			{
				break;
			}
		}
	}

	return result;
}

int main(void)
{
	string t;
	cin >> t;

	int n;
	cin >> n;

	vector<string> patterns(n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector<int> ans;
	ans = solve(t, n, patterns);

	for (int i = 0; i < (int)ans.size(); i++)
	{
		cout << ans[i];
		if (i + 1 < (int)ans.size())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}
