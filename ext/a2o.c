
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "a2o.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *a2o_mapper_ce;

ZEND_DECLARE_MODULE_GLOBALS(a2o)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(a2o)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(A2o_Mapper);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(a2o)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_a2o_globals *a2o_globals TSRMLS_DC)
{
	a2o_globals->initialized = 0;

	/* Cache Enabled */
	a2o_globals->cache_enabled = 1;

	/* Recursive Lock */
	a2o_globals->recursive_lock = 0;

	/* Static cache */
	memset(a2o_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_a2o_globals *a2o_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(a2o)
{
	zend_a2o_globals *a2o_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	a2o_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(a2o_globals_ptr);
	zephir_initialize_memory(a2o_globals_ptr);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(a2o)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(a2o)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_A2O_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_A2O_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_A2O_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_A2O_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_A2O_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(a2o)
{
	php_zephir_init_globals(a2o_globals);
	php_zephir_init_module_globals(a2o_globals);
}

static PHP_GSHUTDOWN_FUNCTION(a2o)
{
	
}


zend_function_entry php_a2o_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_a2o_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry a2o_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_a2o_deps,
	PHP_A2O_EXTNAME,
	php_a2o_functions,
	PHP_MINIT(a2o),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(a2o),
#else
	NULL,
#endif
	PHP_RINIT(a2o),
	PHP_RSHUTDOWN(a2o),
	PHP_MINFO(a2o),
	PHP_A2O_VERSION,
	ZEND_MODULE_GLOBALS(a2o),
	PHP_GINIT(a2o),
	PHP_GSHUTDOWN(a2o),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(a2o),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_A2O
ZEND_GET_MODULE(a2o)
#endif
