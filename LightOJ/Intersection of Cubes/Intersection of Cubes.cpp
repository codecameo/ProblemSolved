#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    int kase=1,x1,y1,z1,x2,y2,z2,t,nCube;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&nCube);
        int maxX,maxY,maxZ,minX,minY,minZ;
        maxX=maxY=maxZ=-1;
        minX=minY=minZ=100000;
        for(int i=0;i<nCube;i++)
        {
            scanf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
            if(x1>maxX)
                maxX=x1;
            if(x2<minX)
                minX=x2;

            if(y1>maxY)
                maxY=y1;
            if(y2<minY)
                minY=y2;

            if(z1>maxZ)
                maxZ=z1;
            if(z2<minZ)
                minZ=z2;

        }
        int res= (maxX-minX)*(maxY-minY)*(maxZ-minZ);
        if(res>0)
            res=0;
        printf("Case %d: ",kase++);
        printf("%d\n",-1*res);
    }

    return 0;
}

