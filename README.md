# Hospital Triage System 🏥

This C project simulates a **Hospital Triage System** where patients are prioritized based on the severity of their condition.

---

## 📜 Project Overview
In real hospitals, patients are not always treated on a first-come-first-served basis.  
Instead, a **triage system** assigns priority levels (from most urgent to least urgent).

This program demonstrates that concept by:
- Taking patient names and complaints
- Assigning a triage level (1 = most urgent, 5 = least urgent)
- Displaying the queue of patients in order of priority

---

## 🧩 Technologies Used
- Language: **C**
- IDE/Compiler: Code::Blocks / Turbo C / GCC

---

## 🧠 Features
✅ Accepts patient details  
✅ Prioritizes based on urgency  
✅ Displays patient queue order  
✅ Easy to modify or extend

---

## 💻 Sample Output
*** Hospital Emergency Triage System ***
1. Register New Patient
2. Call Next Patient for Treatment
3. Exit
Enter choice: 1

--- Register New Patient ---
Enter patient name: Amitesh
Enter chief complaint (e.g., Chest Pain, Fever): Chest Pain
Enter Triage Level (1-5, 1=URGENT, 5=NON-URGENT): 1

Patient Amitesh registered with Triage Level 1. Added to queue successfully!

*** Hospital Emergency Triage System ***
1. Register New Patient
2. Call Next Patient for Treatment
3. Exit
Enter choice: 2

--- NEXT PATIENT TO BE TREATED ---
Name: Amitesh
Triage Level: 1 (Highest Priority)
Chief Complaint: Chest Pain
Please direct this patient to the treatment area immediately.

*** Hospital Emergency Triage System ***
1. Register New Patient
2. Call Next Patient for Treatment
3. Exit
Enter choice: 3
Exiting Triage System...
