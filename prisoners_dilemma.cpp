/*
囚犯困境
題目： http://www.ziyou.math.ncu.edu.tw/~ziyou/c++/ex/1st_edition/ch08/08_22.cc.php
AB二囚犯持續n次，A以合作開始，但會依據「上一次」以牙還牙。
B的反應自訂。
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define innocent 1
#define guilty -1
#define times 20

int A_response(int B_last_response);
int B_response();
void calc(int &A_score, int &B_score);

int main(){
    int A_score=0, B_score=0;
    srand( time(NULL) );
    calc(A_score, B_score);
    cout<< "A_score: " << A_score <<", B_score: "<< B_score <<endl;
    return 0;
}


int A_response(int B_last_response){
    if(B_last_response == innocent) return innocent;
    else return guilty;
}

int B_response(){
    int i = rand()%2;
    if(i == 1) return innocent;
    else return guilty;
}

void calc(int &A_score, int &B_score){
    int A_r, B_r, last; 
    int i;

    for(i=0; i<times; i++){
        if(i == 0){
            A_r = innocent;
            B_r = B_response();
            last = B_r;
        }
        else{
            A_r = A_response(last);
            B_r = B_response();
            last = B_r;
        }
        
        if(A_r == innocent && B_r == innocent){
            cout << "A: innocent\tB: innocent" <<endl;
            A_score += 1;
            B_score += 1;
        }
        else if(A_r == innocent && B_r == guilty){
            cout << "A: innocent\tB: guilty" <<endl;
            A_score -= 2;
            B_score += 2;
        }
        else if(A_r == guilty && B_r == innocent){
            cout << "A: guilty\tB: innocent" <<endl;
            A_score += 2;
            B_score -= 2;
        }
        else if(A_r == guilty && B_r == guilty){
            cout << "A: guilty\tB: guilty" <<endl;
            A_score -= 1;
            B_score -= 1;
        }
    }
}

/*
後記：
在這個演算法中，B做了什麼，A下次就做什麼，
兩者的差異只有A的第一次和B的最後一次，
所以兩者得分差不多，最多才差4分呢。
*/