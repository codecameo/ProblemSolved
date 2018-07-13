#include <bits/stdc++.h>

using namespace std;

struct FileSystem{
    set<int> avaiblePos;
    int maxPos=0;
};

map<string,FileSystem> fileMap;

string getNewFileName(string s,int pos){
    if(pos==0) return s;
    ostringstream convert;   // stream used for the conversion
    convert << pos;
    return s + "(" + convert.str() + ")";
}

string createFile(string fileName){
    string new_fileName = fileName;
    FileSystem file=fileMap[fileName];
    if(file.avaiblePos.size()==0){
        if(file.maxPos!=0){
            new_fileName = getNewFileName(fileName,file.maxPos);
        }
        file.maxPos++;
    }else{
        int pos = *file.avaiblePos.begin();
        file.avaiblePos.erase(file.avaiblePos.begin());
        new_fileName = getNewFileName(fileName,pos);
    }

    fileMap[fileName]=file;
    return new_fileName;
}

string deleteFile(string fileName){
    string f=fileName;
    int openPos = fileName.find_last_of('(')+1;
    int len = fileName.length();
    int pos = 0;
    string sub;

    if(openPos!=0){
        sub = fileName.substr(openPos,len-openPos-1);
        fileName = fileName.substr(0,openPos-1);
        stringstream ss(sub);
        ss>>pos;
    }

    FileSystem file=fileMap[fileName];
    file.avaiblePos.insert(pos);
    fileMap[fileName]=file;
    return f;
}

int main() {
    int q;
    cin >> q;
    getchar();
    // Process each command
    for(int a0 = 0; a0 < q; a0++){
        string command;
        cin >> command;
        if(command.at(0)=='c'){
            string file;
            cin>>file;
            file = createFile(file);
            cout<<"+ "+file<<endl;
        }else if(command.at(0)=='d'){
            string file;
            cin>>file;
            file = deleteFile(file);
            cout<<"- "+file<<endl;
        }else if(command.at(0)=='r'){
            string oldName,newName;
            cin>>oldName>>newName;
            oldName = deleteFile(oldName);
            newName = createFile(newName);
            cout<<"r "<<oldName<<" -> "<<newName<<endl;
        }
    }
    return 0;
}

