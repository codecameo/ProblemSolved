#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int getMinIndex(int f[]){
    for(int i=0;i<26;i++){
        if(f[i]>0)
            return i;
    }
    return 26;
}

int main() {
    string s;
    char s1[10001];
    int freq[26]={0};
    int skip[26]={0};
    cin>>s;
    int len = s.length();
    for(int i=0;i<len;i++){
        char c = s.at(i);
        freq[c -'a']++;
    }

    for(int i=0;i<26;i++) {
        freq[i] = freq[i]/2;
        skip[i] = freq[i];
    }

    char best_seen = 'z'+1;
    int best_index = len-1;
    int string_index=0;
    int minChar = getMinIndex(freq);
    for(int i=len-1;i>=0;i--){
        char c = s.at(i);
        int index = c-'a';

        if(freq[index]<=0) continue;

        if(index>minChar){
            if(skip[index]==0){
                if(c < best_seen){
                    s1[string_index++]=c;
                    freq[index]--;
                    best_seen='z'+1;
                }else{
                    while(i!=best_index){
                        i++;
                        skip[s[i]-'a']++;
                    }
                    freq[s[i]-'a']--;
                    s1[string_index++]=s[i];
                    best_seen='z'+1;
                }
            }else{
                skip[index]--;
                if(c < best_seen){
                    best_seen = c;
                    best_index = i;
                }
            }
        }else{
           if(freq[index]>0){
                s1[string_index++]=s[i];
                freq[index]--;
                minChar = getMinIndex(freq);
                best_seen='z'+1;
           }

        }
    }
    s1[string_index]='\0';
    cout<<s1<< '\n';

    return 0;
}
