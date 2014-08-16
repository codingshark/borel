test2:
	./borel ./testcases/test2.txt

test3:
	./borel ./testcases/test3.y

test4:
	./borel ./testcases/test4.y

test_str:
	./borel ./testcases/test_str.txt

test_type:
	./borel ./testcases/test_usr_type.txt

test_null:
	./borel ./testcases/test_nullable.y

test_bug:
	./borel ./testcases/test_bugs.y

test_func:
	./borel ./testcases/test_func.y

test_rec_func:
	./borel ./testcases/test_rec_func.y

gen_printer:
	rm -f ./outputs/*.cpp ./outputs/*.h
	./borel ./scripts/printer.y

gen_cfg:
	rm -f ./outputs/*.cpp ./outputs/*.h
	./borel ./scripts/cfg.y
	
gen_rec_func:
	rm -f ./outputs/*.cpp ./outputs/*.h
	./borel ./scripts/recursive_func.y

gdb_test3:
	gdb --args ./borel ./testcases/test3.y

gdb_test4:
	gdb --args ./borel ./testcases/test4.y
