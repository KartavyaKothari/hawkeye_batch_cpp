#include<bits/stdc++.h>
using namespace std;

void count_down(int a, int b){

}

void count_down(int counter){
    if(counter == 0) return;
    cout<<counter<<endl;
    counter--;
    count_down(counter);
    // cout<<counter<<endl;
}

int main(int argc, char **argv){

    count_down(4);
    return 0;
}