
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


string int2str(LL a){
    stringstream ss;
    ss << a;
    string res;
    ss >> res;
    return res;
}


int  str2int(string s){
    stringstream ss;
    ss << s;
    int res;
    ss >> res;
    return res;
}

int res, k;
set < pair <string, int> > s;

void dfs(string s1, int turn){
	if(s.count(make_pair(s1, turn))) return;
	s.insert(make_pair(s1, turn));
	if(turn >= k){
		res = max(res, str2int(s1));
		return;
	}

	REP(i, SZ(s1)-1) for(int j = i+1; j < SZ(s1); j++){
		string s2 = s1;
		swap(s2[i], s2[j]);
		if(s2[0] == '0') continue;
		dfs(s2, turn+1);
	}
	return;

}

class TheSwap {
public:
   int findMax( int n, int K ) {
	   res = -1;
	   k = K;
	   s.clear();
	   
	   dfs(int2str(n), 0);
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
			int n                     = 16375;
			int k                     = 1;
			int expected__            = 76315;

			clock_t start__           = clock();
			int received__            = TheSwap().findMax(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 432;
			int k                     = 1;
			int expected__            = 423;

			clock_t start__           = clock();
			int received__            = TheSwap().findMax(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 90;
			int k                     = 4;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = TheSwap().findMax(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 5;
			int k                     = 2;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = TheSwap().findMax(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 436659;
			int k                     = 2;
			int expected__            = 966354;

			clock_t start__           = clock();
			int received__            = TheSwap().findMax(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int n                     = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheSwap().findMax(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheSwap().findMax(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheSwap().findMax(n, k);
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
There is nothing more beautiful than just an integer number.



You are given an integer n.  Write down n in decimal notation with no leading zeroes, and let M be the number of written digits.  Perform the following operation exactly k times:

Choose two different 1-based positions, i and j, such that 1 &lt= i &lt j &lt= M. Swap the digits at positions i and j.  This swap must not cause the resulting number to have a leading zero, i.e., if the digit at position j is zero, then i must be strictly greater than 1.




Return the maximal possible number you can get at the end of this procedure.  If it's not possible to perform k operations, return -1 instead.



DEFINITION
Class:TheSwap
Method:findMax
Parameters:int, int
Returns:int
Method signature:int findMax(int n, int k)


CONSTRAINTS
-n will be between 1 and 1,000,000, inclusive.
-k will be between 1 and 10, inclusive.


EXAMPLES

0)
16375
1

Returns: 76315

The optimal way is to swap 1 and 7.

1)
432
1

Returns: 423

In this case the result is less than the given number.

2)
90
4

Returns: -1

We can't make even a single operation because it would cause the resulting number to have a leading zero.

3)
5
2

Returns: -1

Here we can't choose two different positions for an operation.

4)
436659
2

Returns: 966354



*/

// END CUT HERE
