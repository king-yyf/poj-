
#include <iostream>
#include<cstdio>
#include<cstring>
#define max 30
using namespace std;
struct Btree{
	char data;
	struct Btree *lchild;
	struct Btree *rchild;
};
Btree *root;
char pre[max],in[max];
void postorder(Btree* root){
	if(root!=NULL){
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%c",root->data);
	}
}
void Buitree( Btree *& T, const char *s1, const char *s2, int len)
{
  if (len<=0){
    T = NULL;
    return;
  }else {
      T = new Btree;
      T->data = *s1;
      int i;
      for(i = 0; i < len; i++){
        if(s2[i] == *s1) break;
      }
      Buitree(T->lchild,s1+1, s2, i);
      Buitree(T->rchild,s1+i+1, s2+i+1, len - (i + 1));
  }
}
int main()
{
	while(cin >> pre >> in){
        Buitree(root,pre, in, strlen(pre));
        postorder(root);
        cout << endl;
    }
	return 0;
}
