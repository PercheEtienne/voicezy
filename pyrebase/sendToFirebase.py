import pyrebase
import sys
from datetime import datetime

config = {
    "apiKey": "AIzaSyBntdufX52MP6D-vTKehA4CXkMelIajnZs",
    "authDomain": "voicezy-48275.firebaseapp.com",
    "databaseURL": "https://voicezy-48275.firebaseio.com",
    "storageBucket": "voicezy-48275.appspot.com"
}

firebase = pyrebase.initialize_app(config)

db = firebase.database()

now = datetime.now()

dt_string = now.strftime("%d/%m/%Y %H:%M:%S")

data = {"time":dt_string, "categorie": sys.argv[1],"data" : sys.argv[2]}

db.child("users").push(data)