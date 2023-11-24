#include <WiFi.h>
#include <HTTPClient.h>

const char *ssid = "NomeDaSuaRede"; // Nome da rede
const char *password = "SenhaDaSuaRede"; // Senha da rede
const char *tagoIoEndpoint = "http://api.tago.io/data";
const char *tagoIoToken = "1845a714-382c-47ed-8c65-004b464257bd";  // Substitua pelo seu token de API

void setup() {
  Serial.begin(115200);

  // Conectar à rede Wi-Fi (Conectando na rede do Wokwi)
  WiFi.begin("Wokwi-GUEST", "", 6); 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }

  Serial.println("Conectado ao WiFi!");
}

void loop() {
  // Simulação de leitura do sensor de batimentos cardíacos
  int heartRate = simularLeituraSensor();

  // Enviar os dados para o Tago.io
  enviarDadosTagoIo(heartRate);
}

int simularLeituraSensor() {
  // Simulação de leitura do sensor de batimentos cardíacos
  return random(60, 100);  // Gera um valor aleatório entre 60 e 100 para simular os batimentos cardíacos
}

void enviarDadosTagoIo(int heartRate) {
  if (WiFi.status() == WL_CONNECTED) {
    // Criar o corpo da requisição
    String jsonBody = "{\"variable\": \"heartRate\", \"value\": " + String(heartRate) + "}";

    HTTPClient http;

    // Configurar a requisição POST para o Tago.io
    http.begin(tagoIoEndpoint);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("Device-Token", tagoIoToken);  // Adicionar o token de API ao cabeçalho

    // Enviar a requisição POST
    int httpResponseCode = http.POST(jsonBody);

    if (httpResponseCode > 0) {
      Serial.print("Resposta do Tago.io: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.println("Erro na requisição HTTP para o Tago.io");
    }

    http.end();
  }
}