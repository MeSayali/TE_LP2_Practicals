# Terminal 1
C:\Users\Administrator>cd Downloads

C:\Users\Administrator\Downloads>scp -i VM-F1_key.pem VM-F2_key.pem azureuser@20.205.25.101:/home/azureuser/

# 20.205.25.101 is public ip of vm1
The authenticity of host '20.205.25.101 (20.205.25.101)' can't be established.
ED25519 key fingerprint is SHA256:4shGfqjB1BWzt8+F/jykkgnJLwwuWemG/oSX88OX3aU.
This key is not known by any other names.
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added '20.205.25.101' (ED25519) to the list of known hosts.
VM-F2_key.pem

azureuser@VM-F1:~$ chmod 400 VM-F2_key.pem

azureuser@VM-F1:~$ echo "Hello from VM1" > test.txt

azureuser@VM-F1:~$ scp -i VM-F2_key.pem test.txt

usage: scp [-346ABCOpqRrsTv] [-c cipher] [-D sftp_server_path] [-F ssh_config]
           [-i identity_file] [-J destination] [-l limit] [-o ssh_option]
           [-P port] [-S program] [-X sftp_option] source ... target

azureuser@VM-F1:~$ /home/azureuser

azureuser@VM-F1:~$ scp -i VM-F2_key.pem test.txt 

azureuser@10.0.0.5:/home/azureuser/
The authenticity of host '10.0.0.5 (10.0.0.5)' can't be established.
ED25519 key fingerprint is SHA256:FZ9RP2wMFPd94C5QDkBByops8IJuHmplfeML/L2P4gY.
This key is not known by any other names.
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added '10.0.0.5' (ED25519) to the list of known hosts.
test.txt


# Terminal 2
C:\Users\Administrator>cd downloads


C:\Users\Administrator\Downloads>ssh -i VM-F2_key.pem azureuser@20.205.19.38

# 20.205.19.38 public ip of vm2

azureuser@VM-F2:~$ ls
test.txt
