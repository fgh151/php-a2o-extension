# Array to object php extension

## Dependencies

[Zephir](https://zephir-lang.com/)

## Compile

```shell script
./build.sh
```

## Usage example

```php
class User
{
    public $name;
}

$user = new User();
$source = [
    'name' => 'Fedor'
];

A2o\Mapper::map($source, $user);

var_dump($user);

// object(User)#1 (1) {
//  ["name"]=>
//  string(5) "Fedor"
// }

```
