#include<iostream>
#include<vector>
#include <string>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		int N = s.size();
		int minid = 0;
		int maxlen = 1;
		for (int i = 0; i < N; i++)
		{
			if (N - i <= maxlen / 2)
				break;
			int j = i;
			int k = i;
			while (j < N - 1 && s[j] == s[j + 1])
				j++;
			while (k>0&&j<N-1&&s[k-1]==s[j+1])
			{
				k--;
				j++;
			}
			if (j - k + 1 > maxlen)
			{
				maxlen = j - k + 1;
				minid = k;
			}
		}
		return s.substr(minid, maxlen);
	}
		
};
int main()
{
	Solution so;
	string str = "babad";
	cout << so.longestPalindrome(str);

	return 0;
}
