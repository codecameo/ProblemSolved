#include <iostream>
#include <string>
#include <map>

using namespace std;
struct Node{
    int count=0;
    map<char, Node*> nextMap;
};


int main()
{
    int n;
    cin >> n;
    Node *head = new Node();
    string add = "add", find = "find";
    for(int i=0;i<n;i++){
        string action, name;
        cin>>action>>name;
        if(action == add){
            long len = name.size();
            Node *cur = head;
            for(int i=0;i<len;i++){
                Node *next = cur->nextMap[name[i]];
                if(next == NULL){
                    next = new Node();
                    cur->nextMap[name[i]]=next;
                }
                next->count++;
                cur = cur->nextMap[name[i]];
            }
        }
        else{
            int res = 0;
            long len = name.size();
            Node *cur = head;
            for(int i=0;i<len;i++){
                Node *next = cur->nextMap[name[i]];
                if(next == NULL){
                    res = 0;
                    break;
                }
                cur = cur->nextMap[name[i]];
                res = cur->count;
            }
            cout<<res<<endl;
        }
    }
    return 0;
}
