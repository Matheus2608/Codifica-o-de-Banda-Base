#include <string>
#include <iostream>
#include "CamadaFisica.cpp"
#include "crow.h"
#include "crow/middlewares/cors.h"

int main() {
    AplicacaoTransmissora();
    crow::App<crow::CORSHandler> app;

    auto& cors = app.get_middleware<crow::CORSHandler>();

    cors.global().origin("*");

    CROW_ROUTE(app, "/<int>").methods("POST"_method)([](const crow::request& req, crow::response& res, int id) {
        cout<< req.body.data() << endl;
        res.write("oi"+std::to_string(id));
        res.end();
    });

    app.port(18080).multithreaded().run();
}
