/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
vector<int> ans;
void printAtLevelK(TreeNode* root,int k)
{
   if(k<0||root==NULL)
   {
       return ;
   }
   if(k==0)
   {
    ans.push_back(root->val);
    return;
   }
   printAtLevelK(root->left,k-1);
   printAtLevelK(root->right,k-1);
   return;
}
int distanceKi(TreeNode* root,TreeNode* target,int k)
{// if the target node is not present in the tree
    if(root==NULL)
    {
        return -1;
    }
    //when target node found,return its distance from target node that is 0
    if(root==target)
    {
        printAtLevelK(target,k);
        return 0;
    }
   //now find the ancestors of target node in the left subtree and find their distance from target
   int dl=distanceKi(root->left,target,k);
   if(dl!=-1)
   {
       //to only take the ancestor node
       if(dl+1==k)
       {
           ans.push_back(root->val);
       }
       else
       {
           printAtLevelK(root->right,k-dl-2);
       }
       return dl+1;
   }
   //now check in the right subtree
     int dr=distanceKi(root->right,target,k);
   if(dr!=-1)
   {
       //to only take the ancestor node
       if(dr+1==k)
       {
           ans.push_back(root->val);
       }
       else
       {
           printAtLevelK(root->left,k-dr-2);
       }
       return dr+1;
   }
  return -1;
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            distanceKi(root,target,k);
            return ans;
    }
};
