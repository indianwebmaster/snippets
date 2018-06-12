CC=gcc
CPP=g++

CPROGS=\
	vargs/vargs \
	stringArray/stringArray \
	date_funcs/date_funcs \
	getOpt_example/getOpt_example \
	argc_argv/argc_argv \
	strtok_example/strtok_example \
	matrix/const_matrix  matrix/dyn_matrix  matrix/int_matrix \
	copy_a_struct/copy_a_struct \
	structArray/structArray \
	wait_for_userinput_using_select/wait_for_userinput_using_select

CPP_PROGS=\
	class_inheritance/class_inheritance

all: $(CPROGS) $(CPP_PROGS)

clean: 
	-rm -f $(CPROGS) $(CPP_PROGS)

class_inheritance/class_inheritance: class_inheritance/base_class.cpp class_inheritance/inh_class.cpp
	$(CPP) -o $@ $^

