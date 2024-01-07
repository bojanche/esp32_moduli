const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>Sensor Object</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,">
  <style>
    html {font-family: Arial; display: inline-block; text-align: center;}
    h2 {font-size: 3.0rem;}
    p {font-size: 3.0rem;}
    body {max-width: 600px; margin:0px auto; padding-bottom: 25px;}
    table {
      font-family: arial, sans-serif;
      border-collapse: collapse;
      width: 100%%;
      }
td, th {
  border: 0px;
  text-align: left;
  padding: 8px;
}

tr:nth-child(even) {
  background-color: #dddddd;
}
  </style>
</head>
<body>
  <h2>Sensor Object</h2><h3>* WiFi Config *</h3>
  <table>
    <tr>
      <th>SSID</th>
      <th>RSSI</th>
      <th>Connect</th>
    </tr>
  %WIFILIST%
</table>
<script>
function enterPass() {
  let text;
  let person = prompt("Please enter WiFi pass:", "Harry Potter");
  if (person == null || person == "") {
    text = "User cancelled the prompt.";
  } else {
    text = "Hello " + person + "! How are you today?";
  }
  document.getElementById("demo").innerHTML = text;
}
</script>
</body>
</html>
)rawliteral";
