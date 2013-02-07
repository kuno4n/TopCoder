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

class TheDevice {
	public:
	int minimumAdditional(vector <string> plates) {
		int n = SZ(plates);
        int len = SZ(plates[0]);
        int res = 0;
        REP(i, len){
            int zcnt = 0;
            int ocnt = 0;
            REP(j, n){
                if(plates[j][i] == '0') zcnt++;
                else ocnt++;
            }
            int tmp = 0;
            if(zcnt==0) tmp++;
            if(ocnt==0) tmp+=2;
            if(ocnt==1) tmp++;
            res = max(res, tmp);
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
			string plates[]           = {"010",
 "011",
 "101"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheDevice().minimumAdditional(vector <string>(plates, plates + (sizeof plates / sizeof plates[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string plates[]           = {"0",
 "1",
 "0",
 "1"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TheDevice().minimumAdditional(vector <string>(plates, plates + (sizeof plates / sizeof plates[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string plates[]           = {"01010101",
 "10101010"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheDevice().minimumAdditional(vector <string>(plates, plates + (sizeof plates / sizeof plates[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string plates[]           = {"10010101011",
 "00010101001",
 "00100010111",
 "00101010101",
 "01010111101"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheDevice().minimumAdditional(vector <string>(plates, plates + (sizeof plates / sizeof plates[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string plates[]           = {"1101001011010",
 "0010000010101",
 "1010101011110",
 "1101010100111",
 "1011111110111"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TheDevice().minimumAdditional(vector <string>(plates, plates + (sizeof plates / sizeof plates[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
          string plates[]           = {"000", "000"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheDevice().minimumAdditional(vector <string>(plates, plates + (sizeof plates / sizeof plates[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
          string plates[]           = {"111"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheDevice().minimumAdditional(vector <string>(plates, plates + (sizeof plates / sizeof plates[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			string plates[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheDevice().minimumAdditional(vector <string>(plates, plates + (sizeof plates / sizeof plates[0])));
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
// Manao works at a laboratory on a highly classified project. From time to time, he is given a special device and has to determine its exact structure. Every such device operates on special plates. There are M bits written on each of the plates from left to right. The device has two inputs and a screen. Each input requires a plate. When two plates are connected to the device, M bits of output appear on the screen. Each bit of output is either a binary OR, AND or XOR of the corresponding bits of the input plates. Manao's task is to determine what operation is carried out for each of the bits.

Manao has N plates. He is going to test the device on each possible pair of these plates and determine its structure by the outputs on the screen. It might be that the plates Manao has are not enough to uniquely identify every possible device. You are given vector <string> plates, where each element describes a plate Manao has. Return the minimum number of additional plates Manao needs to be able to determine the structure of any device.

DEFINITION
Class:TheDevice
Method:minimumAdditional
Parameters:vector <string>
Returns:int
Method signature:int minimumAdditional(vector <string> plates)


CONSTRAINTS
-plates will contain between 1 and 50 elements, inclusive.
-Each element of plates will be between 1 and 50 characters long, inclusive.
-All elements of plates will be of equal length.
-Each element of plates will contain characters from the set {'0', '1'} only.


EXAMPLES

0)
{"010",
 "011",
 "101"}

Returns: 1

It is possible to find two different devices such that no pair of Manao's plates will distinguish between them. To fix this it is sufficient to add one more plate. An example of such a plate is "101". There are also other plates that would work in its place.


1)
{"0",
 "1",
 "0",
 "1"}

Returns: 0

With these plates, Manao can test the output for every possible pair of bits, which allows him to distinguish between AND, OR and XOR.

2)
{"01010101",
 "10101010"}

Returns: 1



3)
{"10010101011",
 "00010101001",
 "00100010111",
 "00101010101",
 "01010111101"}

Returns: 1



4)
{"1101001011010",
 "0010000010101",
 "1010101011110",
 "1101010100111",
 "1011111110111"}

Returns: 0



*/

// END CUT HERE
