#include <bits/stdc++.h>

using namespace std;

string s;
int n, res;

struct Power{
    int num=0, power=0;
};
struct Table{
    vector<Power> divisor;
}table[500001];

vector<int> bTable(500001);

void buildTable(){
    for(int i=0;i<n;i++){
        if(s.at(i)=='b'){
            bTable.push_back(i);
        }
        if(table[i].divisor.size() < 1){
            for(int j=i;i>1 && j<=n;j+=i) {
                long long int powerNum=j;
                int p = 0;
                while(powerNum%i==0){
                    powerNum/=i;
                    p++;
                }
                Power power;
                power.num=i;
                power.power=p;
                table[j].divisor.push_back(power);
            }
        }
    }
}

void getDivisor(int num, int index, int target){
    //printf("%d %d\n",num,index);
    if(table[target].divisor.size()==index){

        int64_t sqr = 1LL*target*target;
        int64_t num2 = sqr/(1LL*num);
        cout<<num<<' '<<num2<<' '<<sqr<<endl;
        //printf("%d %lld %lld\n",num,num2,sqr);

        if(num2>n || num2<=0 || num>n || num<=0 || num*num2!=sqr || s.at(num-1)=='b' || s.at(num2-1)=='b') return;
        if(s.at(num-1)!=s.at(num2-1)){
            res++;
        }

        return;
    }

    int div = table[target].divisor[index].num;
    int power = table[target].divisor[index].power;
    int tempNum = num;
    int loop = 0;

    while(tempNum<target && loop <=power*2) {
        getDivisor(tempNum,index+1,target);
        tempNum*=div;
        loop++;
    }
}


int main() {
    cin>>n>>s;
    //printf("String size %d\n",s.max_size());
    res=0;
    buildTable();
    //printf("(%d %d) (%d %d)\n",table[6].divisor[0].num,table[6].divisor[0].power,table[6].divisor[1].num,table[6].divisor[1].power);

    for(int i=0;i<bTable.size();i++){
        getDivisor(1,0,bTable[i]+1);
    }

    //printf("(%d %d) (%d %d) (%d %d) (%d %d)\n",table[94600].divisor[0].num,table[94600].divisor[0].power,table[94600].divisor[1].num,table[94600].divisor[1].power,table[94600].divisor[2].num,table[94600].divisor[2].power,table[94600].divisor[3].num,table[94600].divisor[3].power);

    cout << res << endl;
    return 0;
}
