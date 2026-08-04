#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

const char* ssid = "ESP32_Control";
const char* password = "12345678";

WebServer server(80);

Servo servo;

const int servoPin = 18;
const int greenLED = 26;
const int redLED = 27;

String webpage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>ESP32 Servo Control</title>

<style>
body{
font-family:Arial;
text-align:center;
margin-top:80px;
background:#f2f2f2;
}

button{
width:180px;
height:60px;
font-size:24px;
margin:20px;
border:none;
border-radius:10px;
cursor:pointer;
}

.open{
background:green;
color:white;
}

.close{
background:red;
color:white;
}
</style>

</head>

<body>

<h1>Servo Controller</h1>

<a href="/open">
<button class="open">Open</button>
</a>

<a href="/close">
<button class="close">Close</button>
</a>

</body>
</html>
)rawliteral";

void handleRoot() {
  server.send(200, "text/html", webpage);
}

void handleOpen() {

  servo.write(90);

  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);

  server.sendHeader("Location","/");
  server.send(303);
}

void handleClose() {

  servo.write(0);

  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);

  server.sendHeader("Location","/");
  server.send(303);
}

void setup() {

  Serial.begin(115200);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  servo.attach(servoPin);

  servo.write(0);

  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);

  WiFi.softAP(ssid, password);

  Serial.println();
  Serial.println("Access Point Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);
  server.on("/open", handleOpen);
  server.on("/close", handleClose);

  server.begin();
}

void loop() {
  server.handleClient();
}