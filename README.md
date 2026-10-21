# ParkFlow: Smart Parking Lot Management System

ParkFlow is an efficient C++ based Smart Parking Lot Management System that separates concerns very well by making use of core Data Structures such as Hash Maps, Stacks, and Queues.

---

##Features

- Slot Allocation:** Auto manages VIP and Regular slots.
- Waiting Queue (FIFO): If there are no slots available, cars are pushed automatically into the waiting queue through a queue data structure.
- Vehicle Instant Lookup  Utilizing Hash Map for fast vehicle lookup.
- Action History & Undo Operation: Using Stack data structure for parking actions so that user can undo the latest slot allocations.
- Modularity: Clean separation of the business logic, headers and JSON utility.

---

## 🛠️ Tech Stack

- **Language:** C++,HTML,CSS,Java Script
- **Data Structures Used:**
  - **Hash Map** (`std::unordered_map`) for fast vehicle lookup.
  - **Stack** (`std::stack`) for action history and undo operations.
  - **Queue** (`std::queue`) for the waiting list.
- **Backend / Frontend integration:** Communicates with the web interface using JSON string formatting.
