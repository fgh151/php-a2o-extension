namespace A2o;


class Mapper
{

    /**
     * @param source array of source [name => value]
     * @param reciever object that recieve props from source
     */
    public static function map(array source, object reciever) -> void
    {
        var recieverProps, recieverPropNames, currentProp, currentRecieverProp, currentValue, reflection;
        int i = 0, length;

        let recieverProps = get_object_vars(reciever);
        let recieverPropNames = array_keys(recieverProps);
        let length = count(recieverProps) - 1;

        for i in range(0, length) {
            let currentProp = recieverPropNames[i];
            let currentValue = source[currentProp];
            let reflection = new \ReflectionClass(reciever);
            let currentRecieverProp = reflection->getProperty(currentProp);
            currentRecieverProp->setValue(reciever, currentValue);
        }
    }
}
