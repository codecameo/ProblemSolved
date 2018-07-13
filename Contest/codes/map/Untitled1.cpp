// map::begin/end
#include <iostream>
#include <map>
using namespace std;
int main ()
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  // show content:
 // for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //std::cout << it->first << " => " << it->second << '\n';
    if(mymap.find('c')==mymap.end())
    cout<<mymap['c']<<endl;
    cout<<"hgfh"<<endl;

  return 0;
}
