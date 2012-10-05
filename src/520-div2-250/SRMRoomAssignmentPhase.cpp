
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

class SRMRoomAssignmentPhase {
public:
   int countCompetitors( vector <int> ratings, int K ) {
	   int me = ratings[0];
	   sort(ALL(ratings));
	   int m = 0;
	   REP(i, SZ(ratings)) if(ratings[i] == me) m = i%K;
	   int res = 0;
	   for(int i=1; i<SZ(ratings); i++){
		   if(i%K==m && me<ratings[i]) res++;
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
			int ratings[]             = {491, 981, 1199, 763, 994, 879, 888};
			int K                     = 3;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int ratings[]             = {1024, 1000, 600};
			int K                     = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int ratings[]             = {505, 679, 900, 1022};
			int K                     = 2;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int ratings[]             = {716, 58, 1000, 1004, 912, 822, 453, 1100, 558};
			int K                     = 3;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int ratings[]             = {422, 623, 1023, 941, 882, 776, 852, 495, 803, 622, 618, 532, 751, 500};
			int K                     = 4;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int ratings[]             = {1197, 1198, 1196, 1195, 1199};
			int K                     = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int ratings[]             = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int ratings[]             = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int ratings[]             = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
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
// Mr. Dengklek introduced you to an online programming contest called SRM (Special Round Match)!

There are N coders in the contest, including you. Each coder has a skill measurement called rating. This information is given in ratings, where ratings[0] is your rating and ratings[1] through ratings[N-1] are the ratings of the other coders. Ratings of all coders are pairwise distinct.

You are now in the room assignment phase of the contest. There are K available rooms. Each coder will be assigned to exactly one room in the following way: the coders, in descending order of their ratings, are assigned one-by-one to rooms 1, 2, ..., K, 1, 2, ..., K, ... and so on in that order. See the examples for further clarification.

You wish to win your room, so you wonder how many stronger competitors you have. Return the number of coders in your room who have higher ratings than yours.

DEFINITION
Class:SRMRoomAssignmentPhase
Method:countCompetitors
Parameters:vector <int>, int
Returns:int
Method signature:int countCompetitors(vector <int> ratings, int K)


CONSTRAINTS
-ratings will contain between 2 and 50 elements, inclusive.
-Each element of ratings will be between 0 and 1199, inclusive.
-All elements of ratings will be distinct.
-K will be between 1 and the number of elements in ratings, inclusive.


EXAMPLES

0)
{491, 981, 1199, 763, 994, 879, 888}
3

Returns: 2

Here is the room assignment for all coders.

Room 1 coders' ratings:

1199
888
491


Room 2 coders' ratings:

994
879


Room 3 coders' ratings:

981
763


You are in Room 1, and there are 2 coders with greater ratings than yours.



1)
{1024, 1000, 600}
1

Returns: 0

You are the highest rated coder in Room 1.

2)
{505, 679, 900, 1022}
2

Returns: 1

You are the lowest rated coder in Room 2.

3)
{716, 58, 1000, 1004, 912, 822, 453, 1100, 558}
3

Returns: 1

You are the second highest rated coder in Room 3.

4)
{422, 623, 1023, 941, 882, 776, 852, 495, 803, 622, 618, 532, 751, 500}
4

Returns: 3



5)
{1197, 1198, 1196, 1195, 1199}
1

Returns: 2



*/

// END CUT HERE
