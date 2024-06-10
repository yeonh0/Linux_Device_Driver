savedcmd_/home/dev/OS_DD/mymodule.mod := printf '%s\n'   mymodule.o | awk '!x[$$0]++ { print("/home/dev/OS_DD/"$$0) }' > /home/dev/OS_DD/mymodule.mod
