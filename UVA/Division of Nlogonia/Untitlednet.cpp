#include <stdio.h>

int main()
{
    int test_case, point_x, point_y, centre_x, centre_y, i,j;

    while(scanf("%d", &test_case)==1)
    { if(test_case==0) break;
        scanf("%d %d", &centre_x, &centre_y);
        for(i=0; i<test_case; i++)
        {
            scanf("%d %d", &point_x, &point_y);
            {
                if(point_x==centre_x || point_y==centre_y)
                    printf("divisa\n");
                else if((point_x>centre_x) && (point_y>centre_y))
                    printf("NE\n");
                else if((point_x<centre_x) && (point_y>centre_y))
                    printf("NO\n");
                else if((point_x<centre_x) && (point_y<centre_y))
                    printf("SO\n");
                else printf("SE\n");
            }
        }
    }
}
