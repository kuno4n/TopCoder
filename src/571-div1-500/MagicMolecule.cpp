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

int mxrm;
int res;
int n;
VI mp;
vector <pair <int, int> > E;
bool used[55];

void rec(int removed, int idx_E){
    if(removed > mxrm) return;
    if(idx_E == SZ(E)){
        int tmp = 0;
        REP(i, n) if(!used[i]) tmp += mp[i];
        res = max(res, tmp);
        return;
    }
    int v1 = E[idx_E].first, v2 = E[idx_E].second;
    if(used[v1] || used[v2]) rec(removed, idx_E+1);
    else{
        used[v1] = true;
        rec(removed+1, idx_E+1);
        used[v1] = false;
        used[v2] = true;
        rec(removed+1, idx_E+1);
        used[v2] = false;
    }
    return;
}

class MagicMolecule {
	public:
	int maxMagicPower(vector <int> magicPower, vector <string> magicBond) {
        n = SZ(magicPower);
		mxrm = n/3;
        mp = magicPower;
        res = -1;
        E.clear();
        REP(i, 55) used[i] = false;
        for(int i = 0; i < n-1; i++) for(int j = i+1; j < n; j++) if(magicBond[i][j] == 'N') E.push_back(make_pair(i, j));
        rec(0, 0);
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
			int magicPower[]          = {1,2,3};
			string magicBond[]        = {"NYY","YNN","YNN"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = MagicMolecule().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int magicPower[]          = {1,1,1,1};
			string magicBond[]        = {"NNYY","NNYY","YYNN","YYNN"};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = MagicMolecule().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int magicPower[]          = {86,15,100,93,53,50};
			string magicBond[]        = {"NYYYYN","YNNNNY","YNNYYN","YNYNYN","YNYYNY","NYNNYN"};
			int expected__            = 332;

			clock_t start__           = clock();
			int received__            = MagicMolecule().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int magicPower[]          = {3969,9430,7242,8549,8190,8368,3704,9740,1691};
			string magicBond[]        = {"NYYYYYYYY","YNYYYYYYY","YYNYYYYYY","YYYNYYYYY","YYYYNYYYY","YYYYYNYYY","YYYYYYNNY","YYYYYYNNY","YYYYYYYYN"};
			int expected__            = 57179;

			clock_t start__           = clock();
			int received__            = MagicMolecule().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int magicPower[]          = ;
			string magicBond[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicMolecule().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int magicPower[]          = ;
			string magicBond[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicMolecule().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int magicPower[]          = ;
			string magicBond[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicMolecule().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])));
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

Your task is to improve Ciel's Magic Molecule. You have to choose a subset of the n Magic Atoms so that the following two conditions are met:

The number m of chosen atoms satisfies the inequality 3*m >= 2*n.
Each of the m*(m-1)/2 pairs of chosen atoms is connected by a Magic Bond.

Your goal is to maximize the total Magic Power stored in the chosen atoms. Compute and return the maximum total amount of power. If it is impossible to choose a subset of atoms that satisfies the above criteria, return -1 instead.

DEFINITION
Class:MagicMolecule
Method:maxMagicPower
Parameters:vector <int>, vector <string>
Returns:int
Method signature:int maxMagicPower(vector <int> magicPower, vector <string> magicBond)


NOTES
-The chosen subset is allowed to contain all n Magic Atoms.
-You are not supposed to maximize m; only the total amount of Magic Power matters.


CONSTRAINTS
-magicPower will contain between 2 and 50 elements, inclusive.
-Each element in magicPower will be between 1 and 100,000, inclusive.
-magicBond and magicPower will contain the same number of elements.
-Each element of magicBound will contain exactly n characters, where n is the number of elements in magicPower.
-Each element of magicBound will only contain the characters 'Y' and 'N'.
-For each valid i, magicBound[i][i] will be 'N'.
-For each valid i and j, magicBound[i][j] will be equal to magicBound[j][i].


EXAMPLES

0)
{1,2,3}
{"NYY","YNN","YNN"}

Returns: 4

There are three Magic Atoms.
There are two Magic Bonds: one connects atoms 0 and 1, the other connects atoms 0 and 2.
The first condition requires us to choose at least 2*3/3 = 2 atoms.
We cannot choose all three of them, because atoms 1 and 2 are not connected by a Magic Bond.
The optimal solution is to choose Magic Atoms 0 and 2.
Their total power is 1+3 = 4.

1)
{1,1,1,1}
{"NNYY","NNYY","YYNN","YYNN"}

Returns: -1

This time we must choose at least 3 Magic Atoms, but there is no valid solution.

2)
{86,15,100,93,53,50}
{"NYYYYN","YNNNNY","YNNYYN","YNYNYN","YNYYNY","NYNNYN"}

Returns: 332



3)
{3969,9430,7242,8549,8190,8368,3704,9740,1691}
{"NYYYYYYYY","YNYYYYYYY","YYNYYYYYY","YYYNYYYYY","YYYYNYYYY","YYYYYNYYY","YYYYYYNNY","YYYYYYNNY","YYYYYYYYN"}

Returns: 57179



*/

// END CUT HERE
