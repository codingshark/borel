
//print_base_h
%type <> print_base_h
%token <string> class_name
%token <string> upper_name
//

//print_derived_h
%type <> print_derived_h
%type <> include_file_list
%type <> set_method_arg_list
%type <> arg_type
%type <> data_member_inst
%type <> data_member_list

%token <string> include_file_name
%token <string> base_of_drived
%token <unsigned int> data_member_index
%token <string> data_member_type
%token <string> data_member_name
//

//print_derived_cpp
%type <> print_derived_cpp
%type <> copy_list
%type <> deconstruction_list
%type <> construction_list
%type <> print_list
%type <> set_list
%type <> assert_stmt
%type <> duplicate_list

%token <string> str_member
%token <string> source_code
//

//function related
%type <> recursive_func_decl_list_base
%type <> recursive_func_decl_list_derived
%type <> nonrecursive_func_decl_list
%type <> func_list_cpp
%type <> recursive_func_def
%type <> printer_func_def
%type <> printer_func_decl

%token <string> return_value
%token <string> func_name
%token <string> func_parameter
//

//
%token <string> global_def_h
%token <string> base_class
//

//function for printer_func_decl
%function <nonrecursive> get_return_value
%function <nonrecursive> get_func_name
%function <nonrecursive> get_func_parameter
//end 

//function for printer_base printer_derived
/*%function <nonrecursive> get_rfunc_decl_list_base
%function <nonrecursive> get_rfunc_decl_list_derived
%function <nonrecursive> get_nonrfunc_decl_list
%function <nonrecursive> get_func_list*/
%function <nonrecursive> get_class_name
//
%%

print_base_h:
	"#ifndef " upper_name "_H_\n"
	"#define " upper_name "_H_\n"
	"#include <iostream>\n"
	"#include \"" global_def_h ".h\"\n"
	"#include \"" base_class  ".h\"\n"
	upper_name "_BASE_H_USR_DEF_1\n"
	"using namespace std;\n"
	"class " class_name " :public " base_class " " upper_name "_BASE_H_USR_DEF_2\n"
	"{\n"
	"\tpublic:\n"
	"\t\t" class_name "(){};\n"
	"\t\t" class_name "(const " class_name " & a_" class_name "){}\n"
	"\t\tvirtual ~" class_name "(){};\n"
	"\t\tvirtual " class_name "& operator = (const " class_name " & a_" class_name "){};\n"
	"\t\tvirtual void print_this(std::ostream & out){};\n"
	"\t\tvirtual " class_name " * duplicate(){};\n"
	recursive_func_decl_list_base
	"\t" upper_name "_BASE_H_USR_DEF_3\n"
	"};\n"
	"#endif\n\n"
/*	%get_rfunc_decl_list_base*/
	;

print_derived_h:
	"#ifndef " upper_name "_H_\n"
	"#define " upper_name "_H_\n"
	"#include \"" global_def_h ".h\"\n"
	"#include \"" base_class ".h\"\n"
	"#include <iostream>\n"
	include_file_list
	upper_name "_DERIVED_H_USR_DEF_1\n"
	"using namespace std;\n"
	"class " class_name " :public " base_of_drived " " upper_name "_DERIVED_H_USR_DEF_2\n"
	"{\n"
	"\tpublic:\n"
	"\t\t" class_name "();\n"
	"\t\t" class_name "(const " class_name " & a_" class_name ");\n"
	"\t\tvirtual ~" class_name "();\n"
	"\t\t" class_name "& operator = (const " class_name " & a_" class_name ");\n"
	"\t\tvoid set(" set_method_arg_list ");\n"
	"\t\tvoid print_this(std::ostream & out);\n"
	"\t\t" class_name " * duplicate();\n"
	recursive_func_decl_list_derived
	nonrecursive_func_decl_list
	"\tpublic:\n"
	data_member_list
	"\t" upper_name "_DERIVED_H_USR_DEF_3\n"
	"};\n"
	"#endif\n\n"
	
/*	%get_rfunc_decl_list_derived
	%get_nonrfunc_decl_list*/
	;

recursive_func_decl_list_base:
	recursive_func_decl_list_base "\t\tvirtual " printer_func_decl "{};\n"
|
	;

recursive_func_decl_list_derived:
	recursive_func_decl_list_derived "\t\tvirtual " printer_func_decl ";\n"
|
	;

printer_func_decl:
	return_value func_name func_parameter
	
	%get_return_value
	%get_func_name
	%get_func_parameter
	;

nonrecursive_func_decl_list:
	nonrecursive_func_decl_list "\t\t" printer_func_decl ";\n"
|
	;

include_file_list:
	include_file_list "#include \"" include_file_name ".h\"\n"
|	include_file_list "#include <" include_file_name ".h>\n"
|
	;

set_method_arg_list:
	set_method_arg_list ", " arg_type " a_" data_member_inst 
|	set_method_arg_list arg_type " a_" data_member_inst
|
	;

arg_type:
//	"const " data_member_type " & "
	data_member_type " & "	//remove "const" because if data_member_type is a pointer, "const"
				// will cause problem
|	data_member_type " * "
	;

data_member_inst:
	"m_" data_member_index
	;

data_member_list:
	data_member_list	"\t\t" data_member_type "\t" data_member_inst ";\t// " data_member_name "\n"
|	data_member_list	"\t\t" data_member_type " *\t" data_member_inst ";\t// " data_member_name "\n"
|
	;

print_derived_cpp:
	"#include \"" class_name ".h\"\n"
	
	upper_name "_DERIVED_CPP_USR_DEF\n"
	
	class_name "::" class_name "()\n"
	"{\n"
	construction_list
	"}\n"
	
	class_name "::" class_name "(const " class_name " & a_" class_name ")\n"
	"{\n"
	copy_list
	"}\n"
	
	class_name "::~" class_name "()\n"
	"{\n"
	deconstruction_list
	"}\n"
	
	class_name " & " class_name "::operator = (const " class_name " & a_" class_name ")\n"
	"{\n"
	"\tif(this == & a_" class_name ")\n"
	"\t\treturn *this;\n"
	copy_list
	"\treturn *this;\n"
	"}\n"
	
	"void " class_name "::print_this(std::ostream & out)\n"
	"{\n"
	print_list
	"}\n"
	
	"void " class_name "::set(" set_method_arg_list ")\n"
	"{\n"
	set_list
	"}\n"
	
	class_name " * " class_name "::duplicate()\n"
	"{\n"
	"\t" class_name " * a_copy = new " class_name ";\n"
	duplicate_list
	"\treturn a_copy;\n"
	"}\n"
	func_list_cpp
	
/*	%get_func_list*/
	%get_class_name
	;

copy_list:
	copy_list	"\t" data_member_inst " = a_" class_name "." data_member_inst ";\n"
|	copy_list	"\tif( " data_member_inst "!= NULL )\n" //delete old data
			"\t{\n"
			"\t\tdelete " data_member_inst ";\n"
			"\t}\n"
			"\tif(a_" class_name "." data_member_inst " != NULL)\n"
			"\t{\n"
			"\t\t" data_member_inst " = a_" class_name "." data_member_inst "->duplicate();\n" //copy new data
			"\t}else{\n"
			"\t\t" data_member_inst " = NULL;\n"
			"\t}\n"
|
	;

deconstruction_list:
	deconstruction_list	"\tif( " data_member_inst "!= NULL )\n"
				"\t{\n"
				"\t\tdelete " data_member_inst ";\n"
				"\t}\n"
|
	;

construction_list:
	construction_list "\t" data_member_inst " = NULL;\n"
|
	;

print_list:
	print_list	"\tif( " data_member_inst "!= NULL )\n"
			"\t{\n"
			"\t\t" data_member_inst "->print_this(out);\n"
			"\t}\n"

|	print_list	"\tout<<" data_member_inst ";\n"
|	print_list	"\tout<<" str_member ";\n"
|
	;

set_list:
	set_list assert_stmt "\t" data_member_inst " = a_" data_member_inst ";\n"
|
	;

assert_stmt:
	"\tassert( a_" data_member_inst " != NULL);\n"
|	//
	;	
	
duplicate_list:
	duplicate_list	"\tif( " data_member_inst "!= NULL )\n"
			"\t{\n"
			"\t\ta_copy->" data_member_inst " = " data_member_inst "->duplicate();\n"
			"\t}else{\n"
			"\t\t" data_member_inst " = NULL;\n"
			"\t}\n"
			
|	duplicate_list	"\ta_copy->" data_member_inst " = " data_member_inst ";\n"
|
	;

func_list_cpp:
	func_list_cpp	return_value class_name "::" func_name func_parameter "\n"
			"{\n"
				recursive_func_def
			"}\n"
			
|	func_list_cpp	return_value class_name "::" func_name func_parameter "\n"
			"{\n"
				printer_func_def
			"}\n"
|
	;

recursive_func_def:
	recursive_func_def	"\tif( " data_member_inst "!= NULL )\n"
				"\t{\n"
				"\t\t" data_member_inst "->" func_name func_parameter ";\n"
				"\t}\n"

|	recursive_func_def	printer_func_def
|
	;

printer_func_def:
	printer_func_def source_code
|	printer_func_def data_member_inst
|
	;

%%

string get_return_value()
{
	return $1;
}

string get_func_name()
{
	return $2;
}

string get_func_parameter()
{
	return $3;
}

/*recursive_func_decl_list_base*& get_rfunc_decl_list_base()
{
	return $18;
}

recursive_func_decl_list_derived*& get_rfunc_decl_list_derived()
{
	return $20;
}

nonrecursive_func_decl_list*& get_nonrfunc_decl_list()
{
	return $21;
}

func_list_cpp*& get_func_list()
{
	return $30;
}*/

string get_class_name()
{
	return $1;
}

