
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

const int INF = (1<<29);

long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

class AstronomicalRecords {
public:
   int minimalPlanets( vector <int> A, vector <int> B ) {
	int na = SZ(A), nb = SZ(B);
	
	int ga[na][nb], gb[na][nb];
	REP(i, na) REP(j, nb){
		int g = gcd(A[i], B[j]);
		ga[i][j] = A[i] / g;
		gb[i][j] = B[j] / g;
	}
	
	int dp[na][nb];
	REP(i, na) REP(j, nb) dp[i][j] = i + j + 1;
	
	REP(i, na) REP(j, nb) REP(k, i) REP(l, j)
		if(ga[i][j] == ga[k][l] && gb[i][j] == gb[k][l])
			chmin(dp[i][j], dp[k][l] + (i-k) + (j-l) - 1);
	
	int res = INF;
	REP(i, na) REP(j, nb) chmin(res, dp[i][j] + (na-i-1) + (nb-j-1));
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
			int A[]                   = {1,2,1,2,1};
			int B[]                   = {2,1,2,1,2};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = AstronomicalRecords().minimalPlanets(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A[]                   = {1,2,3,4};
			int B[]                   = {2,4,6,8};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = AstronomicalRecords().minimalPlanets(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A[]                   = {2,3,2,3,2,3,2};
			int B[]                   = {600,700,600,700,600,700,600};
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = AstronomicalRecords().minimalPlanets(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int A[]                   = {1,2,3,4,5,6,7,8,9};
			int B[]                   = {6,7,8,9,10,11,12};
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = AstronomicalRecords().minimalPlanets(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int A[]                   = {100000000,200000000};
			int B[]                   = {200000000,100000000};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = AstronomicalRecords().minimalPlanets(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int A[]                   = {6,6,6,6,7};
			int B[]                   = {6,7,6,6,6};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = AstronomicalRecords().minimalPlanets(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
			int A[]                   = {3,4,6,8,10};
			int B[]                   = {5,7,6,9,12,15};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = AstronomicalRecords().minimalPlanets(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AstronomicalRecords().minimalPlanets(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
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
// Fox Ciel found two astronomical records.
They both describe the same solar system.
Each planet in the system can be characterized by two parameters each being a positive number: planet's size and the distance at which it orbits the sun.
All orbital distances are pairwise distinct, but sizes of some planets may be the same.



The first record is a vector <int> A with x elements.
These elements give the relative sizes of some x planets in the solar system.
Formally, the sizes of those planets have the ratio A[0] : A[1] : ... : A[x-1].
The planets described by A are ordered by their distance from the sun.
(That is, earlier elements of A correspond to planets that are closer to the sun.)



The second record is a vector <int> B with y elements.
These elements give the relative sizes of some y planets in the solar system.
Formally, the sizes of those planets have the ratio B[0] : B[1] : ... : B[y-1].
The planets described by B are ordered by their distance from the sun.



Note that the planets considered by a record do not have to be consecutive.
For example, if a solar system contains the planets P, Q, R, S, T, and U, it is possible that the first record compares P, R, and S, and the second record compares Q, R, T, and U.



We assume that both records are correct.
Return the smallest possible total number of planets in the solar system.

DEFINITION
Class:AstronomicalRecords
Method:minimalPlanets
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minimalPlanets(vector <int> A, vector <int> B)


CONSTRAINTS
-A will contain between 2 and 50 elements, inclusive.
-B will contain between 2 and 50 elements, inclusive.
-Each element in A will be between 1 and 1,000,000,000, inclusive.
-Each element in B will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{1,2,1,2,1}
{2,1,2,1,2}

Returns: 6

There have to be at least 5 planets, because each record compares 5 of them.
There cannot be exactly 5 planets, because the first one would have to be both smaller than and larger than the second one.
(Their ratio would have to be both 1:2 and 2:1, which is impossible.)
There can be exactly 6 planets with relative sizes 1,2,1,2,1,2.

1)
{1,2,3,4}
{2,4,6,8}

Returns: 4

There can be only 4 planets because 1:2:3:4 = 2:4:6:8.

2)
{2,3,2,3,2,3,2}
{600,700,600,700,600,700,600}

Returns: 10



3)
{1,2,3,4,5,6,7,8,9}
{6,7,8,9,10,11,12}

Returns: 12



4)
{100000000,200000000}
{200000000,100000000}

Returns: 3



*/

// END CUT HERE
