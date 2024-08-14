from flask import Flask, request, render_template
import os

app = Flask(__name__)

# Global variable to store the sensor value
sensor_value = 0

@app.route('/update', methods=['POST'])
def update():
    global sensor_value
    sensor_value = request.form.get('value', default='0')
    return "OK", 200

@app.route('/')
def index():
    global sensor_value
    return render_template('index.html', value=sensor_value)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
