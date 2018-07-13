#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
        int val,id;
        friend bool operator< (node n1, node n2){
               return n1.val > n2.val;
        }
};
int flag[200005],ans1,ans2;
priority_queue<node> Q;
int main(){
    int i,n,v;
    char w;
    while(scanf("%d",&n)!=EOF){
          while(Q.size()) Q.pop();
          for(i=2;i<n;i++){
              getchar();
              scanf("%c %d",&w,&v);
              if(w=='d'){
                 node tmp;
                 tmp.id=i;tmp.val=v;
                 Q.push(tmp);
              }
              else{
                 while(Q.size()>=v){
                       Q.pop();
                 }
              }
          }
          getchar();
          scanf("%c %d",&w,&v);
          memset(flag,0,sizeof(flag));
          if(v<=Q.size()){
             ans1=Q.size();
             ans2=0;
             while(Q.size()){
                    node tmp=Q.top();
                    Q.pop();
                    flag[tmp.id]=1;
                    ans2+=tmp.val;
             }
             printf("%d\n",ans2);
             printf("%d\n",ans1);
             int ff=0;
             for(i=2;i<=n;i++){
                 if(flag[i]){
                    if(ff) printf(" ");
                    printf("%d",i);
                    ff=1;
                 }
             }
             printf("\n");
          }
          else printf("-1\n");
    }
    return 0;
}
