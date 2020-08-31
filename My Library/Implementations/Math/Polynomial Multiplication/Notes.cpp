/***
    * Karatsuba, FFT, NTT they all do the same thing.
    * Karatsuba, NTT uses LL where fft uses doubles.
    * So FFT might face loss of precision but karatsuba/NTT won't face that ever.
    * Karatsuba,NTT returns the coefficients%MOD. FFT returns the coefficients as they are.
    * Karatsuba runs O(n^(log2(3)), FFT runs in O(nlog2(n)), NTT runs in O(nlog2(n)). But NTT is slower than FFT due to constant factors.
    * You cannot use NTT for arbitrary mods. NTT works for special mods only. So for the general case, NTT is not an option.

    *** Use karatsuba if you're sure time limit is okay for it. Otherwise go to FFT.

***/
