#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		double st,tmp;
		cin>>st;
		int ret=1;
		for(int i=1;i<n;i++){
			cin>>tmp;
			if(st+1.0<=tmp){
				ret++;
				st=tmp;
			}
		}
		printf("%d\n",ret);
	}
}
