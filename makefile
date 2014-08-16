EXE_NAME = borel

LEX = flex
YACC = bison
CC = g++

CPPFLAGS = -g -DDEBUG


H_FILES	= -I./ -I./cfg_tree -I./cfg_printer -I/recursive_func

CPP_LOCATIONS	= ./*.cpp ./cfg_tree/*.cpp ./cfg_printer/*.cpp ./recursive_func/*.cpp

C_LOCATIONS	= ./*.c

vpath	= ./cfg_tree/ : ./cfg_printer/ : ./recursive_func/


CPP_SRC	= $(wildcard $(CPP_LOCATIONS))
C_SRC	= $(wildcard $(C_LOCATIONS))
CPP_OBJS	= $(CPP_SRC:.cpp=.o)
C_OBJS		= $(C_SRC:.c=.o)
CPP_DEPENDS	= $(CPP_SRC:.cpp=.d)
C_DEPENDS	= $(C_SRC:.c=.d)

$(EXE_NAME): $(CPP_OBJS) $(C_OBJS) 
	$(CC) $(CPPFLAGS) -o $@ $(CPP_OBJS) $(C_OBJS) $(H_FILES)

lex: $(EXE_NAME).l
	$(LEX) $(EXE_NAME).l

bison: $(EXE_NAME).y
	$(YACC) --defines=$(EXE_NAME).tab.h $(EXE_NAME).y

syntax:	lex bison

.cpp.o: 
	$(CC) $(CPPFLAGS) -c $< -o $@ $(H_FILES)

.c.o:
	$(CC) $(CPPFLAGS) -c $< -o $@ 


get_dependency: rm_old_dependency gen_new_dependency

rm_old_dependency:
	rm -f dependencies.d

gen_new_dependency: $(CPP_DEPENDS)  $(C_DEPENDS)

include dependencies.d

%.d: %.cpp
	$(CC) -MM $< $(H_FILES) >> dependencies.d

%.d: %.c
	$(CC) -MM $< >> dependencies.d

.PHONY : clean get_dependency clean_cfg_tree clean_outputs clean_cfg_printer remove_cfg_printer
clean :
	rm -f $(CPP_OBJS) $(C_OBJS) $(EXE_NAME)  $(EXE_NAME) lex.yy.c lex.yy.o $(EXE_NAME).tab.c $(EXE_NAME).tab.h  $(EXE_NAME) lex.yy.o

clean_cfg_tree:
	rm -f ./cfg_tree/*.o
	
clean_outputs:
	rm -f ./outputs/*.cpp ./outputs/*.h ./outputs/*.o

clean_cfg_printer:
	rm -f ./cfg_printer/*.o
	
remove_cfg_printer:
	rm -f ./cfg_printer/*.cpp ./cfg_printer/*.h ./cfg_printer/*.o

links_cfg_tree:
	ln ./utils/cfg_printer_defs.h	./cfg_tree/
	ln ./utils/cfg_tree_defs.h	./cfg_tree/
	ln ./utils/global_defs.h	./cfg_tree/
	ln ./utils/symbol_base.h	./cfg_tree/
	ln ./utils/symbol_base.cpp	./cfg_tree/
	ln ./utils/symbol_list_item.h	./cfg_tree/
	ln ./utils/symbol_list_item.cpp	./cfg_tree/
	ln ./utils/name_n_idx.h		./cfg_tree/
	ln ./utils/name_n_idx.cpp	./cfg_tree/
	ln ./utils/name_n_ptr.cpp	./cfg_tree/
	ln ./utils/name_n_ptr.h		./cfg_tree/
	ln ./utils/symbol_list.cpp	./cfg_tree/
	ln ./utils/symbol_list.h	./cfg_tree/
	ln ./utils/context.h		./cfg_tree/
	ln ./utils/context.cpp		./cfg_tree/
	
rm_links_cfg_tree:
	rm -f ./cfg_tree/cfg_printer_defs.h
	rm -f ./cfg_tree/cfg_tree_defs.h
	rm -f ./cfg_tree/global_defs.h
	rm -f ./cfg_tree/symbol_base.h
	rm -f ./cfg_tree/symbol_base.cpp
	rm -f ./cfg_tree/symbol_list_item.h
	rm -f ./cfg_tree/symbol_list_item.cpp
	rm -f ./cfg_tree/name_n_idx.h
	rm -f ./cfg_tree/name_n_idx.cpp
	rm -f ./cfg_tree/name_n_ptr.cpp
	rm -f ./cfg_tree/name_n_ptr.h
	rm -f ./cfg_tree/symbol_list.cpp
	rm -f ./cfg_tree/symbol_list.h
	rm -f ./cfg_tree/context.h
	rm -f ./cfg_tree/context.cpp

links_recfunc:
	ln ./utils/recfunc_context.h	./recursive_func/
	ln ./utils/recfunc_context.cpp	./recursive_func/
	ln ./utils/symbol_base.h	./recursive_func/

rm_links_recfunc:
	rm -f ./recursive_func/recfunc_context.h
	rm -f ./recursive_func/recfunc_context.cpp
	rm -f ./recursive_func/symbol_base.h

include testcases.mk


