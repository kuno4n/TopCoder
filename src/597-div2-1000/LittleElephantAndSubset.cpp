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
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
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

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset((x), (a), (int)sizeof(x))
#define VI vector < int >
#define LL long long 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = " << A << endl
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }


const int MOD = 1000000007;
LL dp[1<<10];
LL cnt[1<<10];
int n;

void add(LL &a, LL b){
    a = (a + b) % MOD;
}

void dfs(LL val, int mask){
    if(val > n) return;
    cnt[mask]++;
    REP(i, 10) if(!(mask & (1<<i))) dfs(val*10 + i, (mask|(1<<i)));
}

int rec(int mask){
    if(mask == 0) return 1;
    if(dp[mask] >= 0) return dp[mask];
    LL res = 0;
    int a = 1;
    while(a*2 <= mask) a *= 2;
    REP(i, a) if(((a+i) & mask) == a+i){
        add(res, cnt[a+i] * rec(mask - (a+i)));
    }
    return dp[mask] = res;
}

class LittleElephantAndSubset {
	public:
	int getNumber(int N) {
		n = N;
        MSET(cnt, 0);
        for(int i = 1; i < 10; i++) dfs(i, (1<<i));
        LL res = 0;
        MSET(dp, -1);
        for(int i = 1; i < (1<<10); i++) add(res, rec(i));
        return res;
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
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
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
			int N                     = 3;
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = LittleElephantAndSubset().getNumber(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 10;
			int expected__            = 767;

			clock_t start__           = clock();
			int received__            = LittleElephantAndSubset().getNumber(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 47;
			int expected__            = 25775;

			clock_t start__           = clock();
			int received__            = LittleElephantAndSubset().getNumber(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 4777447;
			int expected__            = 66437071;

			clock_t start__           = clock();
			int received__            = LittleElephantAndSubset().getNumber(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LittleElephantAndSubset().getNumber(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LittleElephantAndSubset().getNumber(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LittleElephantAndSubset().getNumber(N);
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
// 
Little Elephant from the Zoo of Lviv has a set S. The set S contains the integers 1, 2, 3, ..., N. He considers some non-empty subset of S cool if we can write down all elements of the subset by using each of the digits 0-9 at most once.




Examples:
The subsets {12,345,67890} and {47,109} are cool.
The subset {147,342} is not cool because the digit 4 is used twice.
The subset {404} is not cool for the same reason.




You are given the int N. Let X be the total number of non-empty cool subsets of S. Return the value (X modulo 1,000,000,007).


DEFINITION
Class:LittleElephantAndSubset
Method:getNumber
Parameters:int
Returns:int
Method signature:int getNumber(int N)


CONSTRAINTS
-N will be between 1 and 1,000,000,000 (10^9), inclusive.


EXAMPLES

0)
3

Returns: 7

All 7 non-empty subsets are cool in this case:


{1, 2, 3}


{1, 2}


{1, 3}


{2, 3}


{1}


{2}


{3}



1)
10

Returns: 767

In this case, the total number of non-empty subsets is 2^10-1 = 1023. The only not cool subsets are those that contain both 1 and 10. There are 2^8 = 256 of them. Thus, the answer is 1023-256 = 767.

2)
47

Returns: 25775



3)
4777447

Returns: 66437071



*/

// END CUT HERE
