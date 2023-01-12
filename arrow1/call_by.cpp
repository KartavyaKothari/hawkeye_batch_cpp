#include<bits/stdc++.h>
using namespace std;

// pass by value
void laxmi_chit_fund_scheme(int money) {
    money = money * 2;
}

// pass by address
void kartavya_chit_fund_scheme(int *wallet) {
    *wallet = *wallet * 2;
}

// pass by reference
void koala_chit_fund_scheme(int &money){
    money = money * 2;
}

void atm_balance(int money){
    cout<< "You have left "<<money<<" rupees"<<endl;
}

int main(int argc, char **argv){
    int money = 10;

    laxmi_chit_fund_scheme(money);

    atm_balance(money);

    kartavya_chit_fund_scheme(&money);

    atm_balance(money);

    koala_chit_fund_scheme(money);

    atm_balance(money);

    return 0;
}