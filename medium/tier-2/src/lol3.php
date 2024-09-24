<?php
$is_post = $_SERVER["REQUEST_METHOD"] === "POST";

if ($is_post === true) {
    $userInput = $_POST["userInput"];
    $output = system("echo " . $userInput, $returnValue);
}
?>
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>User Input Echo</title>
    </head>
    <body>
        <h2>Enter Text:</h2>
        <form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
            <label for="userInput">User Input:</label>
            <input type="text" name="userInput" id="userInput" required>
            <button type="submit">Submit</button>
        </form>
<?php if ($is_post === true) { ?>
        <h2>Output:</h2>
        <code><?= $output ?></code>
        <p>Return Value: <?= $returnValue ?></p>
<?php } ?>
    </body>
</html>
