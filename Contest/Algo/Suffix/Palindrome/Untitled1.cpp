/*
Suffix array O(n lg^2 n)
LCP table O(n)
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int MAXN = 300000;
int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];
char S[MAXN];
namespace SuffixArray{
    int N, gap;
	bool sufCmp(int i, int j){
		if (pos[i] != pos[j])
			return pos[i] < pos[j];
		i += gap;
		j += gap;
		return (i < N && j < N) ? pos[i] < pos[j] : i > j;
	}

	void buildSA(){
		N = strlen(S);
		REP(i, N) sa[i] = i, pos[i] = S[i];
		for (gap = 1;; gap *= 2){
			sort(sa, sa + N, sufCmp);
			REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
			REP(i, N) pos[sa[i]] = tmp[i];
			if (tmp[N - 1] == N - 1) break;
		}
	}

	void buildLCP(){
		for (int i = 0, k = 0; i < N; ++i)
            if (pos[i] != N-1){
                for (int j=sa[pos[i]+1];S[i+k]==S[j+k];) ++k;
                lcp[pos[i]] = k;
                if (k)--k;
            }
	}
} // end namespace SuffixArray
void reset(){
    memset(sa,0,sizeof(sa));
    memset(pos,0,sizeof(sa));
    memset(tmp,0,sizeof(sa));
    memset(lcp,0,sizeof(sa));
}
int N;
char s1[MAXN],s2[MAXN];
int main(){
    int l,i,st;
    cin>>s1;
    N=strlen(s1);
    for(i=0;i<N;i++)    S[i]=s1[i];
    S[i++]='#';
    for(int j=N-1;j>=0;j--) S[i++]=s1[j];
    //cout<<"Length = : "<<N<<endl;
    /*strcpy(s2,s1);
    reverse(s2,s2+N);
    strcpy(S,s1);
    strcat(S,"#");
    strcat(S,s2);*/
    //cout<<S<<endl;
    SuffixArray::buildSA();
    SuffixArray::buildLCP();
    l=-1;
    st=N*3+1;
    for(i=0;i<=2*N;i++){
        //cout<<sa[i]<<endl;
        if((sa[i]<N&&sa[i+1]>N)||(sa[i]>N&&sa[i+1]<N)){
            if(sa[i]+sa[i+1]+lcp[i]!=2*N+1) continue;
            if(l<lcp[i]){
                l=lcp[i];
                st=min(sa[i],sa[i+1]);
            }
            else if(l==lcp[i]){
                st=min(st,min(sa[i],sa[i+1]));
            }
        }
    }
    if(l==1){
        cout<<S[0]<<endl;
        return 0;
    }
    for(i=st;i<st+l;i++){
        cout<<S[i];
    }
    puts("");
}
