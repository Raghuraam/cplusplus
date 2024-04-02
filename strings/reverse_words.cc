// Example program
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string s = "the sky is blue ";
  vector<string> v;
  string word;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != ' ') {
      word = word + s[i];
    } else if (s[i] == ' ') {
      v.push_back(word);
      word = "";
    }

    if (i == s.length() - 1) {
      v.push_back(word);
    }
  }

  for (auto it = v.end(); it >= v.begin(); it--) {
    cout << *it << endl;
  }
}
