//소요시간 20분 난이도 별 2
#include<iostream>
using namespace std;

bool board[100][100];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    for(int k = 0; k < 2; k++){
        int a, b;
        cin >> a >> b;
        for(int i = a-1; i < b; i++){
            int j = 0;
            while(j < m){
                if(board[i][j]==1){
                    board[i][j] = 0;
                    break;
                }
                j++;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j]==1){
                ans++;
            }
        }
    }

    cout<<ans;

   return 0;
}
