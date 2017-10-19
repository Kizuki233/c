在一个二维数组中，每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool flag=false;

         if(!array.empty()&&target!=NULL){
         int maxrow=array[0].size();
         int maxcol=array.size();
         int row=0;
         int col=maxcol-1;
          while(row<=maxrow-1&&col>=0){
             if(array[row][col]==target){
             	flag=true;
             	break;
             }
             else if(array[row][col]>target)
                 --col;
             else
                 ++row;
         }
         }  
        return flag;
    }
};


请实现一个函数，将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
class Solution {
public:
	void replaceSpace(char *str,int length) {
     
     if(str==NULL||length<=0)//输入判定
         return;
     int nowlen=0,newlen=0;
     int num;
     for(int i=0;str[i]!='\0';++i){
         ++nowlen;
         if(str[i]==' ')
          ++num;
     }//i控制循环 nowlen记录长度实现的是不同的功能
    newlen=nowlen+2*num;
    if(length<newlen)//边界判定
        return;

    while(nowlen>=0&&newlen>nowlen){
      if(str[nowlen]==' '){
        str[newlen--]='0';
        str[newlen--]='2';
        str[newlen--]='%';
      }
      else
      	str[newlen--]=str[nowlen];
       nowlen--;
    }
	}
};


输入一个链表，从尾到头打印链表每个节点的值。
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
     vector<int> value;
     std::stack<ListNode*> st; 

       while(head!=NULL){
           st.push(head);
           head=head->next;
       }
       while(!st.empty()){
         value.push_back(st.top()->val);
         st.pop();
       }
        return value;
  }
};


输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
     int size=pre.size();
     TreeNode* root=BinaryTree(pre,0,size-1,vin,0,size-1);
      return root;
    }
    
    TreeNode* BinaryTree(vector<int> pre,int presta,int preend,vector<int> vin,int vinsta,int vinend){
        if(presta>preend||vinsta>vinend)
            return NULL;
        
        TreeNode* root=new TreeNode(pre[presta]); 
        for(int i=vinsta;i<=vinend;++i){
           if(vin[i]==pre[presta]){
              root->left=BinaryTree(pre,presta+1,presta+i-vinsta,vin,vinsta,i-1);
              root->right=BinaryTree(pre,presta+i-vinsta+1,preend,vin,i+1,vinend);
           }           
        }
       return root;
    }
};


用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
class Solution
{
public:
    void push(int node) {
       stack1.push(node);
    }

    int pop() {
      if(stack1.empty()&&stack2.empty())
          return NULL;
      int temp;

      if(stack2.empty()){
         while(!stack1.empty()){
           stack2.push(stack1.top());
           stack1.pop();
         }
      }  
      temp=stack2.top();
      stack2.pop();
      return temp;
   }

private:
    stack<int> stack1;
    stack<int> stack2;
};


把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int size=rotateArray.size();
        if(size==0)
           return 0;
        int start=0,end=size-1,mid;
      
        while(end>start){
        if(end-start==1){
           mid=end;
            break;
        }           
        mid=(start+end)/2;
        if(rotateArray[start]<=rotateArray[mid]){
            start=mid;
        }
        else if(rotateArray[end]>=rotateArray[mid])
          end=mid;
       }
         return rotateArray[mid];
    }
};


大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39
class Solution {
public:
    int Fibonacci(int n) {
    if(n<=0)
      return 0;
    else if(n==1)
      return 1;
    int f0=0,f1=1,fn=0;
    for(int i=2;i<=n;++i){
       fn=f0+f1;
        f0=f1;
        f1=fn;
    }
        return fn;
    }
};


一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
class Solution {
public:
    int jumpFloor(int n) {
    if(n<=0)
      return 0;
    else if(n==1)
      return 1;
    else if(n==2)
      return 2;
    int f0=1,f1=2,fn=0;
    for(int i=3;i<=n;++i){
       fn=f0+f1;
        f0=f1;
        f1=fn;
    }
        return fn;    
    }
};


一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
class Solution {
public:
    int jumpFloorII(int n) {
      return  1<<--n; //左移x2
    }
};
//每个台阶都有跳与不跳两种情况（除了最后一个台阶），最后一个台阶必须跳。所以共用2^(n-1)中情况


我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
class Solution {
public:
    int rectCover(int n) {
     if(n<=2)
       return n;
    int f0=1,f1=2,fn=0;
    for(int i=3;i<=n;++i){
       fn=f0+f1;
        f0=f1;
        f1=fn;
    }
        return fn; 
    }
};


输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
class Solution {
public:
     int NumberOf1(int n) {
         int count=0;
         while(n!=0){
             ++count;
             n=n&(n-1);
         }   
         return count;
     }
};


给定一个double类型的浮点数base和int类型的整数exponent。
求base的exponent次方。
class Solution {
public:
    double Power(double base, int exponent) {
       double ans=1;
        if(exponent<0&&base!=0){
            base=1/base;
            exponent=-1*exponent;
        }
            
        for(int i=0;i<exponent;++i){
            ans*=base;
        }      
        return ans;
   }
};


输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        queue<int> q1,q2;
        for(int i:array){
           if(i%2==0)
             q2.push(i);
           else
             q1.push(i);
        }    
            array.clear();
            while(!q1.empty()){
               array.push_back(q1.front()); 
               q1.pop();
            }
            while(!q2.empty()){
               array.push_back(q2.front()); 
               q2.pop();
           }  
    }
};


输入一个链表，输出该链表中倒数第k个结点。
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(k<=0||pListHead==nullptr){
            return nullptr;
        }
        ListNode* head=pListHead;
        ListNode* tail=pListHead;
        for(int i=1;i<k;i++){
            if(tail->next)
                tail=tail->next;
            else
                return nullptr;
        }
        while(tail->next!=nullptr){
            tail=tail->next;
            head=head->next;
        }
        return head;
     
    }
};


输入一个链表，反转链表后，输出链表的所有元素。
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
      ListNode* prehead=nullptr;
      ListNode* node=pHead;
      ListNode* pre=nullptr;
      
        while(node!=nullptr){
            ListNode* pnext=node->next;
            if(node->next==nullptr)
              prehead=node;
            node->next=pre;
            pre=node;
            node=pnext;                   
        } 
        return prehead;
    }
};


输入两个单调递增的链表，输出两个链表合成后的链表，
当然我们需要合成后的链表满足单调不减规则。
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
      if(pHead1==nullptr)
         return pHead2;
      else if(pHead2==nullptr)
         return pHead1;
        
      ListNode* mergehead=nullptr;
      if(pHead1->val<pHead2->val){
          mergehead=pHead1;
          pHead1->next=Merge(pHead1->next,pHead2);
      }
      else{
          mergehead=pHead2;
          pHead2->next=Merge(pHead1,pHead2->next);
      }
        return mergehead;
    }
};


输入两棵二叉树A，B，判断B是不是A的子结构。
（ps：我们约定空树不是任意一个树的子结构）
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool IsSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
     if(pRoot2==nullptr)
     	return true;
     if(pRoot1==nullptr)
     	return false;
     if(pRoot1->val!=pRoot2->val)
     	return false;
     return IsSubtree(pRoot1->left,pRoot2->left)&&IsSubtree(pRoot1->right,pRoot2->right);
    }

    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
       bool ans=false;
       if(pRoot1!=nullptr&&pRoot2!=nullptr){
           if(pRoot1->val==pRoot2->val)
           	ans=IsSubtree(pRoot1,pRoot2);
           if(!ans)
           	ans=HasSubtree(pRoot1->left,pRoot2);
           if(!ans)
           	ans=HasSubtree(pRoot1->right,pRoot2);
       }
       return ans;
    }
};


操作给定的二叉树，将其变换为源二叉树的镜像。
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* temp=nullptr;
    void Mirror(TreeNode *pRoot) {     	
     if(pRoot==nullptr||(pRoot->left==nullptr&&pRoot->right==nullptr))
           return;
       temp=pRoot->left;
       pRoot->left=pRoot->right;
       pRoot->right=temp;

       if(pRoot->left)
       	 Mirror(pRoot->left);
       if(pRoot->right)
       	 Mirror(pRoot->right);
    }
};


输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix){
     vector<int> print;
       if(matrix.empty())
         return print;
     int row=matrix.size();
     int col=matrix[0].size();
     int startx=0,starty=0,endx=row-1,endy=col-1;
     while(endx>=startx&&endy>=starty){

        for(int i=starty;i<=endy;++i)
            print.push_back(matrix[startx][i]);
        for(int i=startx+1;i<=endx;++i)
            print.push_back(matrix[i][endy]);
        for(int i=endy-1;i>=starty&&startx<endx;--i)
            print.push_back(matrix[endx][i]);
        for(int i=endx-1;i>startx&&starty<endy;--i)
            print.push_back(matrix[i][starty]);
        ++startx;++starty;--endx;--endy;
    }
        return print;
    }
};


定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
#include <assert.h>
class Solution {
public:
    void push(int value) {
       data.push(value);
        if(temp.empty()||value<=temp.top())
            temp.push(value);
        else
            temp.push(temp.top());
    }
    void pop() {
       assert(data.size()>0&&temp.size()>0);
        data.pop();
        temp.pop();
    }
    int top() {
      assert(data.size()>0);
      return data.top();  
    }
    int min() {
      assert(data.size()>0&&temp.size()>0);
       return temp.top();
    }
private:
    stack<int> data,temp;
};


输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int pushsize=pushV.size(),popsize=popV.size();
        if(pushsize==0||popsize==0||pushsize!=popsize)
           return false;       
        vector<int> stack;
        int j=0;
        for(int i=0;i<pushsize;++i){
            stack.push_back(pushV[i]);
            while(j<popsize&&stack.back()==popV[j]){
              stack.pop_back(); 
               ++j;
            }
        }    
      return stack.empty();    
    }
};


从上往下打印出二叉树的每个节点，同层节点从左至右打印。
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
      vector<int> ans;
       if(root==nullptr)
         return ans;
      queue<TreeNode*> que;
      que.push(root);
      while(!que.empty()){
        root=que.front();
        que.pop();
        ans.push_back(root->val);
        if(root->left)
         que.push(root->left);
        if(root->right)
         que.push(root->right);  
      }
      return ans;     
    }
};


输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
左子树一定比右子树小，因此去掉根后，数字分为left，right两部分，right部分的
//最后一个数字是右子树的根他也比左子树所有值大，因此我们可以每次只看有子树是否符合条件
//非递归
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
     int size=sequence.size();
     if(size==NULL)
     	return false;
     int i=0;
     while(--size){
     	while(sequence[i]<sequence[size]) ++i;   	
     	while(sequence[i]>sequence[size]) ++i;
     	if(i<size)
          return false;
         i=0;
     }
          return true;
    }
};


输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
	void Dfsfind(TreeNode* root,int left){
        temp.push_back(root->val);
        if(left-root->val==0&&root->left==nullptr&&root->right==nullptr)
        	ans.push_back(temp);
        else{
           if(root->left!=nullptr)
           	  Dfsfind(root->left,left-root->val);
           if(root->right!=nullptr)
           	  Dfsfind(root->right,left-root->val);
        }
        temp.pop_back();
	}
	
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
      if(root!=nullptr)
      	Dfsfind(root,expectNumber);
      return ans; 
    }
private:
	vector<vector<int> > ans;
	vector<int> temp;
};


输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
       if(pHead==nullptr)
       	  return nullptr;
       	RandomListNode* cur=pHead;
       	while(cur!=nullptr){
       		RandomListNode* node=new RandomListNode(cur->label);
       		node->next=cur->next;
       		cur->next=node;
       		cur=node->next;
       	}
       	cur=pHead;
       	RandomListNode* p;
       	while(cur!=nullptr){
       		p=cur->next;
       	   if(cur->random!=nullptr)
       	   	  p->random=cur->random->next;
       	   	cur=p->next;
       	}
       	RandomListNode* pCloneHead=pHead->next;
       	RandomListNode *temp;
       	cur=pHead;
       	while(cur->next!=nullptr){
            temp=cur->next;
            cur->next=temp->next;
            cur=temp;
       	}
       	  return pCloneHead;
    }
};


输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==nullptr)
        	return nullptr;
        TreeNode* node=nullptr;
        ConvertCore(pRootOfTree,&node);//node为最后结点
        TreeNode* cur=node;
        while(cur->left!=nullptr&&cur!=nullptr)
        	cur=cur->left;
        return cur;
    }
    void ConvertCore(TreeNode* root,TreeNode** node){
    	TreeNode* cur=root;
    	if(cur->left!=nullptr)
    		ConvertCore(root->left,node);
    	cur->left=*node;
    	if(*node!=nullptr)
    		(*node)->right=cur;
    	*node=cur;
    	if(cur->right!=nullptr)
    		ConvertCore(root->right,node);
    }
};


输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

class Solution {
public:
     vector<string> Permutation(string str) {
        vector<string> answer;
        if(str.empty())
            return answer;        
        sort(str.begin(),str.end());
        do{
            answer.push_back(str);
        }
        while(next_permutation(str.begin(),str.end()));
        return answer;
}
};


数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
      int size=numbers.size();
      if(size==0)
      	return 0;
      int num=numbers[0];
      int count=1;
      for(int i=1;i<size;++i){
        if(numbers[i]==num)
        	++count;
        else
        	--count;
        if(count==0){
        	num=numbers[i];
        	count=1;
        }
     }

     count=0;
     for(int i=0;i<size;++i){
     	if(numbers[i]==num)
        	++count;
     }
      if(count*2>size)  
      	return num;
      else
      	return 0;      
    }
};


输入n个整数，找出其中最小的K个数。
例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
       vector<int> ans;
        if(input.size()==0||input.size()<k)
         return ans;
       sort(input.begin(),input.end());
       for(int i=0;i<k;++i)
         ans.push_back(input[i]);
        return ans;   
    }
};


HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,
当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
你会不会被他忽悠住？(子向量的长度至少是1)
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
     int size=array.size();
     if(size==0)
     	return 0;
     int max=array[0],sum=0;
     for(int i=0;i<size;++i){
        if(sum<=0)
        	sum=array[i];
        else
        	sum+=array[i];
       if(sum>max)
     	 max=sum;
     }
        return max;
   }
};


求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。
class Solution {
public:
	int Hasnum(int n){
     int num=0;
     while(n){
        if(n%10==1)
           ++num;
        n/=10;
     }
      return num;
	}
    int NumberOf1Between1AndN_Solution(int n)
    {
      if(n<=0)
       return 0;
        int number=0;
     for(int i=1;i<=n;++i){
        number+=Hasnum(i);
     }
       return number;  
    }
};


输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
// sort中的比较函数compare要声明为静态成员函数或全局函数，不能作为普通成员函数，否则会报错。
// 因为：非静态成员函数是依赖于具体对象的，而std::sort这类函数是全局的，因此无法再sort中调用非静态成员函数。
// 静态成员函数或者全局函数是不依赖于具体对象的, 可以独立访问，无须创建任何对象实例就可以访问。
// 同时静态成员函数不可以调用类的非静态成员。 
class Solution {
public:
	static bool cmp(const string &s1,const string &s2){
		return s1+s2<s2+s1;
	}//类里面就要用static 类的外面不用
    string PrintMinNumber(vector<int> numbers) {
        string ans;
        int size=numbers.size();
        if(size<=0)
        	return ans;
        vector<string> temp;
        for(int i=0;i<size;++i){
        	temp.push_back(std::to_string(numbers[i]));
           //std::to_string(int),sscanf(buf,"%d",number)
           // stringstream ss;
           // ss<<numbers[i];
           // string s = ss.str();

        }
        sort(temp.begin(),temp.end(),cmp);
        for(int i=0;i<size;++i){
        	ans+=temp[i];
        }
          return ans;
    }
};


把只包含因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
     if(index<7)
      return index;
     vector<int> ans(index);
     ans[0]=1;
     int num2=0,num3=0,num5=0;
     for(int i=1;i<index;++i){
     	ans[i]=min(ans[num2]*2,min(ans[num3]*3,ans[num5]*5));
     	if(ans[i]==ans[num2]*2) ++num2;
     	if(ans[i]==ans[num3]*3) ++num3;
     	if(ans[i]==ans[num5]*5) ++num5;
     }
       return ans[index-1];
    }
};


在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
      if(str.size()<=0)
      	return -1;
      int hash[256]={0};
      int i=0;
      while(str[i]!='\0'){
      	++hash[str[i]];
      	++i;
      }
      i=0;
      while(str[i]!='\0'){
      	if(hash[str[i]]==1)
      	   return i;
         ++i;
      }    
        return -1;
    }
};


在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 
即输出P%1000000007
class Solution {
public:
    long InversePairs(vector<int> data) {
        int size=data.size();
        if(size<=1)
          return size;
        vector<int> copy(data);
        return InversePairsCore(copy,data,0,size-1);
    }

    long InversePairsCore(vector<int>& data,vector<int>& copy,int begin,int end){
       if(begin==end) return 0;
       int mid=(begin+end)/2;
       long left=InversePairsCore(copy,data,begin,mid);
       long right=InversePairsCore(copy,data,mid+1,end);
       int i=mid,j=end,indexCopy=end;
       long cnt=0;
       while(i>=begin&&j>=mid+1){
       	if(data[i]>data[j]){
       		copy[indexCopy--]=data[i--];
       		cnt+=j-mid;
       	}
       	else{
       		copy[indexCopy--]=data[j--];
       	}
       }
       while(i>=begin){
       	copy[indexCopy--]=data[i--];
       }
       while(j>=mid+1){
       	copy[indexCopy--]=data[j--];
       }
       return (left+right+cnt)%1000000007;
    }
};


输入两个链表，找出它们的第一个公共结点。
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* p1=pHead1;
        ListNode* p2=pHead2;
        while(p1!=p2){
           p1=(p1==nullptr?pHead2:p1->next);
           p2=(p2==nullptr?pHead1:p2->next);
        }
        return p1;
    }
};


统计一个数字在排序数组中出现的次数。
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
       return count(data.begin(),data.end(),k);
    }//二分查找
};


输入一棵二叉树，求该树的深度。
从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，
最长路径的长度为树的深度。
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot){
      if(pRoot==nullptr)
      	return 0;
      return max(1+TreeDepth(pRoot->left),1+TreeDepth(pRoot->right));
    }
};


输入一棵二叉树，判断该二叉树是否是平衡二叉树。
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot,int& high) {
    	if(pRoot==nullptr){
    		high=0;
    		return true;
    	}
    	int left,right;
    	if(IsBalanced_Solution(pRoot->left,left)&&IsBalanced_Solution(pRoot->right,right)){
    	  int diff=left-right;
    	  if(diff>1||diff<-1)
    	  	return false;
    	  high=1+max(left,right);
          return true;
    	}0
        return false;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
    	int high;
    	return IsBalanced_Solution(pRoot,high);
    }
};

class Solution {
public:
    int IsBalanced(TreeNode* pRoot){
       if(pRoot==nullptr) return 0;
       int left=IsBalanced(pRoot->left);
       int right=IsBalanced(pRoot->right);
       return left>=0&&right>=0&&abs(left-right)<=1?1+max(left,right):-1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
       return IsBalanced(pRoot)>=0;
    }
};


一个整型数组里除了两个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。
//根据异或的结果1所在的最低位，把数字分成两半，每一半里都还有只出现一次的数据和成对出现的数据
//这样继续对每一半相异或则可以分别求出两个只出现一次的数字
class Solution {
public:
	bool Isbit(int n,int bit){
		n=n>>bit;
		return n&1;
	}
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
     if(data.size()<2)
     	return;
     int num=0,bit=0;
     for(int i=0;i<data.size();++i)
        num^=data[i];
     while((num&1)==0){
     	num=num>>1;
        ++bit;
     }
     *num1=*num2=0;
     for(int i=0;i<data.size();++i){
     	if(Isbit(data[i],bit))
     	   *num1^=data[i];
     	else
     	   *num2^=data[i];
     }
    }
};


小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? 
class Solution {
public:
    vector<vector<int>> FindContinuousSequence(int sum) {
       vector<vector<int>> ans;
       if(sum<3)
          return ans;
       vector<int> temp;
       int small=1,big=2;
       int add=small+big;
       int mid=(1+sum)>>1;
       while(small<mid){
         while(add>sum){
         	add-=small;
         	++small;
         }
         if(add==sum){
         	for(int j=small;j<=big;++j)
               temp.push_back(j);
            if(temp.size()>1)
               ans.push_back(temp);
            temp.clear();
         }
         ++big;    //遍历右移是必须的
         add+=big;
       }
        return ans;
    }
};


输入一个递增排序的数组和一个数字S，在数组中查找两个数，
是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> ans;
        int size=array.size();
        if(size==0)
           return ans;
       int small=0;
       int big=size-1;
       int add;
       while(small<big){   //两边相乘的成绩最小，左右遍历
          add=array[small]+array[big];
       	if(add==sum){
       	   ans.push_back(array[small]);
       	   ans.push_back(array[big]);
       	   break;
       	}
       	else if(add<sum)
       	   ++small;
        else
           --big;
    }
        return ans;
   }
};


汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，
就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
是不是很简单？OK，搞定它！
class Solution {
public:
    string LeftRotateString(string str, int n) {
      int size=str.size();
      if(size==0)
      	return "";
      n=n%size;
      str+=str;
      return str.substr(n,size);  //字符字串函数
    }
};


牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。
后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
class Solution {
public:
    string ReverseSentence(string str) {
    int size=str.size();
      if(size==0)
      	return "";
     string ans="",temp="";
     for(int i=0;i<size;++i){
     	if(str[i]==' '){
     	   ans=' '+temp+ans;
  		   temp="";
     	}
     	else
     	 temp+=str[i];
     }
     if(temp.size()!=0)
     	ans=temp+ans;
     return ans;
    }
};


LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！
“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,
决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。
上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。
LL决定去买体育彩票啦。 
现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何。
为了方便起见,你可以认为大小王是0。
class Solution {
public:
    //学习前辈们的代码
    //记录最大最小值,当max-min<5时候返回真
    bool IsContinuous( vector<int> numbers ){
      if(numbers.empty())
      	return false;
      bool count[14]={false};
      int max=-1,min=14;
      for(int i=0;i<numbers.size();++i){
      	 if(numbers[i]==0)  
            continue; 
      	 if(count[numbers[i]]==true)//对子
         	return false;
         count[numbers[i]]=true;
         if(numbers[i]>max)
         	 max=numbers[i];
         if(numbers[i]<min)
         	 min=numbers[i];
      }
      if(max-min<5)
      	return true;
      return false;
    }
};


每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
HF作为牛客的资深元老,自然也准备了一些小游戏。
其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。
然后,他随机指定一个数m,让编号为0的小朋友开始报数。
每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,
并且不再回到圈中,从他的下一个小朋友开始,
继续0...m-1报数....这样下去....直到剩下最后一个小朋友,可以不用表演,
并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
       if(n<1||m<1)
       	  return -1;
       else if(n==1)
       	  return 0;
       // else  return (LastRemaining_Solution(n-1,m)+m)%n;
       int last=0;
       for(int i=2;i<=n;++i)
       	 last=(last+m)%i;
       return last;
    }
};


求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
class Solution {
public:
    int Sum_Solution(int n) {
      int ans=n;
      n&&(ans+=Sum_Solution(n-1));
       return ans;
    }
};


写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
class Solution {
public:
    int Add(int num1, int num2)
    {
      if(num1&num2) 
         return Add((num1&num2)<<1,num1^num2); //递归进位加没有进位
      else
         return num1^num2; //没有进位
    }
};


将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
数值为0或者字符串不是一个合法的数值则返回0
class Solution {
public:
    int StrToInt(string str) {
     if(str.size()==0)
      	return 0;
     int ans=0;
     int e=1;
     if(str[0]=='-')
     	e=-1;

     for(int i=(str[0]=='+'||str[0]=='-')?1:0;i<str.size();++i){
          if(str[i]>='9'||str[i]<='0')
           	 return 0;
           ans=ans*10+str[i]-'0';
       }
        return ans*e;
   }
};


在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
public class Solution {
    // Parameters:
    //    numbers:     an array of integers
    //    length:      the length of array numbers
    //    duplication: (Output) the duplicated number in the array number,length of duplication array is 1,so using duplication[0] = ? in implementation;
    //                  Here duplication like pointor in C/C++, duplication[0] equal *duplication in C/C++
    //    这里要特别注意~返回任意重复的一个，赋值duplication[0]
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    public boolean duplicate(int numbers[], int length, int[] duplication) {
        boolean[] k=new boolean[length];
        for (int i=0;i<k.length;i++) {
            if (k[numbers[i]]==true) {
                duplication[0]=numbers[i];
                return true;
            }
            k[numbers[i]] = true;
        }
        return false;
}
}


给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
//画矩阵图
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
    int size=A.size();
    vector<int> B(size,1);
    if(size>0){
     for(int i=1;i<size;++i)
       B[i]=B[i-1]*A[i-1];
     int temp=1;
     for(int i=size-2;i>=0;--i){
    	temp*=A[i+1];
    	B[i]*=temp;
     }
    }
     return B;
   }
};


请实现一个函数用来匹配包括'.'和'*'的正则表达式。
模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
class Solution {
public:
    bool match(char* str, char* pattern){   
        if(str==nullptr||pattern==nullptr)
       	  return false;
       	if(*str=='\0'&&*pattern=='\0')
       	  return true;
       	if(*str!='\0'&&*pattern=='\0')
       	  return false;
       	if(*(pattern+1)=='*'){
       	   if(*str==*pattern||(*pattern=='.'&&*str!='\0'))
       	   	 return match(str+1,pattern)||match(str,pattern+2)||match(str+1,pattern+2);
       	   	else 
       	   	 return match(str,pattern+2);
       	}
       	if(*str==*pattern||(*pattern=='.'&&*str!='\0'))
       		return match(str+1,pattern+1);
       	return false;
    }
};


请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
class Solution {
public:
    bool isNumeric(char* string){
        if(string==nullptr)
        	return false;
        int len=strlen(string);
        int dotNum=0,eNum=0,nNum=0,i=0;
        if(string[0]=='+'||string[0]=='-')   ++i;
           while(i<len){
           	 if(string[i]>='0'&&string[i]<='9'){
           	 	++i;
           	 	nNum=1;
           	 }
           	 else if(string[i]=='.'){
           	 	if(eNum>0||dotNum>0)
           	 		return false;
           	 	++i;
           	 	++dotNum;
           	 }
           	 else if(string[i]=='e'||string[i]=='E'){
           	 	if(eNum>0||nNum==0)
           	 		return false;
           	 	++i; 
           	 	++eNum;
           	 	if(string[i]=='\0')
           	 		return false;
           	 	if(string[i]=='+'||string[i]=='-') ++i;
           	 }
           	 else
           	 	return false;
           }       
             return true;
    }
};


请实现一个函数用来找出字符流中第一个只出现一次的字符。
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符"google"时，第一个只出现一次的字符是"l"。
//哈希表加队列
class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
       ++c[ch-'\0'];
       if(c[ch-'\0']==1)
         data.push(ch-'\0');   
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while(!data.empty()&&c[data.front()]>1)
        	 data.pop();
         if(data.empty())
            return '#';
         return data.front();
    }
    Solution(){
       memset(c,0,sizeof(unsigned int));
    }
private:
    queue<char> data;
    unsigned int c[128];
};


一个链表中包含环，请找出该链表的环的入口结点。
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
      ListNode* fast=pHead;
      ListNode* slow=pHead;
      do{
      	if(fast==nullptr||fast->next==nullptr)
      		return nullptr;
      	fast=fast->next->next;
      	slow=slow->next;
      }while(fast!=slow);
          
      slow=pHead;
      while(fast!=slow){
      	fast=fast->next;
      	slow=slow->next;
      }
         return slow;      
    }
};


在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
      if(pHead==nullptr||pHead->next==nullptr)
      	 return pHead;
      ListNode Myfirst(-1);
      Myfirst.next=pHead;
      ListNode* p=&Myfirst; //记录相同元素前面的指针
      ListNode* q=pHead;
      int val;
      while(q!=nullptr&&q->next!=nullptr){
         if(q->next->val==q->val){           
           val=q->val;
           while(q!=nullptr&&val==q->val)
           	 q=q->next;
           p->next=q;
         }
         else{
         	p=q;
         	q=q->next;
         }
      }
       return Myfirst.next;
    }
};


给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pHead)
    {
      if(pHead!=nullptr){
      	if(pHead->right){
      		pHead=pHead->right;
      		while(pHead->left){
      			pHead=pHead->left;
      		}
      		return pHead;
      	}
      	else{   //如果该节点是其父节点的左孩子,则返回父节点,否则继续向上遍历其父节点的父节点
      	    while(pHead->next){
      	    	if(pHead->next->left==pHead)
      	    		return pHead->next;
      	    	pHead=pHead->next;
      	    }
      	}
      }
         return nullptr;
    }
};


请实现一个函数，用来判断一颗二叉树是不是对称的。
注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
      if(pRoot==nullptr) 
        return true;
      return isduicheng(pRoot,pRoot);
    }
    bool isduicheng(TreeNode* pRoot1,TreeNode* pRoot2){
       if(pRoot1==nullptr&&pRoot2==nullptr)
       	 return true;
       else if(pRoot1==nullptr||pRoot2==nullptr)
       	 return false;
       if(pRoot1->val!=pRoot2->val)
       	 return false;					
       return isduicheng(pRoot1->left,pRoot2->right)&&isduicheng(pRoot1->right,pRoot2->left);
    }

};


请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* root) {
      vector<int> temp;
      vector<vector<int>> ans;
       if(root==nullptr)
         return ans;
      queue<TreeNode*> que;
      que.push(root);
      int i,size,high=0;
      while(!que.empty()){
        i=0;
        size=que.size();
        ++high;
        while(i++<size){
          root=que.front();
          que.pop();
          temp.push_back(root->val);
          if(root->left)
            que.push(root->left);
          if(root->right)
         	que.push(root->right);  
        }
        if(high%2==0)
        	reverse(temp.begin(),temp.end());
        ans.push_back(temp);
        temp.clear();
     }
      return ans;     
    }
};


从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* root) {
      vector<int> temp;
      vector<vector<int>> ans;
       if(root==nullptr)
         return ans;
      queue<TreeNode*> que;
      que.push(root);
      int i,size;
      while(!que.empty()){
        i=0;
        size=que.size();
        while(i++<size){
          root=que.front();
          que.pop();
          temp.push_back(root->val);
          if(root->left)
            que.push(root->left);
          if(root->right)
         	que.push(root->right);  
        }
        ans.push_back(temp);
        temp.clear();
     }
      return ans;     
    }
};


请实现两个函数，分别用来序列化和反序列化二叉树
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    char* Serialize(TreeNode *root) {    
        Node=root;
        return "hhh";
    }
    TreeNode* Deserialize(char *str) {
       return Node;
    }
private:
	TreeNode * Node;
};


给定一颗二叉搜索树，请找出其中的第k大的结点。
例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
	int count=0;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
      if(pRoot!=nullptr&&k>0){
         TreeNode* node=KthNode(pRoot->left,k);
         if(node!=nullptr) return node; //为了确保在找到(count == k)的时候能逐层返回
         if(++count==k) return pRoot;
         node=KthNode(pRoot->right,k);
         if(node!=nullptr) return node;
      } 
       return nullptr; 
    }
   
};


如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
//中位数 建立最大最小堆
class Solution {
public:
    void Insert(int num){
    	if(p.empty()||num<=p.top())  p.push(num);
    	else  q.push(num);
        if(p.size()+1==q.size()){
           p.push(q.top());
           q.pop();
    	}
    	if(p.size()==q.size()+2){
           q.push(p.top());
           p.pop();
    	}  	       
    }
    double GetMedian(){ 
       return p.size()==q.size()?(p.top()+q.top())/2.0:p.top();
    }
private:
	  priority_queue<int,vector<int>,less<int> > p;    //优先队列,最大堆 top()为最大值
    priority_queue<int,vector<int>,greater<int> > q; 
};


给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
 {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}，
  {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
  class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> ans;
        if(num.empty()||size>num.size())
        	return ans;
        deque<int> deq;
        for(int i=0;i<num.size();++i){
           while(!deq.empty()&&num[deq.back()]<=num[i]) //先pop 后push
           	  deq.pop_back();
            deq.push_back(i);
           	while(deq.front()+size<=i) //front()位置失效
           	  deq.pop_front();
           	if(i>=size-1) //开始记录
           		ans.push_back(num[deq.front()]);
        }
            return ans;
    }
};


请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str){
       if(matrix==nullptr||rows<1||cols<1||str==nullptr)
          return false;
       bool *visited=new bool[rows*cols]; 
       memset(visited,false,rows*cols);
       int len=0;
       for(int i=0;i<rows;++i){
       	  for(int j=0;j<cols;++j){
       	  	 if(hasPathCore(matrix,rows,cols,str,i,j,visited,len))
       	  	 	return true;
       	  }
       }
       delete [] visited;
       return false;
    }
    bool hasPathCore(char *matrix,int rows,int cols,char *str,int row,int col,bool *visited,int& len){
      if(str[len]=='\0')
      	return true;
      bool flag=false;
      if(row>=0&&col>=0&&row<rows&&col<cols&&matrix[row*cols+col]==str[len]&&!visited[row*cols+col]){
       ++len;
       visited[row*cols+col]=true;
       flag=hasPathCore(matrix,rows,cols,str,row+1,col,visited,len)
         ||hasPathCore(matrix,rows,cols,str,row-1,col,visited,len)
         ||hasPathCore(matrix,rows,cols,str,row,col+1,visited,len)
         ||hasPathCore(matrix,rows,cols,str,row,col-1,visited,len);
       if(!flag){
         --len;
         visited[row*cols+col]=false;
      }
    }
        return flag;
    }

};


地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。 
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        bool *visited=new bool[rows*cols];
        memset(visited,0,rows*cols);
        int count=movingCore(threshold,rows,cols,0,0,visited);
        delete[]visited;
        return count;
    }
    int movingCore(int threshold, int rows, int cols,int row,int col,bool *visited){
       int count=0;
       if(row>=0&&col>=0&&row<rows&&col<cols&&!visited[row*cols+col]
       	&&(getSum(row)+getSum(col))<=threshold){
       	  visited[row*cols+col]=true;
       	  count=1+movingCore(threshold,rows,cols,row+1,col,visited)
       	         +movingCore(threshold,rows,cols,row-1,col,visited)
       	         +movingCore(threshold,rows,cols,row,col-1,visited)
       	         +movingCore(threshold,rows,cols,row,col+1,visited);
       }
       return count; 
    }
    int getSum(int num){
      int sum=0;
      while(num){
      	sum+=num%10;
      	num/=10;
      }
       return sum;
    }
};




