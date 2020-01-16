
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(A2o_Mapper) {

	ZEPHIR_REGISTER_CLASS(A2o, Mapper, a2o, mapper, a2o_mapper_method_entry, 0);

	return SUCCESS;

}

/**
 * @param source array of source [name => value]
 * @param reciever object that recieve props from source
 */
PHP_METHOD(A2o_Mapper, map) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i, length = 0, _1, _2;
	zval *source_param = NULL, *reciever, reciever_sub, recieverProps, recieverPropNames, currentProp, currentRecieverProp, currentValue, reflection;
	zval source;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&reciever_sub);
	ZVAL_UNDEF(&recieverProps);
	ZVAL_UNDEF(&recieverPropNames);
	ZVAL_UNDEF(&currentProp);
	ZVAL_UNDEF(&currentRecieverProp);
	ZVAL_UNDEF(&currentValue);
	ZVAL_UNDEF(&reflection);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &source_param, &reciever);

	zephir_get_arrval(&source, source_param);


	i = 0;
	ZEPHIR_CALL_FUNCTION(&recieverProps, "get_object_vars", NULL, 1, reciever);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&recieverPropNames);
	zephir_array_keys(&recieverPropNames, &recieverProps);
	length = (zephir_fast_count_int(&recieverProps) - 1);
	_2 = length;
	_1 = 0;
	_0 = 0;
	if (_1 <= _2) {
		while (1) {
			if (_0) {
				_1++;
				if (!(_1 <= _2)) {
					break;
				}
			} else {
				_0 = 1;
			}
			i = _1;
			ZEPHIR_OBS_NVAR(&currentProp);
			zephir_array_fetch_long(&currentProp, &recieverPropNames, i, PH_NOISY, "a2o/Mapper.zep", 21);
			ZEPHIR_OBS_NVAR(&currentValue);
			zephir_array_fetch(&currentValue, &source, &currentProp, PH_NOISY, "a2o/Mapper.zep", 22);
			ZEPHIR_INIT_NVAR(&reflection);
			object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionclass")));
			ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", &_3, 2, reciever);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&currentRecieverProp, &reflection, "getproperty", &_4, 3, &currentProp);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &currentRecieverProp, "setvalue", NULL, 0, reciever, &currentValue);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

