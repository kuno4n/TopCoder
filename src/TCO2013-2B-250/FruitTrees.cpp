
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

long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

class FruitTrees {
public:
   int maxDist( int a, int b, int c ) {
	   int res = 0;
	   int ab = gcd(a, b);
	   int bc = gcd(b, c);
	   int ca = gcd(c, a);
	   REP(i, 2000){
		   REP(j, 2000){
			   int mvab = i % ab;
			   int mvbc = abs(j-i) % bc;
			   int mvca = j % ca;
			   int dstab = min(mvab, ab - mvab);
			   int dstbc = min(mvbc, bc - mvbc);
			   int dstca = min(mvca, ca - mvca);
			   res = max(res, min(dstab, min(dstbc, dstca)));
		   }
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
			int apple                 = 1;
			int kiwi                  = 5;
			int grape                 = 8;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = FruitTrees().maxDist(apple, kiwi, grape);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int apple                 = 3;
			int kiwi                  = 3;
			int grape                 = 6;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = FruitTrees().maxDist(apple, kiwi, grape);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int apple                 = 40;
			int kiwi                  = 30;
			int grape                 = 20;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = FruitTrees().maxDist(apple, kiwi, grape);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int apple                 = 899;
			int kiwi                  = 1073;
			int grape                 = 1147;
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = FruitTrees().maxDist(apple, kiwi, grape);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int apple                 = 2000;
			int kiwi                  = 2000;
			int grape                 = 2000;
			int expected__            = 666;

			clock_t start__           = clock();
			int received__            = FruitTrees().maxDist(apple, kiwi, grape);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int apple                 = ;
			int kiwi                  = ;
			int grape                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FruitTrees().maxDist(apple, kiwi, grape);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int apple                 = ;
			int kiwi                  = ;
			int grape                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FruitTrees().maxDist(apple, kiwi, grape);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int apple                 = ;
			int kiwi                  = ;
			int grape                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FruitTrees().maxDist(apple, kiwi, grape);
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
// There is an infinitely long straight road.
Fox Ciel is going to plant trees of three kinds: apple trees, kiwi trees, and grape trees.
There will be infinitely many trees of each kind.
Trees of each kind will be placed along the entire road in regular intervals.


More precisely, you are given ints apple, kiwi, and grape with the following meaning:
The distance between any two consecutive apple trees must be apple, the distance between any two consecutive kiwi trees must be kiwi, and the distance between any two consecutive grape trees must be grape.


Ciel can only plant the trees at integer coordinates, but she gets to choose those coordinates as long as the above conditions are satisfied.
In other words, Ciel gets to choose three integers x, y, and z such that:

She plants apple trees at coordinates ..., x - 2 * apple, x - apple, x, x + apple, x + 2 * apple, ...
She plants kiwi trees at coordinates ..., y - 2 * kiwi, y - kiwi, y, y + kiwi, y + 2 * kiwi, ...
She plants grape trees at coordinates ..., z - 2 * grape, z - grape, z, z + grape, z + 2 * grape, ...

Ciel wants to maximize the distance between two closest trees (of any kind).
Return this distance.

DEFINITION
Class:FruitTrees
Method:maxDist
Parameters:int, int, int
Returns:int
Method signature:int maxDist(int apple, int kiwi, int grape)


CONSTRAINTS
-apple will be between 1 and 2,000, inclusive.
-kiwi will be between 1 and 2,000, inclusive.
-grape will be between 1 and 2,000, inclusive.


EXAMPLES

0)
1
5
8

Returns: 0

Apple trees will be planted at all integer coordinates, so at least two trees will be planted where a kiwi tree is planted.

1)
3
3
6

Returns: 1

One of the optimal solutions is as follows:

Plant apple trees at ..., -5, -2, 1, 4, ...
Plant kiwi trees at ..., -4, -1, 2, 5, ...
Plant grape trees at ..., -9, -3, 3, 9, ...




2)
40
30
20

Returns: 5



3)
899
1073
1147

Returns: 14



4)
2000
2000
2000

Returns: 666



*/

// END CUT HERE
