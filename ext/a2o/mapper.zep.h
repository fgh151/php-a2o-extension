
extern zend_class_entry *a2o_mapper_ce;

ZEPHIR_INIT_CLASS(A2o_Mapper);

PHP_METHOD(A2o_Mapper, map);

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_a2o_mapper_map, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_a2o_mapper_map, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_a2o_mapper_map, 0, 0, 2)
#define arginfo_a2o_mapper_map NULL
#endif

	ZEND_ARG_ARRAY_INFO(0, source, 0)
	ZEND_ARG_INFO(0, reciever)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(a2o_mapper_method_entry) {
	PHP_ME(A2o_Mapper, map, arginfo_a2o_mapper_map, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
