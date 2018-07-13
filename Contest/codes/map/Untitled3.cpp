#include <iostream>
#include <map>
#include <string.h>
using namespace std;

int main ()
{
  map<char,int> mymap;
  map<char,int>::iterator it;
   //memset(mymap->second,0,sizeof(mymap));
   mymap.clear();
  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;

  it=mymap.find('b');
  //mymap.erase (it);
 // mymap.erase (mymap.find('d'));

  // print content:
  cout << "elements in mymap:" << endl;
  cout << "a => " << mymap.find('a')->second << endl;
  cout << "c => " << mymap.find('c')->second << endl;

  return 0;
}
