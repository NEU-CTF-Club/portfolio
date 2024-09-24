<?php
function decrypt($encrypted, $password) {
    $data = base64_decode($encrypted);
    $decrypted = openssl_decrypt($data, 'AES-256-ECB', $password, OPENSSL_RAW_DATA);
    return $decrypted;
}

// Check if the User-Agent header is "NEU-CTFApp/1.0"
if ($_SERVER['HTTP_USER_AGENT'] !== "NEU-CTFApp/1.0") {
    header("HTTP/1.1 403 Forbidden");
    exit("we don't know you! get out!");
}

// Check the "X-Autograph" header
if (!isset($_SERVER['HTTP_X_AUTOGRAPH'])) {
    header("HTTP/1.1 400 Bad Request");
    exit("signature validation failed");
}

$autograph = decrypt($_SERVER['HTTP_X_AUTOGRAPH'], "fiNRXxvfWQRLIYvBNCz0b1HzFRcoqsi9");

$timestampParam = $_GET['timestamp'];

$timestampInt = $timestampParam + 0;

$milliseconds = floor(microtime(true) * 1000);

if ($autograph === $timestampParam) {
    // Enforce 4 seconds between the signature timestamp and the current time
    if ($milliseconds - $timestampInt <= 4000) {
        // Generate a random number between 0 and 500
        $randomNumber = rand(0, 500);

        // Check if the random number is 384
        if ($randomNumber === 384) {
            echo "CTF{und3r_the_se4_d00_d00_d00}";
        } else {
            echo "no <3";
        }
    } else {
        echo "you're too slow!";
    }
} else {
    echo "i need your autograph :P"; // Decrypted value doesn't match timestamp query parameter
}
?>