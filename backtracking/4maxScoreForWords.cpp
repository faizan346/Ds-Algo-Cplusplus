#include<bits/stdc++.h>
using namespace std;

int maxScoreForWords(string *words,int n, int *farr, int *scores, int idx) {
    if(idx == n) {
        return 0;
    }
    //words not included
    int maxScoreNoCurr = maxScoreForWords(words,n, farr, scores, idx+1);
    //word const for curr idx
    bool flag = true;
    string word = words[idx];
    int currScore = 0;
    for(auto c : word) {
        if(farr[c - 'a'] - 1 < 0) {
            flag = false; //words can be included becox fre has no lement left
        }
        farr[c - 'a']--;
        currScore += scores[c - 'a'];
    }

    int maxScoreCurr = 0;//when currwords not possible cost will be 0
    if(flag) {// cost whle including curr word
        maxScoreCurr = currScore + maxScoreForWords(words,n, farr, scores, idx+1);
    }
    for(auto c : word) { //setting freq back when backtraking
        farr[c - 'a']++;
    }
    return max(maxScoreNoCurr, maxScoreCurr); //max of included and not included.
    
}

int main() {

    return 0;
}