/***
    * multiply (7x^2 + 8x^1 + 9x^0) with (6x^1 + 5x^0)
    * ans = (42x^3 + 83x^2 + 94x^1 + 45x^0)
    * A = (9,8,7), B = (5,6)
    * multiply(A,B,res)
    * res will be (45 94 83 42)
*/

typedef complex<double> cplx;

void fft (vector<cplx> &a, bool invert) {
    int n = (int) a.size();
    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }

    for (int len=2; len<=n; len<<=1) {
        double ang = 2*PI/len * (invert ? -1 : 1);
        cplx wlen (cos(ang), sin(ang));
        for (int i=0; i<n; i+=len) {
            cplx w (1);
            for (int j=0; j<len/2; ++j) {
                cplx u = a[i+j],  v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
        for (int i=0; i<n; ++i)
            a[i] /= n;
}
/// A and B does not change after passing, res can be any vector
/// A==B || B==res || A==res should not create any problem
/// change to long long vector if needed
void multiply (const vector<int> &a, const vector<int> &b, vector<int> &res) {
    vector<cplx> fa(a.begin(), a.end()),  fb(b.begin(), b.end());
    size_t n = 1;
    size_t mx = max( a.size(), b.size() );
    while( n < mx )  n <<= 1;
    n <<= 1;
    fa.resize (n),  fb.resize (n);

    fft (fa, false),  fft (fb, false);
    for (size_t i=0; i<n; ++i)
        fa[i] *= fb[i];
    fft (fa, true);
    res.resize (n);
    for (size_t i=0; i<n; ++i)
        res[i] = int (fa[i].real() + 0.5); /// change to ll (fa[i].real() + 0.5) if needed

    /** For Base B multiplication
    int B = ?, carry = 0;
    for (size_t i=0; i<n; ++i) {
        res[i] += carry;
        carry = res[i] / B;
        res[i] %= B;
    }
	**/

    /** Removing Leading Zeros
    while(res.size() && res.back() == 0)
        res.pop_back();
    if(res.empty())
        res.push_back(0);
    **/
}
