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


int bitcnt(LL n)
{
    int c;
    for(c=0;n!=0;c++,n&=n-1) ;
    return c;
}

class StrangeDictionary2 {
	public:
	vector <double> getProbabilities(vector <string> words) {
        int n = SZ(words), L = SZ(words[0]);
		vector <double> res(n, 0.0);
        
        REP(i, n){
            int prev[L]; MSET(prev, 0);
            int match[L]; MSET(match, 0);
            REP(j, L) REP(k, n) if(words[i][j] >  words[k][j]) prev[j]  |= (1<<k);
            REP(j, L) REP(k, n) if(words[i][j] == words[k][j]) match[j] |= (1<<k);
            
            double dp[1<<n];
            REP(j, (1<<n)) dp[j] = 0.0;
            dp[1<<i] = 1.0;
            FOR(mask, 1, (1<<n)){
                if(bitcnt(mask) == 1) continue;
                if(!(mask&(1<<i))) continue;
                int cnt = 0;
                REP(j, L){
                    if(prev[j] & mask) cnt++;
                    else if((match[j] & mask) < mask){
                        dp[mask] += dp[match[j] & mask];
                        cnt++;
                    }
                }
                dp[mask] /= cnt;
            }
            
            res[i] = dp[(1<<n)-1];
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	static bool topcoder_fequ(const vector<double> &a, const vector<double> &b) { if (a.size() != b.size()) return false; for (size_t i=0; i<a.size(); ++i) if (!topcoder_fequ(a[i], b[i])) return false; return true; }
	double moj_relative_error(const vector<double> &expected, const vector<double> &result) { double ret = 0.0; for (size_t i=0; i<expected.size(); ++i) { ret = max(ret, moj_relative_error(expected[i], result[i])); } return ret; }
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <double> &expected, const vector <double> &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			string words[]            = {"hardesttestever"};
			double expected__[]       = {1.0 };

			clock_t start__           = clock();
			vector <double> received__ = StrangeDictionary2().getProbabilities(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string words[]            = {"ab", "ba"};
			double expected__[]       = {0.5, 0.5 };

			clock_t start__           = clock();
			vector <double> received__ = StrangeDictionary2().getProbabilities(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string words[]            = {"aza", "aab", "bba"};
			double expected__[]       = {0.3333333333333333, 0.5, 0.16666666666666666 };

			clock_t start__           = clock();
			vector <double> received__ = StrangeDictionary2().getProbabilities(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string words[]            = {"abababab", "babababa", "acacacac", "cacacaca", "bcbcbcbc", "cbcbcbcb"};
			double expected__[]       = {0.5, 0.5, 0.0, 0.0, 0.0, 0.0 };

			clock_t start__           = clock();
			vector <double> received__ = StrangeDictionary2().getProbabilities(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string words[]            = ;
			double expected__[]       = ;

			clock_t start__           = clock();
			vector <double> received__ = StrangeDictionary2().getProbabilities(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			string words[]            = ;
			double expected__[]       = ;

			clock_t start__           = clock();
			vector <double> received__ = StrangeDictionary2().getProbabilities(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string words[]            = ;
			double expected__[]       = ;

			clock_t start__           = clock();
			vector <double> received__ = StrangeDictionary2().getProbabilities(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
// A standard way of ordering words in a dictionary involves comparison of two words character by character, from left to right, until some two characters disagree. Jim thinks it's pretty boring, so he introduced a more complicated and less predictable scheme.

Given is a vector <string> words that contains N distinct words and each element is a single word. The length of each word is the same -- exactly L characters. To order words according to his scheme, Jim first generates a random permutation p[0], p[1], ..., p[L-1] of integers between 0 and L-1, inclusive. This permutation is generated only once and then considered to be fixed for the rest of the procedure. Using the permutation p, Jim can compare any two words as follows:


// returns -1, if A<B, 0, if A=B, and 1, if A>B
function Compare(Word A, Word B):
	for i = 0, 1, ..., L-1:
		a := character at position p[i] (0-based) in A
		b := character at position p[i] (0-based) in B
		if (a < b), return -1
		if (b < a), return 1

	return 0


Let Sorted be the list of the given words ordered according to Compare operator defined above. In other words, Compare(Sorted[i], Sorted[j]) = -1, for any i, j, 0 <= i < j < N.

Return a vector <double> that contains N elements and i-th element of the return is the probability that Sorted[0] is the same word as words[i]. Assume that permutation p is chosen uniformly at random.

DEFINITION
Class:StrangeDictionary2
Method:getProbabilities
Parameters:vector <string>
Returns:vector <double>
Method signature:vector <double> getProbabilities(vector <string> words)


NOTES
-Each element of the return value must have an absolute or relative error of less than 1e-9.


CONSTRAINTS
-words will contain between 1 and 16 elements, inclusive.
-Each element of words will contain between 1 and 50 characters, inclusive.
-All elements of words will contain the same number of characters.
-Each character in each element of words will be a lowercase letter ('a'-'z').
-All elements of words will be distinct.


EXAMPLES

0)
{"hardesttestever"}

Returns: {1.0 }

One word will always be at position 0 regardless of the permutation p.

1)
{"ab", "ba"}

Returns: {0.5, 0.5 }

If p = {0, 1}, then "ab" < "ba". If p = {1, 0}, then "ba" < "ab".

2)
{"aza", "aab", "bba"}

Returns: {0.3333333333333333, 0.5, 0.16666666666666666 }


p		Sorted
{0,1,2}		aab, aza, bba
{0,2,1}		aza, aab, bba
{1,0,2}		aab, bba, aza
{1,2,0}		aab, bba, aza
{2,0,1}		aza, bba, aab
{2,1,0}		bba, aza, aab


3)
{"abababab", "babababa", "acacacac", "cacacaca", "bcbcbcbc", "cbcbcbcb"}

Returns: {0.5, 0.5, 0.0, 0.0, 0.0, 0.0 }



*/

// END CUT HERE
