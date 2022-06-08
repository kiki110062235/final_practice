#include<bits/stdc++.h>
using namespace std;
stack <char> S;
int main(){
    int T;
    cin >> T;
    string str;
    for(int t=1; t<=T; t++){
        cin >> str;
        int len = str.length();
        for(int i=len-1; i>=0; i--){
            // if S.empty() and you wamt to access its top, causes RE!
            if(S.empty()){
                S.push(str[i]);
                continue;
            }
            if(str[i] == '[' && S.top() == ']')    S.pop();
            else if(str[i] == '{' && S.top() == '}')  S.pop();
            else if(str[i] == '(' && S.top() == ')')  S.pop();
            else if(str[i] == '<' && S.top() == '>')  S.pop();
            else S.push(str[i]);
        }
        if(S.empty())   cout << "Case " << t << ": Yes" << endl;
        else{
            while(!S.empty()) S.pop();
            cout << "Case " << t << ": No" << endl;
        }
    }
    return 0;
}