#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
	set<string>se;
	vector<int> helper(string s, vector<string>& wordDict)
	{
		vector<int>res;
		for (int i = 0; i < wordDict.size(); i++)
		{
			string str = wordDict[i];
			int k = s.size() - 1;
			int m = str.size() - 1;
			while (s[k] == str[m])
			{
				k--;
				m--;
				if (k < 0 || m < 0)
					break;
			}
			if (k>=-1&&m<0)
				res.push_back(k + 1);
		}
		return res;
	}
	bool wordBreak(string s, vector<string>& wordDict) {
		int N = s.size();
		se.insert("");
		for (int i = 0; i < N; i++)
		{
			vector<int>vec = helper(s.substr(0, i + 1),wordDict);
			if (vec.size() != 0)
			{
				for (auto n : vec)
				{
					if (se.find(s.substr(0, n)) != se.end())
					{
						se.insert(s.substr(0, i + 1));
					}
				}
			}
		}
		return se.find(s) != se.end();
	}
};
int main()
{
	Solution s0;
	string str = "a";
	vector<string>wordD = { "a" };
	cout << s0.wordBreak(str, wordD);

	return 0;
}
