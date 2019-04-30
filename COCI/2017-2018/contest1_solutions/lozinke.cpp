#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

const int MAXN = 2e4 + 10;

int n;

string l[MAXN];

unordered_set<string> s;
unordered_map<string, int> cnt;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> l[i];
    s.clear();

    for (int j = 0; j < (int) l[i].size(); ++j) {
      string curr;
      for (int k = j; k < (int) l[i].size(); ++k) {
        curr.push_back(l[i][k]);
        s.insert(curr);
        cout <<curr << '\n';
      }
    }

    for (auto &x : s)
      cnt[x]++;
  }

  int sol = 0;
  for (auto &x : l)
    sol += cnt[x];

  cout << sol - n << endl;

  return 0;
}

