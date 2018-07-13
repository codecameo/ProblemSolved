void euler()
{
    int j;
    for(int i=2;i<=MAX;i++)
    {
        if(phi[i]==0)
        {
            phi[i]=i-1;
            for(j=i+i;j<=MAX;j+=i)
            {
                if(phi[j]==0) phi[j]=j;
                phi[j]/=i;
                phi[j]*=i-1;
            }
        }

    }
    for(int i=1;i<=2000000;i++)
        {
        for(int j=2;j*i<=2000000;j++)
        {
            g[j*i]+=i*phi[j];
        }

        }

}
