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

    <?php
    // Check if the form is submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Get user input
        $userInput = $_POST["userInput"];

        // Use the system function to echo the user input
        $output = system("echo " . $userInput, $returnValue);

        // Display the output
        echo "<h2>Output:</h2>";
        echo "<pre>$output</pre>";
        echo "<p>Return Value: $returnValue</p>";
    }
    ?>

</body>
</html>

