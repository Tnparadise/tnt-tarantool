#include <errno.h>
#include <limits.h>
#include <inttypes.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
 * Autogenerated file, do not edit it!
 */


#include <third_party/confetti/prscfg.h>
void out_warning(ConfettyError r, char *format, ...);
#include "cfg/tarantool_feeder_cfg.h"
static int
cmpNameAtoms(NameAtom *a, NameAtom *b) {
	while(a && b) {
		if (strcasecmp(a->name, b->name) != 0)
			return 0;
		a = a->next;
		b = b->next;
	}
	return (a == NULL && b == NULL) ? 1 : 0;
}

int
fill_default_tarantool_cfg(tarantool_cfg *c) {
	c->username = NULL;
	c->coredump = 0;
	c->admin_port = 0;
	c->log_level = 4;
	c->slab_alloc_arena = 1;
	c->slab_alloc_minimal = 64;
	c->slab_alloc_factor = 2;
	c->work_dir = NULL;
	c->pid_file = strdup("tarantool.pid");
	if (c->pid_file == NULL) return CNF_NOMEMORY;
	c->logger = NULL;
	c->logger_nonblock = 1;
	c->io_collect_interval = 0;
	c->backlog = 1024;
	c->readahead = 16320;
	c->wal_feeder_bind_ipaddr = NULL;
	c->wal_feeder_bind_port = 0;
	c->wal_feeder_dir = NULL;
	c->custom_proc_title = NULL;
	return 0;
}

static NameAtom _name__username[] = {
	{ "username", -1, NULL }
};
static NameAtom _name__coredump[] = {
	{ "coredump", -1, NULL }
};
static NameAtom _name__admin_port[] = {
	{ "admin_port", -1, NULL }
};
static NameAtom _name__log_level[] = {
	{ "log_level", -1, NULL }
};
static NameAtom _name__slab_alloc_arena[] = {
	{ "slab_alloc_arena", -1, NULL }
};
static NameAtom _name__slab_alloc_minimal[] = {
	{ "slab_alloc_minimal", -1, NULL }
};
static NameAtom _name__slab_alloc_factor[] = {
	{ "slab_alloc_factor", -1, NULL }
};
static NameAtom _name__work_dir[] = {
	{ "work_dir", -1, NULL }
};
static NameAtom _name__pid_file[] = {
	{ "pid_file", -1, NULL }
};
static NameAtom _name__logger[] = {
	{ "logger", -1, NULL }
};
static NameAtom _name__logger_nonblock[] = {
	{ "logger_nonblock", -1, NULL }
};
static NameAtom _name__io_collect_interval[] = {
	{ "io_collect_interval", -1, NULL }
};
static NameAtom _name__backlog[] = {
	{ "backlog", -1, NULL }
};
static NameAtom _name__readahead[] = {
	{ "readahead", -1, NULL }
};
static NameAtom _name__wal_feeder_bind_ipaddr[] = {
	{ "wal_feeder_bind_ipaddr", -1, NULL }
};
static NameAtom _name__wal_feeder_bind_port[] = {
	{ "wal_feeder_bind_port", -1, NULL }
};
static NameAtom _name__wal_feeder_dir[] = {
	{ "wal_feeder_dir", -1, NULL }
};
static NameAtom _name__custom_proc_title[] = {
	{ "custom_proc_title", -1, NULL }
};

#define ARRAYALLOC(x,n,t,_chk_ro, __flags)  do {                    \
   int l = 0, ar;                                                   \
   __typeof__(x) y = (x), t;                                        \
   if ( (n) <= 0 ) return CNF_WRONGINDEX; /* wrong index */         \
   while(y && *y) {                                                 \
       l++; y++;                                                    \
   }                                                                \
   if ( (n) >= (l + 1) ) {                                          \
      if (_chk_ro)  return CNF_RDONLY;                              \
      if ( (x) == NULL )                                            \
          t = y = malloc( ((n)+1) * sizeof( __typeof__(*(x))) );    \
      else {                                                        \
          t = realloc((x), ((n)+1) * sizeof( __typeof__(*(x))) );   \
          y = t + l;                                                \
      }                                                             \
      if (t == NULL)  return CNF_NOMEMORY;                          \
      (x) = t;                                                      \
      memset(y, 0, (((n)+1) - l) * sizeof( __typeof__(*(x))) );     \
      while ( y - (x) < (n) ) {                                     \
          *y = malloc( sizeof( __typeof__(**(x))) );                \
          if (*y == NULL)  return CNF_NOMEMORY;                     \
          if ( (ar = acceptDefault##t(*y)) != 0 ) return ar;        \
          (*y)->__confetti_flags = __flags;                         \
          y++;                                                      \
      }                                                             \
   }                                                                \
} while(0)

static ConfettyError
acceptValue(tarantool_cfg* c, OptDef* opt, int check_rdonly) {

	if ( cmpNameAtoms( opt->name, _name__username) ) {
		if (opt->paramType != stringType )
			return CNF_WRONGTYPE;
		errno = 0;
		if (check_rdonly && ( (opt->paramValue.stringval == NULL && c->username == NULL) || strcmp(opt->paramValue.stringval, c->username) != 0))
			return CNF_RDONLY;
		c->username = (opt->paramValue.stringval) ? strdup(opt->paramValue.stringval) : NULL;
		if (opt->paramValue.stringval && c->username == NULL)
			return CNF_NOMEMORY;
	}
	else if ( cmpNameAtoms( opt->name, _name__coredump) ) {
		if (opt->paramType != numberType )
			return CNF_WRONGTYPE;
		errno = 0;
		long int i32 = strtol(opt->paramValue.numberval, NULL, 10);
		if (i32 == 0 && errno == EINVAL)
			return CNF_WRONGINT;
		if ( (i32 == LONG_MIN || i32 == LONG_MAX) && errno == ERANGE)
			return CNF_WRONGRANGE;
		if (check_rdonly && c->coredump != i32)
			return CNF_RDONLY;
		c->coredump = i32;
	}
	else if ( cmpNameAtoms( opt->name, _name__admin_port) ) {
		if (opt->paramType != numberType )
			return CNF_WRONGTYPE;
		errno = 0;
		long int i32 = strtol(opt->paramValue.numberval, NULL, 10);
		if (i32 == 0 && errno == EINVAL)
			return CNF_WRONGINT;
		if ( (i32 == LONG_MIN || i32 == LONG_MAX) && errno == ERANGE)
			return CNF_WRONGRANGE;
		if (check_rdonly && c->admin_port != i32)
			return CNF_RDONLY;
		c->admin_port = i32;
	}
	else if ( cmpNameAtoms( opt->name, _name__log_level) ) {
		if (opt->paramType != numberType )
			return CNF_WRONGTYPE;
		errno = 0;
		long int i32 = strtol(opt->paramValue.numberval, NULL, 10);
		if (i32 == 0 && errno == EINVAL)
			return CNF_WRONGINT;
		if ( (i32 == LONG_MIN || i32 == LONG_MAX) && errno == ERANGE)
			return CNF_WRONGRANGE;
		c->log_level = i32;
	}
	else if ( cmpNameAtoms( opt->name, _name__slab_alloc_arena) ) {
		if (opt->paramType != numberType )
			return CNF_WRONGTYPE;
		errno = 0;
		double dbl = strtod(opt->paramValue.numberval, NULL);
		if ( (dbl == 0 || dbl == -HUGE_VAL || dbl == HUGE_VAL) && errno == ERANGE)
			return CNF_WRONGRANGE;
		if (check_rdonly && c->slab_alloc_arena != dbl)
			return CNF_RDONLY;
		c->slab_alloc_arena = dbl;
	}
	else if ( cmpNameAtoms( opt->name, _name__slab_alloc_minimal) ) {
		if (opt->paramType != numberType )
			return CNF_WRONGTYPE;
		errno = 0;
		long int i32 = strtol(opt->paramValue.numberval, NULL, 10);
		if (i32 == 0 && errno == EINVAL)
			return CNF_WRONGINT;
		if ( (i32 == LONG_MIN || i32 == LONG_MAX) && errno == ERANGE)
			return CNF_WRONGRANGE;
		if (check_rdonly && c->slab_alloc_minimal != i32)
			return CNF_RDONLY;
		c->slab_alloc_minimal = i32;
	}
	else if ( cmpNameAtoms( opt->name, _name__slab_alloc_factor) ) {
		if (opt->paramType != numberType )
			return CNF_WRONGTYPE;
		errno = 0;
		double dbl = strtod(opt->paramValue.numberval, NULL);
		if ( (dbl == 0 || dbl == -HUGE_VAL || dbl == HUGE_VAL) && errno == ERANGE)
			return CNF_WRONGRANGE;
		if (check_rdonly && c->slab_alloc_factor != dbl)
			return CNF_RDONLY;
		c->slab_alloc_factor = dbl;
	}
	else if ( cmpNameAtoms( opt->name, _name__work_dir) ) {
		if (opt->paramType != stringType )
			return CNF_WRONGTYPE;
		errno = 0;
		if (check_rdonly && ( (opt->paramValue.stringval == NULL && c->work_dir == NULL) || strcmp(opt->paramValue.stringval, c->work_dir) != 0))
			return CNF_RDONLY;
		c->work_dir = (opt->paramValue.stringval) ? strdup(opt->paramValue.stringval) : NULL;
		if (opt->paramValue.stringval && c->work_dir == NULL)
			return CNF_NOMEMORY;
	}
	else if ( cmpNameAtoms( opt->name, _name__pid_file) ) {
		if (opt->paramType != stringType )
			return CNF_WRONGTYPE;
		errno = 0;
		if (check_rdonly && ( (opt->paramValue.stringval == NULL && c->pid_file == NULL) || strcmp(opt->paramValue.stringval, c->pid_file) != 0))
			return CNF_RDONLY;
		c->pid_file = (opt->paramValue.stringval) ? strdup(opt->paramValue.stringval) : NULL;
		if (opt->paramValue.stringval && c->pid_file == NULL)
			return CNF_NOMEMORY;
	}
	else if ( cmpNameAtoms( opt->name, _name__logger) ) {
		if (opt->paramType != stringType )
			return CNF_WRONGTYPE;
		errno = 0;
		if (check_rdonly && ( (opt->paramValue.stringval == NULL && c->logger == NULL) || strcmp(opt->paramValue.stringval, c->logger) != 0))
			return CNF_RDONLY;
		c->logger = (opt->paramValue.stringval) ? strdup(opt->paramValue.stringval) : NULL;
		if (opt->paramValue.stringval && c->logger == NULL)
			return CNF_NOMEMORY;
	}
	else if ( cmpNameAtoms( opt->name, _name__logger_nonblock) ) {
		if (opt->paramType != numberType )
			return CNF_WRONGTYPE;
		errno = 0;
		long int i32 = strtol(opt->paramValue.numberval, NULL, 10);
		if (i32 == 0 && errno == EINVAL)
			return CNF_WRONGINT;
		if ( (i32 == LONG_MIN || i32 == LONG_MAX) && errno == ERANGE)
			return CNF_WRONGRANGE;
		if (check_rdonly && c->logger_nonblock != i32)
			return CNF_RDONLY;
		c->logger_nonblock = i32;
	}
	else if ( cmpNameAtoms( opt->name, _name__io_collect_interval) ) {
		if (opt->paramType != numberType )
			return CNF_WRONGTYPE;
		errno = 0;
		double dbl = strtod(opt->paramValue.numberval, NULL);
		if ( (dbl == 0 || dbl == -HUGE_VAL || dbl == HUGE_VAL) && errno == ERANGE)
			return CNF_WRONGRANGE;
		if (check_rdonly && c->io_collect_interval != dbl)
			return CNF_RDONLY;
		c->io_collect_interval = dbl;
	}
	else if ( cmpNameAtoms( opt->name, _name__backlog) ) {
		if (opt->paramType != numberType )
			return CNF_WRONGTYPE;
		errno = 0;
		long int i32 = strtol(opt->paramValue.numberval, NULL, 10);
		if (i32 == 0 && errno == EINVAL)
			return CNF_WRONGINT;
		if ( (i32 == LONG_MIN || i32 == LONG_MAX) && errno == ERANGE)
			return CNF_WRONGRANGE;
		if (check_rdonly && c->backlog != i32)
			return CNF_RDONLY;
		c->backlog = i32;
	}
	else if ( cmpNameAtoms( opt->name, _name__readahead) ) {
		if (opt->paramType != numberType )
			return CNF_WRONGTYPE;
		errno = 0;
		long int i32 = strtol(opt->paramValue.numberval, NULL, 10);
		if (i32 == 0 && errno == EINVAL)
			return CNF_WRONGINT;
		if ( (i32 == LONG_MIN || i32 == LONG_MAX) && errno == ERANGE)
			return CNF_WRONGRANGE;
		c->readahead = i32;
	}
	else if ( cmpNameAtoms( opt->name, _name__wal_feeder_bind_ipaddr) ) {
		if (opt->paramType != stringType )
			return CNF_WRONGTYPE;
		errno = 0;
		if (check_rdonly && ( (opt->paramValue.stringval == NULL && c->wal_feeder_bind_ipaddr == NULL) || strcmp(opt->paramValue.stringval, c->wal_feeder_bind_ipaddr) != 0))
			return CNF_RDONLY;
		c->wal_feeder_bind_ipaddr = (opt->paramValue.stringval) ? strdup(opt->paramValue.stringval) : NULL;
		if (opt->paramValue.stringval && c->wal_feeder_bind_ipaddr == NULL)
			return CNF_NOMEMORY;
	}
	else if ( cmpNameAtoms( opt->name, _name__wal_feeder_bind_port) ) {
		if (opt->paramType != numberType )
			return CNF_WRONGTYPE;
		errno = 0;
		long int i32 = strtol(opt->paramValue.numberval, NULL, 10);
		if (i32 == 0 && errno == EINVAL)
			return CNF_WRONGINT;
		if ( (i32 == LONG_MIN || i32 == LONG_MAX) && errno == ERANGE)
			return CNF_WRONGRANGE;
		if (check_rdonly && c->wal_feeder_bind_port != i32)
			return CNF_RDONLY;
		c->wal_feeder_bind_port = i32;
	}
	else if ( cmpNameAtoms( opt->name, _name__wal_feeder_dir) ) {
		if (opt->paramType != stringType )
			return CNF_WRONGTYPE;
		errno = 0;
		if (check_rdonly && ( (opt->paramValue.stringval == NULL && c->wal_feeder_dir == NULL) || strcmp(opt->paramValue.stringval, c->wal_feeder_dir) != 0))
			return CNF_RDONLY;
		c->wal_feeder_dir = (opt->paramValue.stringval) ? strdup(opt->paramValue.stringval) : NULL;
		if (opt->paramValue.stringval && c->wal_feeder_dir == NULL)
			return CNF_NOMEMORY;
	}
	else if ( cmpNameAtoms( opt->name, _name__custom_proc_title) ) {
		if (opt->paramType != stringType )
			return CNF_WRONGTYPE;
		errno = 0;
		if (check_rdonly && ( (opt->paramValue.stringval == NULL && c->custom_proc_title == NULL) || strcmp(opt->paramValue.stringval, c->custom_proc_title) != 0))
			return CNF_RDONLY;
		c->custom_proc_title = (opt->paramValue.stringval) ? strdup(opt->paramValue.stringval) : NULL;
		if (opt->paramValue.stringval && c->custom_proc_title == NULL)
			return CNF_NOMEMORY;
	}
	else {
		return CNF_MISSED;
	}
	return CNF_OK;
}

static void cleanFlags(tarantool_cfg* c, OptDef* opt);

#define PRINTBUFLEN	8192
static char*
dumpOptDef(NameAtom *atom) {
	static char	buf[PRINTBUFLEN], *ptr;
	int  i = 0;

	ptr = buf;
	while(atom) {
		if (i) ptr += snprintf(ptr, PRINTBUFLEN - 1 - (ptr - buf), ".");
		ptr += snprintf(ptr, PRINTBUFLEN - 1 - (ptr - buf), "%s", atom->name);
		if (atom->index >= 0)
			ptr += snprintf(ptr, PRINTBUFLEN - 1 - (ptr - buf), "[%d]", atom->index);
		i = 1;
		atom = atom->next;
	}
	return buf;
}

static void
acceptCfgDef(tarantool_cfg *c, OptDef *opt, int check_rdonly, int *n_accepted, int *n_skipped) {
	ConfettyError	r;
	OptDef		*orig_opt = opt;

	if (n_accepted) *n_accepted=0;
	if (n_skipped) *n_skipped=0;

	while(opt) {
		r = acceptValue(c, opt, check_rdonly);
		switch(r) {
			case CNF_OK:
				if (n_accepted) (*n_accepted)++;
				break;
			case CNF_MISSED:
				out_warning(r, "Could not find '%s' option", dumpOptDef(opt->name));
				if (n_skipped) (*n_skipped)++;
				break;
			case CNF_WRONGTYPE:
				out_warning(r, "Wrong value type for '%s' option", dumpOptDef(opt->name));
				if (n_skipped) (*n_skipped)++;
				break;
			case CNF_WRONGINDEX:
				out_warning(r, "Wrong array index in '%s' option", dumpOptDef(opt->name));
				if (n_skipped) (*n_skipped)++;
				break;
			case CNF_RDONLY:
				out_warning(r, "Could not accept read only '%s' option", dumpOptDef(opt->name));
				if (n_skipped) (*n_skipped)++;
				break;
			case CNF_WRONGINT:
				out_warning(r, "Could not parse integer value for '%s' option", dumpOptDef(opt->name));
				if (n_skipped) (*n_skipped)++;
				break;
			case CNF_WRONGRANGE:
				out_warning(r, "Wrong range for '%s' option", dumpOptDef(opt->name));
				if (n_skipped) (*n_skipped)++;
				break;
			case CNF_NOMEMORY:
				out_warning(r, "Not enough memory to accept '%s' option", dumpOptDef(opt->name));
				if (n_skipped) (*n_skipped)++;
				break;
			case CNF_NOTSET:
				out_warning(r, "Option '%s' is not set (or has a default value)", dumpOptDef(opt->name));
				if (n_skipped) (*n_skipped)++;
				break;
			default:
				out_warning(r, "Unknown error for '%s' option", dumpOptDef(opt->name));
				if (n_skipped) (*n_skipped)++;
				break;
		}

		opt = opt->next;
	}

	cleanFlags(c, orig_opt);
}

void
parse_cfg_file_tarantool_cfg(tarantool_cfg *c, FILE *fh, int check_rdonly, int *n_accepted, int *n_skipped) {
	OptDef *option;

	option = parseCfgDef(fh);
	acceptCfgDef(c, option, check_rdonly, n_accepted, n_skipped);
	freeCfgDef(option);
}

void
parse_cfg_buffer_tarantool_cfg(tarantool_cfg *c, char *buffer, int check_rdonly, int *n_accepted, int *n_skipped) {
	OptDef *option;

	option = parseCfgDefBuffer(buffer);
	acceptCfgDef(c, option, check_rdonly, n_accepted, n_skipped);
	freeCfgDef(option);
}

/************** Iterator **************/
typedef enum IteratorState {
	_S_Initial = 0,
	S_name__username,
	S_name__coredump,
	S_name__admin_port,
	S_name__log_level,
	S_name__slab_alloc_arena,
	S_name__slab_alloc_minimal,
	S_name__slab_alloc_factor,
	S_name__work_dir,
	S_name__pid_file,
	S_name__logger,
	S_name__logger_nonblock,
	S_name__io_collect_interval,
	S_name__backlog,
	S_name__readahead,
	S_name__wal_feeder_bind_ipaddr,
	S_name__wal_feeder_bind_port,
	S_name__wal_feeder_dir,
	S_name__custom_proc_title,
	_S_Finished
} IteratorState;

struct tarantool_cfg_iterator_t {
	IteratorState	state;
};

tarantool_cfg_iterator_t*
tarantool_cfg_iterator_init() {
	tarantool_cfg_iterator_t *i = malloc(sizeof(*i));
	if (i == NULL) return NULL;
	memset(i, 0, sizeof(*i));
	return i;
}

char*
tarantool_cfg_iterator_next(tarantool_cfg_iterator_t* i, tarantool_cfg *c, char **v) {
	static char	buf[PRINTBUFLEN];

	*v = NULL;
	goto again; /* keep compiler quiet */
again:
	switch(i->state) {
		case _S_Initial:
		case S_name__username:
			*v = (c->username) ? strdup(c->username) : NULL;
			if (*v == NULL && c->username) {
				free(i);
				out_warning(CNF_NOMEMORY, "No memory to output value");
				return NULL;
			}
			snprintf(buf, PRINTBUFLEN-1, "username");
			i->state = S_name__coredump;
			return buf;
		case S_name__coredump:
			*v = malloc(32);
			if (*v == NULL) {
				free(i);
				out_warning(CNF_NOMEMORY, "No memory to output value");
				return NULL;
			}
			sprintf(*v, "%"PRId32, c->coredump);
			snprintf(buf, PRINTBUFLEN-1, "coredump");
			i->state = S_name__admin_port;
			return buf;
		case S_name__admin_port:
			*v = malloc(32);
			if (*v == NULL) {
				free(i);
				out_warning(CNF_NOMEMORY, "No memory to output value");
				return NULL;
			}
			sprintf(*v, "%"PRId32, c->admin_port);
			snprintf(buf, PRINTBUFLEN-1, "admin_port");
			i->state = S_name__log_level;
			return buf;
		case S_name__log_level:
			*v = malloc(32);
			if (*v == NULL) {
				free(i);
				out_warning(CNF_NOMEMORY, "No memory to output value");
				return NULL;
			}
			sprintf(*v, "%"PRId32, c->log_level);
			snprintf(buf, PRINTBUFLEN-1, "log_level");
			i->state = S_name__slab_alloc_arena;
			return buf;
		case S_name__slab_alloc_arena:
			*v = malloc(32);
			if (*v == NULL) {
				free(i);
				out_warning(CNF_NOMEMORY, "No memory to output value");
				return NULL;
			}
			sprintf(*v, "%g", c->slab_alloc_arena);
			snprintf(buf, PRINTBUFLEN-1, "slab_alloc_arena");
			i->state = S_name__slab_alloc_minimal;
			return buf;
		case S_name__slab_alloc_minimal:
			*v = malloc(32);
			if (*v == NULL) {
				free(i);
				out_warning(CNF_NOMEMORY, "No memory to output value");
				return NULL;
			}
			sprintf(*v, "%"PRId32, c->slab_alloc_minimal);
			snprintf(buf, PRINTBUFLEN-1, "slab_alloc_minimal");
			i->state = S_name__slab_alloc_factor;
			return buf;
		case S_name__slab_alloc_factor:
			*v = malloc(32);
			if (*v == NULL) {
				free(i);
				out_warning(CNF_NOMEMORY, "No memory to output value");
				return NULL;
			}
			sprintf(*v, "%g", c->slab_alloc_factor);
			snprintf(buf, PRINTBUFLEN-1, "slab_alloc_factor");
			i->state = S_name__work_dir;
			return buf;
		case S_name__work_dir:
			*v = (c->work_dir) ? strdup(c->work_dir) : NULL;
			if (*v == NULL && c->work_dir) {
				free(i);
				out_warning(CNF_NOMEMORY, "No memory to output value");
				return NULL;
			}
			snprintf(buf, PRINTBUFLEN-1, "work_dir");
			i->state = S_name__pid_file;
			return buf;
		case S_name__pid_file:
			*v = (c->pid_file) ? strdup(c->pid_file) : NULL;
			if (*v == NULL && c->pid_file) {
				free(i);
				out_warning(CNF_NOMEMORY, "No memory to output value");
				return NULL;
			}
			snprintf(buf, PRINTBUFLEN-1, "pid_file");
			i->state = S_name__logger;
			return buf;
		case S_name__logger:
			*v = (c->logger) ? strdup(c->logger) : NULL;
			if (*v == NULL && c->logger) {
				free(i);
				out_warning(CNF_NOMEMORY, "No memory to output value");
				return NULL;
			}
			snprintf(buf, PRINTBUFLEN-1, "logger");
			i->state = S_name__logger_nonblock;
			return buf;
		case S_name__logger_nonblock:
			*v = malloc(32);
			if (*v == NULL) {
				free(i);
				out_warning(CNF_NOMEMORY, "No memory to output value");
				return NULL;
			}
			sprintf(*v, "%"PRId32, c->logger_nonblock);
			snprintf(buf, PRINTBUFLEN-1, "logger_nonblock");
			i->state = S_name__io_collect_interval;
			return buf;
		case S_name__io_collect_interval:
			*v = malloc(32);
			if (*v == NULL) {
				free(i);
				out_warning(CNF_NOMEMORY, "No memory to output value");
				return NULL;
			}
			sprintf(*v, "%g", c->io_collect_interval);
			snprintf(buf, PRINTBUFLEN-1, "io_collect_interval");
			i->state = S_name__backlog;
			return buf;
		case S_name__backlog:
			*v = malloc(32);
			if (*v == NULL) {
				free(i);
				out_warning(CNF_NOMEMORY, "No memory to output value");
				return NULL;
			}
			sprintf(*v, "%"PRId32, c->backlog);
			snprintf(buf, PRINTBUFLEN-1, "backlog");
			i->state = S_name__readahead;
			return buf;
		case S_name__readahead:
			*v = malloc(32);
			if (*v == NULL) {
				free(i);
				out_warning(CNF_NOMEMORY, "No memory to output value");
				return NULL;
			}
			sprintf(*v, "%"PRId32, c->readahead);
			snprintf(buf, PRINTBUFLEN-1, "readahead");
			i->state = S_name__wal_feeder_bind_ipaddr;
			return buf;
		case S_name__wal_feeder_bind_ipaddr:
			*v = (c->wal_feeder_bind_ipaddr) ? strdup(c->wal_feeder_bind_ipaddr) : NULL;
			if (*v == NULL && c->wal_feeder_bind_ipaddr) {
				free(i);
				out_warning(CNF_NOMEMORY, "No memory to output value");
				return NULL;
			}
			snprintf(buf, PRINTBUFLEN-1, "wal_feeder_bind_ipaddr");
			i->state = S_name__wal_feeder_bind_port;
			return buf;
		case S_name__wal_feeder_bind_port:
			*v = malloc(32);
			if (*v == NULL) {
				free(i);
				out_warning(CNF_NOMEMORY, "No memory to output value");
				return NULL;
			}
			sprintf(*v, "%"PRId32, c->wal_feeder_bind_port);
			snprintf(buf, PRINTBUFLEN-1, "wal_feeder_bind_port");
			i->state = S_name__wal_feeder_dir;
			return buf;
		case S_name__wal_feeder_dir:
			*v = (c->wal_feeder_dir) ? strdup(c->wal_feeder_dir) : NULL;
			if (*v == NULL && c->wal_feeder_dir) {
				free(i);
				out_warning(CNF_NOMEMORY, "No memory to output value");
				return NULL;
			}
			snprintf(buf, PRINTBUFLEN-1, "wal_feeder_dir");
			i->state = S_name__custom_proc_title;
			return buf;
		case S_name__custom_proc_title:
			*v = (c->custom_proc_title) ? strdup(c->custom_proc_title) : NULL;
			if (*v == NULL && c->custom_proc_title) {
				free(i);
				out_warning(CNF_NOMEMORY, "No memory to output value");
				return NULL;
			}
			snprintf(buf, PRINTBUFLEN-1, "custom_proc_title");
			i->state = _S_Finished;
			return buf;
		case _S_Finished:
			free(i);
			break;
		default:
			out_warning(CNF_INTERNALERROR, "Unknown state for tarantool_cfg_iterator_t: %d", i->state);
			free(i);
	}
	return NULL;
}

/************** Checking of required fields  **************/
int
check_cfg_tarantool_cfg(tarantool_cfg *c) {
	tarantool_cfg_iterator_t iterator, *i = &iterator;
	int	res = 0;

	if (c->wal_feeder_bind_ipaddr == NULL) {
		res++;
		out_warning(CNF_NOTSET, "Option '%s' is not set (or has a default value)", dumpOptDef(_name__wal_feeder_bind_ipaddr));
	}

	if (c->wal_feeder_bind_port == 0) {
		res++;
		out_warning(CNF_NOTSET, "Option '%s' is not set (or has a default value)", dumpOptDef(_name__wal_feeder_bind_port));
	}

	if (c->wal_feeder_dir == NULL) {
		res++;
		out_warning(CNF_NOTSET, "Option '%s' is not set (or has a default value)", dumpOptDef(_name__wal_feeder_dir));
	}

	return res;
}

static void
cleanFlags(tarantool_cfg* c, OptDef* opt) {
	tarantool_cfg_iterator_t iterator, *i = &iterator;

}

/************** Duplicate config  **************/

int
dup_tarantool_cfg(tarantool_cfg* dst, tarantool_cfg* src) {
	tarantool_cfg_iterator_t iterator, *i = &iterator;

	dst->username = src->username == NULL ? NULL : strdup(src->username);
	if (src->username != NULL && dst->username == NULL)
		return CNF_NOMEMORY;
	dst->coredump = src->coredump;
	dst->admin_port = src->admin_port;
	dst->log_level = src->log_level;
	dst->slab_alloc_arena = src->slab_alloc_arena;
	dst->slab_alloc_minimal = src->slab_alloc_minimal;
	dst->slab_alloc_factor = src->slab_alloc_factor;
	dst->work_dir = src->work_dir == NULL ? NULL : strdup(src->work_dir);
	if (src->work_dir != NULL && dst->work_dir == NULL)
		return CNF_NOMEMORY;
	dst->pid_file = src->pid_file == NULL ? NULL : strdup(src->pid_file);
	if (src->pid_file != NULL && dst->pid_file == NULL)
		return CNF_NOMEMORY;
	dst->logger = src->logger == NULL ? NULL : strdup(src->logger);
	if (src->logger != NULL && dst->logger == NULL)
		return CNF_NOMEMORY;
	dst->logger_nonblock = src->logger_nonblock;
	dst->io_collect_interval = src->io_collect_interval;
	dst->backlog = src->backlog;
	dst->readahead = src->readahead;
	dst->wal_feeder_bind_ipaddr = src->wal_feeder_bind_ipaddr == NULL ? NULL : strdup(src->wal_feeder_bind_ipaddr);
	if (src->wal_feeder_bind_ipaddr != NULL && dst->wal_feeder_bind_ipaddr == NULL)
		return CNF_NOMEMORY;
	dst->wal_feeder_bind_port = src->wal_feeder_bind_port;
	dst->wal_feeder_dir = src->wal_feeder_dir == NULL ? NULL : strdup(src->wal_feeder_dir);
	if (src->wal_feeder_dir != NULL && dst->wal_feeder_dir == NULL)
		return CNF_NOMEMORY;
	dst->custom_proc_title = src->custom_proc_title == NULL ? NULL : strdup(src->custom_proc_title);
	if (src->custom_proc_title != NULL && dst->custom_proc_title == NULL)
		return CNF_NOMEMORY;

	return CNF_OK;
}

/************** Destroy config  **************/

void
destroy_tarantool_cfg(tarantool_cfg* c) {
	tarantool_cfg_iterator_t iterator, *i = &iterator;

	if (c->username != NULL)
		free(c->username);
	if (c->work_dir != NULL)
		free(c->work_dir);
	if (c->pid_file != NULL)
		free(c->pid_file);
	if (c->logger != NULL)
		free(c->logger);
	if (c->wal_feeder_bind_ipaddr != NULL)
		free(c->wal_feeder_bind_ipaddr);
	if (c->wal_feeder_dir != NULL)
		free(c->wal_feeder_dir);
	if (c->custom_proc_title != NULL)
		free(c->custom_proc_title);
}

/************** Compare config  **************/

int
confetti_strcmp(char *s1, char *s2) {
	if (s1 == NULL || s2 == NULL) {
		if (s1 != s2)
			return s1 == NULL ? -1 : 1;
		else
			return 0;
	}

	return strcmp(s1, s2);
}

char *
cmp_tarantool_cfg(tarantool_cfg* c1, tarantool_cfg* c2, int only_check_rdonly) {
	tarantool_cfg_iterator_t iterator1, iterator2, *i1 = &iterator1, *i2 = &iterator2;
	static char diff[PRINTBUFLEN];

	if (confetti_strcmp(c1->username, c2->username) != 0) {
		snprintf(diff, PRINTBUFLEN - 1, "%s", "c->username");

		return diff;
}
	if (c1->coredump != c2->coredump) {
		snprintf(diff, PRINTBUFLEN - 1, "%s", "c->coredump");

		return diff;
	}
	if (c1->admin_port != c2->admin_port) {
		snprintf(diff, PRINTBUFLEN - 1, "%s", "c->admin_port");

		return diff;
	}
	if (!only_check_rdonly) {
		if (c1->log_level != c2->log_level) {
			snprintf(diff, PRINTBUFLEN - 1, "%s", "c->log_level");

			return diff;
		}
	}
	if (c1->slab_alloc_arena != c2->slab_alloc_arena) {
		snprintf(diff, PRINTBUFLEN - 1, "%s", "c->slab_alloc_arena");

		return diff;
	}
	if (c1->slab_alloc_minimal != c2->slab_alloc_minimal) {
		snprintf(diff, PRINTBUFLEN - 1, "%s", "c->slab_alloc_minimal");

		return diff;
	}
	if (c1->slab_alloc_factor != c2->slab_alloc_factor) {
		snprintf(diff, PRINTBUFLEN - 1, "%s", "c->slab_alloc_factor");

		return diff;
	}
	if (confetti_strcmp(c1->work_dir, c2->work_dir) != 0) {
		snprintf(diff, PRINTBUFLEN - 1, "%s", "c->work_dir");

		return diff;
}
	if (confetti_strcmp(c1->pid_file, c2->pid_file) != 0) {
		snprintf(diff, PRINTBUFLEN - 1, "%s", "c->pid_file");

		return diff;
}
	if (confetti_strcmp(c1->logger, c2->logger) != 0) {
		snprintf(diff, PRINTBUFLEN - 1, "%s", "c->logger");

		return diff;
}
	if (c1->logger_nonblock != c2->logger_nonblock) {
		snprintf(diff, PRINTBUFLEN - 1, "%s", "c->logger_nonblock");

		return diff;
	}
	if (c1->io_collect_interval != c2->io_collect_interval) {
		snprintf(diff, PRINTBUFLEN - 1, "%s", "c->io_collect_interval");

		return diff;
	}
	if (c1->backlog != c2->backlog) {
		snprintf(diff, PRINTBUFLEN - 1, "%s", "c->backlog");

		return diff;
	}
	if (!only_check_rdonly) {
		if (c1->readahead != c2->readahead) {
			snprintf(diff, PRINTBUFLEN - 1, "%s", "c->readahead");

			return diff;
		}
	}
	if (confetti_strcmp(c1->wal_feeder_bind_ipaddr, c2->wal_feeder_bind_ipaddr) != 0) {
		snprintf(diff, PRINTBUFLEN - 1, "%s", "c->wal_feeder_bind_ipaddr");

		return diff;
}
	if (c1->wal_feeder_bind_port != c2->wal_feeder_bind_port) {
		snprintf(diff, PRINTBUFLEN - 1, "%s", "c->wal_feeder_bind_port");

		return diff;
	}
	if (confetti_strcmp(c1->wal_feeder_dir, c2->wal_feeder_dir) != 0) {
		snprintf(diff, PRINTBUFLEN - 1, "%s", "c->wal_feeder_dir");

		return diff;
}
	if (confetti_strcmp(c1->custom_proc_title, c2->custom_proc_title) != 0) {
		snprintf(diff, PRINTBUFLEN - 1, "%s", "c->custom_proc_title");

		return diff;
}

	return 0;
}

