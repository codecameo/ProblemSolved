#include <stdio.h>
int insert_heap(int tree[],int num_element,int item)
{
    num_element=num_element+1;
    int ptr=num_element;
    int par ;
    if(ptr>1)
    {
        while(ptr>1)
        {
            par=ptr/2;
            if(item<=tree[par])
            {
                tree[ptr]=item;
                break;
            }
            else
            {
                tree[ptr]=tree[par];
                ptr=par;
            }
        }
    }
    else
        tree[1]=item;
        //printf("%d ",&tree[1]); // first element garbage print kore
       // return tree;
}
void print_tree(int tree[], int num_element)
{
    for(int i=0;i<num_element;i++)
    {
        printf("%d ",tree[i]);
    }
}

int main()
{
    int num_element=0;
   while(true)
   {
        int item,tree[1000],choice;
        printf("please insert your choice : \n\t1.Insert item\n\t2.Print tree\n\t3.Exit\n\t");
        scanf("%d",&choice);
        if(choice==1)
        {
            //printf("Insert the number of element in tree : ");
           // scanf("%d",&num_element);
            printf("Please insert the item : ");
            scanf("%d",&item);
            tree=insert_heap(tree,num_element,item);
           // printf("%d  ",&tree[1]);
        }
        else if(choice==2)
        {
            print_tree(tree,num_element);
        }
        else if(choice==3)break;
   }
   return 0;
}
