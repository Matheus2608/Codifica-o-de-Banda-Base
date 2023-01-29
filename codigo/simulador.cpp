#include "CamadaFisica.cpp"
#include "crow.h"

int main() {
    AplicacaoTransmissora();
    crow::SimpleApp app;
    CROW_ROUTE(app, "/")([](){
        return "Hello world";
    });
    app.port(18080).multithreaded().run();
}
