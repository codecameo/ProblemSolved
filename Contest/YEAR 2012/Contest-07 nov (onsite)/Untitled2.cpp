#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while (scanf("%d",&n) ==1 && n){
        getchar();
        for (int i=1;i<=n;i++){
            string s1,s2;
            s1.clear();
            getline(cin,s1);
            int len=s1.length();
            for (int j=0;j<len;j++)
                if (s1[j]==' '){
                    if (s2.length())
                        for (int k=0;k<s2.length();k++)
                            //printf("%c",s2[s2.length()-k-1]);
                            cout<<s2[s2.length()-k-1];
                    //printf(" ");
                    cout<<" ";
                    s2.clear();
                }
                else s2+=s1[j];
            if (s2.length())
                for (int k=0;k<s2.length();k++)
                    //printf("%c",s2[s2.length()-k-1]);
                    cout<<s2[s2.length()-k-1];
            //printf("\n");
            cout<<endl;
        }
    }

    return 0;
}
