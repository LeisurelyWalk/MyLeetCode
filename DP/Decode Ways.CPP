#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	int numDecodings(string s) {
		if (s.empty())
			return 0;
		if (s.size() == 1 && s[0] == '0')
			return 0;
		else if (s.size() == 1)
			return 1;
		int N = s.size();
		vector<int>num(N + 1, 0);
		num[0] = 1;
		for (int i = 0; i < N; i++)
		{
			int k = i + 1;
			
			if (s[i] == '0')
				num[i] = 0;
			num[k] += num[k - 1];
			if (i == 0)
				continue;
			string str = s.substr(i - 1, 2);
			const char *ch = str.c_str();
			int temp = atoi(ch);
			if (temp <= 26&&temp>0)
				num[k] += num[k - 2];
		}
		return num[N];
	}
};
int main()
{
	Solution so;
	int res = so.numDecodings("100");


	return 0;
}
