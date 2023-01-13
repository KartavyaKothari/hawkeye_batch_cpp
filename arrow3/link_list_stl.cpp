#include<bits/stdc++.h>
using namespace std;

void display(list<int> &ll){
    for(auto ele: ll){
        cout << ele << " ";
    }
}

int main(int argc, char **argv){
    list<int> ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_front(3);
    ll.push_front(4);

    display(ll);

    return 0;
}