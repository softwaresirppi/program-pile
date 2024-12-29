#include <bits/stdc++.h>
using namespace std;

void traverse(vector<int>& candidates, vector<int>& selection, vector<vector<int>>& combos){
    vector<int> combo;
    for(int i : selection)
        combo.push_back(candidates[i]);
    combos.push_back(combo);

    if(selection.size() == candidates.size()) return;
    for(int i = 0; i < candidates.size(); i++) {
        bool unique = find(selection.begin(), selection.end(), i) == selection.end();
        bool noorder = selection.empty() || i >= selection.back();
        if(noorder) {
            selection.push_back(i);
            traverse(candidates, selection, combos);
            selection.pop_back();
        }
    }
}

int main() {
    vector<int> nums{1,2,3};
    vector<int> selection;
    vector<vector<int>> selections;
    traverse(nums, selection, selections);
    for(vector<int> sel : selections){
        for(int x : sel){
            cout << x << ", ";
        }
        cout << "\n";
    }
}
