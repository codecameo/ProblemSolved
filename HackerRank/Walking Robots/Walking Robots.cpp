#include <bits/stdc++.h>

using namespace std;

int howManyCollisions(string s){
    // Complete this function
    int len = s.length(), colusion=0, sameDirec=0;
    char prev = s.at(0), cur;
    for(int i=1;i<len;i++){
        cur = s.at(i);
        //printf("%c %c\n",prev,cur);
        if(cur == prev){
            if(cur != 'd')
                sameDirec++;
            continue;
        }

        if(cur == 'd' && prev == 'r'){
            prev = 'd';
            colusion++;
            colusion+=sameDirec;
            sameDirec=0;
        }else if(cur == 'l' && prev == 'd'){
            prev = 'd';
            colusion++;
            colusion+=sameDirec;
            sameDirec=0;
        }
        else if(cur == 'l' && prev == 'r'){
            colusion=colusion+2;
            colusion+=sameDirec;
            prev = 'd';
            sameDirec=0;
        }else{
            prev = s.at(i);
            sameDirec=0;
        }

        //printf("%c %c %d %d\n",prev,cur,colusion,sameDirec);
    }

    return colusion;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        // Returns the number of times moving robots collide.
        int result = howManyCollisions(s);
        cout << result << endl;
    }
    return 0;
}

