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

class CubeStickers {
	public:
	string isPossible(vector <string> sticker) {
		map <string, int> m; m.clear();
        REP(i, SZ(sticker)) m[sticker[i]]++;
        if(SZ(m) <= 2) return "NO";
        if(SZ(m) == 3){
            FIT(it, m) if((*it).second == 1) return "NO";
        }
        if(SZ(m) == 4){
            int cnt = 0;
            FIT(it, m) if((*it).second == 1) cnt++;
            if(cnt >= 3) return "NO";
        }
        return "YES";
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
			string sticker[]          = {"cyan","magenta","yellow","purple","black","white","purple"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = CubeStickers().isPossible(vector <string>(sticker, sticker + (sizeof sticker / sizeof sticker[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string sticker[]          = {"blue","blue","blue","blue","blue","blue","blue","blue","blue","blue"};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = CubeStickers().isPossible(vector <string>(sticker, sticker + (sizeof sticker / sizeof sticker[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string sticker[]          = {"red","yellow","blue","red","yellow","blue","red","yellow","blue"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = CubeStickers().isPossible(vector <string>(sticker, sticker + (sizeof sticker / sizeof sticker[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string sticker[]          = {"purple","orange","orange","purple","black","orange","purple"};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = CubeStickers().isPossible(vector <string>(sticker, sticker + (sizeof sticker / sizeof sticker[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string sticker[]          = {"white","gray","green","blue","yellow","red","target","admin"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = CubeStickers().isPossible(vector <string>(sticker, sticker + (sizeof sticker / sizeof sticker[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string sticker[]          = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CubeStickers().isPossible(vector <string>(sticker, sticker + (sizeof sticker / sizeof sticker[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string sticker[]          = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CubeStickers().isPossible(vector <string>(sticker, sticker + (sizeof sticker / sizeof sticker[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string sticker[]          = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CubeStickers().isPossible(vector <string>(sticker, sticker + (sizeof sticker / sizeof sticker[0])));
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
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.
Fox Ciel has a cube and some colored stickers.  You are given a vector <string> sticker, where the i-th element is the color of the i-th sticker.  Ciel wants to choose six of these stickers and apply one on each of the cube's faces.  Each pair of adjacent faces must have different colors.  Two faces are considered adjacent if they share an edge.

If this is possible, return "YES", otherwise, return "NO" (all quotes for clarity).


DEFINITION
Class:CubeStickers
Method:isPossible
Parameters:vector <string>
Returns:string
Method signature:string isPossible(vector <string> sticker)


CONSTRAINTS
-sticker will contain between 6 and 50 elements, inclusive.
-Each element of sticker will contain between 1 and 10 lowercase letters ('a'-'z'), inclusive.


EXAMPLES

0)
{"cyan","magenta","yellow","purple","black","white","purple"}

Returns: "YES"

One of the possible ways is shown in the following picture:



1)
{"blue","blue","blue","blue","blue","blue","blue","blue","blue","blue"}

Returns: "NO"



2)
{"red","yellow","blue","red","yellow","blue","red","yellow","blue"}

Returns: "YES"



3)
{"purple","orange","orange","purple","black","orange","purple"}

Returns: "NO"



4)
{"white","gray","green","blue","yellow","red","target","admin"}

Returns: "YES"



*/

// END CUT HERE
