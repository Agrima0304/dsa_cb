/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

   class Pair{
       public:
       int max_sum;
       int branch_sum;
       Pair()
       {
           max_sum=-1000;
           branch_sum=-1000;
       }
   };
   Pair maxSumP(TreeNode* root)
   {
       Pair p;
       if(root==NULL)
       {
           return p;
       }
       Pair lefti=maxSumP(root->left);
       Pair righti=maxSumP(root->right);
       int op1=root->val;
       int op2=lefti.branch_sum+root->val;
       int op3=righti.branch_sum+root->val;
       int op4=lefti.branch_sum+root->val+righti.branch_sum;
       int ans_curr=max(op1,max(op2,max(op3,op4)));
       p.branch_sum=max(lefti.branch_sum,max(righti.branch_sum,0))+root->val;
       p.max_sum=max(lefti.max_sum,max(righti.max_sum,ans_curr));
       return p;

   }
    int maxPathSum(TreeNode* root) {
         if(root==NULL)
         {
             return 0;
         }
         if(root&&!root->left&&!root->right)
         {
             return root->val;
         }  
        
        
         Pair ans=maxSumP(root);
         return ans.max_sum;
    }
};
