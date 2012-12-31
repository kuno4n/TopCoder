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

vector <string> tmp, p;
int h, w;
int res;

void paintr(int he, int wi){
    res++;
    while(wi < w && (p[he][wi] == 'R' || p[he][wi] == 'G') ){
        if(tmp[he][wi] == '.') tmp[he][wi] = 'R';
        else if(tmp[he][wi] == 'B') tmp[he][wi] = 'G';
        wi++;
    }
    return;
}

void paintb(int he, int wi){
    res++;
    while(he < h && (p[he][wi] == 'B' || p[he][wi] == 'G') ){
        if(tmp[he][wi] == '.') tmp[he][wi] = 'B';
        else if(tmp[he][wi] == 'R') tmp[he][wi] = 'G';
        he++;
    }
    return;
}

class ColoredStrokes {
	public:
	int getLeast(vector <string> picture) {
		tmp.clear(); p.clear(); p = picture;
        h = SZ(picture); w = SZ(picture[0]);
        res = 0;
        string s = "";
        REP(i, w) s += '.';
        REP(j, h) tmp.push_back(s);
        
        REP(he, h){
            REP(wi, w){
                if(p[he][wi] == 'R' && tmp[he][wi] == '.') paintr(he,wi);
                if(p[he][wi] == 'B' && tmp[he][wi] == '.') paintb(he,wi);
                if(p[he][wi] == 'G' && tmp[he][wi] == 'R') paintb(he,wi);
                if(p[he][wi] == 'G' && tmp[he][wi] == 'B') paintr(he,wi);
                if(p[he][wi] == 'G' && tmp[he][wi] == '.') {paintr(he,wi);paintb(he,wi);}
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
			string picture[]          = {"...",
 "..."};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string picture[]          = {"..B.",
 "..B."};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string picture[]          = {".BB."};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string picture[]          = {"...B..",
 ".BRGRR",
 ".B.B.."};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string picture[]          = {"...B..",
 ".BRBRR",
 ".B.B.."};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string picture[]          = {"GR",
 "BG"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string picture[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string picture[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string picture[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast(vector <string>(picture, picture + (sizeof picture / sizeof picture[0])));
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
// Manao has a bitmap H pixels high and W pixels wide. Initially, each of the pixels is white. Manao draws several (possibly zero) horizontal and/or vertical strokes. A stroke is a line segment 1 pixel thick and 1 or more pixels long. Manao only draws horizontal strokes with red color and vertical strokes with blue. He can paint a one pixel long stroke with either red or blue color, and the stroke will be considered horizontal if red and vertical if blue. Manao never draws two horizontal or two vertical strokes that overlap. If a horizontal stroke and a vertical stroke cross, the pixel at their intersection becomes green.

You're given a vector <string> picture denoting the bitmap after Manao's drawing experiments. The x-th character of the y-th element of picture describes the color of the pixel at coordinates (x, y) of the bitmap, where (0, 0) is the pixel at the top left corner and (W-1, H-1) is the pixel at the bottom right corner.  'R' is red, 'G' is green, 'B' is blue and '.' is white. Return the least possible number of strokes needed to obtain the given picture.

DEFINITION
Class:ColoredStrokes
Method:getLeast
Parameters:vector <string>
Returns:int
Method signature:int getLeast(vector <string> picture)


CONSTRAINTS
-picture will contain between 1 and 50 elements, inclusive.
-Each element of picture will be between 1 and 50 characters long, inclusive.
-All elements of picture will have equal length.
-Each character in picture will be 'R', 'G', 'B' or '.'.


EXAMPLES

0)
{"...",
 "..."}

Returns: 0

The picture is blank, Manao made no strokes.

1)
{"..B.",
 "..B."}

Returns: 1

A single vertical stroke is enough.

2)
{".BB."}

Returns: 2

Since only vertical strokes are painted with blue color, this picture needs two strokes.

3)
{"...B..",
 ".BRGRR",
 ".B.B.."}

Returns: 3

One horizontal and two vertical strokes are necessary for this masterpiece.

4)
{"...B..",
 ".BRBRR",
 ".B.B.."}

Returns: 4

This is the same picture as in the previous case with pixel (3,1) colored blue instead of green. Therefore, a single horizontal stroke won't help.

5)
{"GR",
 "BG"}

Returns: 4



*/

// END CUT HERE
