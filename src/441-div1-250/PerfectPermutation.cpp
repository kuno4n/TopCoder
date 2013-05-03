
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
#include <numeric>

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



class PerfectPermutation {
public:
   int reorder( vector <int> p ) {
	   bool vis[52];
	   REP(i, 52) vis[i] = false;
	   int c = 0;
	   REP(i, SZ(p)){
		   if(vis[i]) continue;
		   c++;
		   int a = i;
		   while(!vis[a]){
			   vis[a] = true;
			   a = p[a];
		   }
	   }
	   if(c == 1) return 0;
	   else return c;
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
			int P[]                   = {2, 0, 1};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PerfectPermutation().reorder(vector <int>(P, P + (sizeof P / sizeof P[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int P[]                   = {2, 0, 1, 4, 3};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = PerfectPermutation().reorder(vector <int>(P, P + (sizeof P / sizeof P[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int P[]                   = {2, 3, 0, 1};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = PerfectPermutation().reorder(vector <int>(P, P + (sizeof P / sizeof P[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int P[]                   = {0, 5, 3, 2, 1, 4};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = PerfectPermutation().reorder(vector <int>(P, P + (sizeof P / sizeof P[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int P[]                   = {4, 2, 6, 0, 3, 5, 9, 7, 8, 1};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = PerfectPermutation().reorder(vector <int>(P, P + (sizeof P / sizeof P[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int P[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PerfectPermutation().reorder(vector <int>(P, P + (sizeof P / sizeof P[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int P[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PerfectPermutation().reorder(vector <int>(P, P + (sizeof P / sizeof P[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int P[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PerfectPermutation().reorder(vector <int>(P, P + (sizeof P / sizeof P[0])));
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
// A permutation A[0], A[1], ..., A[N-1] is a sequence containing each integer between 0 and N-1, inclusive, exactly once.  Each permutation A of length N has a corresponding child array B of the same length, where B is defined as follows:


B[0] = 0
B[i] = A[B[i-1]], for every i between 1 and N-1, inclusive.


A permutation is considered perfect if its child array is also a permutation.

Below are given all permutations for N=3 with their child arrays. Note that for two of these permutations ({1, 2, 0} and {2, 0, 1}) the child array is also a permutation, so these two permutations are perfect.


Permutation		Child array
{0, 1, 2}		{0, 0, 0}
{0, 2, 1}		{0, 0, 0}
{1, 0, 2}		{0, 1, 0}
{1, 2, 0}		{0, 1, 2}
{2, 0, 1}		{0, 2, 1}
{2, 1, 0}		{0, 2, 0}


You are given a vector <int> P containing a permutation of length N.  Find a perfect permutation Q of the same length such that the difference between P and Q is as small as possible, and return this difference.  The difference between P and Q is the number of indices i for which P[i] and Q[i] are different.

DEFINITION
Class:PerfectPermutation
Method:reorder
Parameters:vector <int>
Returns:int
Method signature:int reorder(vector <int> P)


CONSTRAINTS
-P will contain between 1 and 50 elements, inclusive.
-P will contain each integer between 0 and N-1, inclusive, exactly once, where N is the number of elements in P.


EXAMPLES

0)
{2, 0, 1}

Returns: 0

P is a perfect permutation, so we can use the same permutation for Q.  The difference is then 0 because P and Q are the same.

1)
{2, 0, 1, 4, 3}

Returns: 2

Q might be {2, 0, 3, 4, 1}.

2)
{2, 3, 0, 1}

Returns: 2

Q might be {1, 3, 0, 2}.

3)
{0, 5, 3, 2, 1, 4}

Returns: 3



4)
{4, 2, 6, 0, 3, 5, 9, 7, 8, 1}

Returns: 5



*/

// END CUT HERE
