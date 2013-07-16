
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
//#include "cout.h"

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
#define OUT(A) cout << #A << " = "<< (A) << endl
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

long long _Pow(long long x, long long y){
    long long r=1, a=x;
    while(y > 0){
        if((y&1) == 1) r = r*a;
        a = a*a;
        y /= 2;
    }
    return r;
}


int n;
VI old, rd;

LL INF = (1LL<<58);
LL memo[1<<16][2];
bool vis[1<<16][2];

LL rec_lo(int mask, int lo_ok, int step){
	LL &res = memo[mask][lo_ok];
	if(vis[mask][lo_ok]) return res;
	vis[mask][lo_ok] = true;
	if(step == n) return res = 0;
	
	REP(i, n) if(!(mask&(1<<i))){
		int a = old[i];
		if(!lo_ok && a > old[step]) continue;
		if(a == rd[step]) continue;
		LL tmp = rec_lo(mask|(1<<i), lo_ok|(a<old[step]), step+1);
		if(tmp >= 0) chmax(res, tmp + a*_Pow(10, n-step-1));
	}
	return res;
}

LL rec_hi(int mask, int hi_ok, int step){
	LL &res = memo[mask][hi_ok];
	if(vis[mask][hi_ok]) return res;
	vis[mask][hi_ok] = true;
	if(step == n) return res = 0;
	
	REP(i, n) if(!(mask&(1<<i))){
		int a = old[i];
		if(!hi_ok && a < old[step]) continue;
		if(a == rd[step]) continue;
		LL tmp = rec_hi(mask|(1<<i), hi_ok|(a>old[step]), step+1);
		if(tmp < INF) chmin(res, tmp + a*_Pow(10, n-step-1));
	}
	return res;
}

class KingdomAndPassword {
public:
   long long newPassword( long long oldPassword, vector <int> rD ) {
	LL op = oldPassword;
	n = SZ(rD);
	rd = rD;
	old.clear();
	while(op) old.push_back(op%10), op/=10;
	reverse(ALL(old));
	
	MSET(memo, -1); MSET(vis, false);
	LL lo = rec_lo(0, 0, 0);
	
	REP(i, (1<<16)) REP(j, 2) memo[i][j] = INF; MSET(vis, false);
	LL hi = rec_hi(0, 0, 0);
	
	if(lo == -1 && hi == INF) return -1;
	if(lo == -1) return hi;
	if(hi == INF) return lo;
	if(abs(oldPassword-lo) < abs(oldPassword-hi)) return lo;
	if(abs(oldPassword-lo) > abs(oldPassword-hi)) return hi;
	return lo;
	
   }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			long long oldPassword     = 548;
			int restrictedDigits[]    = {5, 1, 8};
			long long expected__      = 485;

			clock_t start__           = clock();
			long long received__      = KingdomAndPassword().newPassword(oldPassword, vector <int>(restrictedDigits, restrictedDigits + (sizeof restrictedDigits / sizeof restrictedDigits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long oldPassword     = 7777;
			int restrictedDigits[]    = {4, 7, 4, 7};
			long long expected__      = -1;

			clock_t start__           = clock();
			long long received__      = KingdomAndPassword().newPassword(oldPassword, vector <int>(restrictedDigits, restrictedDigits + (sizeof restrictedDigits / sizeof restrictedDigits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long oldPassword     = 58;
			int restrictedDigits[]    = {4, 7};
			long long expected__      = 58;

			clock_t start__           = clock();
			long long received__      = KingdomAndPassword().newPassword(oldPassword, vector <int>(restrictedDigits, restrictedDigits + (sizeof restrictedDigits / sizeof restrictedDigits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long oldPassword     = 172;
			int restrictedDigits[]    = {4, 7, 4};
			long long expected__      = 127;

			clock_t start__           = clock();
			long long received__      = KingdomAndPassword().newPassword(oldPassword, vector <int>(restrictedDigits, restrictedDigits + (sizeof restrictedDigits / sizeof restrictedDigits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long oldPassword     = 241529363573463LL;
			int restrictedDigits[]    = {1, 4, 5, 7, 3, 9, 8, 1, 7, 6, 3, 2, 6, 4, 5};
			long long expected__      = 239676554423331LL;

			clock_t start__           = clock();
			long long received__      = KingdomAndPassword().newPassword(oldPassword, vector <int>(restrictedDigits, restrictedDigits + (sizeof restrictedDigits / sizeof restrictedDigits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			long long oldPassword     = ;
			int restrictedDigits[]    = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = KingdomAndPassword().newPassword(oldPassword, vector <int>(restrictedDigits, restrictedDigits + (sizeof restrictedDigits / sizeof restrictedDigits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long oldPassword     = ;
			int restrictedDigits[]    = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = KingdomAndPassword().newPassword(oldPassword, vector <int>(restrictedDigits, restrictedDigits + (sizeof restrictedDigits / sizeof restrictedDigits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long oldPassword     = ;
			int restrictedDigits[]    = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = KingdomAndPassword().newPassword(oldPassword, vector <int>(restrictedDigits, restrictedDigits + (sizeof restrictedDigits / sizeof restrictedDigits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}

/*
// PROBLEM STATEMENT
// King Dengklek has a special room protected by a password. The password is a positive integer that does not contain the digit zero. You are given the old password as a long long oldPassword. King Dengklek has been using this password for a long time. Now, he wants to create a new password. You are also given a vector <int> restrictedDigits. The tradition in the kingdom insists that:


The digits in the new password are a permutation of the digits in oldPassword.
For each i, the i-th most significant digit (0-based index) of the new password is not restrictedDigits[i].


Return the new password X. If there are multiple solutions, return the one for which |oldPassword - X| is minimized. If there are still two possible solutions, return the smaller one. If there is no valid new password at all, return -1 instead.

DEFINITION
Class:KingdomAndPassword
Method:newPassword
Parameters:long long, vector <int>
Returns:long long
Method signature:long long newPassword(long long oldPassword, vector <int> restrictedDigits)


NOTES
-|x| denotes the absolute value of x. For example, |3| = |-3| = 3.
-The new password may be equal to the old password (see example 2).


CONSTRAINTS
-oldPassword will be between 1 and 10^16 - 1, inclusive.
-oldPassword will not contain the digit zero.
-restrictedDigits will contain the same number of elements as the number of digits in oldPassword.
-Each element of restrictedDigits will be between 1 and 9, inclusive.


EXAMPLES

0)
548
{5, 1, 8}

Returns: 485



1)
7777
{4, 7, 4, 7}

Returns: -1

The only possible new password is 7777. Since digit 7 is restricted in two positions, this new password cannot be created.

2)
58
{4, 7}

Returns: 58



3)
172
{4, 7, 4}

Returns: 127

Both 127 and 217 are valid passwords. No other valid password is closer to 172 than these two. In this situation, King Dengklek will choose the smaller one.

4)
241529363573463
{1, 4, 5, 7, 3, 9, 8, 1, 7, 6, 3, 2, 6, 4, 5}

Returns: 239676554423331



*/

// END CUT HERE
