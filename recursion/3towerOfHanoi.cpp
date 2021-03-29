#include<bits/stdc++.h>
using namespace std;
// print(n, towersrc, towerdest, towerhelper)
void printTransferDisksSteps(int n, char t1, char t2, char t3) {
    if(n == 0) {
        return;
    }
    //mujhko n-1 disk ko kisi ek tower se dusre tower mai order 
    //mai daalna ke steps aaata hai using other tower
    //so now i have left with one disk usko kese daalu?
    //simple tower t1 se n-1 disks ko tower t3 mai daalo  auro fir nth disk t2 mai dalo
    //then t3 tower helping tower se t2 mai daldo baki disk.
    printTransferDisksSteps(n-1, t1, t3, t2); //this will print steps fro n-1 disks t1 -> t2
    cout << n << "[" << t1 << " -> " << t2 << "]" << endl; // this step is to transfer last disk
    printTransferDisksSteps(n-1, t3, t2, t1); //this will print steps fro n-1 disks t2 -> t3
}

int main() {
    int n;
    cin >> n;
    char t1 = 'a', t2 = 'b', t3 = 'c';
    printTransferDisksSteps(n, t1, t2, t3); // print the steps to insert disk in t2 from t1 using t3(helping tower)
    return 0;
}