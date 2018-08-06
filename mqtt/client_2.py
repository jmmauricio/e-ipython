#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jan 29 15:23:28 2018

@author: jmmauricio
"""

import paho.mqtt.client as paho
broker="192.168.2.103"
port=1883
def on_publish(client,userdata,result):             #create function for callback
    print("data published \n")
    
client1= paho.Client("control1")                           #create client object
client1.on_publish = on_publish                          #assign function to callback
client1.connect(broker,port)                                 #establish connection
ret= client1.publish("","on")                   #publish
