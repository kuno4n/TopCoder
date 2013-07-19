
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


int MOD = 1000000007;

    const int MAX_N = 2010;
    LL C[MAX_N+1][MAX_N+1];
    
    void makepas(){
        REP(i, MAX_N+1) REP(j, MAX_N+1) C[i][j] = 0;
        for(int i=1; i<=MAX_N; i++){
            C[i][0] = 1;
            C[i][i] = 1;
            for(int j=1; j<i; j++){
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
            }
        }
    }

long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

void add(LL &a, LL b){
	a = (a+b+MOD) % MOD;
}


LL dp[2010];
int gc[2010][2010];

class Spacetsk {
public:
   int countsets( int L, int H, int K ) {
	if(K == 1) return (L+1)*(H+1);
	
	makepas();
	REP(i, 2010) REP(j, 2010){
		if(j == 0) gc[i][j] = i;
		else if(i == 0) gc[i][j] = j;
		else if(i < j) gc[i][j] = gc[i][j%i];
		else gc[i][j] = gc[i%j][j];
	}
	
	LL res = 0;
	for(int y = 1; y <= H; y++){
		MSET(dp, 0);
		for(int x = 0; x <= L; x++){
			int d = gc[x][y];
			add(dp[0], C[d][K-1]);
		}
		for(int x = 1; x <= L; x++){
			dp[x] = dp[x-1];
			int d = gc[x][y];
			add(dp[x], C[d][K-1]);
			d = gc[L-x+1][y];
			add(dp[x], -C[d][K-1]);
		}
		for(int x = 0; x <= L; x++) add(res, dp[x]);
	}
	
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
			int L                     = 1;
			int H                     = 1;
			int K                     = 2;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = Spacetsk().countsets(L, H, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int L                     = 1;
			int H                     = 1;
			int K                     = 1;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = Spacetsk().countsets(L, H, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int L                     = 2;
			int H                     = 2;
			int K                     = 1;
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = Spacetsk().countsets(L, H, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int L                     = 2;
			int H                     = 2;
			int K                     = 2;
			int expected__            = 23;

			clock_t start__           = clock();
			int received__            = Spacetsk().countsets(L, H, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int L                     = 5;
			int H                     = 5;
			int K                     = 3;
			int expected__            = 202;

			clock_t start__           = clock();
			int received__            = Spacetsk().countsets(L, H, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int L                     = 561;
			int H                     = 394;
			int K                     = 20;
			int expected__            = 786097180;

			clock_t start__           = clock();
			int received__            = Spacetsk().countsets(L, H, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 6: {
			int L                     = 2000;
			int H                     = 2000;
			int K                     = 2000;
			int expected__            = 2000;

			clock_t start__           = clock();
			int received__            = Spacetsk().countsets(L, H, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int L                     = ;
			int H                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Spacetsk().countsets(L, H, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int L                     = ;
			int H                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Spacetsk().countsets(L, H, K);
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
// The spaceport is a horizontal segment of length L.
We are planning to launch a rocket from the spaceport.
The rocket must fly in a straight line.
The line does not have to be orthogonal to the spaceport, but it must lie in the vertical plane that contains the spaceport.
The line is not allowed to be strictly horizontal.


Each point in the vertical plane has two coordinates:
the x-coordinate is the horizontal distance from the left end of the spaceport, and the y-coordinate is the altitude above the spaceport.
Points for with both coordinates are integers are called grid points.


The rocket has to be launched from a grid point on the spaceport.
Moreover, after the launch the rocket must send exactly K signals.
A signal can only be sent when the rocket is at a grid point above the spaceport, and its altitude does not exceed H.


Formally:
The rocket starts from one of the points (x,0), where 0 <= x <= L and x is an integer.
The rocket may send a signal if it is at one of the points (x,y), where 0 <= x <= L, 0 <= y <= H, and x and y are both integers.
The rocket may only send at most one signal at each grid point it passes through.





The picture above shows two different test cases.
The grid on the left corresponds to L=9, H=7, and K=2.
Each of the six colors shows one pair of signals you could observe during the launch.
The small grids on the right show all four possibilities for L=1, H=1, and K=2.


You are given the ints L, H, and K.
Count how many different sets of signals are possible during the launch.
Return the answer modulo 1,000,000,007.

DEFINITION
Class:Spacetsk
Method:countsets
Parameters:int, int, int
Returns:int
Method signature:int countsets(int L, int H, int K)


CONSTRAINTS
-L will be between 1 and 2000, inclusive.
-H will be between 1 and 2000, inclusive.
-K will be between 1 and 2000, inclusive.


EXAMPLES

0)
1
1
2

Returns: 4

Example from the statement.

1)
1
1
1

Returns: 4



2)
2
2
1

Returns: 9



3)
2
2
2

Returns: 23



4)
5
5
3

Returns: 202



5)
561
394
20

Returns: 786097180

*/

// END CUT HERE
