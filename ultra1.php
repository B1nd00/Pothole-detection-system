<?php
class dht11{
 public $link='';
 function __construct($depth, $lat,$longi){
  $this->connect();
  $this->storeInDB($depth, $lat,$longi);
 }
 
 function connect(){
  $this->link = mysqli_connect('localhost','root','') or die('Cannot connect to the DB');
  mysqli_select_db($this->link,'ultrasensordata') or die('Cannot select the DB');
 }
 
 function storeInDB($depth, $lat,$longi){
  $query = "insert into data set depth='".$depth."', lat='".$lat."', longi='".$longi."'";
  $result = mysqli_query($this->link,$query) or die('Errant query:  '.$query);
 }
 
}
if($_GET['depth'] != '' and  $_GET['lat'] != '' and $_GET['longi'] != ''){
 $dht11=new dht11($_GET['depth'],$_GET['lat'],$_GET['longi']);
}


?>
