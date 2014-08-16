#ifndef NAME_N_IDX_H_
#define NAME_N_IDX_H_

#include <sstream>
#include "symbol_base.h"
using namespace std;

class name_n_idx
{
	public:
		name_n_idx();
		name_n_idx(const string & a_name, int a_idx);
		name_n_idx(const name_n_idx & a_name_n_idx);
		virtual ~name_n_idx();
		name_n_idx & operator = (const name_n_idx & a_name_n_idx);
		void set(const string & a_name, const int & a_idx);

		void print_this(std::ostream & out);
		
		long int hash_code();
		static long int hash_code(const string & a_name, int a_idx);
		
		//The key comparison function, a "Strict Weak Ordering" whose argument type is key_type;
		//it returns "true if its first argument is less than its second argument", and false otherwise. 
		//This is also defined as map::key_compare. 
//		bool operator()(const name_n_idx & an_obj,const name_n_idx & another_obj) const;

/*		int compare_name(const name_n_idx & a_name_n_idx) const;
		int compare_idx(const name_n_idx & a_name_n_idx) const;*/
	public:
		name_n_idx * duplicate();
	public:
		
		static std::locale loc;
		static const std::collate<char>& coll;
		static ostringstream ss;
		
		string	name;
		int	idx;
};

/*struct name_n_idx_less
{
	bool operator()(const name_n_idx & an_obj,const name_n_idx & another_obj) const
	{
		int comp_result = an_obj.compare_name(another_obj);
		if( comp_result == 0)
		{
			return an_obj.compare_idx(another_obj) < 0;
		}else
		{
			return comp_result < 0;
		}
	}
};*/

#endif
