<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Strings</title>
</head>
<body>
    <?php
    $str ="This is a string.";
    echo "<br>";
    echo $str;
    $str_len =strlen($str);
    echo "The length of this string is ".$str_len.".<br>Thank You!!.";
    echo "<br>";
    echo "The no of words in this string is ".str_word_count($str).".<br>Thank You!!.";
    echo "<br>";
    echo "The reversed string is ".strrev($str).".<br>Thank you!!";
    echo "<br>";
    echo "The position of word in the string is ".strpos($str,"is").".<br>Thank You!!.";
    echo "<br>";
    echo "The replaced string is ".str_replace("a","the",$str).".<br>Thank You!!.";
    
    ?>
</body>
</html>