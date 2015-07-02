//

inline bg to_bg (const string &s) {
        bg x;
        for (int i = 0; i < s.size (); ++i)
                x.push_back (s[i]);
        reverse (x.begin (), x.end ());
        return x;
}
 
inline string to_string (const bg &x) {
        string s;
        for (int i = 0; i < x.size (); ++i)
                s += (x[i] + '0');
        reverse (s.begin (), s.end ());
        return s;
}
 
inline bg operator + (const bg &x, const int &y) {
        bg res = x;
        res[0] += y;
        for (int i = 0; i < x.size (); ++i) {
                if (res[i] > 9)
                        res.push_back (0);
                res[i + 1] += (res[i] / 10);
                res[i] %= 10;
        }
        return res;
}
 
inline bg operator - (const bg &x, const bg &y) {
        bg res = x;
        for (int i = 0; i < res.size (); ++i) {
                if (i + 1 == res.size ())
                        res.push_back (0);
        }
        while (res.size () && !res.back ())
                res.pop_back ();
        return res;
}
 
inline bool operator < (const bg &x, const bg &y) {
        if (x.size () != y.size ())
                return x.size () < y.size ();
        for (int i = x.size () - 1; i; --i)
                if (x[i] != y[i])
                        return x[i] < y[i];
        return 0;
}
 
inline bg operator * (const bg &x, const int &y) {
        bg res = x;
        char r = 0;
        for (int i = 0; i < res.size (); ++i) {
                res[i] = res[i] * y + r;
                r = res[i] / base;
                res[i] %= base;
        }
        if (r)
                res.push_back (r);
}
 
inline bg operator * (const bg &x, const bg &y) {
        bg res (x.size () + y.size ());
        for (int i = 0; i < x.size (); ++i) {
                char r = 0;
                for (int j = 0; j < y.size (); ++j) {
                        res[i + j] = x[i] * y[j] + r;
                        r = res[i + j] / base;
                        res[i + j] %= base;
                }
                res[y.size () + i] += r;
        }
        return res;
}
 
//
