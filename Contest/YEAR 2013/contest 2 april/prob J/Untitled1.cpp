#include <stdio.h>
int main(){
	int T;
	long long c;
	int cas = 1;

	scanf("%d", &T);
	while (T--){
		scanf("%lld", &c);
		printf("Case %d: ", cas++);
		long long cnt = 0;
		while (c){
			cnt++;
			c /= 2;
		}
		printf("%lld\n", cnt);

	}
	return 0;

}
