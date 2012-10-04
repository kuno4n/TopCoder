
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
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define OUT(A) std::cout << #A << '='<<A << std::endl;

int _isPow2(long long l);
bool isPow2(long long l);
int _isPowN(long long l, int N);
bool isPowN(long long l, int N);
long long _2to10(string s);
string _10to2(long long l);
long long Nto10(int N, string s);

//--------------------------------
// l��2�ׂ̂���ł���΁A���̎w����Ԃ��B0�������B
// �����łȂ���΁A-1��Ԃ��B
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
// 2�ׂ̂��悩�ǂ����̍�������B
// 0���true�B
bool isPow2(long long l){
	if (l <= 0) return false;
	else if (l & (l-1)) return false;
	else return true;
}

//--------------------------------
// N�F2�ȏ�̐���
// l��N�ׂ̂���ł���΁A���̎w����Ԃ��B0�������B
// �����łȂ���΁A-1��Ԃ��B
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
// 0��ł�true�Ƃ������ꍇ�B
bool isPowN(long long l, int N){
	if (_isPowN(l, N) == -1) return false;
	else return true;
}

//--------------------------------
//2�i����10�i���ɁB
// s�F0��1����Ȃ镶����
long long _2to10(string s){
	long long res = 0;
	REP (i, SZ(s)) {
		res <<= 1;
		if (s[i] == '1') res++;
	}
	return res;
}

//--------------------------------
//10�i����2�i���ɁB
// l�F0�ȏ�̐���
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
//N�i���̕�����s����10�i���ɁB
// N�F2�`9�̎��R��
// s�F0�`N-1����Ȃ镶����
long long Nto10(int N, string s){
	long long res = 0;
	REP (i, SZ(s)) {
		res *= N;
		res += s[i] - '0';
	}
	return res;
}

//--------------------------------
//10�i����N�i���̕�����ɁB
// l�F0�ȏ�̐���
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



namespace unittest {
	int  run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}

		int total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) break;
			++total;
		}

		if (total == 0) {
			cerr << "No test cases run." << endl;
		} 
	}

	int run_test_case(int casenum__) {
		cout << endl;
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
		default : return -1;
		}
	}
}


int main(int argc, char *argv[]) {
	if (argc == 1) {
		unittest::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			unittest::run_test(atoi(argv[i]));
	}
	}
