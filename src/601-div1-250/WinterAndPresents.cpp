#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <sys/time.h>
#include <fstream>
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

class WinterAndPresents {
public:
   long long getNumber( vector <int> apple, vector <int> orange ) {
       LL res = 0;
       int n = SZ(apple);
//       int mn = 10000000;
//       REP(i, n) chmin(mn, apple[i]+orange[i]);
//       sort(ALL(apple));
//       sort(ALL(orange));
//       int ptr1 = 0, ptr2 = 0;
//       int sum1 = 0, sum2 = 0;
//       for(int i = 1; i <= mn; i++){
//           while(ptr1 < n && apple[ptr1] < i) ptr1++;
//           while(ptr2 < n && orange[ptr2] < i) ptr2++;
//           sum1 += n-ptr1;
//           sum2 += n-ptr2;
//           res += sum1 - (i*n - sum2) + 1;
//       }
       
       for(int s = 1; ; s++){
           int sum1 = 0;
           int sum2 = 0;
           REP(i, n){
               sum1 += min(apple[i], s), sum2 += min(orange[i], s);
               if(s > apple[i] + orange[i]) return res;
           }
           res += sum1 - (s*n - sum2) + 1;
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
			int apple[]               = {1};
			int orange[]              = {1};
			long long expected__      = 3;

			clock_t start__           = clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int apple[]               = {1, 2, 0, 3};
			int orange[]              = {4, 5, 0, 6};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int apple[]               = {2, 2, 2};
			int orange[]              = {2, 2, 2};
			long long expected__      = 16;

			clock_t start__           = clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int apple[]               = {7, 4, 5};
			int orange[]              = {1, 10, 2};
			long long expected__      = 46;

			clock_t start__           = clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int apple[]               = {1000000};
			int orange[]              = {1000000};
			long long expected__      = 1000002000000LL;

			clock_t start__           = clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int apple[]               = ;
			int orange[]              = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int apple[]               = ;
			int orange[]              = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int apple[]               = ;
			int orange[]              = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
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
It's winter time!
You need to prepare a Christmas gift for your friend.




You have several bags arranged in a row.
The bags only contain apples and oranges.
You are given an vector <int> apple and an vector <int> orange.
For each i, the i-th element of apple represents the number of apples in the i-th bag, and the i-th element of orange represents the number of oranges in the i-th bag.




You will choose the gift using the following procedure:
First, you will choose any positive integer X such that there are at least X pieces of fruit in each bag.
Then, you will take exactly X pieces of fruit out of each bag, and combine all the fruit into one present.
Return the number of different gifts that may be produced by following the given procedure.
(Two gifts are considered different if they contain a different number of apples or a different number of oranges.)


DEFINITION
Class:WinterAndPresents
Method:getNumber
Parameters:vector <int>, vector <int>
Returns:long long
Method signature:long long getNumber(vector <int> apple, vector <int> orange)


CONSTRAINTS
-apple will contain between 1 and 50 elements, inclusive.
-orange will contain between 1 and 50 elements, inclusive.
-apple and orange will contain the same number of elements.
-Each element of apple and orange will be between 0 and 1,000,000, inclusive.


EXAMPLES

0)
{1}
{1}

Returns: 3

Three different presents are possible in this case: 


0 apples and 1 orange


1 apple and 0 oranges


1 apple and 1 orange



1)
{1, 2, 0, 3}
{4, 5, 0, 6}

Returns: 0

As there is an empty bag, there is no way to choose the present.

2)
{2, 2, 2}
{2, 2, 2}

Returns: 16



3)
{7, 4, 5}
{1, 10, 2}

Returns: 46



4)
{1000000}
{1000000}

Returns: 1000002000000



*/

// END CUT HERE
