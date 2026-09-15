import mysql.connector as con
import ast

username = input("Enter the username : ")
password = input("Enter the password : ")

dbExists = False


def CHECKDATABASEEXISTS():
    try:
        quizdb = con.connect(
            host="localhost",
            user=username,
            password=password,
            database = "Quiz"
        )
        return True

    except Exception as e:
        return False



try:
    quizdb = con.connect(
        host="localhost",
        user=username,
        password=password,
        database = "Quiz"
    )
    dbExists = True
    print("Connected successfully!")

except Exception as e:
    print("Connection failed!")
    print("DATABASE NOT FOUND")
    print("CREATING DATABASE...")


if dbExists == False:
    try:
        quizdb = con.connect(
            host="localhost",
            user=username,
            password=password,
        )
        cursor = quizdb.cursor()
        cursor.execute("CREATE DATABASE quiz")
        if(CHECKDATABASEEXISTS):
            print("DataBase Created Successfully")

    except Exception as e:
        print("Connection failed!")
        print(type(e).__name__)
        print(e)


print("RETRIEVING QUESTIONS FROM DATABASE...")

QnTableExists = False


try:
    quizdb = con.connect(
        host="localhost",
        user=username,
        password=password,
        database = "Quiz"
    )
    cursor=quizdb.cursor()
    cursor.execute("SHOW TABLES")
    result = cursor.fetchall()
    if ('questions',) not in result:
        QnTableExists = False
    else:
        QnTableExists = True
        

except Exception as e:
    pass

QuestionsExists = False

if(QnTableExists==True):
    print("TABLE EXISTS")
    try:
        quizdb = con.connect(
        host="localhost",
        user=username,
        password=password,
        database = "Quiz"
        )
        cursor=quizdb.cursor()
        cursor.execute("SELECT * FROM questions")
        result = cursor.fetchall()
        if not result:
            QuestionsExists = False
            print("Questions Not in Table, Adding ...")
        else:
            QuestionsExists = True
            print("Questions Exists in Table")
        

    except Exception as e:
        pass

else:
    print("TABLE NOT EXISTS")
    

if(QuestionsExists==False):
    try:
        quizdb = con.connect(
        host="localhost",
        user=username,
        password=password,
        database = "Quiz"
        )
        cursor=quizdb.cursor()
        cursor.execute("""
            CREATE TABLE IF NOT EXISTS questions (
            id INT AUTO_INCREMENT PRIMARY KEY,
            question TEXT,
            option_a VARCHAR(100),
            option_b VARCHAR(100),
            option_c VARCHAR(100),
            option_d VARCHAR(100),
            answer VARCHAR(100)
            )
        """)
        print("TABLE CREATED SUCCESSFULLY")
        f = open("questions.txt","r")
        g=f.read()
        questions = ast.literal_eval(g)
        sql = """
            INSERT INTO questions
            (question, option_a, option_b, option_c, option_d, answer)
            VALUES (%s, %s, %s, %s, %s, %s)
            """
        for i in questions:
            values = (
            i["question"],
            i["options"][0],
            i["options"][1],
            i["options"][2],
            i["options"][3],
            i["answer"]
            )
            cursor.execute(sql, values)
        quizdb.commit()
        print("Questions inserted successfully!")
        cursor.close()
        quizdb.close()
        
    except Exception as e:
        pass



print("RETRIEVING QUESTIONS FROM DB")
try:
    quizdb = con.connect(
    host="localhost",
    user=username,
    password=password,
    database = "Quiz"
    )
    cursor=quizdb.cursor()
    cursor.execute("SELECT * FROM questions")
    qns = cursor.fetchall()
except Exception:
    pass


Enter = input("Press Enter to Start Quiz")
marks=0
for row in qns:
    print("\n" + "=" * 70)
    print(f"Question {row[0]}: {row[1]}")
    print("=" * 70)

    print(f"A. {row[2]}")
    print(f"B. {row[3]}")
    print(f"C. {row[4]}")
    print(f"D. {row[5]}")
    print("=" * 70)
    user = input("Enter Your Option [A,B,C,D] : ")
    correctFlag = 0
    if (user.capitalize() == 'A' and row[6]==row[2]):
        correctFlag = 1
    elif (user.capitalize() == 'B' and row[6]==row[3]):
        correctFlag = 1
    elif (user.capitalize() == 'C' and row[6]==row[4]):
        correctFlag = 1
    elif (user.capitalize() == 'D' and row[6]==row[5]):
        correctFlag = 1
    if(correctFlag==0):
        print("!!!Incorrect Answer!!!")
        print("Correct Answer : ",row[6])
    else:
        print("!!!Correct Answer!!!")
        marks=marks+1

print("\n======================")
print("Your Score : ",marks,"/10")
print("======================")