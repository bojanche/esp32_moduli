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
    ul {text-align: left;}
  </style>
</head>
<body>
  <h2>Sensor Object</h2><h3>* WiFi Config *</h3>
  <ul>
  %WIFILIST%
  </ul>
<script>
</script>
</body>
</html>
)rawliteral";
