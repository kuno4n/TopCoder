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

bool isSQ(LL l){
    LL tmp = (LL)sqrt(l);
    if(tmp * tmp == l) return true;
    else return false;
}

LL str2int(string s){
    LL res = 0;
    REP(i, SZ(s)){
        res *= 10;
        res += s[i]-'0';
    }
    return res;
}

class FindingSquareInTable {
	public:
	int findMaximalSquare(vector <string> table) {
		int h = SZ(table);
        int w = SZ(table[0]);
        LL res = -1;
        REP(i, h) REP(j, w) REP(ii, h) REP(jj, w){
            if(i == ii && j == jj){
                LL l = table[i][j] - '0';
                if(isSQ(l)) res = max(res, l);
            }
            else{
                string s = "";
                for(int x = i, y = j; x < h && x >= 0 && y < w && y >= 0; x += ii - i, y += jj - j){
                    s.push_back(table[x][y]);
                    if(isSQ(str2int(s))) res = max(res, str2int(s));
                }
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
			string table[]            = {"123",
 "456"};
			int expected__            = 64;

			clock_t start__           = clock();
			int received__            = FindingSquareInTable().findMaximalSquare(vector <string>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string table[]            = {"00000",
 "00000",
 "00200",
 "00000",
 "00000"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = FindingSquareInTable().findMaximalSquare(vector <string>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string table[]            = {"3791178",
 "1283252",
 "4103617",
 "8233494",
 "8725572",
 "2937261"};
			int expected__            = 320356;

			clock_t start__           = clock();
			int received__            = FindingSquareInTable().findMaximalSquare(vector <string>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string table[]            = {"135791357",
 "357913579",
 "579135791",
 "791357913",
 "913579135"}
;
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = FindingSquareInTable().findMaximalSquare(vector <string>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string table[]            = {"553333733",
 "775337775",
 "777537775",
 "777357333",
 "755553557",
 "355533335",
 "373773573",
 "337373777",
 "775557777"};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = FindingSquareInTable().findMaximalSquare(vector <string>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string table[]            = {"257240281",
 "197510846",
 "014345401",
 "035562575",
 "974935632",
 "865865933",
 "684684987",
 "768934659",
 "287493867"};
			int expected__            = 95481;

			clock_t start__           = clock();
			int received__            = FindingSquareInTable().findMaximalSquare(vector <string>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string table[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FindingSquareInTable().findMaximalSquare(vector <string>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string table[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FindingSquareInTable().findMaximalSquare(vector <string>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string table[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FindingSquareInTable().findMaximalSquare(vector <string>(table, table + (sizeof table / sizeof table[0])));
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
// You are given a vector <string> table representing a rectangular grid where each cell contains a digit.  The j-th character of the i-th element of table is the digit in the cell at row i, column j of the grid.

Consider a sequence of distinct cells in this table where the row numbers of the cells (in the order they appear in the sequence) form an arithmetic progression, and the column numbers also form an arithmetic progression.  Concatenate the digits in the cells of this sequence to obtain a number.

Among all numbers that can be obtained in this manner, find and return the largest perfect square (a square of an integer).  If there are no perfect squares, return -1 instead.

DEFINITION
Class:FindingSquareInTable
Method:findMaximalSquare
Parameters:vector <string>
Returns:int
Method signature:int findMaximalSquare(vector <string> table)


NOTES
-An arithmetic progression is a sequence of numbers where the difference between each number and the previous number is constant.


CONSTRAINTS
-table will contain between 1 and 9 elements, inclusive.
-Each element of table will contain between 1 and 9 characters, inclusive.
-All elements of table will be of the same length.
-Each element of table will contain only digits ('0'-'9').


EXAMPLES

0)
{"123",
 "456"}

Returns: 64

Several three-digit numbers can be obtained: 123, 321, 456, and 654, but none of them is a perfect square.
The largest obtainable perfect square is 64.

1)
{"00000",
 "00000",
 "00200",
 "00000",
 "00000"}

Returns: 0

0 is a perfect square. It is the largest one that can be obtained in this table.

2)
{"3791178",
 "1283252",
 "4103617",
 "8233494",
 "8725572",
 "2937261"}

Returns: 320356

Take the i-th digit of each row i, and you'll get 320356 = 566 ? 566.

3)
{"135791357",
 "357913579",
 "579135791",
 "791357913",
 "913579135"}


Returns: 9

It is known that a perfect square can't end with two odd digits. Therefore, the largest perfect square that contains only odd digits is 9.

4)
{"553333733",
 "775337775",
 "777537775",
 "777357333",
 "755553557",
 "355533335",
 "373773573",
 "337373777",
 "775557777"}

Returns: -1

There exists no perfect square that contains only digits 3, 5, and 7.

5)
{"257240281",
 "197510846",
 "014345401",
 "035562575",
 "974935632",
 "865865933",
 "684684987",
 "768934659",
 "287493867"}

Returns: 95481

The sequence of digits that forms 95481 is shown in bold:
257240281
197510846
014345401
035562575
974935632
865865933
684684987
768934659
287493867

*/

// END CUT HERE
