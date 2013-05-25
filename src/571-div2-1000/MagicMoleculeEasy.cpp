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

int res;
vector <pair<int , int > > E; //idx1, idx2
vector <pair<int , int > > V; //power, idx
VI M;
bool used[55];
int K;

void rec(int idx_E, int cnt_usedV, int sum){
    if(cnt_usedV > K) return;
    if(idx_E == SZ(E)){
        for(int i = 0; cnt_usedV < K; i++){
            if(!used[V[i].second]){
                sum += V[i].first;
                cnt_usedV++;
            }
        }
        res = max(res, sum);
        return;
    }
    int v1 = E[idx_E].first, v2 = E[idx_E].second;
    if(used[v1] || used[v2]) rec(idx_E+1, cnt_usedV, sum);
    else{
        used[v1] = true; rec(idx_E+1, cnt_usedV+1, sum+M[v1]); used[v1] = false;
        used[v2] = true; rec(idx_E+1, cnt_usedV+1, sum+M[v2]); used[v2] = false;
    }
    return;
}

class MagicMoleculeEasy {
	public:
	int maxMagicPower(vector <int> magicPower, vector <string> magicBond, int k) {
        res = -1;
        E.clear(); V.clear();
        REP(i, SZ(magicPower)) V.push_back(make_pair(magicPower[i], i));
        sort(ALL(V));reverse(ALL(V));
        REP(i, SZ(magicBond)) for(int j = i+1; j < SZ(magicBond); j++) if(magicBond[i][j] == 'Y') E.push_back(make_pair(i, j));
        REP(i, 55) used[i] = false;
        K = k; M = magicPower;
        
        rec(0, 0, 0);
        
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
			int magicPower[]          = {1, 2};
			string magicBond[]        = {"NY",
 "YN"};
			int k                     = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int magicPower[]          = {100, 1, 100};
			string magicBond[]        = {"NYN",
 "YNY",
 "NYN"};
			int k                     = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int magicPower[]          = {100, 1, 100};
			string magicBond[]        = {"NYN",
 "YNY",
 "NYN"};
			int k                     = 2;
			int expected__            = 200;

			clock_t start__           = clock();
			int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int magicPower[]          = {4, 7, 5, 8};
			string magicBond[]        = {"NYNY",
 "YNYN",
 "NYNY",
 "YNYN"};
			int k                     = 2;
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int magicPower[]          = {46474, 60848, 98282, 58073, 42670, 50373};
			string magicBond[]        = {"NYNNNY", "YNNYNY", "NNNYYY", "NYYNNN", "NNYNNN", "YYYNNN"};
			int k                     = 3;
			int expected__            = 209503;

			clock_t start__           = clock();
			int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int magicPower[]          = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			string magicBond[]        = {"NNYYYNYYNYNNY", "NNYNYYYYYYYNY", "YYNYYNYYYYYYY", "YNYNYYNYYYYYY",
 "YYYYNNYYYYYNY", "NYNYNNYYYYYNN", "YYYNYYNYYYYYY", "YYYYYYYNYNYYY",
 "NYYYYYYYNYYYY", "YYYYYYYNYNNNN", "NYYYYYYYYNNYN", "NNYYNNYYYNYNN", "YYYYYNYYYNNNN"};
			int k                     = 9;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int magicPower[]          = {1, 1};
			string magicBond[]        = {"NN", "NN"};
			int k                     = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			int magicPower[]          = {1,1,2,5,2,4,2};
			string magicBond[]        = {"NNNNNNN","NNYNNNN","NYNNNYN","NNNNNNY","NNNNNNN","NNYNNNN","NNNYNNN"};
			int k                     = 3;
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			int magicPower[]          = ;
			string magicBond[]        = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int magicPower[]          = ;
			string magicBond[]        = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int magicPower[]          = ;
			string magicBond[]        = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
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
// Fox Ciel is learning magical physics. Currently, she studies Magic Molecules. Each Magic Molecule consists of some Magic Atoms. Each Magic Atom stores some Magic Power, with different atoms possibly storing different amounts of power. Within the molecule, some pairs of atoms are connected by bidirectional Magic Bonds.

Ciel now has a Magic Molecule formed by n Magic Atoms. The atoms are numbered 0 through n-1, inclusive. You are given a vector <int> magicPower with n elements: For each i, the amount of power stored in the Magic Atom number i is magicPower[i]. You are also given a vector <string> magicBond with n elements, each containing n characters.
Character j of element i of magicBond is 'Y' if the Magic Atoms i and j are connected by a Magic Bond. Otherwise, character j of element i of magicBond is 'N'.

Your task is to improve Ciel's Magic Molecule. You have to choose a subset S of the n Magic Atoms so that the following two conditions are met:

You are given a int k. The subset S must contain exactly k atoms.
For each pair of the given n atoms that are connected by a Magic Bond, at least one of these two atoms must belong to S.

Your goal is to maximize the total Magic Power stored in the chosen atoms. Compute and return the maximum total amount of power. If it is impossible to choose a subset of atoms that satisfies the above criteria, return -1 instead.

DEFINITION
Class:MagicMoleculeEasy
Method:maxMagicPower
Parameters:vector <int>, vector <string>, int
Returns:int
Method signature:int maxMagicPower(vector <int> magicPower, vector <string> magicBond, int k)


CONSTRAINTS
-k will be between 1 and min(n, 14), inclusive, where n is the number of elements in magicPower.
-magicPower will contain between 2 and 50 elements, inclusive.
-Each element in magicPower will be between 1 and 100,000, inclusive.
-magicBond and magicPower will contain the same number of elements.
-Each element of magicBond will contain exactly n characters, where n is the number of elements in magicPower.
-Each element of magicBond will only contain the characters 'Y' and 'N'.
-For each valid i, magicBond[i][i] will be 'N'.
-For each valid i and j, magicBond[i][j] will be equal to magicBond[j][i].


EXAMPLES

0)
{1, 2}
{"NY",
 "YN"}
1

Returns: 2

There are two Magic Atoms and we need to select exactly one of them. Both selections are valid. It is better to choose atom 1 (0-based index) since it stores more power.

1)
{100, 1, 100}
{"NYN",
 "YNY",
 "NYN"}
1

Returns: 1

There is only one valid subset. It consists of atom 1.

2)
{100, 1, 100}
{"NYN",
 "YNY",
 "NYN"}
2

Returns: 200

The optimal solution is to choose atoms 0 and 2.

3)
{4, 7, 5, 8}
{"NYNY",
 "YNYN",
 "NYNY",
 "YNYN"}
2

Returns: 15



4)
{46474, 60848, 98282, 58073, 42670, 50373}
{"NYNNNY", "YNNYNY", "NNNYYY", "NYYNNN", "NNYNNN", "YYYNNN"}
3

Returns: 209503



5)
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
{"NNYYYNYYNYNNY", "NNYNYYYYYYYNY", "YYNYYNYYYYYYY", "YNYNYYNYYYYYY",
 "YYYYNNYYYYYNY", "NYNYNNYYYYYNN", "YYYNYYNYYYYYY", "YYYYYYYNYNYYY",
 "NYYYYYYYNYYYY", "YYYYYYYNYNNNN", "NYYYYYYYYNNYN", "NNYYNNYYYNYNN", "YYYYYNYYYNNNN"}
9

Returns: -1



6)
{1, 1}
{"NN", "NN"}
1

Returns: 1



7)
{1,1,2,5,2,4,2}
{"NNNNNNN","NNYNNNN","NYNNNYN","NNNNNNY","NNNNNNN","NNYNNNN","NNNYNNN"}
3

Returns: 11



*/

// END CUT HERE
