#include <iostream>

#include <cmath>

using namespace std;
bool check(char arr[3][3]) {
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
int main() {
  char arr[3][3];
  for (int j = 0; j < 3; j++) {
    for (int k = 0; k < 3; k++) {
      arr[j][k] = '.';
    }
  }
  for (int i = 0; i < 9; i++) {
    int a;
    cin >> a;
    int row = ceil(a / 3.0) - 1, col = 0;
    if (row == 2) row = 0;
    else if (row == 0) row = 2;
    if (a % 3 == 0)
      col = 2;
    else
      col = a % 3 - 1;
    if (arr[row][col] != '.') {
      cout << "illegal box" << endl;
      i--;
      continue;
    }
    if (i % 2 == 0)
      arr[row][col] = 'x';
    else
      arr[row][col] = 'o';
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        cout << arr[j][k] << " ";
      }
      cout << endl;
    }
    if (check(arr)) {
      cout << "Congratulation, you win" << endl;
      cin >> a;
      return 0;
    }

  }
  return 0;
}