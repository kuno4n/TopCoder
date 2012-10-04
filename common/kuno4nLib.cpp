
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset(x, a, (int)sizeof(x))
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) std::cout << #A << '='<<A << std::endl;

int _isPow2(long long l);
bool isPow2(long long l);
int _isPowN(long long l, int N);
bool isPowN(long long l, int N);
long long _2to10(string s);
string _10to2(long long l);
long long Nto10(int N, string s);
string _10toN(long long l, int N);
bool isPrime(long long l)

//--------------------------------
// lが2のべき乗であれば、その指数を返す。0乗もあり。
// そうでなければ、-1を返す。
int _isPow2(long long l){
    if (l <= 0) return -1;
    int p = 0;
    while (!(l&1)){
        l >>= 1;
        p++;
    }
    if (l == 1) return p;
    else return -1;
}

//--------------------------------
// 2のべき乗かどうかの高速判定。
// 0乗もtrue。
bool isPow2(long long l){
    if (l <= 0) return false;
    else if (l & (l-1)) return false;
    else return true;
}

//--------------------------------
// N：2以上の整数
// lがNのべき乗であれば、その指数を返す。0乗もあり。
// そうでなければ、-1を返す。
int _isPowN(long long l, int N){
    if (l <= 0) return -1;
    if (N <= 1) return -1;
    int p = 0;
    while (!(l%N)){
        l/=N;
        p++;
    }
    if (l == 1) return p;
    else return -1;
}

//--------------------------------
// 0乗でもtrueとしたい場合。
bool isPowN(long long l, int N){
    if (_isPowN(l, N) == -1) return false;
    else return true;
}

//--------------------------------
//2進数を10進数に。
// s：0と1からなる文字列
long long _2to10(string s){
    long long res = 0;
    REP (i, SZ(s)) {
        res <<= 1;
        if (s[i] == '1') res++;
    }
    return res;
}

//--------------------------------
//10進数を2進数に。
// l：0以上の整数
string _10to2(long long l){
    if (l == 0) return "0";
    string res = "";
    while(l != 1){
        if ( l & 1 ) res = '1' + res;
        else res = '0' + res;
        l >>= 1;
    }
    return '1' + res;
}

//--------------------------------
//N進数の文字列sをを10進数に。
// N：2～9の自然数
// s：0～N-1からなる文字列
long long Nto10(int N, string s){
    long long res = 0;
    REP (i, SZ(s)) {
        res *= N;
        res += s[i] - '0';
    }
    return res;
}

//--------------------------------
//10進数をN進数の文字列に。
// l：0以上の整数
string _10toN(long long l, int N){
    if (l == 0) return "0";
    string res = "";
    while(l != 0){
        stringstream ss;
        ss << l % N;
        string tmp;
        ss >> tmp;
        res = tmp + res;
        l /= N;
    }
    return res;
}

//--------------------------------
//素数判定。
// l：0以上の整数
bool isPrime(long long l)
{
    if(l==0 || l==1 ) return false;
    if(l==2) return true;
    if(l%2==0) return false;
    for(int i=3;i<=l/2;i+=2)
        if(l%i == 0 )
            return false;
    return true; 
}


namespace unittest {
	int  run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
            cout << endl;
			return;
		}
        
		int total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) break;
            cout << endl;
			++total;
		}
        
		if (total == 0) {
			cerr << "No test cases run." << endl;
		}
	}
    
	int run_test_case(int casenum__) {
		switch (casenum__) {
            case 0 : {
                OUT(_isPow2(16));
                OUT(_isPow2(1024));
                OUT(_isPow2(1));
                OUT(_isPow2(0));
                OUT(_isPow2(5));
                OUT(_isPow2(1023));
                OUT(_isPow2(-1));
                return 1;
            }
            case 1 : {
                OUT(isPow2(8192));
                OUT(isPow2(1));
                OUT(isPow2(0));
                OUT(isPow2(-1));
                OUT(isPow2(245436432));
                OUT(isPow2(_2to10("1000")));
                OUT(isPow2(_2to10("1111")));
                return 1;
            }
            case 2 : {
                OUT(_isPowN(625,5));
                OUT(_isPowN(624,5));
                OUT(_isPowN(5,5));
                OUT(_isPowN(2,5));
                OUT(_isPowN(1,5));
                OUT(_isPowN(0,5));
                OUT(_isPowN(-1,5));
                OUT(_isPowN(1024,1));
                return 1;
            }
            case 3 : {
                OUT(isPowN(144,12));
                OUT(isPowN(3000,5));
                OUT(isPowN(300,1));
                OUT(isPowN(1,234523));
                return 1;
            }
            case 4 : {
                OUT(_2to10("101"));
                OUT(_2to10("0"));
                OUT(_2to10("1"));
                OUT(_2to10("0001"));
                OUT(_2to10("1111"));
                OUT(_2to10("1000000"));
                OUT(isPowN(_2to10("10000"), 2));
                OUT(_2to10("1bcd"));
                return 1;
            }
            case 5 : {
                OUT(_10to2(5));
                OUT(_10to2(0));
                OUT(_10to2(16));
                OUT(_10to2(24));
                OUT(_10to2(255));
                //OUT(_10to2(-1));
                return 1;
            }
            case 6 : {
                OUT(Nto10(2,"101"));
                OUT(Nto10(2,"1000"));
                OUT(Nto10(3,"2012"));
                OUT(Nto10(8,"2705"));
                OUT(Nto10(9,"0010"));
                return 1;
            }
            case 7 : {
                OUT(_10toN(59, 3));
                OUT(_10toN(1477, 8));
                OUT(_10toN(0, 8));
                OUT(_10toN(1, 8));
                return 1;
            }
            case 8 : {
                string s("abcdefg");
                OUT(s.find("c"));
                OUT(s.find("def"));
                int a = s.find("df");
                OUT(a);
                //if (s.find("ag") == -1) OUT("1");
                return 1;
            }
            case 9 : {
                VI a;
                a.PB(4);
                a.PB(-100);
                a.PB(200);
                a.PB(50);
                FIT(it, a) OUT(*it);
                cout << endl;
                sort(ALL(a));
                FIT(it, a) OUT(*it);
                cout << endl;
                sort(ALL(a), greater<int>());
                FIT(it, a) OUT(*it);
                cout << endl;
                //int tmp = find(ALL(a), 50);
                
                
                
                
                return 1;
            }
            case 999 : {
                return 1;
            }
            default : return -1;
		}
	}
}


int main(int argc, char *argv[]) {
    cout << endl;
	if (argc == 1) {
		unittest::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			unittest::run_test(atoi(argv[i]));
	}
}
