#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <sys/time.h>
#include <fstream>
//#include "cout.h"

using namespace std;

//#define SZ(x) ((int)x.size())
//#define MSET(x,a) memset(x, a, (int)sizeof(x))
//#define PB push_back
//#define VI vector < int >
//#define PII pair < int, int >
//#define LL long long
//#define FOR(i,a,b) for (int i = (a); i < (b); i++)
//#define REP(i,n) FOR(i,0,n)
//#define ALL(v) (v).begin(), (v).end()
//#define FIT(it,v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())


const int MOD = 1000000007;


// x^y (�ŏ����@)
int modPow(long long x, long long y){
    long long r = 1, a = x % MOD;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        y /= 2;
    }
    return r;
}

// n!
int modFact(int n){
    long long res = 1;
    while(n > 1) res = (res * n--) % MOD;
    return res;
}

// x��MOD��ł̋t���iMOD���f���̏ꍇ�j
int modInverse(long long x){
    return modPow(x, MOD-2);
}

int modDivision(long long p, long long q){
    return ((p%MOD) * modInverse(q)) % MOD;
}




long long C[1010][1010];

void make_C(){
	memset(C, 0, (int)sizeof(C));
	
	for(int i = 0; i < 1010; i++){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
	}
}



long long dp[1010][1010];


// S(n, m) = S(n-1, m) * m + S(n-1, m-1) * m
int count1_1(int n, int m){
	if(n < m) return 0;
	
	memset(dp, 0, (int)sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			
			// i-1�̃{�[����j�̔��ɓ����Ă����ԂŁAi�ڂ̃{�[��������ꍇ
			dp[i][j] += dp[i-1][j] * j;
			
			// i-1�̃{�[����j-1�̔��ɓ����Ă����ԂŁAi�ڂ̃{�[���͐V�������ɓ����ꍇ
			dp[i][j] += dp[i-1][j-1] * j;
			
			dp[i][j] %= MOD;
		}
	}
	
	return dp[n][m];
}

// �����
int count1_2(int n, int m){
	if(n < m) return 0;
	
	long long res = 0;
	
	for(int i = 1; i <= m; i++){
		long long tmp = (C[m][i] * modPow(i, n)) % MOD;
		if((m-i)&1) res = (res - tmp + MOD) % MOD;
		else res = (res + tmp) % MOD;
	}
	return res;
}

// mPn
int count2(int n, int m){
	if(n > m) return 0;
	
	long long res = 1;
	while(n--) res = (res * m--) % MOD;
	return res;
}

// m^n
int count3(int n, int m){
	return modPow(m, n);
}

// ����X�^�[�����O���ƌĂ΂��
// S(n, m) = S(n-1, m) * m + S(n-1, m-1)
int count4_1(int n, int m){
	if(n < m) return 0;
	
	memset(dp, 0, (int)sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			
			// i-1�̃{�[����j�̔��ɓ����Ă����ԂŁAi�ڂ̃{�[��������ꍇ�B���̏ꍇ��j�ʂ��ʂł���B
			dp[i][j] += dp[i-1][j] * j;
			
			// i-1�̃{�[����j-1�̔��ɓ����Ă����ԂŁAi�ڂ̃{�[���͐V�������ɓ����ꍇ�B���̏ꍇ�͋�ʂł��Ȃ��B
			dp[i][j] += dp[i-1][j-1];
			
			dp[i][j] %= MOD;
		}
	}
	
	return dp[n][m];
}

int count4_2(int n, int m){
	if(n < m) return 0;
	return modDivision(count1_1(n, m), modFact(m));
}

int count5(int n, int m){
	if(n > m) return 0;
	return 1;
}

int count6_1(int n, int m){
	// count4_1 �Ɠ��l��dp��O�����Ď��{
	memset(dp, 0, (int)sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] += dp[i-1][j] * j;
			dp[i][j] += dp[i-1][j-1];			
			dp[i][j] %= MOD;
		}
	}
	
	// count4_1�ɂ�����u����1�̏ꍇ�v�u����2�̏ꍇ�v�c�c�u����m�̏ꍇ�v�𑫂�
	long long res = 0;
	for(int i = 1; i <= m; i++) res = (res + dp[n][i]) % MOD;
	return res;
}


long long dp_tmp[1010][1010];

int count6_2(int n, int m){
	memset(dp_tmp, 0, (int)sizeof(dp_tmp));
	
	// count4_1 �Ɠ��l��dp��O�����Ď��{
	dp_tmp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp_tmp[i][j] += dp_tmp[i-1][j] * j;
			dp_tmp[i][j] += dp_tmp[i-1][j-1];
			dp_tmp[i][j] %= MOD;
		}
	}
	
	// �{�v�Z�B
	// �Ⴆ�΁Adp[10][7] ���v�Z����Ƃ��́A
	// dp[10][6]�i���̒��ɁA���P�g���`���U�g���A���S�Ċ܂܂�Ă���j�ƁA
	// dp_tmp[10][7]�i�������傤�ǂV�g���j�𑫂��Ηǂ��B
	memset(dp, 0, (int)sizeof(dp));
	for(int i = 1; i <= n; i++){
		 for(int j = 1; j <= m; j++){
			dp[i][j] += dp[i][j-1];
			dp[i][j] += dp_tmp[i][j];
			dp[i][j] %= MOD;
		}
	}
	return dp[n][m];
}

// �x����
long long dp_bell[1010];

int bellNumber(int n){
	memset(dp_bell, 0, (int)sizeof(dp_bell));
	dp_bell[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= i-1; j++){
			dp_bell[i] = (dp_bell[i] + (C[i-1][j] * dp_bell[j])) % MOD;
		}
	}
	return dp_bell[n];
}

int count7(int n, int m){
	if(n < m) return 0;
	return C[n-1][m-1];
	// ������ł��ł���͂��ł�
}

int count8(int n, int m){
	if(n > m) return 0;
	return C[m][n];
}

// nHm
int count9_1(int n, int m){
	// �͈͊O�A�N�Z�X�ɒ��ӂ��ĉ�����
	return C[n+m-1][m-1];
}

int count9_2(int n, int m){
	memset(dp, 0, (int)sizeof(dp));
	dp[0][0] = 1;
	// O((n^2)*m) �ł�
	for(int i = 0; i <= n; i++){
		 for(int j = 1; j <= m; j++){
			for(int k = 0; k <= i; k++){
				// j�Ԗڂ̔��ɂ�k�����B���vi�ɂȂ�悤�ɁB
				dp[i][j] = (dp[i][j] + dp[i-k][j-1]) % MOD;
			}
		}
	}
	return dp[n][m];
}

int count10(int n, int m){
	if(n < m) return 0;
	
	memset(dp, 0, (int)sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			
			// �{�[��1�̔������Ȃ��Ƃ�1����ꍇ�B
			// 1���ɓ���āA�c��i-1��j-1�̔��ɕ�����B
			dp[i][j] += dp[i-1][j-1];
			
			// �{�[��1�̔��������ꍇ�B
			// �܂�1�ÂAj�̔��ɓ���Ă��܂��B�c��i-j��j�̔��ɕ�����B 
			if(i >= j) dp[i][j] += dp[i-j][j];
			
			dp[i][j] %= MOD; 
		}
	}
	return dp[n][m];
}

int count11(int n, int m){
	if(n > m) return 0;
	return 1;
}

// n��m�����B
// n = m�̂Ƃ��A����n�̕������Ƃ����B

int count12_1(int n, int m){
	// �܂�count10�Ɠ��l��dp
	memset(dp, 0, (int)sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] += dp[i-1][j-1];
			if(i >= j) dp[i][j] += dp[i-j][j];
			dp[i][j] %= MOD; 
		}
	}
	
	// 1�`m��sum���Ƃ�
	long long res = 0;
	for(int i = 1; i <= m; i++) res = (res + dp[n][i]) % MOD;
	return res;
}

// �a�{�ɋL�ڂ���Ă����肩��
int count12_2(int n, int m){
	memset(dp, 0, (int)sizeof(dp));
	dp[0][0] = 1;
	for(int i = 0; i <= n; i++){
		for(int j = 1; j <= m; j++){
			
			// j-1�ȉ��̔��ɓ����ꍇ
			dp[i][j] += dp[i][j-1];
			
			// �K��j�g���ꍇ�i�ŏ��Ɉ�Â���Ă��܂��j�j
			if(i >= j) dp[i][j] += dp[i-j][j];
			
			dp[i][j] %= MOD; 
		}
	}
	return dp[n][m];
}

long long dp_omake[1000010];
int count_omake(int n){
	memset(dp_omake, 0, (int)sizeof(dp_omake));
	dp_omake[1] = 0;
	dp_omake[2] = 1;
	
	for(int i = 3; i <= n; i++){
		
		// �܂��Ai�Ԃ̃{�[����1�`i-1�̂ǂꂩ�̔��ɓ����
		// �i�����i-1�ʂ�j�ik�Ԃ̔��ɓ��ꂽ�Ƃ���j
		
		// dp[i-2] �́Ak�Ԃ̃{�[����i�Ԃ̔��ɓ��ꂽ���B
		
		// dp[i-1] �́Ak�Ԃ̃{�[����i�Ԃ̔��ɓ���Ȃ����B
		// ���̂Ƃ��A1�`i-1�Ԃ̃{�[���S�āA������Ȃ�����1����킯������A����dp[i-1]�ƂȂ�B
		
		dp_omake[i] = ((i-1) * ((dp_omake[i-2] + dp_omake[i-1]) % MOD)) % MOD;
		
	}
	return dp_omake[n];
}


int main() {
	int n, m, c;
	cin >> c >> n >> m;
	
	make_C();
	
	switch(c){
		case 1:
			OUT(count1_1(n, m));
			OUT(count1_2(n, m));
			break;
		case 2:
			OUT(count2(n, m));
			break;
		case 3:
			OUT(count3(n, m));
			break;
		case 4:
			OUT(count4_1(n, m));
			OUT(count4_2(n, m));
			break;
		case 5:
			OUT(count5(n, m));
			break;
		case 6:
			OUT(count6_1(n, m));
			OUT(count6_2(n, m));
			OUT(bellNumber(n));
			break;
		case 7:
			OUT(count7(n, m));
			break;
		case 8:
			OUT(count8(n, m));
			break;
		case 9:
			OUT(count9_1(n, m));
			OUT(count9_2(n, m));
			break;
		case 10:
			OUT(count10(n, m));
			break;
		case 11:
			OUT(count11(n, m));
			break;
		case 12:
			OUT(count12_1(n, m));
			OUT(count12_2(n, m));
		case 13:
			OUT(count_omake(n));
		default:
			break;
	}
	return 0;
}






