//This is a cpp about all BinaryTree algorithms asked in an interview
/*
 @author:Zhang Qi
 @time:2018/07/28
*/

/*
@二叉树的前后中序非递归遍历实现
*/

void preOrder(TreeNode*root,vector<int>&res)
{
    if(root==nullptr)
        return;
    stack<TreeNode*>s;
    s.push(root);
    TreeNode*t=root;
    while(!s.empty())
    {
        while(t!=nullptr)
        {
            res.push_back(t->val);
            s.push(t);
        }
    }
}

