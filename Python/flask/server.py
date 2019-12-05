from flask import Flask, render_template, request 

app = Flask(__name__)

@app.route("/")

def index():
    return render_template("index.html")

@app.route('/login',methods = ['POST'])  
def login():  
    uname = request.form['uname']
    passwrd = request.form['pass']

    if uname=="ayush" and passwrd=="123":
        return "Welcome %s" %uname  
    else:
        return "fail"

if __name__ =='__main__':
    app.run(debug = True)