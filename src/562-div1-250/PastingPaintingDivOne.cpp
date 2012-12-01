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

class PastingPaintingDivOne {
    int Nx;
    int Ny;
    vector<LL> res;
    vector<string> c;
    int t;
    
    void cnt(int x, int y, int j){
        if(c[x][y] == '.') return;
        int tmp = t;
//        OUT(c[x][y]);
//        OUT(j); 
        FOR(i, 1, j+1){
            if(i == t) break;
            if(c[x-i][y-i] != '.'){
                tmp = i;
                break;
            }
        }
        if(c[x][y] == 'R') res[0] += tmp;
        if(c[x][y] == 'G') res[1] += tmp;
        if(c[x][y] == 'B') res[2] += tmp;
        return;
    }
    
	public:
	vector<long long> countColors(vector <string> clipboard, int T) {
        res.push_back((LL)0);
        res.push_back((LL)0);
        res.push_back((LL)0);
        c = clipboard;
        Nx = SZ(c);
        Ny = SZ(c[0]);
        t = T;
        
        REP(i, Nx) {
            for(int j=0; i+j<Nx && j<Ny; j++){
                cnt(i+j, j, j);
            }
        }
        FOR(i, 1, Ny) {
            for(int j=0; i+j<Ny && j<Nx; j++){
                cnt(j, i+j, j);
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector<long long> &expected, const vector<long long> &received, clock_t elapsed) { 
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
			string clipboard[]        = {
"..G",
"R..",
"BG."
};
			int T                     = 3;
			long long expected__[]    = {3, 4, 3};

			clock_t start__           = clock();
			vector<long long> received__ = PastingPaintingDivOne().countColors(vector <string>(clipboard, clipboard + (sizeof clipboard / sizeof clipboard[0])), T);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string clipboard[]        = {
"R...",
"....",
"....",
"...R"
};
			int T                     = 2;
			long long expected__[]    = {4, 0, 0};

			clock_t start__           = clock();
			vector<long long> received__ = PastingPaintingDivOne().countColors(vector <string>(clipboard, clipboard + (sizeof clipboard / sizeof clipboard[0])), T);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string clipboard[]        = {"RGB"};
			int T                     = 100000;
			long long expected__[]    = {100000, 100000, 100000};

			clock_t start__           = clock();
			vector<long long> received__ = PastingPaintingDivOne().countColors(vector <string>(clipboard, clipboard + (sizeof clipboard / sizeof clipboard[0])), T);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string clipboard[]        = {"."};
			int T                     = 1000000000;
			long long expected__[]    = {0, 0, 0};

			clock_t start__           = clock();
			vector<long long> received__ = PastingPaintingDivOne().countColors(vector <string>(clipboard, clipboard + (sizeof clipboard / sizeof clipboard[0])), T);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			string clipboard[]        = {
"RB.",
".G."
}
;
			int T                     = 100;
			long long expected__[]    = {100, 1, 100};

			clock_t start__           = clock();
			vector<long long> received__ = PastingPaintingDivOne().countColors(vector <string>(clipboard, clipboard + (sizeof clipboard / sizeof clipboard[0])), T);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			string clipboard[]        = {
"..........G..........",
".........G.G.........",
"........G...G........",
".......G.....G.......",
"......G..B.B..G......",
".....G...B.B...G.....",
"....G...........G....",
"...G...R.....R...G...",
"..G.....RRRRRR....G..",
".G..........RR.....G.",
"GGGGGGGGGGGGGGGGGGGGG"
};
			int T                     = 1000000000;
			long long expected__[]    = {2000000018, 17000000048LL, 2000000005};

			clock_t start__           = clock();
			vector<long long> received__ = PastingPaintingDivOne().countColors(vector <string>(clipboard, clipboard + (sizeof clipboard / sizeof clipboard[0])), T);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string clipboard[]        = ;
			int T                     = ;
			long long expected__[]    = ;

			clock_t start__           = clock();
			vector<long long> received__ = PastingPaintingDivOne().countColors(vector <string>(clipboard, clipboard + (sizeof clipboard / sizeof clipboard[0])), T);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			string clipboard[]        = ;
			int T                     = ;
			long long expected__[]    = ;

			clock_t start__           = clock();
			vector<long long> received__ = PastingPaintingDivOne().countColors(vector <string>(clipboard, clipboard + (sizeof clipboard / sizeof clipboard[0])), T);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			string clipboard[]        = ;
			int T                     = ;
			long long expected__[]    = ;

			clock_t start__           = clock();
			vector<long long> received__ = PastingPaintingDivOne().countColors(vector <string>(clipboard, clipboard + (sizeof clipboard / sizeof clipboard[0])), T);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
// Cucumber Boy likes drawing pictures.  Today, he plans to draw a picture using a very simple graphics editor.

The editor has the following functions:

The canvas is an infinite two-dimensional grid of pixels.
There are only four colors: red, green, blue, and transparent. These are denoted 'R', 'G', 'B', and '.' (a period), respectively.
The editor has a clipboard that contains a rectangular picture.
The editor can take the picture in the clipboard and paste it onto any corresponding rectangle of the canvas. The user just has to select the pixel of the canvas where the upper left corner of the clipboard will be pasted.
When pasting the picture, the red, green, and blue pixels of the picture in the clipboard will overwrite their corresponding pixels on the canvas. The pixels that are transparent in the clipboard picture do not change the canvas.


At this moment, all pixels on the infinite canvas are transparent.  Cucumber Boy has already stored a picture in the clipboard.  You are given this picture as a vector <string> clipboard.

Cucumber Boy now wants to paste the clipboard picture onto the canvas exactly T times in a row.  For each i, when pasting the clipboard for the i-th time, he will choose the pixel (i,i) as the upper left corner of the pasted picture.

You are given the vector <string> clipboard and the int T.  Return a vector<long long> containing exactly three elements: the number of red, green, and blue pixels on the canvas after all the pasting is finished.

DEFINITION
Class:PastingPaintingDivOne
Method:countColors
Parameters:vector <string>, int
Returns:vector<long long>
Method signature:vector<long long> countColors(vector <string> clipboard, int T)


CONSTRAINTS
-clipboard will contain between 1 and 50 elements, inclusive.
-Each element of clipboard will contain between 1 and 50 characters, inclusive.
-Each element of clipboard will contain the same number of characters.
-Each character of each element of clipboard will be one of 'R', 'G', 'B', and '.'.
-T will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{
"..G",
"R..",
"BG."
}
3

Returns: {3, 4, 3 }



1)
{
"R...",
"....",
"....",
"...R"
}
2

Returns: {4, 0, 0 }



2)
{"RGB"}
100000

Returns: {100000, 100000, 100000 }



3)
{"."}
1000000000

Returns: {0, 0, 0 }



4)
{
"RB.",
".G."
}

100

Returns: {100, 1, 100 }



5)
{
"..........G..........",
".........G.G.........",
"........G...G........",
".......G.....G.......",
"......G..B.B..G......",
".....G...B.B...G.....",
"....G...........G....",
"...G...R.....R...G...",
"..G.....RRRRRR....G..",
".G..........RR.....G.",
"GGGGGGGGGGGGGGGGGGGGG"
}
1000000000

Returns: {2000000018, 17000000048, 2000000005 }

Note that the answers may overflow a 32-bit integer variable.


This is the image of clipboard in this example.

*/

// END CUT HERE
