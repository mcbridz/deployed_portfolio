#filename: lab3-grading.py
#author: Zachary McBride


running = True
while running == True:
    grade = int(input("Please enter a grade (0-100): "))
    # if grade <= 59:
    #     print("The grade you entered is a 'F'")
    # elif grade <= 64:
    #     print("The grade you entered is a 'D-'")
    # elif grade < 66:
    #     print("The grade you entered is a 'D'") 
    # elif grade <= 69:
    #     print("The grade you entered is a 'D+'")
    # elif grade <= 74:
    #     print("The grade you entered is a 'C-'")
    # elif grade <= 75:
    #     print("The grade you entered is a 'C'")
    # elif grade <= 79:
    #     print("The grade you entered is a 'C+'")
    # elif grade <= 84:
    #     print("The grade you entered is a 'B-'")
    # elif grade <= 85:
    #     print("The grade you entered is a 'B'")
    # elif grade <= 89:
    #     print("The grade you entered is a 'B+'")
    # elif grade <= 94:
    #     print("The grade you entered is an 'A-'")
    # elif grade <= 95:
    #     print("The grade you entered is an 'A'")
    # else:
    #     print("The grade you entered is an 'A+'")
    grades = {5: 'F', 6: 'D', 7: 'C', 8: 'B', 9: 'A', 10: 'A'}
    modifier = ''
    if grade % 10 < 5:
        modifier = '-'
    elif grade % 10 > 5:
        modifier = '+'
    if grade != 100:
        print(f"The grade you entered evaluates as: {grades.get(grade//10, 'F')}{modifier}")
    else:
        print("The grade you entered evaluates as: A+")
    question = input("Do you want to grade another student? Enter 'Yes' to contine, 'No' to quit. ").lower()
    if question == "no":
        break