<?php
$insert =false;
if(isset($_POST['name'])){
  //Set connection variables
  $server= "localhost";
  $username= "root";
  $password= "root";

  //Create a database connection
  $con=mysqli_connect($server, $username, $password);

  //Connection Success
  if(!$con){
    die("Connection to this database failed due to".mysqli_connect_error());
  }
  $name= $_POST['name'];
  $gender= $_POST['gender'];
  $age= $_POST['age'];
  $email= $_POST['email'];
  $phone= $_POST['phone'];
  $other= $_POST['other'];

  $sql="INSERT INTO `trip`.`trip` (`name`, `age`, `gender`, `email`, `phone`, `other`, `date`) VALUES ('$name', '$age', '$gender', '$email', '$phone', '$other', CURRENT_TIMESTAMP());";
  //echo "$sql";

  //Execute the query
  if($con->query($sql) == true){
  //  echo "Successfully Inserted";
    $insert = true;
  //Flag for successful Insertion  
  }
  else{
    echo "ERROR: $sql <br> $con->error";
  }
  //Close the database connection
  $con->close();
}

 ?>

 <!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Welcome to Travel Form</title>
    <link rel="stylesheet" href="index.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Dancing+Script:wght@600&display=swap" rel="stylesheet"> 
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Noto+Sans:ital,wght@1,300&display=swap" rel="stylesheet">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Sriracha&display=swap" rel="stylesheet">   

</head>

<body>
    <img class="bg" src="bg1.jpg" alt="BIT-M">
    <div class="container">
        <h1>Welcome to BIT Mesra Goa Trip Form</h1>
        <p>Enter your details and submit this form to confrm your participation in the trip.</p>
        <?php
        if($insert == true){
          echo "<p class='submitMsg'>Thanx for submitting the form.We are happy to see you joining our trip.</p>";
        }
        ?>
        <form action="index.php" method="post">
          <input type="text" name="name" id="name" placeholder="Enter your name">
          <input type="text" name="age" id="age" placeholder="Enter your age">
          <input type="text" name="gender" id="gender" placeholder="Enter your gender">
          <input type="email" name="email" id="email" placeholder="Enter your email">
          <input type="phone" name="phone" id="phone" placeholder="Enter your phone">
          <textarea name="other" id= "other" cols= "30" rows= "10" placeholder= "Enter any other information here"></textarea>
          <button class="btn">Submit</button>

        </form>
    </div>
    <script src="index.js"></script>

</body>
</html>