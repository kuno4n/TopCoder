
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
//#include "cout.h"

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

class TeamContest {
public:
   int worstRank( vector <int> s ) {
	   sort(s.begin(), s.begin()+3);
	   int me = s[0] + s[2];

	   VI ss;
	   FOR(i, 3, SZ(s)) ss.PB(s[i]);
	   sort(ALL(ss));

	   int res = 1;
	   while(1){
		   if(SZ(ss) == 0) break;
		   int i1, i2, i3;
		   i3 = SZ(ss)-1;
		   i1 = upper_bound(ALL(ss), me - ss[i3]) - ss.begin();
		   if(i1 >= i3 - 1) break;
		   i2 = i1 + 1;
		   res++;
		   VI tmp;
		   REP(i, SZ(ss)) if(i != i1 && i != i2 && i != i3) tmp.PB(ss[i]);
		   ss = tmp;
		   sort(ALL(ss));
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
			int strength[]            = {5, 7, 3, 5, 7, 3, 5, 7, 3};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TeamContest().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int strength[]            = {5, 7, 3} ;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TeamContest().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int strength[]            = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TeamContest().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int strength[]            = {3,9,4,6,2,6,1,6,9,1,4,1,3,8,5} ;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TeamContest().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int strength[]            = {53,47,88,79,99,75,28,54,65,14,22,13,11,31,43} ;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TeamContest().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int strength[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TeamContest().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int strength[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TeamContest().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int strength[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TeamContest().worstRank(vector <int>(strength, strength + (sizeof strength / sizeof strength[0])));
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
// Your university is holding a programming competition and your team is going to compete.

There are 3*N students in the university. They are numbered from 0 to 3*N-1. Each student has a certain strength which is a positive integer that characterizes his/her programming skills. You are given a vector <int> strength. The strength of student i is equal to strength[i].

Your team will consist of students 0, 1 and 2. Other 3*N-3 students will form N-1 more teams so that each team has exactly 3 members. The exact composition of other teams is not known yet. Each team has a strength that is calculated as follows: if it consists of members with strengths X, Y and Z, then the team's strength is equal to max{X, Y, Z} + min{X, Y, Z}.

You are interested how your team will rank by strength among the other teams. Formally, the rank of your team is defined as 1 + (the number of other teams that have a strictly greater strength than the strength of your team).

Return the maximum possible rank that your team may have after all students split into teams.

DEFINITION
Class:TeamContest
Method:worstRank
Parameters:vector <int>
Returns:int
Method signature:int worstRank(vector <int> strength)


CONSTRAINTS
-strength will contain between 3 and 48 elements, inclusive.
-The number of elements in strength will be divisible by 3.
-Each element of strength will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
{5, 7, 3, 5, 7, 3, 5, 7, 3}

Returns: 2

The strength of your team is max{5, 7, 3} + min{5, 7, 3} = 10. It is possible that one of the other teams will be stronger than your team. For example, if it consists of students with strengths 5, 7 and 7, then its strength will be 12. However, it is not possible that both other teams will be stronger than your team.


1)
{5, 7, 3}


Returns: 1

Just your team. No rivals.

2)
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}

Returns: 1

All teams (including yours) will have the same strength: 2.

3)
{3,9,4,6,2,6,1,6,9,1,4,1,3,8,5}


Returns: 3



4)
{53,47,88,79,99,75,28,54,65,14,22,13,11,31,43}


Returns: 3



*/

// END CUT HERE
