<?php
class User{
    public $name;
}
$user = new User();
$source = [
    'name' => 'Fedor'
];
A2o\Mapper::map($source, $user);

var_dump($user);
