
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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

int n;
VI child[60];
int parent[60];
int grundy[60];

bool isAns(int target, int now){
	if(target == now) return true;
	if(now == -1) return false;
	return isAns(target, parent[now]);
}

int make(int node){
	if(grundy[node] != -1) return grundy[node];
	set<int> s;
	REP(i, n) if(isAns(node, i)){
		int g = 0;
		for(int j = i, prv = -1;; prv = j, j = parent[j]){
			REP(k, SZ(child[j])) if(child[j][k] != prv) g ^= make(child[j][k]);
			if(j == node) break;
		}
		s.insert(g);
	}
	int cnt = 0;
	for(; s.count(cnt); cnt++);
	return grundy[node] = cnt;
}


class CirclesGame {
public:
   string whoCanWin( vector <int> x, vector <int> y, vector <int> r ) {
	n = SZ(x);
	REP(i, 60) child[i].clear();
	REP(i, 60) parent[i] = -1;
	REP(i, n){
		int tmp = -1;
		REP(j, n) if(r[j] > r[i] && r[j]*r[j] > (x[j]-x[i])*(x[j]-x[i]) + (y[j]-y[i])*(y[j]-y[i])){
			if(tmp == -1 || r[tmp] > r[j]) tmp = j;
		}
		parent[i] = tmp;
		if(tmp != -1) child[tmp].PB(i);
	}

	REP(i, 60) grundy[i] = -1;
	REP(i, n) make(i);
	int res = 0;
	REP(i, n) if(parent[i] == -1) res ^= grundy[i];
	return (res == 0 ? "Bob" : "Alice");
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int x[]                   = {0};
			int y[]                   = {0};
			int r[]                   = {1};
			string expected__         = "Alice";

			clock_t start__           = clock();
			string received__         = CirclesGame().whoCanWin(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {0, 3};
			int y[]                   = {0, 0};
			int r[]                   = {1, 1};
			string expected__         = "Bob";

			clock_t start__           = clock();
			string received__         = CirclesGame().whoCanWin(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {0, 0, 5};
			int y[]                   = {0, 0, 0};
			int r[]                   = {1, 2, 1};
			string expected__         = "Alice";

			clock_t start__           = clock();
			string received__         = CirclesGame().whoCanWin(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {0, 0, 0, 10, 10, 20};
			int y[]                   = {0, 0, 0, 0, 0, 0};
			int r[]                   = {1, 2, 3, 1, 2, 1};
			string expected__         = "Bob";

			clock_t start__           = clock();
			string received__         = CirclesGame().whoCanWin(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {10,20,30,40,50,60,70,80};
			int y[]                   = {8,7,6,5,4,3,2,1};
			int r[]                   = {2,2,2,2,2,2,2,2};
			string expected__         = "Bob";

			clock_t start__           = clock();
			string received__         = CirclesGame().whoCanWin(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int x[]                   = {0, 3, 6, 9, 12, -4747, -4777};
			int y[]                   = {-5858, -5858, -5858, -5858, -5858, 777, 777};
			int r[]                   = {58, 1, 1, 1, 1, 44, 8};
			string expected__         = "Bob";

			clock_t start__           = clock();
			string received__         = CirclesGame().whoCanWin(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int x[]                   = {5202, 5699, -7433, 5068, -9483, -684, -6593, 5108, -7813, 6823, 3267, -8222, -8547, 2878, 2413, 8557, 5149, 5073, -8638, -6108, 8097};
			int y[]                   = {8728, -7407, 4338, -8414, 7652, -3705, -984, 5976, -9180, -9119, 9301, 2398, 7915, 6205, 7665, 717, -9884, 11, -8579, -6903, -746};
			int r[]                   = {4196, 9303, 7152, 5875, 2943, 788, 502, 416, 1958, 3174, 182, 1256, 1147, 444, 979, 65, 1040, 1233, 438, 175, 1140};
			string expected__         = "Alice";

			clock_t start__           = clock();
			string received__         = CirclesGame().whoCanWin(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			int r[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CirclesGame().whoCanWin(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int x[]                   = ;
			int y[]                   = ;
			int r[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CirclesGame().whoCanWin(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int x[]                   = ;
			int y[]                   = ;
			int r[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CirclesGame().whoCanWin(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
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
// Alice is playing a game with her old friend, Bob.

There are n circles on a paper. The center of the i-th circle is (x[i], y[i]), and the radius is r[i].
No two different circles share a common point on their boundary.
However, it is allowed for circles to be located entirely within other circles.
In the game, the players take alternating turns.
Alice starts.
In each move, the current player must:

Choose a circle such that there is no red point strictly inside the circle.
Pick one point that is strictly inside the chosen circle and color it red.

If a player can't do such a move, he/she loses the game.

You are given the vector <int>s x, y, and r that describe a set of circles with the above property.
Return "Alice" (quotes for clarity) if Alice has a winning strategy for the given set of circles.
Otherwise, return "Bob".


DEFINITION
Class:CirclesGame
Method:whoCanWin
Parameters:vector <int>, vector <int>, vector <int>
Returns:string
Method signature:string whoCanWin(vector <int> x, vector <int> y, vector <int> r)


NOTES
-Points located on the boundary of a circle are not considered to be strictly inside that circle.


CONSTRAINTS
-x will contain between 1 and 50 elements, inclusive.
-x, y, and r will each contain the same number of elements.
-Each element in x will be between -10,000 and 10,000, inclusive.
-Each element in y will be between -10,000 and 10,000, inclusive.
-Each element in r will be between 1 and 10,000, inclusive.
-No two circles intersect. That is, the boundaries of the given circles are pairwise disjoint.


EXAMPLES

0)
{0}
{0}
{1}

Returns: "Alice"

This test case has just one circle. Alice draws a red point anywhere inside the circle and Bob has no valid move.

1)
{0, 3}
{0, 0}
{1, 1}

Returns: "Bob"

Two separate circles. Alice draws a red point in one of them, Bob draws a red point in another one, then Alice has no valid moves.

2)
{0, 0, 5}
{0, 0, 0}
{1, 2, 1}

Returns: "Alice"

In her first move, Alice should draw a point within the circle 1, but so that it's not within the circle 0. (Both indices are 0-based.)

3)
{0, 0, 0, 10, 10, 20}
{0, 0, 0, 0, 0, 0}
{1, 2, 3, 1, 2, 1}

Returns: "Bob"



4)
{10,20,30,40,50,60,70,80}
{8,7,6,5,4,3,2,1}
{2,2,2,2,2,2,2,2}

Returns: "Bob"



5)
{0, 3, 6, 9, 12, -4747, -4777}
{-5858, -5858, -5858, -5858, -5858, 777, 777}
{58, 1, 1, 1, 1, 44, 8}

Returns: "Bob"



6)
{5202, 5699, -7433, 5068, -9483, -684, -6593, 5108, -7813, 6823, 3267, -8222, -8547, 2878, 2413, 8557, 5149, 5073, -8638, -6108, 8097}
{8728, -7407, 4338, -8414, 7652, -3705, -984, 5976, -9180, -9119, 9301, 2398, 7915, 6205, 7665, 717, -9884, 11, -8579, -6903, -746}
{4196, 9303, 7152, 5875, 2943, 788, 502, 416, 1958, 3174, 182, 1256, 1147, 444, 979, 65, 1040, 1233, 438, 175, 1140}

Returns: "Alice"

*/

// END CUT HERE
