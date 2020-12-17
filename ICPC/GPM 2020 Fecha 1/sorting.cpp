#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
   int n;
   map<int,int> mnums;
   vector<pair<int,int>> vnums;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      int b;
      cin >> b;
      mnums[b] = max(mnums[b],i);
      vnums.push_back({b,i});
   }
   sort(vnums.begin(),vnums.end());
   int next_pos = vnums.size();
   int bef = vnums.front().first, bef_pos = mnums[bef];
   for(auto it = vnums.begin() + 1; it != vnums.end(); ++it) {
      int act = it->first; int act_pos = it->second;
      if(it->first > (it-1)->first) {
         bef = (it-1)->first, bef_pos = mnums[bef];
      }
      if(act > bef && bef_pos > act_pos) {
         mnums[act] = it->second = next_pos++;
      }
   }
   cout << next_pos - vnums.size() << '\n';
   return 0;
}