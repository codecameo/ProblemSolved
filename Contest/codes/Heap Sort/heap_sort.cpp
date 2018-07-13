#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int heap[10000],len=0;
void insert(int item)
{
    len++;
    int loc=len,par;
    heap[loc]=item;
    par=loc/2;
    while(par)
    {
        if(heap[par]>=heap[loc])
        break;
        else
        {
            swap(heap[loc],heap[par]);
            loc=par;
            par=par/2;
        }
    }
}
int del()
{
    int left,right,loc,item;
    item=heap[1];
    heap[1]=heap[len];
    len--;
    loc=1;
    left=2*loc;
    right=left++;
    while(right<=len)
    {
        if((heap[loc]>=heap[left])&&(heap[loc]>=heap[right]))
        break;
        if(heap[left]>heap[right])
        {
            swap(heap[loc],heap[left]);
            loc=left;
        }
        else
        {
            swap(heap[loc],heap[right]);
            loc=right;
        }
        left=loc*2;
        right=left++;
    }
    if(left==len && heap[left]>heap[loc])
     swap(heap[loc],heap[left]);
     return item;
}
int main()
{
    int itm,key,i,x,l;
    for(;;)
    {
        printf("1. Insert\n2. Delete\n3. Print\n4. Exit\n");
        scanf("%d",&key);
        if(key==1)
        {
            scanf("%d",&itm);
            insert(itm);
        }
        else if(key==3)
        {
            l=len;
            while(len)
            {
                x=del();
                printf("%d ",x);
            }
            puts("");
        }
        else if(key==2)
        {
            del();
        }
        else
        break;
    }
}
