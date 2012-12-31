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

class PermutationSignature {
	public:
	vector <int> reconstruct(string signature) {
		VI res; res.clear();
        res.push_back(1);
        int mxptr = 0;
        REP(i, SZ(signature)){
            if(signature[i] == 'I') {
                res.push_back(i+2);
                mxptr = SZ(res) - 1;
            }
            else{
                FOR(j, mxptr, SZ(res)) res[j]++;
                res.push_back(res[SZ(res)-1] - 1);
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
			string signature          = "IIIII";
			int expected__[]          = {1, 2, 3, 4, 5, 6 };

			clock_t start__           = clock();
			vector <int> received__   = PermutationSignature().reconstruct(signature);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string signature          = "DI";
			int expected__[]          = {2, 1, 3 };

			clock_t start__           = clock();
			vector <int> received__   = PermutationSignature().reconstruct(signature);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string signature          = "IIIID";
			int expected__[]          = {1, 2, 3, 4, 6, 5 };

			clock_t start__           = clock();
			vector <int> received__   = PermutationSignature().reconstruct(signature);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string signature          = "DIIDID";
			int expected__[]          = {2, 1, 3, 5, 4, 7, 6 };

			clock_t start__           = clock();
			vector <int> received__   = PermutationSignature().reconstruct(signature);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string signature          = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = PermutationSignature().reconstruct(signature);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			string signature          = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = PermutationSignature().reconstruct(signature);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string signature          = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = PermutationSignature().reconstruct(signature);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
// 
The signature of a permutation is a string that is computed as follows: for each pair of consecutive elements of the permutation, write down the letter 'I' (increasing) if the second element is greater than the first one, otherwise write down the letter 'D' (decreasing).



For example, the signature of the permutation {3,1,2,7,4,6,5} is "DIIDID".



Your task is to reverse this computation: You are given a string signature containing the signature of a permutation.
Find and return the lexicographically smallest permutation with the given signature.
If no such permutation exists, return an empty vector <int> instead.


DEFINITION
Class:PermutationSignature
Method:reconstruct
Parameters:string
Returns:vector <int>
Method signature:vector <int> reconstruct(string signature)


NOTES
-For any positive integer N, a permutation of N elements is a sequence of length N that contains each of the integers 1 through N exactly once.
-To compare two permutations A and B, find the smallest index i such that A[i] and B[i] differ. If A[i] < B[i], we say that A is lexicographically smaller than B, and vice versa.


CONSTRAINTS
-signature will contain between 1 and 50 characters, inclusive.
-Each character in signature will be either 'I' or 'D'.


EXAMPLES

0)
"IIIII"

Returns: {1, 2, 3, 4, 5, 6 }



1)
"DI"

Returns: {2, 1, 3 }

There are two permutations with this signature: {3,1,2} and {2,1,3}. You must return the lexicographically smaller one.

2)
"IIIID"

Returns: {1, 2, 3, 4, 6, 5 }



3)
"DIIDID"

Returns: {2, 1, 3, 5, 4, 7, 6 }

This is the signature from the problem statement. Note that the correct answer is not the permutation from the problem statement.

*/

// END CUT HERE
