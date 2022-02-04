#include <iostream>
using namespace std;
int sol;
 bool check(char arr[][3]) {
  char x = arr[0][0];
  bool flag = true;
  for (int i = 0; i < 3; i++) {
    if (arr[i][i] != x || arr[i][i] == '.') {
      flag = false;
      break;
    }
  }
  if (flag)
    return true;
  x = arr[0][2];
  flag = true;
  int row = 0, col = 2;
  for (int i = 0; i < 3; i++) {
    if (arr[row][col] != x || arr[row][col] == '.') {
      flag = false;
      break;
    }
    row++;
    col--;
  }
  if (flag)
    return true;
  for (int i = 0; i < 3; i++) {
    flag = true;
    for (int j = 1; j < 3; j++) {
      if (arr[i][j] != arr[i][j - 1] || (arr[i][j] == '.' || arr[i][j - 1] == '.'))
        flag = false;
    }
    if (flag)
      return true;
  }
  for (int i = 0; i < 3; i++) {
    flag = true;
    for (int j = 1; j < 3; j++) {
      if (arr[j][i] != arr[j - 1][i] || (arr[j][i] == '.' || arr[j - 1][i] == '.'))
        flag = false;
    }
    if (flag)
      return true;
  }
  return false;
}   
bool isFull(char arr[3][3]){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(arr[i][j]=='.')
        return false;
    }
  }
  return true;
}
void how_Many_Different_Games_Could_We_Play(char arr[][3],int num){
if(check(arr)){
  sol++;
  return ;
}
if(isFull(arr)){
  sol++;
  return ;
}
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(arr[i][j]=='.'){
        if(num%2==0){
          arr[i][j]='x';
          how_Many_Different_Games_Could_We_Play(arr,num+1);
          arr[i][j]='.';
        }else{
          arr[i][j]='o';
          how_Many_Different_Games_Could_We_Play(arr,num+1);
          arr[i][j]='.';
        }
      }
    }
  }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);
    #endif
    char arr[3][3];
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        arr[i][j]='.';
      }
    }
    how_Many_Different_Games_Could_We_Play(arr,0);
    cout<<sol<<endl;
      return 0;
    }