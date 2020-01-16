
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(A2o_MapperInterface) {

	ZEPHIR_REGISTER_INTERFACE(A2o, MapperInterface, a2o, mapperinterface, a2o_mapperinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(A2o_MapperInterface, mapVars);

