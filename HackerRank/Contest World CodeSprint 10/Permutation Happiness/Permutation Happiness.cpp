#include <bits/stdc++.h>

using namespace std;

struct happiness{
    int num;
    bool happy;
}number[3001];

bool table[3001]={false};
int n,k,happyCombo;


void clear(){
    happyCombo=0;
    for(int i=0;i<=3000;i++){
        table[i]=false;
        number[i].happy=false;
    }

}

void print(int index){
    for(int i=1;i<=index;i++)
        printf("(%d %d)",number[i].num,number[i].happy);
    printf("\n");
}

void calculateCombo(){
    int count=0;
    for(int i=1;i<=n;i++){
        if(number[i].happy)
            count++;
        if(count>=k){
            happyCombo++;
            break;
        }
    }
}

void backtrack(int index, int happyCount){
    if(index==n+1){
        calculateCombo();
        //print(n);
        return;
    }

    for(int i=1;i<=n;i++){
        if(table[i])continue;
        table[i]=true;
        number[index].num = i;
        if(index>1){

            number[index].happy = number[index-1].num > number[index].num;

            if(index==1){
                number[index-1].happy =  !(number[index-1].num > number[index].num);
            }else{
                number[index-1].happy = number[index-2].num > number[index-1].num | number[index].num >  number[index-1].num;
            }
        }

        number[index+1].happy=false;
        backtrack(index+1,happyCount);
        table[i]=false;
    }
}



int query(int n, int k){
    backtrack(1,0);
    return happyCombo;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        clear();
        cin >> n >> k;

        if(n==k){
            cout<<0<<endl;
            continue;
        }
        // Find the number of ways to arrange 'n' people such that at least 'k' of them will be happy
        // The return value must be modulo 10^9 + 7
        int result = query(n, k);
        cout << result << endl;
    }
    return 0;
}

