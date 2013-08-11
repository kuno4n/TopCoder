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

const int INF = (1<<29);
int d[30][30];

int start[30][12];

class History {
	public:
	string verifyClaims(vector <string> dynasties, vector <string> battles, vector <string> queries) {
		int n = SZ(dynasties), qn = SZ(queries);
        vector <pair<int, int> > bat1, bat2, qur1, qur2;
        
        MSET(start, 0);
        REP(i, n){
            stringstream ss(dynasties[i]);
            int j = 0;
            int st;
            while(ss >> start[i][j]){
                if(j == 0) st = start[i][j];
                start[i][j] -= st;
                j++;
            }
        }
        
        string s; REP(i, SZ(battles)) s += battles[i];
        stringstream ss(s); string t;
        while(ss >> t) bat1.push_back(make_pair(t[0]-'A', t[1]-'0')), bat2.push_back(make_pair(t[3]-'A', t[4]-'0'));
        
        REP(i, qn) qur1.push_back(make_pair(queries[i][0]-'A', queries[i][1]-'0')), qur2.push_back(make_pair(queries[i][3]-'A', queries[i][4]-'0'));
        
        string res = "";
        REP(q, qn){
            REP(i, n) REP(j, n) d[i][j] = INF;
            REP(i, n) d[i][i] = 0;
            
            int n1, m1, n2, m2;
            REP(i, SZ(bat1)){
                n1 = bat1[i].first, m1 = bat1[i].second, n2 = bat2[i].first, m2 = bat2[i].second;
                chmin(d[n1][n2], start[n1][m1+1] - start[n2][m2] - 1);
                chmin(d[n2][n1], start[n2][m2+1] - start[n1][m1] - 1);
            }
            n1 = qur1[q].first, m1 = qur1[q].second, n2 = qur2[q].first, m2 = qur2[q].second;
            chmin(d[n1][n2], start[n1][m1+1] - start[n2][m2] - 1);
            chmin(d[n2][n1], start[n2][m2+1] - start[n1][m1] - 1);
            
                      
            REP(k, n) REP(i, n) REP(j, n) chmin(d[i][j], d[i][k] + d[k][j]);
            bool ok = true;
            REP(i, n) ok &= d[i][i] >= 0;
            res.push_back(ok ? 'Y' : 'N');
            
//            return res;
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string dynasties[]        = {"1 2 4",
 "1 2 3"};
			string battles[]          = {"A1-B0"};
			string queries[]          = {"A0-B0",
 "A0-B1",
 "A1-B0",
 "A1-B1"};
			string expected__         = "NNYY";

			clock_t start__           = clock();
			string received__         = History().verifyClaims(vector <string>(dynasties, dynasties + (sizeof dynasties / sizeof dynasties[0])), vector <string>(battles, battles + (sizeof battles / sizeof battles[0])), vector <string>(queries, queries + (sizeof queries / sizeof queries[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string dynasties[]        = {"1000 2000 3000 10000",
 "600 650 2000",
 "1 1001 20001"};
			string battles[]          = {"B1-C0 A0-B0 A2-C1 B1-C1"};
			string queries[]          = {"A0-B1",
 "A1-B1",
 "A2-B1",
 "C0-A0",
 "B0-A2",
 "C1-B0"};
			string expected__         = "YYYYNN";

			clock_t start__           = clock();
			string received__         = History().verifyClaims(vector <string>(dynasties, dynasties + (sizeof dynasties / sizeof dynasties[0])), vector <string>(battles, battles + (sizeof battles / sizeof battles[0])), vector <string>(queries, queries + (sizeof queries / sizeof queries[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string dynasties[]        = {"1 4 5",
 "10 13 17"};
			string battles[]          = {"A0-B0 A0-B0 B0-A0"};
			string queries[]          = {"A1-B0",
 "A0-B1",
 "A1-B1"};
			string expected__         = "YYY";

			clock_t start__           = clock();
			string received__         = History().verifyClaims(vector <string>(dynasties, dynasties + (sizeof dynasties / sizeof dynasties[0])), vector <string>(battles, battles + (sizeof battles / sizeof battles[0])), vector <string>(queries, queries + (sizeof queries / sizeof queries[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string dynasties[]        = {"1 5 6",
 "1 2 5"};
			string battles[]          = {"A0",
 "-B0 A",
 "1-B1"};
			string queries[]          = {"A0-B0",
 "A1-B0",
 "A0-B1",
 "A1-B1"};
			string expected__         = "YNYY";

			clock_t start__           = clock();
			string received__         = History().verifyClaims(vector <string>(dynasties, dynasties + (sizeof dynasties / sizeof dynasties[0])), vector <string>(battles, battles + (sizeof battles / sizeof battles[0])), vector <string>(queries, queries + (sizeof queries / sizeof queries[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string dynasties[]        = {"2294 7344","366 384 449 965 1307 1415","307 473 648 688 1097","1145 1411 1569 2606","87 188 551 598 947 998 1917 1942"}
;
			string battles[]          = {"A0-B4 B4-E2 B3-E2 D2-E4 A0-E4 B1-C3 A0-E3 A0-E6 D0","-E2 B2-E1 B4-E3 B4-D0 D0-E3 A0-D1 B2-C3 B1-C3 B4-E","3 D0-E1 B3-D0 B3-E2"}
;
			string queries[]          = {"A0-C2","E6-C2","A0-E4","B3-C1","C0-D2","B0-C1","D1-C3","C3-D0","C1-E3","D1-A0"};
			string expected__         = "YNYNNYNNNY";

			clock_t start__           = clock();
			string received__         = History().verifyClaims(vector <string>(dynasties, dynasties + (sizeof dynasties / sizeof dynasties[0])), vector <string>(battles, battles + (sizeof battles / sizeof battles[0])), vector <string>(queries, queries + (sizeof queries / sizeof queries[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string dynasties[]        = ;
			string battles[]          = ;
			string queries[]          = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = History().verifyClaims(vector <string>(dynasties, dynasties + (sizeof dynasties / sizeof dynasties[0])), vector <string>(battles, battles + (sizeof battles / sizeof battles[0])), vector <string>(queries, queries + (sizeof queries / sizeof queries[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string dynasties[]        = ;
			string battles[]          = ;
			string queries[]          = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = History().verifyClaims(vector <string>(dynasties, dynasties + (sizeof dynasties / sizeof dynasties[0])), vector <string>(battles, battles + (sizeof battles / sizeof battles[0])), vector <string>(queries, queries + (sizeof queries / sizeof queries[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string dynasties[]        = ;
			string battles[]          = ;
			string queries[]          = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = History().verifyClaims(vector <string>(dynasties, dynasties + (sizeof dynasties / sizeof dynasties[0])), vector <string>(battles, battles + (sizeof battles / sizeof battles[0])), vector <string>(queries, queries + (sizeof queries / sizeof queries[0])));
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
// There were N ancient nations.
We will denote them using uppercase letters from 'A' to 'A'+N-1.

All nations were using the same calendar: the new year always started on the same day in each nation.
However, each nation used its own numbering of years.
For example, the years 47, 48, and 49 of nation A could correspond to years 123, 124, and 125 of nation B.

Each nation had several monarchs over its history.
For each nation, the monarchs are numbered starting from 0, in chronological order.
For example, "C0" denotes the earliest ruling monarch of the nation 'C'.
Each monarch started his rule on the first day of some year.
For each monarch we know the exact years when they ruled, according to the corresponding nation's calendar.

Manao wants to determine how the calendars of those nations correspond to each other.
To do this, he collected information about various battles that have occurred throughout the history.
For each battle we know the two monarchs that were involved.
For example, "C0-D3" denotes a battle between the monarchs "C0" and "D3".
The information that this battle has occurred tells us that "C0" and "D3" had to rule in the same year.

Manao now has to answer a bunch of questions.
Each question is of the following form:
"Given all the known information, is it possible that there was a battle between monarchs Xn and Ym?"

You are given the above information encoded as three vector <string>s: dynasties, battles, and queries.

For each i, element i of dynasties contains information about all monarchs of the nation 'A'+i:
the year when each of them started ruling, and finally the first year after the last monarch died.
More precisely, dynasties[i] is a space-separated list of increasing integers: the years described above.
For example, if dynasties[0]="42 47 55 63", nation 'A' had three monarchs: "A0" ruled in years 42-46, "A1" ruled in years 47-54, and "A2" ruled in years 55-62. 

Concatenate the elements of battles to obtain a single string.
The string will represent a space-separated list of battles that are known to have occurred.
Each battle will be given in the above format.

Each element of queries is a single battle given in the same format.

Return a string of the same length as the number of elements in queries.
For each i, character i of this string should be 'Y' if the battle in queries[i] is possible, and 'N' otherwise.

DEFINITION
Class:History
Method:verifyClaims
Parameters:vector <string>, vector <string>, vector <string>
Returns:string
Method signature:string verifyClaims(vector <string> dynasties, vector <string> battles, vector <string> queries)


NOTES
-The Constraints guarantee that there will be at most 10 monarchs in each dynasty. Thus, the number of each monarch will be a single digit.
-Each query should be processed separately. In other words, if you answer 'Y' to some query, this should not be considered as new information for the remaining queries.


CONSTRAINTS
-dynasties will contain between 2 and 26 elements, inclusive.
-Each element of dynasties will be between 3 and 50 characters long, inclusive.
-Each element of dynasties will be a space-separated list containing between 2 and 11 integers, inclusive.
-Each integer in dynasties will be between 1 and 99999, inclusive.
-The sequence of integers in each element of dynasties will be strictly increasing.
-battles will contain between 1 and 50 elements, inclusive.
-Each element of battles will be between 1 and 50 characters long, inclusive.
-The string B obtained by concatenating the elements of battles will be a space-separated list of tokens.
-Each token in the string B will be of the form "Xn-Ym", where X and Y are two distinct uppercase letters that represent valid nations, and n and m are digits that represent valid monarchs of those nations.
-The information given in dynasties and battles will not be contradictory.
-queries will contain between 1 and 50 elements, inclusive.
-Each element of queries will be of the form "Xn-Ym", where X and Y are two distinct uppercase letters that represent valid nations, and n and m are digits that represent valid monarchs of those nations.


EXAMPLES

0)
{"1 2 4",
 "1 2 3"}
{"A1-B0"}
{"A0-B0",
 "A0-B1",
 "A1-B0",
 "A1-B1"}

Returns: "NNYY"

There are two nations. Both had two monarchs. Nation A's monarch 0 ruled in year 1 according to this nation's year numbering. Nation A's monarch 1 ruled in years 2 and 3. Nation B's monarch 0 ruled in year 1 and its monarch 1 ruled in year 2, according to nation B's year numbering.

Manao knows for sure that a battle between nation A's monarch 1 and nation B's monarch 0 occured. He is interested whether the following battles could take place:


A0-B0. Since monarchs A0 and B0 both ruled for 1 year only, the battle between them would mean that their rulings coincided. However, B0 battled A1, thus he had to rule later than A0.
A0-B1. We have already seen that monarch B0 ruled later than A0. Therefore monarch B1 ruled even later and could not battle with A0.
A1-B0. This battle is already provided in battles.
A1-B1. This battle could occur if nation A's year 2 coincides with nation B's year 1.


1)
{"1000 2000 3000 10000",
 "600 650 2000",
 "1 1001 20001"}
{"B1-C0 A0-B0 A2-C1 B1-C1"}
{"A0-B1",
 "A1-B1",
 "A2-B1",
 "C0-A0",
 "B0-A2",
 "C1-B0"}

Returns: "YYYYNN"

Some monarchs can rule for thousands of years.

2)
{"1 4 5",
 "10 13 17"}
{"A0-B0 A0-B0 B0-A0"}
{"A1-B0",
 "A0-B1",
 "A1-B1"}

Returns: "YYY"

Note that a battle between the same monarchs can occur multiple times. Also note that they all may occur during the same year.

3)
{"1 5 6",
 "1 2 5"}
{"A0",
 "-B0 A",
 "1-B1"}
{"A0-B0",
 "A1-B0",
 "A0-B1",
 "A1-B1"}

Returns: "YNYY"

Note that you need to concatenate the elements of battles before parsing the tokens.

4)
{"2294 7344","366 384 449 965 1307 1415","307 473 648 688 1097","1145 1411 1569 2606","87 188 551 598 947 998 1917 1942"}

{"A0-B4 B4-E2 B3-E2 D2-E4 A0-E4 B1-C3 A0-E3 A0-E6 D0","-E2 B2-E1 B4-E3 B4-D0 D0-E3 A0-D1 B2-C3 B1-C3 B4-E","3 D0-E1 B3-D0 B3-E2"}

{"A0-C2","E6-C2","A0-E4","B3-C1","C0-D2","B0-C1","D1-C3","C3-D0","C1-E3","D1-A0"}

Returns: "YNYNNYNNNY"



*/

// END CUT HERE
