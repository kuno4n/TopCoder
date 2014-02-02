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
VI G[55];
int n;
LL memo[55][55];
bool vis[55];


void add(LL &a, LL b){
    a = (a + b) % MOD;
}


void rec(int r){
    vis[r] = true;
    LL prv[55], nxt[55];
    MSET(prv, 0);
    prv[1] = 1;
    REP(i, SZ(G[r])){
        if(vis[G[r][i]]) continue;
        rec(G[r][i]);
        MSET(nxt, 0);
        REP(j, 55) REP(k, 55) if(j + k < 55) add(nxt[j+k], (prv[j] * memo[G[r][i]][k]) % MOD);
        REP(j, 55) prv[j] = nxt[j];
    }
    REP(i, 55) memo[r][i] = prv[i];
    memo[r][0] = 1;
}

class FoxConnection2 {
	public:
	int ways(vector <int> A, vector <int> B, int k) {
		n = SZ(A);
        
        REP(i, 55) G[i].clear();
        REP(i, n){
            G[A[i]-1].push_back(B[i]-1);
            G[B[i]-1].push_back(A[i]-1);
        }
        
        MSET(memo, 0);
        MSET(vis, false);
        rec(0);
        LL res = 0;
        REP(i, n+1) add(res, memo[i][k]);
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
			int A[]                   = {1,2,3};
			int B[]                   = {2,3,4};
			int k                     = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = FoxConnection2().ways(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A[]                   = {1,1,1,1};
			int B[]                   = {2,3,4,5};
			int k                     = 3;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = FoxConnection2().ways(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A[]                   = {1,2,3,4};
			int B[]                   = {2,3,4,5};
			int k                     = 3;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = FoxConnection2().ways(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int A[]                   = {1,2,2,4,4};
			int B[]                   = {2,3,4,5,6};
			int k                     = 3;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = FoxConnection2().ways(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int A[]                   = {1,2,2,4,4};
			int B[]                   = {2,3,4,5,6};
			int k                     = 5;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = FoxConnection2().ways(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int A[]                   = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int B[]                   = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
			int k                     = 20;
			int expected__            = 923263934;

			clock_t start__           = clock();
			int received__            = FoxConnection2().ways(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int A[]                   = {2};
			int B[]                   = {1};
			int k                     = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = FoxConnection2().ways(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int A[]                   = ;
			int B[]                   = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxConnection2().ways(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int A[]                   = ;
			int B[]                   = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxConnection2().ways(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int A[]                   = ;
			int B[]                   = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxConnection2().ways(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])), k);
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
// There are N cities in Treeland.
The cities are numbered 1 through N.
The roads in Treeland have the topology of a tree.
That is, there are exactly N-1 bidirectional roads in Treeland, each connecting a pair of cities, and it is possible to travel between any two cities along the roads.

You are given two vector <int>s A and B that describe the tree.
Each of these vector <int>s has N-1 elements.
For each valid i, there is a road that connects the cities A[i] and B[i].

Currently, k foxes live in a forest in Treeland.
They would like to move into cities.
Each fox must live in a different city.
Therefore, they must select exactly k different cities where they will live.
Additionally, they have an important constraint:
The set of cities inhabited by the foxes must be connected.
That is, for any two different cities i and j that both contain a fox, all the cities on the (only) path between i and j must also contain a fox.

Let X be the number of ways in which we can choose k cities in Treeland in such a way that the constraint is satisfied.
Return the value (X modulo 1,000,000,007).
Two selections are different if and only if there is a city selected in one of them but not in the other.
(Note that we are only selecting a set of cities, we are not assigning individual foxes to the cities.)

DEFINITION
Class:FoxConnection2
Method:ways
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int ways(vector <int> A, vector <int> B, int k)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-A will contain exactly N-1 elements.
-Each element of A will be between 1 and N, inclusive.
-B will contain exactly N-1 elements.
-Each element of B will be between 1 and N, inclusive.
-The graph described by A and B will be a tree.
-k will be between 1 and N, inclusive.


EXAMPLES

0)
{1,2,3}
{2,3,4}
2

Returns: 3

Treeland looks as follows: 1-2-3-4.
There are 3 ways to put 2 foxes: {1,2}, {2,3} or {3,4}.

1)
{1,1,1,1}
{2,3,4,5}
3

Returns: 6

There are 6 ways: {1,2,3}, {1,2,4}, {1,2,5}, {1,3,4}, {1,3,5} and {1,4,5}.

2)
{1,2,3,4}
{2,3,4,5}
3

Returns: 3



3)
{1,2,2,4,4}
{2,3,4,5,6}
3

Returns: 6



4)
{1,2,2,4,4}
{2,3,4,5,6}
5

Returns: 4



5)
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
{2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40}
20

Returns: 923263934



6)
{2}
{1}
1

Returns: 2



*/

// END CUT HERE
