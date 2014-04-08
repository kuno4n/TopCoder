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

const double EPS = 1e-8;
typedef vector<double> vec;
typedef vector<vec> mat;

vec gauss_jordan(const mat& A, const vec& b){
    int n = SZ(A);
    mat B(n, vec(n + 1));
    REP(i, n) REP(j, n) B[i][j] = A[i][j];
    REP(i, n) B[i][n] = b[i];
    
    REP(i, n){
        int pivot = i;
        FOR(j, i, n) if(abs(B[j][i]) > abs(B[pivot][i])) pivot = j;
        swap(B[i], B[pivot]);
        if(abs(B[i][i]) < EPS) return vec();
        for(int j = i + 1; j <= n; j++) B[i][j] /= B[i][i];
        REP(j, n) if(i != j) for(int k = i + 1; k <= n; k++) B[j][k] -= B[j][i] * B[i][k];
    }
    vec x(n);
    REP(i, n) x[i] = B[i][n];
    return x;
}

class TorusSailingEasy {
public:
   double expectedTime( int N, int M, int goalX, int goalY ) {
       int t, x, y, a;
       t = x = y = 0;
       a = -1;
       do{
           t++;
           x++;
           y++;
           x %= N;
           y %= M;
           if(x == goalX && y == goalY) a = t;
       }while(!(x == 0 && y == 0));
       if(a == -1) return -1.0;
       
       // !!!
       return a*(t-a);

       mat A(t, vec(t));
       REP(i, t){
           REP(j, t) A[i][j] = 0.0;
           if(i == a) A[i][i] = 1.0;
           else{
               A[i][i] = 2.0;
               A[i][(i-1+t)%t] = -1.0;
               A[i][(i+1)%t] = -1.0;
           }
       }
       vec b(t, 2.0);
       b[a] = 0.0;
       
       vec res = gauss_jordan(A, b);
       return res[0];
       
//       int l = 0;
//       int r = 0;
//       srand((unsigned int)time(NULL));
//       REP(_, 100000){
//           int pos = 0;
//           int prv = 0;
//           while(1){
//               if(pos == 33){
//                   if(prv == 32) l++;
//                   else r++;
//                   break;
//               }
//               prv = pos;
//               if(rand() & 1) pos = (pos + 1) % 100;
//               else pos = (pos - 1 + 100) % 100;
//           }
//       }
//       OUT2(l, r);
//       
//       
//       int t, x, y, a;
//       t = x = y = 0;
//       a = -1;
//       do{
//           t++;
//           x++;
//           y++;
//           x %= N;
//           y %= M;
//           if(x == goalX && y == goalY) a = t;
//       }while(!(x == 0 && y == 0));
//       if(a == -1) return -1.0;
//
//       MSET(dp, 0);
//       dp[0][0] = 1.0;
//       double res = 0;
//       REP(i, 100000){
//           res += dp[i][a]*i;
//           REP(j, t) if(j != a){
//               dp[i+1][(j+1)%t] += dp[i][j]/2;
//               dp[i+1][(j-1+t)%t] += dp[i][j]/2;
//           }
//       }
//       return res;
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int N                     = 2;
			int M                     = 2;
			int goalX                 = 1;
			int goalY                 = 1;
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = TorusSailingEasy().expectedTime(N, M, goalX, goalY);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 2;
			int M                     = 2;
			int goalX                 = 0;
			int goalY                 = 1;
			double expected__         = -1.0;

			clock_t start__           = clock();
			double received__         = TorusSailingEasy().expectedTime(N, M, goalX, goalY);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 3;
			int M                     = 3;
			int goalX                 = 1;
			int goalY                 = 1;
			double expected__         = 2.0;

			clock_t start__           = clock();
			double received__         = TorusSailingEasy().expectedTime(N, M, goalX, goalY);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 4;
			int M                     = 6;
			int goalX                 = 1;
			int goalY                 = 3;
			double expected__         = 27.0;

			clock_t start__           = clock();
			double received__         = TorusSailingEasy().expectedTime(N, M, goalX, goalY);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			int M                     = ;
			int goalX                 = ;
			int goalY                 = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TorusSailingEasy().expectedTime(N, M, goalX, goalY);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			int M                     = ;
			int goalX                 = ;
			int goalY                 = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TorusSailingEasy().expectedTime(N, M, goalX, goalY);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int M                     = ;
			int goalX                 = ;
			int goalY                 = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TorusSailingEasy().expectedTime(N, M, goalX, goalY);
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
Fox Ciel is sailing in the Donut sea. The Donut sea is a torus. For navigation, the torus is divided into N times M cells, as shown in the figure below.




(Image by YassineMrabet from Wikimedia Commons, licensed under CC BY-SA 3.0.)



Each of the cells has two integer coordinates (n, m), where 0 <= n < N and 0 <= m < M. Note that the coordinates wrap around modulo N and M. For example, if you are in the cell (N-1, M-1) and you cross over one of its sides, you will reach one of the cells (N-2, M-1), (0, M-1), (N-1, M-2), and (N-1, 0).



Ciel starts in the cell (0, 0) and wants to reach the goal cell (goalX, goalY).



Unfortunately, Ciel's navigation is very poor. Whenever she moves to a new cell, there are two equally probable outcomes: either both of her coordinates increase by 1, or both of them decrease by 1 (wrapping around if necessary). Formally, if Ciel's current coordinates are (n, m), her new coordinates will be either ((n+1) modulo N, (m+1) modulo M), or ((n-1) modulo N, (m-1) modulo M), with equal probability. Each such move takes one day.



If Ciel can never reach her goal, return -1. Otherwise, return the expected number of days Ciel will need to reach her goal.



DEFINITION
Class:TorusSailingEasy
Method:expectedTime
Parameters:int, int, int, int
Returns:double
Method signature:double expectedTime(int N, int M, int goalX, int goalY)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.
-In many programming languages the modulo operator returns negative values for negative inputs. If you are using such a language, it is safer to use the formulas ((n-1+N) modulo N) and ((m-1+M) modulo M) to compute Ciel's new coordinates when both of them are supposed to decrease.
-Informally, the expected value of a random variable can be seen as its average over very many trials.


CONSTRAINTS
-N will be between 2 and 10, inclusive.
-M will be between 2 and 10, inclusive.
-goalX will be between 0 and N - 1, inclusive.
-goalY will be between 0 and M - 1, inclusive.
-(goalX, goalY) will not be (0, 0).


EXAMPLES

0)
2
2
1
1

Returns: 1.0

She will always reach the goal in 1 day.

1)
2
2
0
1

Returns: -1.0

It is impossible to reach the goal. Ciel will only visit the cells (0, 0) and (1, 1) alternately.

2)
3
3
1
1

Returns: 2.0

She can reach the goal in 1 day with probability 1/2, in 2 days with probability 1/4, in 3 days with probability 1/8, in 4 days with probability 1/16 and so on. In general, she can reach the goal in n days with probability 1/(2^n) where n is a positive integer.

The answer is (1 * 1/2) + (2 * 1/4) + (3 * 1/8) + (4 * 1/16) + ... = 2.0.


3)
4
6
1
3

Returns: 27.0



*/

// END CUT HERE
