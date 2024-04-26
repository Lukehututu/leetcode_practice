#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    
};



int DFS(struct TreeNode* root, int sum)
{
    if (root == NULL && sum == 0)//当没有子树且sum为0时 此时算找到了路径
        return 1;
    else if (root == NULL && sum != 0)
        return 0;
    else if (root != NULL && sum == 0)
        return 0;
    else if (root != NULL && sum != 0)//继续向下遍历
    {
        sum -= root->val;
        return DFS(root->left, sum) + DFS(root->right, sum);
    }
    return 0;
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL)
        return false;
    if (root->val == targetSum && root->left != NULL || root->right != NULL)
    {
        return false;
    }
    //深度算法
    //DFS
    int ret = DFS(root, targetSum);
    if (ret)//只要找到一条路径DFS就大于0
        return true;
    else
        return false;
}

int main()
{

    TreeNode* root = new(TreeNode);
    root->val = 5;
    TreeNode* vl = new(TreeNode);
    TreeNode* vr = new(TreeNode);
    vl->val = 4;
    vr->val = 8;
    root->left = vl;
    root->right = vr;
    TreeNode* ele = new(TreeNode);
    TreeNode* sev = new(TreeNode);
    TreeNode* two = new(TreeNode);
    TreeNode* thir = new(TreeNode);
    TreeNode* four = new(TreeNode);
    TreeNode* one = new(TreeNode);
    vl->left = ele;
    vl->right = NULL;
    ele->left = sev;
    ele->right = two;
    vr->left = thir;
    vr->right = four;
    four->right = one;
    sev->left = NULL;
    sev->right = NULL;
    two->left = NULL;
    two->right = NULL;
    thir->left = NULL;
    thir->right = NULL;
    four->left = NULL;
    one->left = NULL;
    one->right = NULL;
    vl->right = NULL;
    cout<<hasPathSum(root, 22)<<endl;

}


