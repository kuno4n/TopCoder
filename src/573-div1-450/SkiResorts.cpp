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

vector <string> R;
VI ALT, sort_ALT;

const LL INF = (1LL<<60);
const int MAX_V = 50;
LL d[MAX_V][MAX_V];
bool used[MAX_V][MAX_V];
int V;

void dijk(){
    while(1){
        int node = -1;
        int alt_id = -1;
        LL dd = INF;
        REP(i, V) REP(j, V){
            if(!used[i][j] && d[i][j] < dd){
                node = i;
                alt_id = j;
                dd = d[i][j];
            }
        }
        if(node == -1 && alt_id == -1) break;
        used[node][alt_id] = true;
        REP(i, V) if(R[node][i] == 'Y') REP(j, alt_id+1){
//            if(sort_ALT[j] > sort_ALT[alt_id]) break;
            d[i][j] = min(d[i][j], dd + abs((LL)ALT[i] - sort_ALT[j]));
        }
    }
    return;
}

class SkiResorts {
	public:
	long long minCost(vector <string> road, vector <int> altitude) {
		R = road;
        V = SZ(R);
        ALT = altitude;
        sort_ALT = altitude; sort(ALL(sort_ALT));
        
        REP(i, V) REP(j, V) used[i][j] = false;
        REP(i, V) REP(j, V) d[i][j] = INF;
        REP(i, V) d[0][i] = abs((LL)ALT[0] - sort_ALT[i]);
        
        dijk();
        LL res = INF;
        REP(i, V) res = min(res, d[V-1][i]);
        return (res == INF ? -1 : res);
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			string road[]             = {"NYN",
 "YNY",
 "NYN"};
			int altitude[]            = {30, 20, 10};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = SkiResorts().minCost(vector <string>(road, road + (sizeof road / sizeof road[0])), vector <int>(altitude, altitude + (sizeof altitude / sizeof altitude[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string road[]             = {"NY",
 "YN"};
			int altitude[]            = {10, 20};
			long long expected__      = 10;

			clock_t start__           = clock();
			long long received__      = SkiResorts().minCost(vector <string>(road, road + (sizeof road / sizeof road[0])), vector <int>(altitude, altitude + (sizeof altitude / sizeof altitude[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string road[]             = {"NYN",
 "YNN",
 "NNN"};
			int altitude[]            = {573, 573, 573};
			long long expected__      = -1;

			clock_t start__           = clock();
			long long received__      = SkiResorts().minCost(vector <string>(road, road + (sizeof road / sizeof road[0])), vector <int>(altitude, altitude + (sizeof altitude / sizeof altitude[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string road[]             = {"NNYNNYYYNN",
 "NNNNYNYNNN",
 "YNNNNYYNNN",
 "NNNNNNYNYY",
 "NYNNNNNNYY",
 "YNYNNNNYNN",
 "YYYYNNNYNN",
 "YNNNNYYNNN",
 "NNNYYNNNNN",
 "NNNYYNNNNN"};
			int altitude[]            = {7, 4, 13, 2, 8, 1, 8, 15, 5, 15};
			long long expected__      = 12;

			clock_t start__           = clock();
			long long received__      = SkiResorts().minCost(vector <string>(road, road + (sizeof road / sizeof road[0])), vector <int>(altitude, altitude + (sizeof altitude / sizeof altitude[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string road[]             = ;
			int altitude[]            = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = SkiResorts().minCost(vector <string>(road, road + (sizeof road / sizeof road[0])), vector <int>(altitude, altitude + (sizeof altitude / sizeof altitude[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string road[]             = ;
			int altitude[]            = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = SkiResorts().minCost(vector <string>(road, road + (sizeof road / sizeof road[0])), vector <int>(altitude, altitude + (sizeof altitude / sizeof altitude[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string road[]             = ;
			int altitude[]            = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = SkiResorts().minCost(vector <string>(road, road + (sizeof road / sizeof road[0])), vector <int>(altitude, altitude + (sizeof altitude / sizeof altitude[0])));
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
// Fox Ciel is the owner of a ski resort. The ski resort has N places numbered 0 through N-1. There are some bidirectional roads between pairs of places. You are given a vector <string> roads. If the j-th character of the i-th element of roads is 'Y', there is a bidirectional road that connects place i and place j. If it is 'N', there's no road between them. You are also given a vector <int> altitude. The i-th element of altitude is the altitude of the place i.


You can go directly from the place i to the place j by skiing if there is a bidirectional road between them and the altitude of the place i is higher than or equal to the altitude of the place j. Ciel wants to reconstruct the ski resort so that place N-1 is reachable (not necessarily directly) from place 0 by skiing. In the reconstruction, Ciel can change the altitude of some places. The cost of changing the altitude of a place from x to y is |x - y| units of money, where || denotes the absolute value.


Return the minimal cost required for the reconstruction. If it is impossible to reach place N-1 from place 0 even after the reconstruction, return -1.

DEFINITION
Class:SkiResorts
Method:minCost
Parameters:vector <string>, vector <int>
Returns:long long
Method signature:long long minCost(vector <string> road, vector <int> altitude)


CONSTRAINTS
-road will contain between 2 and 50 elements, inclusive.
-Each element of road will contain exactly N characters, where N is the number of elements of road.
-Each character in road will be either 'Y' or 'N'.
-For each valid i, the i-th character of the i-th element of road will be 'N'.
-For each valid pair (i, j), the i-th character of the j-th element of road and the j-th character of the i-th element of road will be equal.
-altitude will contain exactly N elements.
-Each element of altitude will be between 0 and 1,000,000,000, inclusive.


EXAMPLES

0)
{"NYN",
 "YNY",
 "NYN"}
{30, 20, 10}

Returns: 0

It is possible to reach place 2 from place 0 even without the reconstruction by following the path (place 0) -> (place 1) -> (place 2).

1)
{"NY",
 "YN"}
{10, 20}

Returns: 10

For example, Ciel can change the altitude of both places to 15. The cost is |10 - 15| + |20 - 15| = 10.

2)
{"NYN",
 "YNN",
 "NNN"}
{573, 573, 573}

Returns: -1

Place 2 is not reachable from place 0.

3)
{"NNYNNYYYNN",
 "NNNNYNYNNN",
 "YNNNNYYNNN",
 "NNNNNNYNYY",
 "NYNNNNNNYY",
 "YNYNNNNYNN",
 "YYYYNNNYNN",
 "YNNNNYYNNN",
 "NNNYYNNNNN",
 "NNNYYNNNNN"}
{7, 4, 13, 2, 8, 1, 8, 15, 5, 15}

Returns: 12



*/

// END CUT HERE
