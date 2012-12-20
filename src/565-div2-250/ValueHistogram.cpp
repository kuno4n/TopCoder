
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

class ValueHistogram {
public:
   vector <string> build( vector <int> values ) {
	   int cnt[10];
	   MSET(cnt, 0);
	   REP(i, SZ(values)) cnt[values[i]]++;
	   int mx = 0;
	   REP(i, 10) mx = max(mx, cnt[i]);
	   OUT(mx);
	   vector <string> res;
	   res.clear();
	   for(int i=mx+1; i>0; i--){
		   string s = "";
		   REP(j, 10){
			   if(cnt[j] >= i) s += 'X';
			   else s += '.';
		   }
			   res.push_back(s);
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
	template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed) { 
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
			int values[]              = {2, 3, 5, 5, 5, 2, 0, 8};
			string expected__[]       = {"..........", ".....X....", "..X..X....", "X.XX.X..X." };

			clock_t start__           = clock();
			vector <string> received__ = ValueHistogram().build(vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int values[]              = {9, 9, 9, 9};
			string expected__[]       = {"..........", ".........X", ".........X", ".........X", ".........X" };

			clock_t start__           = clock();
			vector <string> received__ = ValueHistogram().build(vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int values[]              = {6, 4, 0, 0, 3, 9, 8, 8};
			string expected__[]       = {"..........", "X.......X.", "X..XX.X.XX" };

			clock_t start__           = clock();
			vector <string> received__ = ValueHistogram().build(vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int values[]              = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			string expected__[]       = {"..........", "XXXXXXXXXX" };

			clock_t start__           = clock();
			vector <string> received__ = ValueHistogram().build(vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int values[]              = {6, 2, 3, 3, 3, 7, 8, 1, 0, 9, 2, 2, 4, 3};
			string expected__[]       = {"..........", "...X......", "..XX......", "..XX......", "XXXXX.XXXX" };

			clock_t start__           = clock();
			vector <string> received__ = ValueHistogram().build(vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int values[]              = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = ValueHistogram().build(vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int values[]              = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = ValueHistogram().build(vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int values[]              = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = ValueHistogram().build(vector <int>(values, values + (sizeof values / sizeof values[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
// A histogram of a given collection of numbers graphically represents the frequency of each value in the collection. We are given several numbers ranging from 0 to 9 as a vector <int> values. The goal is to build their histogram according to the following rules.

1) The width of the histogram should be exactly 10.

2) The height of the histogram should equal to H+1, where H is the number of times the most frequent element occurs in values.

3) The i-th (0-based) column of the histogram corresponds to the value i. Let X(i) be the frequency of value i in values. Then the last X(i) characters in the column should be 'X's and the other ones should be '.'s. For example, if value i was not present in values, the column should be filled with '.' characters. If i was present once, the last element of the column should be 'X' and and the other ones should be '.'s. If i was present twice, the last two elements should be 'X's and and the other ones should be '.'s, and so on.

Build the histogram and return it as a vector <string>.

DEFINITION
Class:ValueHistogram
Method:build
Parameters:vector <int>
Returns:vector <string>
Method signature:vector <string> build(vector <int> values)


CONSTRAINTS
-values will contain between 1 and 50 elements, inclusive.
-Each element of values will be between 0 and 9, inclusive.


EXAMPLES

0)
{2, 3, 5, 5, 5, 2, 0, 8}

Returns: {"..........", ".....X....", "..X..X....", "X.XX.X..X." }

The most frequent value is 5, which occurs 3 times. Hence the height of the histogram is 4. It looks as follows:

..........
.....X....
..X..X....
X.XX.X..X.


1)
{9, 9, 9, 9}

Returns: {"..........", ".........X", ".........X", ".........X", ".........X" }

..........
.........X
.........X
.........X
.........X

2)
{6, 4, 0, 0, 3, 9, 8, 8}

Returns: {"..........", "X.......X.", "X..XX.X.XX" }

..........
X.......X.
X..XX.X.XX

3)
{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

Returns: {"..........", "XXXXXXXXXX" }

..........
XXXXXXXXXX

4)
{6, 2, 3, 3, 3, 7, 8, 1, 0, 9, 2, 2, 4, 3}

Returns: {"..........", "...X......", "..XX......", "..XX......", "XXXXX.XXXX" }

..........
...X......
..XX......
..XX......
XXXXX.XXXX

*/

// END CUT HERE
