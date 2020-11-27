#include<iostream>
#include<string>
using namespace std;
bool isrot(string str1,string str2){
    if(str1.length()!=str2.length())
        return false;
    string temp = str1+str1;
    return (temp.find(str2)!=string::npos);
}

int main(){
    string str1="ABCD";
    string str2="CDAB";
    bool res = isrot(str1,str2);
    if(res==false)
        cout<<"Not rotation\n";
    else
        cout<<"Are rotation\n";
    return 0;
}
