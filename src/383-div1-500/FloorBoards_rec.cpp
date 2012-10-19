
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


int H, W;
vector <string> vs;
int memo[11][1<<11];
int MAX = 999999;

class FloorBoards {
	
	// fieldにて、nowlineを引いた時、何本足されるか
	int addline(int beforeline, int nowline, int field){
		int res = 0;
		bool hor = false;
		REP(i, W){
			//横
			if(!(nowline>>i & 1) && !(field>>i & 1)){
				if(!hor) res++;
				hor = true;
				continue;
			}
			//縦
			if((nowline>>i & 1) && !(beforeline>>i & 1)) res++;
			//縦または'#'
			hor = false;
		}
		return res;
	}

	// vs[h]にて、h-1の線がbeforelineのとき、それ以降最低何本プラスするか
	int rec(int h, int beforeline){
		if(h == H) return 0;
		if(memo[h][beforeline] < MAX) return memo[h][beforeline];
		int res = MAX;
		int field = 0;
		REP(i, W) if(vs[h][i] == '#') field += (1<<i);
		REP(i, 1<<W){
			if(field&i) continue;
			res = min(res, rec(h+1, i) + addline(beforeline, i, field));
		}		
		memo[h][beforeline] = res;
		return res;
	}

public:
   int layout( vector <string> room ) {
	   vs = room;
	   H = SZ(vs);
	   W = SZ(vs[0]);
	   REP(i, H+1) REP(j, 1<<W) memo[i][j] = MAX;

	   return rec(0, 0);
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
			string room[]             = {"....."
,"....."
,"....."
,"....."
,"....."};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = FloorBoards().layout(vector <string>(room, room + (sizeof room / sizeof room[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string room[]             = {"......."
,".#..##."
,".#....."
,".#####."
,".##..#."
,"....###"};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = FloorBoards().layout(vector <string>(room, room + (sizeof room / sizeof room[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string room[]             = {"####"
,"####"
,"####"
,"####"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = FloorBoards().layout(vector <string>(room, room + (sizeof room / sizeof room[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string room[]             = {"...#.."
,"##...."
,"#.#..."
,".#...."
,"..#..."
,"..#..#"};
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = FloorBoards().layout(vector <string>(room, room + (sizeof room / sizeof room[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string room[]             = {".#...."
,"..#..."
,".....#"
,"..##.."
,"......"
,".#..#."};
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = FloorBoards().layout(vector <string>(room, room + (sizeof room / sizeof room[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string room[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FloorBoards().layout(vector <string>(room, room + (sizeof room / sizeof room[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string room[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FloorBoards().layout(vector <string>(room, room + (sizeof room / sizeof room[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string room[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FloorBoards().layout(vector <string>(room, room + (sizeof room / sizeof room[0])));
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
// You are building a house and are laying the floorboards in one of the rooms. Each floorboard is a rectangle 1 unit wide and can be of any positive integer length. Floorboards must be laid with their sides parallel to one of the sides of the room and cannot overlap. In addition, the room may contain features such as pillars, which lead to areas of the floor where no floorboards can be laid. The room is rectangular and the features all lie on a unit-square grid within it. You want to know the minimum number of floorboards that you need to completely cover the floor.
You are given a vector <string> room containing the layout of the room. Character j in element i of room represents the grid-square at position (i, j) and will be a '.' if this square needs to be covered with a floorboard or a '#' if the square is a feature where no floorboard can be laid. Return an int containing the minimum number of floorboards you need to completely cover the floor. 

DEFINITION
Class:FloorBoards
Method:layout
Parameters:vector <string>
Returns:int
Method signature:int layout(vector <string> room)


CONSTRAINTS
-room will contain between 1 and 10 elements, inclusive.
-Each element of room will contain between 1 and 10 characters, inclusive.
-Each element of room will contain the same number of characters.
-Each character in room will be a '.' or a '#'.


EXAMPLES

0)
{"....."
,"....."
,"....."
,"....."
,"....."}

Returns: 5

5 boards laid side-by-side will cover this square room.

1)
{"......."
,".#..##."
,".#....."
,".#####."
,".##..#."
,"....###"}

Returns: 7

A possible optimal layout could look like the following
|------
|#--##|
|#----|
|#####|
|##--#|
|---###
Each floorboard is represented by a consecutive horizontal sequence of '-' characters or a consecutive vertical sequence of '|' characters.

2)
{"####"
,"####"
,"####"
,"####"}

Returns: 0

This is a strange room, with no floor area to cover.

3)
{"...#.."
,"##...."
,"#.#..."
,".#...."
,"..#..."
,"..#..#"}

Returns: 9

An optimal pattern here is:

---#||
##--||
#-#|||
|#-|||
||#|||
||#||#

4)
{".#...."
,"..#..."
,".....#"
,"..##.."
,"......"
,".#..#."}

Returns: 9



*/

// END CUT HERE
