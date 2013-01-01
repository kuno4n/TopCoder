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

class InternetSecurity {
	public:
	vector <string> determineWebsite(vector <string> address, vector <string> keyword, vector <string> dangerous, int threshold) {
		int res_cnt = 0;
        int den[60] = {0};
        
        set <string> d;
        REP(i, SZ(dangerous)) d.insert(dangerous[i]);
        
        vector< vector <string> > key(SZ(keyword));
        REP(i, SZ(keyword)){
            stringstream ss(keyword[i]);
            string elem;
            while(ss >> elem) key[i].push_back(elem);
        }
        do{
            res_cnt = accumulate(den, den+55, 0);
            REP(i, SZ(address)){
                if(den[i]) continue;
                int cnt = 0;
                
                REP(j, SZ(key[i])) if(d.find(key[i][j]) != d.end()) cnt++;
                
                if(cnt >= threshold){
                    den[i] = 1;
                    REP(j, SZ(key[i])) d.insert(key[i][j]);
                }
            }
            
        }while(res_cnt != accumulate(den, den+55, 0));
        
        vector <string> res;
        REP(i, 55) if(den[i]) res.push_back(address[i]);
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
	template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed) { 
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
			string address[]          = {"www.topcoder.com",
"www.sindicate_of_evil.com",
"www.happy_citizens.com"};
			string keyword[]          = {"hack encryption decryption internet algorithm",
"signal interference evil snake poison algorithm",
"flower baloon topcoder blue sky sea"};
			string dangerous[]        = {"hack","encryption","decryption","interference","signal","internet"};
			int threshold             = 3;
			string expected__[]       = {"www.topcoder.com", "www.sindicate_of_evil.com" };

			clock_t start__           = clock();
			vector <string> received__ = InternetSecurity().determineWebsite(vector <string>(address, address + (sizeof address / sizeof address[0])), vector <string>(keyword, keyword + (sizeof keyword / sizeof keyword[0])), vector <string>(dangerous, dangerous + (sizeof dangerous / sizeof dangerous[0])), threshold);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string address[]          = {"brokenlink","flowerpower.net","purchasedomain.com"};
			string keyword[]          = {"broken","rose tulips","cheap free domain biggest greatest"};
			string dangerous[]        = {"biggest","enemy","hideout"};
			int threshold             = 2;
			string expected__[]       = { };

			clock_t start__           = clock();
			vector <string> received__ = InternetSecurity().determineWebsite(vector <string>(address, address + (sizeof address / sizeof address[0])), vector <string>(keyword, keyword + (sizeof keyword / sizeof keyword[0])), vector <string>(dangerous, dangerous + (sizeof dangerous / sizeof dangerous[0])), threshold);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string address[]          = {"a..a.ab.","...aa.b"};
			string keyword[]          = {"a bc def","def ghij klmno"};
			string dangerous[]        = {"a","b","c","d","e"};
			int threshold             = 1;
			string expected__[]       = {"a..a.ab.", "...aa.b" };

			clock_t start__           = clock();
			vector <string> received__ = InternetSecurity().determineWebsite(vector <string>(address, address + (sizeof address / sizeof address[0])), vector <string>(keyword, keyword + (sizeof keyword / sizeof keyword[0])), vector <string>(dangerous, dangerous + (sizeof dangerous / sizeof dangerous[0])), threshold);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string address[]          = {"www.tsa.gov"};
			string keyword[]          = {"information assurance signal intelligence research"};
			string dangerous[]        = {"signal","assurance","penguin"};
			int threshold             = 2;
			string expected__[]       = {"www.tsa.gov" };

			clock_t start__           = clock();
			vector <string> received__ = InternetSecurity().determineWebsite(vector <string>(address, address + (sizeof address / sizeof address[0])), vector <string>(keyword, keyword + (sizeof keyword / sizeof keyword[0])), vector <string>(dangerous, dangerous + (sizeof dangerous / sizeof dangerous[0])), threshold);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string address[]          = ;
			string keyword[]          = ;
			string dangerous[]        = ;
			int threshold             = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = InternetSecurity().determineWebsite(vector <string>(address, address + (sizeof address / sizeof address[0])), vector <string>(keyword, keyword + (sizeof keyword / sizeof keyword[0])), vector <string>(dangerous, dangerous + (sizeof dangerous / sizeof dangerous[0])), threshold);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			string address[]          = ;
			string keyword[]          = ;
			string dangerous[]        = ;
			int threshold             = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = InternetSecurity().determineWebsite(vector <string>(address, address + (sizeof address / sizeof address[0])), vector <string>(keyword, keyword + (sizeof keyword / sizeof keyword[0])), vector <string>(dangerous, dangerous + (sizeof dangerous / sizeof dangerous[0])), threshold);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string address[]          = ;
			string keyword[]          = ;
			string dangerous[]        = ;
			int threshold             = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = InternetSecurity().determineWebsite(vector <string>(address, address + (sizeof address / sizeof address[0])), vector <string>(keyword, keyword + (sizeof keyword / sizeof keyword[0])), vector <string>(dangerous, dangerous + (sizeof dangerous / sizeof dangerous[0])), threshold);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
// TopCoder Security Agency (TSA, established today) is going to search for dangerous content in the internet.


There are N candidate websites numbered 0 through N-1. Each website has an address given as address[i]. It also has one or more keywords associated with it. The i-th element of keyword is a string describing all keywords associated with the i-th website. It is formatted as a single space separated list of keywords without leading or trailing spaces, where each keyword consists only of lowercase letters.


It is known to TSA that some keywords are dangerous. These keywords are given in vector <string> dangerous, where each element is a single dangerous keyword. For all other keywords it is not initially known whether they are dangerous or not.


TSA uses the following algorithm to identify all dangerous websites:


  Initially, all websites are considered to be safe.

  While there exists a website W such that it's considered safe and
        at least threshold of its keywords are known to be dangerous

    Website W becomes dangerous
    All keywords associated with W become dangerous   

  End While


Return a vector <string> containing the addresses of all dangerous websites found by the algorithm described above sorted in increasing order of website numbers. Return an empty vector <string> if no dangerous website is found.

DEFINITION
Class:InternetSecurity
Method:determineWebsite
Parameters:vector <string>, vector <string>, vector <string>, int
Returns:vector <string>
Method signature:vector <string> determineWebsite(vector <string> address, vector <string> keyword, vector <string> dangerous, int threshold)


NOTES
-The address of a website is just a string used to uniquely identify it. It doesn't necessarily adhere to any common format of naming websites.


CONSTRAINTS
-address will contain between 1 and 50 elements, inclusive.
-Each element of address will contain between 1 and 50 characters, inclusive.
-Each character in address will be a '.', '_' or a lowercase letter ('a'-'z').
-All elements of address will be distinct.
-keyword will contain the same number of elements as address.
-Each element of keyword will contain between 1 and 50 characters, inclusive.
-Each character in keyword will be a ' ' or a lowercase letter ('a'-'z').
-Each element in keyword will be formatted as described in the statement above.
-For each website, the keywords associated with it will be distinct.
-dangerous will contain between 1 and 50 elements, inclusive.
-Each element of dangerous will contain between 1 and 50 characters, inclusive.
-Each character in dangerous will be a lowercase letter ('a'-'z').
-All elements of dangerous will be distinct.
-threshold will be between 1 and 25, inclusive.


EXAMPLES

0)
{"www.topcoder.com",
"www.sindicate_of_evil.com",
"www.happy_citizens.com"}
{"hack encryption decryption internet algorithm",
"signal interference evil snake poison algorithm",
"flower baloon topcoder blue sky sea"}
{"hack","encryption","decryption","interference","signal","internet"}
3

Returns: {"www.topcoder.com", "www.sindicate_of_evil.com" }

"www.topcoder.com" is detected as dangerous since it contains four dangerous keywords: "hack", "encryption", "decryption", and "internet". Hence, "algorithm" becomes a dangerous keyword. As a result, "www.sindicate_of_evil.com" is detected as dangerous since it contains three dangerous keywords: "interference", "signal", and "algorithm". Hence, the correct return value is {"www.topcoder.com","www.sindicate_of_evil.com"} since the answer must be sorted in increasing order of website numbers.

1)
{"brokenlink","flowerpower.net","purchasedomain.com"}
{"broken","rose tulips","cheap free domain biggest greatest"}
{"biggest","enemy","hideout"}
2

Returns: { }

No website is dangerous and an empty vector <string> should be returned.

2)
{"a..a.ab.","...aa.b"}
{"a bc def","def ghij klmno"}
{"a","b","c","d","e"}
1

Returns: {"a..a.ab.", "...aa.b" }



3)
{"www.tsa.gov"}
{"information assurance signal intelligence research"}
{"signal","assurance","penguin"}
2

Returns: {"www.tsa.gov" }



*/

// END CUT HERE
