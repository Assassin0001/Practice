<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>More Basics</title>
</head>
<style>
*{
    margin: 0;
    padding: 0;
    box-sizing: border-box;
}

.container{
    max-width: 80%;
    background-color: grey;
    margin: auto;
    padding: 20px;
}
</style>
<body>
    <div class ="container">
       <h1> Lets learn more about PHP: </h1>
       <p>Your party status is here.</p>
       <?php

        //If-Else
         $age =34;
         if($age >=18){
            echo "You can go to the party";
         }
         else{
            echo "You can't go to the party"; 
         }
         if($age == 18){
            echo "You are 18 years old";
         }
         echo "<br>";

         //Arrays in PHP
         $languages =array("Python","C++","php","NodeJS");
         echo $languages[0];
         echo"<br>"; 
         echo count($languages); 

         //Loops
         $a=0;
         while($a <=10){
            echo "<br> The value of a is: ";
            echo $a;
            $a++;
         }

         //Iterating arrays in PHP Using while loop
         $c= 0;
         while($c <count($languages)){
            echo "<br> The element is: ";
            echo $languages[$c];
            $c++;
         }

         //Iterating arrays in PHP Using do while loop
         $c= 0;
         do{
            echo "<br> The element in Languages array print using while loop: ";
            echo $languages[$c];
            $c++;
         }
         while($c < count($languages));

         // For loops
         for ($i=0; $i < 10;$i++) { 
            echo "<br>The value of i from for loop is ";
            echo $i;
         }

         //For each loop
         foreach ($languages as $value) {
            echo "<br>The Value from foreach loop is: ";
            echo $value;
         }
         
         //Function
         function print5(){
            echo "<br> FIVE";
         }
         print5();

         function print_num($number){
            echo "<br> Your number is ".$number;
         }
         print_num(21);

      ?>
</div>
</body>
</html>