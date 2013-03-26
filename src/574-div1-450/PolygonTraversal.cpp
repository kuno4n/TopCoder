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

LL dp[1<<18][18];

class PolygonTraversal {
public:
	long long count(int N, vector <int> points) {
		MSET(dp, 0);
        REP(i, SZ(points)) points[i]--;
        
        int mask = 0;
        REP(i, SZ(points)) mask |= (1<<points[i]);
        dp[mask][points[SZ(points)-1]] = 1;
        
        REP(i, (1<<N)) REP(j, N){
            if(dp[i][j] == 0) continue;
            REP(k, N){
                if(1<<k & i) continue;
                int pt1 = max(k, j), pt2 = min(k, j);
                int mask1 = (1<<pt1) - (1<<(pt2+1));
                int mask2 = (1<<N)-1 - ((1<<pt1+1)-(1<<pt2));
                if((mask1 & i) == 0 || (mask2 & i) == 0) continue;
                dp[i|(1<<k)][k] += dp[i][j];
            }
        }
        
        LL res = 0;
        REP(i, N) if(i != (points[0]+1)%N && i != (points[0]-1+N)%N) res += dp[(1<<N)-1][i];
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
                int N                     = 5;
                int points[]              = {1, 3, 5};
                long long expected__      = 1;
                
                clock_t start__           = clock();
                long long received__      = PolygonTraversal().count(N, vector <int>(points, points + (sizeof points / sizeof points[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 1: {
                int N                     = 6;
                int points[]              = {1, 4, 2};
                long long expected__      = 1;
                
                clock_t start__           = clock();
                long long received__      = PolygonTraversal().count(N, vector <int>(points, points + (sizeof points / sizeof points[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 2: {
                int N                     = 7;
                int points[]              = {2, 4, 7};
                long long expected__      = 2;
                
                clock_t start__           = clock();
                long long received__      = PolygonTraversal().count(N, vector <int>(points, points + (sizeof points / sizeof points[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 3: {
                int N                     = 7;
                int points[]              = {1, 2, 3, 4, 6, 5};
                long long expected__      = 0;
                
                clock_t start__           = clock();
                long long received__      = PolygonTraversal().count(N, vector <int>(points, points + (sizeof points / sizeof points[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 4: {
                int N                     = 18;
                int points[]              = {1, 7, 18};
                long long expected__      = 4374612736LL;
                
                clock_t start__           = clock();
                long long received__      = PolygonTraversal().count(N, vector <int>(points, points + (sizeof points / sizeof points[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 5: {
                int N                     = 7;
                int points[]              = {1, 3, 6};
                long long expected__      = 2;
                
                clock_t start__           = clock();
                long long received__      = PolygonTraversal().count(N, vector <int>(points, points + (sizeof points / sizeof points[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
                
                // custom cases
                
                /*      case 5: {
                 int N                     = ;
                 int points[]              = ;
                 long long expected__      = ;
                 
                 clock_t start__           = clock();
                 long long received__      = PolygonTraversal().count(N, vector <int>(points, points + (sizeof points / sizeof points[0])));
                 return verify_case(casenum__, expected__, received__, clock()-start__);
                 }*/
                /*      case 6: {
                 int N                     = ;
                 int points[]              = ;
                 long long expected__      = ;
                 
                 clock_t start__           = clock();
                 long long received__      = PolygonTraversal().count(N, vector <int>(points, points + (sizeof points / sizeof points[0])));
                 return verify_case(casenum__, expected__, received__, clock()-start__);
                 }*/
                /*      case 7: {
                 int N                     = ;
                 int points[]              = ;
                 long long expected__      = ;
                 
                 clock_t start__           = clock();
                 long long received__      = PolygonTraversal().count(N, vector <int>(points, points + (sizeof points / sizeof points[0])));
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
 // Manao had a sheet of paper. He drew N points on it, which corresponded to vertices of a regular N-gon. He numbered the vertices from 1 to N in clockwise order.
 
 After that, Manao connected several pairs of points with straight line segments. Namely, he connected points points[i] and points[i+1] for each i between 0 and M-2, where M is the number of elements in points. Note that all numbers in points are distinct.
 
 Manao took a look at what he had drawn and decided to continue his traversal by adding every remaining point of the polygon to it and then returning to point points[0]. In other words, Manao is going to connect point points[M-1] with some point tail[0] which is not in points, then connect tail[0] with some point tail[1] which is neither in points nor in tail, and so on. In the end, he will connect point tail[N-M-1] with point points[0], thus completing the traversal.
 
 Manao is really fond of intersections, so he wants to continue the traversal in such a way that every new line segment he draws intersects with at least one of the previously drawn line segments. (Note that the set of previously drawn segments includes not only the original set of segments, but also the new segments drawn before the current one.) Count and return the number of ways in which he can complete the traversal.
 
 DEFINITION
 Class:PolygonTraversal
 Method:count
 Parameters:int, vector <int>
 Returns:long long
 Method signature:long long count(int N, vector <int> points)
 
 
 CONSTRAINTS
 -N will be between 4 and 18, inclusive.
 -points will contain between 2 and N-1 elements, inclusive.
 -Each element of points will be between 1 and N, inclusive.
 -The elements of points will be distinct.
 
 
 EXAMPLES
 
 0)
 5
 {1, 3, 5}
 
 Returns: 1
 
 The only way for Manao to complete the traversal is:
 
 
 
 1)
 6
 {1, 4, 2}
 
 Returns: 1
 
 The only way to complete the traversal is to visit vertices {6, 3, 5, 1}, in order.
 Note that the segment 5-1 does not intersect the original two segments (1-4 and 4-2), but it does intersect segments 2-6 and 6-3 which were both added before 5-1.
 
 2)
 7
 {2, 4, 7}
 
 Returns: 2
 
 The two possible tails are:
 
 3-5-1-6-2
 3-6-1-5-2
 
 
 3)
 7
 {1, 2, 3, 4, 6, 5}
 
 Returns: 0
 
 Manao needs to connect points 5 and 7 and then connect points 7 and 1. Obviously, segment 1-7 will not intersect with any other segment.
 
 4)
 18
 {1, 7, 18}
 
 Returns: 4374612736
 
 
 
 */

// END CUT HERE
