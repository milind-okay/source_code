#include<bits/stdc++.h>
#include<vector>
using namespace std;
class Solution {
    public:
        vector<vector<int> > subsets(vector<int> &S) {
            vector<vector<int> > result;
            vector<int> current;
            sort(S.begin(), S.end());
            generateSubsets(S, 0, current, result);
            sort(result.begin(), result.end());
            return result;
        }

        void generateSubsets(vector<int> &S, int index, vector<int> &current, vector<vector<int> > &result) {
            if (index >= S.size()) {
                result.push_back(current);
                return;
            }
            // Ignore the current index.
            generateSubsets(S, index + 1, current, result);

            // Include the current index.
            current.push_back(S[index]);
            generateSubsets(S, index + 1, current, result);
            current.pop_back();
        }
};
int main(){
    vector<int> mk;
    mk.push_back(1);
    mk.push_back(2);
    mk.push_back(3);
    Solution obj;
    vector<vector<int >  > ss;
    ss = obj.subsets(mk);
    for(int i=0;i<(1<<3);i++){
            for(vector<int>:: iterator j = ss[i].begin();j!=ss[i].end();++j)
        cout<<*j;
    cout<<endl;
    }

return  0;
}
