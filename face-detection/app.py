from flask import Flask, Response
from detect_faces import gen_frames

app = Flask(__name__)

@app.route('/')
def vid():
    return Response(gen_frames(), mimetype='multipart/x-mixed-replace; boundary=frame')

@app.route('/names')
def names():
    return get_names()


app.run(host='0.0.0.0', port=8000)
