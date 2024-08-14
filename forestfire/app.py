from flask import Flask, request, render_template
import os

app = Flask(__name__)

# Global variable to store the sensor value
sensor_value = 0
threshold = 1000  # Threshold value for safety

@app.route('/update', methods=['POST'])
def update():
    global sensor_value
    sensor_value = int(request.form.get('value', default='0'))
    return "OK", 200

@app.route('/')
def index():
    global sensor_value, threshold
    status = "Safe" if sensor_value <= threshold else "Dangerous"
    return render_template('index.html', value=sensor_value, status=status, threshold=threshold)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
