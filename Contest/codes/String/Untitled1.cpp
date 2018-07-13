#include <stdio.h>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;
int main(){
int i,pos1=0,pos2=0;
string st,st1,st2,text;
//cin>>st1>>st2;
//st=st1+st2;
//cout<<st<<endl;
/*getline (cin, st1);
getline (cin,st2);
st=st1+st2;
cout<<st<<endl;
for(i=0;i<st.size();i++)
st[i]=toupper(st[i]);
cout<<st<<endl;
cin>>st;
for(i=0;i<5;i++)
st[i]=tolower(st[i]);
cout<<st<<endl;
pos1=st.find('O');
pos2=st.rfind('T');
cout<<pos1<<endl<<pos2<<endl<<endl;
if (st.find ("OSHAN") != string::npos)
{
    cout  << "Contains at least one OSHAN!" << endl;
}
else
{
    cout  << "Does not contain any OSHAN!" << endl;
}
getchar();
string text;
getline (cin, text);
string::size_type pos = text.find ("oshan");
cout<<pos<<endl;
int count=0;
cout<<text.size()<<endl;
for(i=0,count=0;i<text.size();i++)
{
    string::size_type pos1 = text.find ("oshan",i);
    if(pos1==string::npos)
    break;
    i=pos1;
    count++;
    //cout<<i<<endl;
}
cout<<count+1<<"c"<<endl;*/
/*string text;
getline (cin, text);

if (text.find_first_of ("aeiouAEIOU",1) == string::npos)
{
    cout << "The text entered does not contain vowels!"
         << endl;
}
else
cout << "The text entered contains vowels!"
         << endl;*/
text = "This is a test";
text.erase (5,5);
cout<<text<<endl;
text = "This is a test";
text.replace (5,2,"was");
cout<<text<<endl;
text = "hello world, this is a test";
string fra = text.substr (6,100);
cout<<fra<<endl;
return 0;
}
