
# Parking Management System

### Installation

First, navigate into the project directory:

```bash
cd parking-system
```

Setup a virtual environment
```bash
python -m venv venv --system-site-packages
. venv/bin/activate
```
Install requirements

```bash
pip install -r requirements.txt
```
## Download `key.json` from Firebase

1. Go to the [Firebase Console](https://console.firebase.google.com/).
2. Select your project.
3. Navigate to `Project settings` > `Firebase Admin SDK`.
4. Click on "Generate new private key" and save the file as `key.json` to your project directory.

## Run the application

Finally, run the application:

```bash
python app.py
```

## Pinout for Raspberry Pi 4 GPIOs  
  
![Pinout for Raspberry Pi 4](pin_layout.svg "Pinout for Raspberry Pi 4")  