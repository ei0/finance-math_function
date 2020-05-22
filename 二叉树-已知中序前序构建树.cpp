/*
P31
通过前序和中序构造二叉树
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
	TreeNode* MyBulidTree(vector<int>& preorder, vector<int>& inorder, int pleft, int pright, int ileft, int iright) {
		if (pleft > pright) {
			return nullptr;
		}
		int Root_p = pleft;
		int Root_i = 0;
		for (int i = ileft; i <= iright; i++) {
			if (inorder[i] == preorder[Root_p]) {
				Root_i = i;
				break;
			}
		}
		TreeNode* root = new TreeNode(preorder[Root_p]);
		root->left = MyBulidTree(preorder, inorder, pleft + 1, pleft + Root_i - ileft, ileft, Root_i - 1);
		root->right = MyBulidTree(preorder, inorder, pleft + Root_i - ileft + 1, pright, Root_i + 1, iright);
		return root;

	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int len1 = preorder.size();
		int len2 = inorder.size();
		if (len1 != len2) {
			return nullptr;
		}
		else {
			return MyBulidTree(preorder, inorder, 0, len1 - 1, 0, len1 - 1);
		}
	}
};