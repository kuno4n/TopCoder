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

int tab[55];
LL dp[55][55];


LL C[55][55];

void makepas(){
    MSET(C, 0);
    C[0][0] = C[1][0] = C[1][1] = 1;
    for(int i=2; i<55; i++){
        C[i][0] = 1;
        C[i][i] = 1;
        for(int j=1; j<i; j++){
            C[i][j] = (C[i-1][j-1] + C[i-1][j]);
        }
    }
}

class Excavations2 {
	public:
	long long count(vector <int> kind, vector <int> found, int K) {
        
        MSET(tab, 0);
        REP(i, SZ(kind)) tab[kind[i]]++;
        
        makepas();
        MSET(dp, 0);
        dp[0][0] = 1;
        REP(i, SZ(found)) REP(j, 55) if(dp[i][j] > 0){
            for(int k = 1; k <= tab[found[i]]; k++){
                dp[i+1][j+k] += dp[i][j] * C[tab[found[i]]][k];
            }
        }
        
        return dp[SZ(found)][K];
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
			int kind[]                = {1, 2, 2, 1};
			int found[]               = {1};
			int K                     = 2;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = Excavations2().count(vector <int>(kind, kind + (sizeof kind / sizeof kind[0])), vector <int>(found, found + (sizeof found / sizeof found[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int kind[]                = {1, 2, 2, 1};
			int found[]               = {1, 2};
			int K                     = 2;
			long long expected__      = 4;

			clock_t start__           = clock();
			long long received__      = Excavations2().count(vector <int>(kind, kind + (sizeof kind / sizeof kind[0])), vector <int>(found, found + (sizeof found / sizeof found[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int kind[]                = {1, 2, 1, 1, 2, 3, 4, 3, 2, 2};
			int found[]               = {4, 2};
			int K                     = 3;
			long long expected__      = 6;

			clock_t start__           = clock();
			long long received__      = Excavations2().count(vector <int>(kind, kind + (sizeof kind / sizeof kind[0])), vector <int>(found, found + (sizeof found / sizeof found[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int kind[]                = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
			int found[]               = {50};
			int K                     = 21;
			long long expected__      = 5567902560LL;

			clock_t start__           = clock();
			long long received__      = Excavations2().count(vector <int>(kind, kind + (sizeof kind / sizeof kind[0])), vector <int>(found, found + (sizeof found / sizeof found[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int kind[]                = ;
			int found[]               = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Excavations2().count(vector <int>(kind, kind + (sizeof kind / sizeof kind[0])), vector <int>(found, found + (sizeof found / sizeof found[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int kind[]                = ;
			int found[]               = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Excavations2().count(vector <int>(kind, kind + (sizeof kind / sizeof kind[0])), vector <int>(found, found + (sizeof found / sizeof found[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int kind[]                = ;
			int found[]               = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Excavations2().count(vector <int>(kind, kind + (sizeof kind / sizeof kind[0])), vector <int>(found, found + (sizeof found / sizeof found[0])), K);
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
// Once upon a time, there was a civilization called Ruritania. It had n building sites numbered from 0 to n-1. There were various types of buildings such as libraries, markets, and palaces. Each building type was assigned an integer from 1 to 50. The building at site i (0-based index) was of type kind[i].

With the passing of millennia, Ruritania declined and its building sites were covered in sand, concealing all the buildings. Recently, an intrepid archeologist excavated K building sites.

You are given vector <int>s kind and found as well as the int K. The types of buildings discovered by the excavation are described by the vector <int> found, which contains at most one value for each building type even if several buildings of a type were excavated.

Return the number of K-tuples of sites that could have been excavated to arrive at the given values. The answer is guaranteed to be at least one.


DEFINITION
Class:Excavations2
Method:count
Parameters:vector <int>, vector <int>, int
Returns:long long
Method signature:long long count(vector <int> kind, vector <int> found, int K)


CONSTRAINTS
-kind will contain N elements, where N is between 1 and 50, inclusive.
-Each element of kind will be between 1 and 50, inclusive.
-found will contain between 1 and 50 elements, inclusive.
-Each element of found will occur in kind at least once.
-The elements of found will be distinct.
-K will be between the number of elements in found and N, inclusive.
-There will exist at least one K-tuple of sites consistent with the given information.


EXAMPLES

0)
{1, 2, 2, 1}
{1}
2

Returns: 1

There are four building sites. Two contain a building of type 1 and two contain a building of type 2. The archeologist excavated two sites and only found buildings of type 1. The only possible scenario is that the archeologist excavated sites 0 and 3.

1)
{1, 2, 2, 1}
{1, 2}
2

Returns: 4

The building sites are the same as before, but in this case buildings of type 1 and type 2 have been discovered. The archeologist must have excavated one of four possible pairs of sites: (0, 1), (0, 2), (1, 3), or (2, 3).

2)
{1, 2, 1, 1, 2, 3, 4, 3, 2, 2}
{4, 2}
3

Returns: 6

The archeologist excavated one of six possible triples of building sites:

(1, 4, 6)
(1, 6, 8)
(1, 6, 9)
(4, 6, 8)
(4, 6, 9)
(6, 8, 9)


3)
{50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50}
{50}
21

Returns: 5567902560



*/

// END CUT HERE
