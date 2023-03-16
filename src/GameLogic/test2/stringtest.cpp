#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char s[100];
    cin.getline(s,100);
    char *c = strtok(s, ",");
    cout<<*c<<endl;
    cout<<c<<endl;
    int x= stoi(c);
    cout<<(x+1)<<endl;
    c=strtok(NULL,",");
    cout<<c<<endl;


}