<?php 
    session_start();

    $pass_phrase= "";
    for($i=0;$i<6;$i++){
        $pass_phrase .= chr(rand(97,122));
    }

    $_SESSION['pass_phrase']=$pass_phrase;
    $img = imagecreatetruecolor(100,25);

    $bg_color= imagecolorallocate($img,255,255,255); //white
    $text_color=imagecolorallocate($img,0,0,0); //black
    $graphic_color= imagecolorallocate($img,64,64,64); // dark gray

    imagefilledrectangle($img,0,0,100,25,$bg_color);

    for($i=0;$i<5;$i++){
        imageline($img,0,rand()%25,100,rand()%25,$graphic_color);
    }
    for($i=0;$i<50;$i++){
        imagesetpixel($img,rand()%100,rand()%25,$graphic_color);
    }
    imagettftext($img,18,0,5,20,$text_color,"/usr/share/fonts/opentype/urw-base35/NimbusSans-Regular.otf",$pass_phrase);

    header("Content-type:image/png");
    imagepng($img);
    imagedestroy($img);
?>