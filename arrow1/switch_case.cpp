#include<bits/stdc++.h>
using namespace std;

string grade_my_assignment(int marks){
    switch(marks/10){
        case 9:
            return "A";
        case 8:
            return "B";
        case 7:
            return "C";
        case 6:
            return "D";
        case 5:
            return "E";
        case 4:
            return "F";
        case 3:
            return "G";
        default:
            return "H";
    }

    // if(marks > 90) return "A";
    // else if(marks > 80) return "B";
    // else if(marks > 70) return "C";
    // else if(marks > 60) return "D";
    // else if(marks > 50) return "E";
    // else if(marks > 40) return "F";
    // else if(marks > 30) return "G";
    // else return "H";

    // return "ZZ";

}

int main(int argc, char **argv){
    int marks = -197;

    cout<<"You grade is "<<grade_my_assignment(marks)<<endl;

    return 0;
}