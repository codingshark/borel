#ifndef CFG_TREE_DEFS_H_
#define CFG_TREE_DEFS_H_

#include "global_defs.h"

#include "print_base_h.h"
#include "print_derived_h.h"
#include "recursive_func_decl_list_base1.h"
#include "recursive_func_decl_list_base.h"
#include "recursive_func_decl_list_derived1.h"
#include "recursive_func_decl_list_derived.h"
#include "printer_func_decl.h"
#include "nonrecursive_func_decl_list1.h"
#include "nonrecursive_func_decl_list.h"
#include "include_file_list1.h"
#include "include_file_list2.h"
#include "include_file_list.h"
#include "set_method_arg_list1.h"
#include "set_method_arg_list2.h"
#include "set_method_arg_list.h"
#include "arg_type1.h"
#include "arg_type2.h"
#include "arg_type.h"
#include "data_member_inst.h"
#include "data_member_list1.h"
#include "data_member_list2.h"
#include "data_member_list.h"
#include "print_derived_cpp.h"
#include "copy_list1.h"
#include "copy_list2.h"
#include "copy_list.h"
#include "deconstruction_list1.h"
#include "deconstruction_list.h"
#include "construction_list1.h"
#include "construction_list.h"
#include "print_list1.h"
#include "print_list2.h"
#include "print_list3.h"
#include "print_list.h"
#include "set_list1.h"
#include "set_list.h"
#include "assert_stmt1.h"
#include "assert_stmt.h"
#include "duplicate_list1.h"
#include "duplicate_list2.h"
#include "duplicate_list.h"
#include "func_list_cpp1.h"
#include "func_list_cpp2.h"
#include "func_list_cpp.h"
#include "recursive_func_def1.h"
#include "recursive_func_def2.h"
#include "recursive_func_def.h"
#include "printer_func_def1.h"
#include "printer_func_def2.h"
#include "printer_func_def.h"

#include "name_n_idx.h"
#include "name_n_ptr.h"

#define arg_type_token			arg_type1
#define arg_type_type			arg_type2

#define include_file_list_usr		include_file_list1
#define include_file_list_std		include_file_list2

#define set_method_arg_list_other	set_method_arg_list1
#define set_method_arg_list_first	set_method_arg_list2

#define data_member_list_token		data_member_list1
#define data_member_list_type		data_member_list2

#define deconstruction_list_c		deconstruction_list1
#define construction_list_c		construction_list1

#define set_list_c			set_list1

#define print_list_type			print_list1
#define print_list_token		print_list2
#define print_list_str			print_list3

#define copy_list_token			copy_list1
#define copy_list_type			copy_list2

#define duplicate_list_type		duplicate_list1
#define duplicate_list_token		duplicate_list2

/*#define func_list_source		func_list3104041755
#define func_list_child			func_list3325065994*/

#define recursive_func_decl_list_base_c		recursive_func_decl_list_base1
#define recursive_func_decl_list_derived_c	recursive_func_decl_list_derived1

#define nonrecursive_func_decl_list_c		nonrecursive_func_decl_list1

#define printer_func_def_str		printer_func_def1
#define printer_func_def_data		printer_func_def2

#define func_list_cpp_rec		func_list_cpp1
#define func_list_cpp_nonrec		func_list_cpp2

#define recursive_func_def_data		recursive_func_def1
#define recursive_func_def_func		recursive_func_def2

////

#define T_PRINTER_FUNC_DEF	104

#define obj_rfunc_decl_list_derived	m_20	//print_derived
#define obj_rfunc_decl_list_base	m_18	//print_base
#define obj_nonrfunc_decl_list		m_21
#define obj_func_list			m_30
//#define obj_class_name			m_1	//print_derived_cpp



#define	VISIT_LIST_IDX		0
#define	DUPLICATE_LIST_IDX	1
#define	COPY_LIST_IDX		2
#define	DECONSTRUCTION_LIST_IDX	3
#define	CONSTRUCTION_LIST_IDX	4
#define	PRINT_LIST_IDX		5
#define	SET_LIST_IDX		6
#define	INCLUDE_FILE_LIST_IDX	7
#define	SET_METHOD_ARG_LIST_IDX	8
#define	DATA_MEMBER_LIST_IDX	9

#define CONTEXT_P_LAST_SIZE 10

////

#include "../recursive_func/recfunc_context.h"

#include "../recursive_func/bkn_rule_id.h"
#include "../recursive_func/bkn_production1.h"
#include "../recursive_func/bkn_production2.h"
#include "../recursive_func/bkn_production.h"
#include "../recursive_func/bkn_symbol.h"
#include "../recursive_func/bkn_func_place_holder.h"

#define bkn_production_symb		bkn_production1
#define bkn_production_func		bkn_production2

////

#endif

