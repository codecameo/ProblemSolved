#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

bool table[27];

void clearTable()
{
    for(int i=0;i<27;i++)
        table[0]=false;
}


int main() {

    char sentence[1001];
    int len,index,cnt=0;

    clearTable();

    scanf ("%[^\n]%*c", sentence);
    len = strlen(sentence);
    for(int i=0;i<len && cnt<=26;i++)
    {
        if(sentence[i]==' ')
            continue;
        if(sentence[i]<97)
            index=sentence[i]-'A';
        else
            index=sentence[i]-'a';

        if(!table[index])
        {
            table[index]=true;
            cnt++;
        }
    }
    if(cnt==26)
        printf("pangram\n");
    else
        printf("not pangram\n");

    return 0;
}

