import cffi

ffi = cffi.FFI()
ffi.cdef("void cffi_combinacionImagenes();")
ffi.cdef("void cffi_ecualizacion(char *);")
ffi.cdef("void cffi_sobel(char *);")
ffi.cdef("void cffi_medianblur(char *);")
ffi.cdef("void cffi_difuminadoAleatorio(char *);")
ffi.cdef("void cffi_transformacionBilineal(char *);")
ffi.cdef("void cffi_fft(char *);")
C = ffi.dlopen("./milibreria.so")

def combinacionImagenes():
	return C.cffi_combinacionImagenes()

def ecualizacion(nameImage):
	return C.cffi_ecualizacion(nameImage)

def sobel(nameImage):
	return C.cffi_sobel(nameImage)

def medianblur(nameImage):
	return C.cffi_medianblur(nameImage)

def difuminadoAleatorio(nameImage):
	return C.cffi_difuminadoAleatorio(nameImage)

def transformacionBilineal(nameImage):
	return C.cffi_transformacionBilineal(nameImage)

def fft(nameImage):
	return C.cffi_fft(nameImage)



