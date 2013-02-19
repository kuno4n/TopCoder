
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
#include <queue>

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
#define OUT(A) cout << #A << " = "<< A << endl

bool G[52][52];
LL ans;

LL dfs(int root, int parent){
	LL res = 1;
	REP(i, 52) if(i!=parent && G[root][i]) res *= dfs(i, root);
	ans += res;
	return res + 1;
}

class CentaurCompanyDiv2 {
public:
   long long count( vector <int> a, vector <int> b ) {
	   MSET(G, false);
	   REP(i, SZ(a)){
		   G[a[i]-1][b[i]-1] = true;
		   G[b[i]-1][a[i]-1] = true;
	   }
	   ans = 0;
	   dfs(0, -1);
	   return ans + 1;
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
			int a[]                   = {1};
			int b[]                   = {2};
			long long expected__      = 4;

			clock_t start__           = clock();
			long long received__      = CentaurCompanyDiv2().count(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a[]                   = {2,2};
			int b[]                   = {1,3};
			long long expected__      = 7;

			clock_t start__           = clock();
			long long received__      = CentaurCompanyDiv2().count(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a[]                   = {1,2,3,4,5,6,7,8,9};
			int b[]                   = {2,3,4,5,6,7,8,9,10};
			long long expected__      = 56;

			clock_t start__           = clock();
			long long received__      = CentaurCompanyDiv2().count(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a[]                   = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int b[]                   = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51};
			long long expected__      = 1125899906842675LL;

			clock_t start__           = clock();
			long long received__      = CentaurCompanyDiv2().count(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int a[]                   = {10, 7, 2, 5, 6, 2, 4, 9, 7};
			int b[]                   = {8, 10, 10, 4, 1, 6, 2, 2, 3};
			long long expected__      = 144;

			clock_t start__           = clock();
			long long received__      = CentaurCompanyDiv2().count(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int a[]                   = ;
			int b[]                   = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = CentaurCompanyDiv2().count(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int a[]                   = ;
			int b[]                   = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = CentaurCompanyDiv2().count(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int a[]                   = ;
			int b[]                   = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = CentaurCompanyDiv2().count(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
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
// The Centaur company has N servers, numbered 1 through N.
These servers are currently connected into a network.
The topology of the network is a tree.
In other words, there are exactly N-1 bidirectional cables, each connecting some two servers in such a way that the entire network is connected.

The Centaur company is about to split into two new companies: the Human company and the Horse company.
When this happens, the companies will divide the servers somehow.
Once they divide their servers, they will cut each cable that connects a server of the Horse company and a server of the Human company.

While the Horse company has a lot of cables, the Human company does not have any.
Therefore, when dividing the servers, the Human company must get a set of servers that will remain connected after the cables are cut.

You are given two vector <int>s a and b, each containing N-1 elements.
These two arrays describe the original cables:
for each i, there is a cable that connects the servers a[i] and b[i].

Compute and return the number of different ways in which the two companies may divide the servers.
(It is possible that one of the companies will get no servers at all.)

DEFINITION
Class:CentaurCompanyDiv2
Method:count
Parameters:vector <int>, vector <int>
Returns:long long
Method signature:long long count(vector <int> a, vector <int> b)


NOTES
-N can be determined as (1 + the length of a).


CONSTRAINTS
-N will be between 2 and 51, inclusive.
-a and b will contain exactly N-1 elements.
-Each element of a and b will be between 1 and N, inclusive.
-The network defined by a and b will be a tree (as explained in the problem statement).


EXAMPLES

0)
{1}
{2}

Returns: 4

There are 2^2 = 4 ways to divide the servers between two companies. For any division, the Human company's servers will remain connected.

1)
{2,2}
{1,3}

Returns: 7

There are 2^3 = 8 ways to divide the servers between two companies. However, if the Human company gets server 1 and server 3, and the Horse company gets server 2, the Human company's servers will not be connected. Therefore the number of valid ways is 8 - 1 = 7.

2)
{1,2,3,4,5,6,7,8,9}
{2,3,4,5,6,7,8,9,10}

Returns: 56



3)
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
{2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51}

Returns: 1125899906842675

The answer overflows a 32-bit integer data type.

4)
{10, 7, 2, 5, 6, 2, 4, 9, 7}
{8, 10, 10, 4, 1, 6, 2, 2, 3}

Returns: 144



*/

// END CUT HERE
