<?php


function isNumberArmstrong(int $input): bool
{
    $arr = array_map('intval', str_split($input));
    $sumOfCubes = 0;
    foreach ($arr as $num) {
        $sumOfCubes += $num * $num * $num;
    }
    if ($sumOfCubes == $input) {
        return true;
    } else {
        return false;
    }
}

function fibonacciRecursive(int $num)
{
    $fibonacciRecursive = [];
    for ($i = 0; $i < $num; $i++) {
        array_push($fibonacciRecursive, recursive($i));
    }
    return $fibonacciRecursive;
}

function recursive(int $num)
{
    if ($num < 0) {
        throw new \Exception("Number must be greater than 0.");
    } else {
        if ($num == 0 || $num == 1) {
            return $num;
        } else {
            return recursive($num - 1) + recursive($num - 2);
        }
    }
}

function fibonacciWithBinetFormula(int $num)
{
    $fib_series = [];

    if ($num < 0) {
        throw new \Exception("Number must be greater than 0.");
    } else {
        $sqrt = sqrt(5);
        $phi_1 = (1 + $sqrt) / 2;
        $phi_2 = (1 - $sqrt) / 2;

        foreach (range(0, $num - 1) as $n) {
            $seriesNumber = (pow($phi_1, $n) - pow($phi_2, $n)) / $sqrt;
            array_push($fib_series, (int)$seriesNumber);
        }
    }

    return $fib_series;
}

function isNumberNeon($input)
{
    $inputSquare = $input * $input;
    $inputArr = array_map('intval', str_split($inputSquare));
    $sumOfSquareDigits = 0;
    foreach ($inputArr as $digit) {
        $sumOfSquareDigits += $digit;
    }

    return $sumOfSquareDigits == $input;
}

function findDistance($str1, $str2)
{
    $lenStr1 = strlen($str1);
    $lenStr2 = strlen($str2);
    if ($lenStr1 == 0) {
        return $lenStr2;
    }

    if ($lenStr2 == 0) {
        return $lenStr1;
    }

    $distanceVectorInit = [];
    $distanceVectorFinal = [];

    for ($i = 0; $i < $lenStr1 + 1; $i++) {
        $distanceVectorInit[] = 0;
        $distanceVectorFinal[] = 0;
    }

    for ($i = 0; $i < $lenStr1 + 1; $i++) {
        $distanceVectorInit[$i] = $i;
    }

    for ($i = 0; $i < $lenStr2; $i++) {
        $distanceVectorFinal[0] = $i + 1;

        for ($j = 0; $j < $lenStr1; $j++) {
            $substitutionCost = 0;
            if ($str1[$j] == $str2[$i]) {
                $substitutionCost = $distanceVectorInit[$j];
            } else {
                $substitutionCost = $distanceVectorInit[$j] + 1;
            }

            $distanceVectorFinal[$j + 1] = min($distanceVectorInit[$j + 1] + 1, min($distanceVectorFinal[$j] + 1, $substitutionCost));
        }

        $distanceVectorInit = $distanceVectorFinal;
    }


    return $distanceVectorFinal[$lenStr1];
}

function countVowelsSimple(string $string): int
{
    if (empty($string)) {
        throw new \Exception('Please pass a non-empty string value.');
    }

    $numberOfVowels = 0;
    $vowels = ['a', 'e', 'i', 'o', 'u']; 

    $string = strtolower($string);

    $characters = str_split($string);

    foreach ($characters as $character) {
        if (in_array($character, $vowels)) {
            $numberOfVowels++;
        }
    }

    return $numberOfVowels;
}

function countVowelsRegex(string $string)
{
    if (empty($string)) {
        throw new \Exception('Please pass a non-empty string value');
    }

    $string = strtolower($string); 

    return preg_match_all('/[a,e,i,o,u]/', $string);
}

function quickSort(array $input)
{
    if (empty($input)) {
        return [];
    }

    $lt = [];
    $gt = [];
    if (sizeof($input) < 2) {
        return $input;
    }

    $key = key($input);
    $shift = array_shift($input);
    foreach ($input as $value) {
        $value <= $shift ? $lt[] = $value : $gt[] = $value;
    }

    return array_merge(quickSort($lt), [$key => $shift], quickSort($gt));
}

function selectionSort(array $array)
{
    $length = count($array);

    for ($i = 0; $i < $length; $i++) {
        $lowest = $i;

        for ($j = $i + 1; $j < $length; $j++) {
            if ($array[$j] < $array[$lowest]) {
                $lowest = $j;
            }
        }

        if ($i !== $lowest) {
            $temp = $array[$i];
            $array[$i] = $array[$lowest];
            $array[$lowest] = $temp;
        }
    }

    return $array;
}

function heapSort(array $arr): array
{
    $n = count($arr);

    if ($n <= 0) {
        throw new \UnexpectedValueException('Input array must have at least one element.');
    }

    for ($i = floor($n / 2) - 1; $i >= 0; $i--) {
        heapify($arr, $n, $i);
    }

    for ($i = $n - 1; $i >= 0; $i--) {
        [$arr[0], $arr[$i]] = [$arr[$i], $arr[0]];

        heapify($arr, $i, 0);
    }

    return $arr;
}

function heapify(array &$arr, int $n, int $i): void
{
    $largest = $i;
    $left = 2 * $i + 1;
    $right = 2 * $i + 2;
    if ($left < $n && $arr[$left] > $arr[$largest]) {
        $largest = $left;
    }

    if ($right < $n && $arr[$right] > $arr[$largest]) {
        $largest = $right;
    }

    if ($largest !== $i) {
        [$arr[$i], $arr[$largest]] = [$arr[$largest], $arr[$i]];
        heapify($arr, $n, $largest);
    }
}

class ArrayKeysSort
{
    public const ORDER_ASC = 'ASC';
    public const ORDER_DESC = 'DESC';

    public static function sort($collection, array $keys, string $order = self::ORDER_ASC, bool $isCaseSensitive = false)
    {
        if (!empty($collection) && !empty($keys)) {
            try {
                usort($collection, function ($a, $b) use ($keys, $order, $isCaseSensitive) {

                        $pos = 0;
                    do {
                            $key = $keys[$pos];
                        if (is_array($a)) {
                            if (!isset($a[$key]) || !isset($b[$key])) {
                                $errorMsg = 'The key "' . $key
                                        . '" does not exist in the collection';
                                throw new Exception($errorMsg);
                            }
                            $item1 = !$isCaseSensitive
                            ? strtolower($a[$key]) : $a[$key];
                            $item2 = !$isCaseSensitive
                            ? strtolower($b[$key]) : $b[$key];
                        } else {
                            if (!isset($a->$key) || !isset($b->$key)) {
                                $errorMsg = 'The key "' . $key
                                        . '" does not exist in the collection';
                                throw new Exception($errorMsg);
                            }
                            $item1 = !$isCaseSensitive
                            ? strtolower($a->$key) : $a->$key;
                            $item2 = !$isCaseSensitive
                            ? strtolower($b->$key) : $b->$key;
                        }
                    } while ($item1 === $item2 && !empty($keys[++$pos]));
                    if ($item1 === $item2) {
                        return 0;
                    } elseif ($order === self::ORDER_ASC) {
                        return ($item1 < $item2) ? -1 : 1;
                    } else {
                        return ($item1 > $item2) ? -1 : 1;
                    }
                });
            } catch (Exception $e) {
                echo $e->getMessage();
                die();
            }
        }

        return $collection;
    }
}