savedcmd_/home/dev/OS_DD/02_devicenumbers/dev_nr.mod := printf '%s\n'   dev_nr.o | awk '!x[$$0]++ { print("/home/dev/OS_DD/02_devicenumbers/"$$0) }' > /home/dev/OS_DD/02_devicenumbers/dev_nr.mod
