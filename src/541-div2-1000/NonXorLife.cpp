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

int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};


bool cur[200][200];
bool prv[200][200];

void upd(){
    MSET(cur, false);
    for(int i = 5; i < 195 ; i++) for(int j = 5; j < 195; j++)  REP(k, 5){
        if(prv[i+dx[k]][j+dy[k]]) cur[i][j]= true;
    }
}

void swp(){
    REP(i, 200) REP(j, 200) prv[i][j] = cur[i][j];
}

int cnt(){
    int res = 0;
    REP(i, 200) REP(j, 200) if(cur[i][j]) res++;
    return res;
}


class NonXorLife {
	public:
	int countAliveCells(vector <string> field, int K) {
        MSET(prv, false);
        int h = SZ(field), w = SZ(field[0]);
        REP(i, h) REP(j, w) if(field[i][j] == 'o') prv[i+70][j+70] = true;
        
        for(int turn = 1; turn <= 60; turn++){
            upd();
            if(turn == K) return cnt();
            swp();
        }
        
        int cnt60 = cnt();
        upd();
        int cnt61 = cnt();
        swp();
        upd();
        int cnt62 = cnt();
        
        int res = cnt60;
        int b = cnt61 - cnt60;
        int c = (cnt62-cnt61) - (cnt61-cnt60);
        for(int turn = 61; ; turn++){
            res += b;
            if(turn == K) return res;
            b += c;
        }
        
        
        return 0;
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
			string field[]            = {"oo"
,"o."};
			int K                     = 3;
			int expected__            = 36;

			clock_t start__           = clock();
			int received__            = NonXorLife().countAliveCells(vector <string>(field, field + (sizeof field / sizeof field[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string field[]            = {".."
,".."};
			int K                     = 23;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = NonXorLife().countAliveCells(vector <string>(field, field + (sizeof field / sizeof field[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string field[]            = {"o"};
			int K                     = 1000;
			int expected__            = 2002001;

			clock_t start__           = clock();
			int received__            = NonXorLife().countAliveCells(vector <string>(field, field + (sizeof field / sizeof field[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string field[]            = {"o.oo.ooo"
,"o.o.o.oo"
,"ooo.oooo"
,"o.o..o.o"
,"o.o..o.o"
,"o..oooo."
,"..o.o.oo"
,"oo.ooo.o"};
			int K                     = 1234;
			int expected__            = 3082590;

			clock_t start__           = clock();
			int received__            = NonXorLife().countAliveCells(vector <string>(field, field + (sizeof field / sizeof field[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string field[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NonXorLife().countAliveCells(vector <string>(field, field + (sizeof field / sizeof field[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string field[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NonXorLife().countAliveCells(vector <string>(field, field + (sizeof field / sizeof field[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string field[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NonXorLife().countAliveCells(vector <string>(field, field + (sizeof field / sizeof field[0])), K);
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
// Magical Girl Sayaka just learned about Conway's Game of Life. She is now thinking about new rules for this game.
In the Game of Life, an infinite plane is divided into a grid of unit square cells. 
At any moment, each cell is either alive or dead.
Every second the state of each cell changes according to a fixed rule.
In Sayaka's version of the game the following rule is used: 

 Consider any cell C. Look at the current states of the cell C and all four cells that share a side with C. 
 If at least one of these five cells are alive, cell C will be alive in the next second. Otherwise, cell C will be dead in the next second. 
 Note that each second the rule is applied on all cells at the same time.  
Sayaka wants to know how many cells are alive after K seconds.
You are given the int K and a vector <string> field that describes the initial state of the plane. field describes only some rectangular area of the plane. More precisely, character j of element i of field is 'o' if the cell in the i-th row of the j-th column of the rectangular area is alive, and it is '.' otherwise. Cells which aren't described in field is initially all dead. 
Return the number of alive cells after K seconds.

DEFINITION
Class:NonXorLife
Method:countAliveCells
Parameters:vector <string>, int
Returns:int
Method signature:int countAliveCells(vector <string> field, int K)


CONSTRAINTS
-field will contain between 1 and 50 elements, inclusive.
-Each elements of field will contain between 1 and 50 characters, inclusive.
-All elements of field will contain the same number of characters.
-Each character in each element of field will be either 'o' or '.'.
-K will be between 1 and 1500, inclusive.


EXAMPLES

0)
{"oo"
,"o."}
3

Returns: 36

The status after 3 seconds is below.
...oo...
..oooo..
.oooooo.
oooooooo
ooooooo.
.ooooo..
..ooo...
...o....

1)
{".."
,".."}
23

Returns: 0

All cells of the plane can be dead.

2)
{"o"}
1000

Returns: 2002001



3)
{"o.oo.ooo"
,"o.o.o.oo"
,"ooo.oooo"
,"o.o..o.o"
,"o.o..o.o"
,"o..oooo."
,"..o.o.oo"
,"oo.ooo.o"}
1234

Returns: 3082590



*/

// END CUT HERE
