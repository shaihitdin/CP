#include <bits/stdc++.h>

using namespace std;

const int TEST_CNT = 17000;

int test_sz;
char test[20];

int testk[TEST_CNT];
string testnum[TEST_CNT];

// for first group
inline void rec (const int &now, const int &k, const int &n, const string &result = "") {
	if (now == n + 1) {
		testk[++test_sz] = k;
		testnum[test_sz] = result;
		return;
	}
	
	for (int i = 0; i < k; ++i)
		rec (now + 1, k, n, result + char ('0' + i));
	rec (now + 1, k, n, result + '?');
}

int rndm[TEST_CNT];

#ifdef ON_WINDOWS
	inline int myrand () {
		return ((rand () * 1ll) << 10) ^ (rand ());
	}
#else
	inline int myrand () {
		return rand ();
	}
#endif

/* [l, r] */
inline int in_range (const int &l, const int &r) {
	return (myrand () % (r - l + 1)) + l;
}

inline int range0 (const int &r) {
	return myrand () % r;
}

int main (int argc, char * argv[]) {

	srand (atoi (argv[1]));

	// first group
	int k = 1;
	for (int n = 1; n <= 5; ++n)
		rec (1, k, n);

	k = 2;
	for (int n = 1; n <= 6; ++n)
		rec (1, k, n);
    
    k = 3;
    for (int n = 1; n <= 5; ++n)
    	rec (1, k, n);

    k = 4;
    for (int n = 1; n <= 4; ++n)
		rec (1, k, n);


	// second group
	for (int test_num = 1; test_num <= 600; ++test_num) {
		int n = 2 * in_range (4, 50);
		k = 2;
		string result = "";
		if (int (myrand ()) & 1)
			for (int j = 1; j <= n; ++j)
				result += ('0' + (j & 1));
		else			
			for (int j = 1; j <= n; ++j)
				result += ('1' - (j & 1));

		for (int i = 1; i <= n; ++i)
			rndm[i] = i;
		
		random_shuffle (rndm + 1, rndm + n + 1, range0);
		int m = in_range (0, n);
		
		for (int i = 1; i <= m; ++i)
			result[rndm[i] - 1] = '?';

		testk[++test_sz] = k;
		testnum[test_sz] = result;
	}

	// third group
	for (int test_num = 1; test_num <= 600; ++test_num) {
		int n = 2 * in_range (4, 50);
		k = 2;
		string result = "";
		if (int (myrand ()) & 1)
			for (int j = 1; j <= n; ++j)
				result += ('0' + (j & 1));
		else			
			for (int j = 1; j <= n; ++j)
				result += ('1' - (j & 1));

		for (int i = 1; i <= n; ++i)
			rndm[i] = i;
		
		random_shuffle (rndm + 1, rndm + n + 1, range0);
		int l = in_range (0, n / 10) + 1;
		
		for (int i = 1; i <= l; ++i)
			result[rndm[i] - 1] ^= 1;

		testk[++test_sz] = k;
		testnum[test_sz] = result;
	}
	
	//	fourth group
	for (int test_num = 1; test_num <= 600; ++test_num) {
		int n = 2 * in_range (4, 50) - 1;
		k = 2;
		string result = "";
		if (int (myrand ()) & 1)
			for (int j = 1; j <= n; ++j)
				result += ('0' + (j & 1));
		else			
			for (int j = 1; j <= n; ++j)
				result += ('1' - (j & 1));

		for (int i = 1; i <= n; ++i)
			rndm[i] = i;
		
		random_shuffle (rndm + 1, rndm + n + 1, range0);
		int m = in_range (0, n);
		
		for (int i = 1; i <= m; ++i)
			result[rndm[i] - 1] = '?';

		testk[++test_sz] = k;
		testnum[test_sz] = result;
	}

	// fifth group
	for (int test_num = 1; test_num <= 2000; ++test_num) {
		int n = in_range (1, 100);
		k = in_range (1, 10);
		string result = "";
		
		for (int i = 1; i <= n; ++i) {
			int val = in_range (0, k);
			if (val == k)
				result += '?';
			else
				result += char ('0' + val);
		}
		testk[++test_sz] = k;
		testnum[test_sz] = result;
	}
	
	// sixth group
	for (int test_num = 1; test_num <= 2000; ++test_num) {
		int n = in_range (1, 100);
		k = in_range (3, 10);
		string result = "";
		result += char ('0' + in_range (0, k - 1));
		
		if (n == 1) {
			testk[++test_sz] = k;
			testnum[test_sz] = result;			
			continue;
		}

		for (int i = 2; i < n; ++i) {
			int val;
			while (1) {
				val = in_range (0, k - 1);
				if (val + '0' != result[i - 2])
					break;
			}
			result += char (val + '0');
		}

		int val;
		while (1) {
			val = in_range (0, k - 1);
			if (char (val + '0') != result[n - 2] && char (val + '0') != result[0])
				break;
		}

		result += char (val + '0');

		for (int i = 1; i <= n; ++i)
			rndm[i] = i;
		
		random_shuffle (rndm + 1, rndm + n + 1, range0);
		int m = in_range (0, n);
		
		for (int i = 1; i <= m; ++i)
			result[rndm[i] - 1] = '?';
		
		testk[++test_sz] = k;
		testnum[test_sz] = result;
	}
	
	// seventh group
	for (int test_num = 1; test_num <= 2000; ++test_num) {
		int n = in_range (1, 100);
		k = in_range (3, 10);
		string result = "";
		result += char ('0' + in_range (0, k - 1));
		
		if (n == 1) {
			if (in_range (0, k) == k)
				result[0] = '?';
			testk[++test_sz] = k;
			testnum[test_sz] = result;			
			continue;
		}

		for (int i = 2; i < n; ++i) {
			int val;
			while (1) {
				val = in_range (0, k - 1);
				if (val + '0' != result[i - 2])
					break;
			}
			result += char (val + '0');
		}

		int val;
		while (1) {
			val = in_range (0, k - 1);
			if (char (val + '0') != result[n - 2] && char (val + '0') != result[0])
				break;
		}

		result += char (val + '0');

		for (int i = 1; i <= n; ++i)
			rndm[i] = i;
		
		random_shuffle (rndm + 1, rndm + n + 1, range0);
		int m = in_range (0, n);
		
		for (int i = 1; i <= m; ++i)
			result[rndm[i] - 1] = '?';
		
		int cnt = 0;

		for (int i = 1; i < result.size (); ++i)
			if (result[i - 1] != '?' && result[i] != '?')
				rndm[++cnt] = i;
		
		random_shuffle (rndm + 1, rndm + cnt + 1, range0);
		
		val = in_range (0, 6);
		
		for (int i = 1; i <= min (cnt, val); ++i)
			result[rndm[i]] = result[rndm[i + 1]];

		if (result[0] != '?' && result.back () != '?' && in_range (0, 100) <= 20)
			result[0] = result.back ();

		testk[++test_sz] = k;
		testnum[test_sz] = result;
	}
	
	for (int i = 1; i <= 11098; ++i)
		rndm[i] = i;

	random_shuffle (rndm + 1, rndm + 11099, range0);

	int test_left = 11098;

	int t_file_num = 0;
	char t_file[20];

	for (int i = 1; i <= 11098; ++i) {
		if (i % 1000 == 1) {
			++t_file_num;
			sprintf (t_file, "%d", t_file_num);
			fclose (stdout);
			freopen (t_file, "w", stdout);
			printf ("%d\n", min (1000, test_left));
			test_left -= min (1000, test_left);
		}
		printf ("%d\n%s\n", testk[rndm[i]], testnum[rndm[i]].c_str ());
	}
	
	
	// Max tests

	++t_file_num;
	sprintf (t_file, "%d", t_file_num);
	fclose (stdout);
	freopen (t_file, "w", stdout);
	printf ("%d\n", 1000);
		
	for (int test_num = 1; test_num <= 1000; ++test_num) {
		int n = 100;
		k = 2;
		string result = "";
		if (int (myrand ()) & 1)
			for (int j = 1; j <= n; ++j)
				result += ('0' + (j & 1));
		else			
			for (int j = 1; j <= n; ++j)
				result += ('1' - (j & 1));

		for (int i = 1; i <= n; ++i)
			rndm[i] = i;
		
		random_shuffle (rndm + 1, rndm + n + 1, range0);
		int m = in_range (0, n);
		
		for (int i = 1; i <= m; ++i)
			result[rndm[i] - 1] = '?';

		printf ("%d\n%s\n", k, result.c_str ());
	}

	++t_file_num;
	sprintf (t_file, "%d", t_file_num);
	fclose (stdout);
	freopen (t_file, "w", stdout);
	printf ("%d\n", 1000);
	
	for (int test_num = 1; test_num <= 1000; ++test_num) {
		if (myrand () & 1) {
			int n = 100;
			k = 2;
			string result = "";
			if (int (myrand ()) & 1)
				for (int j = 1; j <= n; ++j)
					result += ('0' + (j & 1));
			else			
				for (int j = 1; j <= n; ++j)
					result += ('1' - (j & 1));
		
			for (int i = 1; i <= n; ++i)
				rndm[i] = i;
			
			random_shuffle (rndm + 1, rndm + n + 1, range0);
			int m = in_range (0, n);
			
			for (int i = 1; i <= m; ++i)
				result[rndm[i] - 1] = '?';
			
			printf ("%d\n%s\n", k, result.c_str ());
		} else {
			int n = 100;
			k = 2;
			string result = "";
			if (int (myrand ()) & 1)
				for (int j = 1; j <= n; ++j)
					result += ('0' + (j & 1));
			else			
				for (int j = 1; j <= n; ++j)
					result += ('1' - (j & 1));

			for (int i = 1; i <= n; ++i)
				rndm[i] = i;
	
			random_shuffle (rndm + 1, rndm + n + 1, range0);
			int l = in_range (0, n / 10) + 1;
		
			for (int i = 1; i <= l; ++i)
				result[rndm[i] - 1] ^= 1;
								
			printf ("%d\n%s\n", k, result.c_str ());
		}
	}

	++t_file_num;
	sprintf (t_file, "%d", t_file_num);
	fclose (stdout);
	freopen (t_file, "w", stdout);
	printf ("%d\n", 1000);
	
	for (int test_num = 1; test_num <= 1000; ++test_num) {
		int n = 100;
		k = in_range (3, 10);
		string result = "";
		result += char ('0' + in_range (0, k - 1));
		
		if (n == 1) {
			testk[++test_sz] = k;
			testnum[test_sz] = result;			
			continue;
		}

		for (int i = 2; i < n; ++i) {
			int val;
			while (1) {
				val = in_range (0, k - 1);
				if (val + '0' != result[i - 2])
					break;
			}
			result += char (val + '0');
		}

		int val;
		while (1) {
			val = in_range (0, k - 1);
			if (char (val + '0') != result[n - 2] && char (val + '0') != result[0])
				break;
		}

		result += char (val + '0');

		for (int i = 1; i <= n; ++i)
			rndm[i] = i;
		
		random_shuffle (rndm + 1, rndm + n + 1, range0);
		int m = in_range (0, n);
		
		for (int i = 1; i <= m; ++i)
			result[rndm[i] - 1] = '?';
		
		printf ("%d\n%s\n", k, result.c_str ());
	}
	
	++t_file_num;
	sprintf (t_file, "%d", t_file_num);
	fclose (stdout);
	freopen (t_file, "w", stdout);
	printf ("%d\n", 1000);

	
	for (int test_num = 1; test_num <= 1000; ++test_num) {
		if (myrand () & 1) {
			int n = 100;
			k = in_range (3, 10);
			string result = "";
			result += char ('0' + in_range (0, k - 1));
			
			if (n == 1) {
				testk[++test_sz] = k;
				testnum[test_sz] = result;			
				continue;
			}
	
			for (int i = 2; i < n; ++i) {
				int val;
				while (1) {
					val = in_range (0, k - 1);
					if (val + '0' != result[i - 2])
						break;
				}
				result += char (val + '0');
			}
	
			int val;
			while (1) {
				val = in_range (0, k - 1);
				if (char (val + '0') != result[n - 2] && char (val + '0') != result[0])
					break;
			}
	
			result += char (val + '0');
	
			for (int i = 1; i <= n; ++i)
				rndm[i] = i;
			
				random_shuffle (rndm + 1, rndm + n + 1, range0);
				int m = in_range (0, n);
				
				for (int i = 1; i <= m; ++i)
					result[rndm[i] - 1] = '?';
				
			printf ("%d\n%s\n", k, result.c_str ());
		} else {
			int n = 100;
			k = in_range (3, 10);
			string result = "";
			result += char ('0' + in_range (0, k - 1));
			
			if (n == 1) {
				if (in_range (0, k) == k)
					result[0] = '?';
				testk[++test_sz] = k;
				testnum[test_sz] = result;			
				continue;
			}
		
			for (int i = 2; i < n; ++i) {
				int val;
				while (1) {
					val = in_range (0, k - 1);
					if (val + '0' != result[i - 2])
						break;
				}
				result += char (val + '0');
			}
		
			int val;
			while (1) {
				val = in_range (0, k - 1);
				if (char (val + '0') != result[n - 2] && char (val + '0') != result[0])
					break;
			}
		
			result += char (val + '0');
	   	
			for (int i = 1; i <= n; ++i)
				rndm[i] = i;
			
			random_shuffle (rndm + 1, rndm + n + 1, range0);
			int m = in_range (0, n);
			
			for (int i = 1; i <= m; ++i)
				result[rndm[i] - 1] = '?';
			
			int cnt = 0;
		
			for (int i = 1; i < result.size (); ++i)
				if (result[i - 1] != '?' && result[i] != '?')
					rndm[++cnt] = i;
			
			random_shuffle (rndm + 1, rndm + cnt + 1, range0);
			
			val = in_range (0, 6);
			
			for (int i = 1; i <= min (cnt, val); ++i)
				result[rndm[i]] = result[rndm[i + 1]];
		
			if (result[0] != '?' && result.back () != '?' && in_range (0, 100) <= 20)
				result[0] = result.back ();
   	
			printf ("%d\n%s\n", k, result.c_str ());
		}
	}
	

	
	return 0;
}