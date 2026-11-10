# CPlusPlus-Application-Design
My C++ Application Design class projects and assignments.

# Student Record Management System — Modules 8 and 9

## Module 8: Input Validation
I added input validation to my student record management program. The program checks that student IDs are positive whole numbers and are not duplicates. Student names cannot be empty or just spaces. Grades must be numbers from 0 to 100. The menus reject invalid choices, and numeric inputs reject letters or extra characters. When the user enters invalid information, the program displays an error message and lets them try again instead of ending the operation.

## Module 9: AI-Powered Feature (Mock Prototype)
**Feature:** Student Performance Advisor.

**What it does:** The advisor reviews a student's grade and provides a study recommendation. This is a rule-based mock prototype, not a live AI model.

**Data needed:** Student ID, student name, and grade from the existing student records.

**What the user sees:** The user chooses the advisor from the Admin or Regular User menu, enters a student ID, and sees the student's information and a recommendation. A grade of 90 or higher gets encouragement, 70–89 gets a review suggestion, and below 70 gets a tutoring and study-plan suggestion.

**Where AI fits into the application:** The advisor is a separate function that uses the existing binary search to retrieve a student. In a future version, the rule-based recommendation could be replaced by a real AI service that receives student performance data and returns personalized advice. The existing classes, record storage, and menus could stay the same.

## Files
- `Module08_Data/main.cpp` — student record system with input validation.
- `Module09_AI/main.cpp` — validated student record system with a mock AI advisor.
