#include<bits/stdc++.h>
using namespace std;

void findSubset(vector<int>& s, int i, int smask, int allSkills, vector<int>& asf, vector<int>& minAns) {
     if(smask == ((1 << allSkills) - 1)) {
        if(minAns.empty() || minAns.size() > asf.size()) {
            minAns = asf;
        }
    }
    if(i == s.size()) {
        return;
    }
    findSubset(s, i+1, smask, allSkills, asf, minAns); // no
    asf.push_back(i);
    findSubset(s, i+1, (smask | s[i]), allSkills, asf, minAns); // yes
    asf.pop_back();
}

void minDevelopersSubset(vector<string>& skills, vector<vector<string>>& engSkills) {
    unordered_map<string, int> umap;
    int k = 0;
    for(auto s : skills) {
        umap[s] = k++;
    }
    vector<int> skillBinary;
    for(auto es : engSkills) {
        int tempSkill = 0;
        for(auto s : es) {
            tempSkill = tempSkill | (1 << umap[s]);
        }
        skillBinary.push_back(tempSkill);
    }
    vector<int> minAns;
    vector<int> asf;
    findSubset(skillBinary, 0, 0, skills.size(), asf, minAns);
    cout<<"[";
     for(int i=0; i<minAns.size(); i++){
         cout<<minAns[i];
         if(i != minAns.size() - 1){
             cout<<", ";
         }
     }
     cout<<"]";
}

int main() {
    int n;
    cin >> n;
    vector<string> skills;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        skills.push_back(s);
    }
    int e;
    cin >> e;
    vector<vector<string>> engSkills(e, vector<string>());
    for(int i = 0; i < e; i++) {
        int ts;
        cin >> ts;
        for(int j = 0; j < ts; j++) {
            string s;
            cin >> s;
            engSkills[i].push_back(s);
        }
    }
    minDevelopersSubset(skills, engSkills);
    return 0;
}