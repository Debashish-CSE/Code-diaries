# Input score from the user
    score = int(input("Enter your score (0-100): "))
    
    if 1 <= score <= 39:
        grade = "Fail"
    elif 40 <= score <= 49:
        grade = "C"
    elif 50 <= score <= 59:
        grade = "B"
    elif 60 <= score <= 69:
        grade = "A-"
    elif 70 <= score <= 79:
        grade = "A"
    elif 80 <= score <= 100:
        grade = "A+"
    else:
        grade = "Invalid score. Please enter a number between 1 and 100."

    print("Your grade is: {grade}")

