#include<bits/stdc++.h>
using namespace std;

bool custom_comparator(int a, int b){
    return a < b;
}

class Comparator{
    public:
    bool operator()(int a, int b){
        return a < b;
    }
};

auto cust_cmp = [](int a, int b){return a<b;};

int main(int argc, char **argv){
    // decltype(cust_cmp)


    return 0;
}