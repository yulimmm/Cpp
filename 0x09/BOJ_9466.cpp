#include <iostream>
#include <queue>
using namespace std;

int studentList[100002];
bool ischosen[100002];
int totalMem, testCase, ans;

int getSuccessMem(int mem)
{
  int firstMem = mem;
  bool tempChosen[100002];
  queue<int>Q;
  fill(tempChosen, tempChosen+totalMem+1, 0);
  int successMem = 1;
  int chosenMem = studentList[firstMem];
  Q.push(chosenMem); tempChosen[chosenMem] = 1;
  while(1){
    int selector = Q.front(); Q.pop();
    if(selector == firstMem) break;
    int chosenMem = studentList[selector];
    if(tempChosen[chosenMem] || ischosen[chosenMem]) return 0;
    successMem++;
    Q.push(chosenMem); tempChosen[chosenMem] = 1;
  }
  for(int studentNum = 1; studentNum <= totalMem; studentNum++){
    ischosen[studentNum] =  tempChosen[studentNum];
  }
  return successMem;
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> testCase;
  for(int tc = 0; tc < testCase; tc++){
    cin >> totalMem;
    int successMem = 0;
    for(int i = 1; i <= totalMem; i++) cin >> studentList[i];
    fill(ischosen, ischosen+totalMem+1, 0);
    for(int studentNum = 1; studentNum <= totalMem; studentNum++){
      if(ischosen[studentNum]) continue;
      int result = getSuccessMem(studentNum);
      //cout << result << ' ';
      successMem += result;
    }
    cout << totalMem - successMem <<'\n';
  }
  return 0;
}
