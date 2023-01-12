#include<bits/stdc++.h>
using namespace std;

void display(vector<string> vec){
    for(auto ele: vec){
        cout<<ele<<" ";
    }
    cout<<endl;
}

int main(int argc, char **argv){
    vector<string> solar_system = {"Mercury", "Venus", "Earth","Mars","Jupiter","Saturn","Uranus","Neptune"};
    display(solar_system);

    // vector<string>::iterator falcon = solar_system.begin();
    auto falcon = solar_system.begin();

    for(;falcon != solar_system.end();falcon++){
        cout<<*falcon<<" ";
    }
    cout<<endl;

    // vector<string>::reverse_iterator milano = solar_system.rbegin();

    // for(;milano!= solar_system.rend();milano++){
    //     cout<<*milano<<" ";
    // }

    vector<string>::iterator milano = solar_system.end()-1;

    for(;milano!= solar_system.begin()-1;milano--){
        cout<<*milano<<" ";
    }


    return 0;
}