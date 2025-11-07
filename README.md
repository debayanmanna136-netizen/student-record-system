📘 Student Record Management System (C Project)

A simple Data Structures and File Handling based project written in C.
This project allows users to add, view, search, and store student records using file handling operations.
It’s a great beginner-friendly project to understand how structured data can be stored and retrieved from text files in C.

🧠 Features

✅ Add new student records (Roll, Name, Marks)
✅ View all stored students
✅ Search for a student by roll number
✅ Store data permanently using text files
✅ Simple and easy-to-use console interface

🧩 Tech Stack

Language: C

Concepts Used:

Structures

File Handling (fopen, fprintf, fscanf, fclose)

Loops & Conditional Statements

🧱 Project Structure
StudentRecordSystem/
│
├── main.c          # main program file
├── students.txt    # data file for storing student records
└── README.md       # project documentation

📂 Sample Data (students.txt)
101 Rahul Sen 85.5
102 Priya Das 92.0
103 Arjun Roy 78.0
104 Sneha Paul 88.5
105 Riya Ghosh 95.0
106 Amit Dutta 67.5
107 Suman Das 73.0
108 Neha Kapoor 81.0
109 Dev Sharma 89.0
110 Tania Mukherjee 90.5

⚙️ How to Run

Step 1: Open VS Code or any C IDE
Step 2: Save the project files in one folder
Step 3: Compile and run using:

gcc main.c -o student
./student


Step 4: Follow on-screen instructions to perform operations like Add, View, and Search.

💻 Sample Output
====== Student Record Management System ======
1. Add Student Record
2. Display All Students
3. Search Student
4. Exit
Enter your choice: 1
Enter Roll, Name and Marks: 106 Aman 91.2
Record added successfully!

====== Student Record Management System ======
1. Add Student Record
2. Display All Students
3. Search Student
4. Exit
Enter your choice: 2

Roll   Name    Marks
101    Rahul   85.50
102    Priya   92.00
103    Arjun   78.00
104    Sneha   88.50
105    Riya    95.00
106    Aman    91.20

🌱 Learning Outcomes

Through this project, you’ll learn:

How to create and manage structures in C

How to store and retrieve data using files

How to design a simple menu-driven console application

How data persistence works across program runs

📜 Future Enhancements

Add student deletion and record update feature

Sort students by marks or name

Save data in binary files for efficiency

Create a simple GUI version using Python or Java

👨‍💻 Author

Debayan Manna
🎓 B.Tech in Data Science
📍 West Bengal, India
💬 Passionate about Data Structures, Algorithms & Real-world Projects
