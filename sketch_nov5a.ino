
/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/
// Load Wi-Fi library
#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "ahihi"; // tên wifi
const char* password = "12345679"; // password của wifi

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output25State = "off";
String output27State = "off";
String output23State = "off";
String output26State = "off";

// Assign output variables to GPIO pins
const int output25 = 25;
const int output27 = 27;
const int output23 = 23;
const int output26 = 26;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  
  // Initialize the output variables as outputs
  pinMode(output25, OUTPUT);
  pinMode(output27, OUTPUT);
  pinMode(output23, OUTPUT);
  pinMode(output26, OUTPUT);
  
  // Set outputs to LOW
  digitalWrite(output25, LOW);
  digitalWrite(output27, LOW);
  digitalWrite(output23, LOW);
  digitalWrite(output26, LOW);
  
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients
  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /25/on") >= 0) {
              Serial.println("GPIO 25 on");
              output25State = "on";
              digitalWrite(output25, HIGH);
              delay(250); // Wait for 500 milliseconds
              Serial.println("GPIO 25 off");
              output25State = "off";
              digitalWrite(output25, LOW);
            } 
            
            if (header.indexOf("GET /27/on") >= 0) {
              Serial.println("GPIO 27 on");
              output27State = "on";
              digitalWrite(output27, HIGH);
              delay(250); // Wait for 500 milliseconds
              Serial.println("GPIO 27 off");
              output27State = "off";
              digitalWrite(output27, LOW);
            }

            if (header.indexOf("GET /23/on") >= 0) {
              Serial.println("GPIO 23 on");
              output23State = "on";
              digitalWrite(output23, HIGH);
              delay(250); // Wait for 500 milliseconds
              Serial.println("GPIO 23 off");
              output23State = "off";
              digitalWrite(output23, LOW);
            }
            
            if (header.indexOf("GET /26/on") >= 0) {
              Serial.println("GPIO 26 on");
              output26State = "on";
              digitalWrite(output26, HIGH);
              delay(250); // Wait for 500 milliseconds
              Serial.println("GPIO 26 off");
              output26State = "off";
              digitalWrite(output26, LOW);
            }
            
            // Display the HTML web page
                // Display the HTML web page
                client.println("<!DOCTYPE html><html lang=\"en\">");
                client.println("<head><meta charset=\"UTF-8\">");
                client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
                client.println("<title>Traffic remote Animation</title>");
                client.println("<link rel=\"stylesheet\" href=\"./bootstrap/dist/css/bootstrap.css\">");
                client.println("<style>");
                client.println("body { display: flex; justify-content: center; align-items: center; flex-direction: column; width: 100%; height: 100vh; margin: 0;background-image: url(https://img.freepik.com/free-vector/circles-background-dark-tones_60389-166.jpg?semt=ais_hybrid);background-size: 100%;background-repeat:no-repeat; }");
                client.println(".header { width: 100%; height: 100vh; }");
                client.println(".inner-container { position: relative; width: 1200px; height: 100000px; display: flex; align-items: center; justify-content: space-around; background-image: url('image/traffic.png'); background-size: cover; background-position: center; }");
                client.println(".traffic-signal { width: 100px; height: 300px; background-color: #333; border-radius: 10px; display: flex; flex-direction: column; justify-content: space-between; align-items: center; }");
                client.println(".light { width: 60px; height: 60px; border-radius: 50%; margin: 10px; transition: background-color 0.9s; }");
                client.println(".red { background-color: red; }");
                client.println(".yellow { background-color: yellow; animation: blinkYellow 9s infinite; animation-delay: 3s; }");
                client.println(".green { background-color: green; animation: blinkGreen 9s infinite; animation-delay: 6s; }");
                client.println(".button-container { margin-top: 20px; display: flex; justify-content: center; flex-wrap: wrap; }");
                client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px; text-decoration: none; font-size: 30px; margin: 5px; border-radius: 5px; transition: background-color 0.3s, transform 0.3s; }");
                client.println(".button:hover { background-color: #45a049; transform: translateY(-2px); }");
                client.println(".button:active { transform: translateY(0); background-color: #003d7a; }");
                client.println(".button2 { background-color: #555555; }");
                client.println(".traffic-light-title { color: #f5f5f5; text-align: center; }");
                client.println("</style></head>");
                client.println("<body>");
                client.println("<h1 class=\"traffic-light-title\">TRAFFIC LIGHT SYSTEM WITH REMOTE CONTROL</h1>");
                client.println("<div class=\"header\"></div>");
                client.println("<div class=\"inner-container\">");
                client.println("<div class=\"traffic-signal\"><div class=\"light red\" id=\"red-light-1\"></div><div class=\"light yellow\"></div><div class=\"light green\"></div></div>");
                client.println("<div class=\"traffic-signal\"><div class=\"light red\"></div><div class=\"light yellow\"></div><div class=\"light green\"></div></div>");
                client.println("<div class=\"traffic-signal\"><div class=\"light red\"></div><div class=\"light yellow\"></div><div class=\"light green\"></div></div>");
                client.println("<div class=\"traffic-signal\"><div class=\"light red\"></div><div class=\"light yellow\"></div><div class=\"light green\"></div></div>");
                client.println("</div>");
                client.println("<div class=\"button-container\">");

                if (output25State == "off") {
                    client.println("<p><a href=\"/25/on\"><button class=\"button\">MODE</button></a></p>");
                }

                if (output27State == "off") {
                    client.println("<p><a href=\"/27/on\"><button class=\"button\">MAN1/CHANGE</button></a></p>");
                }

                if (output23State == "off") {
                    client.println("<p><a href=\"/23/on\"><button class=\"button\">MAN2/INC</button></a></p>");
                }

                if (output26State == "off") {
                    client.println("<p><a href=\"/26/on\"><button class=\"button\">DEC</button></a></p>");
                }

                client.println("</div>");
                client.println("<script src=\"bootstrap/js/bootstrap.min.js\"></script>");
                client.println("<script>");
                client.println("const button1 = document.getElementById('button-1');");
                client.println("const redLight1 = document.getElementById('red-light-1');");
                client.println("let blinkingInterval;");
                client.println("button1.addEventListener('click', () => {");
                client.println("    clearInterval(blinkingInterval);");
                client.println("    blinkingInterval = setInterval(() => {");
                client.println("        if (redLight1.style.backgroundColor === 'red') {");
                client.println("            redLight1.style.backgroundColor = 'black';");
                client.println("        } else {");
                client.println("            redLight1.style.backgroundColor = 'red';");
                client.println("        }");
                client.println("    }, 1000);");
                client.println("});");
                client.println("</script>");
                client.println("</body></html>");
                client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    header = "";
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
