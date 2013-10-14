
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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 



bool chk(string s, VI c, int b, int w){
	int n = SZ(s);
	int ptr = 0;
	VI remain;
	int now_w = 0;
	
	while(ptr < n){
		if(s[ptr] >= '0' && s[ptr] <= '2') c[s[ptr]-'0']--, ptr++;
		else{
			int i = ptr;
			int cnt = 0;
			while(i < n && s[i] == 'b') cnt++, i++;
			if(cnt & 1){
				now_w++;
				if(now_w == w) return false;
				if(ptr == 0){
					if(cnt == 1) return false;
					else remain.push_back(1);
				}
				else remain.push_back(ptr-1);
				b -= (cnt+1)/2;
			}
			else b -= cnt/2;
			ptr = i; 
		}
	}
	REP(i, 3) if(c[i] < 0) return false;
	if(b < 0) return false;
	
	int t = 0;
	REP(i, 3) t += c[i];
	
	REP(i, SZ(remain)) while(remain[i] > 0){
		if(remain[i] >= 2 && b > 0) remain[i] -= 2, b--;
		else t--, remain[i]--;
		if(t < 0) return false;
	}
	
	return true;
}


class SkewedPerspectives {
public:
   vector <string> areTheyPossible( vector <int> cubes, int B, int w, vector <string> views ) {
	vector <string> res;
	REP(i, SZ(views)){
		if(chk(views[i], cubes, B, w)) res.push_back("valid");
		else res.push_back("invalid");
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
			int cubes[]               = {1,1,1};
			int B                     = 1;
			int w                     = 2;
			string views[]            = { "012", "012bb", "bb0", "21bb", "21b", "1bb20" };
			string expected__[]       = {"valid", "valid", "valid", "valid", "valid", "valid" };

			clock_t start__           = clock();
			vector <string> received__ = SkewedPerspectives().areTheyPossible(vector <int>(cubes, cubes + (sizeof cubes / sizeof cubes[0])), B, w, vector <string>(views, views + (sizeof views / sizeof views[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int cubes[]               = {0,1,0};
			int B                     = 3;
			int w                     = 2;
			string views[]            = {"b","bb","bbb","bbbb","bbbbb","bbbbbb",
 "1", "1b","1bb","1bbb","1bbbb","1bbbbb","1bbbbbb",
 "b1","b1b","b1bb","b1bbb","b1bbbb","b1bbbbb",
 "bb1","bb1b","bb1bb","bb1bbb","bb1bbbb",
 "bbb1","bbb1b","bbb1bb","bbb1bbb",
 "bbbb1","bbbb1b","bbbb1bb",
 "bbbbb1","bbbbb1b",
 "bbbbbb1" };
			string expected__[]       = {"invalid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "invalid", "invalid", "invalid", "invalid", "invalid", "invalid", "valid", "valid", "valid", "invalid", "valid", "invalid", "invalid", "invalid", "invalid", "valid", "invalid", "valid", "invalid", "invalid", "valid" };

			clock_t start__           = clock();
			vector <string> received__ = SkewedPerspectives().areTheyPossible(vector <int>(cubes, cubes + (sizeof cubes / sizeof cubes[0])), B, w, vector <string>(views, views + (sizeof views / sizeof views[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int cubes[]               = {100,0,0};
			int B                     = 20;
			int w                     = 3;
			string views[]            = {"00000000000000000000000000000000000000000000000000",
 "00000000000000000000000000000000000b00000000000000",
 "0000000000000000000000000000000000000000000000000b",
 "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb0000000000000"};
			string expected__[]       = {"valid", "valid", "valid", "valid" };

			clock_t start__           = clock();
			vector <string> received__ = SkewedPerspectives().areTheyPossible(vector <int>(cubes, cubes + (sizeof cubes / sizeof cubes[0])), B, w, vector <string>(views, views + (sizeof views / sizeof views[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int cubes[]               = {5,6,3};
			int B                     = 0;
			int w                     = 1;
			string views[]            = {"00000111111222", "0000111111222", "0000011111222", "000001111111222", "0000011111122", "b"};
			string expected__[]       = {"valid", "valid", "valid", "invalid", "valid", "invalid" };

			clock_t start__           = clock();
			vector <string> received__ = SkewedPerspectives().areTheyPossible(vector <int>(cubes, cubes + (sizeof cubes / sizeof cubes[0])), B, w, vector <string>(views, views + (sizeof views / sizeof views[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int cubes[]               = {100,100,100};
			int B                     = 100;
			int w                     = 50;
			string views[]            = {"2",
 "bb1b012012012012012012012",
 "bb1b012012012012012012012b",
 "bb1b012012012b012b012b012012b",
 "bb1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "b1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "bbb1b012012012012012012012"
};
			string expected__[]       = {"valid", "valid", "valid", "valid", "valid", "invalid", "valid" };

			clock_t start__           = clock();
			vector <string> received__ = SkewedPerspectives().areTheyPossible(vector <int>(cubes, cubes + (sizeof cubes / sizeof cubes[0])), B, w, vector <string>(views, views + (sizeof views / sizeof views[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			int cubes[]               = {0,0,0};
			int B                     = 0;
			int w                     = 1;
			string views[]            = {"0", "bb"};
			string expected__[]       = {"invalid", "invalid" };

			clock_t start__           = clock();
			vector <string> received__ = SkewedPerspectives().areTheyPossible(vector <int>(cubes, cubes + (sizeof cubes / sizeof cubes[0])), B, w, vector <string>(views, views + (sizeof views / sizeof views[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 6: {
			int cubes[]               = {3,0,0};
			int B                     = 4;
			int w                     = 3;
			string views[]            = {"00b0b", "bbbbbbbb", "000b"};
			string expected__[]       = {"invalid", "valid", "valid" };

			clock_t start__           = clock();
			vector <string> received__ = SkewedPerspectives().areTheyPossible(vector <int>(cubes, cubes + (sizeof cubes / sizeof cubes[0])), B, w, vector <string>(views, views + (sizeof views / sizeof views[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int cubes[]               = ;
			int B                     = ;
			int w                     = ;
			string views[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = SkewedPerspectives().areTheyPossible(vector <int>(cubes, cubes + (sizeof cubes / sizeof cubes[0])), B, w, vector <string>(views, views + (sizeof views / sizeof views[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			int cubes[]               = ;
			int B                     = ;
			int w                     = ;
			string views[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = SkewedPerspectives().areTheyPossible(vector <int>(cubes, cubes + (sizeof cubes / sizeof cubes[0])), B, w, vector <string>(views, views + (sizeof views / sizeof views[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 9: {
			int cubes[]               = ;
			int B                     = ;
			int w                     = ;
			string views[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = SkewedPerspectives().areTheyPossible(vector <int>(cubes, cubes + (sizeof cubes / sizeof cubes[0])), B, w, vector <string>(views, views + (sizeof views / sizeof views[0])));
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
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.

Cat Taro has the following building blocks:

cubes[0] red unit cubes,
cubes[1] yellow unit cubes,
cubes[2] blue unit cubes,
B black rectangular prisms with dimensions 2x1x1.


Cat Taro is using the blocks to build w adjacent towers of blocks (some possibly empty), as shown on the right side of the picture below. Taro will always place the rectangular prisms vertically. In other words, each prism will look like two black unit cubes placed one on top of the other. Taro is not required to use all of the blocks when building the towers. (In fact, he may even decide not to use any blocks at all.)

 

Rabbit Hanako is looking at Taro's towers from the left side of the room. To him, the towers seem as a single tower which we will call a view, as shown on the left side of the picture above. More precisely, at each height i Hanako sees the color of the block at height i in the leftmost tower that has such a block. Hanako's view can be described as a string of characters, giving the colors of each 1x1 square seen by Hanako in the order from bottom to top.
Black squares will be denoted 'b', and colored squares will be denoted '0', '1', and '2' (in the same order used in cubes).

You are given the vector <int> cubes, the int B, the int w, and a vector <string> views.
Each element of views specifies one view Taro wants Hanako to see, in the format specified above.
Return a vector <string> with the same number of elements as views.
If Taro can build the towers in such a way that Hanako will see the view views[i], the i-th element of the return value should be "valid", otherwise it should be "invalid" (quotes for clarity).

DEFINITION
Class:SkewedPerspectives
Method:areTheyPossible
Parameters:vector <int>, int, int, vector <string>
Returns:vector <string>
Method signature:vector <string> areTheyPossible(vector <int> cubes, int B, int w, vector <string> views)


CONSTRAINTS
-w will be between 1 and 50, inclusive.
-cubes will contain exactly 3 elements.
-Each element of cubes will be between 0 and 100, inclusive.
-B will be between 0 and 100, inclusive.
-views will contain between 1 and 50 elements, inclusive.
-Each element of views will contain between 1 and 50 characters, inclusive.
-Each character in each element of views will be one of 'b', '0', '1', and '2'.


EXAMPLES

0)
{1,1,1}
1
2
{ "012", "012bb", "bb0", "21bb", "21b", "1bb20" }

Returns: {"valid", "valid", "valid", "valid", "valid", "valid" }

The following picture shows a way to achieve each of the given views.


1)
{0,1,0}
3
2
{"b","bb","bbb","bbbb","bbbbb","bbbbbb",
 "1", "1b","1bb","1bbb","1bbbb","1bbbbb","1bbbbbb",
 "b1","b1b","b1bb","b1bbb","b1bbbb","b1bbbbb",
 "bb1","bb1b","bb1bb","bb1bbb","bb1bbbb",
 "bbb1","bbb1b","bbb1bb","bbb1bbb",
 "bbbb1","bbbb1b","bbbb1bb",
 "bbbbb1","bbbbb1b",
 "bbbbbb1" }

Returns: {"invalid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "invalid", "invalid", "invalid", "invalid", "invalid", "invalid", "valid", "valid", "valid", "invalid", "valid", "invalid", "invalid", "invalid", "invalid", "valid", "invalid", "valid", "invalid", "invalid", "valid" }



2)
{100,0,0}
20
3
{"00000000000000000000000000000000000000000000000000",
 "00000000000000000000000000000000000b00000000000000",
 "0000000000000000000000000000000000000000000000000b",
 "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb0000000000000"}

Returns: {"valid", "valid", "valid", "valid" }



3)
{5,6,3}
0
1
{"00000111111222", "0000111111222", "0000011111222", "000001111111222", "0000011111122", "b"}

Returns: {"valid", "valid", "valid", "invalid", "valid", "invalid" }



4)
{100,100,100}
100
50
{"2",
 "bb1b012012012012012012012",
 "bb1b012012012012012012012b",
 "bb1b012012012b012b012b012012b",
 "bb1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "b1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "bbb1b012012012012012012012"
}

Returns: {"valid", "valid", "valid", "valid", "valid", "invalid", "valid" }



5)
{0,0,0}
0
1
{"0", "bb"}

Returns: {"invalid", "invalid" }

Taro has no cubes and no prisms, therefore he cannot create any non-empty view.

6)
{3,0,0}
4
3
{"00b0b", "bbbbbbbb", "000b"}

Returns: {"invalid", "valid", "valid" }



*/

// END CUT HERE
