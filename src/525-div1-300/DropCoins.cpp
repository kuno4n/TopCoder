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

class DropCoins {
    vector <string> b;
    int k;
    
    int count(int x, int y, int h, int w){
        int res = 0;
        if(x+h > SZ(b) || y+w > SZ(b[0])) return -1;
        for(int i=x; i<x+h; i++){
            for(int j=y; j<y+w; j++){
                if(b[i][j] == 'o') res++;
            }
        }
        return res;
    }
    
	public:
	int getMinimum(vector <string> board, int K) {
		b = board;
        k = K;
        int res = 10000000;
        REP(x, SZ(b)){
            REP(y, SZ(b[0])){
                REP(h, SZ(b)+1){
                    REP(w, SZ(b[0])+1){
                        if(count(x,y,h,w) == K){
                            int tmp = 0;
                            int minh = min(x, SZ(b)-x-h);
                            int minw = min(y, SZ(b[0])-y-w);
                            tmp += minh*2;
                            tmp += minw*2;
                            tmp += (SZ(b)-h-minh);
                            tmp += (SZ(b[0])-w-minw);
                            res = min(res, tmp);
                        }
                    }
                }
            }
        }
        return res==10000000? -1 : res;
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
			string board[]            = {".o.."
,"oooo"
,"..o."}
;
			int K                     = 3;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {".....o"
,"......"
,"oooooo"
,"oooooo"
,"......"
,"o....."}
;
			int K                     = 12;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"...."
,".oo."
,".oo."
,"...."}
;
			int K                     = 3;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"......."
,"..ooo.."
,"ooooooo"
,".oo.oo."
,"oo...oo"}
;
			int K                     = 12;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"................."
,".ooooooo...oooo.."
,".ooooooo..oooooo."
,".oo.......oo..oo."
,".oo.......oo..oo."
,".ooooo.....oooo.."
,".ooooooo...oooo.."
,".....ooo..oo..oo."
,"......oo..oo..oo."
,".ooooooo..oooooo."
,".oooooo....oooo.."
,"................."}
;
			int K                     = 58;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
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
// There is a rectangle divided into 1x1 cells. Each cell is either empty or it contains a single coin. 

You can apply the following operation repeatedly.

First, choose one of the directions: up, down, left, or right. 
Then, move all coins in the chosen direction by exactly 1 cell. If this would cause a coin to move out of the rectangle, the coin drops out from the rectangle and disappears. 

Your objective in this problem is to apply the operations so that the number of coins remaining on the rectangle becomes exactly K.

You are given the int K and a vector <string> board that describes the initial state of the rectangle. More precisely, character j of element i of board is 'o' if i-th row of j-th column of the rectangle contains a coin, and it is '.' otherwise.

Return the minimum number of operations you have to perform. If the objective is impossible, return -1.

DEFINITION
Class:DropCoins
Method:getMinimum
Parameters:vector <string>, int
Returns:int
Method signature:int getMinimum(vector <string> board, int K)


CONSTRAINTS
-board will contain between 1 and 30 elements, inclusive.
-Each element of board will contain between 1 and 30 characters, inclusive.
-All elements of board will contain the same number of characters.
-Each character in each element of board will be either '.' or 'o'.
-K will be between 1 and 900, inclusive.


EXAMPLES

0)
{".o.."
,"oooo"
,"..o."}

3

Returns: 2

One of the optimal solutions is to move coins to the right twice.

1)
{".....o"
,"......"
,"oooooo"
,"oooooo"
,"......"
,"o....."}

12

Returns: 3

One of the optimal solutions:

move coins up (1 coin drops, 13 remain) 
move coins down 
move coins down again (1 coin drops, 12 remain) 


2)
{"...."
,".oo."
,".oo."
,"...."}

3

Returns: -1

It is impossible to make the number of remaining coins exactly 3.

3)
{"......."
,"..ooo.."
,"ooooooo"
,".oo.oo."
,"oo...oo"}

12

Returns: 4



4)
{"................."
,".ooooooo...oooo.."
,".ooooooo..oooooo."
,".oo.......oo..oo."
,".oo.......oo..oo."
,".ooooo.....oooo.."
,".ooooooo...oooo.."
,".....ooo..oo..oo."
,"......oo..oo..oo."
,".ooooooo..oooooo."
,".oooooo....oooo.."
,"................."}

58

Returns: 6



*/

// END CUT HERE
