#include<bits/stdc++.h>
using namespace std;

//when every encouner increament operation 
//just pop all and make new stack then push the number
void smallestWithPattern() {
    string str;
    cin >> str;
    stack<int> s;
    int num = 1;
    s.push(num);
    for(int i = 0; i < str.length(); i++) {
        char c = str[i];
        //we have to choose next possible smallest for every pop() so we have to push accordingly
        if(c == 'd') {
            num++;
            s.push(num);  //push current num as it will get to its next smallest possible pos while popping
        } else if(c == 'i') { //when there is i pop all prev and push this num in empty stack
            while(!s.empty()) {
                cout << s.top() << " " ;
                s.pop();
            }
            num++;
            s.push(num); //push current num as it will get to its next smallest possible pos while popping
        }
    }
     while(!s.empty()) {
        cout << s.top() << " " ;
        s.pop();
    }
    cout<< endl;
}
//ddiiddid
//3 2 1 4 7 6 5 9 8 
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    smallestWithPattern();
    return 0;
}