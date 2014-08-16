#include "backend.h"
#include <algorithm>
#include "global_defs.h"
#include <fstream>
#include <sstream>
using std::ofstream;
using std::stringstream;

//#define PRINT_TO_CONSOLE

#if DEBUG || PRINT_TO_CONSOLE
#include <iostream>
using std::cout;
using std::endl;
#endif


backend::backend (cfg * a_cfg_ptr): p_cfg(a_cfg_ptr)
{
}

backend::~backend ()
{
}

void backend::generate_output()
{
	context the_context;
	p_cfg->visit_this(the_context);

	for (std::list<name_n_ptr>::iterator 
		it = the_context.for_print.begin(); 
		it != the_context.for_print.end(); it ++)
	{
		print_to_file(it->name, it->ptr_symbol_base);
	}
	
	print_def_file(the_context);

	the_context.clean_up();
//	delete p_cfg;
	#ifdef DEBUG
	cout<<"symbol_base counter: "<<symbol_base::obj_counter<<endl;
	#endif
	return;
}


void backend::print_to_file(const string & a_file_name, symbol_base * p_symb)
{
#ifdef PRINT_TO_CONSOLE
	p_symb->print_this(cout);
#else
	ofstream fout;
	fout.open((OUTFILE_DIR+a_file_name).c_str());

	p_symb->print_this(fout);
	
	fout.close();
#endif
}

void backend::print_def_file(const context & a_context)
{
	std::string def_upper_name;
	std::string def_class_name;

#ifdef PRINT_TO_CONSOLE
#define OUT	cout
#else
	ofstream fout;
	stringstream ss;
	ss<< OUTFILE_DIR GLOBAL_DEF_H "_"<<&a_context<<".h";
	fout.open(ss.str().c_str());
#define OUT	fout
#endif

	for (std::list<name_n_idx>::const_iterator 
		it = a_context.name_list.begin(); 
		it != a_context.name_list.end(); it ++)
	{
		def_class_name = it->name;
		def_upper_name = it->name;
		transform(def_upper_name.begin(), def_upper_name.end(), def_upper_name.begin(), ::toupper);
		if(it->idx == DEF_BASE)
		{
			OUT<<"#define "<<def_upper_name<<"_BASE_H_USR_DEF_1\t\n";
			OUT<<"#define "<<def_upper_name<<"_BASE_H_USR_DEF_2\t\n";
			OUT<<"#define "<<def_upper_name<<"_BASE_H_USR_DEF_3\t\n";
		}else
		{
			OUT<<"#define "<<def_upper_name<<"_DERIVED_H_USR_DEF_1\t\n";
			OUT<<"#define "<<def_upper_name<<"_DERIVED_H_USR_DEF_2\t\n";
			OUT<<"#define "<<def_upper_name<<"_DERIVED_H_USR_DEF_3\t\n";
			OUT<<"#define "<<def_upper_name<<"_DERIVED_CPP_USR_DEF\t\n";
		}
		
	}
	for (std::list<name_n_idx>::const_iterator 
		it = a_context.name_list.begin(); 
		it != a_context.name_list.end(); it ++)
	{
		def_class_name = it->name;
		OUT<<"#include \""<<def_class_name<<".h\"\n";
	}

#ifndef PRINT_TO_CONSOLE
	fout.close();
#endif
}
