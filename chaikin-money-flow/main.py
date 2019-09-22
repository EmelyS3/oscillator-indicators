import cffi

MAX_RESULT = 3
ffi = cffi.FFI()
# ffi.cdef("struct RetValues{ double *mfMultipler; double *nPeriods; double *mfVolume; int retCode;};")
ffi.set_source('libcmfos.so', 'typedef struct _RetValues { double *mfMultipler; double *nPeriods; double *mfVolume; int retCode; } RetValues, *P_ARRAY_RETVALUES;')
ffi.cdef("P_ARRAY_RETVALUES cffi_cmf_oscillator(double *h, double *l, double *c, double *v, int periods);")
C = ffi.dlopen("./libcmfos.so")	


def cmf_oscillator(h, l, c, v, p):
    C.cffi_cmf_oscillator(h, l, c, v, p)


if __name__ == "__main__":
	h = [62.34, 62.05, 62.27, 60.79, 59.93, 61.75, 60]
	l = [61.37, 60.69, 60.1, 58.61, 58.71, 59.86, 57.97]
	c = [62.15, 60.81, 60.45, 59.18, 59.24, 60.2, 58.48]
	v = [7849.025, 11692.075, 10575.307, 13059.128, 20733.508, 29630.096, 17705.294]
	cmf_oscillator(h, l, c, v, MAX_RESULT)
	