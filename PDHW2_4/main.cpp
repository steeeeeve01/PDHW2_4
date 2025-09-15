//
//  main.cpp
//  PDHW2_3
//
//  Created by 簡紹益 on 2025/9/15.
//

#include <iostream>
using namespace std;

const int MAXN = 20;
int calcRulSeats(int rulVotes[][MAXN], int oppVotes[][MAXN],
                 int posCnt[][MAXN], int rowCnt, int colCnt,int n);
int main() {
    int a[MAXN][MAXN] = {0},b[MAXN][MAXN] = {0},p[MAXN][MAXN] = {0};
    int n = 0;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>p[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>b[i][j];
        }
    }
    int maxRulSeats=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int curRulSeat = calcRulSeats(a, b, p, i, j,n);
            maxRulSeats = max(curRulSeat,maxRulSeats);
        }
    }
    cout << maxRulSeats;
    return 0;
}

int calcRulSeats(int rulVotes[][MAXN], int oppVotes[][MAXN],
                 int posCnt[][MAXN], int rowCnt, int colCnt,int n){
    int rulCnt1=0,oppCnt1=0,pos1=0;
    int rulCnt2=0,oppCnt2=0,pos2=0;
    for(int i=1;i<=rowCnt;i++){
        for(int j=1;j<=colCnt;j++){
            if (i==j && j==n) continue;
            rulCnt1 += rulVotes[i][j];
            oppCnt1 += oppVotes[i][j];
            pos1 += posCnt[i][j];
            
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            rulCnt2 += rulVotes[i][j];
            oppCnt2 += oppVotes[i][j];
            pos2 += posCnt[i][j];
        }
    }
    rulCnt2 -= rulCnt1;
    oppCnt2 -= oppCnt1;
    pos2 -= pos1;
    int curRulSeat =0;
    if(rulCnt1 >= oppCnt1){
        curRulSeat += pos1;
    }
    if(rulCnt2 >= oppCnt2){
        curRulSeat += pos2;
    }
    return curRulSeat;
}
