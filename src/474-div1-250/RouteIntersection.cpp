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

class RouteIntersection {
	public:
	string isValid(int N, vector <int> coords, string moves) {
		set<int> s;
        REP(i, SZ(coords)) s.insert(coords[i]);
        int dim = SZ(s);
        map<int, int> m;
        int ptr = 0;
        FIT(it, s){
            m[*it] = ptr;
            ptr++;
        }
        set< VI > visited;
        
        VI now(dim);
        REP(i, dim) now[i] = 0;
        visited.insert(now);
        
        REP(i, SZ(coords)){
            if(moves[i] == '+') now[m[coords[i]]]++;
            else now[m[coords[i]]]--;
            if(visited.find(now) != visited.end()) return "NOT VALID";
            visited.insert(now);
        }
        return "VALID";
        
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int N                     = 1;
			int coords[]              = {1};
			string moves              = "+";
			string expected__         = "VALID";

			clock_t start__           = clock();
			string received__         = RouteIntersection().isValid(N, vector <int>(coords, coords + (sizeof coords / sizeof coords[0])), moves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 2;
			int coords[]              = {1,2,1,2};
			string moves              = "++--";
			string expected__         = "NOT VALID";

			clock_t start__           = clock();
			string received__         = RouteIntersection().isValid(N, vector <int>(coords, coords + (sizeof coords / sizeof coords[0])), moves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 3;
			int coords[]              = {1,2,3,1,2};
			string moves              = "+++--";
			string expected__         = "VALID";

			clock_t start__           = clock();
			string received__         = RouteIntersection().isValid(N, vector <int>(coords, coords + (sizeof coords / sizeof coords[0])), moves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 344447;
			int coords[]              = {132,51717,628,344447,628,51717,344447,2};
			string moves              = "+-++-+--";
			string expected__         = "NOT VALID";

			clock_t start__           = clock();
			string received__         = RouteIntersection().isValid(N, vector <int>(coords, coords + (sizeof coords / sizeof coords[0])), moves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 1;
			int coords[]              = {1,1};
			string moves              = "+-";
			string expected__         = "NOT VALID";

			clock_t start__           = clock();
			string received__         = RouteIntersection().isValid(N, vector <int>(coords, coords + (sizeof coords / sizeof coords[0])), moves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 990630;
			int coords[]              = {833196,524568,361663,108056,28026,824639,269315,440977,440977,765458, 988451,242440,948414,130873,773990,765458,130873,28026,853121,553636, 581069,82254,735536,833196,898562,898562,940783,988451,540613,317306, 623194,940783,571384,988451,108056,514374,97664};
			string moves              = "--+---+-+++-+-+---++-++-+---+-+--+-++";
			string expected__         = "NOT VALID";

			clock_t start__           = clock();
			string received__         = RouteIntersection().isValid(N, vector <int>(coords, coords + (sizeof coords / sizeof coords[0])), moves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			int coords[]              = ;
			string moves              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RouteIntersection().isValid(N, vector <int>(coords, coords + (sizeof coords / sizeof coords[0])), moves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int coords[]              = ;
			string moves              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RouteIntersection().isValid(N, vector <int>(coords, coords + (sizeof coords / sizeof coords[0])), moves);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int N                     = ;
			int coords[]              = ;
			string moves              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RouteIntersection().isValid(N, vector <int>(coords, coords + (sizeof coords / sizeof coords[0])), moves);
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
Little Dazdraperma likes to travel a lot. One day she made a route in an N-dimensional space. In this space each point is represented by N coordinates. The coordinates are indexed from 1 to N, inclusive. She started from the origin, i.e., a point where each coordinate is 0. Then she did several moves of the following type:

 First she chose a coordinate index, i.e., a number between 1 and N, inclusive.
 Then she jumped to a point where the coordinate with the chosen index is either increased or decreased by 1 and all other coordinates remain the same.

Now Dazdraperma wonders whether she has ever visited the same point twice. You will be given a vector <int> coords and a string moves representing her route. The i-th element of coords is the coordinate index she has chosen during her i-th move. If the coordinate with this index was increased during the i-th move, the i-th character of moves will be '+', and it will be '-' if this coordinate was decreased.


Return "VALID" if all points of her route were unique, including the first and the last points, and return "NOT VALID" otherwise. Two points A and B in N-dimensional space are different if there's an index i such that A's coordinate with index i and B's coordinate with index i are different.

DEFINITION
Class:RouteIntersection
Method:isValid
Parameters:int, vector <int>, string
Returns:string
Method signature:string isValid(int N, vector <int> coords, string moves)


CONSTRAINTS
-N will be between 1 and 1000000000 (109), inclusive.
-coords will contain between 1 and 50 elements, inclusive.
-Each element of coords will be between 1 and N, inclusive.
-moves will contain the same number of characters as the number of elements in coords.
-Each character in moves will be either '+' or '-'.


EXAMPLES

0)
1
{1}
"+"

Returns: "VALID"

Dazdraperma starts at (0) and then jumps to (1). The answer is "VALID".

1)
2
{1,2,1,2}
"++--"

Returns: "NOT VALID"

The route goes through 5 points:
(0,0) -> (1,0) -> (1,1) -> (0,1) -> (0,0). The point (0,0) was visited twice.

2)
3
{1,2,3,1,2}
"+++--"

Returns: "VALID"

(0,0,0) -> (1,0,0) -> (1,1,0) -> (1,1,1) -> (0,1,1) -> (0,0,1).

3)
344447
{132,51717,628,344447,628,51717,344447,2}
"+-++-+--"

Returns: "NOT VALID"

The repeated point doesn't have to be the first or the last point in the route.

4)
1
{1,1}
"+-"

Returns: "NOT VALID"



5)
990630
{833196,524568,361663,108056,28026,824639,269315,440977,440977,765458,
988451,242440,948414,130873,773990,765458,130873,28026,853121,553636,
581069,82254,735536,833196,898562,898562,940783,988451,540613,317306,
623194,940783,571384,988451,108056,514374,97664}
"--+---+-+++-+-+---++-++-+---+-+--+-++"

Returns: "NOT VALID"



*/

// END CUT HERE
