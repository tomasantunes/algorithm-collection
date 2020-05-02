<h1>Wordpress to Text</h1>
<?php
  $user = 'user';
  $pass = 'pass';
  $db_name = 'db';
  $posts_table = 'posts';
  
try {
	$db_connection = new PDO('mysql:host=localhost;dbname='.$db_name.';charset=utf8', $user, $pass);
} catch (PDOException $e) {
    echo 'Connection failed: ' . $e->getMessage();
}

function getPosts($db_connection) {
	try{
		$stm_posts = $db_connection->prepare('SELECT post_title, post_content FROM ? WHERE post_status = ?');
	}
	catch(PDOException $e){
		echo 'Connection failed: ' . $e->getMessage();
	} 
	$stm_posts->execute(array($posts_table, 'publish'));
	return  $stm_posts->fetchAll();
}

$posts = getPosts($db_connection);

$has_posts = false;

foreach($posts as $post) {
	echo "<h2>" . $post['post_title'] . "</h2>";
        echo "<p>" . $post['post_content'] . "</p>";
        $has_posts = true;
}

if(!$has_posts) {
    echo "Posts not found";
}
?>
