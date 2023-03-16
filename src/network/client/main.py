from cli import Client
from listen import listen
from sys import argv
import threading

if len(argv)!=3:
    print(f"Usage: {argv[0]} <server ip> <server port>")

server_addr = (argv[1], int(argv[2]))

client = Client(server_addr)

t=threading.Thread(target = listen, args=(client,))
t.daemon = True
t.start()

'''
 Troops
 Miners
 Farmers
 Engineers
 Spies
 Food
 Raw Materials
'''

try:
    pass
    '''Call the functions in client over here
    '''
except KeyboardInterrupt:
    print("Closing the client")