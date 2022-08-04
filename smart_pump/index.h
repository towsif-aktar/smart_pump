char mainpage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<meta charset="UTF-8">
<title>Smart Pump</title>
<meta name="viewport" content="width=device-width,initial-scale=1">

<head>
<style>


body{
  margin: 0;
  padding: 0;
background: rgb(2,0,36);
background: linear-gradient(180deg, rgba(2,0,36,1) 0%, rgba(9,9,121,1) 20%, rgba(0,212,255,1) 100%);
background-repeat: no-repeat;
/* background-size: cover; */
background-attachment: fixed;
}



ul {
  list-style-type: none;
  display: inline;
}
li{
  display: inline;
  margin: 20px;
  justify-content: center;
  
}

a {
  text-decoration: none;
  color: white;
}

a:hover {
  color: black;
  text-decoration: none;
  cursor: pointer;
}

.button {
  border: none;
  color: white;
  padding: 16px 32px;
  text-align: center;
  text-decoration: none;
  font-size: 16px;
  margin: 4px 2px;
  transition-duration: 0.4s;
  cursor: pointer;
  margin-left: 50px;
}

.button1 {
  background-color: #4CAF50;
  color: white;
  border: 2px solid black;
  /* display: inline; */
}

.button1:hover {
  background-color:white;
  color: black;
}

.button2 {
  background-color: #ba0000;
  color: white;
  border: 2px solid black;
}

.button2:hover {
  background-color: white;
  color: black;
}



.navbar{
  background-color: orangered;
}
marquee{
      font-size: 20px;
      font-weight: 300;
      color: white;
      font-family: sans-serif;
      }

.btn{
  display: inline-flex;
  /* background-color: white; */
  width: 100%;
  margin-top: 200px;
  justify-content: center;
}

.footer {
   position: fixed;
   left: 0;
   bottom: 0;
   width: 100%;
   background-color: orangered;
   color: white;
   text-align: center;
}

.foot{
color: black;
}
 .foot:hover{
  color:rgb(255, 255, 255);
 }

</style>
</head><center>
<body>
  <div>
    <marquee>Automatic and Smart Water Pump</marquee>
  </div>
  
  <div class="navbar">
  <ul>
    <li><a href="/">Home</a></li>
    <li><a href="/config">WiFi Settings</a></li>
    <li><a href="/contact">Contact</a></li>
    <li><a href="/about">About</a></li>
  </ul></div>
    <div class="btn">
        <button class="button button1" onclick="window.location.href='/on';">Turn  On</button>
        <button class="button button2" onclick="window.location.href='/off';">Turn Off</button>
    
    </div>
  

    <div class="footer">
      <p>Copyright © 2022,<a style= "color: green" class="foot" href="https://github.com/towsif-aktar">TOWSIF AKTAR</a> All Rights Reserved </p>
    </div>
</body></center>
</html>

)=====";
