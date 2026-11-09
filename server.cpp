// KNOWBRIDGE AI - Native C++ HTTP Web Server & Governance Engine
// Tech Stack: C++ (Backend) + HTML5 + CSS3 + JavaScript (Frontend)
// Compliant with CodersInPune Hackathon Round 2 Specifications

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8080
#define BUFFER_SIZE 65536

std::string readFileContents(const std::string& filepath) {
    std::ifstream file(filepath.c_str(), std::ios::in | std::ios::binary);
    if (!file.is_open()) {
        return "";
    }
    std::ostringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

std::string buildHttpResponse(const std::string& contentType, const std::string& body, int statusCode = 200) {
    std::ostringstream response;
    std::string statusText = (statusCode == 200) ? "OK" : (statusCode == 404 ? "Not Found" : "Internal Server Error");
    
    response << "HTTP/1.1 " << statusCode << " " << statusText << "\r\n";
    response << "Content-Type: " << contentType << "; charset=utf-8\r\n";
    response << "Content-Length: " << body.size() << "\r\n";
    response << "Access-Control-Allow-Origin: *\r\n";
    response << "Access-Control-Allow-Methods: GET, POST, OPTIONS\r\n";
    response << "Access-Control-Allow-Headers: Content-Type\r\n";
    response << "Connection: close\r\n";
    response << "\r\n";
    response << body;
    
    return response.str();
}

std::string handleApiHealth() {
    return "{\n"
           "  \"status\": \"online\",\n"
           "  \"server\": \"KNOWBRIDGE Native C++ Server v2.0\",\n"
           "  \"tech_stack\": [\"C++\", \"HTML5\", \"CSS3\", \"JavaScript\"],\n"
           "  \"team\": \"TECHY'VENGERS\",\n"
           "  \"leader\": \"Kamal Lochan Mishra\",\n"
           "  \"hackathon\": \"CodersInPune Round 2\"\n"
           "}";
}

std::string handleApiRules() {
    return "[\n"
           "  {\"id\": \"R-01\", \"title\": \"ADR-001: Hazelcast Distributed IMDG Locking\", \"category\": \"Architecture ADR\", \"mandate\": \"Strict CP mode required. Standalone Redis prohibited.\", \"source\": \"architecture_decisions.md#L8-15\"},\n"
           "  {\"id\": \"R-02\", \"title\": \"SEC-002: KMS Root Credential Shadow Ceremony\", \"category\": \"Security & Compliance\", \"mandate\": \"Single custodian prohibited on Tier-0 modules.\", \"source\": \"team_handover_notes.txt#L10-14\"},\n"
           "  {\"id\": \"R-03\", \"title\": \"ADR-002: Mandatory Idempotency Keys on /v2/charge\", \"category\": \"Architecture ADR\", \"mandate\": \"UUIDv4 key with 24h memory TTL required.\", \"source\": \"architecture_decisions.md#L20-27\"},\n"
           "  {\"id\": \"R-04\", \"title\": \"OPS-004: Fragile Memory Leak Workaround Disclosure\", \"category\": \"Operational SLA\", \"mandate\": \"Pod restart cronjob must be patched in Netty bytebuf.\", \"source\": \"team_handover_notes.txt#L18-20\"},\n"
           "  {\"id\": \"R-05\", \"title\": \"BRD-005: Verified Public Availability SLA\", \"category\": \"Brand & Marketing\", \"mandate\": \"Core ledger SLA is 99.99%. Over-promising 100.00% is prohibited.\", \"source\": \"service_dependencies.json#L18\"}\n"
           "]";
}

int main() {
    std::cout << "========================================================\n";
    std::cout << "  KNOWBRIDGE AI - Native C++ Web Server\n";
    std::cout << "  Team: TECHY'VENGERS | Leader: Kamal Lochan Mishra\n";
    std::cout << "  Stack: Pure C++ + HTML5 + CSS3 + JavaScript\n";
    std::cout << "========================================================\n";

    WSADATA wsaData;
    int wsaInit = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (wsaInit != 0) {
        std::cerr << "WSAStartup failed with error: " << wsaInit << "\n";
        return 1;
    }

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Socket creation failed: " << WSAGetLastError() << "\n";
        WSACleanup();
        return 1;
    }

    int opt = 1;
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, (const char*)&opt, sizeof(opt));

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Bind failed with error: " << WSAGetLastError() << "\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Listen failed with error: " << WSAGetLastError() << "\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "[C++ SERVER] Listening on http://localhost:" << PORT << "\n";
    std::cout << "[C++ SERVER] Ready for CodersInPune Hackathon evaluation!\n";

    while (true) {
        SOCKET clientSocket = accept(serverSocket, NULL, NULL);
        if (clientSocket == INVALID_SOCKET) {
            continue;
        }

        char buffer[BUFFER_SIZE];
        int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE - 1, 0);
        if (bytesReceived > 0) {
            buffer[bytesReceived] = '\0';
            std::string request(buffer);

            // Parse request method and path
            std::istringstream reqStream(request);
            std::string method, path;
            reqStream >> method >> path;

            std::string response;

            if (method == "OPTIONS") {
                response = buildHttpResponse("text/plain", "OK", 200);
            } else if (path == "/" || path == "/index.html") {
                std::string html = readFileContents("index.html");
                if (html.empty()) {
                    html = readFileContents("C:\\Users\\Kamal Lochan Mishra\\.gemini\\antigravity\\scratch\\knowbridge-ai\\index.html");
                }
                if (!html.empty()) {
                    response = buildHttpResponse("text/html", html, 200);
                } else {
                    response = buildHttpResponse("text/plain", "Error: index.html not found", 404);
                }
            } else if (path == "/api/health") {
                response = buildHttpResponse("application/json", handleApiHealth(), 200);
            } else if (path == "/api/rules") {
                response = buildHttpResponse("application/json", handleApiRules(), 200);
            } else {
                response = buildHttpResponse("text/plain", "404 Not Found", 404);
            }

            send(clientSocket, response.c_str(), (int)response.size(), 0);
        }
        closesocket(clientSocket);
    }

    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
