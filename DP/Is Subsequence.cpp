#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	bool isSubsequence(string s, string t) {
		int ns = s.size();
		int nt = t.size();
		if (ns == 0)
			return true;
		if (nt == 0)
			return false;
		int i, j = 0;
		for (i = 0; i < ns; i++)
		{
			for (; j < nt; j++)
			{
				if (s[i] == t[j])
				{
					j++;

					break;
				}
			}
			if (j == nt && (i != ns - 1 || i == 0))
				return false;
		}
		return true;

	}
};
int main()
{

	int i = 0;
	for (; i < 4; i++)
	{
		if (i == 2)
			break;
	}
	return 0;
}
