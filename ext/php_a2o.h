
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_A2O_H
#define PHP_A2O_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_A2O_NAME        "a2o"
#define PHP_A2O_VERSION     "0.0.1"
#define PHP_A2O_EXTNAME     "a2o"
#define PHP_A2O_AUTHOR      "Fedor B Gorsky"
#define PHP_A2O_ZEPVERSION  "0.12.12-$Id$"
#define PHP_A2O_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(a2o)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(a2o)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(a2o)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(a2o, v)
#else
	#define ZEPHIR_GLOBAL(v) (a2o_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_a2o_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(a2o_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(a2o_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def a2o_globals
#define zend_zephir_globals_def zend_a2o_globals

extern zend_module_entry a2o_module_entry;
#define phpext_a2o_ptr &a2o_module_entry

#endif
