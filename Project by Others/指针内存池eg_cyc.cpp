// luogu-judger-enable-o2
// luogu-judger-enable-o2
#include <cstdio>
#include <vector>
using std::vector;

namespace Scapegoat_Tree {
    const int maxn = 100000 + 10;
    const double alpha = 0.75;    //旋转因子 
    struct Node {
        Node* ch[2];              //左右子节点 
        int key,siz,cover;        //key是值，siz是以该节点为根的树的存在的节点数，cover是所有节点数量 
        bool exist;               //exist标志该节点是否被删除 
        void pushup() {           //更新函数 
            this->siz=ch[0]->siz+ch[1]->siz+(int)exist;
            this->cover=ch[0]->cover+ch[1]->cover+1; 
        }
        int isbad() {             //判断是否要重构 
            return (ch[0]->cover>this->cover*alpha+5)||(ch[1]->cover>this->cover*alpha+5);
        }
    };
    struct STree {
        protected:
            Node mempol[maxn];           //内存池 
            Node *tail,*null,*root;      //tail为指向内存池元素的指针 
            Node *bc[maxn];              //内存回收池（栈） 
            int bc_top;                  //内存回收池（栈）顶指针 
            
            Node* newnode(int key) {
                Node* p=bc_top?bc[--bc_top]:tail++;
                p->ch[0]=p->ch[1]=null;
                p->cover=p->siz=p->exist=1;
                p->key=key;
                return p;
            }
            
            void travel(Node* p,vector<Node*>& x) {    //将一棵树转化成序列，保存在vector中 
                if(p==null) return;                    //如果是空树则退出 
                travel(p->ch[0],x);                    //递归操作左子树 
                if(p->exist) x.push_back(p);           //如果该节点存在则放入序列中 
                else bc[bc_top++]=p;                   //回收内存，将不用的节点扔到内存回收池（栈）中 
                travel(p->ch[1],x);                    //递归操作右子树 
            }
            
            Node* divide(vector<Node*>& x,int l,int r) {    //返回建好的树 
                if(l>=r) return null;                       //序列为空不用建树 
                int mid=(l+r)>>1;
                Node* p=x[mid];                             //mid保证平衡 
                p->ch[0]=divide(x,l,mid);                   //递归操作 
                p->ch[1]=divide(x,mid+1,r);                 //递归操作 
                p->pushup();                                //维护节点信息 
                return p; 
            }
            
            void rebuild(Node*& p) {
                static vector<Node*> v;
                v.clear();
                travel(p,v);                //拍扁 
                p=divide(v,0,v.size());     //建树 
            }
            
            Node** insert(Node*& p,int val) {                     //返回指向距离根节点最近的一棵不平衡的子树的指针 
                if(p==null) {
                    p=newnode(val);
                    return &null;
                } else {
                    p->siz++,p->cover++;                          //维护节点数 
                    Node** res=insert(p->ch[val>=p->key],val);
                    if(p->isbad()) res=&p;
                    return res;
                }
            }
            
            void erase(Node*& p,int k) {
                p->siz--;                               //维护siz 
                int offset=p->ch[0]->siz+p->exist;      //计算左子树的存在的节点总数 
                if(p->exist&&k==offset) {               //判断当前节点权值是否第k小 
                    p->exist=false;                     //删除节点 
                } else {
                    if(k<=offset) erase(p->ch[0],k);    //如果k小于等于offset，递归操作左子树 
                    else erase(p->ch[1],k-offset);      //反之递归操作右子树 
                }
            }
            
            void iod(Node* p) {
                if(p!=null) {
                    iod(p->ch[0]);
                    printf("%d ",p->key);
                    iod(p->ch[1]);
                }
            }
        public:
            void init() {
                tail=mempol;                         //tail指向内存池的第一个元素 
                null=tail++;                         //为null指针分配内存 
                null->ch[0]=null->ch[1]=null;        //null的两个儿子也是null 
                null->cover=null->siz=null->key=0;   //null的所有标记都是0 
                root=null;                           //初始化根节点 
                bc_top=0;                            //清空栈 
            }
            
            STree() {
                init();
            }
            
            void insert(int val) {
                Node** res=insert(root,val);
                if(*res!=null) rebuild(*res);
            }
            
            int rank(int val) {
                Node* now=root;
                int ans=1;
                while(now!=null) {
                    if(now->key>=val) now=now->ch[0];
                    else {
                        ans+=now->ch[0]->siz+now->exist;
                        now=now->ch[1]; 
                    }
                }
                return ans;
            }
            
            int kth(int val) {
                Node* now=root;
                while(now!=null) {
                    if(now->ch[0]->siz+1==val&&now->exist) return now->key;
                    else if(now->ch[0]->siz>=val) now=now->ch[0];
                    else val-=now->ch[0]->siz+now->exist,now=now->ch[1];
                }
            }
            
            void erase(int k) {              //删除值为k的元素 
                erase(root,rank(k));
                if(root->siz<root->cover*alpha) rebuild(root);
            }
            
            void erase_kth(int k) {          //删除第k小 
                erase(root,k);
                if(root->siz<root->cover*alpha) rebuild(root);
            }
            
            void iod() {                     //调试用的中序遍历 
                Node* p=root;
                iod(p);
            }
    };
}


template <class T> inline void read(T &x) {
    x = 0; int ch, f = 0;
    for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = 1;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    if (f) x = -x;
}

using namespace Scapegoat_Tree;
STree st; 
int main() {
    int n, opt, que;
    read(n);
    while(n--) {
        read(opt), read(que);
        if(opt==1) st.insert(que);
        if(opt==2) st.erase(que);
        if(opt==3) printf("%d\n",st.rank(que));
        if(opt==4) printf("%d\n",st.kth(que));
        if(opt==5) printf("%d\n",st.kth(st.rank(que)-1));
        if(opt==6) printf("%d\n",st.kth(st.rank(que+1)));
        if(opt==7) st.iod();
    }
    return 0;
}
