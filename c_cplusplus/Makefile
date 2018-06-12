all: \
	vargs/vargs \
	stringArray/stringArray \
	date_funcs/date_funcs \
	getOpt_example/getOpt_example \
	argc_argv/argc_argv \
	strtok_example/strtok_example \
	matrix/const_matrix  matrix/dyn_matrix  matrix/int_matrix \
	copy_a_struct/copy_a_struct \
	structArray/structArray

clean: 
	rm \
		vargs/vargs \
		stringArray/stringArray \
		date_funcs/date_funcs \
		getOpt_example/getOpt_example \
		argc_argv/argc_argv \
		strtok_example/strtok_example \
		matrix/const_matrix  matrix/dyn_matrix  matrix/int_matrix \
		copy_a_struct/copy_a_struct \
		structArray/structArray

vargs/vargs:
	cd vargs && gcc -o vargs vargs.c

stringArray/stringArray:
	cd stringArray && gcc -o stringArray stringArray.c

date_funcs/date_funcs:
	cd date_funcs && gcc -o date_funcs date_funcs.c

getOpt_example/getOpt_example:
	cd getOpt_example && gcc -o getOpt_example getOpt_example.c

argc_argv/argc_argv:
	cd argc_argv && gcc -o argc_argv argc_argv.c

strtok_example/strtok_example:
	cd strtok_example && gcc -o strtok_example strtok_example.c

matrix/const_matrix  matrix/dyn_matrix  matrix/int_matrix:
	cd matrix && gcc -o const_matrix const_matrix.c
	cd matrix && gcc -o dyn_matrix dyn_matrix.c
	cd matrix && gcc -o int_matrix int_matrix.c

copy_a_struct/copy_a_struct:
	cd copy_a_struct && gcc -o copy_a_struct copy_a_struct.c

structArray/structArray:
	cd structArray && gcc -o structArray structArray.c

