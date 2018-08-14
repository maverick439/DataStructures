//To count the no of substring which start from a particular char and end at a particular char
#include <iostream>
#include <cstring>
using namespace std;
int countSubstr(string str,int n,char x,char y){
    int tot_count = 0;
    int count_x = 0;
    for(int i=0;i<n;i++){
        if(str[i] == x)
            count_x++;
        if(str[i] == y)
            tot_count += count_x;
    }
    return tot_count;
}
int main() {     
    string str;
    cin>>str;
    char x,y;   //x = start char    y = end char
    cin>>x>>y;
    int n = str.size();
    int ans = countSubstr(str,n,x,y);   //count substrings which start from x and end with y
    cout<<ans;
}
