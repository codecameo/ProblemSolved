#include <iostream>
#include <cstdio>
   #include <cstring>
   #include <cmath>
   using namespace std;

 const int maxn = 110;
  const int maxm = 11000;
  const int oo = 2000000;

  int n,s;
  int v[maxn], w[maxn];
  int f[maxm][maxn];

  int solve();

  int main()
  {
      while (!cin.eof())
      {
          cin >> s >> n;
          s+= 200;
          if (cin.eof()) break;
          for (int i=1; i<=n; i++) cin >> w[i] >> v[i];
          cout << solve() << endl;
      }
      return 0;
  }

  int solve() {
      int result = 0, total = 0;
      for (int i=0; i<=n; i++)
      {
          total += w[i];
          for (int j=0; j<=s; j++) f[j][i] = -oo;
      }
      f[0][0] = 0;
      for (int j=1; j<=n; j++)
          for (int i=0; i<=min(total,s); i++)
              if (w[j]<=i) f[i][j] = max(f[i-w[j]][j-1]+v[j],f[i][j-1]);
              else f[i][j] = f[i][j-1];
      s-=200;
      for (int i=0; i<=s; i++) result = max(result,f[i][n]);
      for (int i=2001; i<=s+200; i++) result = max(result,f[i][n]);
      return(result);
 }
