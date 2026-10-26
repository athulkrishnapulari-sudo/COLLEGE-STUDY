import sqlite3

con = sqlite3.connect('student.db')

cur = con.cursor()

# cur.execute('CREATE TABLE students (id INTEGER PRIMARY KEY , name TEXT , mark INTEGER)')

# cur.execute('INSERT INTO students VALUES(?,?,?)',(1,'Anu',85))

# con.commit()

# cur.execute('SELECT * FROM students')

# data = cur.fetchall()

# for i in data:
#     print(i)

# cur.execute('INSERT INTO students VALUES(?,?,?)',(2,'Abhi',95))
# con.commit()

# cur.execute('UPDATE students SET mark = ? WHERE id = ?',(78,2))
# con.commit()

# cur.execute('DELETE FROM students WHERE id = ?',(2,))
# con.commit()

