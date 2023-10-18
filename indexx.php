<?php session_start();?>
<!DOCTYPE html>
<html>
<head>
    <title>Contact Form</title>
</head>
<body>
    <h1>Contact Us</h1>
        <h1><?php 
            if(isset($_SESSION['wrong_email']) && !empty($_SESSION['wrong_email'])) 
                echo $_SESSION['wrong_email'] . '<br>';
            $_SESSION['wrong_email']="";
    ?></h1>
    <form action="backend.php" method="post">
        <label for="name">Name:</label>
        <input type="text" id="name" name="name" required><br><br>

        <label for="email">Email:</label>
        <input type="email" id="email" name="email" required><br><br>

        <label for="message">Message:</label><br>
        <textarea id="message" name="message" rows="4" cols="50" required></textarea><br>

        <label for="verify">Verification:</label><br>
        <input type="text" id="verify" name="verify" placeholder="Enter the pass-phrase" required>
        <img src="captcha.php" alt="Verification pass-phrase" /><br><br>

        <input type="submit" value="Submit">
    </form>
</body>
</html>