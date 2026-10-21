#include <iostream>
#include "httplib.h"
#include "ParkingLot.h"

#include "ParkingLot.cpp"
#include "waitingqueue.cpp"
#include "VehicleManager.cpp"
#include "ParkingSlots.cpp"
#include "UndoStack.cpp"
#include "VehicleHashMap.cpp"

using namespace std;

int main() {
    ParkingLot parkingLot;
    httplib::Server svr;

    auto set_cors_headers = [](httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
        res.set_header("Access-Control-Allow-Headers", "Content-Type");
    };

    svr.Options(R"(/.*)", [&](const httplib::Request& req, httplib::Response& res) {
        set_cors_headers(res);
        res.status = 200;
    });

    svr.Get("/api/status", [&](const httplib::Request& req, httplib::Response& res) {
        set_cors_headers(res);
        string jsonStatus = parkingLot.getStatus();
        res.set_content(jsonStatus, "application/json");
    });

    svr.Post("/api/entry", [&](const httplib::Request& req, httplib::Response& res) {
        set_cors_headers(res);
        string plate = req.has_param("plate") ? req.get_param_value("plate") : "";
        string type = req.has_param("type") ? req.get_param_value("type") : "REGULAR";
        
        string responseJson = parkingLot.vehicleEntry(plate, type);
        res.set_content(responseJson, "application/json");
    });

    svr.Post("/api/exit", [&](const httplib::Request& req, httplib::Response& res) {
        set_cors_headers(res);
        string plate = req.has_param("plate") ? req.get_param_value("plate") : "";
        
        string responseJson = parkingLot.vehicleExit(plate);
        res.set_content(responseJson, "application/json");
    });

    svr.Post("/api/undo", [&](const httplib::Request& req, httplib::Response& res) {
        set_cors_headers(res);
        string responseJson = parkingLot.undoLastAction();
        res.set_content(responseJson, "application/json");
    });

    svr.Get("/api/search", [&](const httplib::Request& req, httplib::Response& res) {
        set_cors_headers(res);
        string plate = req.has_param("plate") ? req.get_param_value("plate") : "";
        
        string responseJson = parkingLot.searchVehicle(plate);
        res.set_content(responseJson, "application/json");
    });

    cout << "Parking Lot C++ Backend Engine Initialized Successfully!" << endl;
    cout << "Server started at http://localhost:8080" << endl;

    svr.listen("localhost", 8080);

    return 0;
}
