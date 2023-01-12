#include<bits/stdc++.h>
using namespace std;

class Marvel{
    private:
    int a;
    protected:
    int b;
    public:
    int c;
    void print_info(){
        cout << "Marvel: " << a << " " << b << " " << c<<endl;
    }    
};

class Character: public Marvel{

};

int main(int argc, char** argv){
    Marvel hero;
    // cout<<sizeof(Marvel)<<endl;
    // cout<<sizeof(hero);

    // cout<<hero.a<<endl;
    // cout<<hero.b<<endl;
    cout<<hero.c<<endl;

    hero.print_info();

    return 0;
}