namespace A2o;


class Mapper
{

    /**
     * @param source array of source [name => value]
     * @param receiver object that recieve props from source
     */
    public static function map(array source, object receiver) -> void
    {
        var receiverProps, receiverPropNames, currentProp, currentreceiverProp, currentValue, reflection;
        int i = 0, length;

        let receiverProps = get_object_vars(receiver);
        let receiverPropNames = array_keys(receiverProps);
        let length = count(receiverProps) - 1;

        for i in range(0, length) {
            let currentProp = receiverPropNames[i];
            let currentValue = source[currentProp];
            let reflection = new \ReflectionClass(receiver);
            let currentreceiverProp = reflection->getProperty(currentProp);
            currentreceiverProp->setValue(receiver, currentValue);
        }
    }
}
