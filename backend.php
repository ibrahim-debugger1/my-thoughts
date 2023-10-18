<?php
session_start();
require 'db_connection';

$name=mysqli_real_escape_string($pdo,trim($_POST['name']));
echo $name;die;
$email_domain = preg_replace('/^[a-zA-Z0-9][a-zA-Z0-9\_\-&!?=#]*@/','',$_POST['email']);

if(!checkdnsrr($email_domain)){
    $message= 'Your email address is invalid. <br>';
    $_SESSION['wrong_email']=$message;
    header("Location: indexx.php");
}
echo 'hi';die;
$sql = "SELECT * FROM contact_forms";

$stmt = $pdo->prepare($sql);

$stmt->execute();

$results = $stmt->fetchAll(PDO::FETCH_ASSOC);

foreach ($results as $row) {
    echo "User ID: " . $row['id'] . "<br>";
    echo "Username: " . $row['Full_Name'] . "<br>";
    echo "Email: " . $row['Email'] . "<br><br>";
    echo "Message: " . $row['Message'] . "<br><br>";
}
?>

