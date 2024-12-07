POST

<body>
    <form method="POST">
        <label for=""> Enter a Number </label>
        <input type="number" id="num" name="num" required> <br>
        <input type="submit" value="submit">
    </form>

    <?php
        $bl = false;

        if($_SERVER["REQUEST_METHOD"] == "POST") {
            $num = $_POST['num'];
            $bl = true;
        }

        if($bl) {
            for($i=1; $i <= $num; $i++) {
                if($i % 2 == 0) {
                    echo("$i <br>");
                }
            }
        }
    ?>
</body>



//--------------------------------------------------------------------------------------------------------

CREATE TABLE crud1 (
	id INT PRIMARY KEY AUTO_INCREMENT,
	name VARCHAR(100) NOT NULL,
	email VARCHAR(100) NOT NULL UNIQUE,
	phone VARCHAR(15) NOT NULL,
	join_date DATE NOT NULL
);
INSERT INTO crud1 (name, email, phone, join_date)
VALUES ('John Doe', 'johndoe@example.com', '1234567890', '2024-11-06');

INSERT INTO crud1 (name, email, phone, join_date)
VALUES ('Jane Smith', 'janesmith@example.com', '0987654321', '2024-11-06');

---------------->
<?php
$servername = "localhost";
$username = "root";
$password = "";
$db_name = "crud";

$conn = new mysqli($servername, $username, $password, $db_name); 
if($conn->connect_error){
	die("Connection failed".$conn->connect_error);
}
echo "Successful";
?>

//--------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------

