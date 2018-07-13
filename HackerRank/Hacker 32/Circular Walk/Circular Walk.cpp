#include <bits/stdc++.h>

using namespace std;

int R[10000001];
bool table[10000001];
int n,s,t,g,seed,p;

struct Node{
    int number,index;
    int clkLow,clkHigh;
    int counterClkLow, counterClkHigh;
};

void constructR(){
    for(int i=1;i<n;i++){
        R[i]=(R[i-1]*g+seed)%p;
        printf("%d\n",R[i]);
    }
}

int getClockWiseNum(int number,int offset){
    number += offset;
    return number%n;
}

int getCounterClockWiseNum(int number,int offset){
    number -= offset;
    if(number<0) number = n+number;
    return number;
}

int nextClockNumber(int position){
    return getClockWiseNum(position,1);
}

int nextCounterClockNumber(int position){
    return getCounterClockWiseNum(position,1);
}

int bfs(){
    queue<Node> q;
    Node source;
    source.number=s;
    source.index=0;
    source.clkHigh = getClockWiseNum(source.number,R[source.number]);
    source.clkLow = nextClockNumber(source.number);
    source.counterClkHigh = getCounterClockWiseNum(source.number,R[source.number]);
    source.counterClkLow = nextCounterClockNumber(source.number);
    q.push(source);
    table[source.number]=true;
    int number = -1;
    bool isClkRotation = true, isAntiClkRotation = false;

    while(!q.empty()){
        source = q.front();
        printf("Source %d Index %d\n",source.number,source.index);
        int index = source.index;
        if(R[source.number] == 0){
            q.pop();
            continue;
        }
        int number;
        bool alter = false;

        if(isClkRotation){
            if(number == -1){
                number = source.clkLow;
            }
            else{
                number = nextClockNumber(number);
            }
            while(table[number] && number!=source.clkHigh){
                number = nextClockNumber(number);
            }
            if(number==source.clkHigh){
                alter = true;
            }
        }

        if(isAntiClkRotation){
            if(number==-1){
                number = source.counterClkLow;
            }
            else{
                number = nextCounterClockNumber(number);
            }
            while(table[number] && number!=source.counterClkHigh){
                number = nextCounterClockNumber(number);
            }
            if(number==source.counterClkHigh){
                alter = true;
            }
        }
        printf("Child %d\n",number);
        //if(number==t) return index+1;

        if(!table[number]){
            Node child;
            child.number=number;
            child.index=index+1;
            child.clkHigh = getClockWiseNum(child.number,R[child.number]);
            child.clkLow = nextClockNumber(child.number);
            child.counterClkHigh = getCounterClockWiseNum(child.number,R[child.number]);
            child.counterClkLow = nextCounterClockNumber(child.number);
            q.push(child);
            printf("%d %d %d %d %d\n",child.clkLow,child.clkHigh,child.counterClkLow,child.counterClkHigh,child.index);
            table[child.number]=true;
        }

        if(alter){
            isClkRotation= !isClkRotation;
            isAntiClkRotation= !isAntiClkRotation;
            number=-1;
            if(isClkRotation)
                q.pop();
        }
    }
    return -1;
}

int main(){

    cin>>n>>s>>t;
    cin>>R[0]>>g>>seed>>p;
    constructR();
    if(s==t)
        cout<<0;
    else
        cout<<bfs();


    return 0;
}
