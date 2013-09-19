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

class TheTree {
	public:
	int maximumDiameter(vector <int> cnt) {
		int n = SZ(cnt);
        VI a;
        a.push_back(0);
        REP(i, n) if(cnt[i] == 1) a.push_back(i+1);
        a.push_back(n+1);
        
        int res = 0;
        for(int i = 1; i < SZ(a); i++) chmax(res, (a[i]-a[i-1]-1)*2 + (a[i]==n+1 ? 0 :n-a[i]+1));
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
			int cnt[]                 = {3};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheTree().maximumDiameter(vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int cnt[]                 = {2, 2};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TheTree().maximumDiameter(vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int cnt[]                 = {4, 1, 2, 4};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = TheTree().maximumDiameter(vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int cnt[]                 = {4, 2, 1, 3, 2, 5, 7, 2, 4, 5, 2, 3, 1, 13, 6};
			int expected__            = 21;

			clock_t start__           = clock();
			int received__            = TheTree().maximumDiameter(vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int cnt[]                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheTree().maximumDiameter(vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int cnt[]                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheTree().maximumDiameter(vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int cnt[]                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheTree().maximumDiameter(vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])));
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
// Manao is working in the Tree Research Center.
It may come as a surprise that the trees they research are not the ones you can see in a park.
Instead, they are researching special graphs.
(See Notes for definitions of terms related to these trees.)

Manao's daily job is reconstructing trees, given some partial information about them.
Today Manao faced a difficult task.
He needed to find the maximum possible diameter of a tree, given the following information:


Some vertex in the tree is called V.
The distance between V and the farthest vertex from V is D.
For each x between 1 and D, inclusive, Manao knows the number of vertices such that their distance from V is x.


You are given a vector <int> cnt containing D strictly positive integers.
For each i, the i-th element of cnt is equal to the number of vertices which have distance i+1 from V.
Please help Manao with his task.
Return the maximum possible diameter of a tree that matches the given information.


DEFINITION
Class:TheTree
Method:maximumDiameter
Parameters:vector <int>
Returns:int
Method signature:int maximumDiameter(vector <int> cnt)


NOTES
-A tree is a connected graph with no cycles. Note that each tree with N vertices has precisely N-1 edges.
-The distance between two vertices of a tree is the smallest number of edges one has to traverse in order to get from one of the vertices to the other one.
-The diameter of a tree is the maximum of all pairwise distances. In other words, the diameter is the distance between the two vertices that are the farthest away from each other.


CONSTRAINTS
-cnt will contain between 1 and 50 elements, inclusive.
-Each element of cnt will be between 1 and 1000, inclusive.


EXAMPLES

0)
{3}

Returns: 2

The only tree that matches the given information is shown below. The vertex V is red.




1)
{2, 2}

Returns: 4

There are two trees which correspond to the given partial information:



The tree on the left has diameter 3 and the tree on the right has diameter 4.

2)
{4, 1, 2, 4}

Returns: 5

This is one example of a tree that corresponds to the given constraints and has the largest possible diameter.



3)
{4, 2, 1, 3, 2, 5, 7, 2, 4, 5, 2, 3, 1, 13, 6}

Returns: 21



*/

// END CUT HERE
