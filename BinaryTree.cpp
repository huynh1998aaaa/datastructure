#include<iostream>
#include<queue>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int a)
    {
        val= a;
        left = nullptr;
        right= nullptr;
    }
};
class Tree{
    private:
    TreeNode* root;
    TreeNode* _AddVal(TreeNode* root1, int n)
    {
        if (root1 == nullptr)
        {
            TreeNode* cur = new TreeNode(n);
			//cout<<cur->val<<endl;
            return cur;
        }
        else
        {
            TreeNode* temp;
            if (root1-> val < n)
            {
                temp = _AddVal(root1->right, n);
                //cout<<temp->val<<endl;
                root1->right = temp;
				
            }
            else
            {
                temp= _AddVal(root1->left, n);
                //cout<<temp->val<<endl;
                root1->left= temp;
            }
			return root1;

        }
    }
    void _PreOrder(TreeNode* root1)
    {
        if(root1== nullptr)
        return;
        else
        {
            cout<<root1->val<<endl;
            _PreOrder(root1->left);
            _PreOrder(root1->right);
        }
    }
	void _PostOrder(TreeNode* root1)
	{
		if(root1==nullptr)
		return;
		else
		{
			_PostOrder(root1->left);
			_PostOrder(root1->right);
			cout<<root1->val;
		}
	}

	void _InOrder(TreeNode* root1)
	{
		
		if (root1== nullptr) {
			/* code */
			return ;
		}
		else
		{
			_InOrder(root1->left);
			cout<<root1->val<<" ";
			_InOrder(root1->right);
		}
		
	}

    void _LevelOrder(TreeNode* root1)
    {
        if(root == nullptr)
        return;
        else
        {
            queue<TreeNode*> q;
            q.push(root1);
            while(!q.empty()){
                TreeNode* temp = q.front();
                q.pop();
                cout<<temp->val<<" ";
                
                if (temp->left!= nullptr) {
                    q.push(temp->left);
                }
                
                if (temp->right!=nullptr) {
                    q.push(temp->right);
                }
                
                
            }
            

        }
    }
    int _TreeHeight(TreeNode* root1)
    {
        if(root1 == nullptr)
        return -1;
        else
        {
            int leftHeight = _TreeHeight(root1->left);
            int rightHeight = _TreeHeight(root1->right);
            int max1 = max(leftHeight,rightHeight);
            return max1+1;    

        }
    }
    public:
    Tree()
    {
        root= nullptr;
    }
    void AddVal(int n)
    {
        root = _AddVal(root,n);
    }
    void PreOrder()     //in tien to
    {
        _PreOrder(root);
		//cout<< root->val;
    }
	void PostOrder()	//in hau to
	{
		_PostOrder(root);
	}

	void InOrder()      //in trung to
	{
		_InOrder(root);
	}

    void LevelOrder()   //in theo level
    {
        _LevelOrder(root);
    }

    int TreeHeight()
    {
        return _TreeHeight(root);
    }

    void AddFullTree(int a) // cay day du la cay co chieu sau khoang cach bang 1
    {
        
        if (root == nullptr) {
           root = new TreeNode(a);
        }
        else
        {
            queue<TreeNode*> q;
            q.push(this->root);
            
            while(!q.empty()){
                TreeNode* temp = q.front();
                if(temp->left == nullptr)
                {
                    temp-> left = new TreeNode(a);
                    return;
                }
                else
                    q.push(temp->left);
                
                if (temp ->right == nullptr) {
                    temp->right = new TreeNode(a);
                    return;
                }
                else
                    q.push(temp -> right);
                
                q.pop();
            }
            
        }
        
    }

    void AddChanLe(int a)
    {
        
        if (this->root == nullptr) {
            root = new TreeNode(a);
            return;
        }
        else
        {
        queue<TreeNode*> q;
        q.push(root);
            
            while(!q.empty())
            {
                TreeNode* temp = q.front();
                if (temp->left== nullptr && a%2==0) {
                    temp->left = new TreeNode(a);
                    return;
                }
                else
                q.push(temp->left);

                
                if (temp->right == nullptr && a%2!=0) {
                    temp->right = new TreeNode(a);
                    return;
                }
                else
                q.push(temp->right);
                q.pop();
         }
         }
    }
    
};

int main(int argc, char const *argv[])
{
    Tree myTree;
    int n, val;
    cout<<"Nhap n : ";
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>> val;
        myTree.AddChanLe(val);
    }
    //myTree.InOrder();
	//myTree.PreOrder();
    myTree.PostOrder();
    //myTree.LevelOrder();
    cout<<endl<<myTree.TreeHeight();
	return 0;
}
