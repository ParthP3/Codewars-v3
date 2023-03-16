import json

def listen(client):
    input = ""
    input += client.client_sock.recv(1024).decode("utf-8")
    client.process(input)