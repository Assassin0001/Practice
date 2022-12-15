<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>First PHP</title>
</head>

<body>
    <div>
        <p>This is my first PHP website.
          <?php
          // Constants
          define('PI' ,3.14);

          echo "Hello world and this is printed using php.";
          // Single line comment
          /* This
             is a multiline 
             comment
          */
         // Lorem, ipsum dolor.

        $variable1 = 34;
        $variable2 = 45;
        echo "The value of sum of Variable1 and Variable 2 is";
        echo $variable1 + $variable2;
        echo "<br>";
        echo "The value of diff of Variable1 and Variable 2 is";
        echo $variable1 - $variable2;
        echo "<br>";
        $newVar = $variable1;
        echo "The value of New variable is: ";
        echo $newVar;
        echo "<br>";
        echo "The increment operator increases te value by k: ";
        $newVar+=1;
        echo $newVar;

        echo "<h2> Comparison Operators :-</h2>";
        echo "The value of 1==2 is: ";
        echo var_dump(1==2);
        echo "<br>";
        echo "The value of 1!=2 is: ";
        echo var_dump(1!=2);
        echo "<br>";
        echo "The value of 1>=2 is: ";
        echo var_dump(1>=2);
        echo "<br>";
        echo "The value of 1<=2 is: ";
        echo var_dump(1<=2);
        echo "<br>";
        
        // Increment/Decrement Operator
        echo $variable1;
        echo "<br>";
        echo $variable1++;
        echo "<br>";
        echo $variable1;
        echo "<br>";
        echo --$variable1;
        echo "<br>";

        //Logical Operators
        echo $myVar = var_dump(true xor false);
        echo "<br>";
        echo $myVar = var_dump(false or false);
        echo "<br>";
        echo $myVar = var_dump(true and true);
        echo "<br>";
        
        // Data Types
            // 1.String
            // 2.Integer
            // 3.Float
            // 4.Boolean
            // 5.Object 
            echo "<br>";
            echo "Data types in PHP :-";
        $var ="This is a string.";
        echo "<br>";
        echo var_dump($var);
        $var =67;
        echo "<br>";
        echo var_dump($var);
        $var = true;
        echo "<br>";
        echo var_dump($var);
        echo "<br>";

        // Constants
        echo PI;
          ?>  
        </p>
</div>
    
</body>
</html>