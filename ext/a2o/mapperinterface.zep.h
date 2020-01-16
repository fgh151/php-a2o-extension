
extern zend_class_entry *a2o_mapperinterface_ce;

ZEPHIR_INIT_CLASS(A2o_MapperInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_a2o_mapperinterface_mapvars, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_a2o_mapperinterface_mapvars, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(a2o_mapperinterface_method_entry) {
	PHP_ABSTRACT_ME(A2o_MapperInterface, mapVars, arginfo_a2o_mapperinterface_mapvars)
	PHP_FE_END
};
