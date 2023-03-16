import socket
import sys
import json
from time import time, strftime, localtime

class Client:
    '''This class contains the client object and the necessary functions
    '''

    def __init__(self, server_addr):
        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.name = 1
        self.Troops
        self.Miners
        self.Farmers
        self.Engineers
        self.Spies
        self.Food
        self.Raw_Materials
    '''Define functions here
    '''
    def ResourceAllocator(self):
        pass
    def DefenseStrategy(self):
        pass
    def AttackStrategy(self):
        pass
    def SpyDeployer():
        pass
