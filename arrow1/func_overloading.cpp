#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    if (a>=b){
        return a;
    }

    return b;
}

// int max(int a, int b, int c){
//     if(a > b){
//         if(a>c) return a;
//         return c;
//     } 
//     if(b > c) return b;
//     return c;
// }

int max(int a, int b, int c, int d = INT32_MIN){
    return max(max(a,b),max(c,d));
}

int main(int argc, char **argv){
    int a = 20;
    int b = 15;
    int c = 50;

    cout << max(a, b) << endl;
    cout << max(a, b, c) << endl;
    cout << max(a, b, c, 90) << endl;

    return 0;
}