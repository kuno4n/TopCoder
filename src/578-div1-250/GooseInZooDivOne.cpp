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
//#include "cout.h"

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

#define MOD 1000000007

int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};

const int MAX_N = 2510;
LL nCr[MAX_N+1][MAX_N+1];

void makepas(){
    for(LL i=1; i<=MAX_N; i++){
        nCr[i][0] = 1;
        nCr[i][i] = 1;
        for(LL j=1; j<i; j++){
            nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % MOD;
        }
    }
}

long long modPow(long long x, long long y){
    long long r=1, a=x;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        y /= 2;
    }
    return r;
}



int h, w;
int d;
vector <string> f;

LL dfs(int x, int y){
    LL res = 0;
    REP(i, d+1){
        REP(k, d-i+1){
            REP(j, 4){
                int xx = x + i * dx[j];
                int yy = y + k * dy[j];
                if(xx >= 0 && xx < h && yy >= 0 && yy < w && f[xx][yy] == 'v'){
                    f[xx][yy] = '.';
                    res += dfs(xx, yy);
                }
            }
        }

//        int xx = x + i;
//        int yy = y + (d-i);
//        if(xx >= 0 && xx < h && yy >= 0 && yy < w && f[xx][yy] == 'v'){
//            f[xx][yy] = '.';
//            res += dfs(xx, yy);
//        }
//         xx = x - i;
//         yy = y + (d-i);
//        if(xx >= 0 && xx < h && yy >= 0 && yy < w && f[xx][yy] == 'v'){
//            f[xx][yy] = '.';
//            res += dfs(xx, yy);
//        }
//         xx = x + i;
//         yy = y - (d-i);
//        if(xx >= 0 && xx < h && yy >= 0 && yy < w && f[xx][yy] == 'v'){
//            f[xx][yy] = '.';
//            res += dfs(xx, yy);
//        }
//         xx = x - i;
//         yy = y - (d-i);
//        if(xx >= 0 && xx < h && yy >= 0 && yy < w && f[xx][yy] == 'v'){
//            f[xx][yy] = '.';
//            res += dfs(xx, yy);
//        }
    }
    return res + 1;
}

class GooseInZooDivOne {
	public:
	int count(vector <string> field, int dist) {
        h = SZ(field); w = SZ(field[0]);
        f = field; d = dist;
        LL ev = 0;
        LL od = 0;
        REP(i, h) REP(j, w) if(f[i][j] == 'v'){
            f[i][j] = '.';
            LL tmp = dfs(i, j);
            if(tmp & 1) od++;
            else ev++;
        }
        OUT(ev);OUT(od);
        makepas();
        LL res = 0;
        res += modPow(2, ev + max(0LL, od-1));
        return (res-1+MOD)%MOD;
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
			string field[]            = {"vvv"};
			int dist                  = 0;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = GooseInZooDivOne().count(vector <string>(field, field + (sizeof field / sizeof field[0])), dist);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string field[]            = {"."};
			int dist                  = 100;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = GooseInZooDivOne().count(vector <string>(field, field + (sizeof field / sizeof field[0])), dist);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string field[]            = {"vvv"};
			int dist                  = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = GooseInZooDivOne().count(vector <string>(field, field + (sizeof field / sizeof field[0])), dist);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string field[]            = {"v.v..................v............................"
,".v......v..................v.....................v"
,"..v.....v....v.........v...............v......v..."
,".........vvv...vv.v.........v.v..................v"
,".....v..........v......v..v...v.......v..........."
,"...................vv...............v.v..v.v..v..."
,".v.vv.................v..............v............"
,"..vv.......v...vv.v............vv.....v.....v....."
,"....v..........v....v........v.......v.v.v........"
,".v.......v.............v.v..........vv......v....."
,"....v.v.......v........v.....v.................v.."
,"....v..v..v.v..............v.v.v....v..........v.."
,"..........v...v...................v..............v"
,"..v........v..........................v....v..v..."
,"....................v..v.........vv........v......"
,"..v......v...............................v.v......"
,"..v.v..............v........v...............vv.vv."
,"...vv......v...............v.v..............v....."
,"............................v..v.................v"
,".v.............v.......v.........................."
,"......v...v........................v.............."
,".........v.....v..............vv.................."
,"................v..v..v.........v....v.......v...."
,"........v.....v.............v......v.v............"
,"...........v....................v.v....v.v.v...v.."
,"...........v......................v...v..........."
,"..........vv...........v.v.....................v.."
,".....................v......v............v...v...."
,".....vv..........................vv.v.....v.v....."
,".vv.......v...............v.......v..v.....v......"
,"............v................v..........v....v...."
,"................vv...v............................"
,"................v...........v........v...v....v..."
,"..v...v...v.............v...v........v....v..v...."
,"......v..v.......v........v..v....vv.............."
,"...........v..........v........v.v................"
,"v.v......v................v....................v.."
,".v........v................................v......"
,"............................v...v.......v........."
,"........................vv.v..............v...vv.."
,".......................vv........v.............v.."
,"...v.............v.........................v......"
,"....v......vv...........................v........."
,"....vv....v................v...vv..............v.."
,".................................................."
,"vv........v...v..v.....v..v..................v...."
,".........v..............v.vv.v.............v......"
,".......v.....v......v...............v............."
,"..v..................v................v....v......"
,".....v.....v.....................v.v......v......."};
			int dist                  = 3;
			int expected__            = 898961330;

			clock_t start__           = clock();
			int received__            = GooseInZooDivOne().count(vector <string>(field, field + (sizeof field / sizeof field[0])), dist);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			string field[]            = "vv";
			int dist                  = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = GooseInZooDivOne().count(vector <string>(field, field + (sizeof field / sizeof field[0])), dist);
			return verify_case(casenum__, expected__, received__, clock()-start__);
      }
            case 5: {
                string field[]            = {"vv", "..", ".v"};
                int dist                  = 1;
                int expected__            = 1;
                
                clock_t start__           = clock();
                int received__            = GooseInZooDivOne().count(vector <string>(field, field + (sizeof field / sizeof field[0])), dist);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 6: {
                string field[]            = {"v.v.", ".v.v", "...v"};
                int dist                  = 2;
                int expected__            = 1;
                
                clock_t start__           = clock();
                int received__            = GooseInZooDivOne().count(vector <string>(field, field + (sizeof field / sizeof field[0])), dist);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
/*      case 5: {
			string field[]            = ;
			int dist                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GooseInZooDivOne().count(vector <string>(field, field + (sizeof field / sizeof field[0])), dist);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string field[]            = ;
			int dist                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GooseInZooDivOne().count(vector <string>(field, field + (sizeof field / sizeof field[0])), dist);
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
// Crow Keith is looking at the goose cage in the zoo.
The bottom of the cage is divided into a grid of square cells.
There are some birds sitting on those cells (with at most one bird per cell).
Some of them are geese and all the others are ducks.

Keith wants to know which birds are geese.
He knows the following facts about them:

There is at least one goose in the cage.
The number of geese is even.
Each bird within Manhattan distance dist of any goose is also a goose.

 
You are given a vector <string> field and the int dist.
The array field describes the bottom of the cage.
Each character of each element of field describes one of the cells.
The meaning of individual characters follows.

The character 'v' represents a cell that contains a bird.
The character '.' represents an empty cell.


Return the number of possible sets of geese in the cage, modulo 1,000,000,007.
Note that for some of the test cases there can be no possible sets of geese.

DEFINITION
Class:GooseInZooDivOne
Method:count
Parameters:vector <string>, int
Returns:int
Method signature:int count(vector <string> field, int dist)


NOTES
-The Manhattan distance between cells (a,b) and (c,d) is |a-c| + |b-d|, where || denotes absolute value. In words, the Manhattan distance is the smallest number of steps needed to get from one cell to the other, given that in each step you can move to a cell that shares a side with your current cell.


CONSTRAINTS
-field will contain between 1 and 50 elements, inclusive.
-Each element of field will contain between 1 and 50 characters, inclusive.
-Each element of field will contain the same number of characters.
-Each character of each element of field will be 'v' or '.'.
-dist will be between 0 and 100, inclusive.


EXAMPLES

0)
{"vvv"}
0

Returns: 3

There are three possible sets of positions of geese: "ggd", "gdg", or "dgg" ('g' are geese and 'd' are ducks).

1)
{"."}
100

Returns: 0

The number of geese must be positive, but there are no birds in the cage.

2)
{"vvv"}
1

Returns: 0



3)
{"v.v..................v............................"
,".v......v..................v.....................v"
,"..v.....v....v.........v...............v......v..."
,".........vvv...vv.v.........v.v..................v"
,".....v..........v......v..v...v.......v..........."
,"...................vv...............v.v..v.v..v..."
,".v.vv.................v..............v............"
,"..vv.......v...vv.v............vv.....v.....v....."
,"....v..........v....v........v.......v.v.v........"
,".v.......v.............v.v..........vv......v....."
,"....v.v.......v........v.....v.................v.."
,"....v..v..v.v..............v.v.v....v..........v.."
,"..........v...v...................v..............v"
,"..v........v..........................v....v..v..."
,"....................v..v.........vv........v......"
,"..v......v...............................v.v......"
,"..v.v..............v........v...............vv.vv."
,"...vv......v...............v.v..............v....."
,"............................v..v.................v"
,".v.............v.......v.........................."
,"......v...v........................v.............."
,".........v.....v..............vv.................."
,"................v..v..v.........v....v.......v...."
,"........v.....v.............v......v.v............"
,"...........v....................v.v....v.v.v...v.."
,"...........v......................v...v..........."
,"..........vv...........v.v.....................v.."
,".....................v......v............v...v...."
,".....vv..........................vv.v.....v.v....."
,".vv.......v...............v.......v..v.....v......"
,"............v................v..........v....v...."
,"................vv...v............................"
,"................v...........v........v...v....v..."
,"..v...v...v.............v...v........v....v..v...."
,"......v..v.......v........v..v....vv.............."
,"...........v..........v........v.v................"
,"v.v......v................v....................v.."
,".v........v................................v......"
,"............................v...v.......v........."
,"........................vv.v..............v...vv.."
,".......................vv........v.............v.."
,"...v.............v.........................v......"
,"....v......vv...........................v........."
,"....vv....v................v...vv..............v.."
,".................................................."
,"vv........v...v..v.....v..v..................v...."
,".........v..............v.vv.v.............v......"
,".......v.....v......v...............v............."
,"..v..................v................v....v......"
,".....v.....v.....................v.v......v......."}
3

Returns: 898961330



*/

// END CUT HERE
