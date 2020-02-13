#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    for(int i=18;i>=0;i--) {
      if ( n > pow(3, i)) {
        cout << pow(3,i) << endl;
        cout << n / pow(3,i) << (double)n % pow(3,i) << endl;
      } else {
        cout << "no" << endl;
      }
    }
    cout << answer << endl;
    return answer;
}

int main() {
  cout << solution(11);
  // cout << solution(2);
  // cout << solution(3);
  // cout << solution(4);
  return 0;
}