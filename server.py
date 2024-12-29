#!/bin/python

import flask as f

server = f.Flask(__name__)

@server.route('/')
def home():
    return "WTF"

@server.route('/whatisyourname')
def name():
    return "Um beep boop, i never thought about it!"

@server.route('/fuckyou')
def tuant():
    return "Oh yeah, you too mothafucka"

@server.route('/wtf')
def wtf():
    return "Ionno either"

@server.route('/im/<name>', methods=['GET', 'POST'])
def greet(name):
    if f.request.method == 'POST':
        return 'Okay ill \'try\' to remember you'
    return f"Hey, {name}. You an a-hole."

if __name__ == '__main__':
    server.run(host="0.0.0.0", port=6969)
