#include "name_n_idx.h"
#include <iostream>

std::locale name_n_idx::loc;
const std::collate<char>& name_n_idx::coll = std::use_facet<std::collate<char> >(name_n_idx::loc);
std::ostringstream name_n_idx::ss;

name_n_idx::name_n_idx()
{
}
name_n_idx::name_n_idx(const name_n_idx & a_name_n_idx)
{
	name = a_name_n_idx.name;
	idx = a_name_n_idx.idx;
}
name_n_idx::name_n_idx(const string & a_name, int a_idx)
{
	name =	a_name;
	idx =	a_idx;
}
name_n_idx::~name_n_idx()
{
}
name_n_idx & name_n_idx::operator = (const name_n_idx & a_name_n_idx)
{
	name = a_name_n_idx.name;
	idx = a_name_n_idx.idx;
}


void name_n_idx::print_this(std::ostream & out)
{
	out<< name;
	out<< idx;
}

void name_n_idx::set(const string & a_name, const int & a_idx)
{
	name =	a_name;
	idx =	a_idx;
}

name_n_idx * name_n_idx::duplicate()
{
	name_n_idx * a_copy = new name_n_idx;
	a_copy->name = name;
	a_copy->idx = idx;
	return a_copy;
}

//The key comparison function, a "Strict Weak Ordering" whose argument type is key_type;
//it returns "true if its first argument is less than its second argument", and false otherwise. 
//This is also defined as map::key_compare. 
/*bool name_n_idx::operator()(const name_n_idx & an_obj, const name_n_idx & another_obj) const
{
	int comp_result = an_obj.name.compare(another_obj.name);
	if(comp_result == 0)
	{
		return an_obj.idx < another_obj.idx;
	}else
	{
		return comp_result < 0;
	}
}*/

/*int name_n_idx::compare_name(const name_n_idx & a_name_n_idx) const
{
	return name.compare(a_name_n_idx.name);
}

int name_n_idx::compare_idx(const name_n_idx & a_name_n_idx) const
{
	return idx - a_name_n_idx.idx;
}*/

long int name_n_idx::hash_code()
{
	ss<<idx;
	string n_idx = name+ss.str();
	ss.str("");
	return coll.hash(n_idx.data(),n_idx.data()+n_idx.length());
}

long int name_n_idx::hash_code(const string & a_name, int an_idx)
{
	ss<<an_idx;
	string n_idx = a_name+ss.str();
	ss.str("");
	return coll.hash(n_idx.data(),n_idx.data()+n_idx.length());
}

