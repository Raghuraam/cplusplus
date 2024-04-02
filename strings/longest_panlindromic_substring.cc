// program to find the longest palindromic substring
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longest_palindrome;

bool isPalindrome(string &word) {
  for (int i = 0, j = word.length() - 1; i < j; i++, j--) {
    if (word[i] != word[j]) {
      return false;
    }
  }

  if (longest_palindrome.length() < word.length()) {
    longest_palindrome = word;
  }

  return true;
}
int main() {
  string s = "cbbd";
  vector<string> v;
  string word;
  for (int i = 0; i < s.length(); i++) {
    word = s[i];
    cout << word << endl;
    isPalindrome(word);
    for (int j = i + 1; j < s.length(); j++) {
      word = word + s[j];
      cout << word << endl;
      isPalindrome(word);
    }
    cout << "--------------" << endl;
    word = "";
  }

  cout << "longest_palindrome : " << longest_palindrome << endl;
}
