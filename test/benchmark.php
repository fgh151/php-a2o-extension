<?php
require_once './vendor/autoload.php';
require  './vendor/yiisoft/yii2/Yii.php';

class User extends \yii\base\Model
{
    public $name;
    public $lastName;

    public function rules()
    {
        return [
            [['name', 'lastName'], 'required']
        ];
    }
}

const ITERATIONS = 10000;

function generateRandomString($length = 10) {
    $characters = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
    $charactersLength = strlen($characters);
    $randomString = '';
    for ($i = 0; $i < $length; $i++) {
        $randomString .= $characters[rand(0, $charactersLength - 1)];
    }
    return $randomString;
}

$testData = [];

for ($i = 0 ; $i <= ITERATIONS; $i++) {
    $testData[] = [
        'name' => generateRandomString(),
        'lastName' => generateRandomString()
    ];
}


$loopTest = [];

for ($i = 0; $i <= ITERATIONS; $i++) {
    $loopTest[] = new User();
}

$startMemory = memory_get_usage(true);
$startTime = time();
foreach ($loopTest as $i => $user) {
    $user->name =  $testData[$i]['name'];
    $user->lastName =  $testData[$i]['lastName'];
    $user->validate();
}
$endMemory = memory_get_usage(true);
$endTime = time();

echo 'Loop memory: ';
var_dump($endMemory - $startMemory);

$loopTest = [];

for ($i = 0; $i <= ITERATIONS; $i++) {
    $loopTest[] = new User();
}

$startMemory = memory_get_usage(true);
$startTime = time();
foreach ($loopTest as $i => $user) {
    A2o\Mapper::map($testData[$i], $user);
    $user->validate();
}
$endMemory = memory_get_usage(true);
$endTime = time();

echo 'A2o  memory: ';
var_dump($endMemory - $startMemory);
