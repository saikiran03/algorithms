#include <bits/stdc++.h>
using namespace std;

template <class T>
struct node{
	T v;
	node* right;
	node* left;
	
	node(){
		left = NULL;
		right = NULL;
	}
	
	node(T x){
		v = x;
		left = NULL;
		right = NULL;
	}
};

template <class T>
class BST{
	private:
		node<T>* root;
		
		void Insert(T x, node<T>* h){
			if(h->v > x){
				if(h->left == NULL)
					h->left = new node<T>(x);
				else
					Insert(x, h->left);
			}
			else{
				if(h->right == NULL)
					h->right = new node<T>(x);
				else
					Insert(x, h->right);
			}
			return;
		}
		
		
		node<T>* Search(T x, node<T>* h){
			if(h==NULL)
				return h;
			else if(h->v == x)
				return h;
			else if(h->v > x)
				return Search(x, h->left);
			else
				return Search(x, h->right);
		}
		
		void traversal(int x, node<T>* h){
			if(h==NULL)
				return;
				
			if(x==0)
				cout << h->v << " ";
			
			traversal(x, h->left);
			
			if(x==1)
				cout << h->v << " ";
				
			traversal(x, h->right);
			
			if(x==2)
				cout << h->v << " ";
			
			return;
		}
		
	public:
	
		BST(){
			root = NULL;
		}
		
		bool isEmpty(){
			return root==NULL;
		}
		
		void insert(T x){
			if(root==NULL){
				root = new node<T>(x);
				return;
			}
			Insert(x, root);
		}
		
		node<T>* search(T x){
			return Search(x, root);
		}
		
		void preorder(){
			traversal(0, root);
			cout << endl;
		}
		
		void inorder(){
			traversal(1, root);
			cout << endl;
		}
		
		void postorder(){
			traversal(2, root);
			cout << endl;
		}
};

int main(){
	BST<int> t;
	
	for(int i=1; i<20; i++){
		t.insert(i*i - 20*i + 75);
	}
	
	t.preorder();
	t.postorder();
	t.inorder();
}
