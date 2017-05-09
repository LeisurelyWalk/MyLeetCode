#include<iostream>
#include<vector>
#include<set>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution {
public:
	TreeNode* buildNode(TreeNode*root)
	{
		if (root == NULL)
			return NULL;
		TreeNode* newRoot = new TreeNode(root->val);
		newRoot->right = buildNode(root->right);
		newRoot->left = buildNode(root->left);
		return newRoot;
	}
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*>nodes;
		TreeNode* h1 = new TreeNode(1);
		nodes.push_back(h1);
		int i = 2;
		while (i <= n)
		{
			vector<TreeNode*>temp;
			for (int j = 0; j < nodes.size(); j++)
			{
				TreeNode*cur = new TreeNode(i);
				cur->left = buildNode(nodes[j]);
				temp.push_back(cur);
			}
			for (int j = 0; j < nodes.size(); j++)
			{
				set<int>s;
				while (1)
				{
					TreeNode*head = buildNode(nodes[j]);
					temp.push_back(head);
					TreeNode*cn = head;
					while (s.find(cn->val) != s.end())
					{
						cn = cn->right;
						if (cn == NULL)
							break;
					}
					if (s.find(cn->val) == s.end() && cn->right == NULL)
					{
						cn->right = new TreeNode(i);
						s.insert(cn->val);
						break;
					}
					else
					{
						TreeNode* tp = cn->right;
						cn->right = new TreeNode(i);
						cn->right->left = tp;
						s.insert(cn->val);
					}
				}
			}
			nodes.clear();
			nodes = temp;
			i++;
		}
		return nodes;
	}
};
int main()
{
	Solution s0;
	vector<TreeNode*> res = s0.generateTrees(3);

	return 0;
}
