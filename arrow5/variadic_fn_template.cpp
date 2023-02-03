#include<bits/stdc++.h>
using namespace std;

template <typename KOALA_DT>
void print_all(KOALA_DT data){
    cout<<data<<endl;
}

template <typename KOALA_DT, typename... KOALA_DT2>
void print_all(KOALA_DT data, KOALA_DT2... data2){
    print_all(data);
    print_all(data2...);
}

int main(int argc, char **argv){
    string name = "Kartavya";
    int age = 25;
    print_all(name,"Kothari",age);
    // print_all(name);
    return 0;
}