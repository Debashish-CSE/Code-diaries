from graphviz import Digraph

er = Digraph('ER', filename='er_diagram', format='png')

er.attr(rankdir='LR', size='8')

# ENTITY: Student
er.node('Student', shape='rectangle')
er.node('S_ID', 'id', shape='ellipse')
er.node('S_Name', 'name', shape='ellipse')
er.edge('Student', 'S_ID')
er.edge('Student', 'S_Name')

# ENTITY: Course
er.node('Course', shape='rectangle')
er.node('C_ID', 'code', shape='ellipse')
er.node('C_Title', 'title', shape='ellipse')
er.edge('Course', 'C_ID')
er.edge('Course', 'C_Title')

# RELATIONSHIP: Enrolls
er.node('Enrolls', shape='diamond')
er.edge('Student', 'Enrolls')
er.edge('Enrolls', 'Course')

# ATTRIBUTES of Enrolls
er.node('Date', 'date', shape='ellipse')
er.node('Grade', 'grade', shape='ellipse')
er.edge('Enrolls', 'Date')
er.edge('Enrolls', 'Grade')

er.render(view=True)
