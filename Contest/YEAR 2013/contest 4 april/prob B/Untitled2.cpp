#include<cstdio>
//#include<sstream>
//#include<cstdlib>
//#include<cctype>
//#include<cmath>
//#include<algorithm>
#include<set>
//#include<queue>
//#include<stack>
//#include<list>
//#include<iostream>
//#include<fstream>
//#include<numeric>
//#include<string>
//#include<vector>
#include<cstring>
//#include<map>
#include<iterator>
#define i64 long long int
using namespace std;
const int maxn=1010;
int table[maxn][maxn] ;
int dx[] ={-1,-1,-2,-2,1,-3} ;
int dy[] ={-2,-3,-1,1,-2,-1} ;
bool in_line(int x,int y){
	if(x<0 ||y<0) return false ;
	return true ;
}
int grundyNumber(int posx,int posy) {
if(table[posx][posy]!=-1)
return table[posx][posy] ;
set<int>s;
set<int>::iterator it;
    for(int i=0;i<6;i++){
    	int New_x  = dx[i]+posx ;
    	int New_y = dy[i]+posy ;
    	if(in_line(New_x,New_y))
    		s.insert(grundyNumber(New_x,New_y)) ;
    }
    int ret=0;
    while (1)
    {
        it=s.find(ret);
        if(it)
        ret++;
        else
        break;
    }
    table[posx][posy] = ret ;
    return ret;
}


int main() {
  int tc,ct=1,ans ,k,x,y;
  memset(table,-1,sizeof(table)) ;
  for(int i=0;i<maxn;i++){
	  for(int j=0;j<maxn;j++)
	  table[i][j] = grundyNumber(i,j) ;
  }
  scanf("%d",&tc) ;
  while(tc--){
	  ans=0;
	  scanf("%d",&k) ;
	  while(k--){
		  scanf("%d %d",&x,&y) ;
		  ans^=table[x][y] ;
	  }

	  printf("Case %d: ",ct++) ;
	  if(ans) printf("Alice") ;
	  else printf("Bob") ;
	  printf("\n" ) ;
  }
return 0;
}
