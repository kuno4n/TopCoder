
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
bool G[55][55];
LL memo[55][55]; //idx, node

LL calc(int idx, int node, int parent){
//	OUT(idx); OUT(node); OUT(parent);
//	if(memo[idx][node] != -1) return memo[idx][node]; //‚¢‚ç‚È‚©‚Á‚½
	
	int n_child = 0;
	REP(i, n) if(node != i && G[node][i] && i != parent) n_child++;
	
	int i_child = 0;
	if(idx*2+1 < n) i_child++;
	if(idx*2+2 < n) i_child++;
	if(n_child != i_child) return memo[idx][node] = 0;
	if(n_child == 0) return memo[idx][node] = 1;
	
	if(n_child == 1){
		REP(i, n) if(node != i && G[node][i] && i != parent) return memo[idx][node] = calc(idx*2+1, i, node);
	}
	
	int c1 = -1, c2 = -1;
	REP(i, n) if(node != i && G[node][i] && i != parent){
		if(c1 == -1) c1 = i;
		else c2 = i;
	}
	return memo[idx][node] = calc(idx*2+1, c1, node)*calc(idx*2+2, c2, node) + calc(idx*2+1, c2, node)*calc(idx*2+2, c1, node);
	
}

class HatRack {
public:
   long long countWays( vector <int> knob1, vector <int> knob2 ) {
	n = SZ(knob1) + 1;
	MSET(G, false);
	REP(i, n-1) G[knob1[i]-1][knob2[i]-1] = G[knob2[i]-1][knob1[i]-1] = true;
	
	LL res = 0;
	REP(i, n){
		MSET(memo, -1);
		res += calc(0, i, -1);
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
			int knob1[]               = {1};
			int knob2[]               = {2};
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = HatRack().countWays(vector <int>(knob1, knob1 + (sizeof knob1 / sizeof knob1[0])), vector <int>(knob2, knob2 + (sizeof knob2 / sizeof knob2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int knob1[]               = {1,1};
			int knob2[]               = {2,3};
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = HatRack().countWays(vector <int>(knob1, knob1 + (sizeof knob1 / sizeof knob1[0])), vector <int>(knob2, knob2 + (sizeof knob2 / sizeof knob2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int knob1[]               = {1,1,1,1};
			int knob2[]               = {2,3,4,5};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = HatRack().countWays(vector <int>(knob1, knob1 + (sizeof knob1 / sizeof knob1[0])), vector <int>(knob2, knob2 + (sizeof knob2 / sizeof knob2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int knob1[]               = {6,6,6,4,1};
			int knob2[]               = {1,2,4,5,3};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = HatRack().countWays(vector <int>(knob1, knob1 + (sizeof knob1 / sizeof knob1[0])), vector <int>(knob2, knob2 + (sizeof knob2 / sizeof knob2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int knob1[]               = {1,1,2,2,11,11,8,8,3,3,4,4,5};
			int knob2[]               = {2,3,11,8,12,13,9,10,4,5,7,6,14};
			long long expected__      = 16;

			clock_t start__           = clock();
			long long received__      = HatRack().countWays(vector <int>(knob1, knob1 + (sizeof knob1 / sizeof knob1[0])), vector <int>(knob2, knob2 + (sizeof knob2 / sizeof knob2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int knob1[]               = {1,2,3,4,5,6,7,8,9};
			int knob2[]               = {2,3,4,5,6,7,8,9,10};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = HatRack().countWays(vector <int>(knob1, knob1 + (sizeof knob1 / sizeof knob1[0])), vector <int>(knob2, knob2 + (sizeof knob2 / sizeof knob2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int knob1[]               = ;
			int knob2[]               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = HatRack().countWays(vector <int>(knob1, knob1 + (sizeof knob1 / sizeof knob1[0])), vector <int>(knob2, knob2 + (sizeof knob2 / sizeof knob2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int knob1[]               = ;
			int knob2[]               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = HatRack().countWays(vector <int>(knob1, knob1 + (sizeof knob1 / sizeof knob1[0])), vector <int>(knob2, knob2 + (sizeof knob2 / sizeof knob2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int knob1[]               = ;
			int knob2[]               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = HatRack().countWays(vector <int>(knob1, knob1 + (sizeof knob1 / sizeof knob1[0])), vector <int>(knob2, knob2 + (sizeof knob2 / sizeof knob2[0])));
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
// The Order of the Hats has commissioned the creation of a new hat rack. This new hat rack must meet certain properties in order to be considered to hold headwear of such importance.
The hat rack is formed by taking several numbered knobs that are connected by rods. One of the knobs is nailed to the wall. The remaining knobs then hang below this top knob. A sample hat rack is shown in the picture below.



The picture also shows that the hat rack can be divided into levels of knobs. Formally, the level i is defined to contain each knob X such that there are exactly i rods between the top knob and knob X.

The order would like their hat rack to meet the following three requirements:

Each knob X can have at most two knobs hanging directly below it. If there is only one such knob, it hangs directly below X; otherwise, one knob will hang slightly to the right of X and the other slightly to the left.
Except for the bottommost level, each level must be full. That is, if level i is not the bottommost level, it must contain exactly 2^i knobs.
The bottommost level must have all its knobs as far on the left as possible.


The third requirement in more detail: Let b be the bottommost level. If we traverse level b-1 from left to right, there will first be some knobs with two rods going to knobs in level b, then possibly a single knob with one rod going to level b, and finally some knobs not connected to any knob in level b.

You are given a configuration of knobs and rods. The knobs are not fastened to the wall yet. The knobs are numbered 1 through N. There are precisely N-1 rods, and they are connecting the knobs in such a way that the entire structure holds together. (Thus, necessarily, the topology of the hat rack is a tree.)

You are given two vector <int>s knob1 and knob2, each containing N-1 elements. These two vector <int>s describe the rods: For each i, there is a rod connecting the two knobs knob1[i] and knob2[i]. Return the number of ways to arrange the hat rack such that it meets the requirements set by the Order of the Hats. Two arrangements are considered different if the relative position of at least one pair of knobs differs. If it is not possible to meet the requirements, return 0.

DEFINITION
Class:HatRack
Method:countWays
Parameters:vector <int>, vector <int>
Returns:long long
Method signature:long long countWays(vector <int> knob1, vector <int> knob2)


NOTES
-The correct number of arrangements always fits in a signed 64 bit integer.


CONSTRAINTS
-knob1 will contain between 1 and 50 elements, inclusive.
-knob1 and knob2 will contain the same number of elements.
-Each element of knob1 will be between 1 and N, inclusive, where N is 1 + (the number of elements in knob1).
-Each element of knob2 will be between 1 and N, inclusive, where N is 1 + (the number of elements in knob2).
-Each pair of knobs in the hat rack will be connected by some sequence of rods and knobs.


EXAMPLES

0)
{1}
{2}

Returns: 2



1)
{1,1}
{2,3}

Returns: 2



2)
{1,1,1,1}
{2,3,4,5}

Returns: 0



3)
{6,6,6,4,1}
{1,2,4,5,3}

Returns: 0



4)
{1,1,2,2,11,11,8,8,3,3,4,4,5}
{2,3,11,8,12,13,9,10,4,5,7,6,14}

Returns: 16



5)
{1,2,3,4,5,6,7,8,9}
{2,3,4,5,6,7,8,9,10}

Returns: 0



*/

// END CUT HERE
