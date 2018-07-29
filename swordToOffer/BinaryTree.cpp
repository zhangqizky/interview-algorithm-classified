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
    TreeNode*t=root;
    while(t!=nullptr||!s.empty())
    {
        while(t!=nullptr)
        {
            res.push_back(t->val);
            s.push(t);
            t=t->left;
        }
        if(!s.empty())
        {
            t=s.top();
            s.pop();
            t=t->right;
        }
    }
}
void inOrder(TreeNode*root,vector<int>&res)
{
    if(root==nullptr)
        return;
    stack<TreeNode*>s;
    TreeNode*t=root;
    while(t!=nullptr||!s.empty())
    {
        while(t!=nullptr)
        {
            s.push(t);
            t=t->left;
        }
        if(!s.empty())
        {
            t=s.top();
            res.push_back(t->val);
            s.pop();
            t=t->right;
        }
    }
}


/*
@功能：判断一个二叉树是否是另一个二叉树的子树
@参数：输入为两个二叉树，输出为true or false
*/
class Solution {
public:
    bool isEqual(TreeNode*root1,TreeNode*root2)
    {
        if(root2==nullptr) return true;
        if(root1==nullptr) return false;
        if(root1->val==root2->val)
        {
            return isEqual(root1->left,root2->left)&&isEqual(root1->right,root2->right);
        }
        return false;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1==nullptr||pRoot2==nullptr)
        return false;
        if(isEqual(pRoot1,pRoot2))return true;
        return HasSubtree(pRoot1->left,pRoot2)||HasSubtree(pRoot1->right,pRoot2);
    }
};

/*
@功能：求一个二叉树的镜像
@参数：输入为一个二叉树，输出为其镜像
*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot==nullptr)
        return;
        if(pRoot->left==nullptr&&pRoot->right==nullptr)
        return;
        TreeNode*temp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=temp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};
/*
@功能：从上往下打印二叉树，从左往右打印同一层节点
*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int>res;
        if(root==nullptr)
        {
            return res;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode*temp=q.front();
            res.push_back(temp->val);
            q.pop();
            if(temp->left!=nullptr)
            {
                q.push(temp->left);
            }
            if(temp->right!=nullptr)
            {
                q.push(temp->right);
            }
        }
        return res;
    }
};
/*
@功能：判断一个序列是否为二叉搜索树的后序遍历序列
*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size()==0)
        return false;
        int s=0,e=sequence.size()-1;
        return help(sequence,s,e);
    }
    bool help(vector<int>sequence,int s,int e)
    {
        if(s>e)
            return false;
        int root=sequence[e];
        int i;
        for(i=s;i<e;i++)
        {
            if(sequence[i]>root)
                break;
        }
        int j=i;
        for(;j<e;j++)
        {
            if(sequence[j]<root)
            return false;
        }
        bool left=true,right=true;
        if(s<i-1)
        {
            left=help(sequence,s,i-1);
        }
        if(i<e-1)
        {
            right=help(sequence,i,e-1);
        }
        return left&&right;
    }
};
/*
@功能：从一个二叉树的前序和中序遍历序列重建该二叉树
*/
class Solution {
public:
    int find(vector<int>data,int key)
    {
        if(data.size()<=0)
        return -1;
        for(size_t i=0;i<data.size();i++)
        {
            if(data[i]==key)
            return i;
        }
        return -1;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin)
    {
        if(pre.size()==0||vin.size()==0)
        return nullptr;
        int ps=0,pe=pre.size()-1,vs=0,ve=vin.size()-1;
        return construct(pre,ps,pe,vin,vs,ve);
    }
    TreeNode*construct(vector<int>pre,int ps,int pe,vector<int>vin,int vs,int ve)
    {
        if(vs>ve)
        return nullptr;
        TreeNode*root=new TreeNode(pre[ps]);
        int index=find(vin,pre[ps]);
        int offset=index-vs;
        root->left=construct(pre,ps+1,ps+offset,vin,vs,index-1);
        root->right=construct(pre,ps+offset+1,pe,vin,index+1,ve);
        return root;
    }
};
/*
@功能：返回二叉树中和为某一值的所有路径
*/
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>>res;
        if(root==nullptr)
        return res;
        vector<int>temp;
        int cur=0;
        help(root,cur,temp,res,expectNumber);
        return res;
    }
    void help(TreeNode*root,int cur,vector<int>temp,vector<vector<int>>&res,int e)
    {
        cur+=root->val;
        temp.push_back(root->val);
        bool isleaf=(root->left==nullptr)&&(root->right==nullptr);
        if(cur==e&&isleaf)
        {
            res.push_back(temp);
            return;
        }
        if(root->left)
        {
            help(root->left,cur,temp,res,e);
        }
        if(root->right)
        {
            help(root->right,cur,temp,res,e);
        }
    }
};
/*
@功能：二叉树的深度
*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==nullptr)
        return 0;
        int left=TreeDepth(pRoot->left);
        int right=TreeDepth(pRoot->right);
        return left>right?left+1:right+1;
    }
};
/*
@是否为平衡二叉树
*/


