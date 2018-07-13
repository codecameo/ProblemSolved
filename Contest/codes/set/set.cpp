#include <iostream>
#include <set>
using namespace std;
int main ()
{
  std::set<int> myset;
  std::set<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=5; i++) myset.insert(i*10);
  myset.insert(23);    // set: 10 20 30 40 50

  //while(myset.find(80)!=s.end())
  it=myset.find(10);
  if(it!=myset.end()){
  cout<<"jehd"<<endl;
  //myset.erase (it);
  }
  myset.erase (myset.find(40));
  std::cout << "myset contains:";
  //for (it=myset.begin(); it!=myset.end(); ++it)
    //std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
