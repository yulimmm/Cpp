//한양대 HCPC 2023 Lv2 소요시간: 1시간...
#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0); cin.tie(0);
    string ss;
    stack<char>st;
    cin >> ss;
    int sz = ss.size();

    for(int i = 0; i < sz; i++){
        if(ss[i] == '('){
            cout<<'(';
            st.push(ss[i]);
        }
        else{
            st.pop();
            if(ss[i+1]=='('){
                cout<<1<<')'<<'+';
            }
            else if(ss[i+1]==')' && st.size()>0){
                cout<<1<<')'<<'+';
            }
            else if(st.size()==0){
                cout<<1<<')';
            }
        }
        
    }

   return 0;
}
