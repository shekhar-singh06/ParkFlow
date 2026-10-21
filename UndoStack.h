#ifndef UNDOSTACK_H
#define UNDOSTACK_H

#include <stack>
#include <string>
#include "ParkingSlots.h"
#include "waitingqueue.h"
#include "VehicleHAshMap.h"

// Forward Declaration to prevent circular dependency / type errors
class VehicleHashMap;

using namespace std;

class ActionLog
{
private:
    string plate;
    string slotType;
    int slotIndex;

public:
    ActionLog();
    ActionLog(string p, string t, int idx);
    string getPlate();
    string getSlotType();
    int getSlotIndex();
};

class UndoStack
{
private:
    stack<ActionLog> historyStack;

public:
    void push(const ActionLog& action);
    void pop();
    bool empty();
    size_t size();
    ActionLog top();
    void removePlate(string plate);
    string undoLastAction(ParkingSlots& slots, waitingqueue& waitingQueue, VehicleHashMap& vehicleMap);
};

#endif
