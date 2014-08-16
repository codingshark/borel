#ifndef GLOBAL_DEFS_H_
#define GLOBAL_DEFS_H_


#define SYM_TYPE		1
#define SYM_TOKEN		2
#define SYM_STR			3
#define SYM_RECURSIVE		4
#define SYM_NONRECURSIVE	5
#define SYM_UNKNOWN		6

#define RECURSIVE_FUNC		"recursive"
#define NONRECURSIVE_FUNC	"nonrecursive"

#define IS_LEFT_SYMBOL(x)	((x<0) ? 1 : 0)
#define LEFT_SYMBOL		-1
#define NONREC_FUNC_INDEX	-1


#define OUTFILE_DIR		"./outputs/"

#define GLOBAL_DEF_H		"glb_def"
#define BASE_CLASS		"symbol_base"

#define DEF_BASE	1
#define DEF_DERIVED	2

#endif
