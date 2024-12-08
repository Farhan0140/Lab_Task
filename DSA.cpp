IPOST

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

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Movie Collection</title>
</head>
<body>
    <script>
        const movieCollection={
            title: ["Oppenheimer","Taken","The Dark Knight","Interstellar","Wanted"],
            director: ["Christopher Nolan","Pierre Morel","Christopher Nolan","Christopher Nolan","Timur Bekmambetov"],
            year: [2023,2008,2008,2014,2008],
            rating: [8.3,7.7,9,8.7,6.7],
            
            addMovie(title, director, year, rating){
                this.title.push(title);
                this.director.push(director);
                this.year.push(year);
                this.rating.push(rating);
            },
            removeMovie(){
                this.title.pop();
                this.director.pop();
                this.year.pop();
                this.rating.pop();
            },
            search_by_director(director){
                let index=[];
                for(let i=0;i<this.director.length;i++){
                    if(this.director[i]==director){
                        index.push(i);
                    }
                }
                if(index.length!=0){
                    document.write("The Movies of ",director," is/are,<br>");
                    for(let i=0;i<index.length;i++){
                        document.write(this.title[index[i]],"<br>");
                    }
                    document.write("<br>");
                }
                else{
                    document.write("There is no movie of ",director," in our collection.<br>")
                }
            },
            search_by_year(year){
                let index=[];
                for(let i=0;i<this.year.length;i++){
                    if(this.year[i]==year){
                        index.push(i);
                    }
                }
                if(index.length!=0){
                    document.write("The Movies from ",year," is/are,<br>");
                    for(let i=0;i<index.length;i++){
                        document.write(this.title[index[i]],"<br>");
                    }
                    document.write("<br>");
                }
                else{
                    document.write("There is no movie from ",year," in our collection.<br>")
                }
            }
        }
        

        movieCollection.addMovie("The Happining", "M. Night Shyamalan", "2008", "5");
        movieCollection.search_by_director("Christopher Nolan");
        movieCollection.search_by_year(2008);
        movieCollection.search_by_director("M. Night Shyamalan");
        movieCollection.removeMovie();
        movieCollection.search_by_year(2008);
        movieCollection.search_by_director("M. Night Shyamalan");
        movieCollection.search_by_year(2009);
    </script>
</body>
</html>

//--------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------

